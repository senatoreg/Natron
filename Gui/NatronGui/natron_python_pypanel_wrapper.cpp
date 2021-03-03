
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
#include <algorithm>
#include <set>
#include <iterator>

// module include
#include "natrongui_python.h"

// main header
#include "natron_python_pypanel_wrapper.h"

// inner classes

#include <cctype>
#include <cstring>

using namespace Natron;



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

// Native ---------------------------------------------------------

void PyPanelWrapper::pysideInitQtMetaTypes()
{
}

void PyPanelWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

PyPanelWrapper::PyPanelWrapper(const QString & scriptName, const QString & label, bool useUserParameters, Natron::Python::GuiApp * app) : Natron::Python::PyPanel(scriptName, label, useUserParameters, app)
{
    resetPyMethodCache();
    // ... middle
}

void PyPanelWrapper::enterEvent(QEvent * e)
{
    if (m_PyMethodCache[0]) {
        return this->::Natron::Python::PyPanel::enterEvent(e);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "enterEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
    if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[0] = true;
        return this->::Natron::Python::PyPanel::enterEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), e)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void PyPanelWrapper::keyPressEvent(QKeyEvent * e)
{
    if (m_PyMethodCache[1]) {
        return this->::Natron::Python::PyPanel::keyPressEvent(e);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "keyPressEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
    if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[1] = true;
        return this->::Natron::Python::PyPanel::keyPressEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX]), e)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void PyPanelWrapper::leaveEvent(QEvent * e)
{
    if (m_PyMethodCache[2]) {
        return this->::Natron::Python::PyPanel::leaveEvent(e);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "leaveEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
    if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[2] = true;
        return this->::Natron::Python::PyPanel::leaveEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), e)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void PyPanelWrapper::mousePressEvent(QMouseEvent * e)
{
    if (m_PyMethodCache[3]) {
        return this->::Natron::Python::PyPanel::mousePressEvent(e);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "mousePressEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
    if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[3] = true;
        return this->::Natron::Python::PyPanel::mousePressEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), e)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void PyPanelWrapper::restore(const QString & arg__1)
{
    if (m_PyMethodCache[4]) {
        return this->::Natron::Python::PyPanel::restore(arg__1);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "restore";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
    if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[4] = true;
        return this->::Natron::Python::PyPanel::restore(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

QString PyPanelWrapper::save()
{
    if (m_PyMethodCache[5])
        return this->::Natron::Python::PyPanel::save();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    static PyObject *nameCache[2] = {};
    static const char *funcName = "save";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
    if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[5] = true;
        return this->::Natron::Python::PyPanel::save();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.save", "QString", Py_TYPE(pyResult)->tp_name);
        return ::QString();
    }
    ::QString cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

PyPanelWrapper::~PyPanelWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_PyPanel_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    SbkObjectType *type = reinterpret_cast<SbkObjectType *>(self->ob_type);
    SbkObjectType *myType = reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]);
    if (type != myType)
        Shiboken::ObjectType::copyMultipleInheritance(type, myType);

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::PyPanel >()))
        return -1;

    ::PyPanelWrapper *cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "PyPanel", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: PyPanel::PyPanel(QString,QString,bool,Natron::Python::GuiApp*)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX]), (pyArgs[3])))) {
        overloadId = 0; // PyPanel(QString,QString,bool,Natron::Python::GuiApp*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanel_Init_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return -1;
        ::Natron::Python::GuiApp *cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // PyPanel(QString,QString,bool,Natron::Python::GuiApp*)
            cptr = new ::PyPanelWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::PyPanel >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Natron_Python_PyPanel_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Natron_Python_PyPanel_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyPanel");
        return -1;
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_enterEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::enterEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // enterEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_enterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // enterEvent(QEvent*)
            static_cast<::PyPanelWrapper *>(cppSelf)->PyPanelWrapper::enterEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyPanelFunc_enterEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.enterEvent");
        return {};
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_getPanelLabel(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPanelLabel()const
            QString cppResult = const_cast<const ::PyPanelWrapper *>(cppSelf)->getPanelLabel();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_getPanelScriptName(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPanelScriptName()const
            QString cppResult = const_cast<const ::PyPanelWrapper *>(cppSelf)->getPanelScriptName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_getParam(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::getParam(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getParam(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_getParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getParam(QString)const
            Natron::Python::Param * cppResult = const_cast<const ::PyPanelWrapper *>(cppSelf)->getParam(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyPanelFunc_getParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.getParam");
        return {};
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_getParams(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParams()const
            // Begin code injection
            std::list<Natron::Python::Param*> params = cppSelf->getParams();
            PyObject* ret = PyList_New((int) params.size());
            int idx = 0;
            for (std::list<Natron::Python::Param*>::iterator it = params.begin(); it!=params.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), *it);
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
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_keyPressEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QKeyEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            static_cast<::PyPanelWrapper *>(cppSelf)->PyPanelWrapper::keyPressEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyPanelFunc_keyPressEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.keyPressEvent");
        return {};
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_leaveEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::leaveEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // leaveEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_leaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // leaveEvent(QEvent*)
            static_cast<::PyPanelWrapper *>(cppSelf)->PyPanelWrapper::leaveEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyPanelFunc_leaveEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.leaveEvent");
        return {};
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_mousePressEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QMouseEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            static_cast<::PyPanelWrapper *>(cppSelf)->PyPanelWrapper::mousePressEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyPanelFunc_mousePressEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.mousePressEvent");
        return {};
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_onUserDataChanged(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onUserDataChanged()
            static_cast<::PyPanelWrapper *>(cppSelf)->PyPanelWrapper::onUserDataChanged_protected();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_restore(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::restore(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // restore(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_restore_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // restore(QString)
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject *>(self))
                ? cppSelf->::Natron::Python::PyPanel::restore(cppArg0)
                : cppSelf->restore(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyPanelFunc_restore_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.restore");
        return {};
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_save(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // save()
            QString cppResult = static_cast<::PyPanelWrapper *>(cppSelf)->PyPanelWrapper::save_protected();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_setPanelLabel(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::setPanelLabel(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPanelLabel(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_setPanelLabel_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPanelLabel(QString)
            cppSelf->setPanelLabel(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyPanelFunc_setPanelLabel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.setPanelLabel");
        return {};
}

static PyObject *Sbk_Natron_Python_PyPanelFunc_setParamChangedCallback(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<PyPanelWrapper *>(reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyPanel::setParamChangedCallback(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setParamChangedCallback(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyPanelFunc_setParamChangedCallback_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setParamChangedCallback(QString)
            cppSelf->setParamChangedCallback(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyPanelFunc_setParamChangedCallback_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.setParamChangedCallback");
        return {};
}


static const char *Sbk_Natron_Python_PyPanel_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_PyPanel_methods[] = {
    {"enterEvent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_enterEvent), METH_O},
    {"getPanelLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_getPanelLabel), METH_NOARGS},
    {"getPanelScriptName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_getPanelScriptName), METH_NOARGS},
    {"getParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_getParam), METH_O},
    {"getParams", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_getParams), METH_NOARGS},
    {"keyPressEvent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_keyPressEvent), METH_O},
    {"leaveEvent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_leaveEvent), METH_O},
    {"mousePressEvent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_mousePressEvent), METH_O},
    {"onUserDataChanged", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_onUserDataChanged), METH_NOARGS},
    {"restore", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_restore), METH_O},
    {"save", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_save), METH_NOARGS},
    {"setPanelLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_setPanelLabel), METH_O},
    {"setParamChangedCallback", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyPanelFunc_setParamChangedCallback), METH_O},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_PyPanel_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::PyPanel *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<PyPanelWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_PyPanel_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyPanel_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
static int mi_offsets[] = { -1, -1, -1 };
int *
Sbk_Natron_Python_PyPanel_mi_init(const void *cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        const auto *class_ptr = reinterpret_cast<const Natron::Python::PyPanel *>(cptr);
        const auto base = reinterpret_cast<uintptr_t>(class_ptr);
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::UserParamHolder *>(class_ptr)) - base));
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::UserParamHolder *>(static_cast<const Natron::Python::PyPanel *>(static_cast<const void *>(class_ptr)))) - base));

        offsets.erase(0);

        std::copy(offsets.cbegin(), offsets.cend(), mi_offsets);
    }
    return mi_offsets;
}
static void * Sbk_Natron_Python_PyPanelSpecialCastFunction(void *obj, SbkObjectType *desiredType)
{
    auto me = reinterpret_cast< ::Natron::Python::PyPanel *>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]))
        return static_cast< ::Natron::Python::UserParamHolder *>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyPanel_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyPanel_TypeF(void)
{
    return _Sbk_Natron_Python_PyPanel_Type;
}

static PyType_Slot Sbk_Natron_Python_PyPanel_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_PyPanel_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_PyPanel_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_PyPanel_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_PyPanel_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_Natron_Python_PyPanel_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyPanel_spec = {
    "1:NatronGui.PyPanel",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyPanel_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyPanel_PythonToCpp_PyPanel_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyPanel_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyPanel_PythonToCpp_PyPanel_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_PyPanel_TypeF())))
        return PyPanel_PythonToCpp_PyPanel_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *PyPanel_PTR_CppToPython_PyPanel(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyPanel *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyPanel_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyPanel_SignatureStrings[] = {
    "NatronGui.PyPanel(self,scriptName:QString,label:QString,useUserParameters:bool,app:NatronGui.GuiApp)",
    "NatronGui.PyPanel.enterEvent(self,e:PySide2.QtCore.QEvent)",
    "NatronGui.PyPanel.getPanelLabel(self)->QString",
    "NatronGui.PyPanel.getPanelScriptName(self)->QString",
    "NatronGui.PyPanel.getParam(self,scriptName:QString)->NatronEngine.Natron.Python.Param",
    "NatronGui.PyPanel.getParams(self)->std.list[NatronEngine.Natron.Python.Param]",
    "NatronGui.PyPanel.keyPressEvent(self,e:PySide2.QtGui.QKeyEvent)",
    "NatronGui.PyPanel.leaveEvent(self,e:PySide2.QtCore.QEvent)",
    "NatronGui.PyPanel.mousePressEvent(self,e:PySide2.QtGui.QMouseEvent)",
    "NatronGui.PyPanel.onUserDataChanged(self)",
    "NatronGui.PyPanel.restore(self,arg__1:QString)",
    "NatronGui.PyPanel.save(self)->QString",
    "NatronGui.PyPanel.setPanelLabel(self,label:QString)",
    "NatronGui.PyPanel.setParamChangedCallback(self,callback:QString)",
    nullptr}; // Sentinel

void init_Natron_Python_PyPanel(PyObject *module)
{
    PyObject *Sbk_Natron_Python_PyPanel_Type_bases = PyTuple_Pack(1,
        reinterpret_cast<PyObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]));

    _Sbk_Natron_Python_PyPanel_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyPanel",
        "Natron::Python::PyPanel*",
        &Sbk_Natron_Python_PyPanel_spec,
        &Shiboken::callCppDestructor< ::Natron::Python::PyPanel >,
        0,
        Sbk_Natron_Python_PyPanel_Type_bases,
        0    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_PyPanel_Type);
    InitSignatureStrings(pyType, Natron_Python_PyPanel_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_PyPanel_Type), Sbk_Natron_Python_PyPanel_PropertyStrings);
    SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_PyPanel_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyPanel_TypeF(),
        PyPanel_PythonToCpp_PyPanel_PTR,
        is_PyPanel_PythonToCpp_PyPanel_PTR_Convertible,
        PyPanel_PTR_CppToPython_PyPanel);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyPanel");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyPanel*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyPanel&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyPanel");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyPanel*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyPanel&");
    Shiboken::Conversions::registerConverterName(converter, "PyPanel");
    Shiboken::Conversions::registerConverterName(converter, "PyPanel*");
    Shiboken::Conversions::registerConverterName(converter, "PyPanel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyPanel).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyPanelWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_Natron_Python_PyPanel_mi_init;
    Shiboken::ObjectType::setMultipleInheritanceFunction(Sbk_Natron_Python_PyPanel_TypeF(), func);
    Shiboken::ObjectType::setCastFunction(Sbk_Natron_Python_PyPanel_TypeF(), &Sbk_Natron_Python_PyPanelSpecialCastFunction);

    PyPanelWrapper::pysideInitQtMetaTypes();
}
