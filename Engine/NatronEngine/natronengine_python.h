

#ifndef SBK_NATRONENGINE_PYTHON_H
#define SBK_NATRONENGINE_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
// Module Includes
#include <pyside2_qtcore_python.h>

// Bound library includes
#include <PyParameter.h>
#include <EngineFwd.h>
#include <RectD.h>
#include <PyAppInstance.h>
#include <PyNodeGroup.h>
#include <PyTracker.h>
#include <Macros.h>
#include <PyExprUtils.h>
#include <PyRoto.h>
#include <PyGlobalFunctions.h>
#include <RectI.h>
#include <Enums.h>
#include <PyNode.h>
// Conversion Includes - Primitive Types
#include <qabstractitemmodel.h>
#include <QString>
#include <QStringList>
#include <signalmanager.h>

// Conversion Includes - Container Types
#include <pysideqflags.h>
#include <QLinkedList>
#include <QList>
#include <QMap>
#include <QMultiMap>
#include <QPair>
#include <QQueue>
#include <QSet>
#include <QStack>
#include <QVector>
#include <list>
#include <map>
#include <map>
#include <utility>
#include <set>
#include <vector>

// Type indices
enum : int {
    SBK_NATRON_STATUSENUM_IDX                                = 60,
    SBK_NATRON_STANDARDBUTTONENUM_IDX                        = 59,
    SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX                 = 64,
    SBK_NATRON_KEYFRAMETYPEENUM_IDX                          = 5,
    SBK_NATRON_PIXMAPENUM_IDX                                = 8,
    SBK_NATRON_VALUECHANGEDREASONENUM_IDX                    = 61,
    SBK_NATRON_ANIMATIONLEVELENUM_IDX                        = 1,
    SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX                = 4,
    SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX             = 63,
    SBK_NATRON_VIEWERCOLORSPACEENUM_IDX                      = 62,
    SBK_NATRON_IMAGEBITDEPTHENUM_IDX                         = 3,
    SBK_NATRON_ORIENTATIONENUM_IDX                           = 7,
    SBK_NATRON_PLAYBACKMODEENUM_IDX                          = 9,
    SBK_NATRON_DISPLAYCHANNELSENUM_IDX                       = 2,
    SBK_NATRON_MERGINGFUNCTIONENUM_IDX                       = 6,
    SBK_NatronEngineNATRON_IDX                               = 0,
    SBK_NatronEngineNATRON_PYTHON_IDX                        = 10,
    SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX                      = 11,
    SBK_NATRON_PYTHON_APP_IDX                                = 12,
    SBK_NATRON_PYTHON_APPSETTINGS_IDX                        = 13,
    SBK_NATRON_PYTHON_BEZIERCURVE_IDX                        = 14,
    SBK_NATRON_PYTHON_BOOLNODECREATIONPROPERTY_IDX           = 15,
    SBK_NATRON_PYTHON_BOOLEANPARAM_IDX                       = 16,
    SBK_NATRON_PYTHON_BUTTONPARAM_IDX                        = 17,
    SBK_NATRON_PYTHON_CHOICEPARAM_IDX                        = 18,
    SBK_NATRON_PYTHON_COLORPARAM_IDX                         = 19,
    SBK_NATRON_PYTHON_COLORTUPLE_IDX                         = 20,
    SBK_NATRON_PYTHON_DOUBLE2DPARAM_IDX                      = 21,
    SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX                      = 22,
    SBK_NATRON_PYTHON_DOUBLE3DPARAM_IDX                      = 23,
    SBK_NATRON_PYTHON_DOUBLE3DTUPLE_IDX                      = 24,
    SBK_NATRON_PYTHON_DOUBLEPARAM_IDX                        = 25,
    SBK_NATRON_PYTHON_EFFECT_IDX                             = 26,
    SBK_NATRON_PYTHON_EXPRUTILS_IDX                          = 27,
    SBK_NATRON_PYTHON_FILEPARAM_IDX                          = 28,
    SBK_NATRON_PYTHON_FLOATNODECREATIONPROPERTY_IDX          = 29,
    SBK_NATRON_PYTHON_GROUP_IDX                              = 30,
    SBK_NATRON_PYTHON_GROUPPARAM_IDX                         = 31,
    SBK_NATRON_PYTHON_IMAGELAYER_IDX                         = 32,
    SBK_NATRON_PYTHON_INT2DPARAM_IDX                         = 33,
    SBK_NATRON_PYTHON_INT2DTUPLE_IDX                         = 34,
    SBK_NATRON_PYTHON_INT3DPARAM_IDX                         = 35,
    SBK_NATRON_PYTHON_INT3DTUPLE_IDX                         = 36,
    SBK_NATRON_PYTHON_INTNODECREATIONPROPERTY_IDX            = 37,
    SBK_NATRON_PYTHON_INTPARAM_IDX                           = 38,
    SBK_NATRON_PYTHON_ITEMBASE_IDX                           = 39,
    SBK_NATRON_PYTHON_LAYER_IDX                              = 40,
    SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX               = 41,
    SBK_NATRON_PYTHON_OUTPUTFILEPARAM_IDX                    = 42,
    SBK_NATRON_PYTHON_PAGEPARAM_IDX                          = 43,
    SBK_NATRON_PYTHON_PARAM_IDX                              = 44,
    SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX                    = 45,
    SBK_NATRON_PYTHON_PATHPARAM_IDX                          = 46,
    SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX                  = 47,
    SBK_NATRON_PYTHON_ROTO_IDX                               = 48,
    SBK_NATRON_PYTHON_SEPARATORPARAM_IDX                     = 49,
    SBK_NATRON_PYTHON_STRINGNODECREATIONPROPERTY_IDX         = 50,
    SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX               = 52,
    SBK_NATRON_PYTHON_STRINGPARAM_IDX                        = 51,
    SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX                    = 53,
    SBK_NATRON_PYTHON_TRACK_IDX                              = 54,
    SBK_NATRON_PYTHON_TRACKER_IDX                            = 55,
    SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX                    = 56,
    SBK_NATRON_RECTD_IDX                                     = 57,
    SBK_NATRON_RECTI_IDX                                     = 58,
    SBK_NatronEngine_IDX_COUNT                               = 65
};
// This variable stores all Python types exported by this module.
extern PyTypeObject **SbkNatronEngineTypes;

