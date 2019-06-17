#define CAM_WIDTH    320
#define CAM_HEIGHT   240
#define CAM_CENTER_X 160
#define CAM_CENTER_Y 120
#define CAM_OFFSET_X 0
#define CAM_OFFSET_Y 0


// Zones
const int cam_left_zone = 30;
const int cam_right_zone = 290;
const int cam_top_zone = 30;
const int cam_bottom_zone = 210;

// Thresholds
const int blob_center_tlv = 90;
const int end_way_threshold = 35;
const int x_way_threshold = 30;
const int area_curve_tlv = 6000; // tlv = threshold limit value 

void camSetup() {
  cam_l.init(51, 115200, 30); // 51 for left camera
  //cam_r.init(52, 115200, 30); // 52 for right camera
}

void camRead() {
  cam_l.readBlobs(5);
  //cam_r.readBlobs();
}

CamBlob camLineBlobFilter(Camera *cam) {

  // Filter out far blobs
  CamBlob blobs[5];
  byte idx = 0;
  for(int i = 0; i < cam->blobs_count; i++) {
    if (distFromCenterTlv(cam->blob[i].cx, cam->blob[i].cy, blob_center_tlv)) {
      blobs[idx++] = cam->blob[i];
    }
  }

  // Find th biggest blob (1-st solution)
  /**********************************
  byte mx_area_idx = 0;
  for(int i = 1; i < cam->blobs_count; i++) {
    if (cam->blob[i].area > cam->blob[mx_area_idx].area) {
      mx_area_idx = i;
    }
  }
  
  // return blob with maximum area
  return cam->blob[mx_area_idx];
  **********************************/

  // Make the arage blob (2-nd solution)
  CamBlob out_blob = blobs[0];
  byte lt = 0, rt = 0, tp = 0, bm = 0;
  for(int i = 1; i < idx; i++) {
    out_blob.area += blobs[i].area;
    out_blob.cx += blobs[i].cx;
    out_blob.cy += blobs[i].cy;
    if (blobs[i].left < blobs[lt].left) lt = i;
    if (blobs[i].right > blobs[rt].right) rt = i;
    if (blobs[i].top < blobs[tp].top) tp = i;
    if (blobs[i].bottom > blobs[bm].bottom) bm = i;
    
  }
  out_blob.cx = (int)(out_blob.cx / idx);
  out_blob.cy = (int)(out_blob.cy / idx);
  out_blob.left = blobs[lt].left; 
  out_blob.right = blobs[rt].right;
  out_blob.top = blobs[tp].top; 
  out_blob.bottom = blobs[bm].bottom;

  // return out blob
  return out_blob;
}

byte camDefineCell(CamBlob blob) {
  bool in_left = blob.left < cam_left_zone;
  bool in_right = blob.right > cam_right_zone;
  bool in_top = blob.top < cam_top_zone;
  bool in_bottom = blob.bottom > cam_bottom_zone;

  // Straight line
  if ((in_top  && in_bottom) && !in_left && !in_right)  return 11; // ║
  if ((in_left && in_right)  && !in_top  && !in_bottom) return 12; // =

  // End way
  if (in_top    && distFromCenterTlv((CAM_CENTER_X + CAM_OFFSET_X), blob.bottom, end_way_threshold) && !in_bottom && !in_right && !in_left)   return 21; // ╵
  if (in_right  && distFromCenterTlv(blob.left, (CAM_CENTER_Y + CAM_OFFSET_Y), end_way_threshold)   && !in_left   && !in_top   && !in_bottom) return 22; // ╾ 
  if (in_bottom && distFromCenterTlv((CAM_CENTER_X + CAM_OFFSET_X), blob.top, end_way_threshold)    && !in_top    && !in_right && !in_left)   return 23; // ╷
  if (in_left   && distFromCenterTlv(blob.right, (CAM_CENTER_Y + CAM_OFFSET_Y), end_way_threshold)  && !in_right  && !in_top   && !in_bottom) return 24; // ╼

  // 3-cross
  if (in_left   && in_top    && in_right  && (!in_bottom)) return 31; // ┻
  if (in_top    && in_right  && in_bottom && (!in_left))   return 32; // ┣
  if (in_right  && in_bottom && in_left   && (!in_top))    return 33; // ┳
  if (in_bottom && in_left  && in_top    && (!in_right))  return 34; // ┫

  // X-cross
  if (in_left && in_right && in_top && in_bottom && distFromCenterTlv(blob.cx, blob.cy, x_way_threshold)) return 40; // ╂

  // Turn (5x - straight turn; 6x - curve_turn )
  if ((in_right && in_top)     && !in_bottom && !in_left)  return (blob.area > area_curve_tlv ? 51 : 61);  // ┗
  if ((in_right && in_bottom)  && !in_top    && !in_left)  return (blob.area > area_curve_tlv ? 52 : 62);  // ┏ 
  if ((in_left  && in_bottom)  && !in_top    && !in_right) return (blob.area > area_curve_tlv ? 53 : 63);  // ┓
  if ((in_left  && in_top)     && !in_bottom && !in_right) return (blob.area > area_curve_tlv ? 54 : 64);  // ┛

  return 0;
}

bool distFromCenterTlv(int x, int y, int threshold) {
  return distBetweenPoints(CAM_CENTER_X + CAM_OFFSET_X, CAM_CENTER_Y + CAM_OFFSET_Y, x, y) < threshold;
}

int distBetweenPoints(int x1, int y1, int x2, int y2) {
  return (round(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))));
}
