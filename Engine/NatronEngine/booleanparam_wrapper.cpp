
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

#include "booleanparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void BooleanParamWrapper::pysideInitQtMetaTypes()
{
}

BooleanParamWrapper::~BooleanParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_BooleanParamFunc_addAsDependencyOf(PyObject* self, PyObject* args)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_BooleanParamFunc_addAsDependencyOf_TypeError;

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
            bool cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_BooleanParamFunc_addAsDependencyOf_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.addAsDependencyOf");
#else
        const char* overloads[] = {"int, NatronEngine.Param, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.addAsDependencyOf", overloads);
#endif
        return 0;
}

static PyObject* Sbk_BooleanParamFunc_get(PyObject* self, PyObject* args)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_BooleanParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get() const
        {

            if (!PyErr_Occurred()) {
                // get()const
                bool cppResult = const_cast<const ::BooleanParamWrapper*>(cppSelf)->get();
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // get(double frame) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(double)const
                bool cppResult = const_cast<const ::BooleanParamWrapper*>(cppSelf)->get(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_BooleanParamFunc_get_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.get");
#else
        const char* overloads[] = {"", "float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.get", overloads);
#endif
        return 0;
}

static PyObject* Sbk_BooleanParamFunc_getDefaultValue(PyObject* self)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDefaultValue()const
            bool cppResult = const_cast<const ::BooleanParamWrapper*>(cppSelf)->getDefaultValue();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_BooleanParamFunc_getValue(PyObject* self)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValue()const
            bool cppResult = const_cast<const ::BooleanParamWrapper*>(cppSelf)->getValue();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_BooleanParamFunc_getValueAtTime(PyObject* self, PyObject* pyArg)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getValueAtTime(double)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // getValueAtTime(double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_BooleanParamFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double)const
            bool cppResult = const_cast<const ::BooleanParamWrapper*>(cppSelf)->getValueAtTime(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_BooleanParamFunc_getValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.BooleanParam.getValueAtTime");
#else
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.BooleanParam.getValueAtTime", overloads);
#endif
        return 0;
}

static PyObject* Sbk_BooleanParamFunc_restoreDefaultValue(PyObject* self)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restoreDefaultValue()
            cppSelf->restoreDefaultValue();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_BooleanParamFunc_set(PyObject* self, PyObject* args)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "set", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: set(bool)
    // 1: set(bool,double)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // set(bool)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 1; // set(bool,double)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_BooleanParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(bool x)
        {
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(bool)
                cppSelf->set(cppArg0);
            }
            break;
        }
        case 1: // set(bool x, double frame)
        {
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(bool,double)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_BooleanParamFunc_set_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.set");
#else
        const char* overloads[] = {"bool", "bool, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.set", overloads);
#endif
        return 0;
}

static PyObject* Sbk_BooleanParamFunc_setDefaultValue(PyObject* self, PyObject* pyArg)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultValue(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDefaultValue(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_BooleanParamFunc_setDefaultValue_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultValue(bool)
            cppSelf->setDefaultValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_BooleanParamFunc_setDefaultValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.BooleanParam.setDefaultValue");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.BooleanParam.setDefaultValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_BooleanParamFunc_setValue(PyObject* self, PyObject* pyArg)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setValue(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_BooleanParamFunc_setValue_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValue(bool)
            cppSelf->setValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_BooleanParamFunc_setValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.BooleanParam.setValue");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.BooleanParam.setValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_BooleanParamFunc_setValueAtTime(PyObject* self, PyObject* args)
{
    BooleanParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (BooleanParamWrapper*)((::BooleanParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setValueAtTime", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setValueAtTime(bool,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // setValueAtTime(bool,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_BooleanParamFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValueAtTime(bool,double)
            cppSelf->setValueAtTime(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_BooleanParamFunc_setValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.setValueAtTime");
#else
        const char* overloads[] = {"bool, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.BooleanParam.setValueAtTime", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_BooleanParam_methods[] = {
    {"addAsDependencyOf", (PyCFunction)Sbk_BooleanParamFunc_addAsDependencyOf, METH_VARARGS},
    {"get", (PyCFunction)Sbk_BooleanParamFunc_get, METH_VARARGS},
    {"getDefaultValue", (PyCFunction)Sbk_BooleanParamFunc_getDefaultValue, METH_NOARGS},
    {"getValue", (PyCFunction)Sbk_BooleanParamFunc_getValue, METH_NOARGS},
    {"getValueAtTime", (PyCFunction)Sbk_BooleanParamFunc_getValueAtTime, METH_O},
    {"restoreDefaultValue", (PyCFunction)Sbk_BooleanParamFunc_restoreDefaultValue, METH_NOARGS},
    {"set", (PyCFunction)Sbk_BooleanParamFunc_set, METH_VARARGS},
    {"setDefaultValue", (PyCFunction)Sbk_BooleanParamFunc_setDefaultValue, METH_O},
    {"setValue", (PyCFunction)Sbk_BooleanParamFunc_setValue, METH_O},
    {"setValueAtTime", (PyCFunction)Sbk_BooleanParamFunc_setValueAtTime, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_BooleanParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_BooleanParam_clear(PyObject* self)
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
static SbkObjectType *_Sbk_BooleanParam_Type = nullptr;
static SbkObjectType *Sbk_BooleanParam_TypeF(void)
{
    return _Sbk_BooleanParam_Type;
}

static PyType_Slot Sbk_BooleanParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_BooleanParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_BooleanParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_BooleanParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_BooleanParam_spec = {
    "NatronEngine.BooleanParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_BooleanParam_slots
};
#else
static SbkObjectType Sbk_BooleanParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.BooleanParam",
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
    /*tp_traverse*/         Sbk_BooleanParam_traverse,
    /*tp_clear*/            Sbk_BooleanParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_BooleanParam_methods,
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

static void* Sbk_BooleanParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::BooleanParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void BooleanParam_PythonToCpp_BooleanParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_BooleanParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_BooleanParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_BooleanParam_PythonToCpp_BooleanParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_BooleanParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_BooleanParam_Type))
#endif
        return BooleanParam_PythonToCpp_BooleanParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* BooleanParam_PTR_CppToPython_BooleanParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::BooleanParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_BooleanParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::BooleanParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_BooleanParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *BooleanParam_SignatureStrings[] = {
    "NatronEngine.BooleanParam.addAsDependencyOf(fromExprDimension:int,param:NatronEngine.Param,thisDimension:int)->bool",
    "0:NatronEngine.BooleanParam.get()->bool",
    "1:NatronEngine.BooleanParam.get(frame:double)->bool",
    "NatronEngine.BooleanParam.getDefaultValue()->bool",
    "NatronEngine.BooleanParam.getValue()->bool",
    "NatronEngine.BooleanParam.getValueAtTime(time:double)->bool",
    "NatronEngine.BooleanParam.restoreDefaultValue()",
    "0:NatronEngine.BooleanParam.set(x:bool)",
    "1:NatronEngine.BooleanParam.set(x:bool,frame:double)",
    "NatronEngine.BooleanParam.setDefaultValue(value:bool)",
    "NatronEngine.BooleanParam.setValue(value:bool)",
    "NatronEngine.BooleanParam.setValueAtTime(value:bool,time:double)",
    nullptr}; // Sentinel
#endif

void init_BooleanParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_BooleanParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "BooleanParam",
        "BooleanParam*",
        &Sbk_BooleanParam_spec,
        BooleanParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_NAMESPACE::BooleanParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_BooleanParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_BooleanParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "BooleanParam", "BooleanParam*",
        &Sbk_BooleanParam_Type, &Shiboken::callCppDestructor< ::BooleanParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_BooleanParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_BooleanParam_Type,
#endif
        BooleanParam_PythonToCpp_BooleanParam_PTR,
        is_BooleanParam_PythonToCpp_BooleanParam_PTR_Convertible,
        BooleanParam_PTR_CppToPython_BooleanParam);

    Shiboken::Conversions::registerConverterName(converter, "BooleanParam");
    Shiboken::Conversions::registerConverterName(converter, "BooleanParam*");
    Shiboken::Conversions::registerConverterName(converter, "BooleanParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::BooleanParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::BooleanParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_BooleanParam_TypeF(), &Sbk_BooleanParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_BooleanParam_Type, &Sbk_BooleanParam_typeDiscovery);
#endif


    BooleanParamWrapper::pysideInitQtMetaTypes();
}
