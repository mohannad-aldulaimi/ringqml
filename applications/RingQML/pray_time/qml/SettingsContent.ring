
# --- SETTINGS CONTENT ---
func getSettingsContentComponent
return `
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    id: settingsRoot
    
    property var themeModel: ({ "textColor": "#ffffff", "baseFontSize": 18, "accentColor": "#00ff00", "currentThemeIndex": 0 })
    property string fontFamily: "Segoe UI"
    
    signal themeClicked()
    signal backgroundClicked()

    spacing: 25
    
    RowLayout {
        Layout.fillWidth: true 
        spacing: 10
        layoutDirection: Qt.RightToLeft
        
        Text {
            text: "تغير حجم الخط"
            color: themeModel.textColor
            font.pixelSize: themeModel.baseFontSize
            font.family: settingsRoot.fontFamily
            Layout.fillWidth: true
            Layout.preferredWidth: -1 
            wrapMode: Text.Wrap
        }
        
        Slider {
            id: customSlider
            from: 14.0
            to: 24.0
            stepSize: 1.0
            value: themeModel.baseFontSize
            onValueChanged: themeModel.baseFontSize = value
            Layout.fillWidth: true
            Layout.preferredWidth: -1
            LayoutMirroring.enabled: false

            background: Rectangle {
                x: customSlider.leftPadding
                y: customSlider.topPadding + customSlider.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: customSlider.availableWidth
                height: implicitHeight
                radius: 2
                color: "#505050"
                Rectangle {
                    width: customSlider.visualPosition * parent.width
                    height: parent.height
                    color: "#3498db"
                    radius: 2
                }
            }
            handle: Rectangle {
                x: customSlider.leftPadding + customSlider.visualPosition * (customSlider.availableWidth - width)
                y: customSlider.topPadding + customSlider.availableHeight / 2 - height / 2
                implicitWidth: 24
                implicitHeight: 24
                radius: 12
                color: customSlider.pressed ? "#f0f0f0" : "#ffffff"
                border.color: "#3498db"
                border.width: 2
                scale: customSlider.pressed ? 1.2 : 1.0
                Behavior on scale { NumberAnimation { duration: 100 } }
            }
        }
    }

    Button {
        text: "تغيير المظهر (" + (themeModel.currentThemeIndex + 1) + ")"
        Layout.fillWidth: true
        onClicked: settingsRoot.themeClicked()
        background: Rectangle {
            color: themeModel.accentColor
            radius: 8
        }
        contentItem: Text {
            text: parent.text
            color: "white"
            font.pixelSize: themeModel.baseFontSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: settingsRoot.fontFamily
        }
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            acceptedButtons: Qt.NoButton
        }
    }

    Button {
        text: "تغيير الخلفية"
        Layout.fillWidth: true
        onClicked: settingsRoot.backgroundClicked()
        background: Rectangle {
            color: themeModel.accentColor
            radius: 8
        }
        contentItem: Text {
            text: parent.text
            color: "white"
            font.pixelSize: themeModel.baseFontSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: settingsRoot.fontFamily
        }
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            acceptedButtons: Qt.NoButton
        }
    }
}
`