#include <Python.h>
#include "better_sleep.h"

// compile command
//  g++ -Wall -O0 -Wextra -shared -std=c++11 -fPIC $(python3-config --includes) pyEntrance.cpp -o better_sleep_backend$(python3-config --extension-suffix)

static PyObject* sleepWrapper(PyObject* self, PyObject* args) {
    float time;
    int num_threads;
    if (!PyArg_ParseTuple(args, "fi", &time, &num_threads)) {
        return NULL;
    }
    theSleep(time, num_threads);
    return Py_None;
}

static PyMethodDef MyMethods[] = {
    {"theSleep", sleepWrapper, METH_VARARGS, "Sleep on heavy cpu usage."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef theSleepModule = {
    PyModuleDef_HEAD_INIT,
    "better_sleep_backend",
    NULL,
    -1,
    MyMethods
};

PyMODINIT_FUNC PyInit_better_sleep_backend(void) {
    return PyModule_Create(&theSleepModule);
}
