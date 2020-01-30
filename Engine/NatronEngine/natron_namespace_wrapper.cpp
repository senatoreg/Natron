
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

#include "natron_namespace_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING

#include "Engine/NonKeyParams.h"


// Target ---------------------------------------------------------

extern "C" {
#if SHIBOKEN_MAJOR_VERSION >= 2
static PyObject* Sbk_NatronFunc_getAmountFreePhysicalRAM(PyObject* self)
{
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAmountFreePhysicalRAM()
            std::size_t cppResult = ::Natron::getAmountFreePhysicalRAM();
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_STD_SIZE_T_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_NatronFunc_getSizeOfForBitDepth(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Natron::getSizeOfForBitDepth(Natron::ImageBitDepthEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX])->converter, (pyArg)))) {
        overloadId = 0; // getSizeOfForBitDepth(Natron::ImageBitDepthEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_NatronFunc_getSizeOfForBitDepth_TypeError;

    // Call function/method
    {
        ::Natron::ImageBitDepthEnum cppArg0{Natron::eImageBitDepthNone};
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getSizeOfForBitDepth(Natron::ImageBitDepthEnum)
          int cppResult = ::Natron::getSizeOfForBitDepth(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_NatronFunc_getSizeOfForBitDepth_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.getSizeOfForBitDepth");
        return {};
}

static PyObject* Sbk_NatronFunc_isApplication32Bits(PyObject* self)
{
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isApplication32Bits()
            bool cppResult = ::Natron::isApplication32Bits();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_NatronFunc_isFailureRetCode(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Natron::isFailureRetCode(Natron::StatusEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX]), (pyArg)))) {
        overloadId = 0; // isFailureRetCode(Natron::StatusEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_NatronFunc_isFailureRetCode_TypeError;

    // Call function/method
    {
        ::Natron::StatusEnum cppArg0{Natron::eStatusOK};
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isFailureRetCode(Natron::StatusEnum)
            bool cppResult = ::Natron::isFailureRetCode(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_NatronFunc_isFailureRetCode_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.isFailureRetCode");
        return {};
}

#endif

static PyMethodDef Sbk_Natron_methods[] = {
#if SHIBOKEN_MAJOR_VERSION >= 2
    {"getAmountFreePhysicalRAM", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_getAmountFreePhysicalRAM), METH_NOARGS|METH_STATIC},
    {"getSizeOfForBitDepth", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_getSizeOfForBitDepth), METH_O|METH_STATIC},
    {"isApplication32Bits", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_isApplication32Bits), METH_NOARGS|METH_STATIC},
    {"isFailureRetCode", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_isFailureRetCode), METH_O|METH_STATIC},
#endif

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Natron_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject*>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_Natron_clear(PyObject* self)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject*>(SbkObject_TypeF())->tp_clear(self);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
#endif
}
// Class Definition -----------------------------------------------
extern "C" {
#if SHIBOKEN_MAJOR_VERSION >= 2
static SbkObjectType *_Sbk_Natron_Type = nullptr;
static SbkObjectType *Sbk_Natron_TypeF(void)
{
    return _Sbk_Natron_Type;
}

static PyType_Slot Sbk_Natron_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_spec = {
    "NatronEngine.Natron",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_slots
};
#else
static SbkObjectType Sbk_Natron_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Natron",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_traverse*/         Sbk_Natron_traverse,
    /*tp_clear*/            Sbk_Natron_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Natron_methods,
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

PyObject* SbkNatronEngine_Natron_StandardButtonEnum___and__(PyObject* self, PyObject* pyArg)
{
    ::Natron::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]), &cppResult);
}

PyObject* SbkNatronEngine_Natron_StandardButtonEnum___or__(PyObject* self, PyObject* pyArg)
{
    ::Natron::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]), &cppResult);
}

PyObject* SbkNatronEngine_Natron_StandardButtonEnum___xor__(PyObject* self, PyObject* pyArg)
{
    ::Natron::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]), &cppResult);
}

PyObject* SbkNatronEngine_Natron_StandardButtonEnum___invert__(PyObject* self, PyObject* pyArg)
{
    ::Natron::StandardButtons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]), self, &cppSelf);
    ::Natron::StandardButtons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]), &cppResult);
}

static PyObject* SbkNatronEngine_Natron_StandardButtonEnum_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkNatronEngine_Natron_StandardButtonEnum__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]), self, &val);
    return val != 0;
}

#if SHIBOKEN_MAJOR_VERSION >=2
static PyType_Slot SbkNatronEngine_Natron_StandardButtonEnum_number_slots[] = {
#ifdef IS_PY3K
    {Py_nb_bool,    (void *)SbkNatronEngine_Natron_StandardButtonEnum__nonzero},
#else
    {Py_nb_nonzero, (void *)SbkNatronEngine_Natron_StandardButtonEnum__nonzero},
    {Py_nb_long,    (void *)SbkNatronEngine_Natron_StandardButtonEnum_long},
#endif
    {Py_nb_invert,  (void *)SbkNatronEngine_Natron_StandardButtonEnum___invert__},
    {Py_nb_and,     (void *)SbkNatronEngine_Natron_StandardButtonEnum___and__},
    {Py_nb_xor,     (void *)SbkNatronEngine_Natron_StandardButtonEnum___xor__},
    {Py_nb_or,      (void *)SbkNatronEngine_Natron_StandardButtonEnum___or__},
    {Py_nb_int,     (void *)SbkNatronEngine_Natron_StandardButtonEnum_long},
#ifndef IS_PY3K
    {Py_nb_long,    (void *)SbkNatronEngine_Natron_StandardButtonEnum_long},
#endif
    {0, nullptr} // sentinel
};
#else
static PyNumberMethods SbkNatronEngine_Natron_StandardButtonEnum_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkNatronEngine_Natron_StandardButtonEnum__nonzero,
    /*nb_invert*/               (unaryfunc)SbkNatronEngine_Natron_StandardButtonEnum___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkNatronEngine_Natron_StandardButtonEnum___and__,
    /*nb_xor*/                  (binaryfunc)SbkNatronEngine_Natron_StandardButtonEnum___xor__,
    /*nb_or*/                   (binaryfunc)SbkNatronEngine_Natron_StandardButtonEnum___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkNatronEngine_Natron_StandardButtonEnum_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkNatronEngine_Natron_StandardButtonEnum_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};
#endif


// Type conversion functions.

