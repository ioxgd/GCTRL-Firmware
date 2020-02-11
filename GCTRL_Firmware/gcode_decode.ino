float minX = 999999999.9;
float maxX = -999999999.9;
float minY = 999999999.9;
float maxY = -999999999.9;

void gcode_get_image_size(char *gcode, float *width, float *height) {
  char line_buff[500];
  int index = 0, line_buff_index = 0;
  bool commentFlag = false;
  bool penDownFlag = false;
  float lastX = 0, lastY = 0;
  while (gcode[index] != 0) {
    char c = gcode[index++];
    if (c == '\r') continue;

    if (c == '\n') {
      line_buff[line_buff_index] = 0;

      if (strlen(line_buff) == 0) continue;

      printf("%s\n", line_buff);

      char cmd;
      int cmdCode;

      sscanf(line_buff, "%c%d", &cmd, &cmdCode);

      if (cmd == 'M') {
        if (cmdCode == 300) {
          float angle = 0;
          sscanf(line_buff, "M300 S%f", &angle);
          if (angle == 50.0) { // pen up
            penDownFlag = false;
          } else if (angle == 30.0) { // pen down
            penDownFlag = true;

            minX = min(lastX, minX);
            maxX = max(lastX, maxX);
            minY = min(lastY, minY);
            maxY = max(lastY, maxY);
          }
        }
      } else if (cmd == 'G') {
        if (cmdCode == 0 || cmdCode == 1) {
          float x = 0.0, y = 0.0;
          sscanf(line_buff, "G%*d X%f Y%f", &x, &y);

          if (penDownFlag) {
            minX = min(x, minX);
            maxX = max(x, maxX);
            minY = min(y, minY);
            maxY = max(y, maxY);
          }

          lastX = x;
          lastY = y;
        }
      }

      line_buff_index = 0;
      memset(line_buff, 0, 500);
    }
    else if (c == '(') {
      commentFlag = true;
    } else if (c == ')') {
      commentFlag = false;
    } else if (commentFlag == false) {
      line_buff[line_buff_index++] = c;
    }
  }

  *width = abs(maxX - minX);
  *height = abs(maxY - minY);
}

void gcode_get_image_size_file(File myFile, float *width, float *height) {
  myFile.seek(0);

  char line_buff[500];
  int line_buff_index = 0;
  bool commentFlag = false;
  bool penDownFlag = false;
  float lastX = 0, lastY = 0;
  Serial.println("gcode_get_image_size_file...");
  while (myFile.available()) {
    char c = myFile.read();
    if (c == '\r') continue;

    if (c == '\n') {
      line_buff[line_buff_index] = 0;

      if (strlen(line_buff) == 0) continue;

      Serial.println(line_buff);

      char cmd;
      int cmdCode;

      sscanf(line_buff, "%c%d", &cmd, &cmdCode);

      if (cmd == 'M') {
        if (cmdCode == 300) {
          float angle = 0;
          sscanf(line_buff, "M300 S%f", &angle);
          if (angle == 50.0) { // pen up
            penDownFlag = false;
          } else if (angle == 30.0) { // pen down
            penDownFlag = true;

            minX = min(lastX, minX);
            maxX = max(lastX, maxX);
            minY = min(lastY, minY);
            maxY = max(lastY, maxY);
          }
        }
      } else if (cmd == 'G') {
        if (cmdCode == 0 || cmdCode == 1) {
          float x = 0.0, y = 0.0;
          sscanf(line_buff, "G%*d X%f Y%f", &x, &y);

          if (penDownFlag) {
            minX = min(x, minX);
            maxX = max(x, maxX);
            minY = min(y, minY);
            maxY = max(y, maxY);
          }

          lastX = x;
          lastY = y;
        }
      }

      line_buff_index = 0;
      memset(line_buff, 0, 500);
    }
    else if (c == '(') {
      commentFlag = true;
    } else if (c == ')') {
      commentFlag = false;
    } else if (commentFlag == false) {
      line_buff[line_buff_index++] = c;
    }
  }

  *width = abs(maxX - minX);
  *height = abs(maxY - minY);
}

#define LINE_BUFFER_SIZE 200
#define LINE_POINTS_BUFFER_SIZE 500

#define LINE_OBJ_BUFFER_SIZE 100

lv_obj_t *line[LINE_OBJ_BUFFER_SIZE];

