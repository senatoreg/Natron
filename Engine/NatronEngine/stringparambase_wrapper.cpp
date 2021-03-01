
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

#include "stringparambase_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void StringParamBaseWrapper::pysideInitQtMetaTypes()
{
}

StringParamBaseWrapper::~StringParamBaseWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_StringParamBaseFunc_addAsDependencyOf(PyObject* self, PyObject* args)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_StringParamBaseFunc_addAsDependencyOf_TypeError;

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
            QString cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_StringParamBaseFunc_addAsDependencyOf_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.addAsDependencyOf");
#else
        const char* overloads[] = {"int, NatronEngine.Param, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.addAsDependencyOf", overloads);
#endif
        return 0;
}

static PyObject* Sbk_StringParamBaseFunc_get(PyObject* self, PyObject* args)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_StringParamBaseFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get() const
        {

            if (!PyErr_Occurred()) {
                // get()const
                QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->get();
#if SHIBOKEN_MAJOR_VERSION >= 2
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
            }
            break;
        }
        case 1: // get(double frame) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(double)const
                QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->get(cppArg0);
#if SHIBOKEN_MAJOR_VERSION >= 2
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_StringParamBaseFunc_get_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.get");
#else
        const char* overloads[] = {"", "float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.get", overloads);
#endif
        return 0;
}

static PyObject* Sbk_StringParamBaseFunc_getDefaultValue(PyObject* self)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDefaultValue()const
            QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->getDefaultValue();
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_StringParamBaseFunc_getValue(PyObject* self)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValue()const
            QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->getValue();
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_StringParamBaseFunc_getValueAtTime(PyObject* self, PyObject* pyArg)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_StringParamBaseFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double)const
            QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->getValueAtTime(cppArg0);
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_StringParamBaseFunc_getValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParamBase.getValueAtTime");
#else
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParamBase.getValueAtTime", overloads);
#endif
        return 0;
}

static PyObject* Sbk_StringParamBaseFunc_restoreDefaultValue(PyObject* self)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));

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

static PyObject* Sbk_StringParamBaseFunc_set(PyObject* self, PyObject* args)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "set", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: set(QString)
    // 1: set(QString,double)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#else
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#endif
        if (numArgs == 1) {
            overloadId = 0; // set(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 1; // set(QString,double)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_StringParamBaseFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(const QString & x)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(QString)
                cppSelf->set(cppArg0);
            }
            break;
        }
        case 1: // set(const QString & x, double frame)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(QString,double)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_StringParamBaseFunc_set_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.set");
#else
        const char* overloads[] = {"unicode", "unicode, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.set", overloads);
#endif
        return 0;
}