// Python to C++ enum conversion.
static void Natron_StatusEnum_PythonToCpp_Natron_StatusEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::StatusEnum*)cppOut) = (::Natron::StatusEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_StatusEnum_PythonToCpp_Natron_StatusEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX]))
        return Natron_StatusEnum_PythonToCpp_Natron_StatusEnum;
    return 0;
}
static PyObject* Natron_StatusEnum_CppToPython_Natron_StatusEnum(const void* cppIn) {
    int castCppIn = *((::Natron::StatusEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX], castCppIn);

}

static void Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::StandardButtonEnum*)cppOut) = (::Natron::StandardButtonEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum;
    return 0;
}
static PyObject* Natron_StandardButtonEnum_CppToPython_Natron_StandardButtonEnum(const void* cppIn) {
    int castCppIn = *((::Natron::StandardButtonEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX], castCppIn);

}

static void QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Natron::StandardButtonEnum>*)cppOut) = ::QFlags<Natron::StandardButtonEnum>(QFlag(int(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn)))));

}
static PythonToCppFunc is_QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]))
        return QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return 0;
}
static PyObject* QFlags_Natron_StandardButtonEnum__CppToPython_QFlags_Natron_StandardButtonEnum_(const void* cppIn) {
    int castCppIn = *((::QFlags<Natron::StandardButtonEnum>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]));

}

static void Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject* pyIn, void* cppOut) {
  *((::QFlags<Natron::StandardButtonEnum>*)cppOut) = ::QFlags<Natron::StandardButtonEnum>(QFlag(int(Shiboken::Enum::getValue(pyIn))));

}
static PythonToCppFunc is_Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return 0;
}
static void number_PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Natron::StandardButtonEnum>*)cppOut) = ::QFlags<Natron::StandardButtonEnum>(QFlag(int(PyLong_AsLong(pyLong.object()))));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return 0;
}
static void Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::KeyframeTypeEnum*)cppOut) = (::Natron::KeyframeTypeEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX]))
        return Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum;
    return 0;
}
static PyObject* Natron_KeyframeTypeEnum_CppToPython_Natron_KeyframeTypeEnum(const void* cppIn) {
    int castCppIn = *((::Natron::KeyframeTypeEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX], castCppIn);

}

static void Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::PixmapEnum*)cppOut) = (::Natron::PixmapEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX]))
        return Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum;
    return 0;
}
static PyObject* Natron_PixmapEnum_CppToPython_Natron_PixmapEnum(const void* cppIn) {
    int castCppIn = *((::Natron::PixmapEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX], castCppIn);

}

static void Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::ValueChangedReasonEnum*)cppOut) = (::Natron::ValueChangedReasonEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX]))
        return Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum;
    return 0;
}
static PyObject* Natron_ValueChangedReasonEnum_CppToPython_Natron_ValueChangedReasonEnum(const void* cppIn) {
    int castCppIn = *((::Natron::ValueChangedReasonEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX], castCppIn);

}

static void Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::AnimationLevelEnum*)cppOut) = (::Natron::AnimationLevelEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX]))
        return Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum;
    return 0;
}
static PyObject* Natron_AnimationLevelEnum_CppToPython_Natron_AnimationLevelEnum(const void* cppIn) {
    int castCppIn = *((::Natron::AnimationLevelEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX], castCppIn);

}

static void Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::ImagePremultiplicationEnum*)cppOut) = (::Natron::ImagePremultiplicationEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX]))
        return Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum;
    return 0;
}
static PyObject* Natron_ImagePremultiplicationEnum_CppToPython_Natron_ImagePremultiplicationEnum(const void* cppIn) {
    int castCppIn = *((::Natron::ImagePremultiplicationEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX], castCppIn);

}

static void Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::ViewerCompositingOperatorEnum*)cppOut) = (::Natron::ViewerCompositingOperatorEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX]))
        return Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum;
    return 0;
}
static PyObject* Natron_ViewerCompositingOperatorEnum_CppToPython_Natron_ViewerCompositingOperatorEnum(const void* cppIn) {
    int castCppIn = *((::Natron::ViewerCompositingOperatorEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX], castCppIn);

}

static void Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::ViewerColorSpaceEnum*)cppOut) = (::Natron::ViewerColorSpaceEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX]))
        return Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum;
    return 0;
}
static PyObject* Natron_ViewerColorSpaceEnum_CppToPython_Natron_ViewerColorSpaceEnum(const void* cppIn) {
    int castCppIn = *((::Natron::ViewerColorSpaceEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX], castCppIn);

}

static void Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::ImageBitDepthEnum*)cppOut) = (::Natron::ImageBitDepthEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX]))
        return Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum;
    return 0;
}
static PyObject* Natron_ImageBitDepthEnum_CppToPython_Natron_ImageBitDepthEnum(const void* cppIn) {
    int castCppIn = *((::Natron::ImageBitDepthEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX], castCppIn);

}

static void Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::OrientationEnum*)cppOut) = (::Natron::OrientationEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX]))
        return Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum;
    return 0;
}
static PyObject* Natron_OrientationEnum_CppToPython_Natron_OrientationEnum(const void* cppIn) {
    int castCppIn = *((::Natron::OrientationEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX], castCppIn);

}

static void Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::PlaybackModeEnum*)cppOut) = (::Natron::PlaybackModeEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX]))
        return Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum;
    return 0;
}
static PyObject* Natron_PlaybackModeEnum_CppToPython_Natron_PlaybackModeEnum(const void* cppIn) {
    int castCppIn = *((::Natron::PlaybackModeEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX], castCppIn);

}

static void Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::DisplayChannelsEnum*)cppOut) = (::Natron::DisplayChannelsEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX]))
        return Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum;
    return 0;
}
static PyObject* Natron_DisplayChannelsEnum_CppToPython_Natron_DisplayChannelsEnum(const void* cppIn) {
    int castCppIn = *((::Natron::DisplayChannelsEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX], castCppIn);

}

static void Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum(PyObject* pyIn, void* cppOut) {
    *((::Natron::MergingFunctionEnum*)cppOut) = (::Natron::MergingFunctionEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX]))
        return Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum;
    return 0;
}
static PyObject* Natron_MergingFunctionEnum_CppToPython_Natron_MergingFunctionEnum(const void* cppIn) {
    int castCppIn = *((::Natron::MergingFunctionEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX], castCppIn);

}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_SignatureStrings[] = {
    "NatronEngine.Natron.getAmountFreePhysicalRAM()->std.size_t",
    "NatronEngine.Natron.getSizeOfForBitDepth(bitdepth:NatronEngine.Natron.ImageBitDepthEnum)->int",
    "NatronEngine.Natron.isApplication32Bits()->bool",
    "NatronEngine.Natron.isFailureRetCode(code:NatronEngine.Natron.StatusEnum)->bool",
    nullptr}; // Sentinel
