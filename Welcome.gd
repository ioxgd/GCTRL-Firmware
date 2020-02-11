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
			"name": "supermarket_20",
			"file": "font\\supermarket-1-1\\supermarket.ttf",
			"size": 20,
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
						"alignY": 0,
						"x": 0,
						"y": 30,
						"width": 0,
						"height": 0,
						"text": "GCTRL Firmware",
						"text_align": 0,
						"color": "#1C2833",
						"mode": 0,
						"font": "supermarket_60"
					}
				},
				"component-1": {
					"name": "Image",
					"property": {
						"name": "img1",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": -30,
						"src": "D:\\GitHub\\GCTRL-Firmware\\icon\\book.png"
					}
				},
				"component-2": {
					"name": "Label",
					"property": {
						"name": "txt2",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": -20,
						"width": 0,
						"height": 0,
						"text": "พัฒนาโดย สนธยา นงนุช ชมรมหุ่นยนต์ (ETRC) วิทยาลัยเทคโนโลยีภาคตะวันออก(อี.เทค)",
						"text_align": 0,
						"color": "#566573",
						"mode": 0,
						"font": "supermarket_20"
					}
				},
				"component-4": {
					"name": "Object",
					"property": {
						"name": "obj1",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 110,
						"width": 100,
						"height": 100,
						"main_color": "#000000",
						"grad_color": "#000000",
						"radius": 50,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 0,
						"shadow_color": "#000000",
						"shadow_type": 1
					}
				}
			}
		}
	]
}