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
    QByteArrayData data[24];
    char stringdata[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWidget_t qt_meta_stringdata_GameWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 9),
QT_MOC_LITERAL(4, 36, 18),
QT_MOC_LITERAL(5, 55, 8),
QT_MOC_LITERAL(6, 64, 17),
QT_MOC_LITERAL(7, 82, 12),
QT_MOC_LITERAL(8, 95, 17),
QT_MOC_LITERAL(9, 113, 16),
QT_MOC_LITERAL(10, 130, 12),
QT_MOC_LITERAL(11, 143, 5),
QT_MOC_LITERAL(12, 149, 7),
QT_MOC_LITERAL(13, 157, 17),
QT_MOC_LITERAL(14, 175, 14),
QT_MOC_LITERAL(15, 190, 14),
QT_MOC_LITERAL(16, 205, 12),
QT_MOC_LITERAL(17, 218, 21),
QT_MOC_LITERAL(18, 240, 21),
QT_MOC_LITERAL(19, 262, 14),
QT_MOC_LITERAL(20, 277, 13),
QT_MOC_LITERAL(21, 291, 11),
QT_MOC_LITERAL(22, 303, 4),
QT_MOC_LITERAL(23, 308, 4)
    },
    "GameWidget\0signalEndGame\0\0GameState\0"
    "signalMouseClicked\0Position\0"
    "signalNeedNewGame\0signalNoGame\0"
    "signalSendMessage\0emitNoGameSignal\0"
    "raizeEndGame\0clear\0endGame\0setPlayerVsPlayer\0"
    "setPlayerVsCPU\0setPlayerVsNet\0"
    "setIpAndPort\0createPlayerVsNetGame\0"
    "showNeedNewGameWindow\0needNewGameYes\0"
    "needNewGameNo\0slotNewTurn\0Turn\0turn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    1,  107,    2, 0x06 /* Public */,
       6,    1,  110,    2, 0x06 /* Public */,
       7,    0,  113,    2, 0x06 /* Public */,
       8,    1,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  117,    2, 0x0a /* Public */,
      10,    0,  118,    2, 0x0a /* Public */,
      11,    0,  119,    2, 0x0a /* Public */,
      12,    1,  120,    2, 0x0a /* Public */,
      13,    0,  123,    2, 0x0a /* Public */,
      14,    0,  124,    2, 0x0a /* Public */,
      15,    0,  125,    2, 0x0a /* Public */,
      16,    0,  126,    2, 0x0a /* Public */,
      17,    0,  127,    2, 0x0a /* Public */,
      18,    0,  128,    2, 0x0a /* Public */,
      19,    0,  129,    2, 0x0a /* Public */,
      20,    0,  130,    2, 0x0a /* Public */,
      21,    1,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameWidget *_t = static_cast<GameWidget *>(_o);
        switch (_id) {
        case 0: _t->signalEndGame((*reinterpret_cast< GameState(*)>(_a[1]))); break;
        case 1: _t->signalMouseClicked((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 2: _t->signalNeedNewGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->signalNoGame(); break;
        case 4: _t->signalSendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->emitNoGameSignal(); break;
        case 6: _t->raizeEndGame(); break;
        case 7: _t->clear(); break;
        case 8: _t->endGame((*reinterpret_cast< GameState(*)>(_a[1]))); break;
        case 9: _t->setPlayerVsPlayer(); break;
        case 10: _t->setPlayerVsCPU(); break;
        case 11: _t->setPlayerVsNet(); break;
        case 12: _t->setIpAndPort(); break;
        case 13: _t->createPlayerVsNetGame(); break;
        case 14: _t->showNeedNewGameWindow(); break;
        case 15: _t->needNewGameYes(); break;
        case 16: _t->needNewGameNo(); break;
        case 17: _t->slotNewTurn((*reinterpret_cast< Turn(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameWidget::*_t)(GameState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidget::signalEndGame)) {
                *result = 0;
            }
        }
        {
            typedef void (GameWidget::*_t)(Position );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidget::signalMouseClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (GameWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidget::signalNeedNewGame)) {
                *result = 2;
            }
        }
        {
            typedef void (GameWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidget::signalNoGame)) {
                *result = 3;
            }
        }
        {
            typedef void (GameWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidget::signalSendMessage)) {
                *result = 4;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void GameWidget::signalEndGame(GameState _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameWidget::signalMouseClicked(Position _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameWidget::signalNeedNewGame(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameWidget::signalNoGame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GameWidget::signalSendMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