#endif

void init_Natron(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_Natron_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Natron",
        "Natron",
        &Sbk_Natron_spec,
        Natron_SignatureStrings,
        //&Shiboken::callCppDestructor< ::Natron >,
        nullptr,
        0,
        0,
        0    );

    SbkNatronEngineTypes[SBK_NATRON_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_TypeF());
#else
    SbkNatronEngineTypes[SBK_NATRON_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Natron_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Natron", "Natron",
        &Sbk_Natron_Type)) {
        return;
    }
#endif


    // Initialization of enums.

    // Initialization of enum 'StatusEnum'.
    SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
    Sbk_Natron_TypeF(),
#else
    &Sbk_Natron_Type,
#endif
        "StatusEnum",
        "NatronEngine.Natron.StatusEnum",
        "Natron::StatusEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStatusOK", (long) Natron::eStatusOK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStatusFailed", (long) Natron::eStatusFailed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStatusInputDisconnected", (long) Natron::eStatusInputDisconnected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStatusAborted", (long) Natron::eStatusAborted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStatusOutOfMemory", (long) Natron::eStatusOutOfMemory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStatusReplyDefault", (long) Natron::eStatusReplyDefault))
        return ;
    // Register converter for enum 'Natron::StatusEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
            Natron_StatusEnum_CppToPython_Natron_StatusEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StatusEnum_PythonToCpp_Natron_StatusEnum,
            is_Natron_StatusEnum_PythonToCpp_Natron_StatusEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StatusEnum");
        Shiboken::Conversions::registerConverterName(converter, "StatusEnum");
    }
    // End of 'StatusEnum' enum.

    // Initialization of enum 'StandardButtonEnum'.
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX] = PySide::QFlags::create("StandardButtons", SbkNatronEngine_Natron_StandardButtonEnum_number_slots);
#else
    SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX] = PySide::QFlags::create("StandardButtons", &SbkNatronEngine_Natron_StandardButtonEnum_as_number);
#endif
    SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
    Sbk_Natron_TypeF(),
#else
    &Sbk_Natron_Type,
