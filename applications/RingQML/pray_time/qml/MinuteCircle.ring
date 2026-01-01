# --- COMPONENT: MINUTE CIRCLE ---
func getMinuteCircleComponent
return `
import QtQuick 2.15

Canvas {
    id: canvas
    
    // Properties to be set by the parent
    property real progress: 0.0
    property color baseColor: "#ffffff"
    property color progressColor: "#000000"

    renderTarget: Canvas.Image
    renderStrategy: Canvas.Cooperative
    antialiasing: true
    
    onWidthChanged: requestPaint()
    onHeightChanged: requestPaint()
    onProgressChanged: requestPaint()
    onBaseColorChanged: requestPaint()
    onProgressColorChanged: requestPaint()

    Behavior on progress { NumberAnimation { duration: 1000; easing.type: Easing.OutCubic } }

    onPaint: {
        var ctx = getContext("2d");
        ctx.reset();
        var centerX = width / 2;
        var centerY = height / 2;
        var radius = Math.min(width, height) / 2 - 10;
        
        if (radius <= 0) return;

        ctx.lineWidth = 8;
        ctx.strokeStyle = baseColor;
        ctx.beginPath();
        ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI);
        ctx.stroke();
        
        if (progress > 0) {
            ctx.strokeStyle = progressColor;
            ctx.lineCap = "round";
            ctx.beginPath();
            ctx.arc(centerX, centerY, radius, -Math.PI / 2, (2 * Math.PI * progress) - Math.PI / 2);
            ctx.stroke();
        }
    }
}
`