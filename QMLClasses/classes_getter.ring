load 'ring_qt_qml.ring'

aClasses = classes()

? 'We have : '+ len(aClasses) +' classe'

? "Here is our created classes : "
for x=1 to len(aClasses)
	? ''+x+' : '+aClasses[x]
next 

