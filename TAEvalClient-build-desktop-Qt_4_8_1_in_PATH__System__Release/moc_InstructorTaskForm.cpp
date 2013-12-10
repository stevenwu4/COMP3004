/****************************************************************************
** Meta object code from reading C++ file 'InstructorTaskForm.h'
**
** Created: Tue Dec 10 02:18:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TAEvalClient/InstructorTaskForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InstructorTaskForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InstructorTaskForm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      46,   19,   19,   19, 0x08,
      68,   19,   19,   19, 0x08,
      88,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InstructorTaskForm[] = {
    "InstructorTaskForm\0\0on_cancelButton_clicked()\0"
    "on_okButton_clicked()\0fillFields(TAEval*)\0"
    "alert(QString)\0"
};

void InstructorTaskForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InstructorTaskForm *_t = static_cast<InstructorTaskForm *>(_o);
        switch (_id) {
        case 0: _t->on_cancelButton_clicked(); break;
        case 1: _t->on_okButton_clicked(); break;
        case 2: _t->fillFields((*reinterpret_cast< TAEval*(*)>(_a[1]))); break;
        case 3: _t->alert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InstructorTaskForm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InstructorTaskForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InstructorTaskForm,
      qt_meta_data_InstructorTaskForm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InstructorTaskForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InstructorTaskForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InstructorTaskForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InstructorTaskForm))
        return static_cast<void*>(const_cast< InstructorTaskForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int InstructorTaskForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
