
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

#include "double2dparam_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>


// Native ---------------------------------------------------------

void Double2DParamWrapper::pysideInitQtMetaTypes()
{
}

Double2DParamWrapper::~Double2DParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Double2DParamFunc_get(PyObject* self, PyObject* args)
{
    Double2DParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (Double2DParamWrapper*)((::Double2DParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "get", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: get()const
    // 1: get(double)const
    if (numArgs == 0) {
        overloadId = 0; // get()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        overloadId = 1; // get(double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Double2DParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get() const
        {

            if (!PyErr_Occurred()) {
                // get()const
                Double2DTuple* cppResult = new Double2DTuple(const_cast<const ::Double2DParamWrapper*>(cppSelf)->get());
                pyResult = Shiboken::Object::newObject((SbkObjectType*)SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX], cppResult, true, true);
            }
            break;
        }
        case 1: // get(double frame) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(double)const
                Double2DTuple* cppResult = new Double2DTuple(const_cast<const ::Double2DParamWrapper*>(cppSelf)->get(cppArg0));
                pyResult = Shiboken::Object::newObject((SbkObjectType*)SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX], cppResult, true, true);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Double2DParamFunc_get_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Double2DParam.get");
#else
        const char* overloads[] = {"", "float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Double2DParam.get", overloads);
#endif
        return 0;
}

static PyObject* Sbk_Double2DParamFunc_set(PyObject* self, PyObject* args)
{
    Double2DParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (Double2DParamWrapper*)((::Double2DParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "set", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: set(double,double)
    // 1: set(double,double,double)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // set(double,double)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
            overloadId = 1; // set(double,double,double)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Double2DParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(double x, double y)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(double,double)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
        case 1: // set(double x, double y, double frame)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // set(double,double,double)
                cppSelf->set(cppArg0, cppArg1, cppArg2);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Double2DParamFunc_set_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Double2DParam.set");
#else
        const char* overloads[] = {"float, float", "float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Double2DParam.set", overloads);
#endif
        return 0;
}

static PyObject* Sbk_Double2DParamFunc_setCanAutoFoldDimensions(PyObject* self, PyObject* pyArg)
{
    Double2DParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (Double2DParamWrapper*)((::Double2DParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCanAutoFoldDimensions(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCanAutoFoldDimensions(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Double2DParamFunc_setCanAutoFoldDimensions_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCanAutoFoldDimensions(bool)
            cppSelf->setCanAutoFoldDimensions(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Double2DParamFunc_setCanAutoFoldDimensions_TypeError:
 #if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Double2DParam.setCanAutoFoldDimensions");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Double2DParam.setCanAutoFoldDimensions", overloads);
#endif
        return 0;
}

static PyObject* Sbk_Double2DParamFunc_setUsePointInteract(PyObject* self, PyObject* pyArg)
{
    Double2DParamWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (Double2DParamWrapper*)((::Double2DParam*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUsePointInteract(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setUsePointInteract(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Double2DParamFunc_setUsePointInteract_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUsePointInteract(bool)
            cppSelf->setUsePointInteract(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Double2DParamFunc_setUsePointInteract_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Double2DParam.setUsePointInteract");
#else
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Double2DParam.setUsePointInteract", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_Double2DParam_methods[] = {
    {"get", (PyCFunction)Sbk_Double2DParamFunc_get, METH_VARARGS},
    {"set", (PyCFunction)Sbk_Double2DParamFunc_set, METH_VARARGS},
    {"setCanAutoFoldDimensions", (PyCFunction)Sbk_Double2DParamFunc_setCanAutoFoldDimensions, METH_O},
    {"setUsePointInteract", (PyCFunction)Sbk_Double2DParamFunc_setUsePointInteract, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Double2DParam_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_Double2DParam_clear(PyObject* self)
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
static SbkObjectType *_Sbk_Double2DParam_Type = nullptr;
static SbkObjectType *Sbk_Double2DParam_TypeF(void)
{
    return _Sbk_Double2DParam_Type;
}

static PyType_Slot Sbk_Double2DParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Double2DParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Double2DParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Double2DParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Double2DParam_spec = {
    "NatronEngine.Double2DParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Double2DParam_slots
};
#else
static SbkObjectType Sbk_Double2DParam_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Double2DParam",
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
    /*tp_traverse*/         Sbk_Double2DParam_traverse,
    /*tp_clear*/            Sbk_Double2DParam_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Double2DParam_methods,
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

static void* Sbk_Double2DParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::Double2DParam*>(reinterpret_cast< ::Param*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Double2DParam_PythonToCpp_Double2DParam_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_Double2DParam_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Double2DParam_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_Double2DParam_PythonToCpp_Double2DParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Double2DParam_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Double2DParam_Type))
#endif
        return Double2DParam_PythonToCpp_Double2DParam_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Double2DParam_PTR_CppToPython_Double2DParam(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Double2DParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Double2DParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::Double2DParam*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Double2DParam_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Double2DParam_SignatureStrings[] = {
    "0:NatronEngine.Double2DParam.get()->NatronEngine.Double2DTuple",
    "1:NatronEngine.Double2DParam.get(frame:double)->NatronEngine.Double2DTuple",
    "0:NatronEngine.Double2DParam.set(x:double,y:double)",
    "1:NatronEngine.Double2DParam.set(x:double,y:double,frame:double)",
    "NatronEngine.Double2DParam.setCanAutoFoldDimensions(can:bool)",
    "NatronEngine.Double2DParam.setUsePointInteract(use:bool)",
    nullptr}; // Sentinel
#endif

void init_Double2DParam(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_Double2DParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Double2DParam",
        "Double2DParam*",
        &Sbk_Double2DParam_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        Double2DParam_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::Double2DParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Double2DParam_TypeF());
#else
    SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Double2DParam_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Double2DParam", "Double2DParam*",
        &Sbk_Double2DParam_Type, &Shiboken::callCppDestructor< ::Double2DParam >, (SbkObjectType*)SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Double2DParam_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Double2DParam_Type,
#endif
        Double2DParam_PythonToCpp_Double2DParam_PTR,
        is_Double2DParam_PythonToCpp_Double2DParam_PTR_Convertible,
        Double2DParam_PTR_CppToPython_Double2DParam);

    Shiboken::Conversions::registerConverterName(converter, "Double2DParam");
    Shiboken::Conversions::registerConverterName(converter, "Double2DParam*");
    Shiboken::Conversions::registerConverterName(converter, "Double2DParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Double2DParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::Double2DParamWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Double2DParam_TypeF(), &Sbk_Double2DParam_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_Double2DParam_Type, &Sbk_Double2DParam_typeDiscovery);
#endif


    Double2DParamWrapper::pysideInitQtMetaTypes();
}
