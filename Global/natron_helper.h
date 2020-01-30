#include <typeinfo>
#include <cctype>
#include <cstring>
#include <shiboken.h>
#include <wchar.h>
#include <stdlib.h>

#if SHIBOKEN_MAJOR_VERSION >= 2
#ifndef SBK_CONVERTER
#  define SBK_CONVERTER(pyType) (*PepType_SGTP(pyType)->converter)
#endif

#ifndef CONCAT3
#  define CONCAT3(s1, s2, s3) s1 s2 s3
#endif

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
#endif
