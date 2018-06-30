#ifndef APP_H
#define APP_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "qqmlobjectlistmodel.h"
#include "qqmlhelpers.h"
#include <QtQml/QQmlContext>
#include <QDateTime>

class MySubmodel : public QObject {

    Q_OBJECT

    QML_WRITABLE_PROPERTY (int,          subid)
    QML_WRITABLE_PROPERTY (QString,      subname)

public:
    explicit MySubmodel (QObject * parent = NULL) : QObject (parent) {
        m_subid = -1;
    }
};

class MyModel : public QObject {

    Q_OBJECT

    QML_WRITABLE_PROPERTY (int,          mainID)
    QML_WRITABLE_PROPERTY (int,          no)
    QML_WRITABLE_PROPERTY (QString,      name)
    QML_WRITABLE_PROPERTY (QString,      remark)

    Q_PROPERTY (QQmlObjectListModel<MySubmodel>* submodel READ submodel CONSTANT)

public:
    explicit MyModel (QObject * parent = NULL) : QObject (parent) {        
        m_mainID  = -1;
        m_submodel = new QQmlObjectListModel<MySubmodel>(this, "subname", "subname");
    }

public:

    QQmlObjectListModel<MySubmodel>* submodel() {
        return m_submodel;
    }

private:

    QQmlObjectListModel<MySubmodel> *m_submodel;

};

class App : public QObject
{
    Q_OBJECT
public:
    explicit App(QObject *parent = nullptr);

signals:

public slots:

    void btnAddPage(void);
    void btnClearAllPages(void);
    void btnAddListItem(int id);
    void btnUpdateListItem(int id);    
    void btnClearListItems(int id);

private:
    QQmlApplicationEngine engine;
    QQmlObjectListModel<MyModel> *testModel;

    int counter;
};

#endif // APP_H
