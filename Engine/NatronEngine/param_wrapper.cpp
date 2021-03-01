
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

#include "param_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void ParamWrapper::pysideInitQtMetaTypes()
{
}

ParamWrapper::~ParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_ParamFunc__addAsDependencyOf(PyObject* self, PyObject* args)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "_addAsDependencyOf", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: _addAsDependencyOf(int,Param*,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // _addAsDependencyOf(int,Param*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc__addAsDependencyOf_TypeError;

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
            // _addAsDependencyOf(int,Param*,int)
            ((::ParamWrapper*) cppSelf)->ParamWrapper::_addAsDependencyOf_protected(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc__addAsDependencyOf_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param._addAsDependencyOf");
#else
        const char* overloads[] = {"int, NatronEngine.Param, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param._addAsDependencyOf", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_copy(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.copy(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.copy(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:copy", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: copy(Param*,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // copy(Param*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // copy(Param*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_copy_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.copy(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_ParamFunc_copy_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Param* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // copy(Param*,int)
            bool cppResult = cppSelf->copy(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParamFunc_copy_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.copy");
#else
        const char* overloads[] = {"NatronEngine.Param, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.copy", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_curve(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.curve(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.curve(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:curve", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: curve(double,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // curve(double,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // curve(double,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_curve_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.curve(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_ParamFunc_curve_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // curve(double,int)const
            double cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->curve(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParamFunc_curve_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.curve");
#else
        const char* overloads[] = {"float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.curve", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_getAddNewLine(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAddNewLine()
            bool cppResult = cppSelf->getAddNewLine();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getCanAnimate(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCanAnimate()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getCanAnimate();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getEvaluateOnChange(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getEvaluateOnChange()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getEvaluateOnChange();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getHelp(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHelp()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getHelp();
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

static PyObject* Sbk_ParamFunc_getIsAnimationEnabled(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsAnimationEnabled()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsAnimationEnabled();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getIsEnabled(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.getIsEnabled(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:getIsEnabled", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getIsEnabled(int)const
    if (numArgs == 0) {
        overloadId = 0; // getIsEnabled(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getIsEnabled(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_getIsEnabled_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.getIsEnabled(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_ParamFunc_getIsEnabled_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getIsEnabled(int)const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsEnabled(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParamFunc_getIsEnabled_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.getIsEnabled");
#else
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.getIsEnabled", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_getIsPersistent(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsPersistent()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsPersistent();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getIsVisible(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsVisible()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsVisible();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getLabel(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getLabel()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getLabel();
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

static PyObject* Sbk_ParamFunc_getNumDimensions(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumDimensions()const
            int cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getNumDimensions();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getParent(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParent()const
            Param * cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getParent();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_ParamFunc_getScriptName(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getScriptName()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getScriptName();
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

static PyObject* Sbk_ParamFunc_getTypeName(PyObject* self)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getTypeName()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getTypeName();
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

static PyObject* Sbk_ParamFunc_random(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.random(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:random", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: random(double,double)const
    // 1: random(double,double,double,uint)const
    if (numArgs == 0) {
        overloadId = 0; // random(double,double)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // random(double,double)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // random(double,double)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // random(double,double,double,uint)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3])))) {
                    overloadId = 1; // random(double,double,double,uint)const
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_random_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // random(double min, double max) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "min");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.random(): got multiple values for keyword argument 'min'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0]))))
                        goto Sbk_ParamFunc_random_TypeError;
                }
                value = PyDict_GetItemString(kwds, "max");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.random(): got multiple values for keyword argument 'max'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1]))))
                        goto Sbk_ParamFunc_random_TypeError;
                }
            }
            double cppArg0 = 0.;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1 = 1.;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // random(double,double)const
                double cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->random(cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
            }
            break;
        }
        case 1: // random(double min, double max, double time, unsigned int seed) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "seed");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.random(): got multiple values for keyword argument 'seed'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3]))))
                        goto Sbk_ParamFunc_random_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            unsigned int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // random(double,double,double,uint)const
                double cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->random(cppArg0, cppArg1, cppArg2, cppArg3);
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

    Sbk_ParamFunc_random_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.random");
#else
        const char* overloads[] = {"float = 0., float = 1.", "float, float, float, unsigned int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.random", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_randomInt(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.randomInt(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.randomInt(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:randomInt", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: randomInt(int,int)
    // 1: randomInt(int,int,double,uint)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // randomInt(int,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // randomInt(int,int,double,uint)const
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3])))) {
                overloadId = 1; // randomInt(int,int,double,uint)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_randomInt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // randomInt(int min, int max)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // randomInt(int,int)
                int cppResult = cppSelf->randomInt(cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // randomInt(int min, int max, double time, unsigned int seed) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "seed");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.randomInt(): got multiple values for keyword argument 'seed'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3]))))
                        goto Sbk_ParamFunc_randomInt_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            unsigned int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // randomInt(int,int,double,uint)const
                int cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->randomInt(cppArg0, cppArg1, cppArg2, cppArg3);
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

    Sbk_ParamFunc_randomInt_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.randomInt");
#else
        const char* overloads[] = {"int, int", "int, int, float, unsigned int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.randomInt", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setAddNewLine(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAddNewLine(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAddNewLine(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setAddNewLine_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAddNewLine(bool)
            cppSelf->setAddNewLine(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setAddNewLine_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setAddNewLine");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setAddNewLine", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setAnimationEnabled(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAnimationEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAnimationEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setAnimationEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAnimationEnabled(bool)
            cppSelf->setAnimationEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setAnimationEnabled_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setAnimationEnabled");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setAnimationEnabled", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setAsAlias(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAsAlias(Param*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], (pyArg)))) {
        overloadId = 0; // setAsAlias(Param*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setAsAlias_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Param* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAsAlias(Param*)
            bool cppResult = cppSelf->setAsAlias(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParamFunc_setAsAlias_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setAsAlias");
#else
        const char* overloads[] = {"NatronEngine.Param", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setAsAlias", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setEnabled(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.setEnabled(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.setEnabled(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setEnabled", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setEnabled(bool,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setEnabled(bool,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setEnabled(bool,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setEnabled_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.setEnabled(): got multiple values for keyword argument 'dimension'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_ParamFunc_setEnabled_TypeError;
            }
        }
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setEnabled(bool,int)
            cppSelf->setEnabled(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setEnabled_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.setEnabled");
#else
        const char* overloads[] = {"bool, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.setEnabled", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setEnabledByDefault(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.setEnabledByDefault(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:setEnabledByDefault", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: setEnabledByDefault(bool)
    if (numArgs == 0) {
        overloadId = 0; // setEnabledByDefault(bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // setEnabledByDefault(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setEnabledByDefault_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "enabled");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Param.setEnabledByDefault(): got multiple values for keyword argument 'enabled'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_ParamFunc_setEnabledByDefault_TypeError;
            }
        }
        bool cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // setEnabledByDefault(bool)
            cppSelf->setEnabledByDefault(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setEnabledByDefault_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.setEnabledByDefault");
#else
        const char* overloads[] = {"bool = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.setEnabledByDefault", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setEvaluateOnChange(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEvaluateOnChange(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEvaluateOnChange(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setEvaluateOnChange_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEvaluateOnChange(bool)
            cppSelf->setEvaluateOnChange(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setEvaluateOnChange_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setEvaluateOnChange");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setEvaluateOnChange", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setHelp(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHelp(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setHelp(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setHelp_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHelp(QString)
            cppSelf->setHelp(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setHelp_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setHelp");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setHelp", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setIconFilePath(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconFilePath(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setIconFilePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setIconFilePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIconFilePath(QString)
            cppSelf->setIconFilePath(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setIconFilePath_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setIconFilePath");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setIconFilePath", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setPersistent(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPersistent(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setPersistent(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setPersistent_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPersistent(bool)
            cppSelf->setPersistent(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setPersistent_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setPersistent");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setPersistent", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setVisible(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisible(bool)
            cppSelf->setVisible(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setVisible_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setVisible");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setVisible", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_setVisibleByDefault(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisibleByDefault(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisibleByDefault(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_setVisibleByDefault_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisibleByDefault(bool)
            cppSelf->setVisibleByDefault(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_setVisibleByDefault_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setVisibleByDefault");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.setVisibleByDefault", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_slaveTo(PyObject* self, PyObject* args)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "slaveTo", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: slaveTo(Param*,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // slaveTo(Param*,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_slaveTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Param* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // slaveTo(Param*,int,int)
            bool cppResult = cppSelf->slaveTo(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParamFunc_slaveTo_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.slaveTo");
#else
        const char* overloads[] = {"NatronEngine.Param, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Param.slaveTo", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParamFunc_unslave(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParamWrapper*)((::Param*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unslave(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // unslave(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParamFunc_unslave_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unslave(int)
            cppSelf->unslave(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParamFunc_unslave_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.unslave");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Param.unslave", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_Param_methods[] = {
    {"_addAsDependencyOf", (PyCFunction)Sbk_ParamFunc__addAsDependencyOf, METH_VARARGS},
    {"copy", (PyCFunction)Sbk_ParamFunc_copy, METH_VARARGS|METH_KEYWORDS},
    {"curve", (PyCFunction)Sbk_ParamFunc_curve, METH_VARARGS|METH_KEYWORDS},
    {"getAddNewLine", (PyCFunction)Sbk_ParamFunc_getAddNewLine, METH_NOARGS},
    {"getCanAnimate", (PyCFunction)Sbk_ParamFunc_getCanAnimate, METH_NOARGS},
    {"getEvaluateOnChange", (PyCFunction)Sbk_ParamFunc_getEvaluateOnChange, METH_NOARGS},
    {"getHelp", (PyCFunction)Sbk_ParamFunc_getHelp, METH_NOARGS},
    {"getIsAnimationEnabled", (PyCFunction)Sbk_ParamFunc_getIsAnimationEnabled, METH_NOARGS},
    {"getIsEnabled", (PyCFunction)Sbk_ParamFunc_getIsEnabled, METH_VARARGS|METH_KEYWORDS},
    {"getIsPersistent", (PyCFunction)Sbk_ParamFunc_getIsPersistent, METH_NOARGS},
    {"getIsVisible", (PyCFunction)Sbk_ParamFunc_getIsVisible, METH_NOARGS},
    {"getLabel", (PyCFunction)Sbk_ParamFunc_getLabel, METH_NOARGS},
    {"getNumDimensions", (PyCFunction)Sbk_ParamFunc_getNumDimensions, METH_NOARGS},
    {"getParent", (PyCFunction)Sbk_ParamFunc_getParent, METH_NOARGS},
    {"getScriptName", (PyCFunction)Sbk_ParamFunc_getScriptName, METH_NOARGS},
    {"getTypeName", (PyCFunction)Sbk_ParamFunc_getTypeName, METH_NOARGS},
    {"random", (PyCFunction)Sbk_ParamFunc_random, METH_VARARGS|METH_KEYWORDS},
    {"randomInt", (PyCFunction)Sbk_ParamFunc_randomInt, METH_VARARGS|METH_KEYWORDS},
    {"setAddNewLine", (PyCFunction)Sbk_ParamFunc_setAddNewLine, METH_O},
    {"setAnimationEnabled", (PyCFunction)Sbk_ParamFunc_setAnimationEnabled, METH_O},
    {"setAsAlias", (PyCFunction)Sbk_ParamFunc_setAsAlias, METH_O},
    {"setEnabled", (PyCFunction)Sbk_ParamFunc_setEnabled, METH_VARARGS|METH_KEYWORDS},
    {"setEnabledByDefault", (PyCFunction)Sbk_ParamFunc_setEnabledByDefault, METH_VARARGS|METH_KEYWORDS},
    {"setEvaluateOnChange", (PyCFunction)Sbk_ParamFunc_setEvaluateOnChange, METH_O},
    {"setHelp", (PyCFunction)Sbk_ParamFunc_setHelp, METH_O},
    {"setIconFilePath", (PyCFunction)Sbk_ParamFunc_setIconFilePath, METH_O},
    {"setPersistent", (PyCFunction)Sbk_ParamFunc_setPersistent, METH_O},
    {"setVisible", (PyCFunction)Sbk_ParamFunc_setVisible, METH_O},
    {"setVisibleByDefault", (PyCFunction)Sbk_ParamFunc_setVisibleByDefault, METH_O},
    {"slaveTo", (PyCFunction)Sbk_ParamFunc_slaveTo, METH_VARARGS},
    {"unslave", (PyCFunction)Sbk_ParamFunc_unslave, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Param_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_Param_clear(PyObject* self)
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
static SbkObjectType *_Sbk_Param_Type = nullptr;
static SbkObjectType *Sbk_Param_TypeF(void)
{
    return _Sbk_Param_Type;
}

static PyType_Slot Sbk_Param_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Param_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Param_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Param_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Param_spec = {
    "NatronEngine.Param",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Param_slots
};
#else
static SbkObjectType Sbk_Param_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Param",
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
    /*tp_traverse*/         Sbk_Param_traverse,
    /*tp_clear*/            Sbk_Param_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Param_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Param_PythonToCpp_Param_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_Param_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Param_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_Param_PythonToCpp_Param_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Param_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Param_Type))
#endif
        return Param_PythonToCpp_Param_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Param_PTR_CppToPython_Param(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Param *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Param_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::Param*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Param_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Param_SignatureStrings[] = {
    "NatronEngine.Param._addAsDependencyOf(fromExprDimension:int,param:NatronEngine.Param,thisDimension:int)",
    "NatronEngine.Param.copy(other:NatronEngine.Param,dimension:int=-1)->bool",
    "NatronEngine.Param.curve(time:double,dimension:int=-1)->double",
    "NatronEngine.Param.getAddNewLine()->bool",
    "NatronEngine.Param.getCanAnimate()->bool",
    "NatronEngine.Param.getEvaluateOnChange()->bool",
    "NatronEngine.Param.getHelp()->QString",
    "NatronEngine.Param.getIsAnimationEnabled()->bool",
    "NatronEngine.Param.getIsEnabled(dimention:int=0)->bool",
    "NatronEngine.Param.getIsPersistent()->bool",
    "NatronEngine.Param.getIsVisible()->bool",
    "NatronEngine.Param.getLabel()->QString",
    "NatronEngine.Param.getNumDimensions()->int",
    "NatronEngine.Param.getParent()->NatronEngine.Param",
    "NatronEngine.Param.getScriptName()->QString",
    "NatronEngine.Param.getTypeName()->QString",
    "0:NatronEngine.Param.random(min:double=0.,max:double=1.)->double",
    "1:NatronEngine.Param.random(min:double,max:double,time:double,seed:unsigned int=0)->double",
    "0:NatronEngine.Param.randomInt(min:int,max:int)->int",
    "1:NatronEngine.Param.randomInt(min:int,max:int,time:double,seed:unsigned int=0)->int",
    "NatronEngine.Param.setAddNewLine(a:bool)",
    "NatronEngine.Param.setAnimationEnabled(e:bool)",
    "NatronEngine.Param.setAsAlias(other:NatronEngine.Param)->bool",
    "NatronEngine.Param.setEnabled(enabled:bool)",
    "NatronEngine.Param.setEnabledByDefault(enabled:bool)",
    "NatronEngine.Param.setEvaluateOnChange(eval:bool)",
    "NatronEngine.Param.setHelp(help:QString)",
    "NatronEngine.Param.setIconFilePath(icon:QString)",
    "NatronEngine.Param.setPersistent(persistent:bool)",
    "NatronEngine.Param.setVisible(visible:bool)",
    "NatronEngine.Param.setVisibleByDefault(visible:bool)",
    "NatronEngine.Param.slaveTo(other:NatronEngine.Param,thisDimension:int,otherDimension:int)->bool",
    "NatronEngine.Param.unslave(dimension:int)",
    nullptr}; // Sentinel
#endif

void init_Param(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_Param_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Param",
        "Param*",
        &Sbk_Param_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        Param_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::Param >,
        0,
        0,
        0    );

    SbkNatronEngineTypes[SBK_PARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Param_TypeF());
#else
    SbkNatronEngineTypes[SBK_PARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Param_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Param", "Param*",
        &Sbk_Param_Type, &Shiboken::callCppDestructor< ::Param >)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Param_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Param_Type,
#endif
        Param_PythonToCpp_Param_PTR,
        is_Param_PythonToCpp_Param_PTR_Convertible,
        Param_PTR_CppToPython_Param);

    Shiboken::Conversions::registerConverterName(converter, "Param");
    Shiboken::Conversions::registerConverterName(converter, "Param*");
    Shiboken::Conversions::registerConverterName(converter, "Param&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Param).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ParamWrapper).name());



    ParamWrapper::pysideInitQtMetaTypes();
}
