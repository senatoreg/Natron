#ifndef SBK_APPWRAPPER_H
#define SBK_APPWRAPPER_H

#include <PyAppInstance.h>


// Extra includes
#include <PyNode.h>
#include <PyNodeGroup.h>
#include <map>
#include <PyAppInstance.h>
#include <list>
#include <PyParameter.h>
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

#endif // SBK_APPWRAPPER_H

