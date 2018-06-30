#include "app.h"



App::App(QObject *parent) : QObject(parent)
{

    qRegisterMetaType<QQmlObjectListModel<MySubmodel>*>("QQmlObjectListModel<MySubmodel>*");

    counter = 0;

    testModel = new QQmlObjectListModel<MyModel>(this, "name", "name");

    engine.rootContext()->setContextProperty("testModel", testModel);
    engine.rootContext()->setContextProperty("logic", this);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        // error in qml file
    } else {

    }
}

void App::btnClearAllPages(void) {
    testModel->clear();
    counter = 0;
}
void App::btnClearListItems(int id) {
    for (int z = 0; z<testModel->count(); z++) {
        if (testModel->at(z)->get_mainID() == id) {
            testModel->at(z)->submodel()->clear();
        }
    }
}

void App::btnUpdateListItem(int id) {
    for (int z = 0; z<testModel->count(); z++) {
        if (testModel->at(z)->get_mainID() == id) {
            if (testModel->at(z)->submodel()->count() > 2) {
                // just update the second Item in the Submodel in case it exists:
                testModel->at(z)->submodel()->at(1)->set_subname("Update TEST!");
            }
        }
    }
}

void App::btnAddListItem(int id) {
    for (int z = 0; z<testModel->count(); z++) {
        if (testModel->at(z)->get_mainID() == id) {
            MySubmodel *sub = new MySubmodel();
            sub->set_subid(testModel->at(z)->submodel()->count() + 1);
            sub->set_subname("SubName " + QString::number(testModel->at(z)->submodel()->count()));
            testModel->at(z)->submodel()->append(sub);
        }
    }
}

void App::btnAddPage() {
    MyModel *d = new MyModel(this);
    d->set_mainID(counter);
    d->set_no(counter + 1);
    d->set_name("Page " + QString::number(counter + 1));
    d->set_remark("Remark text.");
    testModel->append(d);

    counter++;
}
