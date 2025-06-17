#define PY_SSIZE_T_CLEAN
#include "/usr/include/python3.13/Python.h"
#include <stdio.h>
#include <stddef.h>

// definiujemy stopień bezpieczeństwa mlkem (512/768/1024)
#define MLK_CONFIG_API_PARAMETER_SET 768
#define MLK_CONFIG_API_NAMESPACE_PREFIX mlkem

// importujemy funkcje mlkem
#include "mlkem/mlkem_native.h"
// implementacja pseudolosowych liczb, wyłącznie do testów
#include "test_only_rng/notrandombytes.h"


uint8_t pk[MLKEM_PUBLICKEYBYTES(MLK_CONFIG_API_PARAMETER_SET)];     // Public Key, wysyłany do strony B
uint8_t sk[MLKEM_SECRETKEYBYTES(MLK_CONFIG_API_PARAMETER_SET)];     // Secret Key
uint8_t ct[MLKEM_CIPHERTEXTBYTES(MLK_CONFIG_API_PARAMETER_SET)];    // c, ciphertext
uint8_t key_a[MLKEM_BYTES];                                         // klucz wspólny po stronie A
uint8_t key_b[MLKEM_BYTES];                                         // klucz wspólny po stronie B

// Pierwsza funkcja, generująca klucz publiczny i prywatny
static PyObject* kemtest_keygen(PyObject* self, PyObject* args) {
    randombytes_reset();
    printf("Generowanie pary kluczy...");
    mlkem_keypair(pk, sk);
    printf("Wygenerowane.");
    return 0;
}

// Funkcja zwracająca klucz publiczny
static PyObject* kemtest_get_pk(PyObject* self, PyObject *pObject){
    return (PyObject *) pk;
}

// Definicje metod
static PyMethodDef KemtestMethods[] = {
        {"keygen", kemtest_keygen, METH_VARARGS, "generuje klucze"},
        {"get_pk", kemtest_get_pk, METH_VARARGS, "zwraca klucz publiczny"},
        {NULL, NULL, 0, NULL}
};

// Definicja modułu
static struct PyModuleDef kemtestmodule = {
        PyModuleDef_HEAD_INIT,
        "kemtest",
        "Wymiana kluczy ml-kem",
        -1,
        KemtestMethods
};

// Inicjalizacja całości
PyMODINIT_FUNC PyInit_kemtest(void) {
    return PyModule_Create(&kemtestmodule);
}