#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Sort);
TEST_SETUP(Sort) {}
TEST_TEAR_DOWN(Sort) {}

TEST(Sort, ParametrosValidos) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
    const char *type;

	for (int algorithm = 0; algorithm < 8; algorithm++) {
		// ValidTest(a, length, algorithm);
        
        if (algorithm < 2)
            type = "On";
        else if (algorithm < 5)
            type = "On2";
        else
            type = "Onlogn";
            
        TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
    }
}

TEST(Sort, ComplexidadeInvalida) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type = "teste";
    
	for (int algorithm = 0; algorithm < 8; algorithm++)
		TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, algorithm));
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
    const char *type;
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		// InvalidTest(a, length, i);
        if (algorithm < 2)
            type = "On2";
        else if (algorithm < 5)
            type = "Onlogn";
        else
            type = "On";

        TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, algorithm));
    }
}

TEST(Sort, AlgoritmoInvalidoLimiteSuperior) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type = "On";

	TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, 9));
}

TEST(Sort, AlgoritmoInvalidoLimiteInferior) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5;
	const char *type = "On";

	TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, -1));
}

TEST(Sort, TamanhoMaiorQueVetor) {
	int a[] = {1, 2, 3, 4, 5};
	int length = 5; // Valgrind error
    const char *type;
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
		// ValidTest(a, length, algorithm);
        if (algorithm < 2)
            type = "On";
        else if (algorithm < 5)
            type = "On2";
        else
            type = "Onlogn";
            
        TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
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
        
        TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
        
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

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
        
        TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
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
        
        TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, algorithm));
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

TEST(Sort, TamanhoInvalidoLimiteSuperior) {
	int a[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int arrayOrdered[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int length = 21;
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
        
        TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, algorithm));
        TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
        
		for (int j = length; j > 0; j--)
			a[length - j] = j;
	}
}

// TODO Talvez remover
TEST(Sort, VetorValoresIguais) {
	int a[] = {9, 9, 9, 9, 9};
	int arrayOrdered[] = {9, 9, 9, 9, 9};
	int length = 5;
	char message[50];
    const char *type;
    
	for (int algorithm = 0; algorithm < 8; algorithm++) {
        if (algorithm < 2)
            type = "On";
        else if (algorithm < 5)
            type = "On2";
        else
            type = "Onlogn";
            
        TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
        
		sprintf(message, "Error in the index: %d", algorithm);
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
        
        TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
        
		TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

TEST(Sort, VetorValidoDesordenadoMeio) {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 13, 12, 11, 10, 9, 14, 15, 16, 17, 18, 19, 20};
	int arrayOrdered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19, 20};
	int length = 5;
    int pos_init = 8;
    int total_length = 20;
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
        
        sort(a+pos_init, length, (char *)type, algorithm);
        
		for (int k = 0; k < total_length; k++)
            TEST_ASSERT_EQUAL_INT32_MESSAGE(arrayOrdered[k], a[k], message);
        
		for (int j = length; j > 0; j--)
			a[pos_init + length - j] = j + pos_init;
	}
}

// Resulta em erro
TEST(Sort, VetorVazio) {
	int a[] = {};
	// int arrayOrdered[] = {};
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
        
        TEST_ASSERT_EQUAL(1, sort(a, length, (char *)type, algorithm));
		// TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
	}
}

// Segmentation fault
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
        
        TEST_ASSERT_EQUAL(0, sort(a, length, (char *)type, algorithm));
        TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(arrayOrdered, a, length, message);
		
		for (int j = length; j > 0; j--)
			a[length - j] = -j;
	}
}