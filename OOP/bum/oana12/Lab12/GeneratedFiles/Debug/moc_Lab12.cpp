/****************************************************************************
** Meta object code from reading C++ file 'Lab12.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab12.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Lab12.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Lab12_t {
    QByteArrayData data[15];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Lab12_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Lab12_t qt_meta_stringdata_Lab12 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Lab12"
QT_MOC_LITERAL(1, 6, 15), // "handleAddButton"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "handleUpdateButton"
QT_MOC_LITERAL(4, 42, 18), // "handleRemoveButton"
QT_MOC_LITERAL(5, 61, 18), // "handleSaveIDButton"
QT_MOC_LITERAL(6, 80, 16), // "handleSaveButton"
QT_MOC_LITERAL(7, 97, 26), // "handleOpenExternallyButton"
QT_MOC_LITERAL(8, 124, 16), // "handleNextButton"
QT_MOC_LITERAL(9, 141, 20), // "handleUserlistButton"
QT_MOC_LITERAL(10, 162, 25), // "handleFilterByLikesButton"
QT_MOC_LITERAL(11, 188, 30), // "handleFilterByLikesGenreButton"
QT_MOC_LITERAL(12, 219, 20), // "handleLoadFileButton"
QT_MOC_LITERAL(13, 240, 16), // "handleUndoButton"
QT_MOC_LITERAL(14, 257, 16) // "handleRedoButton"

    },
    "Lab12\0handleAddButton\0\0handleUpdateButton\0"
    "handleRemoveButton\0handleSaveIDButton\0"
    "handleSaveButton\0handleOpenExternallyButton\0"
    "handleNextButton\0handleUserlistButton\0"
    "handleFilterByLikesButton\0"
    "handleFilterByLikesGenreButton\0"
    "handleLoadFileButton\0handleUndoButton\0"
    "handleRedoButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Lab12[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void Lab12::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Lab12 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleAddButton(); break;
        case 1: _t->handleUpdateButton(); break;
        case 2: _t->handleRemoveButton(); break;
        case 3: _t->handleSaveIDButton(); break;
        case 4: _t->handleSaveButton(); break;
        case 5: _t->handleOpenExternallyButton(); break;
        case 6: _t->handleNextButton(); break;
        case 7: _t->handleUserlistButton(); break;
        case 8: _t->handleFilterByLikesButton(); break;
        case 9: _t->handleFilterByLikesGenreButton(); break;
        case 10: _t->handleLoadFileButton(); break;
        case 11: _t->handleUndoButton(); break;
        case 12: _t->handleRedoButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Lab12::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Lab12.data,
    qt_meta_data_Lab12,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Lab12::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Lab12::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Lab12.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Lab12::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
