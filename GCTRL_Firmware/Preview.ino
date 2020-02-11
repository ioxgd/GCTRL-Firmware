/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_40);
LV_FONT_DECLARE(supermarket_60);

lv_obj_t* previewScreen;

extern lv_obj_t* homeScreen;

lv_obj_t* objCanvas;

LV_IMG_DECLARE(house_icon);
LV_IMG_DECLARE(house_mini_icon);

extern void gcode_drew_line(char *gcode, lv_obj_t *objCanvas, float scale, float offsetX, float offsetY);
extern char test_gcode[];

void preview_page() {
  previewScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFFFFFF);
  style_screen.body.grad_color = lv_color_hex(0xFFFFFF);
  lv_obj_set_style(previewScreen, &style_screen);
  
  /* ========== obj1 ========== */
  static lv_style_t obj1_style;
  lv_obj_t* obj1;
  
  lv_style_copy(&obj1_style, &lv_style_plain);
  obj1_style.body.main_color = lv_color_hex(0xEAECEE);
  obj1_style.body.grad_color = lv_color_hex(0xEAECEE);
  obj1_style.body.radius = 0;
  obj1_style.body.opa = 255;
  obj1_style.body.border.color = lv_color_hex(0x000000);
  obj1_style.body.border.width = 0;
  obj1_style.body.border.opa = 255;
  obj1_style.body.shadow.color = lv_color_hex(0x909090);
  obj1_style.body.shadow.width = 0;
  obj1_style.body.shadow.type = LV_SHADOW_FULL;
  
  obj1 = lv_obj_create(previewScreen, NULL);
  lv_obj_set_style(obj1, &obj1_style);
  lv_obj_set_size(obj1, 240, 480);
  lv_obj_align(obj1, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 0);
  
  lv_obj_set_hidden(obj1, false);
  /* ====== END of obj1 ====== */
  
  /* ========== img1 ========== */
  lv_obj_t* img1;
  
  img1 = lv_img_create(previewScreen, NULL);
  lv_img_set_src(img1, &house_icon);
  lv_obj_align(img1, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -55, -30);
  lv_obj_set_click(img1, true);
  lv_obj_set_event_cb(img1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_load_page(homeScreen);
      gd.beep();
    }
  });
  
  lv_obj_set_hidden(img1, false);
  /* ====== END of img1 ====== */
  
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
  btn1_pr_style.body.main_color = lv_color_hex(0xB7950B);
  btn1_pr_style.body.grad_color = lv_color_hex(0xB7950B);
  btn1_pr_style.body.radius = 6;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  btn1 = lv_btn_create(previewScreen, NULL);
  lv_obj_set_event_cb(btn1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn1, LV_BTN_STATE_REL, &btn1_rel_style);
  lv_btn_set_style(btn1, LV_BTN_STATE_PR, &btn1_pr_style);
  lv_obj_set_size(btn1, 200, 60);
  lv_obj_align(btn1, NULL, LV_ALIGN_IN_TOP_RIGHT, -20, 30);
  
  lv_style_copy(&btn1_label_style, &lv_style_plain);
  btn1_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn1_label_style.text.font = &supermarket_40;
  btn1_label = lv_label_create(btn1, NULL);
  lv_label_set_style(btn1_label, LV_LABEL_STYLE_MAIN, &btn1_label_style);
  lv_label_set_text(btn1_label, "Preview");
  
  lv_obj_set_hidden(btn1, false);
  /* ====== END of btn1 ====== */
  
  /* ========== btn2 ========== */
  static lv_style_t btn2_rel_style;
  static lv_style_t btn2_pr_style;
  lv_obj_t* btn2;
  static lv_style_t btn2_label_style;
  lv_obj_t* btn2_label;
  
  lv_style_copy(&btn2_rel_style, &lv_style_plain);
  btn2_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn2_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn2_rel_style.body.radius = 6;
  btn2_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn2_rel_style.body.border.width = 0;
  
  lv_style_copy(&btn2_pr_style, &lv_style_plain);
  btn2_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn2_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn2_pr_style.body.radius = 6;
  btn2_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn2_pr_style.body.border.width = 0;
  
  btn2 = lv_btn_create(previewScreen, NULL);
  lv_obj_set_event_cb(btn2, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      
      gd.beep();
    }
  });
  lv_btn_set_style(btn2, LV_BTN_STATE_REL, &btn2_rel_style);
  lv_btn_set_style(btn2, LV_BTN_STATE_PR, &btn2_pr_style);
  lv_obj_set_size(btn2, 200, 60);
  lv_obj_align(btn2, NULL, LV_ALIGN_IN_TOP_RIGHT, -20, 110);
  
  lv_style_copy(&btn2_label_style, &lv_style_plain);
  btn2_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn2_label_style.text.font = &supermarket_40;
  btn2_label = lv_label_create(btn2, NULL);
  lv_label_set_style(btn2_label, LV_LABEL_STYLE_MAIN, &btn2_label_style);
  lv_label_set_text(btn2_label, "Run");
  
  lv_obj_set_hidden(btn2, false);
  /* ====== END of btn2 ====== */
  
  /* ========== objCanvas ========== */
  static lv_style_t objCanvas_style;
  
  lv_style_copy(&objCanvas_style, &lv_style_plain);
  objCanvas_style.body.main_color = lv_color_hex(0xFFFFFF);
  objCanvas_style.body.grad_color = lv_color_hex(0xFFFFFF);
  objCanvas_style.body.radius = 0;
  objCanvas_style.body.opa = 255;
  objCanvas_style.body.border.color = lv_color_hex(0x000000);
  objCanvas_style.body.border.width = 0;
  objCanvas_style.body.border.opa = 255;
  objCanvas_style.body.shadow.color = lv_color_hex(0x000000);
  objCanvas_style.body.shadow.width = 0;
  objCanvas_style.body.shadow.type = LV_SHADOW_FULL;
  
  objCanvas = lv_obj_create(previewScreen, NULL);
  lv_obj_set_style(objCanvas, &objCanvas_style);
  lv_obj_set_size(objCanvas, 800 - 240, 480);
  lv_obj_align(objCanvas, NULL, LV_ALIGN_CENTER, -120, 0);
  
  lv_obj_set_hidden(objCanvas, false);
  /* ====== END of objCanvas ====== */

  /*
  
  static lv_point_t line_points[] = { {5, 5}, {70, 70}, {120, 10}, {180, 60}, {240, 10} };

  static lv_style_t style_line;
  lv_style_copy(&style_line, &lv_style_plain);
  style_line.line.color = lv_color_hex(0x000000);
  style_line.line.width = 1;
  style_line.line.rounded = 0;

  lv_obj_t * line1;
  line1 = lv_line_create(objCanvas, NULL);
  lv_line_set_points(line1, line_points, 5);
  lv_line_set_style(line1, LV_LINE_STYLE_MAIN, &style_line);
  lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
  */
  
  // gcode_drew_line(test_gcode, objCanvas);
}
