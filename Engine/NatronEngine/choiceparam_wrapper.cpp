
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

#include "choiceparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>
#include <list>
#include <utility>


// Native ---------------------------------------------------------

void ChoiceParamWrapper::pysideInitQtMetaTypes()
{
}

ChoiceParamWrapper::~ChoiceParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_ChoiceParamFunc_addAsDependencyOf(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_addAsDependencyOf_TypeError;

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
            int cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ChoiceParamFunc_addAsDependencyOf_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.addAsDependencyOf");
#else
        const char* overloads[] = {"int, NatronEngine.Param, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.addAsDependencyOf", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_addOption(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addOption", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addOption(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // addOption(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_addOption_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addOption(QString,QString)
            cppSelf->addOption(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ChoiceParamFunc_addOption_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.addOption");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.addOption", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_get(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get() const
        {

            if (!PyErr_Occurred()) {
                // get()const
                int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->get();
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // get(double frame) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(double)const
                int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->get(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ChoiceParamFunc_get_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.get");
#else
        const char* overloads[] = {"", "float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.get", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_getDefaultValue(PyObject* self)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDefaultValue()const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getDefaultValue();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ChoiceParamFunc_getNumOptions(PyObject* self)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumOptions()const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getNumOptions();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ChoiceParamFunc_getOption(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getOption(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getOption(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_getOption_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getOption(int)const
            QString cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getOption(cppArg0);
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

    Sbk_ChoiceParamFunc_getOption_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.getOption");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.getOption", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_getOptions(PyObject* self)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getOptions()const
            QStringList cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getOptions();
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ChoiceParamFunc_getValue(PyObject* self)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValue()const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getValue();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ChoiceParamFunc_getValueAtTime(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double)const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getValueAtTime(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ChoiceParamFunc_getValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.getValueAtTime");
#else
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.getValueAtTime", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_restoreDefaultValue(PyObject* self)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));

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

static PyObject* Sbk_ChoiceParamFunc_set(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
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
    // 1: set(int)
    // 2: set(int,double)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // set(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 2; // set(int,double)
        }
    } else if (numArgs == 1
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#endif
        overloadId = 0; // set(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(const QString & label)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(QString)
                cppSelf->set(cppArg0);
            }
            break;
        }
        case 1: // set(int x)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(int)
                cppSelf->set(cppArg0);
            }
            break;
        }
        case 2: // set(int x, double frame)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(int,double)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ChoiceParamFunc_set_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.set");
#else
        const char* overloads[] = {"unicode", "int", "int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.set", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_setDefaultValue(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultValue(QString)
    // 1: setDefaultValue(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // setDefaultValue(int)
#if SHIBOKEN_MAJOR_VERSION >= 2
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setDefaultValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_setDefaultValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setDefaultValue(const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDefaultValue(QString)
                cppSelf->setDefaultValue(cppArg0);
            }
            break;
        }
        case 1: // setDefaultValue(int value)
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDefaultValue(int)
                cppSelf->setDefaultValue(cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ChoiceParamFunc_setDefaultValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.setDefaultValue");
#else
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.setDefaultValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_setOptions(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOptions(std::list<std::pair<QString,QString> >)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOptions(std::list<std::pair<QString,QString> >)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_setOptions_TypeError;

    // Call function/method
    {
        ::std::list<std::pair<QString, QString > > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOptions(std::list<std::pair<QString,QString> >)
            cppSelf->setOptions(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ChoiceParamFunc_setOptions_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.setOptions");
#else
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.setOptions", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_setValue(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(QString)
    // 1: setValue(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // setValue(int)
#if SHIBOKEN_MAJOR_VERSION >= 2
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_setValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setValue(const QString & label)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setValue(QString)
                cppSelf->setValue(cppArg0);
            }
            break;
        }
        case 1: // setValue(int value)
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setValue(int)
                cppSelf->setValue(cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ChoiceParamFunc_setValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.setValue");
#else
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ChoiceParam.setValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ChoiceParamFunc_setValueAtTime(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ChoiceParamWrapper*)((::ChoiceParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setValueAtTime", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setValueAtTime(int,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // setValueAtTime(int,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ChoiceParamFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValueAtTime(int,double)
            cppSelf->setValueAtTime(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ChoiceParamFunc_setValueAtTime_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.setValueAtTime");
#else
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ChoiceParam.setValueAtTime", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_ChoiceParam_methods[] = {
    {"addAsDependencyOf", (PyCFunction)Sbk_ChoiceParamFunc_addAsDependencyOf, METH_VARARGS},
    {"addOption", (PyCFunction)Sbk_ChoiceParamFunc_addOption, METH_VARARGS},
    {"get", (PyCFunction)Sbk_ChoiceParamFunc_get, METH_VARARGS},
    {"getDefaultValue", (PyCFunction)Sbk_ChoiceParamFunc_getDefaultValue, METH_NOARGS},
    {"getNumOptions", (PyCFunction)Sbk_ChoiceParamFunc_getNumOptions, METH_NOARGS},
    {"getOption", (PyCFunction)Sbk_ChoiceParamFunc_getOption, METH_O},
    {"getOptions", (PyCFunction)Sbk_ChoiceParamFunc_getOptions, METH_NOARGS},
    {"getValue", (PyCFunction)Sbk_ChoiceParamFunc_getValue, METH_NOARGS},
    {"getValueAtTime", (PyCFunction)Sbk_ChoiceParamFunc_getValueAtTime, METH_O},
    {"restoreDefaultValue", (PyCFunction)Sbk_ChoiceParamFunc_restoreDefaultValue, METH_NOARGS},
    {"set", (PyCFunction)Sbk_ChoiceParamFunc_set, METH_VARARGS},
    {"setDefaultValue", (PyCFunction)Sbk_ChoiceParamFunc_setDefaultValue, METH_O},
    {"setOptions", (PyCFunction)Sbk_ChoiceParamFunc_setOptions, METH_O},
    {"setValue", (PyCFunction)Sbk_ChoiceParamFunc_setValue, METH_O},
    {"setValueAtTime", (PyCFunction)Sbk_ChoiceParamFunc_setValueAtTime, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_ChoiceParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_ChoiceParam_clear(PyObject* self)
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
static SbkObjectType *_Sbk_ChoiceParam_Type = nullptr;
static SbkObjectType *Sbk_ChoiceParam_TypeF(void)
{
    return _Sbk_ChoiceParam_Type;
}

static PyType_Slot Sbk_ChoiceParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_ChoiceParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_ChoiceParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_ChoiceParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_ChoiceParam_spec = {
    "NatronEngine.ChoiceParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_ChoiceParam_slots
};
#else
static SbkObjectType Sbk_ChoiceParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.ChoiceParam",
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
    /*tp_traverse*/         Sbk_ChoiceParam_traverse,
    /*tp_clear*/            Sbk_ChoiceParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_ChoiceParam_methods,
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

static void* Sbk_ChoiceParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::ChoiceParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ChoiceParam_PythonToCpp_ChoiceParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_ChoiceParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_ChoiceParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_ChoiceParam_PythonToCpp_ChoiceParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_ChoiceParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_ChoiceParam_Type))
#endif
        return ChoiceParam_PythonToCpp_ChoiceParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ChoiceParam_PTR_CppToPython_ChoiceParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::ChoiceParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_ChoiceParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::ChoiceParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_ChoiceParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *ChoiceParam_SignatureStrings[] = {
    "NatronEngine.ChoiceParam.addAsDependencyOf(fromExprDimension:int,param:NatronEngine.Param,thisDimension:int)->int",
    "NatronEngine.ChoiceParam.addOption(option:QString,help:QString)",
    "0:NatronEngine.ChoiceParam.get()->int",
    "1:NatronEngine.ChoiceParam.get(frame:double)->int",
    "NatronEngine.ChoiceParam.getDefaultValue()->int",
    "NatronEngine.ChoiceParam.getNumOptions()->int",
    "NatronEngine.ChoiceParam.getOption(index:int)->QString",
    "NatronEngine.ChoiceParam.getOptions()->QList[QString])",
    "NatronEngine.ChoiceParam.getValue()->int",
    "NatronEngine.ChoiceParam.getValueAtTime(time:double)->int",
    "NatronEngine.ChoiceParam.restoreDefaultValue()",
    "0:NatronEngine.ChoiceParam.set(label:QString)",
    "1:NatronEngine.ChoiceParam.set(x:int)",
    "2:NatronEngine.ChoiceParam.set(x:int,frame:double)",
    "0:NatronEngine.ChoiceParam.setDefaultValue(value:QString)",
    "1:NatronEngine.ChoiceParam.setDefaultValue(value:int)",
    "NatronEngine.ChoiceParam.setOptions(options:QList[QPair])",
    "0:NatronEngine.ChoiceParam.setValue(label:QString)",
    "1:NatronEngine.ChoiceParam.setValue(value:int)",
    "NatronEngine.ChoiceParam.setValueAtTime(value:int,time:double)",
    nullptr}; // Sentinel
#endif

void init_ChoiceParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_ChoiceParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ChoiceParam",
        "ChoiceParam*",
        &Sbk_ChoiceParam_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        ChoiceParam_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::ChoiceParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_ChoiceParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_ChoiceParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "ChoiceParam", "ChoiceParam*",
        &Sbk_ChoiceParam_Type, &Shiboken::callCppDestructor< ::ChoiceParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_ChoiceParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_ChoiceParam_Type,
#endif
        ChoiceParam_PythonToCpp_ChoiceParam_PTR,
        is_ChoiceParam_PythonToCpp_ChoiceParam_PTR_Convertible,
        ChoiceParam_PTR_CppToPython_ChoiceParam);

    Shiboken::Conversions::registerConverterName(converter, "ChoiceParam");
    Shiboken::Conversions::registerConverterName(converter, "ChoiceParam*");
    Shiboken::Conversions::registerConverterName(converter, "ChoiceParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::ChoiceParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ChoiceParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_ChoiceParam_TypeF(), &Sbk_ChoiceParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_ChoiceParam_Type, &Sbk_ChoiceParam_typeDiscovery);
#endif


    ChoiceParamWrapper::pysideInitQtMetaTypes();
}