#endif
        "StandardButtonEnum",
        "NatronEngine.Natron.StandardButtonEnum",
        "Natron::StandardButtonEnum",
        SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX]);
    if (!SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
    Sbk_Natron_TypeF(),
#else
    &Sbk_Natron_Type,
#endif
        "eStandardButtonNoButton", (long) Natron::eStandardButtonNoButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonEscape", (long) Natron::eStandardButtonEscape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonOk", (long) Natron::eStandardButtonOk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonSave", (long) Natron::eStandardButtonSave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonSaveAll", (long) Natron::eStandardButtonSaveAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonOpen", (long) Natron::eStandardButtonOpen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonYes", (long) Natron::eStandardButtonYes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonYesToAll", (long) Natron::eStandardButtonYesToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonNo", (long) Natron::eStandardButtonNo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonNoToAll", (long) Natron::eStandardButtonNoToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonAbort", (long) Natron::eStandardButtonAbort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonRetry", (long) Natron::eStandardButtonRetry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonIgnore", (long) Natron::eStandardButtonIgnore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonClose", (long) Natron::eStandardButtonClose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonCancel", (long) Natron::eStandardButtonCancel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonDiscard", (long) Natron::eStandardButtonDiscard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonHelp", (long) Natron::eStandardButtonHelp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonApply", (long) Natron::eStandardButtonApply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonReset", (long) Natron::eStandardButtonReset))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eStandardButtonRestoreDefaults", (long) Natron::eStandardButtonRestoreDefaults))
        return ;
    // Register converter for enum 'Natron::StandardButtonEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
            Natron_StandardButtonEnum_CppToPython_Natron_StandardButtonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum,
            is_Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StandardButtonEnum");
        Shiboken::Conversions::registerConverterName(converter, "StandardButtonEnum");
    }
    // Register converter for flag 'QFlags<Natron::StandardButtonEnum>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX],
            QFlags_Natron_StandardButtonEnum__CppToPython_QFlags_Natron_StandardButtonEnum_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_,
            is_Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_,
            is_QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Natron_StandardButtonEnum_,
            is_number_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Natron::StandardButtonEnum>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<StandardButtonEnum>");
    }
    // End of 'StandardButtonEnum' enum/flags.

    // Initialization of enum 'KeyframeTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "KeyframeTypeEnum",
        "NatronEngine.Natron.KeyframeTypeEnum",
        "Natron::KeyframeTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeConstant", (long) Natron::eKeyframeTypeConstant))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeLinear", (long) Natron::eKeyframeTypeLinear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeSmooth", (long) Natron::eKeyframeTypeSmooth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeCatmullRom", (long) Natron::eKeyframeTypeCatmullRom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeCubic", (long) Natron::eKeyframeTypeCubic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeHorizontal", (long) Natron::eKeyframeTypeHorizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeFree", (long) Natron::eKeyframeTypeFree))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeBroken", (long) Natron::eKeyframeTypeBroken))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eKeyframeTypeNone", (long) Natron::eKeyframeTypeNone))
        return ;
    // Register converter for enum 'Natron::KeyframeTypeEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
            Natron_KeyframeTypeEnum_CppToPython_Natron_KeyframeTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum,
            is_Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KeyframeTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "KeyframeTypeEnum");
    }
    // End of 'KeyframeTypeEnum' enum.

    // Initialization of enum 'PixmapEnum'.
    SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "PixmapEnum",
        "NatronEngine.Natron.PixmapEnum",
        "Natron::PixmapEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PREVIOUS", (long) Natron::NATRON_PIXMAP_PLAYER_PREVIOUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_FIRST_FRAME", (long) Natron::NATRON_PIXMAP_PLAYER_FIRST_FRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_NEXT", (long) Natron::NATRON_PIXMAP_PLAYER_NEXT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_LAST_FRAME", (long) Natron::NATRON_PIXMAP_PLAYER_LAST_FRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_NEXT_INCR", (long) Natron::NATRON_PIXMAP_PLAYER_NEXT_INCR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_NEXT_KEY", (long) Natron::NATRON_PIXMAP_PLAYER_NEXT_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PREVIOUS_INCR", (long) Natron::NATRON_PIXMAP_PLAYER_PREVIOUS_INCR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PREVIOUS_KEY", (long) Natron::NATRON_PIXMAP_PLAYER_PREVIOUS_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_REWIND_ENABLED", (long) Natron::NATRON_PIXMAP_PLAYER_REWIND_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_REWIND_DISABLED", (long) Natron::NATRON_PIXMAP_PLAYER_REWIND_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PLAY_ENABLED", (long) Natron::NATRON_PIXMAP_PLAYER_PLAY_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PLAY_DISABLED", (long) Natron::NATRON_PIXMAP_PLAYER_PLAY_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_STOP_DISABLED", (long) Natron::NATRON_PIXMAP_PLAYER_STOP_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_STOP_ENABLED", (long) Natron::NATRON_PIXMAP_PLAYER_STOP_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PAUSE_DISABLED", (long) Natron::NATRON_PIXMAP_PLAYER_PAUSE_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PAUSE_ENABLED", (long) Natron::NATRON_PIXMAP_PLAYER_PAUSE_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_LOOP_MODE", (long) Natron::NATRON_PIXMAP_PLAYER_LOOP_MODE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_BOUNCE", (long) Natron::NATRON_PIXMAP_PLAYER_BOUNCE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_PLAY_ONCE", (long) Natron::NATRON_PIXMAP_PLAYER_PLAY_ONCE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_TIMELINE_IN", (long) Natron::NATRON_PIXMAP_PLAYER_TIMELINE_IN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PLAYER_TIMELINE_OUT", (long) Natron::NATRON_PIXMAP_PLAYER_TIMELINE_OUT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MAXIMIZE_WIDGET", (long) Natron::NATRON_PIXMAP_MAXIMIZE_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MINIMIZE_WIDGET", (long) Natron::NATRON_PIXMAP_MINIMIZE_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CLOSE_WIDGET", (long) Natron::NATRON_PIXMAP_CLOSE_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_HELP_WIDGET", (long) Natron::NATRON_PIXMAP_HELP_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CLOSE_PANEL", (long) Natron::NATRON_PIXMAP_CLOSE_PANEL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_HIDE_UNMODIFIED", (long) Natron::NATRON_PIXMAP_HIDE_UNMODIFIED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UNHIDE_UNMODIFIED", (long) Natron::NATRON_PIXMAP_UNHIDE_UNMODIFIED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_GROUPBOX_FOLDED", (long) Natron::NATRON_PIXMAP_GROUPBOX_FOLDED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_GROUPBOX_UNFOLDED", (long) Natron::NATRON_PIXMAP_GROUPBOX_UNFOLDED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UNDO", (long) Natron::NATRON_PIXMAP_UNDO))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_REDO", (long) Natron::NATRON_PIXMAP_REDO))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UNDO_GRAYSCALE", (long) Natron::NATRON_PIXMAP_UNDO_GRAYSCALE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_REDO_GRAYSCALE", (long) Natron::NATRON_PIXMAP_REDO_GRAYSCALE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED", (long) Natron::NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED", (long) Natron::NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON", (long) Natron::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR", (long) Natron::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY", (long) Natron::NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY", (long) Natron::NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_CENTER", (long) Natron::NATRON_PIXMAP_VIEWER_CENTER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED", (long) Natron::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED", (long) Natron::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_FULL_FRAME_ON", (long) Natron::NATRON_PIXMAP_VIEWER_FULL_FRAME_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF", (long) Natron::NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_REFRESH", (long) Natron::NATRON_PIXMAP_VIEWER_REFRESH))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE", (long) Natron::NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_ROI_ENABLED", (long) Natron::NATRON_PIXMAP_VIEWER_ROI_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_ROI_DISABLED", (long) Natron::NATRON_PIXMAP_VIEWER_ROI_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_RENDER_SCALE", (long) Natron::NATRON_PIXMAP_VIEWER_RENDER_SCALE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED", (long) Natron::NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED", (long) Natron::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED", (long) Natron::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_OPEN_FILE", (long) Natron::NATRON_PIXMAP_OPEN_FILE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_COLORWHEEL", (long) Natron::NATRON_PIXMAP_COLORWHEEL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_OVERLAY", (long) Natron::NATRON_PIXMAP_OVERLAY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTO_MERGE", (long) Natron::NATRON_PIXMAP_ROTO_MERGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_COLOR_PICKER", (long) Natron::NATRON_PIXMAP_COLOR_PICKER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_IO_GROUPING", (long) Natron::NATRON_PIXMAP_IO_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_3D_GROUPING", (long) Natron::NATRON_PIXMAP_3D_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CHANNEL_GROUPING", (long) Natron::NATRON_PIXMAP_CHANNEL_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_GROUPING", (long) Natron::NATRON_PIXMAP_MERGE_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_COLOR_GROUPING", (long) Natron::NATRON_PIXMAP_COLOR_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRANSFORM_GROUPING", (long) Natron::NATRON_PIXMAP_TRANSFORM_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_DEEP_GROUPING", (long) Natron::NATRON_PIXMAP_DEEP_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_FILTER_GROUPING", (long) Natron::NATRON_PIXMAP_FILTER_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MULTIVIEW_GROUPING", (long) Natron::NATRON_PIXMAP_MULTIVIEW_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TOOLSETS_GROUPING", (long) Natron::NATRON_PIXMAP_TOOLSETS_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MISC_GROUPING", (long) Natron::NATRON_PIXMAP_MISC_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_OPEN_EFFECTS_GROUPING", (long) Natron::NATRON_PIXMAP_OPEN_EFFECTS_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TIME_GROUPING", (long) Natron::NATRON_PIXMAP_TIME_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PAINT_GROUPING", (long) Natron::NATRON_PIXMAP_PAINT_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_KEYER_GROUPING", (long) Natron::NATRON_PIXMAP_KEYER_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_OTHER_PLUGINS", (long) Natron::NATRON_PIXMAP_OTHER_PLUGINS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_READ_IMAGE", (long) Natron::NATRON_PIXMAP_READ_IMAGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_WRITE_IMAGE", (long) Natron::NATRON_PIXMAP_WRITE_IMAGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_COMBOBOX", (long) Natron::NATRON_PIXMAP_COMBOBOX))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_COMBOBOX_PRESSED", (long) Natron::NATRON_PIXMAP_COMBOBOX_PRESSED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ADD_KEYFRAME", (long) Natron::NATRON_PIXMAP_ADD_KEYFRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_REMOVE_KEYFRAME", (long) Natron::NATRON_PIXMAP_REMOVE_KEYFRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INVERTED", (long) Natron::NATRON_PIXMAP_INVERTED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UNINVERTED", (long) Natron::NATRON_PIXMAP_UNINVERTED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VISIBLE", (long) Natron::NATRON_PIXMAP_VISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UNVISIBLE", (long) Natron::NATRON_PIXMAP_UNVISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_LOCKED", (long) Natron::NATRON_PIXMAP_LOCKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UNLOCKED", (long) Natron::NATRON_PIXMAP_UNLOCKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_LAYER", (long) Natron::NATRON_PIXMAP_LAYER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_BEZIER", (long) Natron::NATRON_PIXMAP_BEZIER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PENCIL", (long) Natron::NATRON_PIXMAP_PENCIL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CURVE", (long) Natron::NATRON_PIXMAP_CURVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_BEZIER_32", (long) Natron::NATRON_PIXMAP_BEZIER_32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ELLIPSE", (long) Natron::NATRON_PIXMAP_ELLIPSE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_RECTANGLE", (long) Natron::NATRON_PIXMAP_RECTANGLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ADD_POINTS", (long) Natron::NATRON_PIXMAP_ADD_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_REMOVE_POINTS", (long) Natron::NATRON_PIXMAP_REMOVE_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CUSP_POINTS", (long) Natron::NATRON_PIXMAP_CUSP_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SMOOTH_POINTS", (long) Natron::NATRON_PIXMAP_SMOOTH_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_REMOVE_FEATHER", (long) Natron::NATRON_PIXMAP_REMOVE_FEATHER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_OPEN_CLOSE_CURVE", (long) Natron::NATRON_PIXMAP_OPEN_CLOSE_CURVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SELECT_ALL", (long) Natron::NATRON_PIXMAP_SELECT_ALL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SELECT_POINTS", (long) Natron::NATRON_PIXMAP_SELECT_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SELECT_FEATHER", (long) Natron::NATRON_PIXMAP_SELECT_FEATHER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SELECT_CURVES", (long) Natron::NATRON_PIXMAP_SELECT_CURVES))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_AUTO_KEYING_ENABLED", (long) Natron::NATRON_PIXMAP_AUTO_KEYING_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_AUTO_KEYING_DISABLED", (long) Natron::NATRON_PIXMAP_AUTO_KEYING_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_STICKY_SELECTION_ENABLED", (long) Natron::NATRON_PIXMAP_STICKY_SELECTION_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_STICKY_SELECTION_DISABLED", (long) Natron::NATRON_PIXMAP_STICKY_SELECTION_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_FEATHER_LINK_ENABLED", (long) Natron::NATRON_PIXMAP_FEATHER_LINK_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_FEATHER_LINK_DISABLED", (long) Natron::NATRON_PIXMAP_FEATHER_LINK_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_FEATHER_VISIBLE", (long) Natron::NATRON_PIXMAP_FEATHER_VISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_FEATHER_UNVISIBLE", (long) Natron::NATRON_PIXMAP_FEATHER_UNVISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_RIPPLE_EDIT_ENABLED", (long) Natron::NATRON_PIXMAP_RIPPLE_EDIT_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_RIPPLE_EDIT_DISABLED", (long) Natron::NATRON_PIXMAP_RIPPLE_EDIT_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_BLUR", (long) Natron::NATRON_PIXMAP_ROTOPAINT_BLUR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED", (long) Natron::NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED", (long) Natron::NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_BURN", (long) Natron::NATRON_PIXMAP_ROTOPAINT_BURN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_CLONE", (long) Natron::NATRON_PIXMAP_ROTOPAINT_CLONE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_DODGE", (long) Natron::NATRON_PIXMAP_ROTOPAINT_DODGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_ERASER", (long) Natron::NATRON_PIXMAP_ROTOPAINT_ERASER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED", (long) Natron::NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED", (long) Natron::NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_REVEAL", (long) Natron::NATRON_PIXMAP_ROTOPAINT_REVEAL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_SHARPEN", (long) Natron::NATRON_PIXMAP_ROTOPAINT_SHARPEN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_SMEAR", (long) Natron::NATRON_PIXMAP_ROTOPAINT_SMEAR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTOPAINT_SOLID", (long) Natron::NATRON_PIXMAP_ROTOPAINT_SOLID))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_BOLD_CHECKED", (long) Natron::NATRON_PIXMAP_BOLD_CHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_BOLD_UNCHECKED", (long) Natron::NATRON_PIXMAP_BOLD_UNCHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ITALIC_CHECKED", (long) Natron::NATRON_PIXMAP_ITALIC_CHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ITALIC_UNCHECKED", (long) Natron::NATRON_PIXMAP_ITALIC_UNCHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CLEAR_ALL_ANIMATION", (long) Natron::NATRON_PIXMAP_CLEAR_ALL_ANIMATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION", (long) Natron::NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION", (long) Natron::NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UPDATE_VIEWER_ENABLED", (long) Natron::NATRON_PIXMAP_UPDATE_VIEWER_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_UPDATE_VIEWER_DISABLED", (long) Natron::NATRON_PIXMAP_UPDATE_VIEWER_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ADD_TRACK", (long) Natron::NATRON_PIXMAP_ADD_TRACK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ADD_USER_KEY", (long) Natron::NATRON_PIXMAP_ADD_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_REMOVE_USER_KEY", (long) Natron::NATRON_PIXMAP_REMOVE_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SHOW_TRACK_ERROR", (long) Natron::NATRON_PIXMAP_SHOW_TRACK_ERROR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_HIDE_TRACK_ERROR", (long) Natron::NATRON_PIXMAP_HIDE_TRACK_ERROR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_RESET_TRACK_OFFSET", (long) Natron::NATRON_PIXMAP_RESET_TRACK_OFFSET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON", (long) Natron::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF", (long) Natron::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_RESET_USER_KEYS", (long) Natron::NATRON_PIXMAP_RESET_USER_KEYS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK", (long) Natron::NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_BACKWARD_ON", (long) Natron::NATRON_PIXMAP_TRACK_BACKWARD_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_BACKWARD_OFF", (long) Natron::NATRON_PIXMAP_TRACK_BACKWARD_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_FORWARD_ON", (long) Natron::NATRON_PIXMAP_TRACK_FORWARD_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_FORWARD_OFF", (long) Natron::NATRON_PIXMAP_TRACK_FORWARD_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_PREVIOUS", (long) Natron::NATRON_PIXMAP_TRACK_PREVIOUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_NEXT", (long) Natron::NATRON_PIXMAP_TRACK_NEXT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_RANGE", (long) Natron::NATRON_PIXMAP_TRACK_RANGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_ALL_KEYS", (long) Natron::NATRON_PIXMAP_TRACK_ALL_KEYS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_TRACK_CURRENT_KEY", (long) Natron::NATRON_PIXMAP_TRACK_CURRENT_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_NEXT_USER_KEY", (long) Natron::NATRON_PIXMAP_NEXT_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_PREV_USER_KEY", (long) Natron::NATRON_PIXMAP_PREV_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ENTER_GROUP", (long) Natron::NATRON_PIXMAP_ENTER_GROUP))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SETTINGS", (long) Natron::NATRON_PIXMAP_SETTINGS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_FREEZE_ENABLED", (long) Natron::NATRON_PIXMAP_FREEZE_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_FREEZE_DISABLED", (long) Natron::NATRON_PIXMAP_FREEZE_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_ICON", (long) Natron::NATRON_PIXMAP_VIEWER_ICON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED", (long) Natron::NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED", (long) Natron::NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED", (long) Natron::NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED", (long) Natron::NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_GAMMA_ENABLED", (long) Natron::NATRON_PIXMAP_VIEWER_GAMMA_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_GAMMA_DISABLED", (long) Natron::NATRON_PIXMAP_VIEWER_GAMMA_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_GAIN_ENABLED", (long) Natron::NATRON_PIXMAP_VIEWER_GAIN_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_VIEWER_GAIN_DISABLED", (long) Natron::NATRON_PIXMAP_VIEWER_GAIN_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT", (long) Natron::NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT", (long) Natron::NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT", (long) Natron::NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT", (long) Natron::NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT", (long) Natron::NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED", (long) Natron::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED", (long) Natron::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT", (long) Natron::NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT", (long) Natron::NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_ATOP", (long) Natron::NATRON_PIXMAP_MERGE_ATOP))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_AVERAGE", (long) Natron::NATRON_PIXMAP_MERGE_AVERAGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_COLOR", (long) Natron::NATRON_PIXMAP_MERGE_COLOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_COLOR_BURN", (long) Natron::NATRON_PIXMAP_MERGE_COLOR_BURN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_COLOR_DODGE", (long) Natron::NATRON_PIXMAP_MERGE_COLOR_DODGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_CONJOINT_OVER", (long) Natron::NATRON_PIXMAP_MERGE_CONJOINT_OVER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_COPY", (long) Natron::NATRON_PIXMAP_MERGE_COPY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_DIFFERENCE", (long) Natron::NATRON_PIXMAP_MERGE_DIFFERENCE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_DISJOINT_OVER", (long) Natron::NATRON_PIXMAP_MERGE_DISJOINT_OVER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_DIVIDE", (long) Natron::NATRON_PIXMAP_MERGE_DIVIDE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_EXCLUSION", (long) Natron::NATRON_PIXMAP_MERGE_EXCLUSION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_FREEZE", (long) Natron::NATRON_PIXMAP_MERGE_FREEZE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_FROM", (long) Natron::NATRON_PIXMAP_MERGE_FROM))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_GEOMETRIC", (long) Natron::NATRON_PIXMAP_MERGE_GEOMETRIC))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_GRAIN_EXTRACT", (long) Natron::NATRON_PIXMAP_MERGE_GRAIN_EXTRACT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_GRAIN_MERGE", (long) Natron::NATRON_PIXMAP_MERGE_GRAIN_MERGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_HARD_LIGHT", (long) Natron::NATRON_PIXMAP_MERGE_HARD_LIGHT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_HUE", (long) Natron::NATRON_PIXMAP_MERGE_HUE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_HYPOT", (long) Natron::NATRON_PIXMAP_MERGE_HYPOT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_IN", (long) Natron::NATRON_PIXMAP_MERGE_IN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_LUMINOSITY", (long) Natron::NATRON_PIXMAP_MERGE_LUMINOSITY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_MASK", (long) Natron::NATRON_PIXMAP_MERGE_MASK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_MATTE", (long) Natron::NATRON_PIXMAP_MERGE_MATTE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_MAX", (long) Natron::NATRON_PIXMAP_MERGE_MAX))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_MIN", (long) Natron::NATRON_PIXMAP_MERGE_MIN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_MINUS", (long) Natron::NATRON_PIXMAP_MERGE_MINUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_MULTIPLY", (long) Natron::NATRON_PIXMAP_MERGE_MULTIPLY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_OUT", (long) Natron::NATRON_PIXMAP_MERGE_OUT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_OVER", (long) Natron::NATRON_PIXMAP_MERGE_OVER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_OVERLAY", (long) Natron::NATRON_PIXMAP_MERGE_OVERLAY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_PINLIGHT", (long) Natron::NATRON_PIXMAP_MERGE_PINLIGHT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_PLUS", (long) Natron::NATRON_PIXMAP_MERGE_PLUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_REFLECT", (long) Natron::NATRON_PIXMAP_MERGE_REFLECT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_SATURATION", (long) Natron::NATRON_PIXMAP_MERGE_SATURATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_SCREEN", (long) Natron::NATRON_PIXMAP_MERGE_SCREEN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_SOFT_LIGHT", (long) Natron::NATRON_PIXMAP_MERGE_SOFT_LIGHT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_STENCIL", (long) Natron::NATRON_PIXMAP_MERGE_STENCIL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_UNDER", (long) Natron::NATRON_PIXMAP_MERGE_UNDER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_MERGE_XOR", (long) Natron::NATRON_PIXMAP_MERGE_XOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_ROTO_NODE_ICON", (long) Natron::NATRON_PIXMAP_ROTO_NODE_ICON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_LINK_CURSOR", (long) Natron::NATRON_PIXMAP_LINK_CURSOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_LINK_MULT_CURSOR", (long) Natron::NATRON_PIXMAP_LINK_MULT_CURSOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_APP_ICON", (long) Natron::NATRON_PIXMAP_APP_ICON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_LINEAR", (long) Natron::NATRON_PIXMAP_INTERP_LINEAR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_CURVE", (long) Natron::NATRON_PIXMAP_INTERP_CURVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_CONSTANT", (long) Natron::NATRON_PIXMAP_INTERP_CONSTANT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_BREAK", (long) Natron::NATRON_PIXMAP_INTERP_BREAK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_CURVE_C", (long) Natron::NATRON_PIXMAP_INTERP_CURVE_C))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_CURVE_H", (long) Natron::NATRON_PIXMAP_INTERP_CURVE_H))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_CURVE_R", (long) Natron::NATRON_PIXMAP_INTERP_CURVE_R))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "NATRON_PIXMAP_INTERP_CURVE_Z", (long) Natron::NATRON_PIXMAP_INTERP_CURVE_Z))
        return ;
    // Register converter for enum 'Natron::PixmapEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
            Natron_PixmapEnum_CppToPython_Natron_PixmapEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum,
            is_Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PixmapEnum");
        Shiboken::Conversions::registerConverterName(converter, "PixmapEnum");
    }
    // End of 'PixmapEnum' enum.

    // Initialization of enum 'ValueChangedReasonEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ValueChangedReasonEnum",
        "NatronEngine.Natron.ValueChangedReasonEnum",
        "Natron::ValueChangedReasonEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eValueChangedReasonUserEdited", (long) Natron::eValueChangedReasonUserEdited))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eValueChangedReasonPluginEdited", (long) Natron::eValueChangedReasonPluginEdited))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eValueChangedReasonNatronGuiEdited", (long) Natron::eValueChangedReasonNatronGuiEdited))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eValueChangedReasonNatronInternalEdited", (long) Natron::eValueChangedReasonNatronInternalEdited))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eValueChangedReasonTimeChanged", (long) Natron::eValueChangedReasonTimeChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eValueChangedReasonSlaveRefresh", (long) Natron::eValueChangedReasonSlaveRefresh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eValueChangedReasonRestoreDefault", (long) Natron::eValueChangedReasonRestoreDefault))
        return ;
    // Register converter for enum 'Natron::ValueChangedReasonEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
            Natron_ValueChangedReasonEnum_CppToPython_Natron_ValueChangedReasonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum,
            is_Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ValueChangedReasonEnum");
        Shiboken::Conversions::registerConverterName(converter, "ValueChangedReasonEnum");
    }
    // End of 'ValueChangedReasonEnum' enum.

    // Initialization of enum 'AnimationLevelEnum'.
    SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "AnimationLevelEnum",
        "NatronEngine.Natron.AnimationLevelEnum",
        "Natron::AnimationLevelEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eAnimationLevelNone", (long) Natron::eAnimationLevelNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eAnimationLevelInterpolatedValue", (long) Natron::eAnimationLevelInterpolatedValue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eAnimationLevelOnKeyframe", (long) Natron::eAnimationLevelOnKeyframe))
        return ;
    // Register converter for enum 'Natron::AnimationLevelEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
            Natron_AnimationLevelEnum_CppToPython_Natron_AnimationLevelEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum,
            is_Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::AnimationLevelEnum");
        Shiboken::Conversions::registerConverterName(converter, "AnimationLevelEnum");
    }
    // End of 'AnimationLevelEnum' enum.

    // Initialization of enum 'ImagePremultiplicationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ImagePremultiplicationEnum",
        "NatronEngine.Natron.ImagePremultiplicationEnum",
        "Natron::ImagePremultiplicationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImagePremultiplicationOpaque", (long) Natron::eImagePremultiplicationOpaque))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImagePremultiplicationPremultiplied", (long) Natron::eImagePremultiplicationPremultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImagePremultiplicationUnPremultiplied", (long) Natron::eImagePremultiplicationUnPremultiplied))
        return ;
    // Register converter for enum 'Natron::ImagePremultiplicationEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
            Natron_ImagePremultiplicationEnum_CppToPython_Natron_ImagePremultiplicationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum,
            is_Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImagePremultiplicationEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImagePremultiplicationEnum");
    }
    // End of 'ImagePremultiplicationEnum' enum.

    // Initialization of enum 'ViewerCompositingOperatorEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ViewerCompositingOperatorEnum",
        "NatronEngine.Natron.ViewerCompositingOperatorEnum",
        "Natron::ViewerCompositingOperatorEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorNone", (long) Natron::eViewerCompositingOperatorNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorWipeUnder", (long) Natron::eViewerCompositingOperatorWipeUnder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorWipeOver", (long) Natron::eViewerCompositingOperatorWipeOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorWipeMinus", (long) Natron::eViewerCompositingOperatorWipeMinus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorWipeOnionSkin", (long) Natron::eViewerCompositingOperatorWipeOnionSkin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorStackUnder", (long) Natron::eViewerCompositingOperatorStackUnder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorStackOver", (long) Natron::eViewerCompositingOperatorStackOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorStackMinus", (long) Natron::eViewerCompositingOperatorStackMinus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerCompositingOperatorStackOnionSkin", (long) Natron::eViewerCompositingOperatorStackOnionSkin))
        return ;
    // Register converter for enum 'Natron::ViewerCompositingOperatorEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
            Natron_ViewerCompositingOperatorEnum_CppToPython_Natron_ViewerCompositingOperatorEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum,
            is_Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ViewerCompositingOperatorEnum");
        Shiboken::Conversions::registerConverterName(converter, "ViewerCompositingOperatorEnum");
    }
    // End of 'ViewerCompositingOperatorEnum' enum.

    // Initialization of enum 'ViewerColorSpaceEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ViewerColorSpaceEnum",
        "NatronEngine.Natron.ViewerColorSpaceEnum",
        "Natron::ViewerColorSpaceEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerColorSpaceSRGB", (long) Natron::eViewerColorSpaceSRGB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerColorSpaceLinear", (long) Natron::eViewerColorSpaceLinear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eViewerColorSpaceRec709", (long) Natron::eViewerColorSpaceRec709))
        return ;
    // Register converter for enum 'Natron::ViewerColorSpaceEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
            Natron_ViewerColorSpaceEnum_CppToPython_Natron_ViewerColorSpaceEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum,
            is_Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ViewerColorSpaceEnum");
        Shiboken::Conversions::registerConverterName(converter, "ViewerColorSpaceEnum");
    }
    // End of 'ViewerColorSpaceEnum' enum.

    // Initialization of enum 'ImageBitDepthEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ImageBitDepthEnum",
        "NatronEngine.Natron.ImageBitDepthEnum",
        "Natron::ImageBitDepthEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImageBitDepthNone", (long) Natron::eImageBitDepthNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImageBitDepthByte", (long) Natron::eImageBitDepthByte))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImageBitDepthShort", (long) Natron::eImageBitDepthShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImageBitDepthHalf", (long) Natron::eImageBitDepthHalf))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eImageBitDepthFloat", (long) Natron::eImageBitDepthFloat))
        return ;
    // Register converter for enum 'Natron::ImageBitDepthEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
            Natron_ImageBitDepthEnum_CppToPython_Natron_ImageBitDepthEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum,
            is_Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImageBitDepthEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImageBitDepthEnum");
    }
    // End of 'ImageBitDepthEnum' enum.

    // Initialization of enum 'OrientationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "OrientationEnum",
        "NatronEngine.Natron.OrientationEnum",
        "Natron::OrientationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eOrientationHorizontal", (long) Natron::eOrientationHorizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eOrientationVertical", (long) Natron::eOrientationVertical))
        return ;
    // Register converter for enum 'Natron::OrientationEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
            Natron_OrientationEnum_CppToPython_Natron_OrientationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum,
            is_Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::OrientationEnum");
        Shiboken::Conversions::registerConverterName(converter, "OrientationEnum");
    }
    // End of 'OrientationEnum' enum.

    // Initialization of enum 'PlaybackModeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "PlaybackModeEnum",
        "NatronEngine.Natron.PlaybackModeEnum",
        "Natron::PlaybackModeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ePlaybackModeLoop", (long) Natron::ePlaybackModeLoop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ePlaybackModeBounce", (long) Natron::ePlaybackModeBounce))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "ePlaybackModeOnce", (long) Natron::ePlaybackModeOnce))
        return ;
    // Register converter for enum 'Natron::PlaybackModeEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
            Natron_PlaybackModeEnum_CppToPython_Natron_PlaybackModeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum,
            is_Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PlaybackModeEnum");
        Shiboken::Conversions::registerConverterName(converter, "PlaybackModeEnum");
    }
    // End of 'PlaybackModeEnum' enum.

    // Initialization of enum 'DisplayChannelsEnum'.
    SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "DisplayChannelsEnum",
        "NatronEngine.Natron.DisplayChannelsEnum",
        "Natron::DisplayChannelsEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eDisplayChannelsRGB", (long) Natron::eDisplayChannelsRGB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eDisplayChannelsR", (long) Natron::eDisplayChannelsR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eDisplayChannelsG", (long) Natron::eDisplayChannelsG))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eDisplayChannelsB", (long) Natron::eDisplayChannelsB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eDisplayChannelsA", (long) Natron::eDisplayChannelsA))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eDisplayChannelsY", (long) Natron::eDisplayChannelsY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eDisplayChannelsMatte", (long) Natron::eDisplayChannelsMatte))
        return ;
    // Register converter for enum 'Natron::DisplayChannelsEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
            Natron_DisplayChannelsEnum_CppToPython_Natron_DisplayChannelsEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum,
            is_Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::DisplayChannelsEnum");
        Shiboken::Conversions::registerConverterName(converter, "DisplayChannelsEnum");
    }
    // End of 'DisplayChannelsEnum' enum.

    // Initialization of enum 'MergingFunctionEnum'.
    SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX] = Shiboken::Enum::createScopedEnum(
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "MergingFunctionEnum",
        "NatronEngine.Natron.MergingFunctionEnum",
        "Natron::MergingFunctionEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeATop", (long) Natron::eMergeATop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeAverage", (long) Natron::eMergeAverage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeColor", (long) Natron::eMergeColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeColorBurn", (long) Natron::eMergeColorBurn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeColorDodge", (long) Natron::eMergeColorDodge))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeConjointOver", (long) Natron::eMergeConjointOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeCopy", (long) Natron::eMergeCopy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeDifference", (long) Natron::eMergeDifference))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeDisjointOver", (long) Natron::eMergeDisjointOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeDivide", (long) Natron::eMergeDivide))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeExclusion", (long) Natron::eMergeExclusion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeFreeze", (long) Natron::eMergeFreeze))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeFrom", (long) Natron::eMergeFrom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeGeometric", (long) Natron::eMergeGeometric))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeGrainExtract", (long) Natron::eMergeGrainExtract))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeGrainMerge", (long) Natron::eMergeGrainMerge))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeHardLight", (long) Natron::eMergeHardLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeHue", (long) Natron::eMergeHue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeHypot", (long) Natron::eMergeHypot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeIn", (long) Natron::eMergeIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeLuminosity", (long) Natron::eMergeLuminosity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeMask", (long) Natron::eMergeMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeMatte", (long) Natron::eMergeMatte))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeMax", (long) Natron::eMergeMax))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeMin", (long) Natron::eMergeMin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeMinus", (long) Natron::eMergeMinus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeMultiply", (long) Natron::eMergeMultiply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeOut", (long) Natron::eMergeOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeOver", (long) Natron::eMergeOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeOverlay", (long) Natron::eMergeOverlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergePinLight", (long) Natron::eMergePinLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergePlus", (long) Natron::eMergePlus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeReflect", (long) Natron::eMergeReflect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeSaturation", (long) Natron::eMergeSaturation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeScreen", (long) Natron::eMergeScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeSoftLight", (long) Natron::eMergeSoftLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeStencil", (long) Natron::eMergeStencil))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeUnder", (long) Natron::eMergeUnder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
