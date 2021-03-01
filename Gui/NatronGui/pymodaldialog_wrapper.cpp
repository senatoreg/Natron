
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

#include "pymodaldialog_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyParameter.h>
#include <QList>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdialog.h>
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
#include <qwidget.h>


// Native ---------------------------------------------------------

void PyModalDialogWrapper::pysideInitQtMetaTypes()
{
}

void PyModalDialogWrapper::accept()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "accept"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "accept"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::accept();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void PyModalDialogWrapper::actionEvent(QActionEvent * event)
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

void PyModalDialogWrapper::changeEvent(QEvent * event)
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

void PyModalDialogWrapper::childEvent(QChildEvent * arg__1)
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

void PyModalDialogWrapper::closeEvent(QCloseEvent * arg__1)
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
        return this->::QDialog::closeEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QCLOSEEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], arg__1)
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
void PyModalDialogWrapper::connectNotify(const QMetaMethod & signal)
#else
void PyModalDialogWrapper::connectNotify(const char * signal)
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

void PyModalDialogWrapper::contextMenuEvent(QContextMenuEvent * arg__1)
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
        return this->::QDialog::contextMenuEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], arg__1)
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

void PyModalDialogWrapper::customEvent(QEvent * arg__1)
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

int PyModalDialogWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
void PyModalDialogWrapper::disconnectNotify(const QMetaMethod & signal)
#else
void PyModalDialogWrapper::disconnectNotify(const char * signal)
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

void PyModalDialogWrapper::done(int arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "done"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "done"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::done(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void PyModalDialogWrapper::dragEnterEvent(QDragEnterEvent * event)
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

void PyModalDialogWrapper::dragLeaveEvent(QDragLeaveEvent * event)
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

void PyModalDialogWrapper::dragMoveEvent(QDragMoveEvent * event)
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

void PyModalDialogWrapper::dropEvent(QDropEvent * event)
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

void PyModalDialogWrapper::enterEvent(QEvent * event)
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

bool PyModalDialogWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool PyModalDialogWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        return this->::QDialog::eventFilter(arg__1, arg__2);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void PyModalDialogWrapper::focusInEvent(QFocusEvent * event)
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

bool PyModalDialogWrapper::focusNextPrevChild(bool next)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyModalDialogWrapper::focusOutEvent(QFocusEvent * event)
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

int PyModalDialogWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyModalDialogWrapper::hideEvent(QHideEvent * event)
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

void PyModalDialogWrapper::inputMethodEvent(QInputMethodEvent * event)
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

QVariant PyModalDialogWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyModalDialogWrapper::keyPressEvent(QKeyEvent * arg__1)
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
        return this->::QDialog::keyPressEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], arg__1)
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

void PyModalDialogWrapper::keyReleaseEvent(QKeyEvent * event)
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
void PyModalDialogWrapper::languageChange()
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

void PyModalDialogWrapper::leaveEvent(QEvent * event)
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

int PyModalDialogWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize PyModalDialogWrapper::minimumSizeHint() const
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
        return this->::QDialog::minimumSizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyModalDialogWrapper::mouseDoubleClickEvent(QMouseEvent * event)
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

void PyModalDialogWrapper::mouseMoveEvent(QMouseEvent * event)
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

void PyModalDialogWrapper::mousePressEvent(QMouseEvent * event)
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

void PyModalDialogWrapper::mouseReleaseEvent(QMouseEvent * event)
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

void PyModalDialogWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * PyModalDialogWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyModalDialogWrapper::paintEvent(QPaintEvent * event)
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

void PyModalDialogWrapper::reject()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
#if SHIBOKEN_MAJOR_VERSION < 2 || ( SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 1 )))
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reject"));
#else
    void* nameCache = malloc(2 * sizeof(PyObject*));
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, (PyObject**)nameCache, "reject"));
    free(nameCache);
#endif
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::reject();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void PyModalDialogWrapper::resizeEvent(QResizeEvent * arg__1)
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
        return this->::QDialog::resizeEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QRESIZEEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], arg__1)
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

void PyModalDialogWrapper::setVisible(bool visible)
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
        return this->::QDialog::setVisible(visible);
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

void PyModalDialogWrapper::showEvent(QShowEvent * arg__1)
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
        return this->::QDialog::showEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide2_QtGuiTypes[SBK_QSHOWEVENT_IDX], arg__1)
#else
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], arg__1)
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

QSize PyModalDialogWrapper::sizeHint() const
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
        return this->::QDialog::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyModalDialog.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyModalDialogWrapper::tabletEvent(QTabletEvent * event)
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

void PyModalDialogWrapper::timerEvent(QTimerEvent * arg__1)
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

void PyModalDialogWrapper::wheelEvent(QWheelEvent * event)
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

const QMetaObject* PyModalDialogWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700 && QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return PyModalDialog::metaObject();
#if SHIBOKEN_MAJOR_VERSION >= 2
    return PySide::SignalManager::retrieveMetaObject(reinterpret_cast<PyObject*>(pySelf));
#else
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
#endif
}

int PyModalDialogWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = PyModalDialog::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* PyModalDialogWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< PyModalDialogWrapper* >(this));
        return PyModalDialog::qt_metacast(_clname);
}

PyModalDialogWrapper::~PyModalDialogWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_PyModalDialogFunc_addWidget(PyObject* self, PyObject* pyArg)
{
    PyModalDialogWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyModalDialogWrapper*)((::PyModalDialog*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYMODALDIALOG_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_PyModalDialogFunc_addWidget_TypeError;

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

    Sbk_PyModalDialogFunc_addWidget_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.addWidget");
#else
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.addWidget", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyModalDialogFunc_getParam(PyObject* self, PyObject* pyArg)
{
    PyModalDialogWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyModalDialogWrapper*)((::PyModalDialog*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYMODALDIALOG_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_PyModalDialogFunc_getParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getParam(QString)const
            Param * cppResult = const_cast<const ::PyModalDialogWrapper*>(cppSelf)->getParam(cppArg0);
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

    Sbk_PyModalDialogFunc_getParam_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.getParam");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.getParam", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyModalDialogFunc_insertWidget(PyObject* self, PyObject* args)
{
    PyModalDialogWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyModalDialogWrapper*)((::PyModalDialog*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYMODALDIALOG_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_PyModalDialogFunc_insertWidget_TypeError;

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

    Sbk_PyModalDialogFunc_insertWidget_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyModalDialog.insertWidget");
#else
        const char* overloads[] = {"int, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.PyModalDialog.insertWidget", overloads);
#endif
        return 0;
}

static PyObject* Sbk_PyModalDialogFunc_setParamChangedCallback(PyObject* self, PyObject* pyArg)
{
    PyModalDialogWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (PyModalDialogWrapper*)((::PyModalDialog*)Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_PYMODALDIALOG_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_PyModalDialogFunc_setParamChangedCallback_TypeError;

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

    Sbk_PyModalDialogFunc_setParamChangedCallback_TypeError:
#if SHIBOKEN_MAJOR_VERSION >= 2
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.setParamChangedCallback");
#else
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.PyModalDialog.setParamChangedCallback", overloads);
#endif
        return 0;
}

static PyMethodDef Sbk_PyModalDialog_methods[] = {
    {"addWidget", (PyCFunction)Sbk_PyModalDialogFunc_addWidget, METH_O},
    {"getParam", (PyCFunction)Sbk_PyModalDialogFunc_getParam, METH_O},
    {"insertWidget", (PyCFunction)Sbk_PyModalDialogFunc_insertWidget, METH_VARARGS},
    {"setParamChangedCallback", (PyCFunction)Sbk_PyModalDialogFunc_setParamChangedCallback, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_PyModalDialog_traverse(PyObject* self, visitproc visit, void* arg)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
#endif
}
static int Sbk_PyModalDialog_clear(PyObject* self)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
#else
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
#endif
}
static int mi_offsets[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int*
Sbk_PyModalDialog_mi_init(const void* cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        std::set<int>::iterator it;
        const PyModalDialog* class_ptr = reinterpret_cast<const PyModalDialog*>(cptr);
        size_t base = (size_t) class_ptr;
        offsets.insert(((size_t) static_cast<const QDialog*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QDialog*>((PyModalDialog*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const UserParamHolder*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const UserParamHolder*>((PyModalDialog*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QWidget*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QWidget*>((QDialog*)((void*)class_ptr))) - base);
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
static void* Sbk_PyModalDialogSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    PyModalDialog* me = reinterpret_cast< ::PyModalDialog*>(obj);
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide2_QtGuiTypes[SBK_QDIALOG_IDX]))
        return static_cast< ::QDialog*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]))
        return static_cast< ::QWidget*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide2_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast< ::QPaintDevice*>(me);
#else
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDIALOG_IDX]))
        return static_cast< ::QDialog*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]))
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
static SbkObjectType *_Sbk_PyModalDialog_Type = nullptr;
static SbkObjectType *Sbk_PyModalDialog_TypeF(void)
{
    return _Sbk_PyModalDialog_Type;
}

static PyType_Slot Sbk_PyModalDialog_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_PyModalDialog_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_PyModalDialog_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_PyModalDialog_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_PyModalDialog_spec = {
    "NatronGui.PyModalDialog",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_PyModalDialog_slots
};
#else
static SbkObjectType Sbk_PyModalDialog_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronGui.PyModalDialog",
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
    /*tp_traverse*/         Sbk_PyModalDialog_traverse,
    /*tp_clear*/            Sbk_PyModalDialog_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_PyModalDialog_methods,
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

static void* Sbk_PyModalDialog_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::PyModalDialog*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::PyModalDialog*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::UserParamHolder >()))
        return dynamic_cast< ::PyModalDialog*>(reinterpret_cast< ::UserParamHolder*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyModalDialog_PythonToCpp_PyModalDialog_PTR(PyObject* pyIn, void* cppOut) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::Conversions::pythonToCppPointer(Sbk_PyModalDialog_TypeF(), pyIn, cppOut);
#else
    Shiboken::Conversions::pythonToCppPointer(&Sbk_PyModalDialog_Type, pyIn, cppOut);
#endif
}
static PythonToCppFunc is_PyModalDialog_PythonToCpp_PyModalDialog_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
#if SHIBOKEN_MAJOR_VERSION >= 2
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_PyModalDialog_TypeF())))
#else
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_PyModalDialog_Type))
#endif
        return PyModalDialog_PythonToCpp_PyModalDialog_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyModalDialog_PTR_CppToPython_PyModalDialog(const void* cppIn) {
#if SHIBOKEN_MAJOR_VERSION >= 2
    return PySide::getWrapperForQObject((::PyModalDialog*)cppIn, Sbk_PyModalDialog_TypeF());
#else
    return PySide::getWrapperForQObject((::PyModalDialog*)cppIn, &Sbk_PyModalDialog_Type);
#endif

#if SHIBOKEN_MAJOR_VERSION >= 2
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::PyModalDialog *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_PyModalDialog_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
#endif
}

