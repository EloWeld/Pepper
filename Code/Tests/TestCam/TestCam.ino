#include <TrackingCamDxlUart.h>

// Объект камеры
TrackingCamDxlUart cam;

int blobs_count = 0;

// Таймер считывания камеры
unsigned long timer_cam = 0;

//==================================================================================================
// Инициализация
//==================================================================================================

void setup() {
  cam.init(51, 1, 115200, 30); 
  Serial.begin(115200);
}

//==================================================================================================
// Главный цикл
//==================================================================================================

void loop() {
  if (millis() - timer_cam >= 10) {
    blobs_count = cam.readBlobs(5); // 5 - max blobs

    Serial.println("================================================================================");
    Serial.print("Blobs count: " + String(blobs_count));
    
    Serial.println();
    for(int i = 0; i < blobs_count; i++) {
      TrackingCamBlobInfo_t b = cam.blob[i];
      Serial.println("►Blob {" + String(i) + "} info : Type [" + b.type + ";] Dummy [" + b.dummy + 
                   "]; CenterPos X[" + b.cx + "] Y[" + b.cy + 
                   "]; Top [" + b.top + "]; Bottom [" + b.bottom + "]; Left [" + b.left + "]; Right [" + b.right + "]");
    }
    Serial.println("================================================================================");
    
    timer_cam = millis();
  }
}
