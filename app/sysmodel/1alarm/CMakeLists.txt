DOSEK_BINARY(
  NAME sysmodel_1alarm_a
  SYSTEM_DESC a.oil
  VERIFY verify_a.py
  LIBS libtest
  TEST_ISO
  a.cc
)

DOSEK_BINARY(
  NAME sysmodel_1alarm_aa
  SYSTEM_DESC aa.oil # OTHER XML!
  VERIFY verify_aa.py
  LIBS libtest
  TEST_ISO
  a.cc
)
