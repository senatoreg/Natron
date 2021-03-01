
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

#include "stringparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void StringParamWrapper::pysideInitQtMetaTypes()
{
    qRegisterMetaType< ::StringParam::TypeEnum >("StringParam::TypeEnum");
}

StringParamWrapper::~StringParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_StringParamFunc_setType(PyObject* self, PyObject* pyArg)
{
    StringParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (StringParamWrapper*)((::StringParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_STRINGPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setType(StringParam::TypeEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX]), (pyArg)))) {
        overloadId = 0; // setType(StringParam::TypeEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_StringParamFunc_setType_TypeError;

    // Call function/method
    {
        ::StringParam::TypeEnum cppArg0 = ((::StringParam::TypeEnum)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setType(StringParam::TypeEnum)
            cppSelf->setType(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_StringParamFunc_setType_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParam.setType");
#else
        const char* overloads[] = {"NatronEngine.StringParam.TypeEnum", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.StringParam.setType", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_StringParam_methods[] = {
    {"setType", (PyCFunction)Sbk_StringParamFunc_setType, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_StringParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_StringParam_clear(PyObject* self)
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
static SbkObjectType *_Sbk_StringParam_Type = nullptr;
static SbkObjectType *Sbk_StringParam_TypeF(void)
{
    return _Sbk_StringParam_Type;
}

static PyType_Slot Sbk_StringParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_StringParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_StringParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_StringParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_StringParam_spec = {
    "NatronEngine.StringParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_StringParam_slots
};
#else
static SbkObjectType Sbk_StringParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.StringParam",
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
    /*tp_traverse*/         Sbk_StringParam_traverse,
    /*tp_clear*/            Sbk_StringParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_StringParam_methods,
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

static void* Sbk_StringParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::StringParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void StringParam_TypeEnum_PythonToCpp_StringParam_TypeEnum(PyObject* pyIn, void* cppOut) {
    *((::StringParam::TypeEnum*)cppOut) = (::StringParam::TypeEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_StringParam_TypeEnum_PythonToCpp_StringParam_TypeEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX]))
        return StringParam_TypeEnum_PythonToCpp_StringParam_TypeEnum;
    return 0;
}
static PyObject* StringParam_TypeEnum_CppToPython_StringParam_TypeEnum(const void* cppIn) {
    int castCppIn = *((::StringParam::TypeEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void StringParam_PythonToCpp_StringParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_StringParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_StringParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_StringParam_PythonToCpp_StringParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_StringParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_StringParam_Type))
#endif
        return StringParam_PythonToCpp_StringParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* StringParam_PTR_CppToPython_StringParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::StringParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_StringParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::StringParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_StringParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *StringParam_SignatureStrings[] = {
    "NatronEngine.StringParam.setType(type:NatronEngine.StringParam.TypeEnum)",
    nullptr}; // Sentinel
#endif

void init_StringParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_StringParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "StringParam",
        "StringParam*",
        &Sbk_StringParam_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        StringParam_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::StringParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_STRINGPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_StringParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_STRINGPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_StringParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "StringParam", "StringParam*",
        &Sbk_StringParam_Type, &Shiboken::callCppDestructor< ::StringParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_StringParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_StringParam_Type,
#endif
        StringParam_PythonToCpp_StringParam_PTR,
        is_StringParam_PythonToCpp_StringParam_PTR_Convertible,
        StringParam_PTR_CppToPython_StringParam);

    Shiboken::Conversions::registerConverterName(converter, "StringParam");
    Shiboken::Conversions::registerConverterName(converter, "StringParam*");
    Shiboken::Conversions::registerConverterName(converter, "StringParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::StringParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::StringParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_StringParam_TypeF(), &Sbk_StringParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_StringParam_Type, &Sbk_StringParam_typeDiscovery);
#endif

    // Initialization of enums.

    // Initialization of enum 'TypeEnum'.
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_StringParam_TypeF(),
#else
    SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_StringParam_Type,
#endif
        "TypeEnum",
        "NatronEngine.StringParam.TypeEnum",
        "StringParam::TypeEnum");
    if (!SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_StringParam_TypeF(), "eStringTypeLabel", (long) StringParam::eStringTypeLabel))
#else
        &Sbk_StringParam_Type, "eStringTypeLabel", (long) StringParam::eStringTypeLabel))
#endif
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_StringParam_TypeF(), "eStringTypeMultiLine", (long) StringParam::eStringTypeMultiLine))
#else
        &Sbk_StringParam_Type, "eStringTypeMultiLine", (long) StringParam::eStringTypeMultiLine))
#endif
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_StringParam_TypeF(), "eStringTypeRichTextMultiLine", (long) StringParam::eStringTypeRichTextMultiLine))
#else
        &Sbk_StringParam_Type, "eStringTypeRichTextMultiLine", (long) StringParam::eStringTypeRichTextMultiLine))
#endif
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_StringParam_TypeF(), "eStringTypeCustom", (long) StringParam::eStringTypeCustom))
#else
        &Sbk_StringParam_Type, "eStringTypeCustom", (long) StringParam::eStringTypeCustom))
#endif
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_StringParam_TypeF(), "eStringTypeDefault", (long) StringParam::eStringTypeDefault))
#else
        &Sbk_StringParam_Type, "eStringTypeDefault", (long) StringParam::eStringTypeDefault))
#endif
        return ;
    // Register converter for enum 'StringParam::TypeEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX],
            StringParam_TypeEnum_CppToPython_StringParam_TypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            StringParam_TypeEnum_PythonToCpp_StringParam_TypeEnum,
            is_StringParam_TypeEnum_PythonToCpp_StringParam_TypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "StringParam::TypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "TypeEnum");
    }
    // End of 'TypeEnum' enum.


    StringParamWrapper::pysideInitQtMetaTypes();
}
