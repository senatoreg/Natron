
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

#include "pycoreapplication_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyAppInstance.h>


// Native ---------------------------------------------------------

void PyCoreApplicationWrapper::pysideInitQtMetaTypes()
{
}

PyCoreApplicationWrapper::PyCoreApplicationWrapper() : PyCoreApplication() {
    // ... middle
}

PyCoreApplicationWrapper::~PyCoreApplicationWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_PyCoreApplication_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::PyCoreApplication >()))
        return -1;

    ::PyCoreApplicationWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyCoreApplication()
            cptr = new ::PyCoreApplicationWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::PyCoreApplication >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_PyCoreApplicationFunc_appendToNatronPath(PyObject* self, PyObject* pyArg)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendToNatronPath(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // appendToNatronPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyCoreApplicationFunc_appendToNatronPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendToNatronPath(QString)
            cppSelf->appendToNatronPath(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyCoreApplicationFunc_appendToNatronPath_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.appendToNatronPath");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.appendToNatronPath", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyCoreApplicationFunc_getActiveInstance(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getActiveInstance()const
            App * cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getActiveInstance();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_APP_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getBuildNumber(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getBuildNumber()const
            int cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getBuildNumber();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getInstance(PyObject* self, PyObject* pyArg)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getInstance(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getInstance(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyCoreApplicationFunc_getInstance_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getInstance(int)const
            App * cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getInstance(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_APP_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PyCoreApplicationFunc_getInstance_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.getInstance");
#else
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.getInstance", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyCoreApplicationFunc_getNatronDevelopmentStatus(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronDevelopmentStatus()const
            QString cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNatronDevelopmentStatus();
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

static PyObject* Sbk_PyCoreApplicationFunc_getNatronPath(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronPath()const
            QStringList cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNatronPath();
#if SHIBOKEN_MAJOR_VERSION >= 2
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#else
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#endif
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getNatronVersionEncoded(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionEncoded()const
            int cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNatronVersionEncoded();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getNatronVersionMajor(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionMajor()const
            int cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNatronVersionMajor();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getNatronVersionMinor(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionMinor()const
            int cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNatronVersionMinor();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getNatronVersionRevision(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionRevision()const
            int cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNatronVersionRevision();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getNatronVersionString(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionString()const
            QString cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNatronVersionString();
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

static PyObject* Sbk_PyCoreApplicationFunc_getNumCpus(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumCpus()const
            int cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNumCpus();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getNumInstances(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumInstances()const
            int cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getNumInstances();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_getPluginIDs(PyObject* self, PyObject* args)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getPluginIDs", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: getPluginIDs()const
    // 1: getPluginIDs(QString)const
    if (numArgs == 0) {
        overloadId = 0; // getPluginIDs()const
    } else if (numArgs == 1
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
#endif
        overloadId = 1; // getPluginIDs(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyCoreApplicationFunc_getPluginIDs_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // getPluginIDs() const
        {

            if (!PyErr_Occurred()) {
                // getPluginIDs()const
                QStringList cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getPluginIDs();
#if SHIBOKEN_MAJOR_VERSION >= 2
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#else
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#endif
            }
            break;
        }
        case 1: // getPluginIDs(const QString & filter) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // getPluginIDs(QString)const
                QStringList cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getPluginIDs(cppArg0);
#if SHIBOKEN_MAJOR_VERSION >= 2
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#else
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
#endif
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PyCoreApplicationFunc_getPluginIDs_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.PyCoreApplication.getPluginIDs");
#else
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.PyCoreApplication.getPluginIDs", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyCoreApplicationFunc_getSettings(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getSettings()const
            AppSettings * cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->getSettings();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_APPSETTINGS_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_is64Bit(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // is64Bit()const
            bool cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->is64Bit();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_isBackground(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isBackground()const
            bool cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->isBackground();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_isLinux(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLinux()const
            bool cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->isLinux();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_isMacOSX(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isMacOSX()const
            bool cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->isMacOSX();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_isUnix(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUnix()const
            bool cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->isUnix();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_isWindows(PyObject* self)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWindows()const
            bool cppResult = const_cast<const ::PyCoreApplication*>(cppSelf)->isWindows();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PyCoreApplicationFunc_setOnProjectCreatedCallback(PyObject* self, PyObject* pyArg)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOnProjectCreatedCallback(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setOnProjectCreatedCallback(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyCoreApplicationFunc_setOnProjectCreatedCallback_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOnProjectCreatedCallback(QString)
            cppSelf->setOnProjectCreatedCallback(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyCoreApplicationFunc_setOnProjectCreatedCallback_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.setOnProjectCreatedCallback");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.setOnProjectCreatedCallback", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyCoreApplicationFunc_setOnProjectLoadedCallback(PyObject* self, PyObject* pyArg)
{
    ::PyCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::PyCoreApplication*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOnProjectLoadedCallback(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setOnProjectLoadedCallback(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyCoreApplicationFunc_setOnProjectLoadedCallback_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOnProjectLoadedCallback(QString)
            cppSelf->setOnProjectLoadedCallback(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyCoreApplicationFunc_setOnProjectLoadedCallback_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.setOnProjectLoadedCallback");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.PyCoreApplication.setOnProjectLoadedCallback", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_PyCoreApplication_methods[] = {
    {"appendToNatronPath", (PyCFunction)Sbk_PyCoreApplicationFunc_appendToNatronPath, METH_O},
    {"getActiveInstance", (PyCFunction)Sbk_PyCoreApplicationFunc_getActiveInstance, METH_NOARGS},
    {"getBuildNumber", (PyCFunction)Sbk_PyCoreApplicationFunc_getBuildNumber, METH_NOARGS},
    {"getInstance", (PyCFunction)Sbk_PyCoreApplicationFunc_getInstance, METH_O},
    {"getNatronDevelopmentStatus", (PyCFunction)Sbk_PyCoreApplicationFunc_getNatronDevelopmentStatus, METH_NOARGS},
    {"getNatronPath", (PyCFunction)Sbk_PyCoreApplicationFunc_getNatronPath, METH_NOARGS},
    {"getNatronVersionEncoded", (PyCFunction)Sbk_PyCoreApplicationFunc_getNatronVersionEncoded, METH_NOARGS},
    {"getNatronVersionMajor", (PyCFunction)Sbk_PyCoreApplicationFunc_getNatronVersionMajor, METH_NOARGS},
    {"getNatronVersionMinor", (PyCFunction)Sbk_PyCoreApplicationFunc_getNatronVersionMinor, METH_NOARGS},
    {"getNatronVersionRevision", (PyCFunction)Sbk_PyCoreApplicationFunc_getNatronVersionRevision, METH_NOARGS},
    {"getNatronVersionString", (PyCFunction)Sbk_PyCoreApplicationFunc_getNatronVersionString, METH_NOARGS},
    {"getNumCpus", (PyCFunction)Sbk_PyCoreApplicationFunc_getNumCpus, METH_NOARGS},
    {"getNumInstances", (PyCFunction)Sbk_PyCoreApplicationFunc_getNumInstances, METH_NOARGS},
    {"getPluginIDs", (PyCFunction)Sbk_PyCoreApplicationFunc_getPluginIDs, METH_VARARGS},
    {"getSettings", (PyCFunction)Sbk_PyCoreApplicationFunc_getSettings, METH_NOARGS},
    {"is64Bit", (PyCFunction)Sbk_PyCoreApplicationFunc_is64Bit, METH_NOARGS},
    {"isBackground", (PyCFunction)Sbk_PyCoreApplicationFunc_isBackground, METH_NOARGS},
    {"isLinux", (PyCFunction)Sbk_PyCoreApplicationFunc_isLinux, METH_NOARGS},
    {"isMacOSX", (PyCFunction)Sbk_PyCoreApplicationFunc_isMacOSX, METH_NOARGS},
    {"isUnix", (PyCFunction)Sbk_PyCoreApplicationFunc_isUnix, METH_NOARGS},
    {"isWindows", (PyCFunction)Sbk_PyCoreApplicationFunc_isWindows, METH_NOARGS},
    {"setOnProjectCreatedCallback", (PyCFunction)Sbk_PyCoreApplicationFunc_setOnProjectCreatedCallback, METH_O},
    {"setOnProjectLoadedCallback", (PyCFunction)Sbk_PyCoreApplicationFunc_setOnProjectLoadedCallback, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_PyCoreApplication_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_PyCoreApplication_clear(PyObject* self)
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
static SbkObjectType *_Sbk_PyCoreApplication_Type = nullptr;
static SbkObjectType *Sbk_PyCoreApplication_TypeF(void)
{
    return _Sbk_PyCoreApplication_Type;
}

static PyType_Slot Sbk_PyCoreApplication_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_PyCoreApplication_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_PyCoreApplication_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_PyCoreApplication_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_PyCoreApplication_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_PyCoreApplication_spec = {
    "NatronEngine.PyCoreApplication",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_PyCoreApplication_slots
};
#else
static SbkObjectType Sbk_PyCoreApplication_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.PyCoreApplication",
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
    /*tp_traverse*/         Sbk_PyCoreApplication_traverse,
    /*tp_clear*/            Sbk_PyCoreApplication_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_PyCoreApplication_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_PyCoreApplication_Init,
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
static void PyCoreApplication_PythonToCpp_PyCoreApplication_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_PyCoreApplication_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_PyCoreApplication_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_PyCoreApplication_PythonToCpp_PyCoreApplication_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_PyCoreApplication_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_PyCoreApplication_Type))
#endif
        return PyCoreApplication_PythonToCpp_PyCoreApplication_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyCoreApplication_PTR_CppToPython_PyCoreApplication(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::PyCoreApplication *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_PyCoreApplication_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    const char* typeName = typeid(*((::PyCoreApplication*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_PyCoreApplication_Type, const_cast<void*>(cppIn), false, false, typeName);
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *PyCoreApplication_SignatureStrings[] = {
    "NatronEngine.PyCoreApplication()",
    "NatronEngine.PyCoreApplication.appendToNatronPath(path:QString)",
    "NatronEngine.PyCoreApplication.getActiveInstance()->NatronEngine.App",
    "NatronEngine.PyCoreApplication.getBuildNumber()->int",
    "NatronEngine.PyCoreApplication.getInstance(idx:int)->NatronEngine.App",
    "NatronEngine.PyCoreApplication.getNatronDevelopmentStatus()->QString",
    "NatronEngine.PyCoreApplication.getNatronPath()->QStringList",
    "NatronEngine.PyCoreApplication.getNatronVersionEncoded()->int",
    "NatronEngine.PyCoreApplication.getNatronVersionMajor()->int",
    "NatronEngine.PyCoreApplication.getNatronVersionMinor()->int",
    "NatronEngine.PyCoreApplication.getNatronVersionRevision()->int",
    "NatronEngine.PyCoreApplication.getNatronVersionString()->QString",
    "NatronEngine.PyCoreApplication.getNumCpus()->int",
    "NatronEngine.PyCoreApplication.getNumInstances()->int",
    "0:NatronEngine.PyCoreApplication.getPluginIDs()->QStringList",
    "1:NatronEngine.PyCoreApplication.getPluginIDs(filter:QString)->QStringList",
    "NatronEngine.PyCoreApplication.getSettings()->NatronEngine.AppSettings",
    "NatronEngine.PyCoreApplication.is64Bit()->bool",
    "NatronEngine.PyCoreApplication.isBackground()->bool",
    "NatronEngine.PyCoreApplication.isLinux()->bool",
    "NatronEngine.PyCoreApplication.isMacOSX()->bool",
    "NatronEngine.PyCoreApplication.isUnix()->bool",
    "NatronEngine.PyCoreApplication.isWindows()->bool",
    "NatronEngine.PyCoreApplication.setOnProjectCreatedCallback(pythonFunctionName:QString)",
    "NatronEngine.PyCoreApplication.setOnProjectLoadedCallback(pythonFunctionName:QString)",
    nullptr}; // Sentinel
#endif

void init_PyCoreApplication(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    _Sbk_PyCoreApplication_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyCoreApplication",
        "PyCoreApplication*",
        &Sbk_PyCoreApplication_spec,
        PyCoreApplication_SignatureStrings,
        &Shiboken::callCppDestructor< ::PyCoreApplication >,
        0,
        0,
        0    );

    SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_PyCoreApplication_TypeF());
#else
    SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_PyCoreApplication_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "PyCoreApplication", "PyCoreApplication*",
        &Sbk_PyCoreApplication_Type, &Shiboken::callCppDestructor< ::PyCoreApplication >)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_PyCoreApplication_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_PyCoreApplication_Type,
#endif
        PyCoreApplication_PythonToCpp_PyCoreApplication_PTR,
        is_PyCoreApplication_PythonToCpp_PyCoreApplication_PTR_Convertible,
        PyCoreApplication_PTR_CppToPython_PyCoreApplication);

    Shiboken::Conversions::registerConverterName(converter, "PyCoreApplication");
    Shiboken::Conversions::registerConverterName(converter, "PyCoreApplication*");
    Shiboken::Conversions::registerConverterName(converter, "PyCoreApplication&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyCoreApplication).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyCoreApplicationWrapper).name());



    PyCoreApplicationWrapper::pysideInitQtMetaTypes();
}
