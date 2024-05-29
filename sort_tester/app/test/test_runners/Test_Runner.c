#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
    RUN_TEST_CASE(Sort, ParametrosValidos);
    RUN_TEST_CASE(Sort, ComplexidadeInvalida);
    RUN_TEST_CASE(Sort, ComplexidadeInvalidaVazio);
    RUN_TEST_CASE(Sort, ComplexidadeValidaErrada);
    RUN_TEST_CASE(Sort, AlgoritmoInvalidoLimiteSuperior);
    RUN_TEST_CASE(Sort, AlgoritmoInvalidoLimiteInferior);
    RUN_TEST_CASE(Sort, TamanhoMaiorQueVetor);
    RUN_TEST_CASE(Sort, VetorValidoDesordenado);
    RUN_TEST_CASE(Sort, VetorValidoOrdenado);
    RUN_TEST_CASE(Sort, TamanhoValidoLimiteInferior);
    RUN_TEST_CASE(Sort, TamanhoValidoLimiteSuperior);
    RUN_TEST_CASE(Sort, TamanhoInvalidoLimiteInferior);
    RUN_TEST_CASE(Sort, TamanhoInvalidoLimiteSuperior);
    RUN_TEST_CASE(Sort, VetorValoresIguais);
    RUN_TEST_CASE(Sort, VetorValidoDesordenadoMeio);
    RUN_TEST_CASE(Sort, VetorVazio); 
    // RUN_TEST_CASE(Sort, VetorDeNegativos);
}