/****************************************************************************
** Meta object code from reading C++ file 'Archiver.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Archiver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Archiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Archiver[] = {

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
      10,    9,    9,    9, 0x08,
      35,    9,    9,    9, 0x08,
      60,    9,    9,    9, 0x08,
      89,    9,    9,    9, 0x08,
     119,    9,    9,    9, 0x08,
     153,  147,    9,    9, 0x08,
     179,    9,    9,    9, 0x08,
     208,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Archiver[] = {
    "Archiver\0\0on_file_button_clicked()\0"
    "on_save_button_clicked()\0"
    "on_retrieve_button_clicked()\0"
    "on_reference_button_clicked()\0"
    "on_comment_button_clicked()\0index\0"
    "clickedModel(QModelIndex)\0"
    "retrieveVersionDataForFile()\0"
    "createFirstVersion()\0"
};

void Archiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Archiver *_t = static_cast<Archiver *>(_o);
        switch (_id) {
        case 0: _t->on_file_button_clicked(); break;
        case 1: _t->on_save_button_clicked(); break;
        case 2: _t->on_retrieve_button_clicked(); break;
        case 3: _t->on_reference_button_clicked(); break;
        case 4: _t->on_comment_button_clicked(); break;
        case 5: _t->clickedModel((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->retrieveVersionDataForFile(); break;
        case 7: _t->createFirstVersion(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Archiver::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Archiver::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Archiver,
      qt_meta_data_Archiver, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Archiver::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Archiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Archiver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Archiver))
        return static_cast<void*>(const_cast< Archiver*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Archiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
