#ifndef SBK_PYPANELWRAPPER_H
#define SBK_PYPANELWRAPPER_H

#include <PythonPanels.h>


// Extra includes
#include <qobject.h>
#include <PyGuiApp.h>
#include <PyParameter.h>
#include <list>
#include <qevent.h>
#include <qcoreevent.h>
class PyPanelWrapper : public Natron::Python::PyPanel
{
public:
    PyPanelWrapper(const QString & scriptName, const QString & label, bool useUserParameters, Natron::Python::GuiApp * app);
    inline void enterEvent_protected(QEvent * e) { Natron::Python::PyPanel::enterEvent(e); }
    void enterEvent(QEvent * e) override;
    inline void keyPressEvent_protected(QKeyEvent * e) { Natron::Python::PyPanel::keyPressEvent(e); }
    void keyPressEvent(QKeyEvent * e) override;
    inline void leaveEvent_protected(QEvent * e) { Natron::Python::PyPanel::leaveEvent(e); }
    void leaveEvent(QEvent * e) override;
    inline void mousePressEvent_protected(QMouseEvent * e) { Natron::Python::PyPanel::mousePressEvent(e); }
    void mousePressEvent(QMouseEvent * e) override;
    inline void onUserDataChanged_protected() { Natron::Python::PyPanel::onUserDataChanged(); }
    void restore(const QString & arg__1) override;
    inline QString save_protected() { return Natron::Python::PyPanel::save(); }
    QString save() override;
    ~PyPanelWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[6];
};

#endif // SBK_PYPANELWRAPPER_H

