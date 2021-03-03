
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
#include "natrongui_python.h"

// main header
#include "natron_python_guiapp_wrapper.h"

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

void GuiAppWrapper::pysideInitQtMetaTypes()
{
}

void GuiAppWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

GuiAppWrapper::~GuiAppWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_Python_GuiAppFunc_clearSelection(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.clearSelection(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:clearSelection", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::clearSelection(Natron::Python::Group*)
    if (numArgs == 0) {
        overloadId = 0; // clearSelection(Natron::Python::Group*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[0])))) {
        overloadId = 0; // clearSelection(Natron::Python::Group*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_clearSelection_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","group");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.clearSelection(): got multiple values for keyword argument 'group'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[0]))))
                        goto Sbk_Natron_Python_GuiAppFunc_clearSelection_TypeError;
                }
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Group *cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // clearSelection(Natron::Python::Group*)
            cppSelf->clearSelection(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_clearSelection_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.clearSelection");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_createModalDialog(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createModalDialog()
            Natron::Python::PyModalDialog * cppResult = cppSelf->createModalDialog();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYMODALDIALOG_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_deselectNode(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GuiApp::deselectNode(Natron::Python::Effect*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArg)))) {
        overloadId = 0; // deselectNode(Natron::Python::Effect*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_deselectNode_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::Effect *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // deselectNode(Natron::Python::Effect*)
            cppSelf->deselectNode(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_deselectNode_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.deselectNode");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getActiveTabWidget(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getActiveTabWidget()const
            Natron::Python::PyTabWidget * cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getActiveTabWidget();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getActiveViewer(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getActiveViewer()const
            Natron::Python::PyViewer * cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getActiveViewer();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getDirectoryDialog(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getDirectoryDialog(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getDirectoryDialog", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::getDirectoryDialog(QString)const
    if (numArgs == 0) {
        overloadId = 0; // getDirectoryDialog(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // getDirectoryDialog(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_getDirectoryDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","location");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getDirectoryDialog(): got multiple values for keyword argument 'location'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_Natron_Python_GuiAppFunc_getDirectoryDialog_TypeError;
                }
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getDirectoryDialog(QString)const
            QString cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getDirectoryDialog(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_getDirectoryDialog_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getDirectoryDialog");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getFilenameDialog(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getFilenameDialog(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getFilenameDialog(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getFilenameDialog", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::getFilenameDialog(QStringList,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getFilenameDialog(QStringList,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getFilenameDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_getFilenameDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","location");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getFilenameDialog(): got multiple values for keyword argument 'location'.");
                    return {};
                }
                if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_GuiAppFunc_getFilenameDialog_TypeError;
                }
            }
        }
        ::QStringList cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getFilenameDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getFilenameDialog(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_getFilenameDialog_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getFilenameDialog");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getRGBColorDialog(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getRGBColorDialog()const
            Natron::Python::ColorTuple* cppResult = new Natron::Python::ColorTuple(const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getRGBColorDialog());
            pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORTUPLE_IDX]), cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getSelectedNodes(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSelectedNodes(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getSelectedNodes", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::getSelectedNodes(Natron::Python::Group*)const
    if (numArgs == 0) {
        overloadId = 0; // getSelectedNodes(Natron::Python::Group*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[0])))) {
        overloadId = 0; // getSelectedNodes(Natron::Python::Group*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_getSelectedNodes_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","group");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSelectedNodes(): got multiple values for keyword argument 'group'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[0]))))
                        goto Sbk_Natron_Python_GuiAppFunc_getSelectedNodes_TypeError;
                }
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Group *cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getSelectedNodes(Natron::Python::Group*)const
            // Begin code injection
            std::list<Natron::Python::Effect*> effects = cppSelf->getSelectedNodes(cppArg0);
            PyObject* ret = PyList_New((int) effects.size());
            int idx = 0;
            for (std::list<Natron::Python::Effect*>::iterator it = effects.begin(); it!=effects.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), *it);
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

    Sbk_Natron_Python_GuiAppFunc_getSelectedNodes_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getSelectedNodes");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getSequenceDialog(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSequenceDialog(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSequenceDialog(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getSequenceDialog", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::getSequenceDialog(QStringList,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getSequenceDialog(QStringList,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getSequenceDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_getSequenceDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","location");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.getSequenceDialog(): got multiple values for keyword argument 'location'.");
                    return {};
                }
                if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_GuiAppFunc_getSequenceDialog_TypeError;
                }
            }
        }
        ::QStringList cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getSequenceDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getSequenceDialog(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_getSequenceDialog_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.getSequenceDialog");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getTabWidget(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GuiApp::getTabWidget(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getTabWidget(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_getTabWidget_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getTabWidget(QString)const
            Natron::Python::PyTabWidget * cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getTabWidget(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_getTabWidget_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getTabWidget");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getUserPanel(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GuiApp::getUserPanel(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getUserPanel(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_getUserPanel_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getUserPanel(QString)const
            Natron::Python::PyPanel * cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getUserPanel(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_getUserPanel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getUserPanel");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_getViewer(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GuiApp::getViewer(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getViewer(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_getViewer_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewer(QString)const
            Natron::Python::PyViewer * cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->getViewer(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_getViewer_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.getViewer");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_moveTab(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "moveTab", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::moveTab(QString,Natron::Python::PyTabWidget*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX]), (pyArgs[1])))) {
        overloadId = 0; // moveTab(QString,Natron::Python::PyTabWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_moveTab_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::PyTabWidget *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // moveTab(QString,Natron::Python::PyTabWidget*)
            bool cppResult = cppSelf->moveTab(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_moveTab_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.moveTab");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_registerPythonPanel(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "registerPythonPanel", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::registerPythonPanel(Natron::Python::PyPanel*,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // registerPythonPanel(Natron::Python::PyPanel*,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_registerPythonPanel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::PyPanel *cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // registerPythonPanel(Natron::Python::PyPanel*,QString)
            cppSelf->registerPythonPanel(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_registerPythonPanel_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.registerPythonPanel");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_renderBlocking(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.renderBlocking(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.renderBlocking(): not enough arguments");
        return {};
    } else if (numArgs == 2)
        goto Sbk_Natron_Python_GuiAppFunc_renderBlocking_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:renderBlocking", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::renderBlocking(Natron::Python::Effect*,int,int,int)
    // 1: GuiApp::renderBlocking(std::list<Natron::Python::Effect*>,std::list<int>,std::list<int>,std::list<int>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // renderBlocking(Natron::Python::Effect*,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // renderBlocking(Natron::Python::Effect*,int,int,int)
        }
    } else if (numArgs == 1
        && PyList_Check(pyArgs[0])) {
        overloadId = 1; // renderBlocking(std::list<Natron::Python::Effect*>,std::list<int>,std::list<int>,std::list<int>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_renderBlocking_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // renderBlocking(Natron::Python::Effect * writeNode, int firstFrame, int lastFrame, int frameStep)
        {
            if (kwds) {
                PyObject *keyName = nullptr;
                PyObject *value = nullptr;
                keyName = Py_BuildValue("s","frameStep");
                if (PyDict_Contains(kwds, keyName)) {
                    value = PyDict_GetItem(kwds, keyName);
                    if (value && pyArgs[3]) {
                        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.renderBlocking(): got multiple values for keyword argument 'frameStep'.");
                        return {};
                    }
                    if (value) {
                        pyArgs[3] = value;
                        if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                            goto Sbk_Natron_Python_GuiAppFunc_renderBlocking_TypeError;
                    }
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::Python::Effect *cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // renderBlocking(Natron::Python::Effect*,int,int,int)
                cppSelf->renderBlocking(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
        case 1: // renderBlocking(const std::list<Natron::Python::Effect* > & effects, const std::list<int > & firstFrames, const std::list<int > & lastFrames, const std::list<int > & frameSteps)
        {

            if (!PyErr_Occurred()) {
                // renderBlocking(std::list<Natron::Python::Effect*>,std::list<int>,std::list<int>,std::list<int>)
                // Begin code injection
                if (!PyList_Check(pyArgs[1-1])) {
                PyErr_SetString(PyExc_TypeError, "tasks must be a list of tuple objects.");
                return 0;
                }
                std::list<Natron::Python::Effect*> effects;

                std::list<int> firstFrames;

                std::list<int> lastFrames;

                std::list<int> frameSteps;

                int size = (int)PyList_GET_SIZE(pyArgs[1-1]);
                for (int i = 0; i < size; ++i) {
                PyObject* tuple = PyList_GET_ITEM(pyArgs[1-1],i);
                if (!tuple) {
                PyErr_SetString(PyExc_TypeError, "tasks must be a list of tuple objects.");
                return 0;
                }

                int tupleSize = PyTuple_GET_SIZE(tuple);
                if (tupleSize != 4 && tupleSize != 3) {
                PyErr_SetString(PyExc_TypeError, "the tuple must have 3 or 4 items.");
                return 0;
                }
                ::Natron::Python::Effect* writeNode{nullptr};
                    Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), PyTuple_GET_ITEM(tuple, 0), &(writeNode));
                int firstFrame;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 1), &(firstFrame));
                int lastFrame;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 2), &(lastFrame));
                int frameStep;
                if (tupleSize == 4) {
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 3), &(frameStep));
                } else {
                frameStep = INT_MIN;
                }
                effects.push_back(writeNode);
                firstFrames.push_back(firstFrame);
                lastFrames.push_back(lastFrame);
                frameSteps.push_back(frameStep);
                }

                cppSelf->renderBlocking(effects,firstFrames,lastFrames, frameSteps);

                // End of code injection

            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_renderBlocking_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.renderBlocking");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_saveFilenameDialog(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveFilenameDialog(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveFilenameDialog(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:saveFilenameDialog", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::saveFilenameDialog(QStringList,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // saveFilenameDialog(QStringList,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // saveFilenameDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_saveFilenameDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","location");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveFilenameDialog(): got multiple values for keyword argument 'location'.");
                    return {};
                }
                if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_GuiAppFunc_saveFilenameDialog_TypeError;
                }
            }
        }
        ::QStringList cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // saveFilenameDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->saveFilenameDialog(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_saveFilenameDialog_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.saveFilenameDialog");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_saveSequenceDialog(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveSequenceDialog(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveSequenceDialog(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:saveSequenceDialog", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::saveSequenceDialog(QStringList,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // saveSequenceDialog(QStringList,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // saveSequenceDialog(QStringList,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_saveSequenceDialog_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","location");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.saveSequenceDialog(): got multiple values for keyword argument 'location'.");
                    return {};
                }
                if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_GuiAppFunc_saveSequenceDialog_TypeError;
                }
            }
        }
        ::QStringList cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // saveSequenceDialog(QStringList,QString)const
            QString cppResult = const_cast<const ::Natron::Python::GuiApp *>(cppSelf)->saveSequenceDialog(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_GuiAppFunc_saveSequenceDialog_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.saveSequenceDialog");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_selectAllNodes(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.selectAllNodes(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:selectAllNodes", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::selectAllNodes(Natron::Python::Group*)
    if (numArgs == 0) {
        overloadId = 0; // selectAllNodes(Natron::Python::Group*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[0])))) {
        overloadId = 0; // selectAllNodes(Natron::Python::Group*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_selectAllNodes_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","group");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.GuiApp.selectAllNodes(): got multiple values for keyword argument 'group'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[0]))))
                        goto Sbk_Natron_Python_GuiAppFunc_selectAllNodes_TypeError;
                }
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Group *cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // selectAllNodes(Natron::Python::Group*)
            cppSelf->selectAllNodes(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_selectAllNodes_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.selectAllNodes");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_selectNode(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "selectNode", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: GuiApp::selectNode(Natron::Python::Effect*,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // selectNode(Natron::Python::Effect*,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_selectNode_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Effect *cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // selectNode(Natron::Python::Effect*,bool)
            cppSelf->selectNode(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_selectNode_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.GuiApp.selectNode");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_setSelection(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GuiApp::setSelection(std::list<Natron::Python::Effect*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronGuiTypeConverters[SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX], (pyArg)))) {
        overloadId = 0; // setSelection(std::list<Natron::Python::Effect*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_setSelection_TypeError;

    // Call function/method
    {
        ::std::list<Natron::Python::Effect* > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelection(std::list<Natron::Python::Effect*>)
            cppSelf->setSelection(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_setSelection_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.setSelection");
        return {};
}

static PyObject *Sbk_Natron_Python_GuiAppFunc_unregisterPythonPanel(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GuiApp::unregisterPythonPanel(Natron::Python::PyPanel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]), (pyArg)))) {
        overloadId = 0; // unregisterPythonPanel(Natron::Python::PyPanel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GuiAppFunc_unregisterPythonPanel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::PyPanel *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unregisterPythonPanel(Natron::Python::PyPanel*)
            cppSelf->unregisterPythonPanel(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GuiAppFunc_unregisterPythonPanel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.GuiApp.unregisterPythonPanel");
        return {};
}


static const char *Sbk_Natron_Python_GuiApp_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Natron_Python_GuiApp_methods[] = {
    {"clearSelection", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_clearSelection), METH_VARARGS|METH_KEYWORDS},
    {"createModalDialog", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_createModalDialog), METH_NOARGS},
    {"deselectNode", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_deselectNode), METH_O},
    {"getActiveTabWidget", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getActiveTabWidget), METH_NOARGS},
    {"getActiveViewer", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getActiveViewer), METH_NOARGS},
    {"getDirectoryDialog", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getDirectoryDialog), METH_VARARGS|METH_KEYWORDS},
    {"getFilenameDialog", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getFilenameDialog), METH_VARARGS|METH_KEYWORDS},
    {"getRGBColorDialog", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getRGBColorDialog), METH_NOARGS},
    {"getSelectedNodes", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getSelectedNodes), METH_VARARGS|METH_KEYWORDS},
    {"getSequenceDialog", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getSequenceDialog), METH_VARARGS|METH_KEYWORDS},
    {"getTabWidget", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getTabWidget), METH_O},
    {"getUserPanel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getUserPanel), METH_O},
    {"getViewer", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_getViewer), METH_O},
    {"moveTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_moveTab), METH_VARARGS},
    {"registerPythonPanel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_registerPythonPanel), METH_VARARGS},
    {"renderBlocking", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_renderBlocking), METH_VARARGS|METH_KEYWORDS},
    {"saveFilenameDialog", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_saveFilenameDialog), METH_VARARGS|METH_KEYWORDS},
    {"saveSequenceDialog", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_saveSequenceDialog), METH_VARARGS|METH_KEYWORDS},
    {"selectAllNodes", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_selectAllNodes), METH_VARARGS|METH_KEYWORDS},
    {"selectNode", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_selectNode), METH_VARARGS},
    {"setSelection", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_setSelection), METH_O},
    {"unregisterPythonPanel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GuiAppFunc_unregisterPythonPanel), METH_O},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_GuiApp_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::GuiApp *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<GuiAppWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_GuiApp_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_GuiApp_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_GuiApp_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_GuiApp_TypeF(void)
{
    return _Sbk_Natron_Python_GuiApp_Type;
}

static PyType_Slot Sbk_Natron_Python_GuiApp_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_GuiApp_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_GuiApp_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_GuiApp_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_GuiApp_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_GuiApp_spec = {
    "1:NatronGui.GuiApp",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_GuiApp_slots
};

} //extern "C"

