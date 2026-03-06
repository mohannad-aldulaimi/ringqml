@echo off
setlocal

rem Check if Ring is already in PATH by using 'where' command
where ring >nul 2>nul
if %errorlevel% equ 0 (
    for /f "delims=" %%I in ('where ring') do (
        set RING_EXE=%%I
        goto :found_ring
    )
)

rem If not in PATH, try checking standard default installation path on Windows
if exist "C:\ring\bin\ring.exe" (
    set RING_EXE="C:\ring\bin\ring.exe"
    goto :found_ring
)

echo ERROR: Could not find 'ring' executable in PATH or C:\ring\bin.
echo Please ensure Ring is installed and added to your environment variables.
exit /b 1

:found_ring
echo Found Ring executable at: %RING_EXE%

rem Get the directory containing the ring executable to find the extensions path
for %%F in ("%RING_EXE%") do set RING_BIN_DIR=%%~dpF
set RING_PATH=%RING_BIN_DIR%..

set PAREC_RING="%RING_PATH%\extensions\codegen\parsec.ring"

if not exist %PAREC_RING% (
    echo ERROR: Could not find "%PAREC_RING%".
    echo Path to Ring seems correct at %RING_PATH%, but codegen extension is missing.
    exit /b 1
)

echo calling set_qt_flags_qml.bat to load configurations...
if exist "set_qt_flags_qml.bat" (
    call "set_qt_flags_qml.bat"
) else (
    if exist "classes\set_qt_flags_qml.bat" (
        call "classes\set_qt_flags_qml.bat"
    ) else (
        echo WARNING: set_qt_flags_qml.bat not found. Generating with default flags...
    )
)

echo Calling code generator...
"%RING_EXE%" %PAREC_RING% classes\qt.cf ring_qt_qml.cpp ring_qt_qml.ring

echo Code generation finished!
endlocal
