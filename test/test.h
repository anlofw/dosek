/**
 *  @defgroup test Testing
 *  @brief Testing
 */

/**
 * @ingroup test
 * @defgroup unit_tests Unit Tests
 * @brief Small unit tests
 */


/**
 * @file
 * @ingroup unit_tests
 * @brief Basic functions for unit testing
 *
 * How to use test.h for unit tests
 * ================================
 *
 * A testcase can be defined by including the test.h header.
 * You can define `void test_prepare()` to do work before the experiment
 * (won't be traced).
 *
 * The `void test(void)` function is called by the operating systems
 * main function. Everything that happens there will be included in
 * the fail trace afterwards.
 *
 * @warning This "header" file instantiates global objects.
 *          Do not include this header in multiple files!
 *
 * Each testcase in the test functions has the following form:
 *
 * * *Optionally* store dynamic test result:
 *   ~~~~~~~~~~~~~~{.c}
 *    // Store expected results (if dynamic)
 *    test_expect_store(0, expected_a);
 *    test_expect_store(1, exptected_b);
 *   ~~~~~~~~~~~~~~
 *
 * * Run test case:
 *   ~~~~~~~~~~~~~~{.c}
 *   // Start the testcase (injecting from here)
 *   test_start();
 *   run_my_super_dupper_test_function(&a, &b)
 *   // finish the testcase (injecting till here)
 *   int result = test_start_check();
 *
 *   // Run n tests on the result:
 *   test_eq(result, 123);
 *   test_expect_eq(0, a);
 *   test_expect_eq(1, b);
 *
 *   // Testcase is only positive when more than one condition holds
 *   test_positive_tests_gt(1);
 *   ~~~~~~~~~~~~~~
 */

#include <stdint.h>
#include "util/encoded.h"
#include "util/inline.h"
#include "machine.h"
#include "output.h"

#define EXPECTED_VALUES_MAX 10
typedef unsigned int expected_value_t;


extern "C" {
	/**
	 * @name FAIL* interface variables
	 * These are not changed during injection time as they are outside of fail namespace
	 */
	// @{

	//! encoded result value (result.vc) will be copied here
	extern value_t encoded_storage;

	//! test check function detected error in result
	extern bool detected_error;

	//! all tests (so far) passed
	extern bool global_all_ok;

	//! number of positive checks in this test
	extern	int positive_tests;

	//! number of current experiment
	extern	int experiment_number;

	//! buffer for expected result values
	extern expected_value_t expected_values[EXPECTED_VALUES_MAX];

	// @}

	//! interrupts were enabled before test checks
	extern bool interrupts_suspended;

	//! buffer for task activation records
	extern char trace_table[256];

	//! index for trace_table
	extern unsigned char trace_table_idx;

	/**
	 * @name User supplied functions
	 */
	// @{
      	//! user-supplied prepare function
	void test_prepare(void);

	//! user-supplied test function
	noinline void test(void);
	// @}

	/**
	 * @name FAIL* markers
	 */
	// @{
	extern void (*marker_start)();
	extern void (*marker_start_check)();
	extern void (*marker_stop_check)();
	extern void (*trace_start_marker)();
	extern void (*trace_end_marker)();
	// @}

	extern char trace_table[256];
	extern unsigned char trace_table_idx;
}


inlinehint void test_start()
{
	// update global status variables
	experiment_number++;
	positive_tests = 0;

	kout.setcolor(Color::WHITE, Color::BLACK);
	kout << endl << "Test " << (unsigned) experiment_number << ": " << endl;
	kout.setcolor(Color::YELLOW, Color::BLACK);

	/* Set a marker for starting the test */
	marker_start();
}

inlinehint void test_start_check() {
	marker_start_check();
	interrupts_suspended = Machine::interrupts_enabled();
	Machine::disable_interrupts();
}

inlinehint void test_equality(expected_value_t real_value, const expected_value_t expected_value, bool equal)
{
	if((equal && real_value == expected_value) || (!equal && real_value != expected_value)) {
		kout.setcolor(Color::GREEN, Color::BLACK);
		kout << "  +" << endl;
		kout.setcolor(Color::WHITE, Color::BLACK);

		positive_tests++;
	} else {
		kout.setcolor(Color::RED, Color::BLACK);
		kout << "  -[" << real_value << (equal ? " != " : " == ") << expected_value << "]" << endl;
		kout.setcolor(Color::WHITE, Color::BLACK);
	}
}

inlinehint void test_eq(expected_value_t real_value, const expected_value_t expected_value) {
	test_equality(real_value, expected_value, true);
}

inlinehint void test_ne(expected_value_t real_value, const expected_value_t expected_value) {
	test_equality(real_value, expected_value, false);
}

/* Store and retrieve expected results */

inlinehint void test_expect_store(unsigned char id, expected_value_t value) {
	expected_values[id] = value;
}

inlinehint void test_expect_eq(unsigned char id, const expected_value_t expected_value) {
	test_equality(expected_values[id], expected_value, true);
}

inlinehint void test_expect_ne(unsigned char id, const expected_value_t expected_value) {
	test_equality(expected_values[id], expected_value, false);
}

inlinehint void test_assert(bool result) {
	test_equality(result, true, true);
}



