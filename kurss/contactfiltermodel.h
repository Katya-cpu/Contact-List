#ifndef CONTACTFILTERMODEL_H
#define CONTACTFILTERMODEL_H

#include <QSortFilterProxyModel>
#include <QQmlEngine>
#include <QElapsedTimer>
#include "contactmodel.h"

class ContactFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString searchTerm READ searchTerm WRITE setSearchTerm NOTIFY searchTermChanged)
    Q_PROPERTY(ContactModel* source READ source WRITE setSource)

public:
    explicit ContactFilterModel(QObject *parent = nullptr);

    QString searchTerm() const;
    void setSearchTerm(const QString &searchTerm);

    ContactModel* source() const;
    void setSource(ContactModel* source);

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(const QString &fullName, const QString &address, const QString &city,
                            const QString &number, const QString &workPhone, const QString &homePhone,
                            const QString &email, const QString &birthDate,  const QString &photo);
    Q_INVOKABLE void set(int row, const QString &fullName, const QString &address, const QString &city,
                         const QString &number, const QString &workPhone, const QString &homePhone,
                         const QString &email, const QString &birthDate,  const QString &photo);
    Q_INVOKABLE void remove(int row);

signals:
    void searchTermChanged();
    void searchPerformance(qint64 nanoseconds);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QString m_searchTerm;
    ContactModel* m_source;
    mutable qint64 m_lastSearchTime = 0;
};

#endif // CONTACTFILTERMODEL_H
