/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<contactfiltermodel.h>)
#  include <contactfiltermodel.h>
#endif
#if __has_include(<contactmodel.h>)
#  include <contactmodel.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_kurss()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<ContactFilterModel>("kurss", 1);
    qmlRegisterAnonymousType<QAbstractItemModel, 254>("kurss", 1);
    qmlRegisterTypesAndRevisions<ContactModel>("kurss", 1);
    QMetaType::fromType<ContactModel::ContactRole>().id();
    QMetaType::fromType<QAbstractProxyModel *>().id();
    QMetaType::fromType<QSortFilterProxyModel *>().id();
    QT_WARNING_POP
    qmlRegisterModule("kurss", 1, 0);
}

static const QQmlModuleRegistration kurssRegistration("kurss", qml_register_types_kurss);
