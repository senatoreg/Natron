#ifndef SBK_RECTDWRAPPER_H
#define SBK_RECTDWRAPPER_H

#include <RectD.h>


// Extra includes
#include <RectD.h>
class RectDWrapper : public Natron::RectD
{
public:
    RectDWrapper();
    RectDWrapper(const Natron::RectD& self) : Natron::RectD(self)
    {
    }

    RectDWrapper(double l, double b, double r, double t);
    ~RectDWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_RECTDWRAPPER_H

