/****************************************************************************
** Meta object code from reading C++ file 'CourseSelectController.h'
**
** Created: Tue Dec 10 07:16:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/CourseSelectController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CourseSelectController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CourseSelectController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      42,   23,   23,   23, 0x08,
      60,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CourseSelectController[] = {
    "CourseSelectController\0\0courseRetrieved()\0"
    "taListRetrieved()\0timeout()\0"
};

void CourseSelectController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CourseSelectController *_t = static_cast<CourseSelectController *>(_o);
        switch (_id) {
        case 0: _t->courseRetrieved(); break;
        case 1: _t->taListRetrieved(); break;
        case 2: _t->timeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CourseSelectController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CourseSelectController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CourseSelectController,
      qt_meta_data_CourseSelectController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CourseSelectController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CourseSelectController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CourseSelectController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CourseSelectController))
        return static_cast<void*>(const_cast< CourseSelectController*>(this));
    return QObject::qt_metacast(_clname);
}

int CourseSelectController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
