#ifndef SBK_PYMODALDIALOGWRAPPER_H
#define SBK_PYMODALDIALOGWRAPPER_H

#include <PythonPanels.h>


// Extra includes
#include <qobject.h>
#include <PyParameter.h>
class PyModalDialogWrapper : public Natron::Python::PyModalDialog
{
public:
    ~PyModalDialogWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_PYMODALDIALOGWRAPPER_H

