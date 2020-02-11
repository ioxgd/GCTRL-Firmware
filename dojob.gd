{
	"font": [
		{
			"name": "Roboto_16",
			"size": 16,
			"range": "0x0020-0x007F",
			"variable": "lv_font_roboto_16",
			"file": "font/Roboto-Regular.ttf"
		},
		{
			"name": "supermarket_60",
			"file": "font\\supermarket-1-1\\supermarket.ttf",
			"size": 60,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		},
		{
			"name": "supermarket_40",
			"file": "font\\supermarket-1-1\\supermarket.ttf",
			"size": 40,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		}
	],
	"page": [
		{
			"name": "index",
			"background": {
				"main_color": "#FDFEFE",
				"grad_color": "#FDFEFE"
			},
			"component": {
				"component-0": {
					"name": "Label",
					"property": {
						"name": "txt1",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": -150,
						"width": 0,
						"height": 0,
						"text": "กำลังทำงาน...",
						"text_align": 0,
						"color": "#1C2833",
						"mode": 0,
						"font": "supermarket_60"
					}
				},
				"component-1": {
					"name": "Object",
					"property": {
						"name": "obj1",
						"hidden": 1,
						"define": 0,
						"alignX": 0,
						"alignY": 1,
						"x": 100,
						"y": -20,
						"width": 600,
						"height": 60,
						"main_color": "#DEDEDE",
						"grad_color": "#DEDEDE",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 0,
						"shadow_color": "#000000",
						"shadow_type": 1
					}
				},
				"component-3": {
					"name": "Object",
					"property": {
						"name": "obj2",
						"hidden": 1,
						"define": 0,
						"alignX": 0,
						"alignY": 1,
						"x": 100,
						"y": -20,
						"width": 300,
						"height": 60,
						"main_color": "#2ECC71",
						"grad_color": "#2ECC71",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 0,
						"shadow_color": "#000000",
						"shadow_type": 1
					}
				},
				"component-7": {
					"name": "Label",
					"property": {
						"name": "txt2",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 50,
						"width": 0,
						"height": 0,
						"text": "Move to 200,300",
						"text_align": 1,
						"color": "#566573",
						"mode": 0,
						"font": "supermarket_40"
					}
				},
				"component-8": {
					"name": "Label",
					"property": {
						"name": "txt3",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": -20,
						"width": 0,
						"height": 0,
						"text": "50%",
						"text_align": 0,
						"color": "#186A3B",
						"mode": 0,
						"font": "supermarket_40"
					}
				},
				"component-9": {
					"name": "Button",
					"property": {
						"name": "btn1",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": -30,
						"width": 160,
						"height": 80,
						"toggle": 0,
						"text": "ยกเลิก",
						"rel_main_color": "#E74C3C",
						"rel_grad_color": "#E74C3C",
						"pr_main_color": "#943126",
						"pr_grad_color": "#943126",
						"border_width": 0,
						"border_color": "#0B1928",
						"radius": 6,
						"color": "#FFFFFF",
						"font": "supermarket_40"
					}
				},
				"component-10": {
					"name": "Image",
					"property": {
						"name": "img1",
						"hidden": 0,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": -20,
						"src": "D:\\GitHub\\GCTRL-Firmware\\icon\\house.png"
					}
				},
				"component-11": {
					"name": "Label",
					"property": {
						"name": "txt4",
						"hidden": 0,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": -150,
						"width": 0,
						"height": 0,
						"text": "ทำงานเสร็จสิ้น",
						"text_align": 0,
						"color": "#1C2833",
						"mode": 0,
						"font": "supermarket_60"
					}
				}
			}
		}
	]
}