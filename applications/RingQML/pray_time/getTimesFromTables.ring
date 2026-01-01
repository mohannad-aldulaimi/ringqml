load 'stdlibcore.ring'
load 'csvlib.ring'

load 'tables/table.ring'

func getThisDayPrayTimeList
	nDay = 0+left(date(),2)
	return getDayPrayTimeList(nDay)

func getDayPrayTimeList nDay
	aMonthTimeList = getMonthPrayTimesList()
	del(aMonthTimeList[nDay],1)
	return aMonthTimeList[nDay]

func getMonthPrayTimesList
	cCSVOfMonth = getTableCsvForThisMonth()
	aCSVTimes = csv2list(cCSVOfMonth)
	del(aCSVTimes,1)
	return aCSVTimes
func getTableCsvForThisMonth

	nMonth = 0+substr(date(),4,2)
	aTextList = str2list(gettableCSVContent())
	cSpliter = '##'
	nLength = len(aTextList)
	l_Found_Month = 0
	nMonthCounter = 1
	

	cMonthCSV = ''
	for nLine = 1 to nLength
		if nMonth=1 and nLine=2
			l_Found_Month=1
		ok
		if aTextList[nLine] = cSpliter
			if l_Found_Month
				exit
			ok
			
			nMonthCounter++
			if nMonthCounter = nMonth
				l_Found_Month=1
			ok
		else
			if l_Found_Month
				cMonthCSV += aTextList[nLine] + nl
			ok
		ok
		
	next
	return cMonthCSV
