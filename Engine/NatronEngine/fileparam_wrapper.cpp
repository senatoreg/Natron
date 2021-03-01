
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

#include "fileparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void FileParamWrapper::pysideInitQtMetaTypes()
{
}

FileParamWrapper::~FileParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_FileParamFunc_openFile(PyObject* self)
{
    FileParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (FileParamWrapper*)((::FileParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_FILEPARAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // openFile()
            cppSelf->openFile();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_FileParamFunc_reloadFile(PyObject* self)
{
    FileParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (FileParamWrapper*)((::FileParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_FILEPARAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reloadFile()
            cppSelf->reloadFile();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_FileParamFunc_setSequenceEnabled(PyObject* self, PyObject* pyArg)
{
    FileParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (FileParamWrapper*)((::FileParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_FILEPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSequenceEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSequenceEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_FileParamFunc_setSequenceEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSequenceEnabled(bool)
            cppSelf->setSequenceEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_FileParamFunc_setSequenceEnabled_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.FileParam.setSequenceEnabled");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.FileParam.setSequenceEnabled", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_FileParam_methods[] = {
    {"openFile", (PyCFunction)Sbk_FileParamFunc_openFile, METH_NOARGS},
    {"reloadFile", (PyCFunction)Sbk_FileParamFunc_reloadFile, METH_NOARGS},
    {"setSequenceEnabled", (PyCFunction)Sbk_FileParamFunc_setSequenceEnabled, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_FileParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_FileParam_clear(PyObject* self)
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
static SbkObjectType *_Sbk_FileParam_Type = nullptr;
static SbkObjectType *Sbk_FileParam_TypeF(void)
{
    return _Sbk_FileParam_Type;
}

static PyType_Slot Sbk_FileParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_FileParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_FileParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_FileParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_FileParam_spec = {
    "NatronEngine.FileParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_FileParam_slots
};
#else
static SbkObjectType Sbk_FileParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.FileParam",
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
    /*tp_traverse*/         Sbk_FileParam_traverse,
    /*tp_clear*/            Sbk_FileParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_FileParam_methods,
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

static void* Sbk_FileParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::FileParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void FileParam_PythonToCpp_FileParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_FileParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_FileParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_FileParam_PythonToCpp_FileParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_FileParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_FileParam_Type))
#endif
        return FileParam_PythonToCpp_FileParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* FileParam_PTR_CppToPython_FileParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::FileParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_FileParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::FileParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_FileParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *FileParam_SignatureStrings[] = {
    "NatronEngine.FileParam.openFile()",
    "NatronEngine.FileParam.reloadFile()",
    "NatronEngine.FileParam.setSequenceEnabled(enabled:bool)",
    nullptr}; // Sentinel
#endif

void init_FileParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_FileParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "FileParam",
        "FileParam*",
        &Sbk_FileParam_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        FileParam_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::FileParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_FILEPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_FileParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_FILEPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_FileParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "FileParam", "FileParam*",
        &Sbk_FileParam_Type, &Shiboken::callCppDestructor< ::FileParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_FileParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_FileParam_Type,
#endif
        FileParam_PythonToCpp_FileParam_PTR,
        is_FileParam_PythonToCpp_FileParam_PTR_Convertible,
        FileParam_PTR_CppToPython_FileParam);

    Shiboken::Conversions::registerConverterName(converter, "FileParam");
    Shiboken::Conversions::registerConverterName(converter, "FileParam*");
    Shiboken::Conversions::registerConverterName(converter, "FileParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::FileParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::FileParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_FileParam_TypeF(), &Sbk_FileParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_FileParam_Type, &Sbk_FileParam_typeDiscovery);
#endif


    FileParamWrapper::pysideInitQtMetaTypes();
}
