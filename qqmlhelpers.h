#ifndef QQMLHELPERS_H
#define QQMLHELPERS_H

/*!
    \defgroup QT_QML_HELPERS Qt helper macros

    Brings a couple of macros that can help saving development time,
    by avoiding manual code duplication, often leading to heavy copy-and-paste,
    which is largely error-prone and not productive at all.
*/


/*!
    \def QML_WRITABLE_PROPERTY(type, name)
    \ingroup QT_QML_HELPERS
    \hideinitializer
    \details Creates a \c Q_PROPERTY that will be readable / writable from QML.

    \param type The C++ type of the property
    \param name The name for the property

    It generates for this goal :
    \code
        {type} m_{name}; // private member variable
        {type} get_{name} () const; // public getter method
        void set_{name} ({type}); // public setter slot
        void {name}Changed ({type}); // notifier signal
    \endcode

    \b Note : Any change from either C++ or QML side will trigger the notification.
*/


/*!
    \def QML_READONLY_PROPERTY(type, name)
    \ingroup QT_QML_HELPERS
    \hideinitializer
    \details Creates a \c Q_PROPERTY that will be readable from QML and writable from C++.

    \param type The C++ type of the property
    \param name The name for the property

    It generates for this goal :
    \code
        {type} m_{name}; // private member variable
        {type} get_{name} () const; // public getter method
        void update_{name} ({type}); // public setter method
        void {name}Changed ({type}); // notifier signal
    \endcode

    \b Note : Any change from C++ side will trigger the notification to QML.
*/


/*!
    \def QML_CONSTANT_PROPERTY(type, name)
    \ingroup QT_QML_HELPERS
    \hideinitializer
    \details Creates a \c Q_PROPERTY for a constant value exposed from C++ to QML.

    \param type The C++ type of the property
    \param name The name for the property

    It generates for this goal :
    \code
        {type} m_{name}; // private member variable
        {type} get_{name} () const; // public getter method
    \endcode

    \b Note : There is no change notifier because value is constant.
*/


/*!
    \def QML_ENUM_CLASS(name, ...)
    \ingroup QT_QML_HELPERS
    \hideinitializer
    \details Creates a class that contains a C++ enum that can be exposed to QML.

    \param name The name for the class
    \param ... The variadic list of values for the enum (comma-separated)

    It generates for this goal :
    \li The \c {name} C++ QObject-derived class
    \li The \c {name}::Type enumeration containing the values list
    \li The \c Q_ENUMS macro call to allow QML usage

    Example in use :
    \code
        QML_ENUM_CLASS (DaysOfWeek, Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday)
    \endcode

    \b Note : The QML registration using \c qmlRegisterUncreatableType() will still be needed.
*/



#include <QObject>

#define QML_WRITABLE_PROPERTY(type, name) \
    protected: \
        Q_PROPERTY (type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    private: \
        type m_##name; \
    public: \
        type get_##name () const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = m_##name != name)) { \
                m_##name = name; \
                emit name##Changed (m_##name); \
            } \
            return ret; \
        } \
    Q_SIGNALS: \
        void name##Changed (type name); \
    private:

#define QML_READONLY_PROPERTY(type, name) \
    protected: \
        Q_PROPERTY (type name READ get_##name NOTIFY name##Changed) \
    private: \
        type m_##name; \
    public: \
        type get_##name () const { \
            return m_##name ; \
        } \
        bool update_##name (type name) { \
            bool ret = false; \
            if ((ret = m_##name != name)) { \
                m_##name = name; \
                emit name##Changed (m_##name); \
            } \
            return ret; \
        } \
    Q_SIGNALS: \
        void name##Changed (type name); \
    private:

#define QML_CONSTANT_PROPERTY(type, name) \
    protected: \
        Q_PROPERTY (type name READ get_##name CONSTANT) \
    private: \
        type m_##name; \
    public: \
        type get_##name () const { \
            return m_##name ; \
        } \
    private:

#define QML_LIST_PROPERTY(CLASS, NAME, TYPE) \
    public: \
        static int NAME##_count (QQmlListProperty<TYPE> * prop) { \
            CLASS * instance = qobject_cast<CLASS *> (prop->object); \
            return (instance != NULL ? instance->m_##NAME.count () : 0); \
        } \
        static void NAME##_clear (QQmlListProperty<TYPE> * prop) { \
            CLASS * instance = qobject_cast<CLASS *> (prop->object); \
            if (instance != NULL) { \
                instance->m_##NAME.clear (); \
            } \
        } \
        static void NAME##_append (QQmlListProperty<TYPE> * prop, TYPE * obj) { \
            CLASS * instance = qobject_cast<CLASS *> (prop->object); \
            if (instance != NULL && obj != NULL) { \
                instance->m_##NAME.append (obj); \
            } \
        } \
        static TYPE * NAME##_at (QQmlListProperty<TYPE> * prop, int idx) { \
            CLASS * instance = qobject_cast<CLASS *> (prop->object); \
            return (instance != NULL ? instance->m_##NAME.at (idx) : NULL); \
        } \
        QList<TYPE *> get_##NAME##s (void) const { \
            return m_##NAME; \
        } \
    private: \
        QList<TYPE *> m_##NAME;

#define QML_ENUM_CLASS(name, ...) \
    class name : public QObject { \
        Q_GADGET \
    public: \
        enum Type { __VA_ARGS__ }; \
        Q_ENUMS (Type) \
    };

class QmlProperty : public QObject { Q_OBJECT }; // NOTE : to avoid "no suitable class found" MOC note

#endif // QQMLHELPERS_H

