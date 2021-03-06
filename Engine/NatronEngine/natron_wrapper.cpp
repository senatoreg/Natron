
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
#include "natron_wrapper.h"

// inner classes
#include "natron_recti_wrapper.h"
#include "natron_rectd_wrapper.h"
#include "natron_python_wrapper.h"

#include <cctype>
#include <cstring>



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
static PyObject *Sbk_NatronFunc_getAmountFreePhysicalRAM(PyObject *self)
{
    PyObject *pyResult{};

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

static PyObject *Sbk_NatronFunc_isApplication32Bits(PyObject *self)
{
    PyObject *pyResult{};

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

static PyObject *Sbk_NatronFunc_isFailureRetCode(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Natron::isFailureRetCode(Natron::StatusEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])->converter, (pyArg)))) {
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


static const char *Sbk_Natron_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_methods[] = {
    {"getAmountFreePhysicalRAM", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_getAmountFreePhysicalRAM), METH_NOARGS|METH_STATIC},
    {"isApplication32Bits", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_isApplication32Bits), METH_NOARGS|METH_STATIC},
    {"isFailureRetCode", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_isFailureRetCode), METH_O|METH_STATIC},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Type = nullptr;
static SbkObjectType *Sbk_Natron_TypeF(void)
{
    return _Sbk_Natron_Type;
}

static PyType_Slot Sbk_Natron_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(Sbk_object_dealloc /* PYSIDE-832: Prevent replacement of "0" with subtype_dealloc. */)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_spec = {
    "1:NatronEngine.Natron",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_slots
};

} //extern "C"

PyObject *SbkNatronEngine_Natron_StandardButtonEnum___and__(PyObject *self, PyObject *pyArg)
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
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

PyObject *SbkNatronEngine_Natron_StandardButtonEnum___or__(PyObject *self, PyObject *pyArg)
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
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

PyObject *SbkNatronEngine_Natron_StandardButtonEnum___xor__(PyObject *self, PyObject *pyArg)
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
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

PyObject *SbkNatronEngine_Natron_StandardButtonEnum___invert__(PyObject *self, PyObject *pyArg)
{
    ::Natron::StandardButtons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, self, &cppSelf);
    ::Natron::StandardButtons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

static PyObject *SbkNatronEngine_Natron_StandardButtonEnum_long(PyObject *self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkNatronEngine_Natron_StandardButtonEnum__nonzero(PyObject *self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, self, &val);
    return val != 0;
}

static PyType_Slot SbkNatronEngine_Natron_StandardButtonEnum_number_slots[] = {
#ifdef IS_PY3K
    {Py_nb_bool,    reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum__nonzero)},
#else
    {Py_nb_nonzero, reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum__nonzero)},
    {Py_nb_long,    reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum_long)},
#endif
    {Py_nb_invert,  reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum___invert__)},
    {Py_nb_and,     reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum___and__)},
    {Py_nb_xor,     reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum___xor__)},
    {Py_nb_or,      reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum___or__)},
    {Py_nb_int,     reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum_long)},
    {Py_nb_index,   reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum_long)},
#ifndef IS_PY3K
    {Py_nb_long,    reinterpret_cast<void *>(SbkNatronEngine_Natron_StandardButtonEnum_long)},
#endif
    {0, nullptr} // sentinel
};



// Type conversion functions.

// Python to C++ enum conversion.
static void Natron_ScaleTypeEnum_PythonToCpp_Natron_ScaleTypeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ScaleTypeEnum *>(cppOut) =
        static_cast<::Natron::ScaleTypeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ScaleTypeEnum_PythonToCpp_Natron_ScaleTypeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX]))
        return Natron_ScaleTypeEnum_PythonToCpp_Natron_ScaleTypeEnum;
    return {};
}
static PyObject *Natron_ScaleTypeEnum_CppToPython_Natron_ScaleTypeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ScaleTypeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX], castCppIn);

}

static void Natron_TimelineStateEnum_PythonToCpp_Natron_TimelineStateEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::TimelineStateEnum *>(cppOut) =
        static_cast<::Natron::TimelineStateEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_TimelineStateEnum_PythonToCpp_Natron_TimelineStateEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX]))
        return Natron_TimelineStateEnum_PythonToCpp_Natron_TimelineStateEnum;
    return {};
}
static PyObject *Natron_TimelineStateEnum_CppToPython_Natron_TimelineStateEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::TimelineStateEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX], castCppIn);

}

static void Natron_TimelineChangeReasonEnum_PythonToCpp_Natron_TimelineChangeReasonEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::TimelineChangeReasonEnum *>(cppOut) =
        static_cast<::Natron::TimelineChangeReasonEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_TimelineChangeReasonEnum_PythonToCpp_Natron_TimelineChangeReasonEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX]))
        return Natron_TimelineChangeReasonEnum_PythonToCpp_Natron_TimelineChangeReasonEnum;
    return {};
}
static PyObject *Natron_TimelineChangeReasonEnum_CppToPython_Natron_TimelineChangeReasonEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::TimelineChangeReasonEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX], castCppIn);

}

static void Natron_StatusEnum_PythonToCpp_Natron_StatusEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::StatusEnum *>(cppOut) =
        static_cast<::Natron::StatusEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_StatusEnum_PythonToCpp_Natron_StatusEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX]))
        return Natron_StatusEnum_PythonToCpp_Natron_StatusEnum;
    return {};
}
static PyObject *Natron_StatusEnum_CppToPython_Natron_StatusEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::StatusEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX], castCppIn);

}

static void Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::StandardButtonEnum *>(cppOut) =
        static_cast<::Natron::StandardButtonEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum;
    return {};
}
static PyObject *Natron_StandardButtonEnum_CppToPython_Natron_StandardButtonEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::StandardButtonEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX], castCppIn);

}

static void QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::QFlags<Natron::StandardButtonEnum> *>(cppOut) =
        ::QFlags<Natron::StandardButtonEnum>(QFlag(int(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject *>(pyIn)))));

}
static PythonToCppFunc is_QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX]))
        return QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return {};
}
static PyObject *QFlags_Natron_StandardButtonEnum__CppToPython_QFlags_Natron_StandardButtonEnum_(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::QFlags<Natron::StandardButtonEnum> *>(cppIn));
    return reinterpret_cast<PyObject *>(PySide::QFlags::newObject(castCppIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX]));

}

static void Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::QFlags<Natron::StandardButtonEnum> *>(cppOut) =
        ::QFlags<Natron::StandardButtonEnum>(QFlag(int(Shiboken::Enum::getValue(pyIn))));

}
static PythonToCppFunc is_Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return {};
}
static void number_PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject *pyIn, void *cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *reinterpret_cast<::QFlags<Natron::StandardButtonEnum> *>(cppOut) =
        ::QFlags<Natron::StandardButtonEnum>(QFlag(int(PyLong_AsLong(pyLong.object()))));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject *pyIn) {
    if (PyNumber_Check(pyIn) && PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return number_PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return {};
}
static void Natron_MessageTypeEnum_PythonToCpp_Natron_MessageTypeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::MessageTypeEnum *>(cppOut) =
        static_cast<::Natron::MessageTypeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_MessageTypeEnum_PythonToCpp_Natron_MessageTypeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX]))
        return Natron_MessageTypeEnum_PythonToCpp_Natron_MessageTypeEnum;
    return {};
}
static PyObject *Natron_MessageTypeEnum_CppToPython_Natron_MessageTypeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::MessageTypeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX], castCppIn);

}

static void Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::KeyframeTypeEnum *>(cppOut) =
        static_cast<::Natron::KeyframeTypeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX]))
        return Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum;
    return {};
}
static PyObject *Natron_KeyframeTypeEnum_CppToPython_Natron_KeyframeTypeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::KeyframeTypeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX], castCppIn);

}

static void Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::PixmapEnum *>(cppOut) =
        static_cast<::Natron::PixmapEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX]))
        return Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum;
    return {};
}
static PyObject *Natron_PixmapEnum_CppToPython_Natron_PixmapEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::PixmapEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX], castCppIn);

}

static void Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ValueChangedReasonEnum *>(cppOut) =
        static_cast<::Natron::ValueChangedReasonEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX]))
        return Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum;
    return {};
}
static PyObject *Natron_ValueChangedReasonEnum_CppToPython_Natron_ValueChangedReasonEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ValueChangedReasonEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX], castCppIn);

}

static void Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::AnimationLevelEnum *>(cppOut) =
        static_cast<::Natron::AnimationLevelEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX]))
        return Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum;
    return {};
}
static PyObject *Natron_AnimationLevelEnum_CppToPython_Natron_AnimationLevelEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::AnimationLevelEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX], castCppIn);

}

static void Natron_ImagePlaneDescEnum_PythonToCpp_Natron_ImagePlaneDescEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ImagePlaneDescEnum *>(cppOut) =
        static_cast<::Natron::ImagePlaneDescEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ImagePlaneDescEnum_PythonToCpp_Natron_ImagePlaneDescEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX]))
        return Natron_ImagePlaneDescEnum_PythonToCpp_Natron_ImagePlaneDescEnum;
    return {};
}
static PyObject *Natron_ImagePlaneDescEnum_CppToPython_Natron_ImagePlaneDescEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ImagePlaneDescEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX], castCppIn);

}

static void Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ImagePremultiplicationEnum *>(cppOut) =
        static_cast<::Natron::ImagePremultiplicationEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX]))
        return Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum;
    return {};
}
static PyObject *Natron_ImagePremultiplicationEnum_CppToPython_Natron_ImagePremultiplicationEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ImagePremultiplicationEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX], castCppIn);

}

static void Natron_ImageFieldingOrderEnum_PythonToCpp_Natron_ImageFieldingOrderEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ImageFieldingOrderEnum *>(cppOut) =
        static_cast<::Natron::ImageFieldingOrderEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ImageFieldingOrderEnum_PythonToCpp_Natron_ImageFieldingOrderEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX]))
        return Natron_ImageFieldingOrderEnum_PythonToCpp_Natron_ImageFieldingOrderEnum;
    return {};
}
static PyObject *Natron_ImageFieldingOrderEnum_CppToPython_Natron_ImageFieldingOrderEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ImageFieldingOrderEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX], castCppIn);

}

static void Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ViewerCompositingOperatorEnum *>(cppOut) =
        static_cast<::Natron::ViewerCompositingOperatorEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX]))
        return Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum;
    return {};
}
static PyObject *Natron_ViewerCompositingOperatorEnum_CppToPython_Natron_ViewerCompositingOperatorEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ViewerCompositingOperatorEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX], castCppIn);

}

static void Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ViewerColorSpaceEnum *>(cppOut) =
        static_cast<::Natron::ViewerColorSpaceEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX]))
        return Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum;
    return {};
}
static PyObject *Natron_ViewerColorSpaceEnum_CppToPython_Natron_ViewerColorSpaceEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ViewerColorSpaceEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX], castCppIn);

}

static void Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ImageBitDepthEnum *>(cppOut) =
        static_cast<::Natron::ImageBitDepthEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX]))
        return Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum;
    return {};
}
static PyObject *Natron_ImageBitDepthEnum_CppToPython_Natron_ImageBitDepthEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ImageBitDepthEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX], castCppIn);

}

static void Natron_SequentialPreferenceEnum_PythonToCpp_Natron_SequentialPreferenceEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::SequentialPreferenceEnum *>(cppOut) =
        static_cast<::Natron::SequentialPreferenceEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_SequentialPreferenceEnum_PythonToCpp_Natron_SequentialPreferenceEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX]))
        return Natron_SequentialPreferenceEnum_PythonToCpp_Natron_SequentialPreferenceEnum;
    return {};
}
static PyObject *Natron_SequentialPreferenceEnum_CppToPython_Natron_SequentialPreferenceEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::SequentialPreferenceEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX], castCppIn);

}

static void Natron_StorageModeEnum_PythonToCpp_Natron_StorageModeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::StorageModeEnum *>(cppOut) =
        static_cast<::Natron::StorageModeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_StorageModeEnum_PythonToCpp_Natron_StorageModeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX]))
        return Natron_StorageModeEnum_PythonToCpp_Natron_StorageModeEnum;
    return {};
}
static PyObject *Natron_StorageModeEnum_CppToPython_Natron_StorageModeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::StorageModeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX], castCppIn);

}

static void Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::OrientationEnum *>(cppOut) =
        static_cast<::Natron::OrientationEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX]))
        return Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum;
    return {};
}
static PyObject *Natron_OrientationEnum_CppToPython_Natron_OrientationEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::OrientationEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX], castCppIn);

}

static void Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::PlaybackModeEnum *>(cppOut) =
        static_cast<::Natron::PlaybackModeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX]))
        return Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum;
    return {};
}
static PyObject *Natron_PlaybackModeEnum_CppToPython_Natron_PlaybackModeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::PlaybackModeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX], castCppIn);

}

