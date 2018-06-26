import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Window 2.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Submodel in Model")

    SwipeView {
        id: view
        orientation: Qt.Horizontal
        anchors.fill: parent
        Page {
            Frame {
                anchors.fill: parent
                anchors.margins: 3
                ColumnLayout {
                    Text {
                        text: "Fixed Main Page"
                    }
                    RowLayout {
                        Button {
                            text: "add Page"
                            onClicked: {
                                logic.btnAddPage();
                            }
                        }
                        Button {
                            text: "remove all Pages"
                            onClicked: {
                                logic.btnClearAllPages();
                            }
                        }
                    }
                }
            }
        }

        Repeater {
            id: rep
            model: testModel
            // model: 5
            Page {
                id: page
                Frame {
                    anchors.fill: parent
                    anchors.margins: 3

                    ColumnLayout {
                        anchors.fill: parent
                        Text {
                            text: model.name
                        }
                        Text {
                            text: "ID:" + model.mainID
                        }
                        Text {
                            text: "No:" + model.no
                        }
                        Text {
                            text: model.remark
                        }

                        RowLayout {
                            Button {
                                text: "Add ListItem"
                                onClicked: {
                                    logic.btnAddListItem(model.mainID);
                                }
                            }

                            Button {
                                text: "Clear List"
                                onClicked: {
                                    logic.btnClearListItems(model.mainID);
                                }
                            }
                        }

                        ListView {
                            clip: true
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            model: submodel
                            // model: 10
                            orientation: ListView.Vertical
                            delegate:
                                Frame {
                                width: parent.width
                                height: 40
                                Item {
                                    anchors.fill: parent
                                    Text {
                                        anchors.centerIn: parent
                                        text: model.subname
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    footer: TabBar {
        id: tabBar
        currentIndex: view.currentIndex

        TabButton {
            text: "Main"
            onClicked: {
                view.setCurrentIndex(0);
            }
        }
        Repeater {
            model: rep.model
            TabButton {
                text: model.name
                onClicked: {
                    view.setCurrentIndex(0 + model.no);
                }
            }
        }
    }
}
