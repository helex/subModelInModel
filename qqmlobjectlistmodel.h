#ifndef QQMLOBJECTLISTMODEL_H
#define QQMLOBJECTLISTMODEL_H


#include "QQmlObjectListModel.h"

/*!
    \class QQmlObjectListModel

    \ingroup QT_QML_MODELS

    \brief Provides a generic way to generate a list model from QObject derived class, suitable for QML

    QQmlObjectListModel is a convenience subclass \c QAbstractListModel that makes use of C++ templates
    and Qt Meta Object to extract properties from a \c QObject derived class and create according roles
    inside the model.

    This is a far better way than to expose directly a \c QList<QObject *> inside a \c QVariant.

    And this is far simpler than doing all Qt model stuff manually : no subclassing or reimplementing need.

    The class was designed so that most of the added API is really common with \c QList one.

    \b Note : Simply needs that the class used for items inherits \c QObject and has Qt Meta Properties.

    \sa QQmlVariantListModel
*/

/*!
    \fn static QQmlObjectListModel * QQmlObjectListModel::create (QObject * parent = Q_NULLPTR)

    \details A factory to create a new model from a class that will be used as item type.

    \tparam ItemType The class to use as item
    \param parent The owner object for the model
    \return The newly created and configurerd model

    This is a template method, meant to be used like this :
    \code
        QQmlObjectListModel * myModel = QQmlObjectListModel::create<MyItemClass>(this);
    \endcode

    No other customization in needed after that.
*/

/*!
    \fn ItemType * QQmlObjectListModel::getAs () const

    \details A template method to retreive a given item as a precise \c T* Qt object pointer.

    \tparam ItemType The class to use as return pointer type
    \param idx The position of the item in the model
    \return The typed pointer to the object, or \c Q_NULLPTR if the type doesn't match

    \sa get(int) const, getByUid(QString) const
*/

/*!
    \fn QList<ItemType *> QQmlObjectListModel::listAs () const

    \details A template method to retreive all the items as \c QList<T*> typed Qt object pointer list.

    \tparam ItemType The class as object type to use in the returned pointer list
    \return A strongly typed \c QList of items Qt object pointers

    \sa list() const
*/


/*!
    \details Returns the data in a specific index for a given role.

    Reimplemented for QAbstractItemModel.

    \param index The item index (row, column and parent)
    \param role The role for property
    \return The data in the role

    \b Note : the \c 0 role is a pointer to item object itself.
*/

/*!
    \details Returns the roles available in the model.

    Reimplemented for QAbstractItemModel.

    \return The hash table of role to name matching

    \b Note : an additional \c 'qtObject' role is added for convenience.
*/

/*!
    \details Modifies the data in a specific index for a given role.

    Reimplemented for QAbstractItemModel.

    \param index The item index (row, column and parent)
    \param value The data to write
    \param role The role for property
    \return Weither the modification was done
*/

/*!
    \details Returns the role associated to the given property name.

    \param name The property name inside the item class
    \return The matching role, \c -1 if not found
*/


/*!
    \details Counts the items in the model.

    \return The count of items in the model
*/

/*!
    \details Counts the items in the model.

    \return The count of items in the model
*/
/*!
    \details Tests the content of the model.

    \return Whether the model contains no item
*/

/*!
    \details Tests the presence of a given item in the model.

    \param item The pointer to the item
    \return Whether the item was found
*/

/*!
    \details Finds the position of given item in the model.

    \param item The pointer to the item
    \return The row index of the item, \c -1 if not found
*/

/*!
    \details Delete all the items in the model.

    \b Note : The items objects will be removed from the model but they will be destructed
    only if they have no parent (because the model took the ownership).
*/


/*!
    \details Adds the given item at the end of the model.

    \param item The pointer to the item

    \sa prepend(QObject*), insert(int,QObject*)
*/


/*!
    \details Adds the given item at the beginning of the model.

    \param item The pointer to the item

    \sa append(QObject*), insert(int,QObject*)
*/


/*!
    \details Adds the given item at a certain position in the model.

    \param idx The position where the item must be added
    \param item The pointer to the item

    \sa append(QObject*), prepend(QObject*)
*/


/*!
    \details Adds the given list of items at the end of the model.

    \param itemList The list of items

    \sa prepend(QObjectList), insert(int, QObjectList)
*/


/*!
    \details Adds the given list of items at the beginning of the model.

    \param itemList The list of items

    \sa append(QObjectList), insert(int, QObjectList)
*/


/*!
    \details Adds the given list of items at a certain position in the model.

    \param idx The position where the items must be added
    \param itemList The list of items

    \sa append(QObjectList), prepend(QObjectList)
*/

