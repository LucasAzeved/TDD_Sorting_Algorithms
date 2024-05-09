#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Sort);

TEST_SETUP(Sort)
{
}

TEST_TEAR_DOWN(Sort)
{
}

void ValidTesting(int *a, int length, int index)
{
  const char *type = "On";
  if (index < 2)
  {
    TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, index));
  }
  else if (index >= 2 && index < 5)
  {
    type = "On2";
    TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, index));
  }
  else
  {
    type = "Onlogn";
    TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, index));
  }
}

void InvalidTesting(int *a, int length, int index)
{
  const char *type = "On2";
  if (index < 2)
  {
    TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, index));
  }
  else if (index >= 2 && index < 5)
  {
    type = "Onlogn";
    TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, index));
  }
  else
  {
    type = "On";
    TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, index));
  }
}

TEST(Sort, TestEverythingValid)
{
  int a[] = {1, 2, 3, 4, 5};
  int length = 5;

  for (int i = 0; i < 8; i++)
  {
    ValidTesting(a, length, i);
  }
}

TEST(Sort, TestInvalidType)
{
  int a[] = {1, 2, 3, 4, 5};
  int length = 5;
  const char *type = "T1";

  for (int i = 0; i < 8; i++)
  {
    TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, i));
  }
}

TEST(Sort, TestInvalidIntType)
{
  int a[] = {1, 2, 3, 4, 5};
  int length = 5;
  int type = 2;

  TEST_ASSERT_EQUAL(1, sort(a, length, (void *)&type, 7)); // Needed to add this "(void *)&" to remove warning pointing type mismatch

}

TEST(Sort, TestInvalidEmptyType)
{
  int a[] = {1, 2, 3, 4, 5};
  int length = 5;
  const char *type = "";

  for (int i = 0; i < 8; i++)
  {
    TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, i));
  }
}

TEST(Sort, TestValidButWrongType)
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = 10;

  for (int i = 0; i < 8; i++)
  {
    InvalidTesting(a, length, i);
  }
}

TEST(Sort, TestInvalidAlgorithm)
{
  int a[] = {1, 2, 3, 4, 5};
  int length = 5;
  const char *type = "On";

  TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, 9));

}

TEST(Sort, TestInvalidCharAlgorithm)
{
  int a[] = {1, 2, 3, 4, 5};
  int length = 5;
  const char *type = "On";

  TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, 'a'));

}

TEST(Sort, TestWrongBiggerLenght)
{
  int a[] = {1, 2, 3, 4, 5};
  int length = 5; // Valgrind error, used to be: int length = 6;

  for (int i = 0; i < 8; i++)
  {
    ValidTesting(a, length, i);
  }
}

TEST(Sort, TestInvalidCharLenght)
{
  int a[] = {1, 2, 3, 4, 5};
  char length = 'i'-'d'; // Only works because ASCII of " 'i' - 'd' " translates to the integer 5, otherwise causes sanitizer error
  const char *type = "On";

  for (int i = 0; i < 8; i++)
  {
    if (i < 2)
    {
      TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, i));
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, i));
    }
    else
    {
      type = "Onlogn";
      TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, i));
    }
  }
}

TEST(Sort, TestOutOfOrderArray)
{
  int a[] = {5, 4, 3, 2, 1};
  int arrayOrdered[] = {1, 2, 3, 4, 5};
  int length = 5;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);

    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);

    for (int j = length; j > 0; j--)
    {
      a[length - j] = j;
    }
  }
}

TEST(Sort, TestTwoValuesArray)
{
  int a[] = {2, 1};
  int arrayOrdered[] = {1, 2};
  int length = 2;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);

    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }
    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);

    for (int j = length; j > 0; j--)
    {
      a[length - j] = j;
    }
  }
}

TEST(Sort, TestTwentyValuesArray)
{
  int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
  int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
  int length = 20;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);

    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);

    for (int j = length; j > 0; j--)
    {
      a[length - j] = j;
    }
  }
}

TEST(Sort, TestTwentyOneValuesArray)
{
  int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 21}; // Only works because the value 21 is in the index 20 and not being changed
  int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20, 21};
  int length = 20; // Should be 21, but then the sort function would not work
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);

    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    for (int k = 0; k < 20; k++)
    {
      TEST_ASSERT_EQUAL_INT32_MESSAGE(arrayOrdered[k], a[k], message);
    }

    for (int j = length; j > 0; j--)
    {
      a[length - j] = j;
    }
  }
}

