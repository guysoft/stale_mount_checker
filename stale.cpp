#include <Python.h>

#include <unistd.h>
#include <iso646.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static PyObject * SpamError;

static PyObject *
stale_system(PyObject *self, PyObject * args)
{
	const char *command;
        struct stat st;
        int ret;

        if(!PyArg_ParseTuple(args, "s", &command))
                return NULL;

        ret = stat(command, &st);
        if(ret == -1 and errno == ESTALE){
            return PyBool_FromLong(1);
        }
        return PyBool_FromLong(0);

}

PyMODINIT_FUNC
initstale(void)
{
	PyObject *m;
	static PyMethodDef SpamMethods[] = {
		{"is_stale", stale_system, METH_VARARGS, "Execute a shell command."},
		{NULL, NULL, 0, NULL}
	};
	m = Py_InitModule("stale", SpamMethods);
	if ( m == NULL )
		return;

	SpamError = PyErr_NewException("spam.error", NULL, NULL);
	Py_INCREF(SpamError);
	PyModule_AddObject(m, "error", SpamError);
}

int
main(int argc, char *argv[])
{
	Py_SetProgramName(argv[0]);
	Py_Initialize();
	initstale();
}
