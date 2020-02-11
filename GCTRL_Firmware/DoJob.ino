/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_60);
LV_FONT_DECLARE(supermarket_40);

LV_IMG_DECLARE(house_icon);

lv_obj_t* processScreen;
lv_obj_t* txtProgress;
lv_obj_t* progressbar;

lv_obj_t* btnCancel;
lv_obj_t* txtDoing;
lv_obj_t* txtOK;

lv_obj_t* img1;

extern lv_obj_t* homeScreen;

bool cancelFlag = false;

void process_page() {
  processScreen = lv_obj_create(NULL, NULL);
   
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFDFEFE);
  style_screen.body.grad_color = lv_color_hex(0xFDFEFE);
  lv_obj_set_style(processScreen, &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0x1C2833);
  txt1_style.text.font = &supermarket_60;
  
  txtDoing = lv_label_create(processScreen, NULL);
  lv_label_set_style(txtDoing, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txtDoing, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txtDoing, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txtDoing, "กำลังทำงาน...");
  lv_obj_set_size(txtDoing, 0, 0);
  lv_obj_align(txtDoing, NULL, LV_ALIGN_CENTER, 0, -150);
  
  lv_obj_set_hidden(txtDoing, false);
  /* ====== END of txt1 ====== */
  
  /* ========== obj1 ========== */
  static lv_style_t obj1_style;
  lv_obj_t* obj1;
  
  lv_style_copy(&obj1_style, &lv_style_plain);
  obj1_style.body.main_color = lv_color_hex(0xDEDEDE);
  obj1_style.body.grad_color = lv_color_hex(0xDEDEDE);
  obj1_style.body.radius = 0;
  obj1_style.body.opa = 255;
  obj1_style.body.border.color = lv_color_hex(0x000000);
  obj1_style.body.border.width = 0;
  obj1_style.body.border.opa = 255;
  obj1_style.body.shadow.color = lv_color_hex(0x000000);
  obj1_style.body.shadow.width = 0;
  obj1_style.body.shadow.type = LV_SHADOW_FULL;
  
  obj1 = lv_obj_create(processScreen, NULL);
  lv_obj_set_style(obj1, &obj1_style);
  lv_obj_set_size(obj1, 600, 60);
  lv_obj_align(obj1, NULL, LV_ALIGN_IN_LEFT_MID, 100, -20);
  
  lv_obj_set_hidden(obj1, false);
  /* ====== END of obj1 ====== */
  
  /* ========== progressbar ========== */
  static lv_style_t progressbar_style;
  
  lv_style_copy(&progressbar_style, &lv_style_plain);
  progressbar_style.body.main_color = lv_color_hex(0x2ECC71);
  progressbar_style.body.grad_color = lv_color_hex(0x2ECC71);
  progressbar_style.body.radius = 0;
  progressbar_style.body.opa = 255;
  progressbar_style.body.border.color = lv_color_hex(0x000000);
  progressbar_style.body.border.width = 0;
  progressbar_style.body.border.opa = 255;
  progressbar_style.body.shadow.color = lv_color_hex(0x000000);
  progressbar_style.body.shadow.width = 0;
  progressbar_style.body.shadow.type = LV_SHADOW_FULL;
  
  progressbar = lv_obj_create(processScreen, NULL);
  lv_obj_set_style(progressbar, &progressbar_style);
  lv_obj_set_size(progressbar, 0, 60);
  lv_obj_align(progressbar, NULL, LV_ALIGN_IN_LEFT_MID, 100, -20);
  
  lv_obj_set_hidden(progressbar, false);
  /* ====== END of obj2 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_obj_t* txt2;
  
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0x566573);
  txt2_style.text.font = &supermarket_40;
  
  txt2 = lv_label_create(processScreen, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt2, "Move to 200,300");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_CENTER, 0, 50);
  
  lv_obj_set_hidden(txt2, true); // Hide it
  /* ====== END of txt2 ====== */
  
  /* ========== txtProgress ========== */
  static lv_style_t txtProgress_style;
  
  lv_style_copy(&txtProgress_style, &lv_style_plain);
  txtProgress_style.text.color = lv_color_hex(0x186A3B);
  txtProgress_style.text.font = &supermarket_40;
  
  txtProgress = lv_label_create(processScreen, NULL);
  lv_label_set_style(txtProgress, LV_LABEL_STYLE_MAIN, &txtProgress_style);
  lv_label_set_long_mode(txtProgress, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txtProgress, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txtProgress, "0%");
  lv_obj_set_size(txtProgress, 0, 0);
  lv_obj_align(txtProgress, NULL, LV_ALIGN_CENTER, 0, -20);
  
  lv_obj_set_hidden(txtProgress, false);
  /* ====== END of txt3 ====== */
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  static lv_style_t btn1_pr_style;
  
  static lv_style_t btn1_label_style;
  lv_obj_t* btn1_label;
  
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0xE74C3C);
  btn1_rel_style.body.grad_color = lv_color_hex(0xE74C3C);
  btn1_rel_style.body.radius = 6;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x943126);
  btn1_pr_style.body.grad_color = lv_color_hex(0x943126);
  btn1_pr_style.body.radius = 6;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  btnCancel = lv_btn_create(processScreen, NULL);
  lv_obj_set_event_cb(btnCancel, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      gd.beep();
      cancelFlag = true;

      lv_obj_set_size(progressbar, 0, 60);
      lv_label_set_text(txtProgress, "0%");
      lv_obj_set_hidden(txtDoing, false);
      lv_obj_set_hidden(txtOK, true);
      lv_obj_set_hidden(img1, true);
    }
  });
  lv_btn_set_style(btnCancel, LV_BTN_STATE_REL, &btn1_rel_style);
  lv_btn_set_style(btnCancel, LV_BTN_STATE_PR, &btn1_pr_style);
  lv_obj_set_size(btnCancel, 160, 80);
  lv_obj_align(btnCancel, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -30);
  
  lv_style_copy(&btn1_label_style, &lv_style_plain);
  btn1_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn1_label_style.text.font = &supermarket_40;
  btn1_label = lv_label_create(btnCancel, NULL);
  lv_label_set_style(btn1_label, LV_LABEL_STYLE_MAIN, &btn1_label_style);
  lv_label_set_text(btn1_label, "ยกเลิก");
  
  lv_obj_set_hidden(btnCancel, false);
  /* ====== END of btn1 ====== */
  
  /* ========== img1 ========== */
  
  img1 = lv_img_create(processScreen, NULL);
  lv_img_set_src(img1, &house_icon);
  lv_obj_align(img1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
  lv_obj_set_click(img1, true);
  lv_obj_set_event_cb(img1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_load_page(homeScreen);
      gd.beep();

      lv_obj_set_size(progressbar, 0, 60);
      lv_label_set_text(txtProgress, "0%");
      lv_obj_set_hidden(txtDoing, false);
      lv_obj_set_hidden(txtOK, true);
      lv_obj_set_hidden(img1, true);
    }
  });
  
  lv_obj_set_hidden(img1, true);
  /* ====== END of img1 ====== */
  
  /* ========== txt4 ========== */
  static lv_style_t txt4_style;
  
  lv_style_copy(&txt4_style, &lv_style_plain);
  txt4_style.text.color = lv_color_hex(0x1C2833);
  txt4_style.text.font = &supermarket_60;
  
  txtOK = lv_label_create(processScreen, NULL);
  lv_label_set_style(txtOK, LV_LABEL_STYLE_MAIN, &txt4_style);
  lv_label_set_long_mode(txtOK, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txtOK, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txtOK, "ทำงานเสร็จสิ้น");
  lv_obj_set_size(txtOK, 0, 0);
  lv_obj_align(txtOK, NULL, LV_ALIGN_CENTER, 0, -150);
  
  lv_obj_set_hidden(txtOK, true);
  /* ====== END of txt4 ====== */
}
