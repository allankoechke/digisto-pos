@echo off
setlocal

REM === USAGE ===
REM deploy.bat <binary_path> [windeployqt_path] [qmldir_path]

REM === ARGUMENT PARSING ===
if "%~1"=="" (
    echo ERROR: Binary path is required.
    echo Usage: %~nx0 ^<binary_path^> [windeployqt_path] [qmldir_path]
    exit /b 1
)
set "BINARY=%~1"

if "%~2"=="" (
    set "WINDEPLOYQT_PATH=windeployqt"
) else (
    set "WINDEPLOYQT_PATH=%~2"
)

if "%~3"=="" (
    set "QMLDIR=ui"
) else (
    set "QMLDIR=%~3"
)

echo Deploying Qt app:
echo   Binary:           %BINARY%
echo   windeployqt path: %WINDEPLOYQT_PATH%
echo   QML directory:    %QMLDIR%

REM === DEPLOY ===
ver | find "Windows" >nul
if %errorlevel%==0 (
    echo Running on Windows...

    if not exist "%BINARY%" (
        echo ERROR: Binary not found at "%BINARY%"
        exit /b 1
    )

    "%WINDEPLOYQT_PATH%" ^
    --qmldir "%QMLDIR%" ^
    --no-translations ^
    --no-opengl-sw ^
    --no-multimedia ^
    --no-printsupport ^
    --no-sql ^
    -webengine ^
    "%BINARY%"

    @REM --no-angle ^
    @REM "%WINDEPLOYQT_PATH%" ^
    @REM     --qmldir "%QMLDIR%" ^
    @REM     --no-bluetooth ^
    @REM     --no-concurrent ^
    @REM     --no-core ^
    @REM     --no-declarative ^
    @REM     --no-designer ^
    @REM     --no-designercomponents ^
    @REM     --no-enginio ^
    @REM     --no-gamepad ^
    @REM     --no-gui ^
    @REM     --no-qthelp ^
    @REM     --no-multimedia ^
    @REM     --no-multimediawidgets ^
    @REM     --no-multimediaquick ^
    @REM     --no-network ^
    @REM     --no-nfc ^
    @REM     --no-opengl ^
    @REM     --no-positioning ^
    @REM     --no-printsupport ^
    @REM     --no-qml ^
    @REM     --no-qmltooling ^
    @REM     --no-quick ^
    @REM     --no-quickparticles ^
    @REM     --no-quickwidgets ^
    @REM     --no-script ^
    @REM     --no-scripttools ^
    @REM     --no-sensors ^
    @REM     --no-serialport ^
    @REM     --no-sql ^
    @REM     --no-svg ^
    @REM     --no-test ^
    @REM     --no-webkit ^
    @REM     --no-webkitwidgets ^
    @REM     --no-websockets ^
    @REM     --no-widgets ^
    @REM     --no-winextras ^
    @REM     --no-xml ^
    @REM     --no-xmlpatterns ^
    @REM     --no-webenginecore ^
    @REM     --no-webengine ^
    @REM     --no-webenginewidgets ^
    @REM     --no-3dcore ^
    @REM     --no-3drenderer ^
    @REM     --no-3dquick ^
    @REM     --no-3dquickrenderer ^
    @REM     --no-3dinput ^
    @REM     --no-3danimation ^
    @REM     --no-3dextras ^
    @REM     --no-geoservices ^
    @REM     --no-webchannel ^
    @REM     --no-texttospeech ^
    @REM     --no-serialbus ^
    @REM     --no-webview ^
    @REM     --no-translations ^
    @REM     --no-virtualkeyboard ^
    @REM     --no-webkit2 ^
    @REM     --json ^
    @REM     --no-angle ^
    @REM     --no-opengl-sw ^
    @REM     "%BINARY%"
) else (
    echo Linux or unsupported OS detected.
    echo You must run linuxdeployqt manually for this platform.
)

endlocal
