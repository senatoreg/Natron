
// default includes
#include <shiboken.h>
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <pysideqenum.h>
#include <feature_select.h>
#include <qapp_macro.h>

QT_WARNING_DISABLE_DEPRECATED

#include <typeinfo>
#include <iterator>

// module include
#include "natronengine_python.h"

// main header
#include "natron_python_parametricparam_wrapper.h"

// inner classes

#include <cctype>
#include <cstring>

using namespace Natron;



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}

// Native ---------------------------------------------------------

void ParametricParamWrapper::pysideInitQtMetaTypes()
{
}

void ParametricParamWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

ParametricParamWrapper::~ParametricParamWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_Python_ParametricParamFunc_addControlPoint(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ParametricParam.addControlPoint(): too many arguments");
        return {};
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ParametricParam.addControlPoint(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:addControlPoint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return {};


    // Overloaded function decisor
    // 0: ParametricParam::addControlPoint(int,double,double,Natron::KeyframeTypeEnum)
    // 1: ParametricParam::addControlPoint(int,double,double,double,double,Natron::KeyframeTypeEnum)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // addControlPoint(int,double,double,Natron::KeyframeTypeEnum)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])->converter, (pyArgs[3])))) {
            overloadId = 0; // addControlPoint(int,double,double,Natron::KeyframeTypeEnum)
        } else if (numArgs >= 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // addControlPoint(int,double,double,double,double,Natron::KeyframeTypeEnum)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])->converter, (pyArgs[5])))) {
                overloadId = 1; // addControlPoint(int,double,double,double,double,Natron::KeyframeTypeEnum)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_addControlPoint_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addControlPoint(int dimension, double key, double value, Natron::KeyframeTypeEnum interpolation)
        {
            if (kwds) {
                PyObject *keyName = nullptr;
                PyObject *value = nullptr;
                keyName = Py_BuildValue("s","interpolation");
                if (PyDict_Contains(kwds, keyName)) {
                    value = PyDict_GetItem(kwds, keyName);
                    if (value && pyArgs[3]) {
                        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ParametricParam.addControlPoint(): got multiple values for keyword argument 'interpolation'.");
                        return {};
                    }
                    if (value) {
                        pyArgs[3] = value;
                        if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])->converter, (pyArgs[3]))))
                            goto Sbk_Natron_Python_ParametricParamFunc_addControlPoint_TypeError;
                    }
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::Natron::KeyframeTypeEnum cppArg3 = Natron::KeyframeTypeEnum::eKeyframeTypeSmooth;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addControlPoint(int,double,double,Natron::KeyframeTypeEnum)
                Natron::StatusEnum cppResult = Natron::StatusEnum(cppSelf->addControlPoint(cppArg0, cppArg1, cppArg2, cppArg3));
                pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, &cppResult);
            }
            break;
        }
        case 1: // addControlPoint(int dimension, double key, double value, double leftDerivative, double rightDerivative, Natron::KeyframeTypeEnum interpolation)
        {
            if (kwds) {
                PyObject *keyName = nullptr;
                PyObject *value = nullptr;
                keyName = Py_BuildValue("s","interpolation");
                if (PyDict_Contains(kwds, keyName)) {
                    value = PyDict_GetItem(kwds, keyName);
                    if (value && pyArgs[5]) {
                        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ParametricParam.addControlPoint(): got multiple values for keyword argument 'interpolation'.");
                        return {};
                    }
                    if (value) {
                        pyArgs[5] = value;
                        if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])->converter, (pyArgs[5]))))
                            goto Sbk_Natron_Python_ParametricParamFunc_addControlPoint_TypeError;
                    }
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
            ::Natron::KeyframeTypeEnum cppArg5 = Natron::KeyframeTypeEnum::eKeyframeTypeSmooth;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // addControlPoint(int,double,double,double,double,Natron::KeyframeTypeEnum)
                Natron::StatusEnum cppResult = Natron::StatusEnum(cppSelf->addControlPoint(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5));
                pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_addControlPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ParametricParam.addControlPoint");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_deleteAllControlPoints(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ParametricParam::deleteAllControlPoints(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // deleteAllControlPoints(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_deleteAllControlPoints_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // deleteAllControlPoints(int)
            Natron::StatusEnum cppResult = Natron::StatusEnum(cppSelf->deleteAllControlPoints(cppArg0));
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_deleteAllControlPoints_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ParametricParam.deleteAllControlPoints");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_deleteControlPoint(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "deleteControlPoint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ParametricParam::deleteControlPoint(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // deleteControlPoint(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_deleteControlPoint_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // deleteControlPoint(int,int)
            Natron::StatusEnum cppResult = Natron::StatusEnum(cppSelf->deleteControlPoint(cppArg0, cppArg1));
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_deleteControlPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ParametricParam.deleteControlPoint");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_getCurveColor(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ParametricParam::getCurveColor(int,Natron::Python::ColorTuple&)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getCurveColor(int,Natron::Python::ColorTuple&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_getCurveColor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getCurveColor(int,Natron::Python::ColorTuple&)const
            // Begin code injection
            Natron::Python::ColorTuple t;
            cppSelf->getCurveColor(cppArg0,t);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORTUPLE_IDX]), &t);
            return pyResult;

            // End of code injection

        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_getCurveColor_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ParametricParam.getCurveColor");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_getNControlPoints(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ParametricParam::getNControlPoints(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getNControlPoints(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_getNControlPoints_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getNControlPoints(int)const
            int cppResult = const_cast<const ::ParametricParamWrapper *>(cppSelf)->getNControlPoints(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_getNControlPoints_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ParametricParam.getNControlPoints");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_getNthControlPoint(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getNthControlPoint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ParametricParam::getNthControlPoint(int,int,double*,double*,double*,double*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // getNthControlPoint(int,int,double*,double*,double*,double*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_getNthControlPoint_TypeError;

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
            Natron::StatusEnum cppResult = cppSelf->getNthControlPoint(cppArg0, cppArg1,&key,&value, &left, &right);
            pyResult = PyTuple_New(5);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, &cppResult));
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
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_getNthControlPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ParametricParam.getNthControlPoint");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_getValue(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ParametricParam::getValue(int,double)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // getValue(int,double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_getValue_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getValue(int,double)const
            double cppResult = const_cast<const ::ParametricParamWrapper *>(cppSelf)->getValue(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_getValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ParametricParam.getValue");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_setCurveColor(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setCurveColor", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: ParametricParam::setCurveColor(int,double,double,double)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 0; // setCurveColor(int,double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_setCurveColor_TypeError;

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
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParametricParamFunc_setCurveColor_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ParametricParam.setCurveColor");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_setDefaultCurvesFromCurrentCurves(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setDefaultCurvesFromCurrentCurves()
            cppSelf->setDefaultCurvesFromCurrentCurves();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_setNthControlPoint(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setNthControlPoint", 6, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return {};


    // Overloaded function decisor
    // 0: ParametricParam::setNthControlPoint(int,int,double,double,double,double)
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
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_setNthControlPoint_TypeError;

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
            Natron::StatusEnum cppResult = Natron::StatusEnum(cppSelf->setNthControlPoint(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5));
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_setNthControlPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ParametricParam.setNthControlPoint");
        return {};
}

static PyObject *Sbk_Natron_Python_ParametricParamFunc_setNthControlPointInterpolation(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ParametricParamWrapper *>(reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setNthControlPointInterpolation", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ParametricParam::setNthControlPointInterpolation(int,int,Natron::KeyframeTypeEnum)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])->converter, (pyArgs[2])))) {
        overloadId = 0; // setNthControlPointInterpolation(int,int,Natron::KeyframeTypeEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParametricParamFunc_setNthControlPointInterpolation_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Natron::KeyframeTypeEnum cppArg2{Natron::eKeyframeTypeConstant};
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setNthControlPointInterpolation(int,int,Natron::KeyframeTypeEnum)
            Natron::StatusEnum cppResult = Natron::StatusEnum(cppSelf->setNthControlPointInterpolation(cppArg0, cppArg1, cppArg2));
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParametricParamFunc_setNthControlPointInterpolation_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ParametricParam.setNthControlPointInterpolation");
        return {};
}


static const char *Sbk_Natron_Python_ParametricParam_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_ParametricParam_methods[] = {
    {"addControlPoint", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_addControlPoint), METH_VARARGS|METH_KEYWORDS},
    {"deleteAllControlPoints", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_deleteAllControlPoints), METH_O},
    {"deleteControlPoint", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_deleteControlPoint), METH_VARARGS},
    {"getCurveColor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_getCurveColor), METH_O},
    {"getNControlPoints", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_getNControlPoints), METH_O},
    {"getNthControlPoint", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_getNthControlPoint), METH_VARARGS},
    {"getValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_getValue), METH_VARARGS},
    {"setCurveColor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_setCurveColor), METH_VARARGS},
    {"setDefaultCurvesFromCurrentCurves", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_setDefaultCurvesFromCurrentCurves), METH_NOARGS},
    {"setNthControlPoint", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_setNthControlPoint), METH_VARARGS},
    {"setNthControlPointInterpolation", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParametricParamFunc_setNthControlPointInterpolation), METH_VARARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_ParametricParam_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::ParametricParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<ParametricParamWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_ParametricParam_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_ParametricParam_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_ParametricParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_ParametricParam_TypeF(void)
{
    return _Sbk_Natron_Python_ParametricParam_Type;
}