void gcode_drew_line(char *gcode, lv_obj_t *objCanvas) {
  float w, h;
  gcode_get_image_size(gcode, &w, &h);

  float offsetX = 10.0;
  float offsetY = 10.0;
  
  float scale = 0.0;
  if (w > h) {
    scale = (780.0 - 240.0) / w;
    offsetY = (480.0 / 2.0) - (h * scale / 2.0);
  } else {
    scale = 460.0 / h;
    offsetX = ((800.0 - 240.0) / 2.0) - (w * scale / 2.0);
  }

  static lv_style_t style_line;
  lv_style_copy(&style_line, &lv_style_plain);
  style_line.line.color = lv_color_hex(0x000000);
  style_line.line.width = 1;
  style_line.line.rounded = 0;

  static lv_point_t *points[LINE_BUFFER_SIZE];

  for (int i=0;i<LINE_BUFFER_SIZE;i++) {
    if (points[i]) free(points[i]);
  }
  lv_obj_clean(objCanvas);
  for (int i=0;i<LINE_OBJ_BUFFER_SIZE;i++) {
    if (line[i]) {
      lv_obj_del(line[i]);
      line[i] = 0;
    }
  }

  lv_point_t points_buff[LINE_POINTS_BUFFER_SIZE];

  int points_index = 0;
  int line_points_index = 0;

  char line_buff[500];
  int index = 0, line_buff_index = 0;
  bool commentFlag = false;
  bool penDownFlag = false;
  float lastX = 0, lastY = 0;
  while (gcode[index] != 0) {
    char c = gcode[index++];
    if (c == '\r') continue;

    if (c == '\n') {
      line_buff[line_buff_index] = 0;

      if (strlen(line_buff) == 0) continue;

      char cmd;
      int cmdCode;

      sscanf(line_buff, "%c%d", &cmd, &cmdCode);

      if (cmd == 'M') {
        if (cmdCode == 300) {
          float angle = 0;
          sscanf(line_buff, "M300 S%f", &angle);
          if (angle == 50.0) { // pen up
            penDownFlag = false;

            points[points_index] = (lv_point_t*)malloc(sizeof(lv_point_t) * line_points_index);
            for (int index=0;index<line_points_index;index++) {
              points[points_index][index].x = points_buff[index].x;
              points[points_index][index].y = points_buff[index].y;
            }

            memset(points_buff, 0, sizeof(lv_point_t) * LINE_POINTS_BUFFER_SIZE);

            line[points_index] = lv_line_create(objCanvas, NULL);
            lv_line_set_points(line[points_index], points[points_index], line_points_index);
            lv_line_set_style(line[points_index], LV_LINE_STYLE_MAIN, &style_line);
            lv_obj_align(line[points_index], NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

            points_index++;
            line_points_index = 0;
          } else if (angle == 30.0) { // pen down
            penDownFlag = true;

            points_buff[line_points_index].x = lastX;
            points_buff[line_points_index].y = lastY;
            line_points_index++;
          }
        }
      } else if (cmd == 'G') {
        if (cmdCode == 0 || cmdCode == 1) {
          float x = 0.0, y = 0.0;
          sscanf(line_buff, "G%*d X%f Y%f", &x, &y);

          x = offsetX + ((x + (minX < 0 ? abs(minX) : -minX)) * scale);
          y = offsetY + ((h - y - (minY < 0 ? abs(minY) : -minY)) * scale);

          if (penDownFlag) {
            points_buff[line_points_index].x = x;
            points_buff[line_points_index].y = y;

/*
            Serial.print(points_buff[line_points_index].x);
            Serial.print(" ");
            Serial.print(points_buff[line_points_index].y);
            Serial.println();
*/
            line_points_index++;
          }

          lastX = x;
          lastY = y;
        }
      }

      line_buff_index = 0;
      memset(line_buff, 0, 500);
    }
    else if (c == '(') {
      commentFlag = true;
    } else if (c == ')') {
      commentFlag = false;
    } else if (commentFlag == false) {
      line_buff[line_buff_index++] = c;
    }
  }
}

void gcode_drew_line_file(File myFile, lv_obj_t *objCanvas) {
  float w, h;
  gcode_get_image_size_file(myFile, &w, &h);

  float offsetX = 10.0;
  float offsetY = 10.0;
  
  float scale = 0.0;
  if (w > h) {
    scale = (780.0 - 240.0) / w;
    offsetY = (480.0 / 2.0) - (h * scale / 2.0);
  } else {
    scale = 460.0 / h;
    offsetX = ((800.0 - 240.0) / 2.0) - (w * scale / 2.0);
  }

  static lv_style_t style_line;
  lv_style_copy(&style_line, &lv_style_plain);
  style_line.line.color = lv_color_hex(0x000000);
  style_line.line.width = 1;
  style_line.line.rounded = 0;

  static lv_point_t *points[LINE_BUFFER_SIZE];

  lv_obj_clean(objCanvas);
  /*
  for (int i=0;i<LINE_OBJ_BUFFER_SIZE;i++) {
    if (line[i]) {
      lv_obj_del(line[i]);
      line[i] = 0;
    }
  }*/
  for (int i=0;i<LINE_BUFFER_SIZE;i++) {
    if (points[i]) free(points[i]);
  }

  lv_point_t points_buff[LINE_POINTS_BUFFER_SIZE];

  int points_index = 0;
  int line_points_index = 0;

  char line_buff[500];
  int line_buff_index = 0;
  bool commentFlag = false;
  bool penDownFlag = false;
  float lastX = 0, lastY = 0;
  Serial.println("gcode_drew_line_file...");
  myFile.seek(0);
  while (myFile.available()) {
    char c = myFile.read();
    if (c == '\r') continue;

    if (c == '\n') {
      line_buff[line_buff_index] = 0;

      if (strlen(line_buff) == 0) continue;

      Serial.println(line_buff);

      char cmd;
      int cmdCode;

      sscanf(line_buff, "%c%d", &cmd, &cmdCode);

      if (cmd == 'M') {
        if (cmdCode == 300) {
          float angle = 0;
          sscanf(line_buff, "M300 S%f", &angle);
          if (angle == 50.0) { // pen up
            penDownFlag = false;

            points[points_index] = (lv_point_t*)malloc(sizeof(lv_point_t) * line_points_index);
            for (int index=0;index<line_points_index;index++) {
              points[points_index][index].x = points_buff[index].x;
              points[points_index][index].y = points_buff[index].y;
            }

            memset(points_buff, 0, sizeof(lv_point_t) * LINE_POINTS_BUFFER_SIZE);

            line[points_index] = lv_line_create(objCanvas, NULL);
            lv_line_set_points(line[points_index], points[points_index], line_points_index);
            lv_line_set_style(line[points_index], LV_LINE_STYLE_MAIN, &style_line);
            lv_obj_align(line[points_index], NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

            points_index++;
            line_points_index = 0;
          } else if (angle == 30.0) { // pen down
            penDownFlag = true;

            points_buff[line_points_index].x = lastX;
            points_buff[line_points_index].y = lastY;
            line_points_index++;
          }
        }
      } else if (cmd == 'G') {
        if (cmdCode == 0 || cmdCode == 1) {
          float x = 0.0, y = 0.0;
          sscanf(line_buff, "G%*d X%f Y%f", &x, &y);

          x = offsetX + ((x + (minX < 0 ? abs(minX) : -minX)) * scale);
          y = offsetY + ((h - y - (minY < 0 ? abs(minY) : -minY)) * scale);

          if (penDownFlag) {
            points_buff[line_points_index].x = x;
            points_buff[line_points_index].y = y;

            line_points_index++;
          }

          lastX = x;
          lastY = y;
        }
      }

      line_buff_index = 0;
      memset(line_buff, 0, 500);
    }
    else if (c == '(') {
      commentFlag = true;
    } else if (c == ')') {
      commentFlag = false;
    } else if (commentFlag == false) {
      line_buff[line_buff_index++] = c;
    }
  }
}

void gcode_do_job(char *gcode, bool preview, void (*callback_on_process)()) {
  char line_buff[500];
  int index = 0, line_buff_index = 0;
  bool commentFlag = false;

  while (gcode[index] != 0) {
    char c = gcode[index++];
    if (c == '\r') continue; // Skip \r

    if (c == '\n') {
      line_buff[line_buff_index] = 0;

      if (strlen(line_buff) == 0) continue;
      if (preview && line_buff[0] == 'M') continue; // Skip M command if run preview mode
      
      processIncomingLine(line_buff, line_buff_index);

      line_buff_index = 0;
      memset(line_buff, 0, 500);
    }
    else if (c == '(') {
      commentFlag = true;
    } else if (c == ')') {
      commentFlag = false;
    } else if (commentFlag == false) {
      line_buff[line_buff_index++] = c;
    }
  }
}

void gcode_do_job_file(File myFile, bool preview, bool *cancel, void (*callback_on_process)(int)) {
  myFile.seek(0);

  char line_buff[500];
  int line_buff_index = 0;
  bool commentFlag = false;

  while (myFile.available() && *cancel == false) {
    char c = myFile.read();
    if (c == '\r') continue; // Skip \r

    if (c == '\n') {
      line_buff[line_buff_index] = 0;

      if (strlen(line_buff) == 0) continue;
      if (preview && line_buff[0] == 'M') continue; // Skip M command if run preview mode
      
      if (callback_on_process) callback_on_process((((float)myFile.size() - (float)myFile.available()) / (float)myFile.size()) * 100.0);
      processIncomingLine(line_buff, line_buff_index);

      line_buff_index = 0;
      memset(line_buff, 0, 500);
    }
    else if (c == '(') {
      commentFlag = true;
    } else if (c == ')') {
      commentFlag = false;
    } else if (commentFlag == false) {
      line_buff[line_buff_index++] = c;
    }
  }
}


