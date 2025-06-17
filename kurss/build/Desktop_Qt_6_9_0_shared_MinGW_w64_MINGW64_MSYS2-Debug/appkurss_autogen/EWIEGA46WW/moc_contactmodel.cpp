/****************************************************************************
** Meta object code from reading C++ file 'contactmodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../contactmodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactmodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12ContactModelE_t {};
} // unnamed namespace

template <> constexpr inline auto ContactModel::qt_create_metaobjectdata<qt_meta_tag_ZN12ContactModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ContactModel",
        "QML.Element",
        "auto",
        "get",
        "QVariantMap",
        "",
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
        "ContactRole",
        "FullNameRole",
        "AddressRole",
        "CityRole",
        "NumberRole",
        "WorkPhoneRole",
        "HomePhoneRole",
        "EmailRole",
        "BirthDateRole",
        "PhotoRole"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'get'
        QtMocHelpers::MethodData<QVariantMap(int) const>(3, 5, QMC::AccessPublic, 0x80000000 | 4, {{
            { QMetaType::Int, 6 },
        }}),
        // Method 'append'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &)>(7, 5, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::QString, 9 }, { QMetaType::QString, 10 }, { QMetaType::QString, 11 },
            { QMetaType::QString, 12 }, { QMetaType::QString, 13 }, { QMetaType::QString, 14 }, { QMetaType::QString, 15 },
            { QMetaType::QString, 16 },
        }}),
        // Method 'set'
        QtMocHelpers::MethodData<void(int, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &)>(17, 5, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::QString, 8 }, { QMetaType::QString, 9 }, { QMetaType::QString, 10 },
            { QMetaType::QString, 11 }, { QMetaType::QString, 12 }, { QMetaType::QString, 13 }, { QMetaType::QString, 14 },
            { QMetaType::QString, 15 }, { QMetaType::QString, 16 },
        }}),
        // Method 'remove'
        QtMocHelpers::MethodData<void(int)>(18, 5, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ContactRole'
        QtMocHelpers::EnumData<ContactRole>(19, 19, QMC::EnumFlags{}).add({
            {   20, ContactRole::FullNameRole },
            {   21, ContactRole::AddressRole },
            {   22, ContactRole::CityRole },
            {   23, ContactRole::NumberRole },
            {   24, ContactRole::WorkPhoneRole },
            {   25, ContactRole::HomePhoneRole },
            {   26, ContactRole::EmailRole },
            {   27, ContactRole::BirthDateRole },
            {   28, ContactRole::PhotoRole },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ContactModel, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ContactModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ContactModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ContactModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12ContactModelE_t>.metaTypes,
    nullptr
} };

void ContactModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ContactModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QVariantMap _r = _t->get((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->append((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9]))); break;
        case 2: _t->set((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10]))); break;
        case 3: _t->remove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ContactModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ContactModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int ContactModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
