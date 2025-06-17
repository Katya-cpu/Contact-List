#include "contactmodel.h"
#include "contactfiltermodel.h"

ContactFilterModel::ContactFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent), m_source(nullptr)
{
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setFilterRole(ContactModel::FullNameRole);
    setSortRole(ContactModel::FullNameRole);
    sort(0);
}

QString ContactFilterModel::searchTerm() const
{
    return m_searchTerm;
}

void ContactFilterModel::setSearchTerm(const QString &searchTerm)
{
    if (m_searchTerm == searchTerm)
        return;

    QElapsedTimer timer;
    timer.start();

    m_searchTerm = searchTerm;
    setFilterFixedString(searchTerm);
    emit searchTermChanged();

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "--- Общее время поиска для '" << searchTerm << "' :"
             << elapsed << "нс (" << (elapsed / 1000.0) << "µs)";
    emit searchPerformance(elapsed);
}

ContactModel* ContactFilterModel::source() const
{
    return m_source;
}

void ContactFilterModel::setSource(ContactModel* source)
{
    if (m_source == source)
        return;

    m_source = source;
    setSourceModel(source);
}

QVariantMap ContactFilterModel::get(int row) const
{
    QModelIndex proxyIndex = index(row, 0);
    QModelIndex sourceIndex = mapToSource(proxyIndex);
    return m_source->get(sourceIndex.row());
}

void ContactFilterModel::append(const QString &fullName, const QString &address, const QString &city,
                                const QString &number, const QString &workPhone, const QString &homePhone,
                                const QString &email, const QString &birthDate, const QString &photo)
{
    if (m_source)
        m_source->append(fullName, address, city, number, workPhone, homePhone, email, birthDate, photo);
}

void ContactFilterModel::set(int row, const QString &fullName, const QString &address, const QString &city,
                             const QString &number, const QString &workPhone, const QString &homePhone,
                             const QString &email, const QString &birthDate, const QString &photo)
{
    if (!m_source) return;

    QModelIndex proxyIndex = index(row, 0);
    QModelIndex sourceIndex = mapToSource(proxyIndex);
    m_source->set(sourceIndex.row(), fullName, address, city, number, workPhone, homePhone, email, birthDate, photo);
}

void ContactFilterModel::remove(int row)
{
    if (!m_source) return;

    QModelIndex proxyIndex = index(row, 0);
    QModelIndex sourceIndex = mapToSource(proxyIndex);
    m_source->remove(sourceIndex.row());
}

// contactfiltermodel.cpp
bool ContactFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (m_searchTerm.isEmpty())
        return true;

    const QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    const QString fullName = sourceModel()->data(index, ContactModel::FullNameRole).toString();
    const QString address = sourceModel()->data(index, ContactModel::AddressRole).toString();
    const QString city = sourceModel()->data(index, ContactModel::CityRole).toString();
    const QString number = sourceModel()->data(index, ContactModel::NumberRole).toString();
    const QString workPhone = sourceModel()->data(index, ContactModel::WorkPhoneRole).toString();
    const QString homePhone = sourceModel()->data(index, ContactModel::HomePhoneRole).toString();
    const QString email = sourceModel()->data(index, ContactModel::EmailRole).toString();
    const QString birthDate = sourceModel()->data(index, ContactModel::BirthDateRole).toString();

    return fullName.contains(m_searchTerm, Qt::CaseInsensitive) ||
           address.contains(m_searchTerm, Qt::CaseInsensitive) ||
           city.contains(m_searchTerm, Qt::CaseInsensitive) ||
           number.contains(m_searchTerm, Qt::CaseInsensitive) ||
           workPhone.contains(m_searchTerm, Qt::CaseInsensitive) ||
           homePhone.contains(m_searchTerm, Qt::CaseInsensitive) ||
           email.contains(m_searchTerm, Qt::CaseInsensitive) ||
           birthDate.contains(m_searchTerm, Qt::CaseInsensitive);
}


