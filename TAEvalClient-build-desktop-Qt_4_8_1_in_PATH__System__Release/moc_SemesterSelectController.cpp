/****************************************************************************
** Meta object code from reading C++ file 'SemesterSelectController.h'
**
** Created: Mon Dec 9 22:47:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/SemesterSelectController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SemesterSelectController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SemesterSelectController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x08,
      42,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SemesterSelectController[] = {
    "SemesterSelectController\0\0termRetrieved()\0"
    "timeout()\0"
};

void SemesterSelectController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SemesterSelectController *_t = static_cast<SemesterSelectController *>(_o);
        switch (_id) {
        case 0: _t->termRetrieved(); break;
        case 1: _t->timeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SemesterSelectController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SemesterSelectController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SemesterSelectController,
      qt_meta_data_SemesterSelectController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SemesterSelectController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SemesterSelectController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SemesterSelectController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SemesterSelectController))
        return static_cast<void*>(const_cast< SemesterSelectController*>(this));
    return QObject::qt_metacast(_clname);
}

int SemesterSelectController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