/*!
    \details Moves an item from the model to another position.

    \param idx The current position of the item
    \param pos The position where it willl be after the move
*/


/*!
    \details Remove an item from the model.

    \param item The pointer to the item object
*/


/*!
    \details Remove an item from the model.

    \param idx The position of the item in the model
*/


/*!
    \details Retreives a model item as standard Qt object pointer.

    \param idx The position of the item in the model
    \return A pointer to the \c QObject

    \sa getAs(int) const, getByUid(QString) const
*/

/*!
    \details Retreives the first item of the model as standard Qt object pointer.

    \return A pointer to the \c QObject

    \sa last()
*/

/*!
    \details Retreives the last item of the model as standard Qt object pointer.

    \return A pointer to the \c QObject

    \sa first()
*/

/*!
    \details Retreives all the items of the model as a standard Qt object pointer list.

    \return A \c QObjectList containing all the pointers

    \sa listAs() const
*/

/*!
    \details Retreives a model item as standard Qt object pointer using its indexed property.
    Works only if setRoleNameForUid() was used correctly at start.

    \param uid The identifier value that points to the item in the index
    \return A pointer to the \c QObject

    \sa getAs(int) const, get(int) const
*/

/*!
    \details Sets which property of the items will be used as an index key.
    This can be used or not, but if not, getByUid() won't work.

    Ideally, the property used for UID should not change after items are added
    to the model, because it could have some side-effects.

    \param name The name of the property / role that is used as the index key
*/


#include <QAbstractListModel>
#include <QByteArray>
#include <QChar>
#include <QDebug>
#include <QHash>
#include <QList>
#include <QMetaMethod>
#include <QMetaObject>
#include <QMetaProperty>
#include <QObject>
#include <QString>
#include <QStringBuilder>
#include <QVariant>
#include <QVector>

template<typename T> QList<T> qListFromVariant (const QVariantList & list) {
    QList<T> ret;
    ret.reserve (list.size ());
    for (QVariantList::const_iterator it = list.constBegin (); it != list.constEnd (); ++it) {
        const QVariant & var = static_cast<QVariant>(* it);
        ret.append (var.value<T> ());
    }
    return ret;
}

template<typename T> QVariantList qListToVariant (const QList<T> & list) {
    QVariantList ret;
    ret.reserve (list.size ());
    for (typename QList<T>::const_iterator it = list.constBegin (); it != list.constEnd (); ++it) {
        const T & val = static_cast<T>(* it);
        ret.append (QVariant::fromValue (val));
    }
    return ret;
}

// custom foreach for QList, which uses no copy and check pointer non-null
#define FOREACH_PTR_IN_QLIST(_type_, _var_, _list_) \
    for (typename QList<_type_ *>::const_iterator it = _list_.constBegin (); it != _list_.constEnd (); ++it) \
        if (_type_ * _var_ = (* it))

class QQmlObjectListModelBase : public QAbstractListModel { // abstract Qt base class
    Q_OBJECT
    Q_PROPERTY (int count READ count NOTIFY countChanged)

public:
    explicit QQmlObjectListModelBase (QObject * parent = Q_NULLPTR) : QAbstractListModel (parent) { }

public slots: // virtual methods API for QML
    virtual int size (void) const = 0;
    virtual int count (void) const = 0;
    virtual bool isEmpty (void) const = 0;
    virtual bool contains (QObject * item) const = 0;
    virtual int indexOf (QObject * item) const = 0;
    virtual int roleForName (const QByteArray & name) const = 0;
    virtual void clear (void) = 0;
    virtual void append (QObject * item) = 0;
    virtual void prepend (QObject * item) = 0;
    virtual void insert (int idx, QObject * item) = 0;
    virtual void move (int idx, int pos) = 0;
    virtual void remove (QObject * item) = 0;
    virtual void remove (int idx) = 0;
    virtual QObject * get (int idx) const = 0;
    virtual QObject * get (const QString & uid) const = 0;
    virtual QObject * getFirst (void) const = 0;
    virtual QObject * getLast (void) const = 0;
    virtual QVariantList toVarArray (void) const = 0;

protected slots: // internal callback
    virtual void onItemPropertyChanged (void) = 0;

signals: // notifier
    void countChanged (void);
};

