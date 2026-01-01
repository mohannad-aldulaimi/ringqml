aPackageInfo = [
	:name = "The RingQML Package",
	:description = "RingQML library for the Ring programming language",
	:folder = "RingQML",
	:developer = "Ph.T, Dev. Mohannad Alayash",
	:email = "mohannadazazalayash@gmail.com",
	:license = "MIT License",
	:version = "1.0.0",
	:ringversion = "1.24",
	:versions = 	[
		[
			:version = "1.1.0",
			:branch = "main"
		]
	],
	:libs = 	[
		[
			:name = "codegen",
			:version = "1.0",
			:providerusername = ""
		]
	],
	:files = 	[
		"README.md",
		"main.ring"
	],
	:ringfolderfiles = 	[
		"bin/load/ringQML.ring",
		"libraries/RingQML/callringfuncfromqml.ring",
		"libraries/RingQML/corefunctions.ring",
		"libraries/RingQML/globals.ring",
		"libraries/RingQML/ringQML.ring",
		"libraries/RingQML/ringQmlRoot.ring",
		"libraries/RingQML/ringQMLObject.ring",
		// Samples
		"samples/UsingRingQML/Hello_world.ring",
		// Applications
		"applications/RingQML/pray_time/README.md",
		"applications/RingQML/pray_time/pray_times.ring",
		"applications/RingQML/pray_time/getTimesFromTables.ring",
		"applications/RingQML/pray_time/tables/table.ring",
		"applications/RingQML/pray_time/qml/IconShape.ring",
		"applications/RingQML/pray_time/qml/main.ring"
	],
	:windowsfiles = 	[

	],
	:linuxfiles = 	[

	],
	:ubuntufiles = 	[

	],
	:fedorafiles = 	[

	],
	:freebsdfiles = 	[

	],
	:macosfiles = 	[

	],
	:windowsringfolderfiles = 	[
		"bin/RingQML.dll"
	],
	:linuxringfolderfiles = 	[

	],
	:ubunturingfolderfiles = 	[

	],
	:fedoraringfolderfiles = 	[

	],
	:freebsdringfolderfiles = 	[

	],
	:macosringfolderfiles = 	[

	],
	:run = "ring main.ring",
	:windowsrun = "",
	:linuxrun = "",
	:macosrun = "",
	:ubunturun = "",
	:fedorarun = "",
	:setup = "",
	:windowssetup = "",
	:linuxsetup = "",
	:macossetup = "",
	:ubuntusetup = "",
	:fedorasetup = "",
	:remove = "",
	:windowsremove = "",
	:linuxremove = "",
	:macosremove = "",
	:ubunturemove = "",
	:fedoraremove = ""
]