static PyType_Slot Sbk_Natron_Python_ParametricParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_ParametricParam_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_ParametricParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_ParametricParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_ParametricParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_ParametricParam_spec = {
    "1:NatronEngine.Natron.Python.ParametricParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_ParametricParam_slots
};

} //extern "C"

static void *Sbk_Natron_Python_ParametricParam_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::ParametricParam *>(reinterpret_cast< ::Natron::Python::Param *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ParametricParam_PythonToCpp_ParametricParam_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_ParametricParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_ParametricParam_PythonToCpp_ParametricParam_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_ParametricParam_TypeF())))
        return ParametricParam_PythonToCpp_ParametricParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *ParametricParam_PTR_CppToPython_ParametricParam(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::ParametricParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_ParametricParam_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_ParametricParam_SignatureStrings[] = {
    "1:NatronEngine.Natron.Python.ParametricParam.addControlPoint(self,dimension:int,key:double,value:double,interpolation:NatronEngine.Natron.KeyframeTypeEnum=eKeyframeTypeSmooth)->NatronEngine.Natron.StatusEnum",
    "0:NatronEngine.Natron.Python.ParametricParam.addControlPoint(self,dimension:int,key:double,value:double,leftDerivative:double,rightDerivative:double,interpolation:NatronEngine.Natron.KeyframeTypeEnum=eKeyframeTypeSmooth)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.Natron.Python.ParametricParam.deleteAllControlPoints(self,dimension:int)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.Natron.Python.ParametricParam.deleteControlPoint(self,dimension:int,nthCtl:int)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.Natron.Python.ParametricParam.getCurveColor(self,dimension:int,ret:NatronEngine.Natron.Python.ColorTuple)",
    "NatronEngine.Natron.Python.ParametricParam.getNControlPoints(self,dimension:int)->int",
    "NatronEngine.Natron.Python.ParametricParam.getNthControlPoint(self,dimension:int,nthCtl:int,key:double*,value:double*,leftDerivative:double*,rightDerivative:double*)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.Natron.Python.ParametricParam.getValue(self,dimension:int,parametricPosition:double)->double",
    "NatronEngine.Natron.Python.ParametricParam.setCurveColor(self,dimension:int,r:double,g:double,b:double)",
    "NatronEngine.Natron.Python.ParametricParam.setDefaultCurvesFromCurrentCurves(self)",
    "NatronEngine.Natron.Python.ParametricParam.setNthControlPoint(self,dimension:int,nthCtl:int,key:double,value:double,leftDerivative:double,rightDerivative:double)->NatronEngine.Natron.StatusEnum",
    "NatronEngine.Natron.Python.ParametricParam.setNthControlPointInterpolation(self,dimension:int,nThCtl:int,interpolation:NatronEngine.Natron.KeyframeTypeEnum)->NatronEngine.Natron.StatusEnum",
    nullptr}; // Sentinel

void init_Natron_Python_ParametricParam(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_ParametricParam_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "ParametricParam",
        "Natron::Python::ParametricParam*",
        &Sbk_Natron_Python_ParametricParam_spec,
        &Shiboken::callCppDestructor< ::Natron::Python::ParametricParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]),
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_ParametricParam_Type);
    InitSignatureStrings(pyType, Natron_Python_ParametricParam_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_ParametricParam_Type), Sbk_Natron_Python_ParametricParam_PropertyStrings);
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_ParametricParam_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_ParametricParam_TypeF(),
        ParametricParam_PythonToCpp_ParametricParam_PTR,
        is_ParametricParam_PythonToCpp_ParametricParam_PTR_Convertible,
        ParametricParam_PTR_CppToPython_ParametricParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ParametricParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ParametricParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ParametricParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::ParametricParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::ParametricParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::ParametricParam&");
    Shiboken::Conversions::registerConverterName(converter, "ParametricParam");
    Shiboken::Conversions::registerConverterName(converter, "ParametricParam*");
    Shiboken::Conversions::registerConverterName(converter, "ParametricParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::ParametricParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ParametricParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_ParametricParam_TypeF(), &Sbk_Natron_Python_ParametricParam_typeDiscovery);


    ParametricParamWrapper::pysideInitQtMetaTypes();
}
