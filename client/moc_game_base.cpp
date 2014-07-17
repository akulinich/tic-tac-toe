/****************************************************************************
** Meta object code from reading C++ file 'game_base.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game_base.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_base.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameBase_t {
    QByteArrayData data[10];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameBase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameBase_t qt_meta_stringdata_GameBase = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 13),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 13),
QT_MOC_LITERAL(4, 38, 4),
QT_MOC_LITERAL(5, 43, 14),
QT_MOC_LITERAL(6, 58, 15),
QT_MOC_LITERAL(7, 74, 8),
QT_MOC_LITERAL(8, 83, 11),
QT_MOC_LITERAL(9, 95, 22)
    },
    "GameBase\0signalNewGame\0\0signalNewTurn\0"
    "Turn\0signalGameOver\0slotGetUserTurn\0"
    "Position\0slotNewGame\0slotGetNewGameDecision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   49,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void GameBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameBase *_t = static_cast<GameBase *>(_o);
        switch (_id) {
        case 0: _t->signalNewGame(); break;
        case 1: _t->signalNewTurn((*reinterpret_cast< Turn(*)>(_a[1]))); break;
        case 2: _t->signalGameOver(); break;
        case 3: _t->slotGetUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 4: _t->slotNewGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotGetNewGameDecision((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameBase::signalNewGame)) {
                *result = 0;
            }
        }
        {
            typedef void (GameBase::*_t)(Turn );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameBase::signalNewTurn)) {
                *result = 1;
            }
        }
        {
            typedef void (GameBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameBase::signalGameOver)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GameBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameBase.data,
      qt_meta_data_GameBase,  qt_static_metacall, 0, 0}
};


const QMetaObject *GameBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameBase.stringdata))
        return static_cast<void*>(const_cast< GameBase*>(this));
    return QObject::qt_metacast(_clname);
}

int GameBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void GameBase::signalNewGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameBase::signalNewTurn(Turn _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameBase::signalGameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
struct qt_meta_stringdata_NetGame_t {
    QByteArrayData data[17];
    char stringdata[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetGame_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetGame_t qt_meta_stringdata_NetGame = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 13),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 22),
QT_MOC_LITERAL(4, 46, 13),
QT_MOC_LITERAL(5, 60, 12),
QT_MOC_LITERAL(6, 73, 9),
QT_MOC_LITERAL(7, 83, 28),
QT_MOC_LITERAL(8, 112, 20),
QT_MOC_LITERAL(9, 133, 4),
QT_MOC_LITERAL(10, 138, 8),
QT_MOC_LITERAL(11, 147, 15),
QT_MOC_LITERAL(12, 163, 8),
QT_MOC_LITERAL(13, 172, 3),
QT_MOC_LITERAL(14, 176, 22),
QT_MOC_LITERAL(15, 199, 31),
QT_MOC_LITERAL(16, 231, 11)
    },
    "NetGame\0signalNewGame\0\0signalWaitUserDecision\0"
    "slotConnected\0slotReadInfo\0slotError\0"
    "QAbstractSocket::SocketError\0"
    "slotGetNetPlayerTurn\0Turn\0decision\0"
    "slotGetUserTurn\0Position\0pos\0"
    "slotGetNewGameDecision\0"
    "slotGetNewGameDecisionNetPLayer\0"
    "slotNewGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   68,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       6,    1,   70,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      14,    1,   79,    2, 0x08 /* Private */,
      15,    1,   82,    2, 0x08 /* Private */,
      16,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void NetGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetGame *_t = static_cast<NetGame *>(_o);
        switch (_id) {
        case 0: _t->signalNewGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signalWaitUserDecision(); break;
        case 2: _t->slotConnected(); break;
        case 3: _t->slotReadInfo(); break;
        case 4: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->slotGetNetPlayerTurn((*reinterpret_cast< Turn(*)>(_a[1]))); break;
        case 6: _t->slotGetUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 7: _t->slotGetNewGameDecision((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->slotGetNewGameDecisionNetPLayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slotNewGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetGame::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetGame::signalNewGame)) {
                *result = 0;
            }
        }
        {
            typedef void (NetGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetGame::signalWaitUserDecision)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject NetGame::staticMetaObject = {
    { &GameBase::staticMetaObject, qt_meta_stringdata_NetGame.data,
      qt_meta_data_NetGame,  qt_static_metacall, 0, 0}
};


const QMetaObject *NetGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetGame.stringdata))
        return static_cast<void*>(const_cast< NetGame*>(this));
    return GameBase::qt_metacast(_clname);
}

int NetGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void NetGame::signalNewGame(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetGame::signalWaitUserDecision()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
struct qt_meta_stringdata_CPUGame_t {
    QByteArrayData data[11];
    char stringdata[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPUGame_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPUGame_t qt_meta_stringdata_CPUGame = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 22),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 21),
QT_MOC_LITERAL(4, 54, 29),
QT_MOC_LITERAL(5, 84, 15),
QT_MOC_LITERAL(6, 100, 8),
QT_MOC_LITERAL(7, 109, 3),
QT_MOC_LITERAL(8, 113, 11),
QT_MOC_LITERAL(9, 125, 14),
QT_MOC_LITERAL(10, 140, 22)
    },
    "CPUGame\0signalWaitUserDecision\0\0"
    "signalWaitCPUDecision\0"
    "signalWaitUserNewGameDecision\0"
    "slotGetUserTurn\0Position\0pos\0slotNewGame\0"
    "slotGetCPUTurn\0slotGetNewGameDecision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPUGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   52,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void CPUGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPUGame *_t = static_cast<CPUGame *>(_o);
        switch (_id) {
        case 0: _t->signalWaitUserDecision(); break;
        case 1: _t->signalWaitCPUDecision(); break;
        case 2: _t->signalWaitUserNewGameDecision(); break;
        case 3: _t->slotGetUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 4: _t->slotNewGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotGetCPUTurn(); break;
        case 6: _t->slotGetNewGameDecision((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CPUGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CPUGame::signalWaitUserDecision)) {
                *result = 0;
            }
        }
        {
            typedef void (CPUGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CPUGame::signalWaitCPUDecision)) {
                *result = 1;
            }
        }
        {
            typedef void (CPUGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CPUGame::signalWaitUserNewGameDecision)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CPUGame::staticMetaObject = {
    { &GameBase::staticMetaObject, qt_meta_stringdata_CPUGame.data,
      qt_meta_data_CPUGame,  qt_static_metacall, 0, 0}
};


const QMetaObject *CPUGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPUGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CPUGame.stringdata))
        return static_cast<void*>(const_cast< CPUGame*>(this));
    return GameBase::qt_metacast(_clname);
}

int CPUGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CPUGame::signalWaitUserDecision()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CPUGame::signalWaitCPUDecision()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CPUGame::signalWaitUserNewGameDecision()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
struct qt_meta_stringdata_UserGame_t {
    QByteArrayData data[6];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserGame_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserGame_t qt_meta_stringdata_UserGame = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 15),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 8),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 22)
    },
    "UserGame\0slotGetUserTurn\0\0Position\0"
    "slotNewGame\0slotGetNewGameDecision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       5,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void UserGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserGame *_t = static_cast<UserGame *>(_o);
        switch (_id) {
        case 0: _t->slotGetUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 1: _t->slotNewGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slotGetNewGameDecision((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UserGame::staticMetaObject = {
    { &GameBase::staticMetaObject, qt_meta_stringdata_UserGame.data,
      qt_meta_data_UserGame,  qt_static_metacall, 0, 0}
};


const QMetaObject *UserGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserGame.stringdata))
        return static_cast<void*>(const_cast< UserGame*>(this));
    return GameBase::qt_metacast(_clname);
}

int UserGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
