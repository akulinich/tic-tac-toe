/****************************************************************************
** Meta object code from reading C++ file 'game_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameWidget_t {
    QByteArrayData data[13];
    char stringdata[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWidget_t qt_meta_stringdata_GameWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 7),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 9),
QT_MOC_LITERAL(4, 30, 12),
QT_MOC_LITERAL(5, 43, 8),
QT_MOC_LITERAL(6, 52, 12),
QT_MOC_LITERAL(7, 65, 7),
QT_MOC_LITERAL(8, 73, 7),
QT_MOC_LITERAL(9, 81, 4),
QT_MOC_LITERAL(10, 86, 17),
QT_MOC_LITERAL(11, 104, 14),
QT_MOC_LITERAL(12, 119, 14)
    },
    "GameWidget\0endGame\0\0GameState\0"
    "mouseClicked\0Position\0raizeEndGame\0"
    "newGame\0addTurn\0Turn\0setPlayerVsPlayer\0"
    "setPlayerVsCPU\0setPlayerVsNet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    1,   62,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameWidget *_t = static_cast<GameWidget *>(_o);
        switch (_id) {
        case 0: _t->endGame((*reinterpret_cast< GameState(*)>(_a[1]))); break;
        case 1: _t->mouseClicked((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 2: _t->raizeEndGame(); break;
        case 3: _t->newGame(); break;
        case 4: _t->addTurn((*reinterpret_cast< Turn(*)>(_a[1]))); break;
        case 5: _t->setPlayerVsPlayer(); break;
        case 6: _t->setPlayerVsCPU(); break;
        case 7: _t->setPlayerVsNet(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameWidget::*_t)(GameState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidget::endGame)) {
                *result = 0;
            }
        }
        {
            typedef void (GameWidget::*_t)(Position );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidget::mouseClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GameWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameWidget.data,
      qt_meta_data_GameWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidget.stringdata))
        return static_cast<void*>(const_cast< GameWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GameWidget::endGame(GameState _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameWidget::mouseClicked(Position _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
