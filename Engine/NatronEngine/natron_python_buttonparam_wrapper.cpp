
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
#include "natron_python_buttonparam_wrapper.h"

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

void ButtonParamWrapper::pysideInitQtMetaTypes()
{
}

void ButtonParamWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

ButtonParamWrapper::~ButtonParamWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_Python_ButtonParamFunc_trigger(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<ButtonParamWrapper *>(reinterpret_cast< ::Natron::Python::ButtonParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BUTTONPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // trigger()
            cppSelf->trigger();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}


static const char *Sbk_Natron_Python_ButtonParam_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_ButtonParam_methods[] = {
    {"trigger", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ButtonParamFunc_trigger), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_ButtonParam_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::ButtonParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BUTTONPARAM_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<ButtonParamWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_ButtonParam_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_ButtonParam_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_ButtonParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_ButtonParam_TypeF(void)
{
    return _Sbk_Natron_Python_ButtonParam_Type;
}

static PyType_Slot Sbk_Natron_Python_ButtonParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_ButtonParam_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_ButtonParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_ButtonParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_ButtonParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_ButtonParam_spec = {
    "1:NatronEngine.Natron.Python.ButtonParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_ButtonParam_slots
};

} //extern "C"

static void *Sbk_Natron_Python_ButtonParam_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::ButtonParam *>(reinterpret_cast< ::Natron::Python::Param *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ButtonParam_PythonToCpp_ButtonParam_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_ButtonParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_ButtonParam_PythonToCpp_ButtonParam_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_ButtonParam_TypeF())))
        return ButtonParam_PythonToCpp_ButtonParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *ButtonParam_PTR_CppToPython_ButtonParam(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::ButtonParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_ButtonParam_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_ButtonParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.ButtonParam.trigger(self)",
    nullptr}; // Sentinel

void init_Natron_Python_ButtonParam(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_ButtonParam_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "ButtonParam",
        "Natron::Python::ButtonParam*",
        &Sbk_Natron_Python_ButtonParam_spec,
        &Shiboken::callCppDestructor< ::Natron::Python::ButtonParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]),
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_ButtonParam_Type);
    InitSignatureStrings(pyType, Natron_Python_ButtonParam_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_ButtonParam_Type), Sbk_Natron_Python_ButtonParam_PropertyStrings);
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_BUTTONPARAM_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_ButtonParam_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_ButtonParam_TypeF(),
        ButtonParam_PythonToCpp_ButtonParam_PTR,
        is_ButtonParam_PythonToCpp_ButtonParam_PTR_Convertible,
        ButtonParam_PTR_CppToPython_ButtonParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ButtonParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ButtonParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ButtonParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::ButtonParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::ButtonParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::ButtonParam&");
    Shiboken::Conversions::registerConverterName(converter, "ButtonParam");
    Shiboken::Conversions::registerConverterName(converter, "ButtonParam*");
    Shiboken::Conversions::registerConverterName(converter, "ButtonParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::ButtonParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ButtonParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_ButtonParam_TypeF(), &Sbk_Natron_Python_ButtonParam_typeDiscovery);


    ButtonParamWrapper::pysideInitQtMetaTypes();
}
