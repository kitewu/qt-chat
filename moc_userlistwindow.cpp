/****************************************************************************
** Meta object code from reading C++ file 'userlistwindow.h'
**
** Created: Tue Jun 6 16:33:17 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userlistwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userlistwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserListWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   16,   15,   15, 0x0a,
      78,   76,   15,   15, 0x0a,
     101,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UserListWindow[] = {
    "UserListWindow\0\0msg\0send_to_mainwindow(QString)\0"
    "read_msg_from_chat(QString)\0,\0"
    "new_chat_wind(int,int)\0"
    "close_chat_window(QString)\0"
};

void UserListWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserListWindow *_t = static_cast<UserListWindow *>(_o);
        switch (_id) {
        case 0: _t->send_to_mainwindow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->read_msg_from_chat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->new_chat_wind((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->close_chat_window((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UserListWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserListWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UserListWindow,
      qt_meta_data_UserListWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserListWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserListWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserListWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserListWindow))
        return static_cast<void*>(const_cast< UserListWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UserListWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void UserListWindow::send_to_mainwindow(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