TEST(Sort, TestSameValuesArray)
{
  int a[] = {1, 1, 1, 1, 1};
  int arrayOrdered[] = {1, 1, 1, 1, 1};
  int length = 5;
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    ValidTesting(a, length, i);
    sprintf(message, "Error in the index: %d", i);
    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
  }

}

TEST(Sort, TestOneValueArray)
{
  int a[] = {1};
  int arrayOrdered[] = {1};
  int length = 1;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);
    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
  }
}


TEST(Sort, TestOrderedArray)
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
  int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
  int length = 20;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);
    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
  }
}

TEST(Sort, TestLowerHalfArray)
{
  int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
  int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
  int length = 20;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);
    
    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    for (int k = 0; k < 10; k++)
    {
      TEST_ASSERT_EQUAL_INT32_MESSAGE(arrayOrdered[k], a[k], message);
    }

    for (int j = length; j > 0; j--)
    {
      a[length - j] = j;
    }
  }
}

TEST(Sort, TestUpperHalfArray)
{
  int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
  int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
  int length = 20;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);
    
    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    for (int k = 10; k < 20; k++)
    {
      TEST_ASSERT_EQUAL_INT32_MESSAGE(arrayOrdered[k], a[k], message);
    }

    for (int j = length; j > 0; j--)
    {
      a[length - j] = j;
    }
  }
}

TEST(Sort, TestEmptyArray)
{
  int a[] = {};
  int arrayOrdered[] = {};
  int length = 0;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);
    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
  }
}

TEST(Sort, TestFloatValueArray) // This test generates segmentation fault error, indicating that the sort function cannot receive float values
{
  float a[] = {2.6, 3.7, 3.8, 3.9, 4, 1.1, 1.2, 1.3, 2.4, 2.5};
  float arrayOrdered[] = {1.1, 1.2, 1.3, 2.4, 2.5, 2.6, 3.7, 3.8, 3.9, 4};
  int length = 10;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);
    
    if (i < 2)
    {
      sort((void *)&a, length, (char *)type, i); // Needed to add this "(void *)&" to remove warning pointing type mismatch
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort((void *)&a, length, (char *)type, i); // Needed to add this "(void *)&" to remove warning pointing type mismatch
    }
    else
    {
      type = "Onlogn";
      sort((void *)&a, length, (char *)type, i); // Needed to add this "(void *)&" to remove warning pointing type mismatch
    }

    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(arrayOrdered, a, length, message);

  }
}

TEST(Sort, TestCharValueArray) // This test generates segmentation fault error, indicating that the sort function cannot receive char values
{
  char a[] = {'a', 'b', 'c', 'd', 'e'};
  char arrayOrdered[] = {'a', 'b', 'c', 'd', 'e'};
  int length = 5;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);
    
    if (i < 2)
    {
      sort((void *)&a, length, (char *)type, i); // Needed to add this "(void *)&" to remove warning pointing type mismatch
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort((void *)&a, length, (char *)type, i); // Needed to add this "(void *)&" to remove warning pointing type mismatch
    }
    else
    {
      type = "Onlogn";
      sort((void *)&a, length, (char *)type, i); // Needed to add this "(void *)&" to remove warning pointing type mismatch
    }

    TEST_ASSERT_EQUAL_STRING_ARRAY_MESSAGE(arrayOrdered, a, length, message);

  }
}

TEST(Sort, TestNegativeValuesArray) // This test generates segmentation fault error, indicating that the sort function cannot receive negative integer values
{
  int a[] = {-5, -4, -3, -2, -1};
  int arrayOrdered[] = {-1, -2, -3, -4, -5};
  int length = 5;
  const char *type = "On";
  char message[50];

  for (int i = 0; i < 8; i++)
  {
    sprintf(message, "Error in the index: %d", i);

    if (i < 2)
    {
      sort(a, length, (char *)type, i);
    }
    else if (i >= 2 && i < 5)
    {
      type = "On2";
      sort(a, length, (char *)type, i);
    }
    else
    {
      type = "Onlogn";
      sort(a, length, (char *)type, i);
    }

    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);

    for (int j = length; j > 0; j--)
    {
      a[length - j] = -j;
    }
  }
}