inlinehint void __test_positive_tests(int pos_tests, int sign) {
	int delta = positive_tests - pos_tests;
	if ((sign < 0 && delta < 0)
		|| (sign == 0 && delta == 0)
		|| (sign > 0 && delta > 0)) {

		kout.setcolor(Color::GREEN, Color::BLACK);
		kout << "SUCCESS " << experiment_number << endl;
		kout.setcolor(Color::WHITE, Color::BLACK);
	} else {
		global_all_ok = false;

		kout.setcolor(Color::RED, Color::BLACK);
		kout << "FAIL " << experiment_number << "(positive_tests = " << positive_tests << ")" << endl;
		kout.setcolor(Color::WHITE, Color::BLACK);
	}

	if(interrupts_suspended) Machine::enable_interrupts();
	marker_stop_check();

	for (int i = 0; i < EXPECTED_VALUES_MAX; i++) {
		expected_values[i] = 0xAAAA5555;
	}
}

inlinehint void test_positive_tests_eq(int positive_tests) {
	__test_positive_tests(positive_tests, 0);
}

inlinehint void test_positive_tests_lt(int positive_tests) {
	__test_positive_tests(positive_tests, -1);
}

inlinehint void test_positive_tests_gt(int positive_tests) {
	__test_positive_tests(positive_tests, 1);
}


// run one test with unencoded result
// detectable can be set if the result value is known and error could be detected to set detected_error
// forceinline used to inline this into test() function to stay within allowed text region
// volatile used to prevent inlining of testfunction, which should stay separate
inlinehint void run_checkable_function(void (* volatile testfun)(void), expected_value_t& result_var, value_t expected, bool detectable) {
	test_expect_store(0, expected);
	encoded_storage = 0;
	detected_error = false;

	/* Start the testcase (including marker_start() */
	test_start();
	testfun();
	test_start_check();
	encoded_storage = result_var;

	/* Chcek if result value is equal to expected */
	test_expect_eq(0, result_var);

	/* If the result value is known and the error would be detected set detected_error */
	if(detectable) detected_error = (result_var != expected);

	/* Check has to succeed */
	test_positive_tests_gt(0);
}

// run one test with encoded result
// forceinline used to inline this into test() function to stay within allowed text region
// volatile used to prevent inlining of testfunction, which should stay separate
template<typename T>
inlinehint void run_checkable_function(void (* volatile testfun)(void), T& result_var, value_t expected) {
	test_expect_store(0, expected);
	encoded_storage = 0;
	detected_error = false;

	/* Start the testcase (including marker_start() */
	test_start();
	testfun();
	test_start_check();
	encoded_storage = result_var.vc;

	/* Either the decoded value is equal to expected */
	test_expect_eq(0, result_var.decode());

	/* Or the check says: undecodable */
	detected_error = !result_var.check();
	test_assert(detected_error == true);

	/* and at least one of the tests has to succeed */
	test_positive_tests_gt(0);
}


__attribute__((weak_import))
extern void test_prepare();

inlinehint void test_init(void) {
	// prepare tests
	global_all_ok = true;
	if (test_prepare != 0) {
		test_prepare();
	}

	// run tests
	trace_start_marker();
}



inlinehint void test_finish(int tests=0) {
	trace_end_marker();

	if((tests > 0) && (tests != experiment_number)) {
		kout << "INCORRECT NUMBER of tests run: ";
		kout << dec << experiment_number << " instead of " << tests;
		kout << endl;
	} else {
		kout << "Tests finished: ";
		kout << (global_all_ok ? "ALL OK" : "some tests failed");
		kout << endl;
	}
}



inlinehint void test_main(void)
{
	debug.setcolor(Color::RED, Color::WHITE);
	debug << "CoRedOS start" << endl;
	debug.setcolor(Color::YELLOW, Color::BLACK);

	// prepare tests
	test_init();

	// run tests
	test();

	// finish tests
	test_finish();

	// halt system
	debug.setcolor(Color::RED, Color::WHITE);
	debug << "CoRedOS halt" << endl;
	Machine::shutdown();
}

inlinehint void test_trace(char chr) {
	if (trace_table_idx < 0xff)
		trace_table[trace_table_idx++] = chr;
}

inlinehint void test_trace_dump(void) {
	kout << "traced: ";
	for (unsigned char i = 0; i < trace_table_idx; i++) {
		kout << trace_table[i];
	}
}

inlinehint void test_trace_assert(const char *expected) {
	int good = 1;
	unsigned char count = 0;

	test_start_check();

	for (; expected[count] != 0 && count < 255; count++) {}
	if (count != trace_table_idx) {
		kout << "trace length != expected " << (int) trace_table_idx << endl;
		good = 0;
	} else {
		for (unsigned char i = 0; i < trace_table_idx; i++) {
			if (trace_table[i] != expected[i]) {
				kout << "too unqeual: " <<  trace_table[i] << " at " << (int)i <<endl;
				good = 0;
				break;
			}
		}
	}

	kout << "expect: " << expected << endl;
	test_trace_dump();
	kout << endl;

	test_assert(good);
	test_positive_tests_gt(0);
}

#define TEST_MAKE_OS_MAIN(body) \
	void os_main(void) {		\
		test_main();			\
	}							\
								\
	void test() {				\
		test_start();			\
		body;					\
	}							\

