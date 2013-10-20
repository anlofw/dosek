include(CMakeParseArguments)
include(rtsc)

MACRO(COREDOS_BINARY)
  set(options )
  set(oneValueArgs SYSTEM_XML NAME)
  set(multiValuedParameters SOURCES)
  cmake_parse_arguments(COREDOS_BINARY "${options}" "${oneValueArgs}" "${multiValuedParameters}" ${ARGN} )
  set(COREDOS_BINARY_SOURCES "${COREDOS_BINARY_UNPARSED_ARGUMENTS};${COREDOS_BINARY_SOURCES}")
  SET(COREDOS_SYSTEM_XML "${CMAKE_CURRENT_SOURCE_DIR}/${COREDOS_BINARY_SYSTEM_XML}")

  # First we have to compile all source files with clang
  foreach(src ${COREDOS_BINARY_SOURCES})
	set(llvm_bytecode "${CMAKE_CURRENT_BINARY_DIR}/${src}.ll")
	add_custom_command(OUTPUT ${llvm_bytecode}
	  COMMAND ${CLANG_BINARY} -S -emit-llvm -O0 
	  -I${RTSC_SOURCE_DIR}/data/SystemSupport/OSEKOS/include/
	  ${CMAKE_CURRENT_SOURCE_DIR}/${src} -o ${llvm_bytecode}
	  MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/${src}
      COMMENT "[${PROJECT_NAME}] Compiling application ${src} with clang")
	

	list(APPEND COREDOS_BINARY_LLVM_BYTECODE ${llvm_bytecode})
  endforeach(src)

  set(COREDOS_SOURCE_SYSTEM "${CMAKE_CURRENT_BINARY_DIR}/source_system.ll")
  set(COREDOS_SOURCE_SYSTEM_OBJECT "${CMAKE_CURRENT_BINARY_DIR}/source_system.o")
  set(COREDOS_GENERATED_SOURCE "${CMAKE_CURRENT_BINARY_DIR}/coredos.c")


  
  # Use RTSC to analyze and merge the source system bytecode
  add_custom_command(OUTPUT "${COREDOS_SOURCE_SYSTEM}"
	DEPENDS ${COREDOS_BINARY_LLVM_BYTECODE}
	COMMAND ${RTSC_BINARY} -data-deps=explicit -verify 
	   -sysann=${RTSC_BINARY_DIR}/test/annotate_osek.ll
	   -sourcesystem=${CMAKE_CURRENT_SOURCE_DIR}/${COREDOS_BINARY_SYSTEM_XML}
	   -pns=1 -out=${CMAKE_CURRENT_BINARY_DIR} 
	   -march=${CMAKE_C_ARCH} 
	   -analyze-tasks -dump-source-system
	   ${COREDOS_BINARY_LLVM_BYTECODE}
       COMMENT "[${PROJECT_NAME}] Analyzing application with RTSC")

  # Compile source system to a .o file
  add_custom_command(OUTPUT "${COREDOS_SOURCE_SYSTEM_OBJECT}"
	DEPENDS "${COREDOS_SOURCE_SYSTEM}"
	COMMAND ${CLANG_BINARY} -c -o "${COREDOS_SOURCE_SYSTEM_OBJECT}" "${COREDOS_SOURCE_SYSTEM}"
	COMMENT "Generating object file for app")

  # Add Target for the analysis step
  add_custom_target(${COREDOS_BINARY_NAME}-rtsc-analyze
	DEPENDS ${COREDOS_SOURCE_SYSTEM} ${COREDOS_SOURCE_SYSTEM_OBJECT})


  # All python source files are a dependency
  file(GLOB_RECURSE PYTHON_SOURCE "${COREDOS_GENERATOR_DIR}/*.py")

  # Generating COREDOS System
  add_custom_command(OUTPUT "${COREDOS_GENERATED_SOURCE}"
	DEPENDS ${PYTHON_SOURCE} "${COREDOS_SYSTEM_XML}" "${COREDOS_SOURCE_SYSTEM_OBJECT}" "${LLVM_NM_BINARY}"
	COMMAND ${COREDOS_GENERATOR} 
	   --system-xml "${COREDOS_SYSTEM_XML}"
	   --app-object "${COREDOS_SOURCE_SYSTEM_OBJECT}" 
	   --nm "${LLVM_NM_BINARY}"
	   --output "${COREDOS_GENERATED_SOURCE}"
	COMMENT "Generating COREDOS source code"
	)

  add_custom_target(${COREDOS_BINARY_NAME}-generate
	DEPENDS "${COREDOS_GENERATED_SOURCE}")

ENDMACRO(COREDOS_BINARY)
