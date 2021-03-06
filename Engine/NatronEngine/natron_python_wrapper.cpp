
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

static const char *Sbk_Natron_Python_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_methods[] = {

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
