load 'guilib.ring'
load 'stdlibcore.ring'
load 'ringQML.ring'

// Creating folder "snapshots"
	OsCreateOpenFolder("snapshots")
	chdir('..')
new qApp {

	win=new QQuickView(){
		setWidth(500) setHeight(600)
		setTitle("RingQML : "+substr(justfilename(filename()),'_',' '))
		oQML = new RingQML(win){
			loadContent(getMainQml())

		}

		show()
		// grabItemsnapshot must be after Show ...
			oQML.grabItemsnapshot('myRect').save("snapshots/myRect.png","PNG",80)

	}

	exec()
}
func teakeSnapShowNow nCounter
	cFileName = "snapshots/myRect_"+nCounter+".png"
	oImage = oQML.grabItemsnapshot('myRect')
	nRes = oImage.save(cFileName,"PNG",80)
	? 'Ring : Saved File State : '+nRes +' File Name : '+cFileName

func getMainQml
return `

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    width: 500
    height: 500
    color: "transparent"
    anchors.centerIn: parent

    property int counterValue: 0

    Timer {
        interval: 100 
        running: true  
        repeat: true   
        onTriggered: root.counterValue = root.counterValue + 1
    }

    Rectangle {
        objectName: "myRect"
        width: 320
        height: 300
        anchors.centerIn: parent
        color: "#ffffff"
        radius: 15
        border.color: "#e0e0e0"
        border.width: 1
        
        layer.enabled: true 

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 10

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 50
                color: "#f5f7fa"
                radius: 8
                border.color: "#dcdcdc"
                border.width: 1

                Text {
                    anchors.centerIn: parent
                    text: "RingQML"
                    font.pixelSize: 26
                    font.weight: Font.Bold
                    color: "#2980b9"
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true

                Text {
                    anchors.centerIn: parent
                    text: root.counterValue
                    font.pixelSize: 64
                    font.bold: true
                    color: "#2c3e50"
                }
            }

            Button {
                text: "Take Snapshot"
                Layout.fillWidth: true
                Layout.preferredHeight: 45

                background: Rectangle {
                    color: parent.down ? "#1f618d" : "#2980b9"
                    radius: 8
                }

                contentItem: Text {
                    text: parent.text
                    font.pixelSize: 14
                    font.bold: true
                    color: "#ffffff"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                onClicked: {
                    Ring.callFunc("teakeSnapShowNow",[counterValue])
                }
            }
        }
    }
}
`

