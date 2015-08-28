#include "Python.h"
#include <cstdio>
#include <string>

using namespace std;

// Functions called from Python need to be declared as 'extern'
extern "C"
{
	// The 'say_hello' function that is called from within Python3
	static PyObject *say_hello(PyObject *self,PyObject *args)
	{
		const char *to_who;
		string out;
		if(!PyArg_ParseTuple(args,"s",&to_who))
			return NULL;

		out = "Hello " + string(to_who) + "!";

		return PyUnicode_FromString(out.c_str());
	}

	static PyMethodDef methods[] ={
		{   "say_hello",
			(PyCFunction)say_hello,
			METH_VARARGS|METH_KEYWORDS
		},
		{NULL, NULL}
	};

	PyDoc_STRVAR(module_doc, "Example Python3 extending.\n");

	static struct PyModuleDef moduledef = {
		PyModuleDef_HEAD_INIT,
		"hello",
		module_doc,
		-1,
		methods,
		NULL,
		NULL,
		NULL,
		NULL
	};

	PyObject *PyInit_hello(void)
	{
		PyObject *m;
		m = PyModule_Create(&moduledef);
		return m;
	}

}
