#define PY_SSIZE_T_CLEAN
#include "/usr/include/python3.13/Python.h"
#include <stdio.h>
#include <stddef.h>

#define MLK_CONFIG_API_PARAMETER_SET MLK_CONFIG_PARAMETER_SET
#define MLK_CONFIG_API_NAMESPACE_PREFIX mlkem
#include "mlkem/mlkem_native.h"
#include "mlkem/randombytes.h"



// Funkcja na dodawanie 2 liczb całkowitych
static PyObject* minos_add(PyObject* self, PyObject* args) {
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    return PyLong_FromLong(a + b);
}

// Funkcja na mnożenie 2 liczb całkowitych
static PyObject* minos_multiply(PyObject* self, PyObject* args) {
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    return PyLong_FromLong(a * b);
}

// Definicje metod
static PyMethodDef MinosMethods[] = {
        {"add", minos_add, METH_VARARGS, "Add two integers"},
        {"multiply", minos_multiply, METH_VARARGS, "Multiply two integers"},
        {NULL, NULL, 0, NULL}
};

// Definicja modułu
static struct PyModuleDef minosmodule = {
        PyModuleDef_HEAD_INIT,
        "minos",
        "Judgement",
        -1,
        MinosMethods
};

// Funkcja do inicjalizacji całości
PyMODINIT_FUNC PyInit_minos(void) {
    return PyModule_Create(&minosmodule);
}
