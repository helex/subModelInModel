#include "app.h"



App::App(QObject *parent) : QObject(parent)
{

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
            testModel->at(z)->get_submodel()->clear();
        }
    }
}

void App::btnAddListItem(int id) {
    for (int z = 0; z<testModel->count(); z++) {
        if (testModel->at(z)->get_mainID() == id) {
            MySubmodel *sub = new MySubmodel();
            sub->set_subid(1);
            sub->set_subname("SubName " + QString::number(testModel->at(z)->get_submodel()->count()));
            testModel->at(z)->Submodel_Add(sub);
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