#if SHIBOKEN_MAJOR_VERSION >= 2
        Sbk_Natron_TypeF(),
#else
        &Sbk_Natron_Type,
#endif
        "eMergeXOR", (long) Natron::eMergeXOR))
        return ;
    // Register converter for enum 'Natron::MergingFunctionEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
            Natron_MergingFunctionEnum_CppToPython_Natron_MergingFunctionEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum,
            is_Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::MergingFunctionEnum");
        Shiboken::Conversions::registerConverterName(converter, "MergingFunctionEnum");
    }
    // End of 'MergingFunctionEnum' enum.


    qRegisterMetaType< ::Natron::StatusEnum >("Natron::StatusEnum");
    qRegisterMetaType< ::Natron::StandardButtonEnum >("Natron::StandardButtonEnum");
    qRegisterMetaType< ::Natron::StandardButtons >("Natron::StandardButtons");
    qRegisterMetaType< ::Natron::KeyframeTypeEnum >("Natron::KeyframeTypeEnum");
    qRegisterMetaType< ::Natron::PixmapEnum >("Natron::PixmapEnum");
    qRegisterMetaType< ::Natron::ValueChangedReasonEnum >("Natron::ValueChangedReasonEnum");
    qRegisterMetaType< ::Natron::AnimationLevelEnum >("Natron::AnimationLevelEnum");
    qRegisterMetaType< ::Natron::ImagePremultiplicationEnum >("Natron::ImagePremultiplicationEnum");
    qRegisterMetaType< ::Natron::ViewerCompositingOperatorEnum >("Natron::ViewerCompositingOperatorEnum");
    qRegisterMetaType< ::Natron::ViewerColorSpaceEnum >("Natron::ViewerColorSpaceEnum");
    qRegisterMetaType< ::Natron::ImageBitDepthEnum >("Natron::ImageBitDepthEnum");
    qRegisterMetaType< ::Natron::OrientationEnum >("Natron::OrientationEnum");
    qRegisterMetaType< ::Natron::PlaybackModeEnum >("Natron::PlaybackModeEnum");
    qRegisterMetaType< ::Natron::DisplayChannelsEnum >("Natron::DisplayChannelsEnum");
    qRegisterMetaType< ::Natron::MergingFunctionEnum >("Natron::MergingFunctionEnum");
}
