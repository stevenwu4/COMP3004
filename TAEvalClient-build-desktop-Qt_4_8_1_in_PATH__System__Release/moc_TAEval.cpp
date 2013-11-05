/****************************************************************************
** Meta object code from reading C++ file 'TAEval.h'
**
** Created: Mon Nov 4 23:50:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/TAEval.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TAEval.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TAEval[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,    8,    7,    7, 0x05,
      80,   58,    7,    7, 0x05,
     150,  141,    7,    7, 0x05,
     190,  185,    7,    7, 0x05,
     223,  215,    7,    7, 0x05,
     241,  185,    7,    7, 0x05,
     265,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     303,  283,    7,    7, 0x08,
     344,    7,    7,    7, 0x08,
     361,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TAEval[] = {
    "TAEval\0\0courseList\0"
    "courseListUpdated(std::vector<Course>)\0"
    "teachingAssistantList\0"
    "teachingAssistantListUpdated(std::vector<TeachingAssistant>)\0"
    "taskList\0taskListUpdated(std::vector<Task>)\0"
    "task\0taskCreated(const Task*)\0success\0"
    "taskDeleted(bool)\0taskEdited(const Task*)\0"
    "requestTimedOut()\0packetId,packetData\0"
    "processPacket(unsigned short,QByteArray)\0"
    "requestTimeout()\0initialize()\0"
};

void TAEval::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TAEval *_t = static_cast<TAEval *>(_o);
        switch (_id) {
        case 0: _t->courseListUpdated((*reinterpret_cast< const std::vector<Course>(*)>(_a[1]))); break;
        case 1: _t->teachingAssistantListUpdated((*reinterpret_cast< const std::vector<TeachingAssistant>(*)>(_a[1]))); break;
        case 2: _t->taskListUpdated((*reinterpret_cast< const std::vector<Task>(*)>(_a[1]))); break;
        case 3: _t->taskCreated((*reinterpret_cast< const Task*(*)>(_a[1]))); break;
        case 4: _t->taskDeleted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->taskEdited((*reinterpret_cast< const Task*(*)>(_a[1]))); break;
        case 6: _t->requestTimedOut(); break;
        case 7: _t->processPacket((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 8: _t->requestTimeout(); break;
        case 9: _t->initialize(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TAEval::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TAEval::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TAEval,
      qt_meta_data_TAEval, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TAEval::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TAEval::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TAEval::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TAEval))
        return static_cast<void*>(const_cast< TAEval*>(this));
    return QObject::qt_metacast(_clname);
}

int TAEval::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void TAEval::courseListUpdated(const std::vector<Course> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TAEval::teachingAssistantListUpdated(const std::vector<TeachingAssistant> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TAEval::taskListUpdated(const std::vector<Task> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TAEval::taskCreated(const Task * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TAEval::taskDeleted(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TAEval::taskEdited(const Task * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TAEval::requestTimedOut()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
