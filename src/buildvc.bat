IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=5.15.2
cls
setlocal enableextensions enabledelayedexpansion

REM Locate Visual Studio Compiler (Ring standard script)
call ..\..\language\build\locatevc.bat x64

REM Run QMake (CONFIG+=release is enforced in the .pro now)
"%RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\bin\qmake.exe" ring_qml.pro -spec win32-msvc "CONFIG+=qtquickcompiler"

REM Build using JOM
"%RING_QT_DIR%\Tools\QtCreator\bin\jom\jom.exe"

REM Deploy (Copy from the new 'Build' folder)
rd /s /q "Build\tmp"

rem copy Build\RingQML.dll ..\lib
copy Build\RingQML.dll c:\ring\bin

REM Cleanup
del MakeFile*
endlocal