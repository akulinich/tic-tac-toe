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
    QByteArrayData data[8];
    char stringdata[79];
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
QT_MOC_LITERAL(6, 58, 11),
QT_MOC_LITERAL(7, 70, 8)
    },
    "GameBase\0signalNewGame\0\0signalNewTurn\0"
    "Turn\0signalGameOver\0getUserTurn\0"
    "Position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       5,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,

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
        case 3: _t->getUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
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
    QByteArrayData data[18];
    char stringdata[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetGame_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetGame_t qt_meta_stringdata_NetGame = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 17),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 4),
QT_MOC_LITERAL(4, 32, 30),
QT_MOC_LITERAL(5, 63, 22),
QT_MOC_LITERAL(6, 86, 13),
QT_MOC_LITERAL(7, 100, 9),
QT_MOC_LITERAL(8, 110, 28),
QT_MOC_LITERAL(9, 139, 15),
QT_MOC_LITERAL(10, 155, 16),
QT_MOC_LITERAL(11, 172, 8),
QT_MOC_LITERAL(12, 181, 11),
QT_MOC_LITERAL(13, 193, 8),
QT_MOC_LITERAL(14, 202, 3),
QT_MOC_LITERAL(15, 206, 26),
QT_MOC_LITERAL(16, 233, 13),
QT_MOC_LITERAL(17, 247, 20)
    },
    "NetGame\0signalTurnRecived\0\0Turn\0"
    "signalNewGameDecisionNetPlayer\0"
    "signalWaitUserDecision\0slotReadyRead\0"
    "slotError\0QAbstractSocket::SocketError\0"
    "slotReadyToPlay\0getNetPlayerTurn\0"
    "decision\0getUserTurn\0Position\0pos\0"
    "sendToServerGameOverSignal\0need_new_game\0"
    "sendToServerUserTurn"
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
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   71,    2, 0x08 /* Private */,
       7,    1,   72,    2, 0x08 /* Private */,
       9,    0,   75,    2, 0x08 /* Private */,
      10,    1,   76,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      15,    1,   82,    2, 0x08 /* Private */,
      17,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, 0x80000000 | 3,   11,

       0        // eod
};

void NetGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetGame *_t = static_cast<NetGame *>(_o);
        switch (_id) {
        case 0: _t->signalTurnRecived((*reinterpret_cast< Turn(*)>(_a[1]))); break;
        case 1: _t->signalNewGameDecisionNetPlayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->signalWaitUserDecision(); break;
        case 3: _t->slotReadyRead(); break;
        case 4: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->slotReadyToPlay(); break;
        case 6: _t->getNetPlayerTurn((*reinterpret_cast< Turn(*)>(_a[1]))); break;
        case 7: _t->getUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 8: _t->sendToServerGameOverSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->sendToServerUserTurn((*reinterpret_cast< Turn(*)>(_a[1]))); break;
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
            typedef void (NetGame::*_t)(Turn );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetGame::signalTurnRecived)) {
                *result = 0;
            }
        }
        {
            typedef void (NetGame::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetGame::signalNewGameDecisionNetPlayer)) {
                *result = 1;
            }
        }
        {
            typedef void (NetGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetGame::signalWaitUserDecision)) {
                *result = 2;
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
void NetGame::signalTurnRecived(Turn _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetGame::signalNewGameDecisionNetPlayer(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetGame::signalWaitUserDecision()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
struct qt_meta_stringdata_CPUGame_t {
    QByteArrayData data[9];
    char stringdata[120];
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
QT_MOC_LITERAL(5, 84, 11),
QT_MOC_LITERAL(6, 96, 8),
QT_MOC_LITERAL(7, 105, 3),
QT_MOC_LITERAL(8, 109, 10)
    },
    "CPUGame\0signalWaitUserDecision\0\0"
    "signalWaitCPUDecision\0"
    "signalWaitUserNewGameDecision\0getUserTurn\0"
    "Position\0pos\0getCPUTurn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPUGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

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
        case 3: _t->getUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
        case 4: _t->getCPUTurn(); break;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
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
    QByteArrayData data[4];
    char stringdata[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserGame_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserGame_t qt_meta_stringdata_UserGame = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 11),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 8)
    },
    "UserGame\0getUserTurn\0\0Position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void UserGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserGame *_t = static_cast<UserGame *>(_o);
        switch (_id) {
        case 0: _t->getUserTurn((*reinterpret_cast< Position(*)>(_a[1]))); break;
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
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
