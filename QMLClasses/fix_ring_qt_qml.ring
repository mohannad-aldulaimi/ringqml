
cCppFile = read("ring_qt_qml.cpp")
cCppFile = substr(cCppFile, "@H@ifdef", "#ifdef")
cCppFile = substr(cCppFile, "@H@else", "#else")
cCppFile = substr(cCppFile, "@H@endif", "#endif")
cCppFile = substr(cCppFile, "    ", tab)
write("ring_qt_qml.cpp", cCppFile)
