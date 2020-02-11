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
  Serial.begin(115200);
  delay(100);
  Serial.println("Runing.");

  gd.begin(SETUP_LVGL|SETUP_BUZZER);

  setupStepper();

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
