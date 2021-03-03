#ifndef SBK_PYGUIAPPLICATIONWRAPPER_H
#define SBK_PYGUIAPPLICATIONWRAPPER_H

#include <PyGlobalGui.h>


// Extra includes
#include <qpixmap.h>
#include <PyGuiApp.h>
#include <PyAppInstance.h>
class PyGuiApplicationWrapper : public Natron::Python::PyGuiApplication
{
public:
    PyGuiApplicationWrapper();
    ~PyGuiApplicationWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_PYCOREAPPLICATIONWRAPPER_H
#  define SBK_PYCOREAPPLICATIONWRAPPER_H

// Inherited base class:
class PyCoreApplicationWrapper : public Natron::Python::PyCoreApplication
{
public:
    PyCoreApplicationWrapper();
    ~PyCoreApplicationWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_PYCOREAPPLICATIONWRAPPER_H

#endif // SBK_PYGUIAPPLICATIONWRAPPER_H

