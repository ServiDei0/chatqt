/****************************************************************************
** Meta object code from reading C++ file 'clientClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_clientClass_t {
    QByteArrayData data[10];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_clientClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_clientClass_t qt_meta_stringdata_clientClass = {
    {
QT_MOC_LITERAL(0, 0, 11), // "clientClass"
QT_MOC_LITERAL(1, 12, 9), // "readyRead"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "disconnected"
QT_MOC_LITERAL(4, 36, 7), // "sendMSG"
QT_MOC_LITERAL(5, 44, 3), // "msg"
QT_MOC_LITERAL(6, 48, 4), // "send"
QT_MOC_LITERAL(7, 53, 15), // "insertToHistory"
QT_MOC_LITERAL(8, 69, 7), // "message"
QT_MOC_LITERAL(9, 77, 11) // "loadHistory"

    },
    "clientClass\0readyRead\0\0disconnected\0"
    "sendMSG\0msg\0send\0insertToHistory\0"
    "message\0loadHistory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clientClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::QString,

       0        // eod
};

void clientClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        clientClass *_t = static_cast<clientClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyRead(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->sendMSG((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->send(); break;
        case 4: _t->insertToHistory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { QString _r = _t->loadHistory();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject clientClass::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_clientClass.data,
    qt_meta_data_clientClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *clientClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clientClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_clientClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int clientClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
