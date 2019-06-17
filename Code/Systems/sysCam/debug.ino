void debugCameraL() {
  // LEFT
  Serial.println("================================================================================");
  Serial.println("Left Blobs count: " + String(cam_l.blobs_count));
  
  for(int i = 0; i < cam_l.blobs_count; i++) {
    CamBlob b = cam_l.blob[i];
    Serial.println("►Blob {" + String(i) + "} info : Type [" + b.type + ";] Dummy [" + b.dummy + 
                 "]; CenterPos X[" + b.cx + "] Y[" + b.cy + 
                 "]; Top [" + b.top + "]; Bottom [" + b.bottom + "]; Left [" + b.left + "]; Right [" + b.right + "]");
  }
  Serial.println("================================================================================");
}


void debugCameraR() {
  // RIGHT
  Serial.println("================================================================================");
  Serial.println("Right cam Blobst: " + String(cam_r.blobs_count));
  
  for(int i = 0; i < cam_r.blobs_count; i++) {
    CamBlob b = cam_r.blob[i];
    Serial.println("► Blob {" + String(i) + "} info : Type [" + b.type + "]; Dummy [" + b.dummy + 
                 "]; CenterPos X[" + b.cx + "] Y[" + b.cy + 
                 "]; Top [" + b.top + "]; Bottom [" + b.bottom + "]; Left [" + b.left + "; Right [" + b.right + "]");
  }
  Serial.println("================================================================================");
}
