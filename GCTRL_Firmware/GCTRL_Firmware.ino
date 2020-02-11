#include <SPI.h>
#include <SD.h>
#include <IOXGD.h>

extern lv_obj_t* welcomeScreen;
extern lv_obj_t* homeScreen;
extern lv_obj_t* previewScreen;
extern lv_obj_t* selectFileScreen;

extern lv_obj_t* objCanvas;

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
        char *fileContentBuff = (char*)malloc(myFile.size() + 1);
        memset(fileContentBuff, 0, myFile.size() + 1);

        uint32_t inx = 0;
        while (myFile.available()) {
          fileContentBuff[inx++] = myFile.read();
        }

        gcode_drew_line(fileContentBuff, objCanvas);

        free(fileContentBuff);
        myFile.close();
      }
    }
  }

  vTaskDelay(10 / portTICK_PERIOD_MS);
}
