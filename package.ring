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
			:version = "1.1.2",
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
		"samples/UsingRingQML/runSamples.ring",
		"samples/UsingRingQML/Hello_world.ring",
		"samples/UsingRingQML/take_snapShot_For_Item.ring",
		"samples/UsingRingQML/take_snapShot_For_Item_From_Component.ring",
		// Mansour
		"samples/UsingRingQML/Mansour/01-foundation/01-1-hello-ringqml.ring",
		"samples/UsingRingQML/Mansour/01-foundation/01-2-rectangle.ring",
		"samples/UsingRingQML/Mansour/01-foundation/01-3-anchor-relative.ring",
		"samples/UsingRingQML/Mansour/02-layout/02-1-col-layout.ring",
		"samples/UsingRingQML/Mansour/02-layout/02-2-col-layout.ring",
		"samples/UsingRingQML/Mansour/02-layout/02-3-grid-layout.ring",
		"samples/UsingRingQML/Mansour/02-layout/02-4-adapative-layout.ring",
		"samples/UsingRingQML/Mansour/03-interactive/03-1-col-layout.ring",
		"samples/UsingRingQML/Mansour/03-interactive/03-2-text-input.ring",
		"samples/UsingRingQML/Mansour/03-interactive/03-3-slider-control.ring",
		"samples/UsingRingQML/Mansour/04-visual/04-1-gradients.ring",
		"samples/UsingRingQML/Mansour/04-visual/04-2-borders-and-shadows.ring",
		"samples/UsingRingQML/Mansour/04-visual/04-3-icons-and-images.ring",
		"samples/UsingRingQML/Mansour/05-animation/05-1-property-animation.ring",
		"samples/UsingRingQML/Mansour/05-animation/05-2-sequential-animation.ring",
		"samples/UsingRingQML/Mansour/05-animation/05-3-rotation-animation.ring",
		"samples/UsingRingQML/Mansour/06-states/06-1-basic-states.ring",
		"samples/UsingRingQML/Mansour/06-states/06-2-expanded-collapsed-states.ring",
		"samples/UsingRingQML/Mansour/07-ring-qml-link/07-1-call-ring-from-qml-button.ring",
		"samples/UsingRingQML/Mansour/07-ring-qml-link/07-2-ring-func-wit-return-value.ring",
		"samples/UsingRingQML/Mansour/07-ring-qml-link/07-3-ring-sets-qml-properties.ring",
		"samples/UsingRingQML/Mansour/07-ring-qml-link/07-4-complete-ring-qml-link.ring",
		"samples/UsingRingQML/Mansour/08-data-binding/08-1-property-bindings.ring",
		"samples/UsingRingQML/Mansour/08-data-binding/08-2-computed-properties.ring",
		"samples/UsingRingQML/Mansour/08-data-binding/08-3-list-model-and-repeater.ring",
		"samples/UsingRingQML/Mansour/09-advanced-patterns/09-1-custom-reusable-component.ring",
		"samples/UsingRingQML/Mansour/09-advanced-patterns/09-2-timer-and-periodic-updates.ring",
		"samples/UsingRingQML/Mansour/09-advanced-patterns/09-3-drawer-navigation-pattern.ring",
		"samples/UsingRingQML/Mansour/10-complete-application/10-1-task-management-application.ring",
		"samples/UsingRingQML/Mansour/11-advanced-controls/11-1-combo-box.ring",
		"samples/UsingRingQML/Mansour/11-advanced-controls/11-2-check-box.ring",
		"samples/UsingRingQML/Mansour/11-advanced-controls/11-3-spin-box-and-progress-bar.ring",
		"samples/UsingRingQML/Mansour/11-advanced-controls/11-4-tabbar-tabview-navigation.ring",
		"samples/UsingRingQML/Mansour/12-data-display/12-1-tableview-with-grid-data.ring",
		"samples/UsingRingQML/Mansour/12-data-display/12-2-gridview-with-data.ring",
		"samples/UsingRingQML/Mansour/12-data-display/12-3-swipeview-with-pages.ring",
		"samples/UsingRingQML/Mansour/12-data-display/12-4-tree-like-data-structures.ring",
		"samples/UsingRingQML/Mansour/13-dialogs-and-popups/13-1-dialog-windows.ring",
		"samples/UsingRingQML/Mansour/13-dialogs-and-popups/13-2-popup-and-tooltip.ring",
		"samples/UsingRingQML/Mansour/14-dataviz/14-1-custom-bar-chart-with-canvas.ring",
		"samples/UsingRingQML/Mansour/14-dataviz/14-2-pie-chart-visualization.ring",
		"samples/UsingRingQML/Mansour/14-dataviz/14-3-progress-visualizations.ring",
		"samples/UsingRingQML/Mansour/14-dataviz/14-4-line-chart-with-animation.ring",
		"samples/UsingRingQML/Mansour/15-mobile-and-ui-patterns/15-1-pull-to-refresh-pattern.ring",
		"samples/UsingRingQML/Mansour/15-mobile-and-ui-patterns/15-2-bottom-sheet.ring",
		"samples/UsingRingQML/Mansour/15-mobile-and-ui-patterns/15-3-floating-action-button.ring"	
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