// This variable stores the Python module object exported by this module.
extern PyObject *SbkNatronEngineModuleObject;

// This variable stores all type converters exported by this module.
extern SbkConverter **SbkNatronEngineTypeConverters;

// Converter indices
enum : int {
    SBK_STD_SIZE_T_IDX                                       = 0,
    SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX = 1, // const std::map<QString,Natron::Python::NodeCreationProperty* > &
    SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX    = 2, // std::list<Natron::Python::Effect* >
    SBK_NATRONENGINE_STD_LIST_QSTRING_IDX                    = 3, // std::list<QString >
    SBK_NATRONENGINE_STD_LIST_INT_IDX                        = 4, // const std::list<int > &
    SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX     = 5, // std::list<Natron::Python::Param* >
    SBK_NATRONENGINE_STD_LIST_DOUBLE_IDX                     = 6, // std::list<double > *
    SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX                     = 7, // const std::vector<bool > &
    SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX            = 8, // std::pair<QString,QString >
    SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX   = 9, // const std::list<std::pair< QString,QString > > &
    SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_IMAGELAYER_IDX   = 10, // std::list<Natron::Python::ImageLayer >
    SBK_NATRONENGINE_STD_VECTOR_DOUBLE_IDX                   = 11, // const std::vector<double > &
    SBK_NATRONENGINE_STD_VECTOR_INT_IDX                      = 12, // const std::vector<int > &
    SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_ITEMBASEPTR_IDX  = 13, // std::list<Natron::Python::ItemBase* >
    SBK_NATRONENGINE_STD_VECTOR_NATRON_RECTI_IDX             = 14, // std::vector<Natron::RectI >
    SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX               = 15, // std::vector<std::string > *
    SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_TRACKPTR_IDX     = 16, // std::list<Natron::Python::Track* > *
    SBK_NATRONENGINE_STD_LIST_STD_VECTOR_STD_STRING_IDX      = 17, // std::list<std::vector< std::string > > *
    SBK_NATRONENGINE_QLIST_QVARIANT_IDX                      = 18, // QList<QVariant >
    SBK_NATRONENGINE_QLIST_QSTRING_IDX                       = 19, // QList<QString >
    SBK_NATRONENGINE_QMAP_QSTRING_QVARIANT_IDX               = 20, // QMap<QString,QVariant >
    SBK_NatronEngine_CONVERTERS_IDX_COUNT                    = 21
};
// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
template<> inline PyTypeObject *SbkType< ::Natron::StatusEnum >() { return SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::StandardButtonEnum >() { return SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::QFlags<Natron::StandardButtonEnum> >() { return SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::KeyframeTypeEnum >() { return SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::PixmapEnum >() { return SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::ValueChangedReasonEnum >() { return SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::AnimationLevelEnum >() { return SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::ImagePremultiplicationEnum >() { return SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::ViewerCompositingOperatorEnum >() { return SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::ViewerColorSpaceEnum >() { return SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::ImageBitDepthEnum >() { return SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::OrientationEnum >() { return SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::PlaybackModeEnum >() { return SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::DisplayChannelsEnum >() { return SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::MergingFunctionEnum >() { return SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::Python::AnimatedParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::App >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::AppSettings >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APPSETTINGS_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::BezierCurve >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::BoolNodeCreationProperty >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BOOLNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::BooleanParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BOOLEANPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ButtonParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BUTTONPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ChoiceParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ColorParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ColorTuple >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORTUPLE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Double2DParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Double2DTuple >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Double3DParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE3DPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Double3DTuple >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE3DTUPLE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::DoubleParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLEPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Effect >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ExprUtils >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EXPRUTILS_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::FileParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::FloatNodeCreationProperty >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FLOATNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Group >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::GroupParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ImageLayer >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_IMAGELAYER_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Int2DParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT2DPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Int2DTuple >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT2DTUPLE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Int3DParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Int3DTuple >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DTUPLE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::IntNodeCreationProperty >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INTNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::IntParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INTPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ItemBase >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Layer >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_LAYER_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::NodeCreationProperty >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::OutputFileParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_OUTPUTFILEPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::PageParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PAGEPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Param >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::ParametricParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::PathParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PATHPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::PyCoreApplication >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Roto >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ROTO_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::SeparatorParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_SEPARATORPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::StringNodeCreationProperty >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::StringParam::TypeEnum >() { return SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX]; }
template<> inline PyTypeObject *SbkType< ::Natron::Python::StringParam >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::StringParamBase >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Track >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_TRACK_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::Tracker >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_TRACKER_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::Python::UserParamHolder >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::RectD >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]); }
template<> inline PyTypeObject *SbkType< ::Natron::RectI >() { return reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]); }
QT_WARNING_POP

} // namespace Shiboken

#endif // SBK_NATRONENGINE_PYTHON_H

