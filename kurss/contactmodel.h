#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>
#include <QQmlEngine>
#include <QSettings>

class ContactModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT;

public:
    enum ContactRole {
        FullNameRole = Qt::DisplayRole,
        AddressRole = Qt::UserRole,
        CityRole,
        NumberRole,
        WorkPhoneRole,
        HomePhoneRole,
        EmailRole,
        BirthDateRole,
        PhotoRole
    };
    Q_ENUM(ContactRole)

    ContactModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(const QString &fullName, const QString &address, const QString &city,
                            const QString &number, const QString &workPhone, const QString &homePhone,
                            const QString &email, const QString &birthDate,  const QString &photo);
    Q_INVOKABLE void set(int row, const QString &fullName, const QString &address, const QString &city,
                         const QString &number, const QString &workPhone, const QString &homePhone,
                         const QString &email, const QString &birthDate,  const QString &photo);
    Q_INVOKABLE void remove(int row);

private:
    void saveContacts();
    void loadContacts();
    struct Contact {
        QString fullName;
        QString address;
        QString city;
        QString number;
        QString workPhone;
        QString homePhone;
        QString email;
        QString birthDate;
        QString photo;
    };

    QList<Contact> m_contacts;
};

#endif // CONTACTMODEL_H