#if SHIBOKEN_MAJOR_VERSION >= 2
// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *PyModalDialog_SignatureStrings[] = {
    "NatronGui.PyModalDialog.addWidget(w:PySide2.QtWidgets.QWidget)",
    "NatronGui.PyModalDialog.getParam(scriptName:QString)->NatronEngine.Param",
    "NatronGui.PyModalDialog.insertWidget(pos:int,w:PySide2.QtWidgets.QWidget)",
    "NatronGui.PyModalDialog.setParamChangedCallback(callback:QString)",
    nullptr}; // Sentinel
#endif

void init_PyModalDialog(PyObject* module)
{
#if SHIBOKEN_MAJOR_VERSION >= 2
    PyObject* Sbk_PyModalDialog_Type_bases = PyTuple_Pack(2,
        reinterpret_cast<PyObject*>(SbkPySide2_QtWidgetsTypes[SBK_QDIALOG_IDX]),
        reinterpret_cast<PyObject*>(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]));

    _Sbk_PyModalDialog_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyModalDialog",
        "PyModalDialog*",
        &Sbk_PyModalDialog_spec,
#if SHIBOKEN_MAJOR_VERSION == 2 && ( SHIBOKEN_MINOR_VERSION < 15 || ( SHIBOKEN_MINOR_VERSION == 15 && SHIBOKEN_MICRO_VERSION < 2 ))
        PyModalDialog_SignatureStrings,
#endif
        &Shiboken::callCppDestructor< ::NATRON_NAMESPACE::NATRON_PYTHON_NAMESPACE::PyModalDialog >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]),
        Sbk_PyModalDialog_Type_bases,
        0    );

    SbkNatronGuiTypes[SBK_PYMODALDIALOG_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_PyModalDialog_TypeF());
#else
    SbkNatronGuiTypes[SBK_PYMODALDIALOG_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_PyModalDialog_Type);

    PyObject* Sbk_PyModalDialog_Type_bases = PyTuple_Pack(2,
        (PyObject*)SbkPySide_QtGuiTypes[SBK_QDIALOG_IDX],
        (PyObject*)SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "PyModalDialog", "PyModalDialog*",
        &Sbk_PyModalDialog_Type, &Shiboken::callCppDestructor< ::PyModalDialog >, (SbkObjectType*)SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX], Sbk_PyModalDialog_Type_bases)) {
        return;
    }
#endif

    // Register Converter
#if SHIBOKEN_MAJOR_VERSION >= 2
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_PyModalDialog_TypeF(),
#else
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_PyModalDialog_Type,
#endif
        PyModalDialog_PythonToCpp_PyModalDialog_PTR,
        is_PyModalDialog_PythonToCpp_PyModalDialog_PTR_Convertible,
        PyModalDialog_PTR_CppToPython_PyModalDialog);

    Shiboken::Conversions::registerConverterName(converter, "PyModalDialog");
    Shiboken::Conversions::registerConverterName(converter, "PyModalDialog*");
    Shiboken::Conversions::registerConverterName(converter, "PyModalDialog&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyModalDialog).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyModalDialogWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_PyModalDialog_mi_init;
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setMultipleInheritanceFunction(Sbk_PyModalDialog_TypeF(), func);
    Shiboken::ObjectType::setCastFunction(Sbk_PyModalDialog_TypeF(), &Sbk_PyModalDialogSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_PyModalDialog_TypeF(), &Sbk_PyModalDialog_typeDiscovery);
#else
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_PyModalDialog_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_PyModalDialog_Type, &Sbk_PyModalDialogSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_PyModalDialog_Type, &Sbk_PyModalDialog_typeDiscovery);
#endif


    PyModalDialogWrapper::pysideInitQtMetaTypes();
#if SHIBOKEN_MAJOR_VERSION >= 2
    Shiboken::ObjectType::setSubTypeInitHook(Sbk_PyModalDialog_TypeF(), &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(Sbk_PyModalDialog_TypeF(), &::PyModalDialog::staticMetaObject, sizeof(::PyModalDialog));
#else
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_PyModalDialog_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_PyModalDialog_Type, &::PyModalDialog::staticMetaObject, sizeof(::PyModalDialog));
#endif
}
