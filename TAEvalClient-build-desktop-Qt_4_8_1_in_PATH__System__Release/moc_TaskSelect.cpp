/****************************************************************************
** Meta object code from reading C++ file 'TaskSelect.h'
**
** Created: Tue Dec 10 02:18:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/TaskSelect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskSelect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TaskSelect[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     192,  190,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TaskSelect[] = {
    "TaskSelect\0\0on_semesterButton_clicked()\0"
    "on_courseButton_clicked()\0"
    "on_createButton_clicked()\0"
    "on_editButton_clicked()\0on_evalButton_clicked()\0"
    "on_deleteButton_clicked()\0"
    "on_quitButton_clicked()\0m\0alert(QString)\0"
};

void TaskSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TaskSelect *_t = static_cast<TaskSelect *>(_o);
        switch (_id) {
        case 0: _t->on_semesterButton_clicked(); break;
        case 1: _t->on_courseButton_clicked(); break;
        case 2: _t->on_createButton_clicked(); break;
        case 3: _t->on_editButton_clicked(); break;
        case 4: _t->on_evalButton_clicked(); break;
        case 5: _t->on_deleteButton_clicked(); break;
        case 6: _t->on_quitButton_clicked(); break;
        case 7: _t->alert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TaskSelect::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TaskSelect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TaskSelect,
      qt_meta_data_TaskSelect, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TaskSelect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TaskSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TaskSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TaskSelect))
        return static_cast<void*>(const_cast< TaskSelect*>(this));
    return QWidget::qt_metacast(_clname);
}

int TaskSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE