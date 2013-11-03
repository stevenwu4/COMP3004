/****************************************************************************
** Meta object code from reading C++ file 'ViewTeachingAssistantsTestCase.h'
**
** Created: Sun Nov 3 01:04:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/ViewTeachingAssistantsTestCase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewTeachingAssistantsTestCase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewTeachingAssistantsTestCase[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      40,   32,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   55,   31,   31, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ViewTeachingAssistantsTestCase[] = {
    "ViewTeachingAssistantsTestCase\0\0success\0"
    "complete(bool)\0teachingAssistantList\0"
    "run(std::vector<TeachingAssistant>)\0"
};

void ViewTeachingAssistantsTestCase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewTeachingAssistantsTestCase *_t = static_cast<ViewTeachingAssistantsTestCase *>(_o);
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->run((*reinterpret_cast< const std::vector<TeachingAssistant>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ViewTeachingAssistantsTestCase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewTeachingAssistantsTestCase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ViewTeachingAssistantsTestCase,
      qt_meta_data_ViewTeachingAssistantsTestCase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewTeachingAssistantsTestCase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewTeachingAssistantsTestCase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewTeachingAssistantsTestCase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewTeachingAssistantsTestCase))
        return static_cast<void*>(const_cast< ViewTeachingAssistantsTestCase*>(this));
    return QObject::qt_metacast(_clname);
}

int ViewTeachingAssistantsTestCase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ViewTeachingAssistantsTestCase::complete(bool _t1)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< ViewTeachingAssistantsTestCase *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
