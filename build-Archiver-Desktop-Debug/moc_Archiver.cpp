/****************************************************************************
** Meta object code from reading C++ file 'Archiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Archiver/Archiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Archiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Archiver_t {
    QByteArrayData data[12];
    char stringdata[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Archiver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Archiver_t qt_meta_stringdata_Archiver = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 22),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 22),
QT_MOC_LITERAL(4, 56, 26),
QT_MOC_LITERAL(5, 83, 27),
QT_MOC_LITERAL(6, 111, 25),
QT_MOC_LITERAL(7, 137, 23),
QT_MOC_LITERAL(8, 161, 5),
QT_MOC_LITERAL(9, 167, 8),
QT_MOC_LITERAL(10, 176, 26),
QT_MOC_LITERAL(11, 203, 18)
    },
    "Archiver\0on_file_button_clicked\0\0"
    "on_save_button_clicked\0"
    "on_retrieve_button_clicked\0"
    "on_reference_button_clicked\0"
    "on_comment_button_clicked\0"
    "on_fileviewer_activated\0index\0populate\0"
    "retrieveVersionDataForFile\0"
    "createFirstVersion\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Archiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08,
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    0,   62,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    1,   64,    2, 0x08,
       9,    0,   67,    2, 0x08,
      10,    0,   68,    2, 0x08,
      11,    0,   69,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Archiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Archiver *_t = static_cast<Archiver *>(_o);
        switch (_id) {
        case 0: _t->on_file_button_clicked(); break;
        case 1: _t->on_save_button_clicked(); break;
        case 2: _t->on_retrieve_button_clicked(); break;
        case 3: _t->on_reference_button_clicked(); break;
        case 4: _t->on_comment_button_clicked(); break;
        case 5: _t->on_fileviewer_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->populate(); break;
        case 7: _t->retrieveVersionDataForFile(); break;
        case 8: _t->createFirstVersion(); break;
        default: ;
        }
    }
}

const QMetaObject Archiver::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Archiver.data,
      qt_meta_data_Archiver,  qt_static_metacall, 0, 0}
};


const QMetaObject *Archiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Archiver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Archiver.stringdata))
        return static_cast<void*>(const_cast< Archiver*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Archiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
