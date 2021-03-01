
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <shiboken.h> // produces many warnings
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#if SHIBOKEN_MAJOR_VERSION < 2
#include <typeresolver.h>
#endif
#include <typeinfo>
#include "natronengine_python.h"
#include "natron_helper.h"

#include "doubleparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void DoubleParamWrapper::pysideInitQtMetaTypes()
{
}

DoubleParamWrapper::~DoubleParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_DoubleParamFunc_addAsDependencyOf(PyObject* self, PyObject* args)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addAsDependencyOf", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addAsDependencyOf(int,Param*,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // addAsDependencyOf(int,Param*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_addAsDependencyOf_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::Param* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addAsDependencyOf(int,Param*,int)
            double cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_addAsDependencyOf_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.addAsDependencyOf");
#else
        const char* overloads[] = {"int, NatronEngine.Param, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.addAsDependencyOf", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_get(PyObject* self, PyObject* args)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "get", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: get()const
    // 1: get(double)const
    if (numArgs == 0) {
        overloadId = 0; // get()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        overloadId = 1; // get(double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get() const
        {

            if (!PyErr_Occurred()) {
                // get()const
                double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->get();
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
            }
            break;
        }
        case 1: // get(double frame) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(double)const
                double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->get(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_get_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.get");
#else
        const char* overloads[] = {"", "float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.get", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_getDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getDefaultValue(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getDefaultValue", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getDefaultValue(int)const
    if (numArgs == 0) {
        overloadId = 0; // getDefaultValue(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getDefaultValue(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_getDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getDefaultValue(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_DoubleParamFunc_getDefaultValue_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getDefaultValue(int)const
            double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->getDefaultValue(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_getDefaultValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getDefaultValue");
#else
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getDefaultValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_getDisplayMaximum(PyObject* self, PyObject* pyArg)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getDisplayMaximum(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getDisplayMaximum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_getDisplayMaximum_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getDisplayMaximum(int)const
            double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->getDisplayMaximum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_getDisplayMaximum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.DoubleParam.getDisplayMaximum");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.DoubleParam.getDisplayMaximum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_getDisplayMinimum(PyObject* self, PyObject* pyArg)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getDisplayMinimum(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getDisplayMinimum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_getDisplayMinimum_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getDisplayMinimum(int)const
            double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->getDisplayMinimum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_getDisplayMinimum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.DoubleParam.getDisplayMinimum");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.DoubleParam.getDisplayMinimum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_getMaximum(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getMaximum(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getMaximum", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getMaximum(int)const
    if (numArgs == 0) {
        overloadId = 0; // getMaximum(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getMaximum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_getMaximum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getMaximum(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_DoubleParamFunc_getMaximum_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getMaximum(int)const
            double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->getMaximum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_getMaximum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getMaximum");
#else
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getMaximum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_getMinimum(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getMinimum(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getMinimum", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getMinimum(int)const
    if (numArgs == 0) {
        overloadId = 0; // getMinimum(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getMinimum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_getMinimum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getMinimum(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_DoubleParamFunc_getMinimum_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getMinimum(int)const
            double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->getMinimum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_getMinimum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getMinimum");
#else
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getMinimum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_getValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getValue(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getValue", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getValue(int)const
    if (numArgs == 0) {
        overloadId = 0; // getValue(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getValue(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_getValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getValue(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_DoubleParamFunc_getValue_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getValue(int)const
            double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->getValue(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_getValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getValue");
#else
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_getValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getValueAtTime(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getValueAtTime(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:getValueAtTime", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: getValueAtTime(double,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getValueAtTime(double,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // getValueAtTime(double,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.getValueAtTime(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_DoubleParamFunc_getValueAtTime_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double,int)const
            double cppResult = const_cast<const ::DoubleParamWrapper*>(cppSelf)->getValueAtTime(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_DoubleParamFunc_getValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getValueAtTime");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.getValueAtTime", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_restoreDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.restoreDefaultValue(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:restoreDefaultValue", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: restoreDefaultValue(int)
    if (numArgs == 0) {
        overloadId = 0; // restoreDefaultValue(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // restoreDefaultValue(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_restoreDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.restoreDefaultValue(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_DoubleParamFunc_restoreDefaultValue_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // restoreDefaultValue(int)
            cppSelf->restoreDefaultValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_restoreDefaultValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.restoreDefaultValue");
#else
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.restoreDefaultValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_set(PyObject* self, PyObject* args)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "set", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: set(double)
    // 1: set(double,double)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // set(double)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 1; // set(double,double)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(double x)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(double)
                cppSelf->set(cppArg0);
            }
            break;
        }
        case 1: // set(double x, double frame)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(double,double)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_set_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.set");
#else
        const char* overloads[] = {"float", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.set", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_setDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDefaultValue(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDefaultValue(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setDefaultValue", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDefaultValue(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setDefaultValue(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setDefaultValue(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_setDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDefaultValue(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_DoubleParamFunc_setDefaultValue_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDefaultValue(double,int)
            cppSelf->setDefaultValue(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_setDefaultValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setDefaultValue");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setDefaultValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_setDisplayMaximum(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDisplayMaximum(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDisplayMaximum(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setDisplayMaximum", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDisplayMaximum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setDisplayMaximum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setDisplayMaximum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_setDisplayMaximum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDisplayMaximum(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_DoubleParamFunc_setDisplayMaximum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDisplayMaximum(double,int)
            cppSelf->setDisplayMaximum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_setDisplayMaximum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setDisplayMaximum");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setDisplayMaximum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_setDisplayMinimum(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDisplayMinimum(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDisplayMinimum(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setDisplayMinimum", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDisplayMinimum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setDisplayMinimum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setDisplayMinimum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_setDisplayMinimum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setDisplayMinimum(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_DoubleParamFunc_setDisplayMinimum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDisplayMinimum(double,int)
            cppSelf->setDisplayMinimum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_setDisplayMinimum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setDisplayMinimum");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setDisplayMinimum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_setMaximum(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setMaximum(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setMaximum(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setMaximum", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setMaximum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setMaximum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setMaximum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_setMaximum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setMaximum(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_DoubleParamFunc_setMaximum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setMaximum(double,int)
            cppSelf->setMaximum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_setMaximum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setMaximum");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setMaximum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_setMinimum(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setMinimum(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setMinimum(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setMinimum", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setMinimum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setMinimum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setMinimum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_setMinimum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setMinimum(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_DoubleParamFunc_setMinimum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setMinimum(double,int)
            cppSelf->setMinimum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_setMinimum_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setMinimum");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setMinimum", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_setValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setValue(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setValue(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setValue", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setValue(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setValue(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setValue(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_setValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setValue(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_DoubleParamFunc_setValue_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValue(double,int)
            cppSelf->setValue(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_setValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setValue");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_DoubleParamFunc_setValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    DoubleParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (DoubleParamWrapper*)((::DoubleParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setValueAtTime(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setValueAtTime(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setValueAtTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setValueAtTime(double,double,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setValueAtTime(double,double,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setValueAtTime(double,double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_DoubleParamFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.DoubleParam.setValueAtTime(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_DoubleParamFunc_setValueAtTime_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setValueAtTime(double,double,int)
            cppSelf->setValueAtTime(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_DoubleParamFunc_setValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setValueAtTime");
#else
        const char* overloads[] = {"float, float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.DoubleParam.setValueAtTime", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_DoubleParam_methods[] = {
    {"addAsDependencyOf", (PyCFunction)Sbk_DoubleParamFunc_addAsDependencyOf, METH_VARARGS},
    {"get", (PyCFunction)Sbk_DoubleParamFunc_get, METH_VARARGS},
    {"getDefaultValue", (PyCFunction)Sbk_DoubleParamFunc_getDefaultValue, METH_VARARGS|METH_KEYWORDS},
    {"getDisplayMaximum", (PyCFunction)Sbk_DoubleParamFunc_getDisplayMaximum, METH_O},
    {"getDisplayMinimum", (PyCFunction)Sbk_DoubleParamFunc_getDisplayMinimum, METH_O},
    {"getMaximum", (PyCFunction)Sbk_DoubleParamFunc_getMaximum, METH_VARARGS|METH_KEYWORDS},
    {"getMinimum", (PyCFunction)Sbk_DoubleParamFunc_getMinimum, METH_VARARGS|METH_KEYWORDS},
    {"getValue", (PyCFunction)Sbk_DoubleParamFunc_getValue, METH_VARARGS|METH_KEYWORDS},
    {"getValueAtTime", (PyCFunction)Sbk_DoubleParamFunc_getValueAtTime, METH_VARARGS|METH_KEYWORDS},
    {"restoreDefaultValue", (PyCFunction)Sbk_DoubleParamFunc_restoreDefaultValue, METH_VARARGS|METH_KEYWORDS},
    {"set", (PyCFunction)Sbk_DoubleParamFunc_set, METH_VARARGS},
    {"setDefaultValue", (PyCFunction)Sbk_DoubleParamFunc_setDefaultValue, METH_VARARGS|METH_KEYWORDS},
    {"setDisplayMaximum", (PyCFunction)Sbk_DoubleParamFunc_setDisplayMaximum, METH_VARARGS|METH_KEYWORDS},
    {"setDisplayMinimum", (PyCFunction)Sbk_DoubleParamFunc_setDisplayMinimum, METH_VARARGS|METH_KEYWORDS},
    {"setMaximum", (PyCFunction)Sbk_DoubleParamFunc_setMaximum, METH_VARARGS|METH_KEYWORDS},
    {"setMinimum", (PyCFunction)Sbk_DoubleParamFunc_setMinimum, METH_VARARGS|METH_KEYWORDS},
    {"setValue", (PyCFunction)Sbk_DoubleParamFunc_setValue, METH_VARARGS|METH_KEYWORDS},
    {"setValueAtTime", (PyCFunction)Sbk_DoubleParamFunc_setValueAtTime, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_DoubleParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_DoubleParam_clear(PyObject* self)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
#endif
}
// Class Definition -----------------------------------------------
extern "C" {
#if SHIBOKEN_MAJOR_VERSION >= 2
static SbkObjectType *_Sbk_DoubleParam_Type = nullptr;
static SbkObjectType *Sbk_DoubleParam_TypeF(void)
{
    return _Sbk_DoubleParam_Type;
}

static PyType_Slot Sbk_DoubleParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_DoubleParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_DoubleParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_DoubleParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_DoubleParam_spec = {
    "NatronEngine.DoubleParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_DoubleParam_slots
};
#else
static SbkObjectType Sbk_DoubleParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.DoubleParam",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_DoubleParam_traverse,
    /*tp_clear*/            Sbk_DoubleParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_DoubleParam_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
#endif
} //extern

static void* Sbk_DoubleParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::DoubleParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void DoubleParam_PythonToCpp_DoubleParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_DoubleParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_DoubleParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_DoubleParam_PythonToCpp_DoubleParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_DoubleParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_DoubleParam_Type))
#endif
        return DoubleParam_PythonToCpp_DoubleParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* DoubleParam_PTR_CppToPython_DoubleParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::DoubleParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_DoubleParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::DoubleParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_DoubleParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *DoubleParam_SignatureStrings[] = {
    "NatronEngine.DoubleParam.addAsDependencyOf(fromExprDimension:int,param:NatronEngine.Param,thisDimension:int,fromExprView:QString)->double",
    "0:NatronEngine.DoubleParam.get()->double",
    "1:NatronEngine.DoubleParam.get(frame:double)->double",
    "NatronEngine.DoubleParam.getDefaultValue(dimension:int=0)->double",
    "NatronEngine.DoubleParam.getDisplayMaximum(dimension:int)->double",
    "NatronEngine.DoubleParam.getDisplayMinimum(dimension:int)->double",
    "NatronEngine.DoubleParam.getMaximum(dimension:int=0)->double",
    "NatronEngine.DoubleParam.getMinimum(dimension:int=0)->double",
    "NatronEngine.DoubleParam.getValue(dimension:int=0)->double",
    "NatronEngine.DoubleParam.getValueAtTime(time:double,dimension:int=0)->double",
    "NatronEngine.DoubleParam.restoreDefaultValue(dimension:int=0)",
    "0:NatronEngine.DoubleParam.set(x:double)",
    "1:NatronEngine.DoubleParam.set(x:double,frame:double)",
    "NatronEngine.DoubleParam.setDefaultValue(value:double,dimension:int=0)",
    "NatronEngine.DoubleParam.setDisplayMaximum(maximum:double,dimension:int=0)",
    "NatronEngine.DoubleParam.setDisplayMinimum(minimum:double,dimension:int=0)",
    "NatronEngine.DoubleParam.setMaximum(maximum:double,dimension:int=0)",
    "NatronEngine.DoubleParam.setMinimum(minimum:double,dimension:int=0)",
    "NatronEngine.DoubleParam.setValue(value:double,dimension:int=0)",
    "NatronEngine.DoubleParam.setValueAtTime(value:double,time:double,dimension:int=0)",
    nullptr}; // Sentinel
#endif

void init_DoubleParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_DoubleParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "DoubleParam",
        "DoubleParam*",
        &Sbk_DoubleParam_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        DoubleParam_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::DoubleParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_DoubleParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_DoubleParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "DoubleParam", "DoubleParam*",
        &Sbk_DoubleParam_Type, &Shiboken::callCppDestructor< ::DoubleParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_DoubleParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_DoubleParam_Type,
#endif
        DoubleParam_PythonToCpp_DoubleParam_PTR,
        is_DoubleParam_PythonToCpp_DoubleParam_PTR_Convertible,
        DoubleParam_PTR_CppToPython_DoubleParam);

    Shiboken::Conversions::registerConverterName(converter, "DoubleParam");
    Shiboken::Conversions::registerConverterName(converter, "DoubleParam*");
    Shiboken::Conversions::registerConverterName(converter, "DoubleParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::DoubleParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::DoubleParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_DoubleParam_TypeF(), &Sbk_DoubleParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_DoubleParam_Type, &Sbk_DoubleParam_typeDiscovery);
#endif


    DoubleParamWrapper::pysideInitQtMetaTypes();
}
