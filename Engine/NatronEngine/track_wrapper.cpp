
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

#include "track_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>
#include <list>


#if 0
#if SHIBOKEN_MAJOR_VERSION >= 2
// Native ---------------------------------------------------------

void TrackWrapper::pysideInitQtMetaTypes()
{
}

TrackWrapper::~TrackWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}
#endif
#endif

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_TrackFunc_getParam(PyObject* self, PyObject* pyArg)
{
    ::Track* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Track*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_TRACK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getParam(QString)const
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // getParam(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_TrackFunc_getParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getParam(QString)const
            Param * cppResult = const_cast<const ::Track*>(cppSelf)->getParam(cppArg0);
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

    Sbk_TrackFunc_getParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Track.getParam");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Track.getParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_TrackFunc_getParams(PyObject* self)
{
    ::Track* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Track*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_TRACK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParams()const
            // Begin code injection

            std::list<Param*> params = cppSelf->getParams();
            PyObject* ret = PyList_New((int) params.size());
            int idx = 0;
            for (std::list<Param*>::iterator it = params.begin(); it!=params.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], *it);
            // Ownership transferences.
            Shiboken::Object::getOwnership(item);
            PyList_SET_ITEM(ret, idx, item);
            }
            return ret;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_TrackFunc_getScriptName(PyObject* self)
{
    ::Track* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Track*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_TRACK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getScriptName()const
            QString cppResult = const_cast<const ::Track*>(cppSelf)->getScriptName();
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

static PyObject* Sbk_TrackFunc_reset(PyObject* self)
{
    ::Track* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Track*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_TRACK_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            cppSelf->reset();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_TrackFunc_setScriptName(PyObject* self, PyObject* pyArg)
{
    ::Track* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Track*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_TRACK_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScriptName(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setScriptName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_TrackFunc_setScriptName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScriptName(QString)
            cppSelf->setScriptName(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_TrackFunc_setScriptName_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Track.setScriptName");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Track.setScriptName", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_Track_methods[] = {
    {"getParam", (PyCFunction)Sbk_TrackFunc_getParam, METH_O},
    {"getParams", (PyCFunction)Sbk_TrackFunc_getParams, METH_NOARGS},
    {"getScriptName", (PyCFunction)Sbk_TrackFunc_getScriptName, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_TrackFunc_reset, METH_NOARGS},
    {"setScriptName", (PyCFunction)Sbk_TrackFunc_setScriptName, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Track_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_Track_clear(PyObject* self)
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
static SbkObjectType *_Sbk_Track_Type = nullptr;
static SbkObjectType *Sbk_Track_TypeF(void)
{
    return _Sbk_Track_Type;
}

static PyType_Slot Sbk_Track_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Track_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Track_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Track_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Track_spec = {
    "NatronEngine.Track",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Track_slots
};
#else
static SbkObjectType Sbk_Track_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Track",
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
    /*tp_traverse*/         Sbk_Track_traverse,
    /*tp_clear*/            Sbk_Track_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Track_methods,
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

#if 0
#if SHIBOKEN_MAJOR_VERSION >= 2
static void* Sbk_Track_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::ItemBase >()))
        return dynamic_cast< ::Track*>(reinterpret_cast< ::ItemBase*>(cptr));
    return {};
}
#endif
#endif

// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Track_PythonToCpp_Track_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_Track_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Track_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_Track_PythonToCpp_Track_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Track_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Track_Type))
#endif
        return Track_PythonToCpp_Track_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Track_PTR_CppToPython_Track(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Track *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Track_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::Track*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Track_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Track_SignatureStrings[] = {
    "NatronEngine.Track.getParam(paramScriptName:QString)->NatronEngine.Param",
    "NatronEngine.Track.getParams()->QList[NatronEngine.Param]",
    "NatronEngine.Track.getScriptName()->Qstring",
    "NatronEngine.Track.reset()",
    "NatronEngine.Track.setScriptName(scriptName:QString)",
    nullptr}; // Sentinel
#endif

void init_Track(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_Track_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Track",
        "Track*",
        &Sbk_Track_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        Track_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::Track >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_ITEMBASE_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_TRACK_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Track_TypeF());
#else
    SbkNatronEngineTypes[SBK_TRACK_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Track_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Track", "Track*",
        &Sbk_Track_Type, &Shiboken::callCppDestructor< ::Track >)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Track_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Track_Type,
#endif
        Track_PythonToCpp_Track_PTR,
        is_Track_PythonToCpp_Track_PTR_Convertible,
        Track_PTR_CppToPython_Track);

    Shiboken::Conversions::registerConverterName(converter, "Track");
    Shiboken::Conversions::registerConverterName(converter, "Track*");
    Shiboken::Conversions::registerConverterName(converter, "Track&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Track).name());


#if 0
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Track_TypeF(), &Sbk_Track_typeDiscovery);


    TrackWrapper::pysideInitQtMetaTypes();
#endif
#endif

}
