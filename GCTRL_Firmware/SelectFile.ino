/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_40);
LV_FONT_DECLARE(supermarket_20);

lv_obj_t* selectFileScreen;
lv_obj_t *pageFolderFileList;

extern lv_obj_t* homeScreen;

LV_IMG_DECLARE(file_icon);
LV_IMG_DECLARE(folder_icon);
LV_IMG_DECLARE(house_icon);
LV_IMG_DECLARE(house_mini_icon);

void select_file_page() {
  selectFileScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFBFCFC);
  style_screen.body.grad_color = lv_color_hex(0xFBFCFC);
  lv_obj_set_style(selectFileScreen, &style_screen);

  /* ========== txt5 ========== */
  static lv_style_t txt5_style;
  lv_obj_t* txt5;
  
  lv_style_copy(&txt5_style, &lv_style_plain);
  txt5_style.text.color = lv_color_hex(0x1C2833);
  txt5_style.text.font = &supermarket_40;
  
  txt5 = lv_label_create(selectFileScreen, NULL);
  lv_label_set_style(txt5, LV_LABEL_STYLE_MAIN, &txt5_style);
  lv_label_set_long_mode(txt5, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt5, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt5, "เลือกไฟล์ G Code");
  lv_obj_set_size(txt5, 0, 0);
  lv_obj_align(txt5, NULL, LV_ALIGN_IN_TOP_LEFT, 40, 10);
  
  lv_obj_set_hidden(txt5, false);
  /* ====== END of txt5 ====== */
  
  /* ========== img4 ========== */
  lv_obj_t* img4;
  
  img4 = lv_img_create(selectFileScreen, NULL);
  lv_img_set_src(img4, &house_mini_icon);
  lv_obj_align(img4, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
  lv_obj_set_click(img4, true);
  lv_obj_set_event_cb(img4, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_load_page(homeScreen);
      gd.beep();
    }
  });
  
  lv_obj_set_hidden(img4, false);
  /* ====== END of img4 ====== */
  
  /* ========== obj1 ========== */
  static lv_style_t obj1_style;
  lv_obj_t* obj1;
  
  lv_style_copy(&obj1_style, &lv_style_plain);
  obj1_style.body.main_color = lv_color_hex(0xABB2B9);
  obj1_style.body.grad_color = lv_color_hex(0xABB2B9);
  obj1_style.body.radius = 0;
  obj1_style.body.opa = 255;
  obj1_style.body.border.color = lv_color_hex(0x000000);
  obj1_style.body.border.width = 0;
  obj1_style.body.border.opa = 255;
  obj1_style.body.shadow.color = lv_color_hex(0x000000);
  obj1_style.body.shadow.width = 0;
  obj1_style.body.shadow.type = LV_SHADOW_FULL;
  
  obj1 = lv_obj_create(selectFileScreen, NULL);
  lv_obj_set_style(obj1, &obj1_style);
  lv_obj_set_size(obj1, 800, 2);
  lv_obj_align(obj1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 80);
  
  lv_obj_set_hidden(obj1, false);
  /* ====== END of obj1 ====== */

  static lv_style_t style_page;
  lv_style_copy(&style_page, &lv_style_scr);
  style_page.body.main_color = lv_color_hex(0xFFFFFF);
  style_page.body.grad_color = lv_color_hex(0xFFFFFF);
  style_page.body.border.width = 0;
  style_page.body.radius = 0;
  style_page.body.padding.top = 0;
  style_page.body.padding.left = 0;
  style_page.body.padding.right = 0;
  style_page.body.padding.bottom = 0;
  style_page.body.padding.inner = 8;

  /* Create a scroll bar style */
  static lv_style_t style_sb;
  lv_style_copy(&style_sb, &lv_style_plain);
  style_sb.body.main_color = lv_color_hex(0x2ECC71);
  style_sb.body.grad_color = lv_color_hex(0x2ECC71);
  style_sb.body.border.width = 0;
  style_sb.body.radius = LV_RADIUS_CIRCLE;
  style_sb.body.padding.right = 3;
  style_sb.body.padding.bottom = 3;
  style_sb.body.padding.inner = 8;

  /* Create a page */
  pageFolderFileList = lv_page_create(selectFileScreen, NULL);
  lv_obj_set_size(pageFolderFileList, 800, 400 - 3);
  lv_obj_align(pageFolderFileList, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 80 + 3);
  lv_page_set_style(pageFolderFileList, LV_PAGE_STYLE_BG, &style_page);
  lv_page_set_style(pageFolderFileList, LV_PAGE_STYLE_SB, &style_sb);
  lv_page_set_style(pageFolderFileList, LV_PAGE_STYLE_SCRL, &style_page);
}

