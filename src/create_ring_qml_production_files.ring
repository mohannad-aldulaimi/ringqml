load 'stdlibcore.ring'

cHeader = `/*
    Project      : RingQML library for Ring Programming Language
    Author       : Mohannad Azeez Al-Ayash 
    E-Mail       : mohannadazazalayash@gmail.com
    WebSite      : https://mohannad-aldulaimi.github.io
	Date         : 29/12/2025
*/`

# 'Lists of Lib Files'
	aHeadersFiles = listAllFiles(".","*.h")
	aSourcesFiles = listAllFiles(".","*.cpp")
# 'Global Variable For Files Names'
	cHeaderFileName='RingQML/RingQML.h'
	cSourceFileName='RingQML/RingQML.cpp'
	cApi_Ext_FileName ='cpp/ring_qml_api.cpp'


# 'Global Variable For Files Contents'
	cHeaderFileContent= ''
	cSourceFileContent= ''
# 'Global List For Headers (include)'
	aIncluded_modules=[]
# 'Fixing Paths By removing "./"'
	fixPaths(aHeadersFiles)
	fixPaths(aSourcesFiles)


startReadingFiles()


func startReadingFiles
	for cFileName in aHeadersFiles
		if cFileName = cApi_Ext_FileName or substr(cFileName,"RingQML/")
			continue
		ok
		See 'Start Reading File : '+cFileName
		See ' | Analyzing '
		StartAnaLasingFile(cFileName,:header)
		? ' -> Done'
	next 
	? ''
	for cFileName in aSourcesFiles
		if cFileName = cApi_Ext_FileName or substr(cFileName,"RingQML/")
			continue
		ok
		See 'Start Reading File : '+cFileName
		See ' | Analyzing '
		StartAnaLasingFile(cFileName,:Source)
		? ' -> Done'
	next 
	? ''
	See 'Start Reading File : '+cApi_Ext_FileName
	See ' | Analyzing '
	StartAnaLasingFile(cApi_Ext_FileName,:Source)
	? ' -> Done'


updateBeforWrite()
writeFiles()




func updateBeforWrite
	cHeaderFileContent= 'extern "C" { '+nl+tab+'#include "ring.h"'+nl+'}'+cHeaderFileContent
	cHeaderFileContent=cHeader+nl+list2str(aIncluded_modules)+nl+nl+cHeaderFileContent
	cSourceFileContent=cHeader+nl+list2str(aIncluded_modules)+nl+'#include "RingQML.h"'+nl+nl+cSourceFileContent


	cExtra_empty_Extern='extern "C" {
	}'
	cHeaderFileContent = substr(cHeaderFileContent,cExtra_empty_Extern,'')
	cSourceFileContent = substr(cSourceFileContent,cExtra_empty_Extern,'')

func writeFiles 
	
	write(cHeaderFileName, cHeaderFileContent)
	write(cSourceFileName, cSourceFileContent)
	? ''
	See cHeaderFileName +' : ' ? ''+len(cHeaderFileContent)+' Byte.'
	See cSourceFileName +' : ' ? ''+len(cSourceFileContent)+' Byte.'


func StartAnaLasingFile(cFileName,cFileType)
	aContent = split(read(cFileName),nl)
	l_FileStart  = 0
	l_IncludeStart  = 0
	if cFileType = :Header
		cHeaderFileContent+= nl+nl+'// File : '+justfileName(cFileName)+nl
	but cFileType = :Source
		cSourceFileContent+= nl+nl+'// File : '+justfileName(cFileName)+nl
	ok
	for line in aContent
		if isnull(trim(line))
			continue
		ok
		if startsWith(line , "//<FileStart>")
				l_FileStart=1
				continue
		but startsWith(line , "//<FileEnd>")
				l_FileStart=0
				continue
		but startsWith(line , "//<IncludeStart>")
				l_IncludeStart=1
				continue
		but startsWith(line , "//<IncludeEnd>")
				l_IncludeStart=0
				continue
		ok 

		if l_FileStart
			if l_IncludeStart
				if ! find(aIncluded_modules,line )
					aIncluded_modules+line 
				ok
				continue
			ok 
			if ! l_IncludeStart and startsWith(trim(line),"#include")
				continue
			ok
			if cFileType = :Header
				cHeaderFileContent+= tab +line+nl
			but cFileType = :Source
				cSourceFileContent+= tab+line+nl

			ok

		ok

	next 

	
func fixPaths aList 
	for item in aList
		item = substr(item, './','')
	next 