static void Natron_SchedulingPolicyEnum_PythonToCpp_Natron_SchedulingPolicyEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::SchedulingPolicyEnum *>(cppOut) =
        static_cast<::Natron::SchedulingPolicyEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_SchedulingPolicyEnum_PythonToCpp_Natron_SchedulingPolicyEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX]))
        return Natron_SchedulingPolicyEnum_PythonToCpp_Natron_SchedulingPolicyEnum;
    return {};
}
static PyObject *Natron_SchedulingPolicyEnum_CppToPython_Natron_SchedulingPolicyEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::SchedulingPolicyEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX], castCppIn);

}

static void Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::DisplayChannelsEnum *>(cppOut) =
        static_cast<::Natron::DisplayChannelsEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX]))
        return Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum;
    return {};
}
static PyObject *Natron_DisplayChannelsEnum_CppToPython_Natron_DisplayChannelsEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::DisplayChannelsEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX], castCppIn);

}

static void Natron_ContextEnum_PythonToCpp_Natron_ContextEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ContextEnum *>(cppOut) =
        static_cast<::Natron::ContextEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ContextEnum_PythonToCpp_Natron_ContextEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX]))
        return Natron_ContextEnum_PythonToCpp_Natron_ContextEnum;
    return {};
}
static PyObject *Natron_ContextEnum_CppToPython_Natron_ContextEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ContextEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX], castCppIn);

}

static void Natron_RotoStrokeType_PythonToCpp_Natron_RotoStrokeType(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::RotoStrokeType *>(cppOut) =
        static_cast<::Natron::RotoStrokeType>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_RotoStrokeType_PythonToCpp_Natron_RotoStrokeType_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX]))
        return Natron_RotoStrokeType_PythonToCpp_Natron_RotoStrokeType;
    return {};
}
static PyObject *Natron_RotoStrokeType_CppToPython_Natron_RotoStrokeType(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::RotoStrokeType *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX], castCppIn);

}

static void Natron_RenderSafetyEnum_PythonToCpp_Natron_RenderSafetyEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::RenderSafetyEnum *>(cppOut) =
        static_cast<::Natron::RenderSafetyEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_RenderSafetyEnum_PythonToCpp_Natron_RenderSafetyEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX]))
        return Natron_RenderSafetyEnum_PythonToCpp_Natron_RenderSafetyEnum;
    return {};
}
static PyObject *Natron_RenderSafetyEnum_CppToPython_Natron_RenderSafetyEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::RenderSafetyEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX], castCppIn);

}

static void Natron_PenType_PythonToCpp_Natron_PenType(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::PenType *>(cppOut) =
        static_cast<::Natron::PenType>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_PenType_PythonToCpp_Natron_PenType_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX]))
        return Natron_PenType_PythonToCpp_Natron_PenType;
    return {};
}
static PyObject *Natron_PenType_CppToPython_Natron_PenType(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::PenType *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX], castCppIn);

}

static void Natron_PluginOpenGLRenderSupport_PythonToCpp_Natron_PluginOpenGLRenderSupport(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::PluginOpenGLRenderSupport *>(cppOut) =
        static_cast<::Natron::PluginOpenGLRenderSupport>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_PluginOpenGLRenderSupport_PythonToCpp_Natron_PluginOpenGLRenderSupport_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX]))
        return Natron_PluginOpenGLRenderSupport_PythonToCpp_Natron_PluginOpenGLRenderSupport;
    return {};
}
static PyObject *Natron_PluginOpenGLRenderSupport_CppToPython_Natron_PluginOpenGLRenderSupport(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::PluginOpenGLRenderSupport *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX], castCppIn);

}

static void Natron_CurveChangeReason_PythonToCpp_Natron_CurveChangeReason(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::CurveChangeReason *>(cppOut) =
        static_cast<::Natron::CurveChangeReason>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_CurveChangeReason_PythonToCpp_Natron_CurveChangeReason_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX]))
        return Natron_CurveChangeReason_PythonToCpp_Natron_CurveChangeReason;
    return {};
}
static PyObject *Natron_CurveChangeReason_CppToPython_Natron_CurveChangeReason(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::CurveChangeReason *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX], castCppIn);

}

static void Natron_OpenGLRequirementsTypeEnum_PythonToCpp_Natron_OpenGLRequirementsTypeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::OpenGLRequirementsTypeEnum *>(cppOut) =
        static_cast<::Natron::OpenGLRequirementsTypeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_OpenGLRequirementsTypeEnum_PythonToCpp_Natron_OpenGLRequirementsTypeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX]))
        return Natron_OpenGLRequirementsTypeEnum_PythonToCpp_Natron_OpenGLRequirementsTypeEnum;
    return {};
}
static PyObject *Natron_OpenGLRequirementsTypeEnum_CppToPython_Natron_OpenGLRequirementsTypeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::OpenGLRequirementsTypeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX], castCppIn);

}

static void Natron_DopeSheetItemType_PythonToCpp_Natron_DopeSheetItemType(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::DopeSheetItemType *>(cppOut) =
        static_cast<::Natron::DopeSheetItemType>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_DopeSheetItemType_PythonToCpp_Natron_DopeSheetItemType_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX]))
        return Natron_DopeSheetItemType_PythonToCpp_Natron_DopeSheetItemType;
    return {};
}
static PyObject *Natron_DopeSheetItemType_CppToPython_Natron_DopeSheetItemType(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::DopeSheetItemType *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX], castCppIn);

}

static void Natron_CreateNodeReason_PythonToCpp_Natron_CreateNodeReason(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::CreateNodeReason *>(cppOut) =
        static_cast<::Natron::CreateNodeReason>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_CreateNodeReason_PythonToCpp_Natron_CreateNodeReason_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX]))
        return Natron_CreateNodeReason_PythonToCpp_Natron_CreateNodeReason;
    return {};
}
static PyObject *Natron_CreateNodeReason_CppToPython_Natron_CreateNodeReason(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::CreateNodeReason *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX], castCppIn);

}

static void Natron_KnobClipBoardType_PythonToCpp_Natron_KnobClipBoardType(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::KnobClipBoardType *>(cppOut) =
        static_cast<::Natron::KnobClipBoardType>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_KnobClipBoardType_PythonToCpp_Natron_KnobClipBoardType_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX]))
        return Natron_KnobClipBoardType_PythonToCpp_Natron_KnobClipBoardType;
    return {};
}
static PyObject *Natron_KnobClipBoardType_CppToPython_Natron_KnobClipBoardType(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::KnobClipBoardType *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX], castCppIn);

}

static void Natron_ValueIsNormalizedEnum_PythonToCpp_Natron_ValueIsNormalizedEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ValueIsNormalizedEnum *>(cppOut) =
        static_cast<::Natron::ValueIsNormalizedEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ValueIsNormalizedEnum_PythonToCpp_Natron_ValueIsNormalizedEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX]))
        return Natron_ValueIsNormalizedEnum_PythonToCpp_Natron_ValueIsNormalizedEnum;
    return {};
}
static PyObject *Natron_ValueIsNormalizedEnum_CppToPython_Natron_ValueIsNormalizedEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ValueIsNormalizedEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX], castCppIn);

}

static void Natron_CursorEnum_PythonToCpp_Natron_CursorEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::CursorEnum *>(cppOut) =
        static_cast<::Natron::CursorEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_CursorEnum_PythonToCpp_Natron_CursorEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX]))
        return Natron_CursorEnum_PythonToCpp_Natron_CursorEnum;
    return {};
}
static PyObject *Natron_CursorEnum_CppToPython_Natron_CursorEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::CursorEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX], castCppIn);

}

static void Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::MergingFunctionEnum *>(cppOut) =
        static_cast<::Natron::MergingFunctionEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX]))
        return Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum;
    return {};
}
static PyObject *Natron_MergingFunctionEnum_CppToPython_Natron_MergingFunctionEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::MergingFunctionEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX], castCppIn);

}

static void Natron_Key_PythonToCpp_Natron_Key(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::Key *>(cppOut) =
        static_cast<::Natron::Key>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_Key_PythonToCpp_Natron_Key_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEY_IDX]))
        return Natron_Key_PythonToCpp_Natron_Key;
    return {};
}
static PyObject *Natron_Key_CppToPython_Natron_Key(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::Key *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX], castCppIn);

}

static void Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::KeyboardModifierEnum *>(cppOut) =
        static_cast<::Natron::KeyboardModifierEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX]))
        return Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum;
    return {};
}
static PyObject *Natron_KeyboardModifierEnum_CppToPython_Natron_KeyboardModifierEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::KeyboardModifierEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX], castCppIn);

}

static void Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::AppInstanceStatusEnum *>(cppOut) =
        static_cast<::Natron::AppInstanceStatusEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX]))
        return Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum;
    return {};
}
static PyObject *Natron_AppInstanceStatusEnum_CppToPython_Natron_AppInstanceStatusEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::AppInstanceStatusEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX], castCppIn);

}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *NatronEngineNatron_SignatureStrings[] = {
    "NatronEngine.Natron.getAmountFreePhysicalRAM()->std.size_t",
    "NatronEngine.Natron.isApplication32Bits()->bool",
    "NatronEngine.Natron.isFailureRetCode(code:NatronEngine.Natron.StatusEnum)->bool",
    nullptr}; // Sentinel

