#include "unity.h"
#include "stack.h"

void setUp(void) {
    // Set up code if needed
}

void tearDown(void) {
    // Tear down code if needed
}

void test_initStack(void) {
    Stack stack;
    initStack(&stack);
    TEST_ASSERT_TRUE(isEmpty(&stack));
    TEST_ASSERT_FALSE(isFull(&stack));
}

void test_push_pop(void) {
    Stack stack;
    int value;

    initStack(&stack);

    TEST_ASSERT_TRUE(push(&stack, 10));
    TEST_ASSERT_FALSE(isEmpty(&stack));
    TEST_ASSERT_TRUE(peek(&stack, &value));
    TEST_ASSERT_EQUAL(10, value);

    TEST_ASSERT_TRUE(pop(&stack, &value));
    TEST_ASSERT_EQUAL(10, value);
    TEST_ASSERT_TRUE(isEmpty(&stack));
}

void test_isFull(void) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < MAX_SIZE; i++) {
        TEST_ASSERT_TRUE(push(&stack, i));
    }

    TEST_ASSERT_TRUE(isFull(&stack));
    TEST_ASSERT_FALSE(push(&stack, 101));
}

void test_isEmpty(void) {
    Stack stack;
    int value;

    initStack(&stack);
    TEST_ASSERT_TRUE(isEmpty(&stack));
    TEST_ASSERT_FALSE(pop(&stack, &value));

    push(&stack, 1);
    TEST_ASSERT_FALSE(isEmpty(&stack));

    pop(&stack, &value);
    TEST_ASSERT_TRUE(isEmpty(&stack));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_initStack);
    RUN_TEST(test_push_pop);
    RUN_TEST(test_isFull);
    RUN_TEST(test_isEmpty);
    return UNITY_END();
}

