/****************************************************************************
** Meta object code from reading C++ file 'ViewCoursesTestCase.h'
**
** Created: Sun Dec 8 18:24:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/ViewCoursesTestCase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewCoursesTestCase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewCoursesTestCase[] = {

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
      38,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   57,   20,   20, 0x0a,
      93,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ViewCoursesTestCase[] = {
    "ViewCoursesTestCase\0\0success,testcase\0"
    "complete(bool,int)\0courseList\0"
    "run(std::vector<Course>)\0timeout()\0"
};

void ViewCoursesTestCase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewCoursesTestCase *_t = static_cast<ViewCoursesTestCase *>(_o);
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->run((*reinterpret_cast< const std::vector<Course>(*)>(_a[1]))); break;
        case 2: _t->timeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ViewCoursesTestCase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewCoursesTestCase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ViewCoursesTestCase,
      qt_meta_data_ViewCoursesTestCase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewCoursesTestCase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewCoursesTestCase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewCoursesTestCase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewCoursesTestCase))
        return static_cast<void*>(const_cast< ViewCoursesTestCase*>(this));
    return QObject::qt_metacast(_clname);
}

int ViewCoursesTestCase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ViewCoursesTestCase::complete(bool _t1, int _t2)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< ViewCoursesTestCase *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE