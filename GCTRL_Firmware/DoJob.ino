/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_60);
LV_FONT_DECLARE(supermarket_40);

lv_obj_t* processScreen;

extern lv_obj_t* homeScreen;

void process_page() {
  processScreen = lv_obj_create(NULL, NULL);
   
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFDFEFE);
  style_screen.body.grad_color = lv_color_hex(0xFDFEFE);
  lv_obj_set_style(processScreen, &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_obj_t* txt1;
  
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0x1C2833);
  txt1_style.text.font = &supermarket_60;
  
  txt1 = lv_label_create(processScreen, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "กำลังทำงาน...");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_CENTER, 0, -150);
  
  lv_obj_set_hidden(txt1, false);
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
  
  /* ========== obj2 ========== */
  static lv_style_t obj2_style;
  lv_obj_t* obj2;
  
  lv_style_copy(&obj2_style, &lv_style_plain);
  obj2_style.body.main_color = lv_color_hex(0x2ECC71);
  obj2_style.body.grad_color = lv_color_hex(0x2ECC71);
  obj2_style.body.radius = 0;
  obj2_style.body.opa = 255;
  obj2_style.body.border.color = lv_color_hex(0x000000);
  obj2_style.body.border.width = 0;
  obj2_style.body.border.opa = 255;
  obj2_style.body.shadow.color = lv_color_hex(0x000000);
  obj2_style.body.shadow.width = 0;
  obj2_style.body.shadow.type = LV_SHADOW_FULL;
  
  obj2 = lv_obj_create(processScreen, NULL);
  lv_obj_set_style(obj2, &obj2_style);
  lv_obj_set_size(obj2, 300, 60);
  lv_obj_align(obj2, NULL, LV_ALIGN_IN_LEFT_MID, 100, -20);
  
  lv_obj_set_hidden(obj2, false);
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
  
  lv_obj_set_hidden(txt2, false);
  /* ====== END of txt2 ====== */
  
  /* ========== txt3 ========== */
  static lv_style_t txt3_style;
  lv_obj_t* txt3;
  
  lv_style_copy(&txt3_style, &lv_style_plain);
  txt3_style.text.color = lv_color_hex(0x186A3B);
  txt3_style.text.font = &supermarket_40;
  
  txt3 = lv_label_create(processScreen, NULL);
  lv_label_set_style(txt3, LV_LABEL_STYLE_MAIN, &txt3_style);
  lv_label_set_long_mode(txt3, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt3, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt3, "50%");
  lv_obj_set_size(txt3, 0, 0);
  lv_obj_align(txt3, NULL, LV_ALIGN_CENTER, 0, -20);
  
  lv_obj_set_hidden(txt3, false);
  /* ====== END of txt3 ====== */
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  static lv_style_t btn1_pr_style;
  lv_obj_t* btn1;
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
  
  btn1 = lv_btn_create(processScreen, NULL);
  // lv_obj_set_event_cb(btn1, event_handler); // TODO
  lv_btn_set_style(btn1, LV_BTN_STATE_REL, &btn1_rel_style);
  lv_btn_set_style(btn1, LV_BTN_STATE_PR, &btn1_pr_style);
  lv_obj_set_size(btn1, 160, 80);
  lv_obj_align(btn1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -30);
  
  lv_style_copy(&btn1_label_style, &lv_style_plain);
  btn1_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn1_label_style.text.font = &supermarket_40;
  btn1_label = lv_label_create(btn1, NULL);
  lv_label_set_style(btn1_label, LV_LABEL_STYLE_MAIN, &btn1_label_style);
  lv_label_set_text(btn1_label, "ยกเลิก");
  
  lv_obj_set_hidden(btn1, false);
  /* ====== END of btn1 ====== */
  
  /* ========== img1 ========== */
  lv_obj_t* img1;
  
  img1 = lv_img_create(processScreen, NULL);
  // lv_img_set_src(img1, "D:\GitHub\GCTRL-Firmware\icon\house.png"); // TODO
  lv_obj_align(img1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
  
  lv_obj_set_hidden(img1, true);
  /* ====== END of img1 ====== */
  
  /* ========== txt4 ========== */
  static lv_style_t txt4_style;
  lv_obj_t* txt4;
  
  lv_style_copy(&txt4_style, &lv_style_plain);
  txt4_style.text.color = lv_color_hex(0x1C2833);
  txt4_style.text.font = &supermarket_60;
  
  txt4 = lv_label_create(processScreen, NULL);
  lv_label_set_style(txt4, LV_LABEL_STYLE_MAIN, &txt4_style);
  lv_label_set_long_mode(txt4, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt4, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt4, "ทำงานเสร็จสิ้น");
  lv_obj_set_size(txt4, 0, 0);
  lv_obj_align(txt4, NULL, LV_ALIGN_CENTER, 0, -150);
  
  lv_obj_set_hidden(txt4, true);
  /* ====== END of txt4 ====== */
}
