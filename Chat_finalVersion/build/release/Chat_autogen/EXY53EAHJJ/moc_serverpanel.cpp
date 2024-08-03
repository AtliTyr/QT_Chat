/****************************************************************************
** Meta object code from reading C++ file 'serverpanel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../sources/serverpanel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSServerPanelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSServerPanelENDCLASS = QtMocHelpers::stringData(
    "ServerPanel",
    "actionButtonProcessing",
    "",
    "QAction*",
    "banButtonClicked",
    "unBanButtonClicked",
    "muteButtonClicked",
    "unMuteButtonClicked",
    "kickButtonClicked",
    "on_TypeUserNameEdit_returnPressed",
    "on_UsersList_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_typeCommandEdit_returnPressed",
    "on_SendToEveryoneButton_clicked",
    "on_SendPrivateButton_clicked",
    "on_searchOptionsButton_clicked",
    "on_searchButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSServerPanelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x0a,    1 /* Public */,
       4,    0,   95,    2, 0x0a,    3 /* Public */,
       5,    0,   96,    2, 0x0a,    4 /* Public */,
       6,    0,   97,    2, 0x0a,    5 /* Public */,
       7,    0,   98,    2, 0x0a,    6 /* Public */,
       8,    0,   99,    2, 0x0a,    7 /* Public */,
       9,    0,  100,    2, 0x08,    8 /* Private */,
      10,    1,  101,    2, 0x08,    9 /* Private */,
      13,    0,  104,    2, 0x08,   11 /* Private */,
      14,    0,  105,    2, 0x08,   12 /* Private */,
      15,    0,  106,    2, 0x08,   13 /* Private */,
      16,    0,  107,    2, 0x08,   14 /* Private */,
      17,    0,  108,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ServerPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSServerPanelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSServerPanelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSServerPanelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ServerPanel, std::true_type>,
        // method 'actionButtonProcessing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAction *, std::false_type>,
        // method 'banButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'unBanButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'muteButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'unMuteButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'kickButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_TypeUserNameEdit_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_UsersList_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_typeCommandEdit_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SendToEveryoneButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SendPrivateButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchOptionsButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ServerPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerPanel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->actionButtonProcessing((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 1: _t->banButtonClicked(); break;
        case 2: _t->unBanButtonClicked(); break;
        case 3: _t->muteButtonClicked(); break;
        case 4: _t->unMuteButtonClicked(); break;
        case 5: _t->kickButtonClicked(); break;
        case 6: _t->on_TypeUserNameEdit_returnPressed(); break;
        case 7: _t->on_UsersList_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 8: _t->on_typeCommandEdit_returnPressed(); break;
        case 9: _t->on_SendToEveryoneButton_clicked(); break;
        case 10: _t->on_SendPrivateButton_clicked(); break;
        case 11: _t->on_searchOptionsButton_clicked(); break;
        case 12: _t->on_searchButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *ServerPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSServerPanelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ServerPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
