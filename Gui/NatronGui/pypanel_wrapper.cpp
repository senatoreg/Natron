
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
#include <signalmanager.h>
CLANG_DIAG_OFF(header-guard)
#include <pysidemetafunction.h> // has wrong header guards in pyside 1.2.2
#include <set>
#include "natrongui_python.h"
#include "natron_helper.h"

#include "pypanel_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyGuiApp.h>
#include <PyParameter.h>
#include <QList>
#include <list>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qevent.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qfontmetrics.h>
#include <qgraphicsproxywidget.h>
#include <qicon.h>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <qinputcontext.h>
#endif
#include <qkeysequence.h>
#include <qlayout.h>
#include <qlocale.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qthread.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

void PyPanelWrapper::pysideInitQtMetaTypes()
{
}

PyPanelWrapper::PyPanelWrapper(const QString & scriptName, const QString & label, bool useUserParameters, GuiApp * app) : PyPanel(scriptName, label, useUserParameters, app) {
    // ... middle
}

void PyPanelWrapper::actionEvent(QActionEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "actionEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "actionEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::actionEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QACTIONEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTIONEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::changeEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "changeEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::changeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "childEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::closeEvent(QCloseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closeEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "closeEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::closeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QCLOSEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
void PyPanelWrapper::connectNotify(const QMetaMethod & signal)
#else
void PyPanelWrapper::connectNotify(const char * signal)
#endif
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "connectNotify"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal.typeName())
#else
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
#endif
));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void PyPanelWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "contextMenuEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::contextMenuEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "customEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

int PyPanelWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "devType"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::devType();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
void PyPanelWrapper::disconnectNotify(const QMetaMethod & signal)
#else
void PyPanelWrapper::disconnectNotify(const char * signal)
#endif
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "disconnectNotify"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal.typeName())
#else
    Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
#endif
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void PyPanelWrapper::dragEnterEvent(QDragEnterEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "dragEnterEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragEnterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::dragLeaveEvent(QDragLeaveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "dragLeaveEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragLeaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::dragMoveEvent(QDragMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "dragMoveEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::dropEvent(QDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "dropEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dropEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QDROPEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::enterEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "enterEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "enterEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::enterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool PyPanelWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "event"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool PyPanelWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "eventFilter"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
#endif
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void PyPanelWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "focusInEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusInEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool PyPanelWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "focusNextPrevChild"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusNextPrevChild(next);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &next)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyPanelWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "focusOutEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusOutEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

int PyPanelWrapper::heightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "heightForWidth"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "heightForWidth"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::heightForWidth(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyPanelWrapper::hideEvent(QHideEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hideEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "hideEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::hideEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QHIDEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QHIDEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "inputMethodEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QVariant PyPanelWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "inputMethodQuery"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodQuery(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide2_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), &arg__1)
#else
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), &arg__1)
#endif
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
#if SHIBOKEN_MAJOR_VERSION >= 2
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
#else
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
#endif
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyPanelWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "keyPressEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::keyPressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::keyReleaseEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "keyReleaseEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::keyReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
void PyPanelWrapper::languageChange()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "languageChange"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "languageChange"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::languageChange();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}
#endif

void PyPanelWrapper::leaveEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "leaveEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "leaveEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::leaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

int PyPanelWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "metric"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::metric(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &arg__1)
#else
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &arg__1)
#endif
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize PyPanelWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "minimumSizeHint"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::minimumSizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
#if SHIBOKEN_MAJOR_VERSION >= 2
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
#else
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
#endif
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyPanelWrapper::mouseDoubleClickEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "mouseDoubleClickEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseDoubleClickEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::mouseMoveEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "mouseMoveEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::mousePressEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "mousePressEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mousePressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::mouseReleaseEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "mouseReleaseEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::moveEvent(QMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "moveEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "moveEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::moveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QMOVEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOVEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QPaintEngine * PyPanelWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "paintEngine"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::paintEngine();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QPaintEngine*)0);
    }
    // Check return type
