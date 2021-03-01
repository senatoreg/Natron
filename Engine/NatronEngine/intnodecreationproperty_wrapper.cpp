
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

#include "intnodecreationproperty_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <vector>


// Native ---------------------------------------------------------

void IntNodeCreationPropertyWrapper::pysideInitQtMetaTypes()
{
}

IntNodeCreationPropertyWrapper::IntNodeCreationPropertyWrapper(const std::vector<int > & values) : IntNodeCreationProperty(values) {
    // ... middle
}

IntNodeCreationPropertyWrapper::IntNodeCreationPropertyWrapper(int value) : IntNodeCreationProperty(value) {
    // ... middle
}

IntNodeCreationPropertyWrapper::~IntNodeCreationPropertyWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_IntNodeCreationProperty_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::IntNodeCreationProperty >()))
        return -1;

    ::IntNodeCreationPropertyWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.IntNodeCreationProperty(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:IntNodeCreationProperty", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: IntNodeCreationProperty(std::vector<int>)
    // 1: IntNodeCreationProperty(int)
    if (numArgs == 0) {
        overloadId = 0; // IntNodeCreationProperty(std::vector<int>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 1; // IntNodeCreationProperty(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_INT_IDX], (pyArgs[0])))) {
        overloadId = 0; // IntNodeCreationProperty(std::vector<int>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_IntNodeCreationProperty_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // IntNodeCreationProperty(const std::vector<int > & values)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "values");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.IntNodeCreationProperty(): got multiple values for keyword argument 'values'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_INT_IDX], (pyArgs[0]))))
                        goto Sbk_IntNodeCreationProperty_Init_TypeError;
                }
            }
            ::std::vector<int > cppArg0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // IntNodeCreationProperty(std::vector<int>)
                cptr = new ::IntNodeCreationPropertyWrapper(cppArg0);
            }
            break;
        }
        case 1: // IntNodeCreationProperty(int value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // IntNodeCreationProperty(int)
                cptr = new ::IntNodeCreationPropertyWrapper(cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::IntNodeCreationProperty >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_IntNodeCreationProperty_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_IntNodeCreationProperty_Init_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.IntNodeCreationProperty");
#else
        const char* overloads[] = {"list = std.vector< int >()", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.IntNodeCreationProperty", overloads);
#endif
        return -1;
}

static PyObject* Sbk_IntNodeCreationPropertyFunc_getValues(PyObject* self)
{
    ::IntNodeCreationProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::IntNodeCreationProperty*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_INTNODECREATIONPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValues()const
            const std::vector<int > & cppResult = const_cast<const ::IntNodeCreationProperty*>(cppSelf)->getValues();
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_IntNodeCreationPropertyFunc_setValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::IntNodeCreationProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::IntNodeCreationProperty*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_INTNODECREATIONPROPERTY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.IntNodeCreationProperty.setValue(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.IntNodeCreationProperty.setValue(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setValue", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setValue(int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setValue(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setValue(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_IntNodeCreationPropertyFunc_setValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "index");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.IntNodeCreationProperty.setValue(): got multiple values for keyword argument 'index'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_IntNodeCreationPropertyFunc_setValue_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValue(int,int)
            cppSelf->setValue(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_IntNodeCreationPropertyFunc_setValue_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.IntNodeCreationProperty.setValue");
#else
        const char* overloads[] = {"int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.IntNodeCreationProperty.setValue", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_IntNodeCreationProperty_methods[] = {
    {"getValues", (PyCFunction)Sbk_IntNodeCreationPropertyFunc_getValues, METH_NOARGS},
    {"setValue", (PyCFunction)Sbk_IntNodeCreationPropertyFunc_setValue, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_IntNodeCreationProperty_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_IntNodeCreationProperty_clear(PyObject* self)
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
static SbkObjectType *_Sbk_IntNodeCreationProperty_Type = nullptr;
static SbkObjectType *Sbk_IntNodeCreationProperty_TypeF(void)
{
    return _Sbk_IntNodeCreationProperty_Type;
}

static PyType_Slot Sbk_IntNodeCreationProperty_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_IntNodeCreationProperty_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_IntNodeCreationProperty_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_IntNodeCreationProperty_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_IntNodeCreationProperty_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_IntNodeCreationProperty_spec = {
    "NatronEngine.IntNodeCreationProperty",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_IntNodeCreationProperty_slots
};
#else
static SbkObjectType Sbk_IntNodeCreationProperty_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.IntNodeCreationProperty",
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_IntNodeCreationProperty_traverse,
    /*tp_clear*/            Sbk_IntNodeCreationProperty_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_IntNodeCreationProperty_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_IntNodeCreationProperty_Init,
    /*tp_alloc*/            0,
    /*tp_new*/              SbkObjectTpNew,
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

static void* Sbk_IntNodeCreationProperty_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::NodeCreationProperty >()))
        return dynamic_cast< ::IntNodeCreationProperty*>(reinterpret_cast< ::NodeCreationProperty*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void IntNodeCreationProperty_PythonToCpp_IntNodeCreationProperty_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_IntNodeCreationProperty_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_IntNodeCreationProperty_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_IntNodeCreationProperty_PythonToCpp_IntNodeCreationProperty_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_IntNodeCreationProperty_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_IntNodeCreationProperty_Type))
#endif
        return IntNodeCreationProperty_PythonToCpp_IntNodeCreationProperty_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* IntNodeCreationProperty_PTR_CppToPython_IntNodeCreationProperty(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::IntNodeCreationProperty *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_IntNodeCreationProperty_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::IntNodeCreationProperty*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_IntNodeCreationProperty_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *IntNodeCreationProperty_SignatureStrings[] = {
    "0:NatronEngine.IntNodeCreationProperty(values:QVector[int]=std.vector< int >())",
    "1:NatronEngine.IntNodeCreationProperty(value:int)",
    "NatronEngine.IntNodeCreationProperty.getValues()->QVector[int]=std.vctor< int >()",
    "NatronEngine.IntNodeCreationProperty.setValue(value:int,index:int=0)",
    nullptr}; // Sentinel
#endif

void init_IntNodeCreationProperty(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_IntNodeCreationProperty_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "IntNodeCreationProperty",
        "IntNodeCreationProperty*",
        &Sbk_IntNodeCreationProperty_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        IntNodeCreationProperty_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::IntNodeCreationProperty >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NODECREATIONPROPERTY_IDX]),
        0,
        0    );

    SbkNatronEngineTypes[SBK_INTNODECREATIONPROPERTY_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_IntNodeCreationProperty_TypeF());
#else
    SbkNatronEngineTypes[SBK_INTNODECREATIONPROPERTY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_IntNodeCreationProperty_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "IntNodeCreationProperty", "IntNodeCreationProperty*",
        &Sbk_IntNodeCreationProperty_Type, &Shiboken::callCppDestructor< ::IntNodeCreationProperty >, (SbkObjectType*)SbkNatronEngineTypes[SBK_NODECREATIONPROPERTY_IDX])) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_IntNodeCreationProperty_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_IntNodeCreationProperty_Type,
#endif
        IntNodeCreationProperty_PythonToCpp_IntNodeCreationProperty_PTR,
        is_IntNodeCreationProperty_PythonToCpp_IntNodeCreationProperty_PTR_Convertible,
        IntNodeCreationProperty_PTR_CppToPython_IntNodeCreationProperty);

    Shiboken::Conversions::registerConverterName(converter, "IntNodeCreationProperty");
    Shiboken::Conversions::registerConverterName(converter, "IntNodeCreationProperty*");
    Shiboken::Conversions::registerConverterName(converter, "IntNodeCreationProperty&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::IntNodeCreationProperty).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::IntNodeCreationPropertyWrapper).name());


#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_IntNodeCreationProperty_TypeF(), &Sbk_IntNodeCreationProperty_typeDiscovery);
#else
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_IntNodeCreationProperty_Type, &Sbk_IntNodeCreationProperty_typeDiscovery);
#endif


    IntNodeCreationPropertyWrapper::pysideInitQtMetaTypes();
}
