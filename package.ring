aPackageInfo = [
	:name = "The RingQML Package",
	:description = "RingQML library for the Ring programming language",
	:folder = "RingQML",
	:developer = "Ph.T, Dev. Mohannad Alayash",
	:email = "mohannadazazalayash@gmail.com",
	:license = "MIT License",
	:version = "1.3.0",
	:ringversion = "1.25",
	:versions = 	[
		[
			:version = "1.3.0",
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
		"bin/load/ring_qt_qml.ring",
		"libraries/RingQML/callringfuncfromqml.ring",
		"libraries/RingQML/corefunctions.ring",
		"libraries/RingQML/globals.ring",
		"libraries/RingQML/ringQML.ring",
		"libraries/RingQML/ringQmlRoot.ring",
		"libraries/RingQML/ringQMLObject.ring",
		"libraries/RingQML/utils.ring"
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
		"bin/ring_qt_qml.dll",
		"bin/RingQML.dll",
		"bin/RingQML6.dll"
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