#if SHIBOKEN_MAJOR_VERSION >= 2
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QPAINTENGINE_IDX], pyResult);
#else
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], pyResult);
#endif
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyPanelWrapper::paintEvent(QPaintEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "paintEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::paintEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QPAINTEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::resizeEvent(QResizeEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "resizeEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::resizeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QRESIZEEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::restore(const QString & arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "restore"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "restore"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::PyPanel::restore(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &arg__1)
#else
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &arg__1)
#endif
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QString PyPanelWrapper::save()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "save"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "save"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::PyPanel::save();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
#if SHIBOKEN_MAJOR_VERSION >= 2
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
#else
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
#endif
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.save", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyPanelWrapper::setVisible(bool visible)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setVisible"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "setVisible"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::setVisible(visible);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &visible)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void PyPanelWrapper::showEvent(QShowEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "showEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::showEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QSHOWEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QSize PyPanelWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "sizeHint"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::sizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
#if SHIBOKEN_MAJOR_VERSION >= 2
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
#else
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
#endif
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyPanel.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyPanelWrapper::tabletEvent(QTabletEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "tabletEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "tabletEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::tabletEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QTABLETEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "timerEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void PyPanelWrapper::wheelEvent(QWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "wheelEvent"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::wheelEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QWHEELEVENT_IDX], event)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], event)
#endif
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

const QMetaObject* PyPanelWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700 && QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return PyPanel::metaObject();
#if SHIBOKEN_MAJOR_VERSION >= 2
    return PySide::SignalManager::retrieveMetaObject(reinterpret_cast<PyObject*>(pySelf));
#else
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
#endif
}

int PyPanelWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = PyPanel::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* PyPanelWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< PyPanelWrapper* >(this));
        return PyPanel::qt_metacast(_clname);
}

