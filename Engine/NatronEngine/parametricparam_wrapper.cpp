
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

#include "parametricparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void ParametricParamWrapper::pysideInitQtMetaTypes()
{
}

ParametricParamWrapper::~ParametricParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_ParametricParamFunc_addControlPoint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.ParametricParam.addControlPoint(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.ParametricParam.addControlPoint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:addControlPoint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addControlPoint(int,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
    // 1: addControlPoint(int,double,double,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // addControlPoint(int,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX]), (pyArgs[3])))) {
            overloadId = 0; // addControlPoint(int,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
        } else if (numArgs >= 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // addControlPoint(int,double,double,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX]), (pyArgs[5])))) {
                overloadId = 1; // addControlPoint(int,double,double,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_addControlPoint_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addControlPoint(int dimension, double key, double value, NATRON_NAMESPACE::KeyframeTypeEnum interpolation)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "interpolation");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.ParametricParam.addControlPoint(): got multiple values for keyword argument 'interpolation'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX]), (pyArgs[3]))))
                        goto Sbk_ParametricParamFunc_addControlPoint_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::NATRON_NAMESPACE::KeyframeTypeEnum cppArg3 = NATRON_NAMESPACE::eKeyframeTypeSmooth;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addControlPoint(int,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
                NATRON_NAMESPACE::StatusEnum cppResult = NATRON_NAMESPACE::StatusEnum(cppSelf->addControlPoint(cppArg0, cppArg1, cppArg2, cppArg3));
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STATUSENUM_IDX]), &cppResult);
            }
            break;
        }
        case 1: // addControlPoint(int dimension, double key, double value, double leftDerivative, double rightDerivative, NATRON_NAMESPACE::KeyframeTypeEnum interpolation)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "interpolation");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.ParametricParam.addControlPoint(): got multiple values for keyword argument 'interpolation'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX]), (pyArgs[5]))))
                        goto Sbk_ParametricParamFunc_addControlPoint_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            double cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::NATRON_NAMESPACE::KeyframeTypeEnum cppArg5 = NATRON_NAMESPACE::eKeyframeTypeSmooth;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // addControlPoint(int,double,double,double,double,NATRON_NAMESPACE::KeyframeTypeEnum)
                NATRON_NAMESPACE::StatusEnum cppResult = NATRON_NAMESPACE::StatusEnum(cppSelf->addControlPoint(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5));
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STATUSENUM_IDX]), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_addControlPoint_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.addControlPoint");
#else
        const char* overloads[] = {"int, float, float, NatronEngine.Natron.KeyframeTypeEnum = eKeyframeTypeSmooth", "int, float, float, float, float, NatronEngine.Natron.KeyframeTypeEnum = eKeyframeTypeSmooth", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.addControlPoint", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_deleteAllControlPoints(PyObject* self, PyObject* pyArg)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deleteAllControlPoints(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // deleteAllControlPoints(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_deleteAllControlPoints_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // deleteAllControlPoints(int)
            NATRON_NAMESPACE::StatusEnum cppResult = NATRON_NAMESPACE::StatusEnum(cppSelf->deleteAllControlPoints(cppArg0));
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STATUSENUM_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_deleteAllControlPoints_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ParametricParam.deleteAllControlPoints");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ParametricParam.deleteAllControlPoints", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_deleteControlPoint(PyObject* self, PyObject* args)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "deleteControlPoint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: deleteControlPoint(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // deleteControlPoint(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_deleteControlPoint_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // deleteControlPoint(int,int)
            NATRON_NAMESPACE::StatusEnum cppResult = NATRON_NAMESPACE::StatusEnum(cppSelf->deleteControlPoint(cppArg0, cppArg1));
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STATUSENUM_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_deleteControlPoint_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.deleteControlPoint");
#else
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.deleteControlPoint", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_getCurveColor(PyObject* self, PyObject* pyArg)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getCurveColor(int,ColorTuple&)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getCurveColor(int,ColorTuple&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_getCurveColor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getCurveColor(int,ColorTuple&)const
            // Begin code injection

            ColorTuple t;
            cppSelf->getCurveColor(cppArg0,t);
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], &t);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_getCurveColor_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ParametricParam.getCurveColor");
#else
        const char* overloads[] = {"int, NatronEngine.ColorTuple", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ParametricParam.getCurveColor", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_getNControlPoints(PyObject* self, PyObject* pyArg)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getNControlPoints(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getNControlPoints(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_getNControlPoints_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getNControlPoints(int)const
            int cppResult = const_cast<const ::ParametricParamWrapper*>(cppSelf)->getNControlPoints(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_getNControlPoints_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ParametricParam.getNControlPoints");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.ParametricParam.getNControlPoints", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_getNthControlPoint(PyObject* self, PyObject* args)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getNthControlPoint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: getNthControlPoint(int,int,double*,double*,double*,double*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // getNthControlPoint(int,int,double*,double*,double*,double*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_getNthControlPoint_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getNthControlPoint(int,int,double*,double*,double*,double*)const
            // Begin code injection

            double key,value,left,right;
            NATRON_NAMESPACE::StatusEnum cppResult = cppSelf->getNthControlPoint(cppArg0, cppArg1,&key,&value, &left, &right);
            pyResult = PyTuple_New(5);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STATUSENUM_IDX]), &cppResult));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &key));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &value));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &left));
            PyTuple_SET_ITEM(pyResult, 4, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &right));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_getNthControlPoint_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.getNthControlPoint");
