#include "unity.h"
#include "zk/zklib.h"

zk_vector *vec = NULL;

void setUp(void)
{
	vec = zk_vector_new();
	if (vec == NULL) {
		TEST_FAIL_MESSAGE("Failed to allocate memory for zk_vector");
	}
}

void tearDown(void)
{
	zk_vector_free(vec, NULL);
}

void test_zk_vector_push_back_when_vec_is_null_should_null(void)
{
	zk_vector_push_back(NULL, NULL);
}

void test_zk_vector_push_back_when_no_resize_when_size_is_less_than_capacity(void)
{
	int data = 1;
	zk_vector_push_back(vec, &data);
	TEST_ASSERT_EQUAL(1, zk_vector_size(vec));
	TEST_ASSERT_EQUAL(8, zk_vector_capacity(vec));
}

void test_zk_vector_push_back_shall_increment_size()
{
	int data = 1;
	zk_vector_push_back(vec, &data);
	TEST_ASSERT_EQUAL(1, zk_vector_size(vec));
	TEST_ASSERT_EQUAL(8, zk_vector_capacity(vec));
	zk_vector_push_back(vec, &data);
	TEST_ASSERT_EQUAL(2, zk_vector_size(vec));
	TEST_ASSERT_EQUAL(8, zk_vector_capacity(vec));
}

void test_zk_vector_push_back_when_resize_when_size_is_equal_to_capacity(void)
{
	int data [] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 0; i < 8; i++)
		zk_vector_push_back(vec, &data[i]);
	TEST_ASSERT_EQUAL(8, zk_vector_size(vec));
	TEST_ASSERT_EQUAL(8, zk_vector_capacity(vec));
	zk_vector_push_back(vec, &data[8]);
	TEST_ASSERT_EQUAL(9, zk_vector_size(vec));
	TEST_ASSERT_EQUAL(16, zk_vector_capacity(vec));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_zk_vector_push_back_when_vec_is_null_should_null);
	RUN_TEST(test_zk_vector_push_back_when_no_resize_when_size_is_less_than_capacity);
	RUN_TEST(test_zk_vector_push_back_shall_increment_size);
	RUN_TEST(test_zk_vector_push_back_when_resize_when_size_is_equal_to_capacity);
	return UNITY_END();
}
