/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_40);

lv_obj_t* homeScreen;

extern lv_obj_t* selectFileScreen;
extern lv_obj_t* controlScreen;

LV_IMG_DECLARE(joy_icon);
LV_IMG_DECLARE(sd_card_icon);

void home_page() {
  homeScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFDFEFE);
  style_screen.body.grad_color = lv_color_hex(0xFDFEFE);
  lv_obj_set_style(homeScreen, &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_obj_t* txt1;
  
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0xD35400);
  txt1_style.text.font = &supermarket_40;
  
  txt1 = lv_label_create(homeScreen, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt1, "Load from SD Card");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_BOTTOM_MID, 210, -50);
  
  lv_obj_set_hidden(txt1, false);
  /* ====== END of txt1 ====== */
  
  /* ========== img1 ========== */
  lv_obj_t* img1;
  
  img1 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img1, &sd_card_icon);
  lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_MID, 210, 110);
  lv_obj_set_click(img1, true);
  lv_obj_set_event_cb(img1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_load_page(selectFileScreen);
      gd.beep();
    }
  });
  
  lv_obj_set_hidden(img1, false);
  /* ====== END of img1 ====== */
  
  /* ========== img2 ========== */
  lv_obj_t* img2;

  img2 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img2, &joy_icon);
  lv_obj_align(img2, NULL, LV_ALIGN_IN_TOP_MID, -210, 110);
  lv_obj_set_click(img2, true);
  lv_obj_set_event_cb(img2, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_load_page(controlScreen);
      gd.beep();
    }
  });
  
  lv_obj_set_hidden(img2, false);
  /* ====== END of img2 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_obj_t* txt2;
  
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0x2E86C1);
  txt2_style.text.font = &supermarket_40;
  
  txt2 = lv_label_create(homeScreen, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt2, "Move");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_BOTTOM_MID, -210, -50);
  
  lv_obj_set_hidden(txt2, false);
  /* ====== END of txt2 ====== */
}