#else
        const char* overloads[] = {"int, int, PySide.QtCore.double, PySide.QtCore.double, PySide.QtCore.double, PySide.QtCore.double", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.getNthControlPoint", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_getValue(PyObject* self, PyObject* args)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: getValue(int,double)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // getValue(int,double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_getValue_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getValue(int,double)const
            double cppResult = const_cast<const ::ParametricParamWrapper*>(cppSelf)->getValue(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_getValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.getValue");
#else
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.getValue", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_setCurveColor(PyObject* self, PyObject* args)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setCurveColor", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setCurveColor(int,double,double,double)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 0; // setCurveColor(int,double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_setCurveColor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setCurveColor(int,double,double,double)
            cppSelf->setCurveColor(cppArg0, cppArg1, cppArg2, cppArg3);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_ParametricParamFunc_setCurveColor_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.setCurveColor");
#else
        const char* overloads[] = {"int, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.setCurveColor", overloads);
#endif
        return 0;
}

static PyObject* Sbk_ParametricParamFunc_setDefaultCurvesFromCurrentCurves(PyObject* self)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setDefaultCurvesFromCurrentCurves()
            cppSelf->setDefaultCurvesFromCurrentCurves();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_ParametricParamFunc_setNthControlPoint(PyObject* self, PyObject* args)
{
    ParametricParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (ParametricParamWrapper*)((::ParametricParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setNthControlPoint", 6, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: setNthControlPoint(int,int,double,double,double,double)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[5])))) {
        overloadId = 0; // setNthControlPoint(int,int,double,double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_ParametricParamFunc_setNthControlPoint_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        double cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        double cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // setNthControlPoint(int,int,double,double,double,double)
            NATRON_NAMESPACE::StatusEnum cppResult = NATRON_NAMESPACE::StatusEnum(cppSelf->setNthControlPoint(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5));
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STATUSENUM_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_ParametricParamFunc_setNthControlPoint_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.setNthControlPoint");
#else
        const char* overloads[] = {"int, int, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.ParametricParam.setNthControlPoint", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_ParametricParam_methods[] = {
    {"addControlPoint", (PyCFunction)Sbk_ParametricParamFunc_addControlPoint, METH_VARARGS|METH_KEYWORDS},
    {"deleteAllControlPoints", (PyCFunction)Sbk_ParametricParamFunc_deleteAllControlPoints, METH_O},
    {"deleteControlPoint", (PyCFunction)Sbk_ParametricParamFunc_deleteControlPoint, METH_VARARGS},
    {"getCurveColor", (PyCFunction)Sbk_ParametricParamFunc_getCurveColor, METH_O},
    {"getNControlPoints", (PyCFunction)Sbk_ParametricParamFunc_getNControlPoints, METH_O},
    {"getNthControlPoint", (PyCFunction)Sbk_ParametricParamFunc_getNthControlPoint, METH_VARARGS},
    {"getValue", (PyCFunction)Sbk_ParametricParamFunc_getValue, METH_VARARGS},
    {"setCurveColor", (PyCFunction)Sbk_ParametricParamFunc_setCurveColor, METH_VARARGS},
    {"setDefaultCurvesFromCurrentCurves", (PyCFunction)Sbk_ParametricParamFunc_setDefaultCurvesFromCurrentCurves, METH_NOARGS},
    {"setNthControlPoint", (PyCFunction)Sbk_ParametricParamFunc_setNthControlPoint, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_ParametricParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_ParametricParam_clear(PyObject* self)
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
static SbkObjectType *_Sbk_ParametricParam_Type = nullptr;
static SbkObjectType *Sbk_ParametricParam_TypeF(void)
{
    return _Sbk_ParametricParam_Type;
}

static PyType_Slot Sbk_ParametricParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_ParametricParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_ParametricParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_ParametricParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_ParametricParam_spec = {
    "NatronEngine.ParametricParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_ParametricParam_slots
};
#else
static SbkObjectType Sbk_ParametricParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.ParametricParam",
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
    /*tp_traverse*/         Sbk_ParametricParam_traverse,
    /*tp_clear*/            Sbk_ParametricParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_ParametricParam_methods,
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

static void* Sbk_ParametricParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::ParametricParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ParametricParam_PythonToCpp_ParametricParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_ParametricParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_ParametricParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_ParametricParam_PythonToCpp_ParametricParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_ParametricParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_ParametricParam_Type))
#endif
        return ParametricParam_PythonToCpp_ParametricParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ParametricParam_PTR_CppToPython_ParametricParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::ParametricParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_ParametricParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::ParametricParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_ParametricParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *ParametricParam_SignatureStrings[] = {
    "0:NatronEngine.ParametricParam.addControlPoint(dimension:int,key:double,value:double,interpolation:NatronEngine.Natron.KeyframeTypeEnum=NatronEngine.Natron.KeyframeTypeEnum.eKeyframeTypeSmooth)->NatronEngine.Natron.StatusEnum",
    "1:NatronEngine.ParametricParam.addControlPoint(dimension:int,key:double,value:double,leftDerivative:double,rightDerivative:double,interpolation:NatronEngine.Natron.KeyframeTypeEnum=NatronEngine.Natron.KeyframeTypeEnum.eKeyframeTypeSmooth)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.ParametricParam.deleteAllControlPoints(dimension:int)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.ParametricParam.deleteControlPoint(dimension:int,nthCtl:int)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.ParametricParam.getCurveColor(dimension:int,ret:NatronEngine.ColorTuple)",
    "NatronEngine.ParametricParam.getNControlPoints(dimension:int)->int",
    "NatronEngine.ParametricParam.getNthControlPoint(dimension:int,nthCtl:int,key:double*,value:double*,leftDerivative:double*,rightDerivative:double*)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.ParametricParam.getValue(dimension:int,parametricPosition:double)->double",
    "NatronEngine.ParametricParam.setCurveColor(dimension:int,r:double,g:double,b:double)",
    "NatronEngine.ParametricParam.setDefaultCurvesFromCurrentCurves()",
    "NatronEngine.ParametricParam.setNthControlPoint(dimension:int,nthCtl:int,key:double,value:double,leftDerivative:double,rightDerivative:double)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.ParametricParam.setNthControlPointInterpolation(dimension:int,nThCtl:int,interpolation:NatronEngine.Natron.KeyframeTypeEnum)->NatronEngine.Natron.StatusEnum",
    nullptr}; // Sentinel
#endif

void init_ParametricParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_ParametricParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ParametricParam",
        "ParametricParam*",
        &Sbk_ParametricParam_spec,
        ParametricParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::ParametricParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_PARAM_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_ParametricParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_ParametricParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "ParametricParam", "ParametricParam*",
        &Sbk_ParametricParam_Type, &Shiboken::callCppDestructor< ::ParametricParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_ParametricParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_ParametricParam_Type,
#endif
        ParametricParam_PythonToCpp_ParametricParam_PTR,
        is_ParametricParam_PythonToCpp_ParametricParam_PTR_Convertible,
        ParametricParam_PTR_CppToPython_ParametricParam);

    Shiboken::Conversions::registerConverterName(converter, "ParametricParam");
    Shiboken::Conversions::registerConverterName(converter, "ParametricParam*");
    Shiboken::Conversions::registerConverterName(converter, "ParametricParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::ParametricParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ParametricParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_ParametricParam_TypeF(), &Sbk_ParametricParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_ParametricParam_Type, &Sbk_ParametricParam_typeDiscovery);
#endif


    ParametricParamWrapper::pysideInitQtMetaTypes();
}
