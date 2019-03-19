/****************************************************************************
** Meta object code from reading C++ file 'cheat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CSC3002_GAME/cheat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cheat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cheat_t {
    QByteArrayData data[11];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cheat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cheat_t qt_meta_stringdata_Cheat = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Cheat"
QT_MOC_LITERAL(1, 6, 6), // "change"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 15), // "slotCheatEnergy"
QT_MOC_LITERAL(4, 30, 11), // "slotCheatIQ"
QT_MOC_LITERAL(5, 42, 11), // "slotCheatEQ"
QT_MOC_LITERAL(6, 54, 14), // "slotCheatCharm"
QT_MOC_LITERAL(7, 69, 14), // "slotCheatMoney"
QT_MOC_LITERAL(8, 84, 14), // "slotCheatGrade"
QT_MOC_LITERAL(9, 99, 13), // "slotCheatLike"
QT_MOC_LITERAL(10, 113, 13) // "slotCheatMode"

    },
    "Cheat\0change\0\0slotCheatEnergy\0slotCheatIQ\0"
    "slotCheatEQ\0slotCheatCharm\0slotCheatMoney\0"
    "slotCheatGrade\0slotCheatLike\0slotCheatMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cheat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cheat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cheat *_t = static_cast<Cheat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change(); break;
        case 1: _t->slotCheatEnergy(); break;
        case 2: _t->slotCheatIQ(); break;
        case 3: _t->slotCheatEQ(); break;
        case 4: _t->slotCheatCharm(); break;
        case 5: _t->slotCheatMoney(); break;
        case 6: _t->slotCheatGrade(); break;
        case 7: _t->slotCheatLike(); break;
        case 8: _t->slotCheatMode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cheat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cheat::change)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Cheat::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Cheat.data,
      qt_meta_data_Cheat,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Cheat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cheat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cheat.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cheat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Cheat::change()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
