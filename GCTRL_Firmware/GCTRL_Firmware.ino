#include <SPI.h>
#include <SD.h>
#include <IOXGD.h>

extern lv_obj_t* welcomeScreen;
extern lv_obj_t* homeScreen;
extern lv_obj_t* previewScreen;
extern lv_obj_t* selectFileScreen;
extern lv_obj_t* processScreen;

extern lv_obj_t* objCanvas;
extern lv_obj_t* txtProgress;
extern lv_obj_t* progressbar;

extern bool previewFlag;
extern bool cancelFlag;

extern lv_obj_t* btnCancel;
extern lv_obj_t* txtDoing;
extern lv_obj_t* txtOK;
extern lv_obj_t* img1;

extern String filePath;

bool sdcardMounted = false;
lv_obj_t* showPage = welcomeScreen; // Show welcome page fist

void setupSDCard() {
  sdcardMounted = SD.begin(29);
}

bool pageDidMount = false;

void lv_load_page(lv_obj_t* page) {
  lv_scr_load(page);
  showPage = page;
  pageDidMount = false;
}

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("Runing.");

  gd.begin(SETUP_LVGL|SETUP_BUZZER);

  setupStepper();
  penUp();

  welcome_page();
  home_page();
  
  control_page();
  
  select_file_page();
  preview_page();
  process_page();

  xTaskCreateAtProcessor(0, [](void*) {
    setupSDCard();
    ESP32.begin();

    lv_load_page(homeScreen);
    while (1) {
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }, "mainTask", 256, NULL, 1, NULL);

  xTaskCreateAtProcessor(0, [](void*) {
    char line[100];
    int lineIndex = 0;
    bool lineIsComment = false, lineSemiColon = false;
    while(1) {
      while(Serial.available() > 0) {
        char c = Serial.read();
        if ((c == '\n') || (c == '\r')) {             // End of line reached
          if (lineIndex > 0) {                        // Line is complete. Then execute!
            line[ lineIndex ] = '\0';                   // Terminate string

            processIncomingLine( line, lineIndex );
            lineIndex = 0;
          }
          lineIsComment = false;
          lineSemiColon = false;
          Serial.println("ok");
        } else {
          if ((lineIsComment) || (lineSemiColon)) {   // Throw away all comment characters
            if (c == ')')  lineIsComment = false;     // End of comment. Resume line.
          } else {
            if (c <= ' ') {                           // Throw away whitepace and control characters
            } else if (c == '/') {                    // Block delete not supported. Ignore character.
            } else if (c == '(') {                    // Enable comments flag and ignore all characters until ')' or EOL.
              lineIsComment = true;
            } else if (c == ';') {
              lineSemiColon = true;
            } else if (lineIndex >= sizeof(line) - 1) {
              Serial.println( "ERROR - lineBuffer overflow" );
              lineIsComment = false;
              lineSemiColon = false;
            } else if (c >= 'a' && c <= 'z') {        // Upcase lowercase
              line[lineIndex++] = c - 'a' + 'A';
            } else {
              line[lineIndex++] = c;
            }
          }
        }
      }
      vTaskDelay(1 / portTICK_PERIOD_MS);
    }
  }, "serialTask", 256, NULL, 1, NULL);

  xTaskCreateAtProcessor(0, [](void*) {
    while (1) {
      loop();
    }
  }, "loopTask", 1024, NULL, 1, NULL);

  lv_load_page(welcomeScreen);
  
  gd.startFreeRTOS();
}

void loop() {
  if (showPage == selectFileScreen) {
    if (!pageDidMount) {
      if (!sdcardMounted) {
        setupSDCard();
      }

      if (sdcardMounted) {
        updateListFileFolder("");
      }

      pageDidMount = true;
    }
  }
  if (showPage == previewScreen) {
    if (!pageDidMount) {
      File myFile = SD.open(filePath);
      if (myFile) {
        gcode_drew_line_file(myFile, objCanvas);
        myFile.close();
      }

      pageDidMount = true;
    }
  }
  if (showPage == processScreen) {
    if (!pageDidMount) {
      lv_obj_set_hidden(btnCancel, false);
      lv_obj_set_hidden(txtDoing, false);
      lv_obj_set_hidden(img1, true);
      lv_obj_set_hidden(txtOK, true);

      File myFile = SD.open(filePath);
      if (myFile) {
        gcode_do_job_file(myFile, previewFlag, &cancelFlag, [](int progress) {
          Serial.print(progress);
          Serial.println('%');
          lv_label_set_text(txtProgress, String(String(progress) + "%").c_str());
          lv_obj_set_size(progressbar, (progress / 100.0) * 600.0, 60);
        });
        myFile.close();
      }

      if (cancelFlag) {
        lv_load_page(previewScreen);
        cancelFlag = false;
      } else {
        lv_obj_set_hidden(btnCancel, true);
        lv_obj_set_hidden(txtDoing, true);
        lv_obj_set_hidden(img1, false);
        lv_obj_set_hidden(txtOK, false);
      }

      pageDidMount = true;
    }
  }

  vTaskDelay(10 / portTICK_PERIOD_MS);
}
