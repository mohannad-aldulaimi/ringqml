load 'guilib.ring'
load 'ringQML.ring'

new qApp {

	win=new QQuickView(){
		setWidth(300)
		oQML = new RingQML(win){
			NewComponent("RedBox",getRedBoxComp()){
				root.me(2016)
			}
			loadContent(getMainQml())
			root.me(2025)
		}

		show()
	}

	exec()
}

func getRedBoxComp
return `

import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: myRedBoxRoot
    width: 500
    height: 500
	color:"red"
	function me(n){
		console.log("I'am RedBox, n=",n)
	}
	Text {
		id:myText 
		text :"RedBox Component Loaded"
		font.pointSize:20
	}
}
`
func getMainQml
return `

import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: myRedBoxRoot
    width: 500
    height: 500
	color:"green"
	function me(n){
		console.log("I'am Main, n=",n)
	}
	Column {
		spacing:20
		Text {
			id:myText 
			text :"Ring QML Is Loaded"
			font.pointSize:20
		}
		RedBox {
			id:myRedBox

		}
	}
}
`

