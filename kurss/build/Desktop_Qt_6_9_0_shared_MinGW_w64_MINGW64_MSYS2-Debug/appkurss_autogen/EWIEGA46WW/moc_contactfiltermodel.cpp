/****************************************************************************
** Meta object code from reading C++ file 'contactfiltermodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../contactfiltermodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactfiltermodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
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
struct qt_meta_tag_ZN18ContactFilterModelE_t {};
} // unnamed namespace

template <> constexpr inline auto ContactFilterModel::qt_create_metaobjectdata<qt_meta_tag_ZN18ContactFilterModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ContactFilterModel",
        "QML.Element",
        "auto",
        "searchTermChanged",
        "",
        "searchPerformance",
        "nanoseconds",
        "get",
        "QVariantMap",
        "row",
        "append",
        "fullName",
        "address",
        "city",
        "number",
        "workPhone",
        "homePhone",
        "email",
        "birthDate",
        "photo",
        "set",
        "remove",
        "searchTerm",
        "source",
        "ContactModel*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'searchTermChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'searchPerformance'
        QtMocHelpers::SignalData<void(qint64)>(5, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 6 },
        }}),
        // Method 'get'
        QtMocHelpers::MethodData<QVariantMap(int) const>(7, 4, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::Int, 9 },
        }}),
        // Method 'append'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &)>(10, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::QString, 12 }, { QMetaType::QString, 13 }, { QMetaType::QString, 14 },
            { QMetaType::QString, 15 }, { QMetaType::QString, 16 }, { QMetaType::QString, 17 }, { QMetaType::QString, 18 },
            { QMetaType::QString, 19 },
        }}),
        // Method 'set'
        QtMocHelpers::MethodData<void(int, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &)>(20, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 }, { QMetaType::QString, 11 }, { QMetaType::QString, 12 }, { QMetaType::QString, 13 },
            { QMetaType::QString, 14 }, { QMetaType::QString, 15 }, { QMetaType::QString, 16 }, { QMetaType::QString, 17 },
            { QMetaType::QString, 18 }, { QMetaType::QString, 19 },
        }}),
        // Method 'remove'
        QtMocHelpers::MethodData<void(int)>(21, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'searchTerm'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'source'
        QtMocHelpers::PropertyData<ContactModel*>(23, 0x80000000 | 24, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ContactFilterModel, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ContactFilterModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18ContactFilterModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18ContactFilterModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18ContactFilterModelE_t>.metaTypes,
    nullptr
} };

void ContactFilterModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ContactFilterModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->searchTermChanged(); break;
        case 1: _t->searchPerformance((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 2: { QVariantMap _r = _t->get((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->append((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9]))); break;
        case 4: _t->set((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10]))); break;
        case 5: _t->remove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ContactFilterModel::*)()>(_a, &ContactFilterModel::searchTermChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ContactFilterModel::*)(qint64 )>(_a, &ContactFilterModel::searchPerformance, 1))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ContactModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->searchTerm(); break;
        case 1: *reinterpret_cast<ContactModel**>(_v) = _t->source(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSearchTerm(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setSource(*reinterpret_cast<ContactModel**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ContactFilterModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactFilterModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18ContactFilterModelE_t>.strings))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int ContactFilterModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ContactFilterModel::searchTermChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ContactFilterModel::searchPerformance(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