void init_NatronEngineNatron(PyObject *module)
{
    _Sbk_Natron_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Natron",
        "Natron",
        &Sbk_Natron_spec,
        0,
        0,
        0,
        0    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Type);
    InitSignatureStrings(pyType, NatronEngineNatron_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Type), Sbk_Natron_PropertyStrings);
    SbkNatronEngineTypes[SBK_NatronEngineNATRON_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_TypeF());


    // Initialization of enums.

    // Initialization of enum 'ScaleTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ScaleTypeEnum",
        "1:NatronEngine.Natron.ScaleTypeEnum",
        "Natron::ScaleTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eScaleTypeLinear", (long) Natron::ScaleTypeEnum::eScaleTypeLinear))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eScaleTypeLog", (long) Natron::ScaleTypeEnum::eScaleTypeLog))
        return;
    // Register converter for enum 'Natron::ScaleTypeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX],
            Natron_ScaleTypeEnum_CppToPython_Natron_ScaleTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ScaleTypeEnum_PythonToCpp_Natron_ScaleTypeEnum,
            is_Natron_ScaleTypeEnum_PythonToCpp_Natron_ScaleTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_SCALETYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ScaleTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "ScaleTypeEnum");
    }
    // End of 'ScaleTypeEnum' enum.

    // Initialization of enum 'TimelineStateEnum'.
    SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "TimelineStateEnum",
        "1:NatronEngine.Natron.TimelineStateEnum",
        "Natron::TimelineStateEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineStateIdle", (long) Natron::TimelineStateEnum::eTimelineStateIdle))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineStateDraggingCursor", (long) Natron::TimelineStateEnum::eTimelineStateDraggingCursor))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineStateDraggingBoundary", (long) Natron::TimelineStateEnum::eTimelineStateDraggingBoundary))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineStatePanning", (long) Natron::TimelineStateEnum::eTimelineStatePanning))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineStateSelectingZoomRange", (long) Natron::TimelineStateEnum::eTimelineStateSelectingZoomRange))
        return;
    // Register converter for enum 'Natron::TimelineStateEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX],
            Natron_TimelineStateEnum_CppToPython_Natron_TimelineStateEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_TimelineStateEnum_PythonToCpp_Natron_TimelineStateEnum,
            is_Natron_TimelineStateEnum_PythonToCpp_Natron_TimelineStateEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_TIMELINESTATEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::TimelineStateEnum");
        Shiboken::Conversions::registerConverterName(converter, "TimelineStateEnum");
    }
    // End of 'TimelineStateEnum' enum.

    // Initialization of enum 'TimelineChangeReasonEnum'.
    SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "TimelineChangeReasonEnum",
        "1:NatronEngine.Natron.TimelineChangeReasonEnum",
        "Natron::TimelineChangeReasonEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineChangeReasonUserSeek", (long) Natron::TimelineChangeReasonEnum::eTimelineChangeReasonUserSeek))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineChangeReasonPlaybackSeek", (long) Natron::TimelineChangeReasonEnum::eTimelineChangeReasonPlaybackSeek))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineChangeReasonCurveEditorSeek", (long) Natron::TimelineChangeReasonEnum::eTimelineChangeReasonCurveEditorSeek))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineChangeReasonDopeSheetEditorSeek", (long) Natron::TimelineChangeReasonEnum::eTimelineChangeReasonDopeSheetEditorSeek))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eTimelineChangeReasonOtherSeek", (long) Natron::TimelineChangeReasonEnum::eTimelineChangeReasonOtherSeek))
        return;
    // Register converter for enum 'Natron::TimelineChangeReasonEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX],
            Natron_TimelineChangeReasonEnum_CppToPython_Natron_TimelineChangeReasonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_TimelineChangeReasonEnum_PythonToCpp_Natron_TimelineChangeReasonEnum,
            is_Natron_TimelineChangeReasonEnum_PythonToCpp_Natron_TimelineChangeReasonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_TIMELINECHANGEREASONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::TimelineChangeReasonEnum");
        Shiboken::Conversions::registerConverterName(converter, "TimelineChangeReasonEnum");
    }
    // End of 'TimelineChangeReasonEnum' enum.

    // Initialization of enum 'StatusEnum'.
    SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "StatusEnum",
        "1:NatronEngine.Natron.StatusEnum",
        "Natron::StatusEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusOK", (long) Natron::StatusEnum::eStatusOK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusFailed", (long) Natron::StatusEnum::eStatusFailed))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusInputDisconnected", (long) Natron::StatusEnum::eStatusInputDisconnected))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusAborted", (long) Natron::StatusEnum::eStatusAborted))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusOutOfMemory", (long) Natron::StatusEnum::eStatusOutOfMemory))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusReplyDefault", (long) Natron::StatusEnum::eStatusReplyDefault))
        return;
    // Register converter for enum 'Natron::StatusEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
            Natron_StatusEnum_CppToPython_Natron_StatusEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StatusEnum_PythonToCpp_Natron_StatusEnum,
            is_Natron_StatusEnum_PythonToCpp_Natron_StatusEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StatusEnum");
        Shiboken::Conversions::registerConverterName(converter, "StatusEnum");
    }
    // End of 'StatusEnum' enum.

    // Initialization of enum 'StandardButtonEnum'.
    SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX] = PySide::QFlags::create("1:NatronEngine.Natron.StandardButtons", SbkNatronEngine_Natron_StandardButtonEnum_number_slots);
    SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "StandardButtonEnum",
        "1:NatronEngine.Natron.StandardButtonEnum",
        "Natron::StandardButtonEnum",
        SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX]);
    if (!SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonNoButton", (long) Natron::StandardButtonEnum::eStandardButtonNoButton))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonEscape", (long) Natron::StandardButtonEnum::eStandardButtonEscape))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonOk", (long) Natron::StandardButtonEnum::eStandardButtonOk))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonSave", (long) Natron::StandardButtonEnum::eStandardButtonSave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonSaveAll", (long) Natron::StandardButtonEnum::eStandardButtonSaveAll))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonOpen", (long) Natron::StandardButtonEnum::eStandardButtonOpen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonYes", (long) Natron::StandardButtonEnum::eStandardButtonYes))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonYesToAll", (long) Natron::StandardButtonEnum::eStandardButtonYesToAll))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonNo", (long) Natron::StandardButtonEnum::eStandardButtonNo))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonNoToAll", (long) Natron::StandardButtonEnum::eStandardButtonNoToAll))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonAbort", (long) Natron::StandardButtonEnum::eStandardButtonAbort))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonRetry", (long) Natron::StandardButtonEnum::eStandardButtonRetry))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonIgnore", (long) Natron::StandardButtonEnum::eStandardButtonIgnore))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonClose", (long) Natron::StandardButtonEnum::eStandardButtonClose))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonCancel", (long) Natron::StandardButtonEnum::eStandardButtonCancel))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonDiscard", (long) Natron::StandardButtonEnum::eStandardButtonDiscard))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonHelp", (long) Natron::StandardButtonEnum::eStandardButtonHelp))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonApply", (long) Natron::StandardButtonEnum::eStandardButtonApply))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonReset", (long) Natron::StandardButtonEnum::eStandardButtonReset))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonRestoreDefaults", (long) Natron::StandardButtonEnum::eStandardButtonRestoreDefaults))
        return;
    // Register converter for enum 'Natron::StandardButtonEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
            Natron_StandardButtonEnum_CppToPython_Natron_StandardButtonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum,
            is_Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StandardButtonEnum");
        Shiboken::Conversions::registerConverterName(converter, "StandardButtonEnum");
    }
    // Register converter for flag 'QFlags<Natron::StandardButtonEnum>'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX],
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
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StandardButtons");
        Shiboken::Conversions::registerConverterName(converter, "StandardButtons");
    }
    // End of 'StandardButtonEnum' enum/flags.

    // Initialization of enum 'MessageTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "MessageTypeEnum",
        "1:NatronEngine.Natron.MessageTypeEnum",
        "Natron::MessageTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eMessageTypeInfo", (long) Natron::MessageTypeEnum::eMessageTypeInfo))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eMessageTypeError", (long) Natron::MessageTypeEnum::eMessageTypeError))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eMessageTypeWarning", (long) Natron::MessageTypeEnum::eMessageTypeWarning))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eMessageTypeQuestion", (long) Natron::MessageTypeEnum::eMessageTypeQuestion))
        return;
    // Register converter for enum 'Natron::MessageTypeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX],
            Natron_MessageTypeEnum_CppToPython_Natron_MessageTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_MessageTypeEnum_PythonToCpp_Natron_MessageTypeEnum,
            is_Natron_MessageTypeEnum_PythonToCpp_Natron_MessageTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_MESSAGETYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::MessageTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "MessageTypeEnum");
    }
    // End of 'MessageTypeEnum' enum.

    // Initialization of enum 'KeyframeTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "KeyframeTypeEnum",
        "1:NatronEngine.Natron.KeyframeTypeEnum",
        "Natron::KeyframeTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeConstant", (long) Natron::KeyframeTypeEnum::eKeyframeTypeConstant))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeLinear", (long) Natron::KeyframeTypeEnum::eKeyframeTypeLinear))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeSmooth", (long) Natron::KeyframeTypeEnum::eKeyframeTypeSmooth))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeCatmullRom", (long) Natron::KeyframeTypeEnum::eKeyframeTypeCatmullRom))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeCubic", (long) Natron::KeyframeTypeEnum::eKeyframeTypeCubic))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeHorizontal", (long) Natron::KeyframeTypeEnum::eKeyframeTypeHorizontal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeFree", (long) Natron::KeyframeTypeEnum::eKeyframeTypeFree))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeBroken", (long) Natron::KeyframeTypeEnum::eKeyframeTypeBroken))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeNone", (long) Natron::KeyframeTypeEnum::eKeyframeTypeNone))
        return;
    // Register converter for enum 'Natron::KeyframeTypeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
            Natron_KeyframeTypeEnum_CppToPython_Natron_KeyframeTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum,
            is_Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KeyframeTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "KeyframeTypeEnum");
    }
    // End of 'KeyframeTypeEnum' enum.

    // Initialization of enum 'PixmapEnum'.
    SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "PixmapEnum",
        "1:NatronEngine.Natron.PixmapEnum",
        "Natron::PixmapEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PREVIOUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PREVIOUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_FIRST_FRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_FIRST_FRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_NEXT", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_NEXT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_LAST_FRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_LAST_FRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_NEXT_INCR", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_NEXT_INCR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_NEXT_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_NEXT_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PREVIOUS_INCR", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PREVIOUS_INCR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PREVIOUS_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PREVIOUS_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_REWIND_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_REWIND_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_REWIND_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_REWIND_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PLAY_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PLAY_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PLAY_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PLAY_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_STOP_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_STOP_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_STOP_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_STOP_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PAUSE_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PAUSE_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PAUSE_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PAUSE_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_LOOP_MODE", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_LOOP_MODE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_BOUNCE", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_BOUNCE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PLAY_ONCE", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PLAY_ONCE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_TIMELINE_IN", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_TIMELINE_IN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_TIMELINE_OUT", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_TIMELINE_OUT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MAXIMIZE_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_MAXIMIZE_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MINIMIZE_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_MINIMIZE_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLOSE_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLOSE_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_HELP_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_HELP_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLOSE_PANEL", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLOSE_PANEL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_HIDE_UNMODIFIED", (long) Natron::PixmapEnum::NATRON_PIXMAP_HIDE_UNMODIFIED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNHIDE_UNMODIFIED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNHIDE_UNMODIFIED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_GROUPBOX_FOLDED", (long) Natron::PixmapEnum::NATRON_PIXMAP_GROUPBOX_FOLDED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_GROUPBOX_UNFOLDED", (long) Natron::PixmapEnum::NATRON_PIXMAP_GROUPBOX_UNFOLDED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNDO", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNDO))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REDO", (long) Natron::PixmapEnum::NATRON_PIXMAP_REDO))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNDO_GRAYSCALE", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNDO_GRAYSCALE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REDO_GRAYSCALE", (long) Natron::PixmapEnum::NATRON_PIXMAP_REDO_GRAYSCALE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CENTER", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CENTER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_FULL_FRAME_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_FULL_FRAME_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_REFRESH", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_REFRESH))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ROI_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ROI_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ROI_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ROI_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_RENDER_SCALE", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_RENDER_SCALE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OPEN_FILE", (long) Natron::PixmapEnum::NATRON_PIXMAP_OPEN_FILE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COLORWHEEL", (long) Natron::PixmapEnum::NATRON_PIXMAP_COLORWHEEL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OVERLAY", (long) Natron::PixmapEnum::NATRON_PIXMAP_OVERLAY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTO_MERGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTO_MERGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COLOR_PICKER", (long) Natron::PixmapEnum::NATRON_PIXMAP_COLOR_PICKER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_IO_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_IO_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_3D_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_3D_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CHANNEL_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_CHANNEL_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COLOR_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_COLOR_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRANSFORM_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRANSFORM_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_DEEP_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_DEEP_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FILTER_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_FILTER_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MULTIVIEW_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_MULTIVIEW_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TOOLSETS_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_TOOLSETS_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MISC_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_MISC_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OPEN_EFFECTS_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_OPEN_EFFECTS_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TIME_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_TIME_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PAINT_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_PAINT_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_KEYER_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_KEYER_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OTHER_PLUGINS", (long) Natron::PixmapEnum::NATRON_PIXMAP_OTHER_PLUGINS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_READ_IMAGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_READ_IMAGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_WRITE_IMAGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_WRITE_IMAGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COMBOBOX", (long) Natron::PixmapEnum::NATRON_PIXMAP_COMBOBOX))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COMBOBOX_PRESSED", (long) Natron::PixmapEnum::NATRON_PIXMAP_COMBOBOX_PRESSED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_KEYFRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_KEYFRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_KEYFRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_KEYFRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INVERTED", (long) Natron::PixmapEnum::NATRON_PIXMAP_INVERTED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNINVERTED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNINVERTED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_VISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNVISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNVISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LOCKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_LOCKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNLOCKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNLOCKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LAYER", (long) Natron::PixmapEnum::NATRON_PIXMAP_LAYER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BEZIER", (long) Natron::PixmapEnum::NATRON_PIXMAP_BEZIER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PENCIL", (long) Natron::PixmapEnum::NATRON_PIXMAP_PENCIL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CURVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_CURVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BEZIER_32", (long) Natron::PixmapEnum::NATRON_PIXMAP_BEZIER_32))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ELLIPSE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ELLIPSE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RECTANGLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_RECTANGLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CUSP_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_CUSP_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SMOOTH_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_SMOOTH_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_FEATHER", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_FEATHER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OPEN_CLOSE_CURVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_OPEN_CLOSE_CURVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_ALL", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_ALL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_FEATHER", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_FEATHER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_CURVES", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_CURVES))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_AUTO_KEYING_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_AUTO_KEYING_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_AUTO_KEYING_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_AUTO_KEYING_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_STICKY_SELECTION_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_STICKY_SELECTION_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_STICKY_SELECTION_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_STICKY_SELECTION_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_LINK_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_LINK_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_LINK_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_LINK_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_VISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_VISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_UNVISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_UNVISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RIPPLE_EDIT_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RIPPLE_EDIT_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RIPPLE_EDIT_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RIPPLE_EDIT_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BLUR", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BLUR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BURN", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BURN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_CLONE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_CLONE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_DODGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_DODGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_ERASER", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_ERASER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_REVEAL", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_REVEAL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_SHARPEN", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_SHARPEN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_SMEAR", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_SMEAR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_SOLID", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_SOLID))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BOLD_CHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_BOLD_CHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BOLD_UNCHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_BOLD_UNCHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ITALIC_CHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ITALIC_CHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ITALIC_UNCHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ITALIC_UNCHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLEAR_ALL_ANIMATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLEAR_ALL_ANIMATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UPDATE_VIEWER_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UPDATE_VIEWER_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UPDATE_VIEWER_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UPDATE_VIEWER_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_TRACK", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_TRACK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SHOW_TRACK_ERROR", (long) Natron::PixmapEnum::NATRON_PIXMAP_SHOW_TRACK_ERROR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_HIDE_TRACK_ERROR", (long) Natron::PixmapEnum::NATRON_PIXMAP_HIDE_TRACK_ERROR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESET_TRACK_OFFSET", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESET_TRACK_OFFSET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESET_USER_KEYS", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESET_USER_KEYS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK", (long) Natron::PixmapEnum::NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_BACKWARD_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_BACKWARD_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_BACKWARD_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_BACKWARD_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_FORWARD_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_FORWARD_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_FORWARD_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_FORWARD_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_PREVIOUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_PREVIOUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_NEXT", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_NEXT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_RANGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_RANGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_ALL_KEYS", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_ALL_KEYS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_CURRENT_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_CURRENT_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_NEXT_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_NEXT_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PREV_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_PREV_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ENTER_GROUP", (long) Natron::PixmapEnum::NATRON_PIXMAP_ENTER_GROUP))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SETTINGS", (long) Natron::PixmapEnum::NATRON_PIXMAP_SETTINGS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FREEZE_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FREEZE_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FREEZE_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FREEZE_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ICON", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ICON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAMMA_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAMMA_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAMMA_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAMMA_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAIN_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAIN_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAIN_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAIN_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_ATOP", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_ATOP))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_AVERAGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_AVERAGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COLOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COLOR_BURN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR_BURN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COLOR_DODGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR_DODGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_CONJOINT_OVER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_CONJOINT_OVER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COPY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COPY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_DIFFERENCE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_DIFFERENCE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_DISJOINT_OVER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_DISJOINT_OVER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_DIVIDE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_DIVIDE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_EXCLUSION", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_EXCLUSION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_FREEZE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_FREEZE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_FROM", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_FROM))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GEOMETRIC", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GEOMETRIC))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GRAIN_EXTRACT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GRAIN_EXTRACT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GRAIN_MERGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GRAIN_MERGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_HARD_LIGHT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_HARD_LIGHT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_HUE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_HUE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_HYPOT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_HYPOT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_IN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_IN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_LUMINOSITY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_LUMINOSITY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MASK", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MASK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MATTE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MATTE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MAX", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MAX))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MIN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MIN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MINUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MINUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MULTIPLY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MULTIPLY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_OUT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_OUT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_OVER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_OVER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_OVERLAY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_OVERLAY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_PINLIGHT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_PINLIGHT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_PLUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_PLUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_REFLECT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_REFLECT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_SATURATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_SATURATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_SCREEN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_SCREEN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_SOFT_LIGHT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_SOFT_LIGHT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_STENCIL", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_STENCIL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_UNDER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_UNDER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_XOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_XOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTO_NODE_ICON", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTO_NODE_ICON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LINK_CURSOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_LINK_CURSOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LINK_MULT_CURSOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_LINK_MULT_CURSOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_APP_ICON", (long) Natron::PixmapEnum::NATRON_PIXMAP_APP_ICON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_LINEAR", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_LINEAR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CONSTANT", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CONSTANT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_BREAK", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_BREAK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_C", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_C))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_H", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_H))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_R", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_Z", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_Z))
        return;
    // Register converter for enum 'Natron::PixmapEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
            Natron_PixmapEnum_CppToPython_Natron_PixmapEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum,
            is_Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PixmapEnum");
        Shiboken::Conversions::registerConverterName(converter, "PixmapEnum");
    }
    // End of 'PixmapEnum' enum.

    // Initialization of enum 'ValueChangedReasonEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ValueChangedReasonEnum",
        "1:NatronEngine.Natron.ValueChangedReasonEnum",
        "Natron::ValueChangedReasonEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonUserEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonUserEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonPluginEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonPluginEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonNatronGuiEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonNatronGuiEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonNatronInternalEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonNatronInternalEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonTimeChanged", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonTimeChanged))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonSlaveRefresh", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonSlaveRefresh))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonRestoreDefault", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonRestoreDefault))
        return;
    // Register converter for enum 'Natron::ValueChangedReasonEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
            Natron_ValueChangedReasonEnum_CppToPython_Natron_ValueChangedReasonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum,
            is_Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ValueChangedReasonEnum");
        Shiboken::Conversions::registerConverterName(converter, "ValueChangedReasonEnum");
    }
    // End of 'ValueChangedReasonEnum' enum.

    // Initialization of enum 'AnimationLevelEnum'.
    SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "AnimationLevelEnum",
        "1:NatronEngine.Natron.AnimationLevelEnum",
        "Natron::AnimationLevelEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
        Sbk_Natron_TypeF(), "eAnimationLevelNone", (long) Natron::AnimationLevelEnum::eAnimationLevelNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
        Sbk_Natron_TypeF(), "eAnimationLevelInterpolatedValue", (long) Natron::AnimationLevelEnum::eAnimationLevelInterpolatedValue))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
        Sbk_Natron_TypeF(), "eAnimationLevelOnKeyframe", (long) Natron::AnimationLevelEnum::eAnimationLevelOnKeyframe))
        return;
    // Register converter for enum 'Natron::AnimationLevelEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
            Natron_AnimationLevelEnum_CppToPython_Natron_AnimationLevelEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum,
            is_Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::AnimationLevelEnum");
        Shiboken::Conversions::registerConverterName(converter, "AnimationLevelEnum");
    }
    // End of 'AnimationLevelEnum' enum.

    // Initialization of enum 'ImagePlaneDescEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ImagePlaneDescEnum",
        "1:NatronEngine.Natron.ImagePlaneDescEnum",
        "Natron::ImagePlaneDescEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX],
        Sbk_Natron_TypeF(), "eImageComponentNone", (long) Natron::ImagePlaneDescEnum::eImageComponentNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX],
        Sbk_Natron_TypeF(), "eImageComponentAlpha", (long) Natron::ImagePlaneDescEnum::eImageComponentAlpha))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX],
        Sbk_Natron_TypeF(), "eImageComponentRGB", (long) Natron::ImagePlaneDescEnum::eImageComponentRGB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX],
        Sbk_Natron_TypeF(), "eImageComponentRGBA", (long) Natron::ImagePlaneDescEnum::eImageComponentRGBA))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX],
        Sbk_Natron_TypeF(), "eImageComponentXY", (long) Natron::ImagePlaneDescEnum::eImageComponentXY))
        return;
    // Register converter for enum 'Natron::ImagePlaneDescEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX],
            Natron_ImagePlaneDescEnum_CppToPython_Natron_ImagePlaneDescEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImagePlaneDescEnum_PythonToCpp_Natron_ImagePlaneDescEnum,
            is_Natron_ImagePlaneDescEnum_PythonToCpp_Natron_ImagePlaneDescEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPLANEDESCENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImagePlaneDescEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImagePlaneDescEnum");
    }
    // End of 'ImagePlaneDescEnum' enum.

    // Initialization of enum 'ImagePremultiplicationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ImagePremultiplicationEnum",
        "1:NatronEngine.Natron.ImagePremultiplicationEnum",
        "Natron::ImagePremultiplicationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eImagePremultiplicationOpaque", (long) Natron::ImagePremultiplicationEnum::eImagePremultiplicationOpaque))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eImagePremultiplicationPremultiplied", (long) Natron::ImagePremultiplicationEnum::eImagePremultiplicationPremultiplied))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eImagePremultiplicationUnPremultiplied", (long) Natron::ImagePremultiplicationEnum::eImagePremultiplicationUnPremultiplied))
        return;
    // Register converter for enum 'Natron::ImagePremultiplicationEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
            Natron_ImagePremultiplicationEnum_CppToPython_Natron_ImagePremultiplicationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum,
            is_Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImagePremultiplicationEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImagePremultiplicationEnum");
    }
    // End of 'ImagePremultiplicationEnum' enum.

    // Initialization of enum 'ImageFieldingOrderEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ImageFieldingOrderEnum",
        "1:NatronEngine.Natron.ImageFieldingOrderEnum",
        "Natron::ImageFieldingOrderEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX],
        Sbk_Natron_TypeF(), "eImageFieldingOrderNone", (long) Natron::ImageFieldingOrderEnum::eImageFieldingOrderNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX],
        Sbk_Natron_TypeF(), "eImageFieldingOrderLower", (long) Natron::ImageFieldingOrderEnum::eImageFieldingOrderLower))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX],
        Sbk_Natron_TypeF(), "eImageFieldingOrderUpper", (long) Natron::ImageFieldingOrderEnum::eImageFieldingOrderUpper))
        return;
    // Register converter for enum 'Natron::ImageFieldingOrderEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX],
            Natron_ImageFieldingOrderEnum_CppToPython_Natron_ImageFieldingOrderEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImageFieldingOrderEnum_PythonToCpp_Natron_ImageFieldingOrderEnum,
            is_Natron_ImageFieldingOrderEnum_PythonToCpp_Natron_ImageFieldingOrderEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEFIELDINGORDERENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImageFieldingOrderEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImageFieldingOrderEnum");
    }
    // End of 'ImageFieldingOrderEnum' enum.

    // Initialization of enum 'ViewerCompositingOperatorEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ViewerCompositingOperatorEnum",
        "1:NatronEngine.Natron.ViewerCompositingOperatorEnum",
        "Natron::ViewerCompositingOperatorEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorNone", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeUnder", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeUnder))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeOver", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeMinus", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeMinus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeOnionSkin", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeOnionSkin))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackUnder", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackUnder))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackOver", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackMinus", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackMinus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackOnionSkin", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackOnionSkin))
        return;
    // Register converter for enum 'Natron::ViewerCompositingOperatorEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
            Natron_ViewerCompositingOperatorEnum_CppToPython_Natron_ViewerCompositingOperatorEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum,
            is_Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ViewerCompositingOperatorEnum");
        Shiboken::Conversions::registerConverterName(converter, "ViewerCompositingOperatorEnum");
    }
    // End of 'ViewerCompositingOperatorEnum' enum.

    // Initialization of enum 'ViewerColorSpaceEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ViewerColorSpaceEnum",
        "1:NatronEngine.Natron.ViewerColorSpaceEnum",
        "Natron::ViewerColorSpaceEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerColorSpaceSRGB", (long) Natron::ViewerColorSpaceEnum::eViewerColorSpaceSRGB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerColorSpaceLinear", (long) Natron::ViewerColorSpaceEnum::eViewerColorSpaceLinear))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerColorSpaceRec709", (long) Natron::ViewerColorSpaceEnum::eViewerColorSpaceRec709))
        return;
    // Register converter for enum 'Natron::ViewerColorSpaceEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
            Natron_ViewerColorSpaceEnum_CppToPython_Natron_ViewerColorSpaceEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum,
            is_Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ViewerColorSpaceEnum");
        Shiboken::Conversions::registerConverterName(converter, "ViewerColorSpaceEnum");
    }
    // End of 'ViewerColorSpaceEnum' enum.

    // Initialization of enum 'ImageBitDepthEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ImageBitDepthEnum",
        "1:NatronEngine.Natron.ImageBitDepthEnum",
        "Natron::ImageBitDepthEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthNone", (long) Natron::ImageBitDepthEnum::eImageBitDepthNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthByte", (long) Natron::ImageBitDepthEnum::eImageBitDepthByte))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthShort", (long) Natron::ImageBitDepthEnum::eImageBitDepthShort))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthHalf", (long) Natron::ImageBitDepthEnum::eImageBitDepthHalf))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthFloat", (long) Natron::ImageBitDepthEnum::eImageBitDepthFloat))
        return;
    // Register converter for enum 'Natron::ImageBitDepthEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
            Natron_ImageBitDepthEnum_CppToPython_Natron_ImageBitDepthEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum,
            is_Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImageBitDepthEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImageBitDepthEnum");
    }
    // End of 'ImageBitDepthEnum' enum.

    // Initialization of enum 'SequentialPreferenceEnum'.
    SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "SequentialPreferenceEnum",
        "1:NatronEngine.Natron.SequentialPreferenceEnum",
        "Natron::SequentialPreferenceEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX],
        Sbk_Natron_TypeF(), "eSequentialPreferenceNotSequential", (long) Natron::SequentialPreferenceEnum::eSequentialPreferenceNotSequential))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX],
        Sbk_Natron_TypeF(), "eSequentialPreferenceOnlySequential", (long) Natron::SequentialPreferenceEnum::eSequentialPreferenceOnlySequential))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX],
        Sbk_Natron_TypeF(), "eSequentialPreferencePreferSequential", (long) Natron::SequentialPreferenceEnum::eSequentialPreferencePreferSequential))
        return;
    // Register converter for enum 'Natron::SequentialPreferenceEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX],
            Natron_SequentialPreferenceEnum_CppToPython_Natron_SequentialPreferenceEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_SequentialPreferenceEnum_PythonToCpp_Natron_SequentialPreferenceEnum,
            is_Natron_SequentialPreferenceEnum_PythonToCpp_Natron_SequentialPreferenceEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_SEQUENTIALPREFERENCEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::SequentialPreferenceEnum");
        Shiboken::Conversions::registerConverterName(converter, "SequentialPreferenceEnum");
    }
    // End of 'SequentialPreferenceEnum' enum.

    // Initialization of enum 'StorageModeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "StorageModeEnum",
        "1:NatronEngine.Natron.StorageModeEnum",
        "Natron::StorageModeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX],
        Sbk_Natron_TypeF(), "eStorageModeNone", (long) Natron::StorageModeEnum::eStorageModeNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX],
        Sbk_Natron_TypeF(), "eStorageModeRAM", (long) Natron::StorageModeEnum::eStorageModeRAM))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX],
        Sbk_Natron_TypeF(), "eStorageModeDisk", (long) Natron::StorageModeEnum::eStorageModeDisk))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX],
        Sbk_Natron_TypeF(), "eStorageModeGLTex", (long) Natron::StorageModeEnum::eStorageModeGLTex))
        return;
    // Register converter for enum 'Natron::StorageModeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX],
            Natron_StorageModeEnum_CppToPython_Natron_StorageModeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StorageModeEnum_PythonToCpp_Natron_StorageModeEnum,
            is_Natron_StorageModeEnum_PythonToCpp_Natron_StorageModeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STORAGEMODEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StorageModeEnum");
        Shiboken::Conversions::registerConverterName(converter, "StorageModeEnum");
    }
    // End of 'StorageModeEnum' enum.

    // Initialization of enum 'OrientationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "OrientationEnum",
        "1:NatronEngine.Natron.OrientationEnum",
        "Natron::OrientationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eOrientationHorizontal", (long) Natron::OrientationEnum::eOrientationHorizontal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eOrientationVertical", (long) Natron::OrientationEnum::eOrientationVertical))
        return;
    // Register converter for enum 'Natron::OrientationEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
            Natron_OrientationEnum_CppToPython_Natron_OrientationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum,
            is_Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::OrientationEnum");
        Shiboken::Conversions::registerConverterName(converter, "OrientationEnum");
    }
    // End of 'OrientationEnum' enum.

    // Initialization of enum 'PlaybackModeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "PlaybackModeEnum",
        "1:NatronEngine.Natron.PlaybackModeEnum",
        "Natron::PlaybackModeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
        Sbk_Natron_TypeF(), "ePlaybackModeLoop", (long) Natron::PlaybackModeEnum::ePlaybackModeLoop))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
        Sbk_Natron_TypeF(), "ePlaybackModeBounce", (long) Natron::PlaybackModeEnum::ePlaybackModeBounce))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
        Sbk_Natron_TypeF(), "ePlaybackModeOnce", (long) Natron::PlaybackModeEnum::ePlaybackModeOnce))
        return;
    // Register converter for enum 'Natron::PlaybackModeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
            Natron_PlaybackModeEnum_CppToPython_Natron_PlaybackModeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum,
            is_Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PlaybackModeEnum");
        Shiboken::Conversions::registerConverterName(converter, "PlaybackModeEnum");
    }
    // End of 'PlaybackModeEnum' enum.

    // Initialization of enum 'SchedulingPolicyEnum'.
    SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "SchedulingPolicyEnum",
        "1:NatronEngine.Natron.SchedulingPolicyEnum",
        "Natron::SchedulingPolicyEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX],
        Sbk_Natron_TypeF(), "eSchedulingPolicyFFA", (long) Natron::SchedulingPolicyEnum::eSchedulingPolicyFFA))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX],
        Sbk_Natron_TypeF(), "eSchedulingPolicyOrdered", (long) Natron::SchedulingPolicyEnum::eSchedulingPolicyOrdered))
        return;
    // Register converter for enum 'Natron::SchedulingPolicyEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX],
            Natron_SchedulingPolicyEnum_CppToPython_Natron_SchedulingPolicyEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_SchedulingPolicyEnum_PythonToCpp_Natron_SchedulingPolicyEnum,
            is_Natron_SchedulingPolicyEnum_PythonToCpp_Natron_SchedulingPolicyEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_SCHEDULINGPOLICYENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::SchedulingPolicyEnum");
        Shiboken::Conversions::registerConverterName(converter, "SchedulingPolicyEnum");
    }
    // End of 'SchedulingPolicyEnum' enum.

    // Initialization of enum 'DisplayChannelsEnum'.
    SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "DisplayChannelsEnum",
        "1:NatronEngine.Natron.DisplayChannelsEnum",
        "Natron::DisplayChannelsEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsRGB", (long) Natron::DisplayChannelsEnum::eDisplayChannelsRGB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsR", (long) Natron::DisplayChannelsEnum::eDisplayChannelsR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsG", (long) Natron::DisplayChannelsEnum::eDisplayChannelsG))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsB", (long) Natron::DisplayChannelsEnum::eDisplayChannelsB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsA", (long) Natron::DisplayChannelsEnum::eDisplayChannelsA))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsY", (long) Natron::DisplayChannelsEnum::eDisplayChannelsY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsMatte", (long) Natron::DisplayChannelsEnum::eDisplayChannelsMatte))
        return;
    // Register converter for enum 'Natron::DisplayChannelsEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
            Natron_DisplayChannelsEnum_CppToPython_Natron_DisplayChannelsEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum,
            is_Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::DisplayChannelsEnum");
        Shiboken::Conversions::registerConverterName(converter, "DisplayChannelsEnum");
    }
    // End of 'DisplayChannelsEnum' enum.

    // Initialization of enum 'ContextEnum'.
    SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ContextEnum",
        "1:NatronEngine.Natron.ContextEnum",
        "Natron::ContextEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextNone", (long) Natron::ContextEnum::eContextNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextGenerator", (long) Natron::ContextEnum::eContextGenerator))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextFilter", (long) Natron::ContextEnum::eContextFilter))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextTransition", (long) Natron::ContextEnum::eContextTransition))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextPaint", (long) Natron::ContextEnum::eContextPaint))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextGeneral", (long) Natron::ContextEnum::eContextGeneral))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextRetimer", (long) Natron::ContextEnum::eContextRetimer))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextReader", (long) Natron::ContextEnum::eContextReader))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextWriter", (long) Natron::ContextEnum::eContextWriter))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
        Sbk_Natron_TypeF(), "eContextTracker", (long) Natron::ContextEnum::eContextTracker))
        return;
    // Register converter for enum 'Natron::ContextEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX],
            Natron_ContextEnum_CppToPython_Natron_ContextEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ContextEnum_PythonToCpp_Natron_ContextEnum,
            is_Natron_ContextEnum_PythonToCpp_Natron_ContextEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_CONTEXTENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ContextEnum");
        Shiboken::Conversions::registerConverterName(converter, "ContextEnum");
    }
    // End of 'ContextEnum' enum.

    // Initialization of enum 'RotoStrokeType'.
    SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "RotoStrokeType",
        "1:NatronEngine.Natron.RotoStrokeType",
        "Natron::RotoStrokeType");
    if (!SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeSolid", (long) Natron::RotoStrokeType::eRotoStrokeTypeSolid))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeEraser", (long) Natron::RotoStrokeType::eRotoStrokeTypeEraser))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeClone", (long) Natron::RotoStrokeType::eRotoStrokeTypeClone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeReveal", (long) Natron::RotoStrokeType::eRotoStrokeTypeReveal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeBlur", (long) Natron::RotoStrokeType::eRotoStrokeTypeBlur))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeSharpen", (long) Natron::RotoStrokeType::eRotoStrokeTypeSharpen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeSmear", (long) Natron::RotoStrokeType::eRotoStrokeTypeSmear))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeDodge", (long) Natron::RotoStrokeType::eRotoStrokeTypeDodge))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
        Sbk_Natron_TypeF(), "eRotoStrokeTypeBurn", (long) Natron::RotoStrokeType::eRotoStrokeTypeBurn))
        return;
    // Register converter for enum 'Natron::RotoStrokeType'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX],
            Natron_RotoStrokeType_CppToPython_Natron_RotoStrokeType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_RotoStrokeType_PythonToCpp_Natron_RotoStrokeType,
            is_Natron_RotoStrokeType_PythonToCpp_Natron_RotoStrokeType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::RotoStrokeType");
        Shiboken::Conversions::registerConverterName(converter, "RotoStrokeType");
    }
    // End of 'RotoStrokeType' enum.

    // Initialization of enum 'RenderSafetyEnum'.
    SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "RenderSafetyEnum",
        "1:NatronEngine.Natron.RenderSafetyEnum",
        "Natron::RenderSafetyEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX],
        Sbk_Natron_TypeF(), "eRenderSafetyUnsafe", (long) Natron::RenderSafetyEnum::eRenderSafetyUnsafe))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX],
        Sbk_Natron_TypeF(), "eRenderSafetyInstanceSafe", (long) Natron::RenderSafetyEnum::eRenderSafetyInstanceSafe))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX],
        Sbk_Natron_TypeF(), "eRenderSafetyFullySafe", (long) Natron::RenderSafetyEnum::eRenderSafetyFullySafe))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX],
        Sbk_Natron_TypeF(), "eRenderSafetyFullySafeFrame", (long) Natron::RenderSafetyEnum::eRenderSafetyFullySafeFrame))
        return;
    // Register converter for enum 'Natron::RenderSafetyEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX],
            Natron_RenderSafetyEnum_CppToPython_Natron_RenderSafetyEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_RenderSafetyEnum_PythonToCpp_Natron_RenderSafetyEnum,
            is_Natron_RenderSafetyEnum_PythonToCpp_Natron_RenderSafetyEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_RENDERSAFETYENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::RenderSafetyEnum");
        Shiboken::Conversions::registerConverterName(converter, "RenderSafetyEnum");
    }
    // End of 'RenderSafetyEnum' enum.

    // Initialization of enum 'PenType'.
    SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "PenType",
        "1:NatronEngine.Natron.PenType",
        "Natron::PenType");
    if (!SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX],
        Sbk_Natron_TypeF(), "ePenTypeLMB", (long) Natron::PenType::ePenTypeLMB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX],
        Sbk_Natron_TypeF(), "ePenTypeMMB", (long) Natron::PenType::ePenTypeMMB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX],
        Sbk_Natron_TypeF(), "ePenTypeRMB", (long) Natron::PenType::ePenTypeRMB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX],
        Sbk_Natron_TypeF(), "ePenTypePen", (long) Natron::PenType::ePenTypePen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX],
        Sbk_Natron_TypeF(), "ePenTypeCursor", (long) Natron::PenType::ePenTypeCursor))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX],
        Sbk_Natron_TypeF(), "ePenTypeEraser", (long) Natron::PenType::ePenTypeEraser))
        return;
    // Register converter for enum 'Natron::PenType'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX],
            Natron_PenType_CppToPython_Natron_PenType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PenType_PythonToCpp_Natron_PenType,
            is_Natron_PenType_PythonToCpp_Natron_PenType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PenType");
        Shiboken::Conversions::registerConverterName(converter, "PenType");
    }
    // End of 'PenType' enum.

    // Initialization of enum 'PluginOpenGLRenderSupport'.
    SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "PluginOpenGLRenderSupport",
        "1:NatronEngine.Natron.PluginOpenGLRenderSupport",
        "Natron::PluginOpenGLRenderSupport");
    if (!SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX],
        Sbk_Natron_TypeF(), "ePluginOpenGLRenderSupportNone", (long) Natron::PluginOpenGLRenderSupport::ePluginOpenGLRenderSupportNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX],
        Sbk_Natron_TypeF(), "ePluginOpenGLRenderSupportYes", (long) Natron::PluginOpenGLRenderSupport::ePluginOpenGLRenderSupportYes))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX],
        Sbk_Natron_TypeF(), "ePluginOpenGLRenderSupportNeeded", (long) Natron::PluginOpenGLRenderSupport::ePluginOpenGLRenderSupportNeeded))
        return;
    // Register converter for enum 'Natron::PluginOpenGLRenderSupport'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX],
            Natron_PluginOpenGLRenderSupport_CppToPython_Natron_PluginOpenGLRenderSupport);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PluginOpenGLRenderSupport_PythonToCpp_Natron_PluginOpenGLRenderSupport,
            is_Natron_PluginOpenGLRenderSupport_PythonToCpp_Natron_PluginOpenGLRenderSupport_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PLUGINOPENGLRENDERSUPPORT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PluginOpenGLRenderSupport");
        Shiboken::Conversions::registerConverterName(converter, "PluginOpenGLRenderSupport");
    }
    // End of 'PluginOpenGLRenderSupport' enum.

    // Initialization of enum 'CurveChangeReason'.
    SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "CurveChangeReason",
        "1:NatronEngine.Natron.CurveChangeReason",
        "Natron::CurveChangeReason");
    if (!SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX],
        Sbk_Natron_TypeF(), "eCurveChangeReasonCurveEditor", (long) Natron::CurveChangeReason::eCurveChangeReasonCurveEditor))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX],
        Sbk_Natron_TypeF(), "eCurveChangeReasonDopeSheet", (long) Natron::CurveChangeReason::eCurveChangeReasonDopeSheet))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX],
        Sbk_Natron_TypeF(), "eCurveChangeReasonInternal", (long) Natron::CurveChangeReason::eCurveChangeReasonInternal))
        return;
    // Register converter for enum 'Natron::CurveChangeReason'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX],
            Natron_CurveChangeReason_CppToPython_Natron_CurveChangeReason);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_CurveChangeReason_PythonToCpp_Natron_CurveChangeReason,
            is_Natron_CurveChangeReason_PythonToCpp_Natron_CurveChangeReason_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_CURVECHANGEREASON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::CurveChangeReason");
        Shiboken::Conversions::registerConverterName(converter, "CurveChangeReason");
    }
    // End of 'CurveChangeReason' enum.

    // Initialization of enum 'OpenGLRequirementsTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "OpenGLRequirementsTypeEnum",
        "1:NatronEngine.Natron.OpenGLRequirementsTypeEnum",
        "Natron::OpenGLRequirementsTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eOpenGLRequirementsTypeViewer", (long) Natron::OpenGLRequirementsTypeEnum::eOpenGLRequirementsTypeViewer))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eOpenGLRequirementsTypeRendering", (long) Natron::OpenGLRequirementsTypeEnum::eOpenGLRequirementsTypeRendering))
        return;
    // Register converter for enum 'Natron::OpenGLRequirementsTypeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX],
            Natron_OpenGLRequirementsTypeEnum_CppToPython_Natron_OpenGLRequirementsTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_OpenGLRequirementsTypeEnum_PythonToCpp_Natron_OpenGLRequirementsTypeEnum,
            is_Natron_OpenGLRequirementsTypeEnum_PythonToCpp_Natron_OpenGLRequirementsTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_OPENGLREQUIREMENTSTYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::OpenGLRequirementsTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "OpenGLRequirementsTypeEnum");
    }
    // End of 'OpenGLRequirementsTypeEnum' enum.

    // Initialization of enum 'DopeSheetItemType'.
    SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "DopeSheetItemType",
        "1:NatronEngine.Natron.DopeSheetItemType",
        "Natron::DopeSheetItemType");
    if (!SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeCommon", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeCommon))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeReader", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeReader))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeRetime", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeRetime))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeTimeOffset", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeTimeOffset))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeFrameRange", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeFrameRange))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeGroup", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeGroup))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeKnobRoot", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeKnobRoot))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
        Sbk_Natron_TypeF(), "eDopeSheetItemTypeKnobDim", (long) Natron::DopeSheetItemType::eDopeSheetItemTypeKnobDim))
        return;
    // Register converter for enum 'Natron::DopeSheetItemType'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX],
            Natron_DopeSheetItemType_CppToPython_Natron_DopeSheetItemType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_DopeSheetItemType_PythonToCpp_Natron_DopeSheetItemType,
            is_Natron_DopeSheetItemType_PythonToCpp_Natron_DopeSheetItemType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_DOPESHEETITEMTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::DopeSheetItemType");
        Shiboken::Conversions::registerConverterName(converter, "DopeSheetItemType");
    }
    // End of 'DopeSheetItemType' enum.

    // Initialization of enum 'CreateNodeReason'.
    SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "CreateNodeReason",
        "1:NatronEngine.Natron.CreateNodeReason",
        "Natron::CreateNodeReason");
    if (!SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX],
        Sbk_Natron_TypeF(), "eCreateNodeReasonUserCreate", (long) Natron::CreateNodeReason::eCreateNodeReasonUserCreate))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX],
        Sbk_Natron_TypeF(), "eCreateNodeReasonCopyPaste", (long) Natron::CreateNodeReason::eCreateNodeReasonCopyPaste))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX],
        Sbk_Natron_TypeF(), "eCreateNodeReasonProjectLoad", (long) Natron::CreateNodeReason::eCreateNodeReasonProjectLoad))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX],
        Sbk_Natron_TypeF(), "eCreateNodeReasonInternal", (long) Natron::CreateNodeReason::eCreateNodeReasonInternal))
        return;
    // Register converter for enum 'Natron::CreateNodeReason'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX],
            Natron_CreateNodeReason_CppToPython_Natron_CreateNodeReason);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_CreateNodeReason_PythonToCpp_Natron_CreateNodeReason,
            is_Natron_CreateNodeReason_PythonToCpp_Natron_CreateNodeReason_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_CREATENODEREASON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::CreateNodeReason");
        Shiboken::Conversions::registerConverterName(converter, "CreateNodeReason");
    }
    // End of 'CreateNodeReason' enum.

    // Initialization of enum 'KnobClipBoardType'.
    SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "KnobClipBoardType",
        "1:NatronEngine.Natron.KnobClipBoardType",
        "Natron::KnobClipBoardType");
    if (!SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX],
        Sbk_Natron_TypeF(), "eKnobClipBoardTypeCopyValue", (long) Natron::KnobClipBoardType::eKnobClipBoardTypeCopyValue))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX],
        Sbk_Natron_TypeF(), "eKnobClipBoardTypeCopyAnim", (long) Natron::KnobClipBoardType::eKnobClipBoardTypeCopyAnim))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX],
        Sbk_Natron_TypeF(), "eKnobClipBoardTypeCopyLink", (long) Natron::KnobClipBoardType::eKnobClipBoardTypeCopyLink))
        return;
    // Register converter for enum 'Natron::KnobClipBoardType'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX],
            Natron_KnobClipBoardType_CppToPython_Natron_KnobClipBoardType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_KnobClipBoardType_PythonToCpp_Natron_KnobClipBoardType,
            is_Natron_KnobClipBoardType_PythonToCpp_Natron_KnobClipBoardType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KNOBCLIPBOARDTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KnobClipBoardType");
        Shiboken::Conversions::registerConverterName(converter, "KnobClipBoardType");
    }
    // End of 'KnobClipBoardType' enum.

    // Initialization of enum 'ValueIsNormalizedEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ValueIsNormalizedEnum",
        "1:NatronEngine.Natron.ValueIsNormalizedEnum",
        "Natron::ValueIsNormalizedEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX],
        Sbk_Natron_TypeF(), "eValueIsNormalizedNone", (long) Natron::ValueIsNormalizedEnum::eValueIsNormalizedNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX],
        Sbk_Natron_TypeF(), "eValueIsNormalizedX", (long) Natron::ValueIsNormalizedEnum::eValueIsNormalizedX))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX],
        Sbk_Natron_TypeF(), "eValueIsNormalizedY", (long) Natron::ValueIsNormalizedEnum::eValueIsNormalizedY))
        return;
    // Register converter for enum 'Natron::ValueIsNormalizedEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX],
            Natron_ValueIsNormalizedEnum_CppToPython_Natron_ValueIsNormalizedEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ValueIsNormalizedEnum_PythonToCpp_Natron_ValueIsNormalizedEnum,
            is_Natron_ValueIsNormalizedEnum_PythonToCpp_Natron_ValueIsNormalizedEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VALUEISNORMALIZEDENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ValueIsNormalizedEnum");
        Shiboken::Conversions::registerConverterName(converter, "ValueIsNormalizedEnum");
    }
    // End of 'ValueIsNormalizedEnum' enum.

    // Initialization of enum 'CursorEnum'.
    SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "CursorEnum",
        "1:NatronEngine.Natron.CursorEnum",
        "Natron::CursorEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorDefault", (long) Natron::CursorEnum::eCursorDefault))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorBlank", (long) Natron::CursorEnum::eCursorBlank))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorArrow", (long) Natron::CursorEnum::eCursorArrow))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorUpArrow", (long) Natron::CursorEnum::eCursorUpArrow))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorCross", (long) Natron::CursorEnum::eCursorCross))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorIBeam", (long) Natron::CursorEnum::eCursorIBeam))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorWait", (long) Natron::CursorEnum::eCursorWait))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorBusy", (long) Natron::CursorEnum::eCursorBusy))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorForbidden", (long) Natron::CursorEnum::eCursorForbidden))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorPointingHand", (long) Natron::CursorEnum::eCursorPointingHand))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorWhatsThis", (long) Natron::CursorEnum::eCursorWhatsThis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorSizeVer", (long) Natron::CursorEnum::eCursorSizeVer))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorSizeHor", (long) Natron::CursorEnum::eCursorSizeHor))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorBDiag", (long) Natron::CursorEnum::eCursorBDiag))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorFDiag", (long) Natron::CursorEnum::eCursorFDiag))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorSizeAll", (long) Natron::CursorEnum::eCursorSizeAll))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorSplitV", (long) Natron::CursorEnum::eCursorSplitV))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorSplitH", (long) Natron::CursorEnum::eCursorSplitH))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorOpenHand", (long) Natron::CursorEnum::eCursorOpenHand))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
        Sbk_Natron_TypeF(), "eCursorClosedHand", (long) Natron::CursorEnum::eCursorClosedHand))
        return;
    // Register converter for enum 'Natron::CursorEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX],
            Natron_CursorEnum_CppToPython_Natron_CursorEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_CursorEnum_PythonToCpp_Natron_CursorEnum,
            is_Natron_CursorEnum_PythonToCpp_Natron_CursorEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_CURSORENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::CursorEnum");
        Shiboken::Conversions::registerConverterName(converter, "CursorEnum");
    }
    // End of 'CursorEnum' enum.

    // Initialization of enum 'MergingFunctionEnum'.
    SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "MergingFunctionEnum",
        "1:NatronEngine.Natron.MergingFunctionEnum",
        "Natron::MergingFunctionEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeATop", (long) Natron::MergingFunctionEnum::eMergeATop))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeAverage", (long) Natron::MergingFunctionEnum::eMergeAverage))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeColor", (long) Natron::MergingFunctionEnum::eMergeColor))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeColorBurn", (long) Natron::MergingFunctionEnum::eMergeColorBurn))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeColorDodge", (long) Natron::MergingFunctionEnum::eMergeColorDodge))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeConjointOver", (long) Natron::MergingFunctionEnum::eMergeConjointOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeCopy", (long) Natron::MergingFunctionEnum::eMergeCopy))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeDifference", (long) Natron::MergingFunctionEnum::eMergeDifference))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeDisjointOver", (long) Natron::MergingFunctionEnum::eMergeDisjointOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeDivide", (long) Natron::MergingFunctionEnum::eMergeDivide))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeExclusion", (long) Natron::MergingFunctionEnum::eMergeExclusion))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeFreeze", (long) Natron::MergingFunctionEnum::eMergeFreeze))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeFrom", (long) Natron::MergingFunctionEnum::eMergeFrom))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeGeometric", (long) Natron::MergingFunctionEnum::eMergeGeometric))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeGrainExtract", (long) Natron::MergingFunctionEnum::eMergeGrainExtract))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeGrainMerge", (long) Natron::MergingFunctionEnum::eMergeGrainMerge))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeHardLight", (long) Natron::MergingFunctionEnum::eMergeHardLight))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeHue", (long) Natron::MergingFunctionEnum::eMergeHue))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeHypot", (long) Natron::MergingFunctionEnum::eMergeHypot))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeIn", (long) Natron::MergingFunctionEnum::eMergeIn))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeLuminosity", (long) Natron::MergingFunctionEnum::eMergeLuminosity))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMask", (long) Natron::MergingFunctionEnum::eMergeMask))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMatte", (long) Natron::MergingFunctionEnum::eMergeMatte))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMax", (long) Natron::MergingFunctionEnum::eMergeMax))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMin", (long) Natron::MergingFunctionEnum::eMergeMin))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMinus", (long) Natron::MergingFunctionEnum::eMergeMinus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMultiply", (long) Natron::MergingFunctionEnum::eMergeMultiply))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeOut", (long) Natron::MergingFunctionEnum::eMergeOut))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeOver", (long) Natron::MergingFunctionEnum::eMergeOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeOverlay", (long) Natron::MergingFunctionEnum::eMergeOverlay))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergePinLight", (long) Natron::MergingFunctionEnum::eMergePinLight))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergePlus", (long) Natron::MergingFunctionEnum::eMergePlus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeReflect", (long) Natron::MergingFunctionEnum::eMergeReflect))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeSaturation", (long) Natron::MergingFunctionEnum::eMergeSaturation))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeScreen", (long) Natron::MergingFunctionEnum::eMergeScreen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeSoftLight", (long) Natron::MergingFunctionEnum::eMergeSoftLight))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeStencil", (long) Natron::MergingFunctionEnum::eMergeStencil))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeUnder", (long) Natron::MergingFunctionEnum::eMergeUnder))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeXOR", (long) Natron::MergingFunctionEnum::eMergeXOR))
        return;
    // Register converter for enum 'Natron::MergingFunctionEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
            Natron_MergingFunctionEnum_CppToPython_Natron_MergingFunctionEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum,
            is_Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::MergingFunctionEnum");
        Shiboken::Conversions::registerConverterName(converter, "MergingFunctionEnum");
    }
    // End of 'MergingFunctionEnum' enum.

    // Initialization of enum 'Key'.
    SbkNatronEngineTypes[SBK_NATRON_KEY_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "Key",
        "1:NatronEngine.Natron.Key",
        "Natron::Key");
    if (!SbkNatronEngineTypes[SBK_NATRON_KEY_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Unknown", (long) Natron::Key::Key_Unknown))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_BackSpace", (long) Natron::Key::Key_BackSpace))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Tab", (long) Natron::Key::Key_Tab))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Linefeed", (long) Natron::Key::Key_Linefeed))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Clear", (long) Natron::Key::Key_Clear))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Return", (long) Natron::Key::Key_Return))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Pause", (long) Natron::Key::Key_Pause))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Scroll_Lock", (long) Natron::Key::Key_Scroll_Lock))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Sys_Req", (long) Natron::Key::Key_Sys_Req))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Escape", (long) Natron::Key::Key_Escape))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Delete", (long) Natron::Key::Key_Delete))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Multi_key", (long) Natron::Key::Key_Multi_key))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_SingleCandidate", (long) Natron::Key::Key_SingleCandidate))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_MultipleCandidate", (long) Natron::Key::Key_MultipleCandidate))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_PreviousCandidate", (long) Natron::Key::Key_PreviousCandidate))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Kanji", (long) Natron::Key::Key_Kanji))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Muhenkan", (long) Natron::Key::Key_Muhenkan))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Henkan_Mode", (long) Natron::Key::Key_Henkan_Mode))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Henkan", (long) Natron::Key::Key_Henkan))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Romaji", (long) Natron::Key::Key_Romaji))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Hiragana", (long) Natron::Key::Key_Hiragana))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Katakana", (long) Natron::Key::Key_Katakana))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Hiragana_Katakana", (long) Natron::Key::Key_Hiragana_Katakana))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Zenkaku", (long) Natron::Key::Key_Zenkaku))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Hankaku", (long) Natron::Key::Key_Hankaku))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Zenkaku_Hankaku", (long) Natron::Key::Key_Zenkaku_Hankaku))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Touroku", (long) Natron::Key::Key_Touroku))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Massyo", (long) Natron::Key::Key_Massyo))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Kana_Lock", (long) Natron::Key::Key_Kana_Lock))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Kana_Shift", (long) Natron::Key::Key_Kana_Shift))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Eisu_Shift", (long) Natron::Key::Key_Eisu_Shift))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Eisu_toggle", (long) Natron::Key::Key_Eisu_toggle))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Zen_Koho", (long) Natron::Key::Key_Zen_Koho))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Mae_Koho", (long) Natron::Key::Key_Mae_Koho))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Home", (long) Natron::Key::Key_Home))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Left", (long) Natron::Key::Key_Left))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Up", (long) Natron::Key::Key_Up))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Right", (long) Natron::Key::Key_Right))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Down", (long) Natron::Key::Key_Down))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Prior", (long) Natron::Key::Key_Prior))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Page_Up", (long) Natron::Key::Key_Page_Up))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Next", (long) Natron::Key::Key_Next))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Page_Down", (long) Natron::Key::Key_Page_Down))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_End", (long) Natron::Key::Key_End))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Begin", (long) Natron::Key::Key_Begin))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Select", (long) Natron::Key::Key_Select))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Print", (long) Natron::Key::Key_Print))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Execute", (long) Natron::Key::Key_Execute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Insert", (long) Natron::Key::Key_Insert))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Undo", (long) Natron::Key::Key_Undo))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Redo", (long) Natron::Key::Key_Redo))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Menu", (long) Natron::Key::Key_Menu))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Find", (long) Natron::Key::Key_Find))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Cancel", (long) Natron::Key::Key_Cancel))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Help", (long) Natron::Key::Key_Help))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Break", (long) Natron::Key::Key_Break))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Mode_switch", (long) Natron::Key::Key_Mode_switch))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_script_switch", (long) Natron::Key::Key_script_switch))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Num_Lock", (long) Natron::Key::Key_Num_Lock))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Space", (long) Natron::Key::Key_KP_Space))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Tab", (long) Natron::Key::Key_KP_Tab))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Enter", (long) Natron::Key::Key_KP_Enter))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_F1", (long) Natron::Key::Key_KP_F1))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_F2", (long) Natron::Key::Key_KP_F2))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_F3", (long) Natron::Key::Key_KP_F3))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_F4", (long) Natron::Key::Key_KP_F4))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Home", (long) Natron::Key::Key_KP_Home))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Left", (long) Natron::Key::Key_KP_Left))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Up", (long) Natron::Key::Key_KP_Up))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Right", (long) Natron::Key::Key_KP_Right))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Down", (long) Natron::Key::Key_KP_Down))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Prior", (long) Natron::Key::Key_KP_Prior))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Page_Up", (long) Natron::Key::Key_KP_Page_Up))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Next", (long) Natron::Key::Key_KP_Next))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Page_Down", (long) Natron::Key::Key_KP_Page_Down))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_End", (long) Natron::Key::Key_KP_End))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Begin", (long) Natron::Key::Key_KP_Begin))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Insert", (long) Natron::Key::Key_KP_Insert))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Delete", (long) Natron::Key::Key_KP_Delete))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Equal", (long) Natron::Key::Key_KP_Equal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Multiply", (long) Natron::Key::Key_KP_Multiply))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Add", (long) Natron::Key::Key_KP_Add))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Separator", (long) Natron::Key::Key_KP_Separator))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Subtract", (long) Natron::Key::Key_KP_Subtract))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Decimal", (long) Natron::Key::Key_KP_Decimal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_Divide", (long) Natron::Key::Key_KP_Divide))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_0", (long) Natron::Key::Key_KP_0))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_1", (long) Natron::Key::Key_KP_1))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_2", (long) Natron::Key::Key_KP_2))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_3", (long) Natron::Key::Key_KP_3))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_4", (long) Natron::Key::Key_KP_4))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_5", (long) Natron::Key::Key_KP_5))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_6", (long) Natron::Key::Key_KP_6))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_7", (long) Natron::Key::Key_KP_7))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_8", (long) Natron::Key::Key_KP_8))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_KP_9", (long) Natron::Key::Key_KP_9))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F1", (long) Natron::Key::Key_F1))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F2", (long) Natron::Key::Key_F2))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F3", (long) Natron::Key::Key_F3))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F4", (long) Natron::Key::Key_F4))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F5", (long) Natron::Key::Key_F5))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F6", (long) Natron::Key::Key_F6))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F7", (long) Natron::Key::Key_F7))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F8", (long) Natron::Key::Key_F8))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F9", (long) Natron::Key::Key_F9))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F10", (long) Natron::Key::Key_F10))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F11", (long) Natron::Key::Key_F11))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L1", (long) Natron::Key::Key_L1))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F12", (long) Natron::Key::Key_F12))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L2", (long) Natron::Key::Key_L2))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F13", (long) Natron::Key::Key_F13))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L3", (long) Natron::Key::Key_L3))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F14", (long) Natron::Key::Key_F14))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L4", (long) Natron::Key::Key_L4))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F15", (long) Natron::Key::Key_F15))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L5", (long) Natron::Key::Key_L5))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F16", (long) Natron::Key::Key_F16))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L6", (long) Natron::Key::Key_L6))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F17", (long) Natron::Key::Key_F17))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L7", (long) Natron::Key::Key_L7))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F18", (long) Natron::Key::Key_F18))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L8", (long) Natron::Key::Key_L8))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F19", (long) Natron::Key::Key_F19))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L9", (long) Natron::Key::Key_L9))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F20", (long) Natron::Key::Key_F20))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L10", (long) Natron::Key::Key_L10))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F21", (long) Natron::Key::Key_F21))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R1", (long) Natron::Key::Key_R1))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F22", (long) Natron::Key::Key_F22))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R2", (long) Natron::Key::Key_R2))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F23", (long) Natron::Key::Key_F23))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R3", (long) Natron::Key::Key_R3))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F24", (long) Natron::Key::Key_F24))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R4", (long) Natron::Key::Key_R4))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F25", (long) Natron::Key::Key_F25))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R5", (long) Natron::Key::Key_R5))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F26", (long) Natron::Key::Key_F26))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R6", (long) Natron::Key::Key_R6))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F27", (long) Natron::Key::Key_F27))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R7", (long) Natron::Key::Key_R7))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F28", (long) Natron::Key::Key_F28))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R8", (long) Natron::Key::Key_R8))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F29", (long) Natron::Key::Key_F29))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R9", (long) Natron::Key::Key_R9))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F30", (long) Natron::Key::Key_F30))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R10", (long) Natron::Key::Key_R10))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F31", (long) Natron::Key::Key_F31))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R11", (long) Natron::Key::Key_R11))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F32", (long) Natron::Key::Key_F32))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R12", (long) Natron::Key::Key_R12))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F33", (long) Natron::Key::Key_F33))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R13", (long) Natron::Key::Key_R13))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F34", (long) Natron::Key::Key_F34))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R14", (long) Natron::Key::Key_R14))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F35", (long) Natron::Key::Key_F35))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R15", (long) Natron::Key::Key_R15))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Shift_L", (long) Natron::Key::Key_Shift_L))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Shift_R", (long) Natron::Key::Key_Shift_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Control_L", (long) Natron::Key::Key_Control_L))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Control_R", (long) Natron::Key::Key_Control_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Caps_Lock", (long) Natron::Key::Key_Caps_Lock))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Shift_Lock", (long) Natron::Key::Key_Shift_Lock))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Meta_L", (long) Natron::Key::Key_Meta_L))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Meta_R", (long) Natron::Key::Key_Meta_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Alt_L", (long) Natron::Key::Key_Alt_L))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Alt_R", (long) Natron::Key::Key_Alt_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Super_L", (long) Natron::Key::Key_Super_L))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Super_R", (long) Natron::Key::Key_Super_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Hyper_L", (long) Natron::Key::Key_Hyper_L))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Hyper_R", (long) Natron::Key::Key_Hyper_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_space", (long) Natron::Key::Key_space))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_exclam", (long) Natron::Key::Key_exclam))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_quotedbl", (long) Natron::Key::Key_quotedbl))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_numbersign", (long) Natron::Key::Key_numbersign))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_dollar", (long) Natron::Key::Key_dollar))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_percent", (long) Natron::Key::Key_percent))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ampersand", (long) Natron::Key::Key_ampersand))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_apostrophe", (long) Natron::Key::Key_apostrophe))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_quoteright", (long) Natron::Key::Key_quoteright))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_parenleft", (long) Natron::Key::Key_parenleft))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_parenright", (long) Natron::Key::Key_parenright))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_asterisk", (long) Natron::Key::Key_asterisk))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_plus", (long) Natron::Key::Key_plus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_comma", (long) Natron::Key::Key_comma))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_minus", (long) Natron::Key::Key_minus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_period", (long) Natron::Key::Key_period))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_slash", (long) Natron::Key::Key_slash))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_0", (long) Natron::Key::Key_0))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_1", (long) Natron::Key::Key_1))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_2", (long) Natron::Key::Key_2))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_3", (long) Natron::Key::Key_3))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_4", (long) Natron::Key::Key_4))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_5", (long) Natron::Key::Key_5))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_6", (long) Natron::Key::Key_6))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_7", (long) Natron::Key::Key_7))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_8", (long) Natron::Key::Key_8))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_9", (long) Natron::Key::Key_9))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_colon", (long) Natron::Key::Key_colon))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_semicolon", (long) Natron::Key::Key_semicolon))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_less", (long) Natron::Key::Key_less))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_equal", (long) Natron::Key::Key_equal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_greater", (long) Natron::Key::Key_greater))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_question", (long) Natron::Key::Key_question))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_at", (long) Natron::Key::Key_at))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_A", (long) Natron::Key::Key_A))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_B", (long) Natron::Key::Key_B))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_C", (long) Natron::Key::Key_C))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_D", (long) Natron::Key::Key_D))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_E", (long) Natron::Key::Key_E))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_F", (long) Natron::Key::Key_F))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_G", (long) Natron::Key::Key_G))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_H", (long) Natron::Key::Key_H))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_I", (long) Natron::Key::Key_I))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_J", (long) Natron::Key::Key_J))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_K", (long) Natron::Key::Key_K))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_L", (long) Natron::Key::Key_L))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_M", (long) Natron::Key::Key_M))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_N", (long) Natron::Key::Key_N))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_O", (long) Natron::Key::Key_O))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_P", (long) Natron::Key::Key_P))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Q", (long) Natron::Key::Key_Q))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_R", (long) Natron::Key::Key_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_S", (long) Natron::Key::Key_S))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_T", (long) Natron::Key::Key_T))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_U", (long) Natron::Key::Key_U))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_V", (long) Natron::Key::Key_V))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_W", (long) Natron::Key::Key_W))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_X", (long) Natron::Key::Key_X))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Y", (long) Natron::Key::Key_Y))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Z", (long) Natron::Key::Key_Z))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_bracketleft", (long) Natron::Key::Key_bracketleft))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_backslash", (long) Natron::Key::Key_backslash))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_bracketright", (long) Natron::Key::Key_bracketright))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_asciicircum", (long) Natron::Key::Key_asciicircum))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_underscore", (long) Natron::Key::Key_underscore))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_grave", (long) Natron::Key::Key_grave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_quoteleft", (long) Natron::Key::Key_quoteleft))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_a", (long) Natron::Key::Key_a))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_b", (long) Natron::Key::Key_b))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_c", (long) Natron::Key::Key_c))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_d", (long) Natron::Key::Key_d))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_e", (long) Natron::Key::Key_e))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_f", (long) Natron::Key::Key_f))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_g", (long) Natron::Key::Key_g))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_h", (long) Natron::Key::Key_h))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_i", (long) Natron::Key::Key_i))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_j", (long) Natron::Key::Key_j))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_k", (long) Natron::Key::Key_k))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_l", (long) Natron::Key::Key_l))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_m", (long) Natron::Key::Key_m))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_n", (long) Natron::Key::Key_n))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_o", (long) Natron::Key::Key_o))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_p", (long) Natron::Key::Key_p))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_q", (long) Natron::Key::Key_q))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_r", (long) Natron::Key::Key_r))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_s", (long) Natron::Key::Key_s))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_t", (long) Natron::Key::Key_t))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_u", (long) Natron::Key::Key_u))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_v", (long) Natron::Key::Key_v))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_w", (long) Natron::Key::Key_w))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_x", (long) Natron::Key::Key_x))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_y", (long) Natron::Key::Key_y))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_z", (long) Natron::Key::Key_z))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_braceleft", (long) Natron::Key::Key_braceleft))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_bar", (long) Natron::Key::Key_bar))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_braceright", (long) Natron::Key::Key_braceright))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_asciitilde", (long) Natron::Key::Key_asciitilde))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_nobreakspace", (long) Natron::Key::Key_nobreakspace))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_exclamdown", (long) Natron::Key::Key_exclamdown))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_cent", (long) Natron::Key::Key_cent))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_sterling", (long) Natron::Key::Key_sterling))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_currency", (long) Natron::Key::Key_currency))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_yen", (long) Natron::Key::Key_yen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_brokenbar", (long) Natron::Key::Key_brokenbar))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_section", (long) Natron::Key::Key_section))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_diaeresis", (long) Natron::Key::Key_diaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_copyright", (long) Natron::Key::Key_copyright))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ordfeminine", (long) Natron::Key::Key_ordfeminine))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_guillemotleft", (long) Natron::Key::Key_guillemotleft))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_notsign", (long) Natron::Key::Key_notsign))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_hyphen", (long) Natron::Key::Key_hyphen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_registered", (long) Natron::Key::Key_registered))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_macron", (long) Natron::Key::Key_macron))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_degree", (long) Natron::Key::Key_degree))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_plusminus", (long) Natron::Key::Key_plusminus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_twosuperior", (long) Natron::Key::Key_twosuperior))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_threesuperior", (long) Natron::Key::Key_threesuperior))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_acute", (long) Natron::Key::Key_acute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_mu", (long) Natron::Key::Key_mu))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_paragraph", (long) Natron::Key::Key_paragraph))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_periodcentered", (long) Natron::Key::Key_periodcentered))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_cedilla", (long) Natron::Key::Key_cedilla))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_onesuperior", (long) Natron::Key::Key_onesuperior))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_masculine", (long) Natron::Key::Key_masculine))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_guillemotright", (long) Natron::Key::Key_guillemotright))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_onequarter", (long) Natron::Key::Key_onequarter))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_onehalf", (long) Natron::Key::Key_onehalf))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_threequarters", (long) Natron::Key::Key_threequarters))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_questiondown", (long) Natron::Key::Key_questiondown))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Agrave", (long) Natron::Key::Key_Agrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Aacute", (long) Natron::Key::Key_Aacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Acircumflex", (long) Natron::Key::Key_Acircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Atilde", (long) Natron::Key::Key_Atilde))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Adiaeresis", (long) Natron::Key::Key_Adiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Aring", (long) Natron::Key::Key_Aring))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_AE", (long) Natron::Key::Key_AE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ccedilla", (long) Natron::Key::Key_Ccedilla))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Egrave", (long) Natron::Key::Key_Egrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Eacute", (long) Natron::Key::Key_Eacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ecircumflex", (long) Natron::Key::Key_Ecircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ediaeresis", (long) Natron::Key::Key_Ediaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Igrave", (long) Natron::Key::Key_Igrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Iacute", (long) Natron::Key::Key_Iacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Icircumflex", (long) Natron::Key::Key_Icircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Idiaeresis", (long) Natron::Key::Key_Idiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ETH", (long) Natron::Key::Key_ETH))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Eth", (long) Natron::Key::Key_Eth))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ntilde", (long) Natron::Key::Key_Ntilde))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ograve", (long) Natron::Key::Key_Ograve))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Oacute", (long) Natron::Key::Key_Oacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ocircumflex", (long) Natron::Key::Key_Ocircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Otilde", (long) Natron::Key::Key_Otilde))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Odiaeresis", (long) Natron::Key::Key_Odiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_multiply", (long) Natron::Key::Key_multiply))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ooblique", (long) Natron::Key::Key_Ooblique))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ugrave", (long) Natron::Key::Key_Ugrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Uacute", (long) Natron::Key::Key_Uacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Ucircumflex", (long) Natron::Key::Key_Ucircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Udiaeresis", (long) Natron::Key::Key_Udiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_Yacute", (long) Natron::Key::Key_Yacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_THORN", (long) Natron::Key::Key_THORN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ssharp", (long) Natron::Key::Key_ssharp))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_agrave", (long) Natron::Key::Key_agrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_aacute", (long) Natron::Key::Key_aacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_acircumflex", (long) Natron::Key::Key_acircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_atilde", (long) Natron::Key::Key_atilde))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_adiaeresis", (long) Natron::Key::Key_adiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_aring", (long) Natron::Key::Key_aring))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ae", (long) Natron::Key::Key_ae))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ccedilla", (long) Natron::Key::Key_ccedilla))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_egrave", (long) Natron::Key::Key_egrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_eacute", (long) Natron::Key::Key_eacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ecircumflex", (long) Natron::Key::Key_ecircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ediaeresis", (long) Natron::Key::Key_ediaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_igrave", (long) Natron::Key::Key_igrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_iacute", (long) Natron::Key::Key_iacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_icircumflex", (long) Natron::Key::Key_icircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_idiaeresis", (long) Natron::Key::Key_idiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_eth", (long) Natron::Key::Key_eth))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ntilde", (long) Natron::Key::Key_ntilde))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ograve", (long) Natron::Key::Key_ograve))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_oacute", (long) Natron::Key::Key_oacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ocircumflex", (long) Natron::Key::Key_ocircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_otilde", (long) Natron::Key::Key_otilde))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_odiaeresis", (long) Natron::Key::Key_odiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_division", (long) Natron::Key::Key_division))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_oslash", (long) Natron::Key::Key_oslash))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ugrave", (long) Natron::Key::Key_ugrave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_uacute", (long) Natron::Key::Key_uacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ucircumflex", (long) Natron::Key::Key_ucircumflex))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_udiaeresis", (long) Natron::Key::Key_udiaeresis))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_yacute", (long) Natron::Key::Key_yacute))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_thorn", (long) Natron::Key::Key_thorn))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
        Sbk_Natron_TypeF(), "Key_ydiaeresis", (long) Natron::Key::Key_ydiaeresis))
        return;
    // Register converter for enum 'Natron::Key'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX],
            Natron_Key_CppToPython_Natron_Key);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_Key_PythonToCpp_Natron_Key,
            is_Natron_Key_PythonToCpp_Natron_Key_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KEY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::Key");
        Shiboken::Conversions::registerConverterName(converter, "Key");
    }
    // End of 'Key' enum.

    // Initialization of enum 'KeyboardModifierEnum'.
    SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "KeyboardModifierEnum",
        "1:NatronEngine.Natron.KeyboardModifierEnum",
        "Natron::KeyboardModifierEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierNone", (long) Natron::KeyboardModifierEnum::eKeyboardModifierNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierShift", (long) Natron::KeyboardModifierEnum::eKeyboardModifierShift))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierControl", (long) Natron::KeyboardModifierEnum::eKeyboardModifierControl))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierAlt", (long) Natron::KeyboardModifierEnum::eKeyboardModifierAlt))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierMeta", (long) Natron::KeyboardModifierEnum::eKeyboardModifierMeta))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierKeypad", (long) Natron::KeyboardModifierEnum::eKeyboardModifierKeypad))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierGroupSwitch", (long) Natron::KeyboardModifierEnum::eKeyboardModifierGroupSwitch))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierMask", (long) Natron::KeyboardModifierEnum::eKeyboardModifierMask))
        return;
    // Register converter for enum 'Natron::KeyboardModifierEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
            Natron_KeyboardModifierEnum_CppToPython_Natron_KeyboardModifierEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum,
            is_Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KeyboardModifierEnum");
        Shiboken::Conversions::registerConverterName(converter, "KeyboardModifierEnum");
    }
    // End of 'KeyboardModifierEnum' enum.

    // Initialization of enum 'AppInstanceStatusEnum'.
    SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "AppInstanceStatusEnum",
        "1:NatronEngine.Natron.AppInstanceStatusEnum",
        "Natron::AppInstanceStatusEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eAppInstanceStatusInactive", (long) Natron::AppInstanceStatusEnum::eAppInstanceStatusInactive))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eAppInstanceStatusActive", (long) Natron::AppInstanceStatusEnum::eAppInstanceStatusActive))
        return;
    // Register converter for enum 'Natron::AppInstanceStatusEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX],
            Natron_AppInstanceStatusEnum_CppToPython_Natron_AppInstanceStatusEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum,
            is_Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::AppInstanceStatusEnum");
        Shiboken::Conversions::registerConverterName(converter, "AppInstanceStatusEnum");
    }
    // End of 'AppInstanceStatusEnum' enum.


    qRegisterMetaType< ::Natron::ScaleTypeEnum >("Natron::ScaleTypeEnum");
    qRegisterMetaType< ::Natron::TimelineStateEnum >("Natron::TimelineStateEnum");
    qRegisterMetaType< ::Natron::TimelineChangeReasonEnum >("Natron::TimelineChangeReasonEnum");
    qRegisterMetaType< ::Natron::StatusEnum >("Natron::StatusEnum");
    qRegisterMetaType< ::Natron::StandardButtonEnum >("Natron::StandardButtonEnum");
    qRegisterMetaType< ::Natron::StandardButtons >("Natron::StandardButtons");
    qRegisterMetaType< ::Natron::MessageTypeEnum >("Natron::MessageTypeEnum");
    qRegisterMetaType< ::Natron::KeyframeTypeEnum >("Natron::KeyframeTypeEnum");
    qRegisterMetaType< ::Natron::PixmapEnum >("Natron::PixmapEnum");
    qRegisterMetaType< ::Natron::ValueChangedReasonEnum >("Natron::ValueChangedReasonEnum");
    qRegisterMetaType< ::Natron::AnimationLevelEnum >("Natron::AnimationLevelEnum");
    qRegisterMetaType< ::Natron::ImagePlaneDescEnum >("Natron::ImagePlaneDescEnum");
    qRegisterMetaType< ::Natron::ImagePremultiplicationEnum >("Natron::ImagePremultiplicationEnum");
    qRegisterMetaType< ::Natron::ImageFieldingOrderEnum >("Natron::ImageFieldingOrderEnum");
    qRegisterMetaType< ::Natron::ViewerCompositingOperatorEnum >("Natron::ViewerCompositingOperatorEnum");
    qRegisterMetaType< ::Natron::ViewerColorSpaceEnum >("Natron::ViewerColorSpaceEnum");
    qRegisterMetaType< ::Natron::ImageBitDepthEnum >("Natron::ImageBitDepthEnum");
    qRegisterMetaType< ::Natron::SequentialPreferenceEnum >("Natron::SequentialPreferenceEnum");
    qRegisterMetaType< ::Natron::StorageModeEnum >("Natron::StorageModeEnum");
    qRegisterMetaType< ::Natron::OrientationEnum >("Natron::OrientationEnum");
    qRegisterMetaType< ::Natron::PlaybackModeEnum >("Natron::PlaybackModeEnum");
    qRegisterMetaType< ::Natron::SchedulingPolicyEnum >("Natron::SchedulingPolicyEnum");
    qRegisterMetaType< ::Natron::DisplayChannelsEnum >("Natron::DisplayChannelsEnum");
    qRegisterMetaType< ::Natron::ContextEnum >("Natron::ContextEnum");
    qRegisterMetaType< ::Natron::RotoStrokeType >("Natron::RotoStrokeType");
    qRegisterMetaType< ::Natron::RenderSafetyEnum >("Natron::RenderSafetyEnum");
    qRegisterMetaType< ::Natron::PenType >("Natron::PenType");
    qRegisterMetaType< ::Natron::PluginOpenGLRenderSupport >("Natron::PluginOpenGLRenderSupport");
    qRegisterMetaType< ::Natron::CurveChangeReason >("Natron::CurveChangeReason");
    qRegisterMetaType< ::Natron::OpenGLRequirementsTypeEnum >("Natron::OpenGLRequirementsTypeEnum");
    qRegisterMetaType< ::Natron::DopeSheetItemType >("Natron::DopeSheetItemType");
    qRegisterMetaType< ::Natron::CreateNodeReason >("Natron::CreateNodeReason");
    qRegisterMetaType< ::Natron::KnobClipBoardType >("Natron::KnobClipBoardType");
    qRegisterMetaType< ::Natron::ValueIsNormalizedEnum >("Natron::ValueIsNormalizedEnum");
    qRegisterMetaType< ::Natron::CursorEnum >("Natron::CursorEnum");
    qRegisterMetaType< ::Natron::MergingFunctionEnum >("Natron::MergingFunctionEnum");
    qRegisterMetaType< ::Natron::Key >("Natron::Key");
    qRegisterMetaType< ::Natron::KeyboardModifierEnum >("Natron::KeyboardModifierEnum");
    qRegisterMetaType< ::Natron::AppInstanceStatusEnum >("Natron::AppInstanceStatusEnum");
}
