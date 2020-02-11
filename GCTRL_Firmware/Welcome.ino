/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_60);
LV_FONT_DECLARE(supermarket_20);

lv_obj_t* welcomeScreen;

LV_IMG_DECLARE(book_icon);

void welcome_page() {
  welcomeScreen = lv_obj_create(NULL, NULL);

  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFDFEFE);
  style_screen.body.grad_color = lv_color_hex(0xFDFEFE);
  lv_obj_set_style(welcomeScreen, &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_obj_t* txt1;
  
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0x1C2833);
  txt1_style.text.font = &supermarket_60;
  
  txt1 = lv_label_create(welcomeScreen, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "GCTRL Firmware");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);
  
  lv_obj_set_hidden(txt1, false);
  /* ====== END of txt1 ====== */
  
  /* ========== img1 ========== */
  lv_obj_t* img1;
  
  img1 = lv_img_create(welcomeScreen, NULL);
  lv_img_set_src(img1, &book_icon);
  lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, -30);
  
  lv_obj_set_hidden(img1, false);
  /* ====== END of img1 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_obj_t* txt2;
  
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0x566573);
  txt2_style.text.font = &supermarket_20;
  
  txt2 = lv_label_create(welcomeScreen, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "พัฒนาโดย สนธยา นงนุช ชมรมหุ่นยนต์ (ETRC) วิทยาลัยเทคโนโลยีภาคตะวันออก(อี.เทค)");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
  
  lv_obj_set_hidden(txt2, false);
  /* ====== END of txt2 ====== */

  static lv_style_t preload_style;
  lv_style_copy(&preload_style, &lv_style_plain);
  preload_style.line.width = 10;
  preload_style.line.color = lv_color_hex(0xF1C40F);

  preload_style.body.border.color = lv_color_hex(0xD5D8DC);
  preload_style.body.border.width = 10;
  preload_style.body.padding.left = 0;

  lv_obj_t *preload = lv_preload_create(welcomeScreen, NULL);
  lv_obj_set_size(preload, 100, 100);
  lv_obj_align(preload, NULL, LV_ALIGN_CENTER, 0, 110);
  lv_preload_set_style(preload, LV_PRELOAD_STYLE_MAIN, &preload_style);
}