template<class ItemType> class QQmlObjectListModel : public QQmlObjectListModelBase {
public:
    explicit QQmlObjectListModel (QObject *          parent      = Q_NULLPTR,
                                  const QByteArray & displayRole = QByteArray (),
                                  const QByteArray & uidRole     = QByteArray ())
        : QQmlObjectListModelBase (parent)
        , m_count (0)
        , m_uidRoleName (uidRole)
        , m_dispRoleName (displayRole)
        , m_metaObj (ItemType::staticMetaObject)
    {
        static QSet<QByteArray> roleNamesBlacklist;
        if (roleNamesBlacklist.isEmpty ()) {
            roleNamesBlacklist << QByteArrayLiteral ("id")
                               << QByteArrayLiteral ("index")
                               << QByteArrayLiteral ("class")
                               << QByteArrayLiteral ("model")
                               << QByteArrayLiteral ("modelData");
        }
        static const char * HANDLER = "onItemPropertyChanged()";
        m_handler = metaObject ()->method (metaObject ()->indexOfMethod (HANDLER));
        if (!displayRole.isEmpty ()) {
            m_roles.insert (Qt::DisplayRole, QByteArrayLiteral ("display"));
        }
        m_roles.insert (baseRole (), QByteArrayLiteral ("qtObject"));
        const int len = m_metaObj.propertyCount ();
        for (int propertyIdx = 0, role = (baseRole () +1); propertyIdx < len; propertyIdx++, role++) {
            QMetaProperty metaProp = m_metaObj.property (propertyIdx);
            const QByteArray propName = QByteArray (metaProp.name ());
            if (!roleNamesBlacklist.contains (propName)) {
                m_roles.insert (role, propName);
                if (metaProp.hasNotifySignal ()) {
                    m_signalIdxToRole.insert (metaProp.notifySignalIndex (), role);
                }
            }
            else {
                static const QByteArray CLASS_NAME = (QByteArrayLiteral ("QQmlObjectListModel<") % m_metaObj.className () % '>');
                qWarning () << "Can't have" << propName << "as a role name in" << qPrintable (CLASS_NAME);
            }
        }
    }
    bool setData (const QModelIndex & index, const QVariant & value, int role) Q_DECL_FINAL {
        bool ret = false;
        ItemType * item = at (index.row ());
        const QByteArray rolename = (role != Qt::DisplayRole ? m_roles.value (role, emptyBA ()) : m_dispRoleName);
        if (item != Q_NULLPTR && role != baseRole () && !rolename.isEmpty ()) {
            ret = item->setProperty (rolename, value);
        }
        return ret;
    }
    QVariant data (const QModelIndex & index, int role) const Q_DECL_FINAL {
        QVariant ret;
        ItemType * item = at (index.row ());
        const QByteArray rolename = (role != Qt::DisplayRole ? m_roles.value (role, emptyBA ()) : m_dispRoleName);
        if (item != Q_NULLPTR && !rolename.isEmpty ()) {
            ret.setValue (role != baseRole () ? item->property (rolename) : QVariant::fromValue (static_cast<QObject *> (item)));
        }
        return ret;
    }
    QHash<int, QByteArray> roleNames (void) const Q_DECL_FINAL {
        return m_roles;
    }
    typedef typename QList<ItemType *>::const_iterator const_iterator;
    const_iterator begin (void) const {
        return m_items.begin ();
    }
    const_iterator end (void) const {
        return m_items.end ();
    }
    const_iterator constBegin (void) const {
        return m_items.constBegin ();
    }
    const_iterator constEnd (void) const {
        return m_items.constEnd ();
    }

public: // C++ API
    ItemType * at (int idx) const {
        ItemType * ret = Q_NULLPTR;
        if (idx >= 0 && idx < m_items.size ()) {
            ret = m_items.value (idx);
        }
        return ret;
    }
    ItemType * getByUid (const QString & uid) const {
        return (!m_indexByUid.isEmpty () ? m_indexByUid.value (uid, Q_NULLPTR) : Q_NULLPTR);
    }
    int roleForName (const QByteArray & name) const Q_DECL_FINAL {
        return m_roles.key (name, -1);
    }
    int count (void) const Q_DECL_FINAL {
        return m_count;
    }
    int size (void) const Q_DECL_FINAL {
        return m_count;
    }
    bool isEmpty (void) const Q_DECL_FINAL {
        return m_items.isEmpty ();
    }
    bool contains (ItemType * item) const {
        return m_items.contains (item);
    }
    int indexOf (ItemType * item) const {
        return m_items.indexOf (item);
    }
    void clear (void) Q_DECL_FINAL {
        if (!m_items.isEmpty ()) {
            beginRemoveRows (noParent (), 0, m_items.count () -1);
            FOREACH_PTR_IN_QLIST (ItemType, item, m_items) {
                dereferenceItem (item);
            }
            m_items.clear ();
            updateCounter ();
            endRemoveRows ();
        }
    }
    void append (ItemType * item) {
        if (item != Q_NULLPTR) {
            const int pos = m_items.count ();
            beginInsertRows (noParent (), pos, pos);
            m_items.append (item);
            referenceItem (item);
            updateCounter ();
            endInsertRows ();
        }
    }
    void prepend (ItemType * item) {
        if (item != Q_NULLPTR) {
            beginInsertRows (noParent (), 0, 0);
            m_items.prepend (item);
            referenceItem (item);
            updateCounter ();
            endInsertRows ();
        }
    }
    void insert (int idx, ItemType * item) {
        if (item != Q_NULLPTR) {
            beginInsertRows (noParent (), idx, idx);
            m_items.insert (idx, item);
            referenceItem (item);
            updateCounter ();
            endInsertRows ();
        }
    }
    void append (const QList<ItemType *> & itemList) {
        if (!itemList.isEmpty ()) {
            const int pos = m_items.count ();
            beginInsertRows (noParent (), pos, pos + itemList.count () -1);
            m_items.reserve (m_items.count () + itemList.count ());
            m_items.append (itemList);
            FOREACH_PTR_IN_QLIST (ItemType, item, itemList) {
                referenceItem (item);
            }
            updateCounter ();
            endInsertRows ();
        }
    }
    void prepend (const QList<ItemType *> & itemList) {
        if (!itemList.isEmpty ()) {
            beginInsertRows (noParent (), 0, itemList.count () -1);
            m_items.reserve (m_items.count () + itemList.count ());
            int offset = 0;
            FOREACH_PTR_IN_QLIST (ItemType, item, itemList) {
                m_items.insert (offset, item);
                referenceItem (item);
                offset++;
            }
            updateCounter ();
            endInsertRows ();
        }
    }
    void insert (int idx, const QList<ItemType *> & itemList) {
        if (!itemList.isEmpty ()) {
            beginInsertRows (noParent (), idx, idx + itemList.count () -1);
            m_items.reserve (m_items.count () + itemList.count ());
            int offset = 0;
            FOREACH_PTR_IN_QLIST (ItemType, item, itemList) {
                m_items.insert (idx + offset, item);
                referenceItem (item);
                offset++;
            }
            updateCounter ();
            endInsertRows ();
        }
    }
    void move (int idx, int pos) Q_DECL_FINAL {
        if (idx != pos) {
            // FIXME : use begin/end MoveRows when supported by Repeater, since then use remove/insert pair
            //beginMoveRows (noParent (), idx, idx, noParent (), (idx < pos ? pos +1 : pos));
            beginRemoveRows (noParent (), idx, idx);
            beginInsertRows (noParent (), pos, pos);
            m_items.move (idx, pos);
            endRemoveRows ();
            endInsertRows ();
            //endMoveRows ();
        }
    }
    void remove (ItemType * item) {
        if (item != Q_NULLPTR) {
            const int idx = m_items.indexOf (item);
            remove (idx);
        }
    }
    void remove (int idx) Q_DECL_FINAL {
        if (idx >= 0 && idx < m_items.size ()) {
            beginRemoveRows (noParent (), idx, idx);
            ItemType * item = m_items.takeAt (idx);
            dereferenceItem (item);
            updateCounter ();
            endRemoveRows ();
        }
    }
    ItemType * first (void) const {
        return m_items.first ();
    }
    ItemType * last (void) const {
        return m_items.last ();
    }
    const QList<ItemType *> & toList (void) const {
        return m_items;
    }

public: // QML slots implementation
    void append (QObject * item) Q_DECL_FINAL {
        append (qobject_cast<ItemType *> (item));
    }
    void prepend (QObject * item) Q_DECL_FINAL {
        prepend (qobject_cast<ItemType *> (item));
    }
    void insert (int idx, QObject * item) Q_DECL_FINAL {
        insert (idx, qobject_cast<ItemType *> (item));
    }
    void remove (QObject * item) Q_DECL_FINAL {
        remove (qobject_cast<ItemType *> (item));
    }
    bool contains (QObject * item) const Q_DECL_FINAL {
        return contains (qobject_cast<ItemType *> (item));
    }
    int indexOf (QObject * item) const Q_DECL_FINAL {
        return indexOf (qobject_cast<ItemType *> (item));
    }
    int indexOf (const QString & uid) const {
        return indexOf (get (uid));
    }
    QObject * get (int idx) const Q_DECL_FINAL {
        return static_cast<QObject *> (at (idx));
    }
    QObject * get (const QString & uid) const Q_DECL_FINAL {
        return static_cast<QObject *> (getByUid (uid));
    }
    QObject * getFirst (void) const Q_DECL_FINAL {
        return static_cast<QObject *> (first ());
    }
    QObject * getLast (void) const Q_DECL_FINAL {
        return static_cast<QObject *> (last ());
    }
    QVariantList toVarArray (void) const Q_DECL_FINAL {
        return qListToVariant<ItemType *> (m_items);
    }

protected: // internal stuff
    static const QString & emptyStr (void) {
        static const QString ret = QStringLiteral ("");
        return ret;
    }
    static const QByteArray & emptyBA (void) {
        static const QByteArray ret = QByteArrayLiteral ("");
        return ret;
    }
    static const QModelIndex & noParent (void) {
        static const QModelIndex ret = QModelIndex ();
        return ret;
    }
    static const int & baseRole (void) {
        static const int ret = Qt::UserRole;
        return ret;
    }
    int rowCount (const QModelIndex & parent = QModelIndex ()) const Q_DECL_FINAL {
        return (!parent.isValid () ? m_items.count () : 0);
    }
    void referenceItem (ItemType * item) {
        if (item != Q_NULLPTR) {
            if (!item->parent ()) {
                item->setParent (this);
            }
            for (QHash<int, int>::const_iterator it = m_signalIdxToRole.constBegin (); it != m_signalIdxToRole.constEnd (); ++it) {
                connect (item, item->metaObject ()->method (it.key ()), this, m_handler, Qt::UniqueConnection);
            }
            if (!m_uidRoleName.isEmpty ()) {
                const QString key = m_indexByUid.key (item, emptyStr ());
                if (!key.isEmpty ()) {
                    m_indexByUid.remove (key);
                }
                const QString value = item->property (m_uidRoleName).toString ();
                if (!value.isEmpty ()) {
                    m_indexByUid.insert (value, item);
                }
            }
        }
    }
    void dereferenceItem (ItemType * item) {
        if (item != Q_NULLPTR) {
            disconnect (this, Q_NULLPTR, item, Q_NULLPTR);
            disconnect (item, Q_NULLPTR, this, Q_NULLPTR);
            if (!m_uidRoleName.isEmpty ()) {
                const QString key = m_indexByUid.key (item, emptyStr ());
                if (!key.isEmpty ()) {
                    m_indexByUid.remove (key);
                }
            }
            if (item->parent () == this) { // FIXME : maybe that's not the best way to test ownership ?
                item->deleteLater ();
            }
        }
    }
    void onItemPropertyChanged (void) Q_DECL_FINAL {
        ItemType * item = qobject_cast<ItemType *> (sender ());
        const int row = m_items.indexOf (item);
        const int sig = senderSignalIndex ();
        const int role = m_signalIdxToRole.value (sig, -1);
        if (row >= 0 && role >= 0) {
            const QModelIndex index = QAbstractListModel::index (row, 0, noParent ());
            QVector<int> rolesList;
            rolesList.append (role);
            if (m_roles.value (role) == m_dispRoleName) {
                rolesList.append (Qt::DisplayRole);
            }
            emit dataChanged (index, index, rolesList);
        }
        if (!m_uidRoleName.isEmpty ()) {
            const QByteArray roleName = m_roles.value (role, emptyBA ());
            if (!roleName.isEmpty () && roleName == m_uidRoleName) {
                const QString key = m_indexByUid.key (item, emptyStr ());
                if (!key.isEmpty ()) {
                    m_indexByUid.remove (key);
                }
                const QString value = item->property (m_uidRoleName).toString ();
                if (!value.isEmpty ()) {
                    m_indexByUid.insert (value, item);
                }
            }
        }
    }
    inline void updateCounter (void) {
        if (m_count != m_items.count ()) {
            m_count = m_items.count ();
            emit countChanged ();
        }
    }

private: // data members
    int                        m_count;
    QByteArray                 m_uidRoleName;
    QByteArray                 m_dispRoleName;
    QMetaObject                m_metaObj;
    QMetaMethod                m_handler;
    QHash<int, QByteArray>     m_roles;
    QHash<int, int>            m_signalIdxToRole;
    QList<ItemType *>          m_items;
    QHash<QString, ItemType *> m_indexByUid;
};

#define QML_OBJMODEL_PROPERTY(type, name) \
    protected: Q_PROPERTY (QQmlObjectListModelBase * name READ get_##name CONSTANT) \
    private: QQmlObjectListModel<type> * m_##name; \
    public: QQmlObjectListModel<type> * get_##name (void) const { return m_##name; } \
    private:

#endif // QQMLOBJECTLISTMODEL_H
