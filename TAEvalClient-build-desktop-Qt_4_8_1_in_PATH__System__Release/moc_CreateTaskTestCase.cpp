/****************************************************************************
** Meta object code from reading C++ file 'CreateTaskTestCase.h'
**
** Created: Tue Nov 5 00:08:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/CreateTaskTestCase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateTaskTestCase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CreateTaskTestCase[] = {

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
      37,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   56,   19,   19, 0x0a,
      78,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CreateTaskTestCase[] = {
    "CreateTaskTestCase\0\0success,testCase\0"
    "complete(bool,int)\0task\0run(const Task*)\0"
    "timeout()\0"
};

void CreateTaskTestCase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CreateTaskTestCase *_t = static_cast<CreateTaskTestCase *>(_o);
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->run((*reinterpret_cast< const Task*(*)>(_a[1]))); break;
        case 2: _t->timeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CreateTaskTestCase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CreateTaskTestCase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CreateTaskTestCase,
      qt_meta_data_CreateTaskTestCase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreateTaskTestCase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreateTaskTestCase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreateTaskTestCase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateTaskTestCase))
        return static_cast<void*>(const_cast< CreateTaskTestCase*>(this));
    return QObject::qt_metacast(_clname);
}

int CreateTaskTestCase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CreateTaskTestCase::complete(bool _t1, int _t2)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< CreateTaskTestCase *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
