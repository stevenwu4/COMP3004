/****************************************************************************
** Meta object code from reading C++ file 'LoginController.h'
**
** Created: Mon Dec 9 22:22:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/LoginController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoginController[] = {

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
      24,   17,   16,   16, 0x08,
      43,   16,   16,   16, 0x08,
      59,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LoginController[] = {
    "LoginController\0\0result\0loginFinished(int)\0"
    "termListReady()\0loginTimedOut()\0"
};

void LoginController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoginController *_t = static_cast<LoginController *>(_o);
        switch (_id) {
        case 0: _t->loginFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->termListReady(); break;
        case 2: _t->loginTimedOut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LoginController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoginController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LoginController,
      qt_meta_data_LoginController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoginController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoginController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoginController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoginController))
        return static_cast<void*>(const_cast< LoginController*>(this));
    return QObject::qt_metacast(_clname);
}

int LoginController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
