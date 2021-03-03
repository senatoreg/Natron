
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
#include "natron_python_wrapper.h"

// inner classes
#include "natron_python_tracker_wrapper.h"
#include "natron_python_track_wrapper.h"
#include "natron_python_roto_wrapper.h"
#include "natron_python_itembase_wrapper.h"
#include "natron_python_beziercurve_wrapper.h"
#include "natron_python_layer_wrapper.h"
#include "natron_python_pycoreapplication_wrapper.h"
#include "natron_python_nodecreationproperty_wrapper.h"
#include "natron_python_intnodecreationproperty_wrapper.h"
#include "natron_python_stringnodecreationproperty_wrapper.h"
#include "natron_python_floatnodecreationproperty_wrapper.h"
#include "natron_python_boolnodecreationproperty_wrapper.h"
#include "natron_python_appsettings_wrapper.h"
#include "natron_python_userparamholder_wrapper.h"
#include "natron_python_imagelayer_wrapper.h"
#include "natron_python_group_wrapper.h"
#include "natron_python_effect_wrapper.h"
#include "natron_python_app_wrapper.h"
#include "natron_python_exprutils_wrapper.h"
#include "natron_python_colortuple_wrapper.h"
#include "natron_python_double3dtuple_wrapper.h"
#include "natron_python_double2dtuple_wrapper.h"
#include "natron_python_int3dtuple_wrapper.h"
#include "natron_python_int2dtuple_wrapper.h"
#include "natron_python_param_wrapper.h"
#include "natron_python_parametricparam_wrapper.h"
#include "natron_python_pageparam_wrapper.h"
#include "natron_python_groupparam_wrapper.h"
#include "natron_python_separatorparam_wrapper.h"
#include "natron_python_buttonparam_wrapper.h"
#include "natron_python_animatedparam_wrapper.h"
#include "natron_python_stringparambase_wrapper.h"
#include "natron_python_pathparam_wrapper.h"
#include "natron_python_outputfileparam_wrapper.h"
#include "natron_python_fileparam_wrapper.h"
#include "natron_python_stringparam_wrapper.h"
#include "natron_python_booleanparam_wrapper.h"
#include "natron_python_choiceparam_wrapper.h"
#include "natron_python_colorparam_wrapper.h"
#include "natron_python_doubleparam_wrapper.h"
#include "natron_python_double2dparam_wrapper.h"
#include "natron_python_double3dparam_wrapper.h"
#include "natron_python_intparam_wrapper.h"
#include "natron_python_int2dparam_wrapper.h"
#include "natron_python_int3dparam_wrapper.h"

// Extra includes
#include <vector>


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


// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_PythonFunc_PyStringToStdString(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::PyStringToStdString(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // PyStringToStdString(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_PyStringToStdString_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyStringToStdString(PyObject*)
            std::string cppResult = ::Natron::Python::PyStringToStdString(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_PyStringToStdString_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PyStringToStdString");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_getAttrRecursive(PyObject *self, PyObject *args)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getAttrRecursive", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static Python::getAttrRecursive(std::string,PyObject*,bool*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && PyObject_Check(pyArgs[1])
        && PyBool_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
        overloadId = 0; // getAttrRecursive(std::string,PyObject*,bool*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_getAttrRecursive_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getAttrRecursive(std::string,PyObject*,bool*)
            PyObject * cppResult = ::Natron::Python::getAttrRecursive(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_getAttrRecursive_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.getAttrRecursive");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_getFunctionArguments(PyObject *self, PyObject *args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getFunctionArguments", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static Python::getFunctionArguments(std::string,std::string*,std::vector<std::string>*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // getFunctionArguments(std::string,std::string*,std::vector<std::string>*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_getFunctionArguments_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::string *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::vector<std::string > *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getFunctionArguments(std::string,std::string*,std::vector<std::string>*)
            ::Natron::Python::getFunctionArguments(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_PythonFunc_getFunctionArguments_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.getFunctionArguments");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_getGroupInfos(PyObject *self, PyObject *args)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getGroupInfos", 9, 9, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8])))
        return {};


    // Overloaded function decisor
    // 0: static Python::getGroupInfos(std::string,std::string,std::string*,std::string*,std::string*,std::string*,std::string*,bool*,uint*)
    if (numArgs == 9
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[6])))
        && PyBool_Check(pyArgs[7]) && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[8])))) {
        overloadId = 0; // getGroupInfos(std::string,std::string,std::string*,std::string*,std::string*,std::string*,std::string*,bool*,uint*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_getGroupInfos_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::string cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::string *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::std::string *cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::std::string *cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        ::std::string *cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        ::std::string *cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);
        bool *cppArg7;
        pythonToCpp[7](pyArgs[7], &cppArg7);
        unsigned int *cppArg8;
        pythonToCpp[8](pyArgs[8], &cppArg8);

        if (!PyErr_Occurred()) {
            // getGroupInfos(std::string,std::string,std::string*,std::string*,std::string*,std::string*,std::string*,bool*,uint*)
            bool cppResult = ::Natron::Python::getGroupInfos(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_getGroupInfos_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.getGroupInfos");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_getMainModule(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getMainModule()
            PyObject * cppResult = ::Natron::Python::getMainModule();
            pyResult = Shiboken::Conversions::copyToPython(, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_PythonFunc_interpretPythonScript(PyObject *self, PyObject *args)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "interpretPythonScript", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static Python::interpretPythonScript(std::string,std::string*,std::string*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArgs[2])))) {
        overloadId = 0; // interpretPythonScript(std::string,std::string*,std::string*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_interpretPythonScript_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::string *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::string *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // interpretPythonScript(std::string,std::string*,std::string*)
            bool cppResult = ::Natron::Python::interpretPythonScript(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_interpretPythonScript_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.interpretPythonScript");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_makeNameScriptFriendly(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::makeNameScriptFriendly(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // makeNameScriptFriendly(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_makeNameScriptFriendly_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // makeNameScriptFriendly(std::string)
            std::string cppResult = ::Natron::Python::makeNameScriptFriendly(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_makeNameScriptFriendly_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.makeNameScriptFriendly");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::makeNameScriptFriendlyWithDots(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // makeNameScriptFriendlyWithDots(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // makeNameScriptFriendlyWithDots(std::string)
            std::string cppResult = ::Natron::Python::makeNameScriptFriendlyWithDots(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.makeNameScriptFriendlyWithDots");
        return {};
}


static const char *Sbk_Natron_Python_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_methods[] = {
    {"PyStringToStdString", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_PyStringToStdString), METH_O|METH_STATIC},
    {"getAttrRecursive", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getAttrRecursive), METH_VARARGS|METH_STATIC},
    {"getFunctionArguments", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getFunctionArguments), METH_VARARGS|METH_STATIC},
    {"getGroupInfos", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getGroupInfos), METH_VARARGS|METH_STATIC},
    {"getMainModule", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_getMainModule), METH_NOARGS|METH_STATIC},
    {"interpretPythonScript", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_interpretPythonScript), METH_VARARGS|METH_STATIC},
    {"makeNameScriptFriendly", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_makeNameScriptFriendly), METH_O|METH_STATIC},
    {"makeNameScriptFriendlyWithDots", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots), METH_O|METH_STATIC},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_TypeF(void)
{
    return _Sbk_Natron_Python_Type;
}

static PyType_Slot Sbk_Natron_Python_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(Sbk_object_dealloc /* PYSIDE-832: Prevent replacement of "0" with subtype_dealloc. */)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_spec = {
    "1:NatronEngine.Natron.Python",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_slots
};

} //extern "C"


// Type conversion functions.

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *NatronEngineNatron_Python_SignatureStrings[] = {
    "NatronEngine.Natron.Python.PyStringToStdString(obj:PyObject)->std.string",
    "NatronEngine.Natron.Python.getAttrRecursive(fullyQualifiedName:std.string,parentObj:PyObject,isDefined:bool*)->PyObject",
    "NatronEngine.Natron.Python.getFunctionArguments(pyFunc:std.string,error:std.string*,args:std.vector[std.string])",
    "NatronEngine.Natron.Python.getGroupInfos(modulePath:std.string,pythonModule:std.string,pluginID:std.string*,pluginLabel:std.string*,iconFilePath:std.string*,grouping:std.string*,description:std.string*,isToolset:bool*,version:unsigned int*)->bool",
    "NatronEngine.Natron.Python.getMainModule()->PyObject",
    "NatronEngine.Natron.Python.interpretPythonScript(script:std.string,error:std.string*,output:std.string*)->bool",
    "NatronEngine.Natron.Python.makeNameScriptFriendly(str:std.string)->std.string",
    "NatronEngine.Natron.Python.makeNameScriptFriendlyWithDots(str:std.string)->std.string",
    nullptr}; // Sentinel

void init_NatronEngineNatron_Python(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "Python",
        "Natron::Python",
        &Sbk_Natron_Python_spec,
        0,
        0,
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_Type);
    InitSignatureStrings(pyType, NatronEngineNatron_Python_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_Type), Sbk_Natron_Python_PropertyStrings);
    SbkNatronEngineTypes[SBK_NatronEngineNATRON_PYTHON_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_TypeF());



}
