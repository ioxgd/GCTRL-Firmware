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
			"name": "supermarket_40",
			"file": "font\\supermarket-1-1\\supermarket.ttf",
			"size": 40,
			"range": "0x0E00-0x0E7F,0x0020-0x007F"
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
				"component-1": {
					"name": "Label",
					"property": {
						"name": "txt1",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": 210,
						"y": -50,
						"width": 0,
						"height": 0,
						"text": "Load from SD Card",
						"text_align": 1,
						"color": "#D35400",
						"mode": 0,
						"font": "supermarket_40"
					}
				},
				"component-2": {
					"name": "Image",
					"property": {
						"name": "img1",
						"hidden": 1,
						"define": 1,
						"alignX": 1,
						"alignY": 0,
						"x": 210,
						"y": 110,
						"src": "D:\\GitHub\\GCTRL-Firmware\\icon\\micro-sd-card.png"
					}
				},
				"component-3": {
					"name": "Image",
					"property": {
						"name": "img2",
						"hidden": 1,
						"define": 1,
						"alignX": 1,
						"alignY": 0,
						"x": -210,
						"y": 110,
						"src": "D:\\GitHub\\GCTRL-Firmware\\icon\\JoyJoyJoy.png"
					}
				},
				"component-4": {
					"name": "Label",
					"property": {
						"name": "txt2",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": -210,
						"y": -50,
						"width": 0,
						"height": 0,
						"text": "Move",
						"text_align": 1,
						"color": "#2E86C1",
						"mode": 0,
						"font": "supermarket_40"
					}
				}
			}
		}
	]
}