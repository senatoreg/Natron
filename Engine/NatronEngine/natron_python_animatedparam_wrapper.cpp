
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
#include "natron_python_animatedparam_wrapper.h"

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

void AnimatedParamWrapper::pysideInitQtMetaTypes()
{
}

void AnimatedParamWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

AnimatedParamWrapper::~AnimatedParamWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_Python_AnimatedParamFunc_deleteValueAtTime(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.deleteValueAtTime(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.deleteValueAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:deleteValueAtTime", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::deleteValueAtTime(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // deleteValueAtTime(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // deleteValueAtTime(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_deleteValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.deleteValueAtTime(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_deleteValueAtTime_TypeError;
                }
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // deleteValueAtTime(double,int)
            cppSelf->deleteValueAtTime(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AnimatedParamFunc_deleteValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.deleteValueAtTime");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getCurrentTime(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCurrentTime()const
            int cppResult = const_cast<const ::AnimatedParamWrapper *>(cppSelf)->getCurrentTime();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getDerivativeAtTime(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getDerivativeAtTime(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getDerivativeAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getDerivativeAtTime", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::getDerivativeAtTime(double,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getDerivativeAtTime(double,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // getDerivativeAtTime(double,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_getDerivativeAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getDerivativeAtTime(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_getDerivativeAtTime_TypeError;
                }
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getDerivativeAtTime(double,int)const
            double cppResult = const_cast<const ::AnimatedParamWrapper *>(cppSelf)->getDerivativeAtTime(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_getDerivativeAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.getDerivativeAtTime");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getExpression(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: AnimatedParam::getExpression(int,bool*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getExpression(int,bool*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_getExpression_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getExpression(int,bool*)const
            // Begin code injection
            bool hasRetVar;
            QString cppResult = cppSelf->getExpression(cppArg0,&hasRetVar);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &hasRetVar));
            return pyResult;

            // End of code injection

        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_getExpression_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.AnimatedParam.getExpression");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getIntegrateFromTimeToTime(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getIntegrateFromTimeToTime(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getIntegrateFromTimeToTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:getIntegrateFromTimeToTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::getIntegrateFromTimeToTime(double,double,int)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // getIntegrateFromTimeToTime(double,double,int)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // getIntegrateFromTimeToTime(double,double,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_getIntegrateFromTimeToTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getIntegrateFromTimeToTime(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_getIntegrateFromTimeToTime_TypeError;
                }
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getIntegrateFromTimeToTime(double,double,int)const
            double cppResult = const_cast<const ::AnimatedParamWrapper *>(cppSelf)->getIntegrateFromTimeToTime(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_getIntegrateFromTimeToTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.getIntegrateFromTimeToTime");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getIsAnimated(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getIsAnimated(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getIsAnimated", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::getIsAnimated(int)const
    if (numArgs == 0) {
        overloadId = 0; // getIsAnimated(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getIsAnimated(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_getIsAnimated_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getIsAnimated(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_getIsAnimated_TypeError;
                }
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getIsAnimated(int)const
            bool cppResult = const_cast<const ::AnimatedParamWrapper *>(cppSelf)->getIsAnimated(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_getIsAnimated_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.getIsAnimated");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getKeyIndex(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getKeyIndex(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getKeyIndex(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getKeyIndex", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::getKeyIndex(double,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getKeyIndex(double,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // getKeyIndex(double,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_getKeyIndex_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getKeyIndex(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_getKeyIndex_TypeError;
                }
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getKeyIndex(double,int)const
            int cppResult = const_cast<const ::AnimatedParamWrapper *>(cppSelf)->getKeyIndex(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_getKeyIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.getKeyIndex");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getKeyTime(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getKeyTime", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::getKeyTime(int,int,double*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // getKeyTime(int,int,double*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_getKeyTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getKeyTime(int,int,double*)const
            // Begin code injection
            double time;
            bool cppResult = cppSelf->getKeyTime(cppArg0, cppArg1,&time);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &time));
            return pyResult;

            // End of code injection

        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_getKeyTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.getKeyTime");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_getNumKeys(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getNumKeys(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getNumKeys", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::getNumKeys(int)const
    if (numArgs == 0) {
        overloadId = 0; // getNumKeys(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getNumKeys(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_getNumKeys_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.getNumKeys(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_getNumKeys_TypeError;
                }
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getNumKeys(int)const
            int cppResult = const_cast<const ::AnimatedParamWrapper *>(cppSelf)->getNumKeys(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_getNumKeys_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.getNumKeys");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_removeAnimation(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.removeAnimation(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:removeAnimation", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::removeAnimation(int)
    if (numArgs == 0) {
        overloadId = 0; // removeAnimation(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // removeAnimation(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_removeAnimation_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.removeAnimation(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_removeAnimation_TypeError;
                }
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAnimation(int)
            cppSelf->removeAnimation(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AnimatedParamFunc_removeAnimation_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.removeAnimation");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_setExpression(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.setExpression(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.setExpression(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:setExpression", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::setExpression(QString,bool,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setExpression(QString,bool,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setExpression(QString,bool,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_setExpression_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.setExpression(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_setExpression_TypeError;
                }
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setExpression(QString,bool,int)
            // Begin code injection
            bool cppResult = cppSelf->setExpression(cppArg0,cppArg1,cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection

        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_setExpression_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.setExpression");
        return {};
}

static PyObject *Sbk_Natron_Python_AnimatedParamFunc_setInterpolationAtTime(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<AnimatedParamWrapper *>(reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.setInterpolationAtTime(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.setInterpolationAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:setInterpolationAtTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: AnimatedParam::setInterpolationAtTime(double,Natron::KeyframeTypeEnum,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])->converter, (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setInterpolationAtTime(double,Natron::KeyframeTypeEnum,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setInterpolationAtTime(double,Natron::KeyframeTypeEnum,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AnimatedParamFunc_setInterpolationAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","dimension");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.AnimatedParam.setInterpolationAtTime(): got multiple values for keyword argument 'dimension'.");
                    return {};
                }
                if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_Natron_Python_AnimatedParamFunc_setInterpolationAtTime_TypeError;
                }
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Natron::KeyframeTypeEnum cppArg1{Natron::eKeyframeTypeConstant};
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setInterpolationAtTime(double,Natron::KeyframeTypeEnum,int)
            bool cppResult = cppSelf->setInterpolationAtTime(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AnimatedParamFunc_setInterpolationAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.AnimatedParam.setInterpolationAtTime");
        return {};
}


static const char *Sbk_Natron_Python_AnimatedParam_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_AnimatedParam_methods[] = {
    {"deleteValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_deleteValueAtTime), METH_VARARGS|METH_KEYWORDS},
    {"getCurrentTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getCurrentTime), METH_NOARGS},
    {"getDerivativeAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getDerivativeAtTime), METH_VARARGS|METH_KEYWORDS},
    {"getExpression", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getExpression), METH_O},
    {"getIntegrateFromTimeToTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getIntegrateFromTimeToTime), METH_VARARGS|METH_KEYWORDS},
    {"getIsAnimated", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getIsAnimated), METH_VARARGS|METH_KEYWORDS},
    {"getKeyIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getKeyIndex), METH_VARARGS|METH_KEYWORDS},
    {"getKeyTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getKeyTime), METH_VARARGS},
    {"getNumKeys", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_getNumKeys), METH_VARARGS|METH_KEYWORDS},
    {"removeAnimation", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_removeAnimation), METH_VARARGS|METH_KEYWORDS},
    {"setExpression", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_setExpression), METH_VARARGS|METH_KEYWORDS},
    {"setInterpolationAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AnimatedParamFunc_setInterpolationAtTime), METH_VARARGS|METH_KEYWORDS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_AnimatedParam_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::AnimatedParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<AnimatedParamWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_AnimatedParam_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_AnimatedParam_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_AnimatedParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_AnimatedParam_TypeF(void)
{
    return _Sbk_Natron_Python_AnimatedParam_Type;
}

static PyType_Slot Sbk_Natron_Python_AnimatedParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_AnimatedParam_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_AnimatedParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_AnimatedParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_AnimatedParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_AnimatedParam_spec = {
    "1:NatronEngine.Natron.Python.AnimatedParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_AnimatedParam_slots
};

} //extern "C"

static void *Sbk_Natron_Python_AnimatedParam_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::AnimatedParam *>(reinterpret_cast< ::Natron::Python::Param *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void AnimatedParam_PythonToCpp_AnimatedParam_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_AnimatedParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_AnimatedParam_PythonToCpp_AnimatedParam_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_AnimatedParam_TypeF())))
        return AnimatedParam_PythonToCpp_AnimatedParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *AnimatedParam_PTR_CppToPython_AnimatedParam(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::AnimatedParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_AnimatedParam_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_AnimatedParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.AnimatedParam.deleteValueAtTime(self,time:double,dimension:int=0)",
    "NatronEngine.Natron.Python.AnimatedParam.getCurrentTime(self)->int",
    "NatronEngine.Natron.Python.AnimatedParam.getDerivativeAtTime(self,time:double,dimension:int=0)->double",
    "NatronEngine.Natron.Python.AnimatedParam.getExpression(self,dimension:int,hasRetVariable:bool*)->QString",
    "NatronEngine.Natron.Python.AnimatedParam.getIntegrateFromTimeToTime(self,time1:double,time2:double,dimension:int=0)->double",
    "NatronEngine.Natron.Python.AnimatedParam.getIsAnimated(self,dimension:int=0)->bool",
    "NatronEngine.Natron.Python.AnimatedParam.getKeyIndex(self,time:double,dimension:int=0)->int",
    "NatronEngine.Natron.Python.AnimatedParam.getKeyTime(self,index:int,dimension:int,time:double*)->bool",
    "NatronEngine.Natron.Python.AnimatedParam.getNumKeys(self,dimension:int=0)->int",
    "NatronEngine.Natron.Python.AnimatedParam.removeAnimation(self,dimension:int=0)",
    "NatronEngine.Natron.Python.AnimatedParam.setExpression(self,expr:QString,hasRetVariable:bool,dimension:int=0)->bool",
    "NatronEngine.Natron.Python.AnimatedParam.setInterpolationAtTime(self,time:double,interpolation:NatronEngine.Natron.KeyframeTypeEnum,dimension:int=0)->bool",
    nullptr}; // Sentinel

void init_Natron_Python_AnimatedParam(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_AnimatedParam_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "AnimatedParam",
        "Natron::Python::AnimatedParam*",
        &Sbk_Natron_Python_AnimatedParam_spec,
        &Shiboken::callCppDestructor< ::Natron::Python::AnimatedParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]),
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_AnimatedParam_Type);
    InitSignatureStrings(pyType, Natron_Python_AnimatedParam_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_AnimatedParam_Type), Sbk_Natron_Python_AnimatedParam_PropertyStrings);
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_AnimatedParam_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_AnimatedParam_TypeF(),
        AnimatedParam_PythonToCpp_AnimatedParam_PTR,
        is_AnimatedParam_PythonToCpp_AnimatedParam_PTR_Convertible,
        AnimatedParam_PTR_CppToPython_AnimatedParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::AnimatedParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::AnimatedParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::AnimatedParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::AnimatedParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::AnimatedParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::AnimatedParam&");
    Shiboken::Conversions::registerConverterName(converter, "AnimatedParam");
    Shiboken::Conversions::registerConverterName(converter, "AnimatedParam*");
    Shiboken::Conversions::registerConverterName(converter, "AnimatedParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::AnimatedParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::AnimatedParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_AnimatedParam_TypeF(), &Sbk_Natron_Python_AnimatedParam_typeDiscovery);


    AnimatedParamWrapper::pysideInitQtMetaTypes();
}