PyPanelWrapper::~PyPanelWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_PyPanel_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkNatronGuiTypes[SBK_PYPANEL_IDX]);
    if (type != myType) {
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::ObjectType::copyMultipleInheritance(type, myType);
#else
        Shiboken::ObjectType::copyMultimpleheritance(type, myType);
#endif
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::PyPanel >()))
        return -1;

    ::PyPanelWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "PyPanel", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: PyPanel(QString,QString,bool,GuiApp*)
    if (numArgs == 4
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
#else
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
#endif
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronGuiTypes[SBK_GUIAPP_IDX], (pyArgs[3])))) {
        overloadId = 0; // PyPanel(QString,QString,bool,GuiApp*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyPanel_Init_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return -1;
        ::GuiApp* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // PyPanel(QString,QString,bool,GuiApp*)
            void* addr = PySide::nextQObjectMemoryAddr();
            if (addr) {
                cptr = new (addr) ::PyPanelWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::PyPanelWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
            }

        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::PyPanel >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_PyPanel_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_PyPanel_Init_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyPanel");
#else
        const char* overloads[] = {"unicode, unicode, bool, NatronGui.GuiApp", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyPanel", overloads);
#endif
        return -1;
}

static PyObject* Sbk_PyPanelFunc_addWidget(PyObject* self, PyObject* pyArg)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addWidget(QWidget*)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
#endif
        overloadId = 0; // addWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyPanelFunc_addWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addWidget(QWidget*)
            cppSelf->addWidget(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyPanelFunc_addWidget_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.addWidget");
#else
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.addWidget", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyPanelFunc_getPanelLabel(PyObject* self)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPanelLabel()const
            QString cppResult = const_cast<const ::PyPanelWrapper*>(cppSelf)->getPanelLabel();
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

static PyObject* Sbk_PyPanelFunc_getPanelScriptName(PyObject* self)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPanelScriptName()const
            QString cppResult = const_cast<const ::PyPanelWrapper*>(cppSelf)->getPanelScriptName();
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

static PyObject* Sbk_PyPanelFunc_getParam(PyObject* self, PyObject* pyArg)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_PyPanelFunc_getParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getParam(QString)const
            Param * cppResult = const_cast<const ::PyPanelWrapper*>(cppSelf)->getParam(cppArg0);
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

    Sbk_PyPanelFunc_getParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.getParam");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.getParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyPanelFunc_getParams(PyObject* self)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
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

static PyObject* Sbk_PyPanelFunc_insertWidget(PyObject* self, PyObject* args)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertWidget", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertWidget(int,QWidget*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
#if SHIBOKEN_MAJOR_VERSION >= 2
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
#else
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
#endif
        overloadId = 0; // insertWidget(int,QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyPanelFunc_insertWidget_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertWidget(int,QWidget*)
            cppSelf->insertWidget(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyPanelFunc_insertWidget_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyPanel.insertWidget");
#else
        const char* overloads[] = {"int, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyPanel.insertWidget", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyPanelFunc_onUserDataChanged(PyObject* self)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // onUserDataChanged()
            ((::PyPanelWrapper*) cppSelf)->PyPanelWrapper::onUserDataChanged_protected();
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_PyPanelFunc_restore(PyObject* self, PyObject* pyArg)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: restore(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // restore(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyPanelFunc_restore_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // restore(QString)
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::PyPanel::restore(cppArg0) : cppSelf->restore(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyPanelFunc_restore_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.restore");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.restore", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyPanelFunc_save(PyObject* self)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // save()
            QString cppResult = ((::PyPanelWrapper*) cppSelf)->PyPanelWrapper::save_protected();
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

static PyObject* Sbk_PyPanelFunc_setPanelLabel(PyObject* self, PyObject* pyArg)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPanelLabel(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setPanelLabel(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyPanelFunc_setPanelLabel_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPanelLabel(QString)
            cppSelf->setPanelLabel(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyPanelFunc_setPanelLabel_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.setPanelLabel");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.setPanelLabel", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyPanelFunc_setParamChangedCallback(PyObject* self, PyObject* pyArg)
{
    PyPanelWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyPanelWrapper*)((::PyPanel*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYPANEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setParamChangedCallback(QString)
#if SHIBOKEN_MAJOR_VERSION >= 2
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#else
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
#endif
        overloadId = 0; // setParamChangedCallback(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PyPanelFunc_setParamChangedCallback_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setParamChangedCallback(QString)
            cppSelf->setParamChangedCallback(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_PyPanelFunc_setParamChangedCallback_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.setParamChangedCallback");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyPanel.setParamChangedCallback", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_PyPanel_methods[] = {
    {"addWidget", (PyCFunction)Sbk_PyPanelFunc_addWidget, METH_O},
    {"getPanelLabel", (PyCFunction)Sbk_PyPanelFunc_getPanelLabel, METH_NOARGS},
    {"getPanelScriptName", (PyCFunction)Sbk_PyPanelFunc_getPanelScriptName, METH_NOARGS},
    {"getParam", (PyCFunction)Sbk_PyPanelFunc_getParam, METH_O},
    {"getParams", (PyCFunction)Sbk_PyPanelFunc_getParams, METH_NOARGS},
    {"insertWidget", (PyCFunction)Sbk_PyPanelFunc_insertWidget, METH_VARARGS},
    {"onUserDataChanged", (PyCFunction)Sbk_PyPanelFunc_onUserDataChanged, METH_NOARGS},
    {"restore", (PyCFunction)Sbk_PyPanelFunc_restore, METH_O},
    {"save", (PyCFunction)Sbk_PyPanelFunc_save, METH_NOARGS},
    {"setPanelLabel", (PyCFunction)Sbk_PyPanelFunc_setPanelLabel, METH_O},
    {"setParamChangedCallback", (PyCFunction)Sbk_PyPanelFunc_setParamChangedCallback, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_PyPanel_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF)->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_PyPanel_clear(PyObject* self)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF)->tp_clear(self);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
#endif
}
static int mi_offsets[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int*
Sbk_PyPanel_mi_init(const void* cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        std::set<int>::iterator it;
        const PyPanel* class_ptr = reinterpret_cast<const PyPanel*>(cptr);
        size_t base = (size_t) class_ptr;
        offsets.insert(((size_t) static_cast<const QWidget*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QWidget*>((PyPanel*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const UserParamHolder*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const UserParamHolder*>((PyPanel*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QObject*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QObject*>((QWidget*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QPaintDevice*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QPaintDevice*>((QWidget*)((void*)class_ptr))) - base);

        offsets.erase(0);

        int i = 0;
        for (it = offsets.begin(); it != offsets.end(); it++) {
            mi_offsets[i] = *it;
            i++;
        }
    }
    return mi_offsets;
}
static void* Sbk_PyPanelSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    PyPanel* me = reinterpret_cast< ::PyPanel*>(obj);
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]))
        return static_cast< ::QWidget*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide2_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast< ::QPaintDevice*>(me);
#else
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]))
        return static_cast< ::QWidget*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast< ::QPaintDevice*>(me);
#endif
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]))
        return static_cast< ::UserParamHolder*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
#if SHIBOKEN_MAJOR_VERSION >= 2
static SbkObjectType *_Sbk_PyPanel_Type = nullptr;
static SbkObjectType *Sbk_PyPanel_TypeF(void)
{
    return _Sbk_PyPanel_Type;
}

static PyType_Slot Sbk_PyPanel_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_PyPanel_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_PyPanel_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_PyPanel_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_PyPanel_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_PyPanel_spec = {
    "NatronGui.PyPanel",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_PyPanel_slots
};
#else
static SbkObjectType Sbk_PyPanel_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronGui.PyPanel",
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
    /*tp_traverse*/         Sbk_PyPanel_traverse,
    /*tp_clear*/            Sbk_PyPanel_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_PyPanel_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_PyPanel_Init,
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

static void* Sbk_PyPanel_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::PyPanel*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::PyPanel*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::UserParamHolder >()))
        return dynamic_cast< ::PyPanel*>(reinterpret_cast< ::UserParamHolder*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyPanel_PythonToCpp_PyPanel_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_PyPanel_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_PyPanel_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_PyPanel_PythonToCpp_PyPanel_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_PyPanel_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_PyPanel_Type))
#endif
        return PyPanel_PythonToCpp_PyPanel_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyPanel_PTR_CppToPython_PyPanel(const void* cppIn) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::PyPanel *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_PyPanel_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#else
    return PySide::getWrapperForQObject((::PyPanel*)cppIn, &Sbk_PyPanel_Type);
#endif

}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *PyPanel_SignatureStrings[] = {
    "NatronGui.PyPanel(scriptName:QString,label:QString,useUserParameters:bool,app:NatronGui.GuiApp)",
    "NatronGui.PyPanel.addWidget(w:PySide2.QtWidgets.QWidget)",
    "NatronGui.PyPanel.enterEvent(e:PySide2.QtCore.QEvent)",
    "NatronGui.PyPanel.getPanelLabel()->QString",
    "NatronGui.PyPanel.getPanelScriptName()->QString",
    "NatronGui.PyPanel.getParam(scriptName:QString)->NatronEngine.Param",
    "NatronGui.PyPanel.getParams()->QList[NatronEngine.Param]",
    //"NatronGui.PyPanel.getPythonFunction()->QString",
    "NatronGui.PyPanel.insertWidget(pos:int,w:PySide2.QtWidgets.QWidget)",
    "NatronGui.PyPanel.keyPressEvent(e:PySide2.QtGui.QKeyEvent)",
    "NatronGui.PyPanel.leaveEvent(e:PySide2.QtCore.QEvent)",
    "NatronGui.PyPanel.mousePressEvent(e:PySide2.QtGui.QMouseEvent)",
    "NatronGui.PyPanel.onUserDataChanged()",
    "NatronGui.PyPanel.restore(arg__1:QString)",
    "NatronGui.PyPanel.save()->QString",
    //"NatronGui.PyPanel.save_serialization_thread()->QString",
    "NatronGui.PyPanel.setPanelLabel(label:QString)",
    "NatronGui.PyPanel.setParamChangedCallback(callback:QString)",
    //"NatronGui.PyPanel.setPythonFunction(function:QString)",
    nullptr}; // Sentinel
#endif

void init_PyPanel(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    PyObject* Sbk_PyPanel_Type_bases = PyTuple_Pack(2,
        reinterpret_cast<PyObject*>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]),
        reinterpret_cast<PyObject*>(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]));

    _Sbk_PyPanel_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyPanel",
        "PyPanel*",
        &Sbk_PyPanel_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        PyPanel_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::PyPanel >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]),
        Sbk_PyPanel_Type_bases,
        0    );

    SbkNatronGuiTypes[SBK_PYPANEL_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_PyPanel_TypeF());