lv_obj_t* objImgFileFolderList[100];
lv_obj_t* objLabelFileFolderList[100];
String objFileFolderListName[100];
int objFileFolderListCount = 0;

String nowPath;

int findObjectImgIndex(lv_obj_t* obj) {
  for(int i=0;i<100;i++) {
    if (obj == objImgFileFolderList[i]) return i;
  }

  return -1;
}

void file_cb(lv_obj_t* obj, lv_event_t event) {
  if(event == LV_EVENT_CLICKED) {
    int index = findObjectImgIndex(obj);
    if (index == -1) return; // some thing wrong

    String filePath = nowPath + (nowPath.endsWith("/") ? "" : "/") + objFileFolderListName[index];
    lv_load_page(previewScreen);
  }
}

void folder_cb(lv_obj_t* obj, lv_event_t event) {
  if(event == LV_EVENT_CLICKED) {
    int index = findObjectImgIndex(obj);
    if (index == -1) return; // some thing wrong

    updateListFileFolder(objFileFolderListName[index]);
  }
}

void updateListFileFolder(String cd) {
  nowPath += (nowPath.endsWith("/") ? "" : "/") + cd;
  
  File dir = SD.open(nowPath);

  for (int i=0;i<objFileFolderListCount;i++) {
    lv_obj_del(objImgFileFolderList[i]);
    lv_obj_del(objLabelFileFolderList[i]);
    objFileFolderListName[i] = "";
  }

  static lv_style_t txt_file_folder_name_style;
  lv_style_copy(&txt_file_folder_name_style, &lv_style_plain);
  txt_file_folder_name_style.text.color = lv_color_hex(0x1C2833);
  txt_file_folder_name_style.text.font = &supermarket_20;

  int i = 0;
  while(1) {
    File entry = dir.openNextFile();
    if (!entry) break;
    if (!entry.isDirectory()) {
      if (!String(entry.name()).endsWith(".gcode")) continue;
    }

    objImgFileFolderList[i] = lv_img_create(pageFolderFileList, NULL);
    lv_img_set_src(objImgFileFolderList[i], entry.isDirectory() ? &folder_icon : &file_icon);
    lv_obj_align(objImgFileFolderList[i], NULL, LV_ALIGN_IN_TOP_LEFT, 60 + ((i % 4) * 180), 30 + ((i / 4) * 180));
    lv_obj_set_event_cb(objImgFileFolderList[i], entry.isDirectory() ? folder_cb : file_cb);

    objLabelFileFolderList[i] = lv_label_create(pageFolderFileList, NULL);
    lv_label_set_style(objLabelFileFolderList[i], LV_LABEL_STYLE_MAIN, &txt_file_folder_name_style);
    lv_label_set_long_mode(objLabelFileFolderList[i], LV_LABEL_LONG_SROLL_CIRC);
    lv_label_set_align(objLabelFileFolderList[i], LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(objLabelFileFolderList[i], entry.name());
    lv_obj_set_size(objLabelFileFolderList[i], 128, 40);
    lv_obj_align(objLabelFileFolderList[i], NULL, LV_ALIGN_IN_TOP_LEFT, 60 + ((i % 4) * 180), 160 + ((i / 4) * 180));
    lv_obj_set_event_cb(objLabelFileFolderList[i], entry.isDirectory() ? folder_cb : file_cb);

    objFileFolderListName[i] = entry.name();

    entry.close();

    i++;
  }

  objFileFolderListCount = i;
}
