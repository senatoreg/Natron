
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

#include "double3dtuple_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Double3DTuple_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Double3DTuple >()))
        return -1;

    ::Double3DTuple* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // Double3DTuple()
            cptr = new ::Double3DTuple();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Double3DTuple >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_Double3DTuple_methods[] = {

    {0} // Sentinel
};

PyObject* Sbk_Double3DTupleFunc___getitem__(PyObject* self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Double3DTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Double3DTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i < 0 || _i >= 3) {
    PyErr_BadArgument();
    return 0;
    } else {
    double ret;
    switch (_i) {
    case 0:
    ret = cppSelf->x;
    break;
    case 1:
    ret = cppSelf->y;
    break;
    case 2:
    ret = cppSelf->z;
    break;
    }
    return  Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
    }

    // End of code injection
}

static PyObject* Sbk_Double3DTuple_get_x(PyObject* self, void*)
{
    ::Double3DTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Double3DTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_Double3DTuple_set_x(PyObject* self, PyObject* pyIn, void*)
{
    ::Double3DTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Double3DTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'x' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->x;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Double3DTuple_get_y(PyObject* self, void*)
{
    ::Double3DTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Double3DTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_Double3DTuple_set_y(PyObject* self, PyObject* pyIn, void*)
{
    ::Double3DTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Double3DTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'y' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->y;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Double3DTuple_get_z(PyObject* self, void*)
{
    ::Double3DTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Double3DTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->z);
    return pyOut;
}
static int Sbk_Double3DTuple_set_z(PyObject* self, PyObject* pyIn, void*)
{
    ::Double3DTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Double3DTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'z' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'z', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->z;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for Double3DTuple
static PyGetSetDef Sbk_Double3DTuple_getsetlist[] = {
    {const_cast<char*>("x"), Sbk_Double3DTuple_get_x, Sbk_Double3DTuple_set_x},
    {const_cast<char*>("y"), Sbk_Double3DTuple_get_y, Sbk_Double3DTuple_set_y},
    {const_cast<char*>("z"), Sbk_Double3DTuple_get_z, Sbk_Double3DTuple_set_z},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_Double3DTuple_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_Double3DTuple_clear(PyObject* self)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
#endif
}
// Class Definition -----------------------------------------------
extern "C" {
static PySequenceMethods Sbk_Double3DTuple_TypeAsSequence;

#if SHIBOKEN_MAJOR_VERSION >= 2
static SbkObjectType *_Sbk_Double3DTuple_Type = nullptr;
static SbkObjectType *Sbk_Double3DTuple_TypeF(void)
{
    return _Sbk_Double3DTuple_Type;
}

static PyType_Slot Sbk_Double3DTuple_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Double3DTuple_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Double3DTuple_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Double3DTuple_methods)},
    {Py_tp_getset,      reinterpret_cast<void*>(Sbk_Double3DTuple_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Double3DTuple_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    // type supports sequence protocol
    {Py_sq_item, (void *)&Sbk_Double3DTupleFunc___getitem__},
    {0, nullptr}
};
static PyType_Spec Sbk_Double3DTuple_spec = {
    "NatronEngine.Double3DTuple",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Double3DTuple_slots
};
#else
static SbkObjectType Sbk_Double3DTuple_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Double3DTuple",
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
    /*tp_traverse*/         Sbk_Double3DTuple_traverse,
    /*tp_clear*/            Sbk_Double3DTuple_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Double3DTuple_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_Double3DTuple_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Double3DTuple_Init,
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Double3DTuple_PythonToCpp_Double3DTuple_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_Double3DTuple_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Double3DTuple_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_Double3DTuple_PythonToCpp_Double3DTuple_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Double3DTuple_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Double3DTuple_Type))
#endif
        return Double3DTuple_PythonToCpp_Double3DTuple_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Double3DTuple_PTR_CppToPython_Double3DTuple(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Double3DTuple *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Double3DTuple_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::Double3DTuple*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Double3DTuple_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Double3DTuple_SignatureStrings[] = {
    "NatronEngine.Double3DTuple()",
    nullptr}; // Sentinel
#endif

void init_Double3DTuple(PyObject* module)
{
    // type supports sequence protocol
    memset(&Sbk_Double3DTuple_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_Double3DTuple_TypeAsSequence.sq_item = &Sbk_Double3DTupleFunc___getitem__;
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_Double3DTuple_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Double3DTuple",
        "Double3DTuple*",
        &Sbk_Double3DTuple_spec,
        Double3DTuple_SignatureStrings,
        &Shiboken::callCppDestructor< ::Double3DTuple >,
        0,
        0,
        0    );

    reinterpret_cast<PyTypeObject*>(Sbk_Double3DTuple_TypeF())->tp_as_sequence = &Sbk_Double3DTuple_TypeAsSequence;

    SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Double3DTuple_TypeF());
#else
    Sbk_Double3DTuple_Type.super.ht_type.tp_as_sequence = &Sbk_Double3DTuple_TypeAsSequence;

    SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Double3DTuple_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Double3DTuple", "Double3DTuple*",
        &Sbk_Double3DTuple_Type, &Shiboken::callCppDestructor< ::Double3DTuple >)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Double3DTuple_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Double3DTuple_Type,
#endif
        Double3DTuple_PythonToCpp_Double3DTuple_PTR,
        is_Double3DTuple_PythonToCpp_Double3DTuple_PTR_Convertible,
        Double3DTuple_PTR_CppToPython_Double3DTuple);

    Shiboken::Conversions::registerConverterName(converter, "Double3DTuple");
    Shiboken::Conversions::registerConverterName(converter, "Double3DTuple*");
    Shiboken::Conversions::registerConverterName(converter, "Double3DTuple&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Double3DTuple).name());



}
