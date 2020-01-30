
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

#include "userparamholder_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void UserParamHolderWrapper::pysideInitQtMetaTypes()
{
}

UserParamHolderWrapper::UserParamHolderWrapper() : UserParamHolder() {
    // ... middle
}

UserParamHolderWrapper::~UserParamHolderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_UserParamHolder_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::UserParamHolder >()))
        return -1;

    ::UserParamHolderWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // UserParamHolder()
            cptr = new ::UserParamHolderWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::UserParamHolder >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_UserParamHolderFunc_createBooleanParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createBooleanParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createBooleanParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createBooleanParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createBooleanParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createBooleanParam(QString,QString)
            BooleanParam * cppResult = cppSelf->createBooleanParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createBooleanParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createBooleanParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createBooleanParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createButtonParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createButtonParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createButtonParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createButtonParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createButtonParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createButtonParam(QString,QString)
            ButtonParam * cppResult = cppSelf->createButtonParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_BUTTONPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createButtonParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createButtonParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createButtonParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createChoiceParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createChoiceParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createChoiceParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createChoiceParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createChoiceParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createChoiceParam(QString,QString)
            ChoiceParam * cppResult = cppSelf->createChoiceParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createChoiceParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createChoiceParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createChoiceParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createColorParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createColorParam", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createColorParam(QString,QString,bool)
    if (numArgs == 3
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
#endif
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
        overloadId = 0; // createColorParam(QString,QString,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createColorParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createColorParam(QString,QString,bool)
            ColorParam * cppResult = cppSelf->createColorParam(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_COLORPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createColorParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createColorParam");
#else
        const char* overloads[] = {"unicode, unicode, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createColorParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createDouble2DParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDouble2DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createDouble2DParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createDouble2DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createDouble2DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createDouble2DParam(QString,QString)
            Double2DParam * cppResult = cppSelf->createDouble2DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createDouble2DParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createDouble2DParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createDouble2DParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createDouble3DParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDouble3DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createDouble3DParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createDouble3DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createDouble3DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createDouble3DParam(QString,QString)
            Double3DParam * cppResult = cppSelf->createDouble3DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_DOUBLE3DPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createDouble3DParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createDouble3DParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createDouble3DParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createDoubleParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDoubleParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createDoubleParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createDoubleParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createDoubleParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createDoubleParam(QString,QString)
            DoubleParam * cppResult = cppSelf->createDoubleParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createDoubleParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createDoubleParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createDoubleParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createFileParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createFileParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createFileParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createFileParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createFileParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createFileParam(QString,QString)
            FileParam * cppResult = cppSelf->createFileParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_FILEPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createFileParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createFileParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createFileParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createGroupParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createGroupParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createGroupParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createGroupParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createGroupParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createGroupParam(QString,QString)
            GroupParam * cppResult = cppSelf->createGroupParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUPPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createGroupParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createGroupParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createGroupParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createInt2DParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createInt2DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createInt2DParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createInt2DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createInt2DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createInt2DParam(QString,QString)
            Int2DParam * cppResult = cppSelf->createInt2DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_INT2DPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createInt2DParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createInt2DParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createInt2DParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createInt3DParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createInt3DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createInt3DParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createInt3DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createInt3DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createInt3DParam(QString,QString)
            Int3DParam * cppResult = cppSelf->createInt3DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_INT3DPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createInt3DParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createInt3DParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createInt3DParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createIntParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createIntParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createIntParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createIntParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createIntParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createIntParam(QString,QString)
            IntParam * cppResult = cppSelf->createIntParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_INTPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createIntParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createIntParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createIntParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createOutputFileParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createOutputFileParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createOutputFileParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createOutputFileParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createOutputFileParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createOutputFileParam(QString,QString)
            OutputFileParam * cppResult = cppSelf->createOutputFileParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_OUTPUTFILEPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createOutputFileParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createOutputFileParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createOutputFileParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createPageParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createPageParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createPageParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createPageParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createPageParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createPageParam(QString,QString)
            PageParam * cppResult = cppSelf->createPageParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_PAGEPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createPageParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createPageParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createPageParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createParametricParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createParametricParam", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createParametricParam(QString,QString,int)
    if (numArgs == 3
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
#endif
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // createParametricParam(QString,QString,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createParametricParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createParametricParam(QString,QString,int)
            ParametricParam * cppResult = cppSelf->createParametricParam(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createParametricParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createParametricParam");
#else
        const char* overloads[] = {"unicode, unicode, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createParametricParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createPathParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createPathParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createPathParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createPathParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createPathParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createPathParam(QString,QString)
            PathParam * cppResult = cppSelf->createPathParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_PATHPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createPathParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createPathParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createPathParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createSeparatorParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createSeparatorParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createSeparatorParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createSeparatorParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createSeparatorParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createSeparatorParam(QString,QString)
            SeparatorParam * cppResult = cppSelf->createSeparatorParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_SEPARATORPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createSeparatorParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createSeparatorParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createSeparatorParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_createStringParam(PyObject* self, PyObject* args)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createStringParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createStringParam(QString,QString)
    if (numArgs == 2
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // createStringParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_createStringParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createStringParam(QString,QString)
            StringParam * cppResult = cppSelf->createStringParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_STRINGPARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_createStringParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createStringParam");
#else
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.UserParamHolder.createStringParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_UserParamHolderFunc_refreshUserParamsGUI(PyObject* self)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // refreshUserParamsGUI()
            // Begin code injection

            cppSelf->refreshUserParamsGUI();

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_UserParamHolderFunc_removeParam(PyObject* self, PyObject* pyArg)
{
    ::UserParamHolder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::UserParamHolder*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeParam(Param*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], (pyArg)))) {
        overloadId = 0; // removeParam(Param*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_UserParamHolderFunc_removeParam_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Param* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeParam(Param*)
            bool cppResult = cppSelf->removeParam(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_UserParamHolderFunc_removeParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.UserParamHolder.removeParam");
#else
        const char* overloads[] = {"NatronEngine.Param", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.UserParamHolder.removeParam", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_UserParamHolder_methods[] = {
    {"createBooleanParam", (PyCFunction)Sbk_UserParamHolderFunc_createBooleanParam, METH_VARARGS},
    {"createButtonParam", (PyCFunction)Sbk_UserParamHolderFunc_createButtonParam, METH_VARARGS},
    {"createChoiceParam", (PyCFunction)Sbk_UserParamHolderFunc_createChoiceParam, METH_VARARGS},
    {"createColorParam", (PyCFunction)Sbk_UserParamHolderFunc_createColorParam, METH_VARARGS},
    {"createDouble2DParam", (PyCFunction)Sbk_UserParamHolderFunc_createDouble2DParam, METH_VARARGS},
    {"createDouble3DParam", (PyCFunction)Sbk_UserParamHolderFunc_createDouble3DParam, METH_VARARGS},
    {"createDoubleParam", (PyCFunction)Sbk_UserParamHolderFunc_createDoubleParam, METH_VARARGS},
    {"createFileParam", (PyCFunction)Sbk_UserParamHolderFunc_createFileParam, METH_VARARGS},
    {"createGroupParam", (PyCFunction)Sbk_UserParamHolderFunc_createGroupParam, METH_VARARGS},
    {"createInt2DParam", (PyCFunction)Sbk_UserParamHolderFunc_createInt2DParam, METH_VARARGS},
    {"createInt3DParam", (PyCFunction)Sbk_UserParamHolderFunc_createInt3DParam, METH_VARARGS},
    {"createIntParam", (PyCFunction)Sbk_UserParamHolderFunc_createIntParam, METH_VARARGS},
    {"createOutputFileParam", (PyCFunction)Sbk_UserParamHolderFunc_createOutputFileParam, METH_VARARGS},
    {"createPageParam", (PyCFunction)Sbk_UserParamHolderFunc_createPageParam, METH_VARARGS},
    {"createParametricParam", (PyCFunction)Sbk_UserParamHolderFunc_createParametricParam, METH_VARARGS},
    {"createPathParam", (PyCFunction)Sbk_UserParamHolderFunc_createPathParam, METH_VARARGS},
    {"createSeparatorParam", (PyCFunction)Sbk_UserParamHolderFunc_createSeparatorParam, METH_VARARGS},
    {"createStringParam", (PyCFunction)Sbk_UserParamHolderFunc_createStringParam, METH_VARARGS},
    {"refreshUserParamsGUI", (PyCFunction)Sbk_UserParamHolderFunc_refreshUserParamsGUI, METH_NOARGS},
    {"removeParam", (PyCFunction)Sbk_UserParamHolderFunc_removeParam, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_UserParamHolder_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_UserParamHolder_clear(PyObject* self)
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
static SbkObjectType *_Sbk_UserParamHolder_Type = nullptr;
static SbkObjectType *Sbk_UserParamHolder_TypeF(void)
{
    return _Sbk_UserParamHolder_Type;
}

static PyType_Slot Sbk_UserParamHolder_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_UserParamHolder_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_UserParamHolder_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_UserParamHolder_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_UserParamHolder_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_UserParamHolder_spec = {
    "NatronEngine.UserParamHolder",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_UserParamHolder_slots
};
#else
static SbkObjectType Sbk_UserParamHolder_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.UserParamHolder",
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_UserParamHolder_traverse,
    /*tp_clear*/            Sbk_UserParamHolder_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_UserParamHolder_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_UserParamHolder_Init,
    /*tp_alloc*/            0,
    /*tp_new*/              SbkObjectTpNew,
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void UserParamHolder_PythonToCpp_UserParamHolder_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_UserParamHolder_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_UserParamHolder_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_UserParamHolder_PythonToCpp_UserParamHolder_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_UserParamHolder_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_UserParamHolder_Type))
#endif
        return UserParamHolder_PythonToCpp_UserParamHolder_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* UserParamHolder_PTR_CppToPython_UserParamHolder(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::UserParamHolder *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_UserParamHolder_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::UserParamHolder*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_UserParamHolder_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *UserParamHolder_SignatureStrings[] = {
    "NatronEngine.UserParamHolder()",
    "NatronEngine.UserParamHolder.createBooleanParam(name:QString,label:QString)->NatronEngine.BooleanParam",
    "NatronEngine.UserParamHolder.createButtonParam(name:QString,label:QString)->NatronEngine.ButtonParam",
    "NatronEngine.UserParamHolder.createChoiceParam(name:QString,label:QString)->NatronEngine.ChoiceParam",
    "NatronEngine.UserParamHolder.createColorParam(name:QString,label:QString,useAlpha:bool)->NatronEngine.ColorParam",
    "NatronEngine.UserParamHolder.createDouble2DParam(name:QString,label:QString)->NatronEngine.Double2DParam",
    "NatronEngine.UserParamHolder.createDouble3DParam(name:QString,label:QString)->NatronEngine.Double3DParam",
    "NatronEngine.UserParamHolder.createDoubleParam(name:QString,label:QString)->NatronEngine.DoubleParam",
    "NatronEngine.UserParamHolder.createFileParam(name:QString,label:QString)->NatronEngine.FileParam",
    "NatronEngine.UserParamHolder.createGroupParam(name:QString,label:QString)->NatronEngine.GroupParam",
    "NatronEngine.UserParamHolder.createInt2DParam(name:QString,label:QString)->NatronEngine.Int2DParam",
    "NatronEngine.UserParamHolder.createInt3DParam(name:QString,label:QString)->NatronEngine.Int3DParam",
    "NatronEngine.UserParamHolder.createIntParam(name:QString,label:QString)->NatronEngine.IntParam",
    "NatronEngine.UserParamHolder.createOutputFileParam(name:QString,label:QString)->NatronEngine.FileParam",
    "NatronEngine.UserParamHolder.createPageParam(name:QString,label:QString)->NatronEngine.PageParam",
    "NatronEngine.UserParamHolder.createParametricParam(name:QString,label:QString,nbCurves:int)->NatronEngine.ParametricParam",
    "NatronEngine.UserParamHolder.createPathParam(name:QString,label:QString)->NatronEngine.PathParam",
    "NatronEngine.UserParamHolder.createSeparatorParam(name:QString,label:QString)->NatronEngine.SeparatorParam",
    "NatronEngine.UserParamHolder.createStringParam(name:QString,label:QString)->NatronEngine.StringParam",
    "NatronEngine.UserParamHolder.refreshUserParamsGUI()",
    "NatronEngine.UserParamHolder.removeParam(param:NatronEngine.Param)->bool",
    nullptr}; // Sentinel
#endif

void init_UserParamHolder(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_UserParamHolder_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "UserParamHolder",
        "UserParamHolder*",
        &Sbk_UserParamHolder_spec,
        UserParamHolder_SignatureStrings,
        &Shiboken::callCppDestructor< ::UserParamHolder >,
        0,
        0,
        0    );

    SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_UserParamHolder_TypeF());
#else
    SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_UserParamHolder_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "UserParamHolder", "UserParamHolder*",
        &Sbk_UserParamHolder_Type, &Shiboken::callCppDestructor< ::UserParamHolder >)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_UserParamHolder_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_UserParamHolder_Type,
#endif
        UserParamHolder_PythonToCpp_UserParamHolder_PTR,
        is_UserParamHolder_PythonToCpp_UserParamHolder_PTR_Convertible,
        UserParamHolder_PTR_CppToPython_UserParamHolder);

    Shiboken::Conversions::registerConverterName(converter, "UserParamHolder");
    Shiboken::Conversions::registerConverterName(converter, "UserParamHolder*");
    Shiboken::Conversions::registerConverterName(converter, "UserParamHolder&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::UserParamHolder).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::UserParamHolderWrapper).name());



    UserParamHolderWrapper::pysideInitQtMetaTypes();
}
