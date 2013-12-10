/****************************************************************************
** Meta object code from reading C++ file 'EditTaskTestCase.h'
**
** Created: Sun Dec 8 18:24:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/EditTaskTestCase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditTaskTestCase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditTaskTestCase[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   54,   17,   17, 0x0a,
      76,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EditTaskTestCase[] = {
    "EditTaskTestCase\0\0success,testCase\0"
    "complete(bool,int)\0task\0run(const Task*)\0"
    "timeout()\0"
};

void EditTaskTestCase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditTaskTestCase *_t = static_cast<EditTaskTestCase *>(_o);
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->run((*reinterpret_cast< const Task*(*)>(_a[1]))); break;
        case 2: _t->timeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditTaskTestCase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditTaskTestCase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EditTaskTestCase,
      qt_meta_data_EditTaskTestCase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditTaskTestCase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditTaskTestCase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditTaskTestCase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditTaskTestCase))
        return static_cast<void*>(const_cast< EditTaskTestCase*>(this));
    return QObject::qt_metacast(_clname);
}

int EditTaskTestCase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void EditTaskTestCase::complete(bool _t1, int _t2)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< EditTaskTestCase *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
