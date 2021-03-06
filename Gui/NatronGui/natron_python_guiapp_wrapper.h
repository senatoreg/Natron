#ifndef SBK_GUIAPPWRAPPER_H
#define SBK_GUIAPPWRAPPER_H

#include <PyGuiApp.h>


// Extra includes
#include <PythonPanels.h>
#include <PyParameter.h>
#include <list>
#include <PyNode.h>
#include <PyNodeGroup.h>
#include <PyGuiApp.h>
#include <PyAppInstance.h>
#include <map>
class GuiAppWrapper : public Natron::Python::GuiApp
{
public:
    ~GuiAppWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_APPWRAPPER_H
#  define SBK_APPWRAPPER_H

// Inherited base class:
class AppWrapper : public Natron::Python::App
{
public:
    inline void renderInternal_protected(bool forceBlocking, Natron::Python::Effect * writeNode, int firstFrame, int lastFrame, int frameStep) { Natron::Python::App::renderInternal(forceBlocking, writeNode, firstFrame, lastFrame, frameStep); }
    inline void renderInternal_protected(bool forceBlocking, const std::list<Natron::Python::Effect* > & effects, const std::list<int > & firstFrames, const std::list<int > & lastFrames, const std::list<int > & frameSteps) { Natron::Python::App::renderInternal(forceBlocking, effects, firstFrames, lastFrames, frameSteps); }
    ~AppWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_APPWRAPPER_H

#  ifndef SBK_GROUPWRAPPER_H
#  define SBK_GROUPWRAPPER_H

// Inherited base class:
class GroupWrapper : public Natron::Python::Group
{
public:
    GroupWrapper();
    ~GroupWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_GROUPWRAPPER_H

#endif // SBK_GUIAPPWRAPPER_H

