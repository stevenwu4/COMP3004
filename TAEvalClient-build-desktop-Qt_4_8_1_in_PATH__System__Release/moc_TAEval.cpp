/****************************************************************************
** Meta object code from reading C++ file 'TAEval.h'
**
** Created: Tue Dec 10 04:24:36 2013
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    8,    7,    7, 0x05,
      43,   34,    7,    7, 0x05,
      89,   78,    7,    7, 0x05,
     150,  128,    7,    7, 0x05,
     220,  211,    7,    7, 0x05,
     263,  255,    7,    7, 0x05,
     281,  255,    7,    7, 0x05,
     304,  299,    7,    7, 0x05,
     328,  299,    7,    7, 0x05,
     353,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     391,  371,    7,    7, 0x08,
     432,    7,    7,    7, 0x08,
     449,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TAEval[] = {
    "TAEval\0\0result\0loginComplete(int)\0"
    "termList\0termListUpdated(std::vector<Term>)\0"
    "courseList\0courseListUpdated(std::vector<Course>)\0"
    "teachingAssistantList\0"
    "teachingAssistantListUpdated(std::vector<TeachingAssistant>)\0"
    "taskList\0taskListUpdated(std::vector<Task>)\0"
    "success\0taskCreated(bool)\0taskDeleted(bool)\0"
    "task\0taskEdited(const Task*)\0"
    "taskUpdated(const Task*)\0requestTimedOut()\0"
    "packetId,packetData\0"
    "processPacket(unsigned short,QByteArray)\0"
    "requestTimeout()\0initialize()\0"
};

void TAEval::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TAEval *_t = static_cast<TAEval *>(_o);
        switch (_id) {
        case 0: _t->loginComplete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->termListUpdated((*reinterpret_cast< const std::vector<Term>(*)>(_a[1]))); break;
        case 2: _t->courseListUpdated((*reinterpret_cast< const std::vector<Course>(*)>(_a[1]))); break;
        case 3: _t->teachingAssistantListUpdated((*reinterpret_cast< const std::vector<TeachingAssistant>(*)>(_a[1]))); break;
        case 4: _t->taskListUpdated((*reinterpret_cast< const std::vector<Task>(*)>(_a[1]))); break;
        case 5: _t->taskCreated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->taskDeleted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->taskEdited((*reinterpret_cast< const Task*(*)>(_a[1]))); break;
        case 8: _t->taskUpdated((*reinterpret_cast< const Task*(*)>(_a[1]))); break;
        case 9: _t->requestTimedOut(); break;
        case 10: _t->processPacket((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 11: _t->requestTimeout(); break;
        case 12: _t->initialize(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TAEval::loginComplete(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TAEval::termListUpdated(const std::vector<Term> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TAEval::courseListUpdated(const std::vector<Course> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TAEval::teachingAssistantListUpdated(const std::vector<TeachingAssistant> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TAEval::taskListUpdated(const std::vector<Task> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TAEval::taskCreated(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TAEval::taskDeleted(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TAEval::taskEdited(const Task * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TAEval::taskUpdated(const Task * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TAEval::requestTimedOut()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
