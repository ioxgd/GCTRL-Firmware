/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_40);
LV_FONT_DECLARE(supermarket_60);

lv_obj_t* controlScreen;

extern lv_obj_t* homeScreen;

LV_IMG_DECLARE(house_icon);
LV_IMG_DECLARE(house_mini_icon);

void control_page() {
  controlScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFDFEFE);
  style_screen.body.grad_color = lv_color_hex(0xFDFEFE);
  lv_obj_set_style(controlScreen, &style_screen);
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  static lv_style_t btn1_pr_style;
  lv_obj_t* btn1;
  static lv_style_t btn1_label_style;
  lv_obj_t* btn1_label;
  
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0xF1C40F);
  btn1_rel_style.body.grad_color = lv_color_hex(0xF1C40F);
  btn1_rel_style.body.radius = 6;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x9A7D0A);
  btn1_pr_style.body.grad_color = lv_color_hex(0x9A7D0A);
  btn1_pr_style.body.radius = 6;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  btn1 = lv_btn_create(controlScreen, NULL);
  lv_obj_set_event_cb(btn1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn1, LV_BTN_STATE_REL, &btn1_rel_style);
  lv_btn_set_style(btn1, LV_BTN_STATE_PR, &btn1_pr_style);
  lv_obj_set_size(btn1, 120, 120);
  lv_obj_align(btn1, NULL, LV_ALIGN_IN_TOP_LEFT, 160, 50);
  
  lv_style_copy(&btn1_label_style, &lv_style_plain);
  btn1_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn1_label_style.text.font = &supermarket_60;
  btn1_label = lv_label_create(btn1, NULL);
  lv_label_set_style(btn1_label, LV_LABEL_STYLE_MAIN, &btn1_label_style);
  lv_label_set_text(btn1_label, "+X");
  
  lv_obj_set_hidden(btn1, false);
  /* ====== END of btn1 ====== */
  
  /* ========== btn2 ========== */
  static lv_style_t btn2_rel_style;
  static lv_style_t btn2_pr_style;
  lv_obj_t* btn2;
  static lv_style_t btn2_label_style;
  lv_obj_t* btn2_label;
  
  lv_style_copy(&btn2_rel_style, &lv_style_plain);
  btn2_rel_style.body.main_color = lv_color_hex(0xF1C40F);
  btn2_rel_style.body.grad_color = lv_color_hex(0xF1C40F);
  btn2_rel_style.body.radius = 6;
  btn2_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn2_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn2_pr_style, &lv_style_plain);
  btn2_pr_style.body.main_color = lv_color_hex(0x9A7D0A);
  btn2_pr_style.body.grad_color = lv_color_hex(0x9A7D0A);
  btn2_pr_style.body.radius = 6;
  btn2_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn2_pr_style.body.border.width = 0;
  
  btn2 = lv_btn_create(controlScreen, NULL);
  lv_obj_set_event_cb(btn2, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn2, LV_BTN_STATE_REL, &btn2_rel_style);
  lv_btn_set_style(btn2, LV_BTN_STATE_PR, &btn2_pr_style);
  lv_obj_set_size(btn2, 120, 120);
  lv_obj_align(btn2, NULL, LV_ALIGN_IN_TOP_LEFT, 160, 310);
  
  lv_style_copy(&btn2_label_style, &lv_style_plain);
  btn2_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn2_label_style.text.font = &supermarket_60;
  btn2_label = lv_label_create(btn2, NULL);
  lv_label_set_style(btn2_label, LV_LABEL_STYLE_MAIN, &btn2_label_style);
  lv_label_set_text(btn2_label, "-X");
  
  lv_obj_set_hidden(btn2, false);
  /* ====== END of btn2 ====== */
  
  /* ========== btn3 ========== */
  static lv_style_t btn3_rel_style;
  static lv_style_t btn3_pr_style;
  lv_obj_t* btn3;
  static lv_style_t btn3_label_style;
  lv_obj_t* btn3_label;
  
  lv_style_copy(&btn3_rel_style, &lv_style_plain);
  btn3_rel_style.body.main_color = lv_color_hex(0x8E44AD);
  btn3_rel_style.body.grad_color = lv_color_hex(0x8E44AD);
  btn3_rel_style.body.radius = 6;
  btn3_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn3_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn3_pr_style, &lv_style_plain);
  btn3_pr_style.body.main_color = lv_color_hex(0x5B2C6F);
  btn3_pr_style.body.grad_color = lv_color_hex(0x5B2C6F);
  btn3_pr_style.body.radius = 6;
  btn3_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn3_pr_style.body.border.width = 0;
  
  btn3 = lv_btn_create(controlScreen, NULL);
  lv_obj_set_event_cb(btn3, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn3, LV_BTN_STATE_REL, &btn3_rel_style);
  lv_btn_set_style(btn3, LV_BTN_STATE_PR, &btn3_pr_style);
  lv_obj_set_size(btn3, 120, 120);
  lv_obj_align(btn3, NULL, LV_ALIGN_IN_TOP_LEFT, 30, 180);
  
  lv_style_copy(&btn3_label_style, &lv_style_plain);
  btn3_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn3_label_style.text.font = &supermarket_60;
  btn3_label = lv_label_create(btn3, NULL);
  lv_label_set_style(btn3_label, LV_LABEL_STYLE_MAIN, &btn3_label_style);
  lv_label_set_text(btn3_label, "+Y");
  
  lv_obj_set_hidden(btn3, false);
  /* ====== END of btn3 ====== */
  
  /* ========== btn4 ========== */
  static lv_style_t btn4_rel_style;
  static lv_style_t btn4_pr_style;
  lv_obj_t* btn4;
  static lv_style_t btn4_label_style;
  lv_obj_t* btn4_label;
  
  lv_style_copy(&btn4_rel_style, &lv_style_plain);
  btn4_rel_style.body.main_color = lv_color_hex(0x8E44AD);
  btn4_rel_style.body.grad_color = lv_color_hex(0x8E44AD);
  btn4_rel_style.body.radius = 6;
  btn4_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn4_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn4_pr_style, &lv_style_plain);
  btn4_pr_style.body.main_color = lv_color_hex(0x5B2C6F);
  btn4_pr_style.body.grad_color = lv_color_hex(0x5B2C6F);
  btn4_pr_style.body.radius = 6;
  btn4_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn4_pr_style.body.border.width = 0;
  
  btn4 = lv_btn_create(controlScreen, NULL);
  lv_obj_set_event_cb(btn4, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn4, LV_BTN_STATE_REL, &btn4_rel_style);
  lv_btn_set_style(btn4, LV_BTN_STATE_PR, &btn4_pr_style);
  lv_obj_set_size(btn4, 120, 120);
  lv_obj_align(btn4, NULL, LV_ALIGN_IN_TOP_LEFT, 290, 180);
  
  lv_style_copy(&btn4_label_style, &lv_style_plain);
  btn4_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn4_label_style.text.font = &supermarket_60;
  btn4_label = lv_label_create(btn4, NULL);
  lv_label_set_style(btn4_label, LV_LABEL_STYLE_MAIN, &btn4_label_style);
  lv_label_set_text(btn4_label, "-Y");
  
  lv_obj_set_hidden(btn4, false);
  /* ====== END of btn4 ====== */
  
  /* ========== btn5 ========== */
  static lv_style_t btn5_rel_style;
  static lv_style_t btn5_pr_style;
  lv_obj_t* btn5;
  static lv_style_t btn5_label_style;
  lv_obj_t* btn5_label;
  
  lv_style_copy(&btn5_rel_style, &lv_style_plain);
  btn5_rel_style.body.main_color = lv_color_hex(0x2E86C1);
  btn5_rel_style.body.grad_color = lv_color_hex(0x2E86C1);
  btn5_rel_style.body.radius = 6;
  btn5_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn5_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn5_pr_style, &lv_style_plain);
  btn5_pr_style.body.main_color = lv_color_hex(0x21618C);
  btn5_pr_style.body.grad_color = lv_color_hex(0x21618C);
  btn5_pr_style.body.radius = 6;
  btn5_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn5_pr_style.body.border.width = 0;
  
  btn5 = lv_btn_create(controlScreen, NULL);
  lv_obj_set_event_cb(btn5, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn5, LV_BTN_STATE_REL, &btn5_rel_style);
  lv_btn_set_style(btn5, LV_BTN_STATE_PR, &btn5_pr_style);
  lv_obj_set_size(btn5, 300, 100);
  lv_obj_align(btn5, NULL, LV_ALIGN_IN_TOP_RIGHT, -30, 50);
  
  lv_style_copy(&btn5_label_style, &lv_style_plain);
  btn5_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn5_label_style.text.font = &supermarket_60;
  btn5_label = lv_label_create(btn5, NULL);
  lv_label_set_style(btn5_label, LV_LABEL_STYLE_MAIN, &btn5_label_style);
  lv_label_set_text(btn5_label, "Pen Up");
  
  lv_obj_set_hidden(btn5, false);
  /* ====== END of btn5 ====== */
  
  /* ========== btn6 ========== */
  static lv_style_t btn6_rel_style;
  static lv_style_t btn6_pr_style;
  lv_obj_t* btn6;
  static lv_style_t btn6_label_style;
  lv_obj_t* btn6_label;
  
  lv_style_copy(&btn6_rel_style, &lv_style_plain);
  btn6_rel_style.body.main_color = lv_color_hex(0x2E86C1);
  btn6_rel_style.body.grad_color = lv_color_hex(0x2E86C1);
  btn6_rel_style.body.radius = 6;
  btn6_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn6_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn6_pr_style, &lv_style_plain);
  btn6_pr_style.body.main_color = lv_color_hex(0x21618C);
  btn6_pr_style.body.grad_color = lv_color_hex(0x21618C);
  btn6_pr_style.body.radius = 6;
  btn6_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn6_pr_style.body.border.width = 0;
  
  btn6 = lv_btn_create(controlScreen, NULL);
  lv_obj_set_event_cb(btn6, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn6, LV_BTN_STATE_REL, &btn6_rel_style);
  lv_btn_set_style(btn6, LV_BTN_STATE_PR, &btn6_pr_style);
  lv_obj_set_size(btn6, 300, 100);
  lv_obj_align(btn6, NULL, LV_ALIGN_IN_TOP_RIGHT, -30, 170);
  
  lv_style_copy(&btn6_label_style, &lv_style_plain);
  btn6_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn6_label_style.text.font = &supermarket_60;
  btn6_label = lv_label_create(btn6, NULL);
  lv_label_set_style(btn6_label, LV_LABEL_STYLE_MAIN, &btn6_label_style);
  lv_label_set_text(btn6_label, "Pen Down");
  
  lv_obj_set_hidden(btn6, false);
  /* ====== END of btn6 ====== */
  
  /* ========== obj1 ========== */
  static lv_style_t obj1_style;
  lv_obj_t* obj1;
  
  lv_style_copy(&obj1_style, &lv_style_plain);
  obj1_style.body.main_color = lv_color_hex(0xEAECEE);
  obj1_style.body.grad_color = lv_color_hex(0xEAECEE);
  obj1_style.body.radius = 150;
  obj1_style.body.opa = 255;
  obj1_style.body.border.color = lv_color_hex(0x000000);
  obj1_style.body.border.width = 0;
  obj1_style.body.border.opa = 255;
  obj1_style.body.shadow.color = lv_color_hex(0x000000);
  obj1_style.body.shadow.width = 0;
  obj1_style.body.shadow.type = LV_SHADOW_FULL;
  
  obj1 = lv_obj_create(controlScreen, NULL);
  lv_obj_set_style(obj1, &obj1_style);
  lv_obj_set_size(obj1, 300, 300);
  lv_obj_align(obj1, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 110, 140);
  
  lv_obj_set_hidden(obj1, false);
  /* ====== END of obj1 ====== */
  
  /* ========== img1 ========== */
  lv_obj_t* img1;
  
  img1 = lv_img_create(controlScreen, NULL);
  lv_img_set_src(img1, &house_icon);
  lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 660, 340);
  lv_obj_set_click(img1, true);
  lv_obj_set_event_cb(img1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_load_page(homeScreen);
      gd.beep();
    }
  });
  
  lv_obj_set_hidden(img1, false);
  /* ====== END of img1 ====== */
}