#else
    SbkNatronGuiTypes[SBK_PYPANEL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_PyPanel_Type);

    PyObject* Sbk_PyPanel_Type_bases = PyTuple_Pack(2,
        (PyObject*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX],
        (PyObject*)SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "PyPanel", "PyPanel*",
        &Sbk_PyPanel_Type, &Shiboken::callCppDestructor< ::PyPanel >, (SbkObjectType*)SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], Sbk_PyPanel_Type_bases)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_PyPanel_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_PyPanel_Type,
#endif
        PyPanel_PythonToCpp_PyPanel_PTR,
        is_PyPanel_PythonToCpp_PyPanel_PTR_Convertible,
        PyPanel_PTR_CppToPython_PyPanel);

    Shiboken::Conversions::registerConverterName(converter, "PyPanel");
    Shiboken::Conversions::registerConverterName(converter, "PyPanel*");
    Shiboken::Conversions::registerConverterName(converter, "PyPanel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyPanel).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyPanelWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_PyPanel_mi_init;
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setMultipleInheritanceFunction(Sbk_PyPanel_TypeF(), func);
    Shiboken::ObjectType::setCastFunction(Sbk_PyPanel_TypeF(), &Sbk_PyPanelSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_PyPanel_TypeF(), &Sbk_PyPanel_typeDiscovery);
#else
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_PyPanel_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_PyPanel_Type, &Sbk_PyPanelSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_PyPanel_Type, &Sbk_PyPanel_typeDiscovery);
#endif


    PyPanelWrapper::pysideInitQtMetaTypes();
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setSubTypeInitHook(Sbk_PyPanel_TypeF(), &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(Sbk_PyPanel_TypeF(), &::PyPanel::staticMetaObject, sizeof(::PyPanel));
#else
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_PyPanel_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_PyPanel_Type, &::PyPanel::staticMetaObject, sizeof(::PyPanel));
#endif
}
