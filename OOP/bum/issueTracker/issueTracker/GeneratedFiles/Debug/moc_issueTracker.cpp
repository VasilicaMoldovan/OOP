/****************************************************************************
** Meta object code from reading C++ file 'issueTracker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../issueTracker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'issueTracker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_issueTracker_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_issueTracker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_issueTracker_t qt_meta_stringdata_issueTracker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "issueTracker"
QT_MOC_LITERAL(1, 13, 9), // "handleAdd"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "handleRemove"
QT_MOC_LITERAL(4, 37, 12), // "handleSelect"
QT_MOC_LITERAL(5, 50, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 67, 1), // "h"
QT_MOC_LITERAL(7, 69, 13) // "handleResolve"

    },
    "issueTracker\0handleAdd\0\0handleRemove\0"
    "handleSelect\0QListWidgetItem*\0h\0"
    "handleResolve"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_issueTracker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void issueTracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<issueTracker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleAdd(); break;
        case 1: _t->handleRemove(); break;
        case 2: _t->handleSelect((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->handleResolve(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject issueTracker::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_issueTracker.data,
    qt_meta_data_issueTracker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *issueTracker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *issueTracker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_issueTracker.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Observer"))
        return static_cast< Observer*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int issueTracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
