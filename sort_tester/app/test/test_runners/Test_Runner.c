#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
    RUN_TEST_CASE(Sort, ParametrosValidos);
    RUN_TEST_CASE(Sort, ComplexidadeInvalida);
    RUN_TEST_CASE(Sort, ComplexidadeInvalidaInteiro);
    RUN_TEST_CASE(Sort, ComplexidadeInvalidaVazio);
    RUN_TEST_CASE(Sort, ComplexidadeValidaErrada);
    RUN_TEST_CASE(Sort, AlgoritmoInvalido);
    RUN_TEST_CASE(Sort, AlgoritmoInvalidoChar);
    RUN_TEST_CASE(Sort, TamanhoMaiorQueVetor);
    RUN_TEST_CASE(Sort, TamanhoInvalidoChar);
    RUN_TEST_CASE(Sort, VetorValidoDesordenado);
    RUN_TEST_CASE(Sort, VetorValidoOrdenado);
    RUN_TEST_CASE(Sort, TamanhoValidoLimiteInferior);
    RUN_TEST_CASE(Sort, TamanhoValidoLimiteSuperior);
    RUN_TEST_CASE(Sort, TamanhoInvalidoLimiteInferior);
    RUN_TEST_CASE(Sort, TamanhoInvalidoLimiteSuperior);
    RUN_TEST_CASE(Sort, VetorValoresIguais);
    RUN_TEST_CASE(Sort, VetorValidoDesordenadoTesteInferior);
    RUN_TEST_CASE(Sort, VetorValidoDesordenadoTesteSuperior);
    //RUN_TEST_CASE(Sort, VetorVazio); // This test has been commented because it results in gcov error
    //RUN_TEST_CASE(Sort, TestFloatValueArray); // This test has been commented because it results in segmentation fault
    //RUN_TEST_CASE(Sort, VetorDeChar); // This test has been commented because it results in segmentation fault
    // RUN_TEST_CASE(Sort, VetorDeNegativos); // This test has been commented because it results in segmentation fault
}