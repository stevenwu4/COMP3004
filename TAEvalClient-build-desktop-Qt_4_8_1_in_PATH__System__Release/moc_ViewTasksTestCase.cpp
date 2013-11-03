/****************************************************************************
** Meta object code from reading C++ file 'ViewTasksTestCase.h'
**
** Created: Sun Nov 3 01:04:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/ViewTasksTestCase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewTasksTestCase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewTasksTestCase[] = {

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
      27,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   42,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ViewTasksTestCase[] = {
    "ViewTasksTestCase\0\0success\0complete(bool)\0"
    "taskList\0run(std::vector<Task>)\0"
};

void ViewTasksTestCase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewTasksTestCase *_t = static_cast<ViewTasksTestCase *>(_o);
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->run((*reinterpret_cast< const std::vector<Task>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ViewTasksTestCase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewTasksTestCase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ViewTasksTestCase,
      qt_meta_data_ViewTasksTestCase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewTasksTestCase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewTasksTestCase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewTasksTestCase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewTasksTestCase))
        return static_cast<void*>(const_cast< ViewTasksTestCase*>(this));
    return QObject::qt_metacast(_clname);
}

int ViewTasksTestCase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ViewTasksTestCase::complete(bool _t1)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< ViewTasksTestCase *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
