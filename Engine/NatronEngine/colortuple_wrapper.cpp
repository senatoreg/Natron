
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

#include "colortuple_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_ColorTuple_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::ColorTuple >()))
        return -1;

    ::ColorTuple* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ColorTuple()
            cptr = new ::ColorTuple();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::ColorTuple >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_ColorTuple_methods[] = {

    {0} // Sentinel
};

PyObject* Sbk_ColorTupleFunc___getitem__(PyObject* self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i < 0 || _i >= 4) {
        PyErr_BadArgument();
        return 0;
    } else {
        double ret;
        switch (_i) {
        case 0:
            ret = cppSelf->r;
            break;
        case 1:
            ret = cppSelf->g;
            break;
        case 2:
            ret = cppSelf->b;
            break;
        case 3:
            ret = cppSelf->a;
            break;

        }
        return  Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
    }

    // End of code injection
}

static PyObject* Sbk_ColorTuple_get_g(PyObject* self, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->g);
    return pyOut;
}
static int Sbk_ColorTuple_set_g(PyObject* self, PyObject* pyIn, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'g' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'g', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->g;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_ColorTuple_get_r(PyObject* self, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->r);
    return pyOut;
}
static int Sbk_ColorTuple_set_r(PyObject* self, PyObject* pyIn, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'r' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'r', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->r;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_ColorTuple_get_a(PyObject* self, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->a);
    return pyOut;
}
static int Sbk_ColorTuple_set_a(PyObject* self, PyObject* pyIn, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'a' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'a', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->a;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_ColorTuple_get_b(PyObject* self, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->b);
    return pyOut;
}
static int Sbk_ColorTuple_set_b(PyObject* self, PyObject* pyIn, void*)
{
    ::ColorTuple* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::ColorTuple*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'b' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'b', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->b;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for ColorTuple
static PyGetSetDef Sbk_ColorTuple_getsetlist[] = {
    {const_cast<char*>("g"), Sbk_ColorTuple_get_g, Sbk_ColorTuple_set_g},
    {const_cast<char*>("r"), Sbk_ColorTuple_get_r, Sbk_ColorTuple_set_r},
    {const_cast<char*>("a"), Sbk_ColorTuple_get_a, Sbk_ColorTuple_set_a},
    {const_cast<char*>("b"), Sbk_ColorTuple_get_b, Sbk_ColorTuple_set_b},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_ColorTuple_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_ColorTuple_clear(PyObject* self)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
#endif
}
// Class Definition -----------------------------------------------
extern "C" {
static PySequenceMethods Sbk_ColorTuple_TypeAsSequence;

#if SHIBOKEN_MAJOR_VERSION >= 2
static SbkObjectType *_Sbk_ColorTuple_Type = nullptr;
static SbkObjectType *Sbk_ColorTuple_TypeF(void)
{
    return _Sbk_ColorTuple_Type;
}

static PyType_Slot Sbk_ColorTuple_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_ColorTuple_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_ColorTuple_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_ColorTuple_methods)},
    {Py_tp_getset,      reinterpret_cast<void*>(Sbk_ColorTuple_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_ColorTuple_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    // type supports sequence protocol
    {Py_sq_item, (void *)&Sbk_ColorTupleFunc___getitem__},
    {0, nullptr}
};
static PyType_Spec Sbk_ColorTuple_spec = {
    "NatronEngine.ColorTuple",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_ColorTuple_slots
};
#else
static SbkObjectType Sbk_ColorTuple_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.ColorTuple",
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
    /*tp_traverse*/         Sbk_ColorTuple_traverse,
    /*tp_clear*/            Sbk_ColorTuple_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_ColorTuple_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_ColorTuple_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_ColorTuple_Init,
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
static void ColorTuple_PythonToCpp_ColorTuple_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_ColorTuple_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_ColorTuple_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_ColorTuple_PythonToCpp_ColorTuple_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_ColorTuple_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_ColorTuple_Type))
#endif
        return ColorTuple_PythonToCpp_ColorTuple_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ColorTuple_PTR_CppToPython_ColorTuple(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::ColorTuple *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_ColorTuple_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::ColorTuple*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_ColorTuple_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *ColorTuple_SignatureStrings[] = {
    "NatronEngine.ColorTuple()",
    nullptr}; // Sentinel
#endif

void init_ColorTuple(PyObject* module)
{
    // type supports sequence protocol
    memset(&Sbk_ColorTuple_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_ColorTuple_TypeAsSequence.sq_item = &Sbk_ColorTupleFunc___getitem__;
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_ColorTuple_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ColorTuple",
        "ColorTuple*",
        &Sbk_ColorTuple_spec,
        ColorTuple_SignatureStrings,
        &Shiboken::callCppDestructor< ::ColorTuple >,
        0,
        0,
        0    );

    reinterpret_cast<PyTypeObject*>(Sbk_ColorTuple_TypeF())->tp_as_sequence = &Sbk_ColorTuple_TypeAsSequence;

    SbkNatronEngineTypes[SBK_COLORTUPLE_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_ColorTuple_TypeF());
#else
    Sbk_ColorTuple_Type.super.ht_type.tp_as_sequence = &Sbk_ColorTuple_TypeAsSequence;

    SbkNatronEngineTypes[SBK_COLORTUPLE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_ColorTuple_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "ColorTuple", "ColorTuple*",
        &Sbk_ColorTuple_Type, &Shiboken::callCppDestructor< ::ColorTuple >)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_ColorTuple_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_ColorTuple_Type,
#endif
        ColorTuple_PythonToCpp_ColorTuple_PTR,
        is_ColorTuple_PythonToCpp_ColorTuple_PTR_Convertible,
        ColorTuple_PTR_CppToPython_ColorTuple);

    Shiboken::Conversions::registerConverterName(converter, "ColorTuple");
    Shiboken::Conversions::registerConverterName(converter, "ColorTuple*");
    Shiboken::Conversions::registerConverterName(converter, "ColorTuple&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::ColorTuple).name());



}