static PyObject* Sbk_StringParamBaseFunc_setDefaultValue(PyObject* self, PyObject* pyArg)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultValue(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setDefaultValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_StringParamBaseFunc_setDefaultValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultValue(QString)
            cppSelf->setDefaultValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_StringParamBaseFunc_setDefaultValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParamBase.setDefaultValue");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParamBase.setDefaultValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_StringParamBaseFunc_setValue(PyObject* self, PyObject* pyArg)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_StringParamBaseFunc_setValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValue(QString)
            cppSelf->setValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_StringParamBaseFunc_setValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParamBase.setValue");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParamBase.setValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_StringParamBaseFunc_setValueAtTime(PyObject* self, PyObject* args)
{
    StringParamBaseWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamBaseWrapper*)((::StringParamBase*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setValueAtTime", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setValueAtTime(QString,double)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
#endif
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // setValueAtTime(QString,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_StringParamBaseFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValueAtTime(QString,double)
            cppSelf->setValueAtTime(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_StringParamBaseFunc_setValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.setValueAtTime");
#else
        const char* overloads[] = {"unicode, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.StringParamBase.setValueAtTime", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_StringParamBase_methods[] = {
    {"addAsDependencyOf", (PyCFunction)Sbk_StringParamBaseFunc_addAsDependencyOf, METH_VARARGS},
    {"get", (PyCFunction)Sbk_StringParamBaseFunc_get, METH_VARARGS},
    {"getDefaultValue", (PyCFunction)Sbk_StringParamBaseFunc_getDefaultValue, METH_NOARGS},
    {"getValue", (PyCFunction)Sbk_StringParamBaseFunc_getValue, METH_NOARGS},
    {"getValueAtTime", (PyCFunction)Sbk_StringParamBaseFunc_getValueAtTime, METH_O},
    {"restoreDefaultValue", (PyCFunction)Sbk_StringParamBaseFunc_restoreDefaultValue, METH_NOARGS},
    {"set", (PyCFunction)Sbk_StringParamBaseFunc_set, METH_VARARGS},
    {"setDefaultValue", (PyCFunction)Sbk_StringParamBaseFunc_setDefaultValue, METH_O},
    {"setValue", (PyCFunction)Sbk_StringParamBaseFunc_setValue, METH_O},
    {"setValueAtTime", (PyCFunction)Sbk_StringParamBaseFunc_setValueAtTime, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_StringParamBase_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_StringParamBase_clear(PyObject* self)
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
static SbkObjectType *_Sbk_StringParamBase_Type = nullptr;
static SbkObjectType *Sbk_StringParamBase_TypeF(void)
{
    return _Sbk_StringParamBase_Type;
}

static PyType_Slot Sbk_StringParamBase_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_StringParamBase_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_StringParamBase_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_StringParamBase_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_StringParamBase_spec = {
    "NatronEngine.StringParamBase",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_StringParamBase_slots
};
#else
static SbkObjectType Sbk_StringParamBase_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.StringParamBase",
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
    /*tp_traverse*/         Sbk_StringParamBase_traverse,
    /*tp_clear*/            Sbk_StringParamBase_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_StringParamBase_methods,
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

static void* Sbk_StringParamBase_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::StringParamBase*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void StringParamBase_PythonToCpp_StringParamBase_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_StringParamBase_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_StringParamBase_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_StringParamBase_PythonToCpp_StringParamBase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_StringParamBase_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_StringParamBase_Type))
#endif
        return StringParamBase_PythonToCpp_StringParamBase_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* StringParamBase_PTR_CppToPython_StringParamBase(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::StringParamBase *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_StringParamBase_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::StringParamBase*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_StringParamBase_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *StringParamBase_SignatureStrings[] = {
    "NatronEngine.StringParamBase.addAsDependencyOf(fromExprDimension:int,param:NatronEngine.Param,thisDimension:int)->QString",
    "1:NatronEngine.StringParamBase.get(frame:double)->QString",
    "0:NatronEngine.StringParamBase.get()->QString",
    "NatronEngine.StringParamBase.getDefaultValue()->QString",
    "NatronEngine.StringParamBase.getValue()->QString",
    "NatronEngine.StringParamBase.getValueAtTime(time:double)->QString",
    "NatronEngine.StringParamBase.restoreDefaultValue()",
    "0:NatronEngine.StringParamBase.set(x:QString)",
    "1:NatronEngine.StringParamBase.set(x:QString,frame:double)",
    "NatronEngine.StringParamBase.setDefaultValue(value:QString)",
    "NatronEngine.StringParamBase.setValue(value:QString)",
    "NatronEngine.StringParamBase.setValueAtTime(value:QString,time:double)",
    nullptr}; // Sentinel
#endif

void init_StringParamBase(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_StringParamBase_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "StringParamBase",
        "StringParamBase*",
        &Sbk_StringParamBase_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        StringParamBase_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::StringParamBase >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_StringParamBase_TypeF());
#else
    SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_StringParamBase_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "StringParamBase", "StringParamBase*",
        &Sbk_StringParamBase_Type, &Shiboken::callCppDestructor< ::StringParamBase >, (SbkObjectType*)SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_StringParamBase_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_StringParamBase_Type,
#endif
        StringParamBase_PythonToCpp_StringParamBase_PTR,
        is_StringParamBase_PythonToCpp_StringParamBase_PTR_Convertible,
        StringParamBase_PTR_CppToPython_StringParamBase);

    Shiboken::Conversions::registerConverterName(converter, "StringParamBase");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase*");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::StringParamBase).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::StringParamBaseWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_StringParamBase_TypeF(), &Sbk_StringParamBase_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_StringParamBase_Type, &Sbk_StringParamBase_typeDiscovery);
#endif


    StringParamBaseWrapper::pysideInitQtMetaTypes();
}