static void *Sbk_Natron_Python_GuiApp_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::Natron::Python::Group >()))
        return dynamic_cast< ::Natron::Python::GuiApp *>(reinterpret_cast< ::Natron::Python::Group *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void GuiApp_PythonToCpp_GuiApp_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_GuiApp_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_GuiApp_PythonToCpp_GuiApp_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_GuiApp_TypeF())))
        return GuiApp_PythonToCpp_GuiApp_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *GuiApp_PTR_CppToPython_GuiApp(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::GuiApp *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_GuiApp_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_GuiApp_SignatureStrings[] = {
    "NatronGui.GuiApp.clearSelection(self,group:NatronEngine.Natron.Python.Group=0)",
    "NatronGui.GuiApp.createModalDialog(self)->NatronGui.PyModalDialog",
    "NatronGui.GuiApp.deselectNode(self,effect:NatronEngine.Natron.Python.Effect)",
    "NatronGui.GuiApp.getActiveTabWidget(self)->NatronGui.PyTabWidget",
    "NatronGui.GuiApp.getActiveViewer(self)->NatronGui.PyViewer",
    "NatronGui.GuiApp.getDirectoryDialog(self,location:QString=QString())->QString",
    "NatronGui.GuiApp.getFilenameDialog(self,filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.getRGBColorDialog(self)->NatronEngine.Natron.Python.ColorTuple",
    "NatronGui.GuiApp.getSelectedNodes(self,group:NatronEngine.Natron.Python.Group=0)->std.list[NatronEngine.Natron.Python.Effect]",
    "NatronGui.GuiApp.getSequenceDialog(self,filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.getTabWidget(self,name:QString)->NatronGui.PyTabWidget",
    "NatronGui.GuiApp.getUserPanel(self,scriptName:QString)->NatronGui.PyPanel",
    "NatronGui.GuiApp.getViewer(self,scriptName:QString)->NatronGui.PyViewer",
    "NatronGui.GuiApp.moveTab(self,scriptName:QString,pane:NatronGui.PyTabWidget)->bool",
    "NatronGui.GuiApp.registerPythonPanel(self,panel:NatronGui.PyPanel,pythonFunction:QString)",
    "1:NatronGui.GuiApp.renderBlocking(self,writeNode:NatronEngine.Natron.Python.Effect,firstFrame:int,lastFrame:int,frameStep:int=1)",
    "0:NatronGui.GuiApp.renderBlocking(self,effects:std.list[NatronEngine.Natron.Python.Effect],firstFrames:std.list[int],lastFrames:std.list[int],frameSteps:std.list[int])",
    "NatronGui.GuiApp.saveFilenameDialog(self,filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.saveSequenceDialog(self,filters:QStringList,location:QString=QString())->QString",
    "NatronGui.GuiApp.selectAllNodes(self,group:NatronEngine.Natron.Python.Group=0)",
    "NatronGui.GuiApp.selectNode(self,effect:NatronEngine.Natron.Python.Effect,clearPreviousSelection:bool)",
    "NatronGui.GuiApp.setSelection(self,nodes:std.list[NatronEngine.Natron.Python.Effect])",
    "NatronGui.GuiApp.unregisterPythonPanel(self,panel:NatronGui.PyPanel)",
    nullptr}; // Sentinel

void init_Natron_Python_GuiApp(PyObject *module)
{
    _Sbk_Natron_Python_GuiApp_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "GuiApp",
        "Natron::Python::GuiApp*",
        &Sbk_Natron_Python_GuiApp_spec,
        &Shiboken::callCppDestructor< ::Natron::Python::GuiApp >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]),
        0,
        0    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_GuiApp_Type);
    InitSignatureStrings(pyType, Natron_Python_GuiApp_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Natron_Python_GuiApp_Type), Sbk_Natron_Python_GuiApp_PropertyStrings);
    SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_GuiApp_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_GuiApp_TypeF(),
        GuiApp_PythonToCpp_GuiApp_PTR,
        is_GuiApp_PythonToCpp_GuiApp_PTR_Convertible,
        GuiApp_PTR_CppToPython_GuiApp);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::GuiApp");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::GuiApp*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::GuiApp&");
    Shiboken::Conversions::registerConverterName(converter, "Python::GuiApp");
    Shiboken::Conversions::registerConverterName(converter, "Python::GuiApp*");
    Shiboken::Conversions::registerConverterName(converter, "Python::GuiApp&");
    Shiboken::Conversions::registerConverterName(converter, "GuiApp");
    Shiboken::Conversions::registerConverterName(converter, "GuiApp*");
    Shiboken::Conversions::registerConverterName(converter, "GuiApp&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::GuiApp).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::GuiAppWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_GuiApp_TypeF(), &Sbk_Natron_Python_GuiApp_typeDiscovery);


    GuiAppWrapper::pysideInitQtMetaTypes();
}
