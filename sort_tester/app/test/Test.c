#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Sort);
TEST_SETUP(Sort) {}
TEST_TEAR_DOWN(Sort) {}

void ValidTest(int *a, int length, int algorithm) {
	const char *type;
	if (algorithm < 2)
        type = "On";
	else if (algorithm < 5)
		type = "On2";
	else
		type = "Onlogn";
    
    TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
}

void InvalidTest(int *a, int length, int algorithm) {
	const char *type;
	if (algorithm < 2)
        type = "On2";
	else if (algorithm < 5)
		type = "Onlogn";
	else
		type = "On";
	
    TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, algorithm));
}

TEST(Sort, ParametrosValidos) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;

	for (int algorithm = 0; algorithm < 8; algorithm++)
		ValidTest(a, length, algorithm);
}

TEST(Sort, ComplexidadeInvalida) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type = "T1";
    
	for (int algorithm = 0; algorithm < 8; algorithm++)
		TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, algorithm));
}


// TODO Talvez remover
TEST(Sort, ComplexidadeInvalidaInteiro) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	int type = 2;

	TEST_ASSERT_EQUAL(1, sort(a, length, (void *)&type, 7)); // Needed to add this "(void *)&" to remove warning pointing type mismatch
}

TEST(Sort, ComplexidadeInvalidaVazio) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type = "";

	for (int i = 0; i < 8; i++)
		TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, i));
}

TEST(Sort, ComplexidadeValidaErrada) {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = 10;

	for (int i = 0; i < 8; i++)
		InvalidTest(a, length, i);
}

TEST(Sort, AlgoritmoInvalido) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type = "On";

	TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, 9));
}

TEST(Sort, AlgoritmoInvalidoChar) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type = "On";

	TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, 'a'));
}

TEST(Sort, TamanhoMaiorQueVetor) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5; // Valgrind error, used to be: int length = 6;
    
	for (int i = 0; i < 8; i++)
		ValidTest(a, length, i);
}

// TODO Remover
TEST(Sort, TamanhoInvalidoChar) {
	int a[] = {1, 2, 3, 4, 5};
	char length = 'i'-'d'; // Only works because ASCII of " 'i' - 'd' " translates to the integer 5, otherwise causes sanitizer error
	const char *type = "On";
    
	for (int i = 0; i < 8; i++) {
		if (i < 2)
			TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, i));
		else if (i >= 2 && i < 5) {
			type = "On2";
			TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, i));
		}
		else {
			type = "Onlogn";
			TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, i));
		}
	}
}

TEST(Sort, VetorValidoDesordenado) {
	int a[] = {5, 4, 3, 2, 1};
	int arrayOrdered[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type;
	char message[50];
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
        
		if (algorithm < 2)
            type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
        
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

TEST(Sort, TamanhoValidoLimiteInferior) {
	int a[] = {2, 1};
	int arrayOrdered[] = {1, 2};
	int length = 2;
	const char *type;
	char message[50];
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
        
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

// 
TEST(Sort, TamanhoValidoLimiteSuperior) {
	int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
	int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
	int length = 20;
	const char *type;
	char message[50];

	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
        
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

TEST(Sort, TamanhoInvalidoLimiteInferior) {
	int a[] = {1};
	int arrayOrdered[] = {1};
	int length = 1;
	const char *type;
	char message[50];
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		if (algorithm < 2)
			type = "On";		
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        sort(a, length, (char *)type, algorithm);
        
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

TEST(Sort, TamanhoInvalidoLimiteSuperior) {
	int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 21}; // Only works because the value 21 is in the index 20 and not being changed
	// int a[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20, 21};
	int length = 20; // Should be 21, but then the sort function would not work
	const char *type;
	char message[50];
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		if (algorithm < 2)
            type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
        
		for (int k = 0; k < 20; k++)
			TEST_ASSERT_EQUAL_INT32_MESSAGE(arrayOrdered[k], a[k], message);
        
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

// TODO Talvez remover
TEST(Sort, VetorValoresIguais) {
	int a[] = {1, 1, 1, 1, 1};
	int arrayOrdered[] = {1, 1, 1, 1, 1};
	int length = 5;
	char message[50];
    
	for (int i = 0; i < 8; i++) {
		ValidTest(a, length, i);
		sprintf(message, "Error in the index: %d", i);
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

TEST(Sort, VetorValidoOrdenado) {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
	int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
	int length = 20;
	const char *type;
	char message[50];
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
        
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

// TODO parece desnecessario
TEST(Sort, VetorValidoDesordenadoTesteInferior) {
	int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
	int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
	int length = 20;
	const char *type;
	char message[50];
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
        
        for (int k = 0; k < 10; k++)
			TEST_ASSERT_EQUAL_INT32_MESSAGE(arrayOrdered[k], a[k], message);
		
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

// TODO parece desnecessario
TEST(Sort, VetorValidoDesordenadoTesteSuperior) {
	int a[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
	int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
	int length = 20;
	const char *type;
	char message[50];
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
        
		for (int k = 10; k < 20; k++)
            TEST_ASSERT_EQUAL_INT32_MESSAGE(arrayOrdered[k], a[k], message);
        
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

// Eesults in gcov error
TEST(Sort, VetorVazio) {
	int a[] = {};
	int arrayOrdered[] = {};
	int length = 0;
	const char *type;
    char message[50];
	
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		
        if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort(a, length, (char *)type, algorithm);
        
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

 // This test generates segmentation fault error, indicating that the sort function cannot receive float values
TEST(Sort, TestFloatValueArray) {
	float a[] = {2.6, 3.7, 3.8, 3.9, 4, 1.1, 1.2, 1.3, 2.4, 2.5};
	float arrayOrdered[] = {1.1, 1.2, 1.3, 2.4, 2.5, 2.6, 3.7, 3.8, 3.9, 4};
	int length = 10;
	const char *type;
    char message[50];
	
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort((void *)&a, length, (char *)type, algorithm); // Needed to add this "(void *)&" to remove warning pointing type mismatch
        
		TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

// This test generates segmentation fault error, indicating that the sort function cannot receive char values
TEST(Sort, VetorDeChar) {
	char a[] = {'a', 'b', 'c', 'd', 'e'};
	char arrayOrdered[] = {'a', 'b', 'c', 'd', 'e'};
	int length = 5;
	const char *type;
    char message[50];
	
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		sprintf(message, "Error in the index: %d", algorithm);
		
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        
        sort((void *)&a, length, (char *)type, algorithm); // Needed to add this "(void *)&" to remove warning pointing type mismatch
        
		TEST_ASSERT_EQUAL_STRING_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

// This test generates segmentation fault error, indicating that the sort function cannot receive negative integer values
TEST(Sort, VetorDeNegativos) {
	int a[] = {-5, -4, -3, -2, -1};
	int arrayOrdered[] = {-1, -2, -3, -4, -5};
	int length = 5;
	const char *type;
    char message[50];
	
	for (int algorithm = 0; algorithm < 8; algorithm++) {
        sprintf(message, "Error in the index: %d", algorithm);
		
		if (algorithm < 2)
			type = "On";
		else if (algorithm < 5)
			type = "On2";
		else
			type = "Onlogn";
        sort(a, length, (char *)type, algorithm);
        
        TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
		
		for (int j = length; j > 0; j--)
			a[length - j] = -j;
	}
}