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
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		},
		{
			"name": "supermarket_60",
			"file": "font\\supermarket-1-1\\supermarket.ttf",
			"size": 60,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		}
	],
	"page": [
		{
			"name": "index",
			"background": {
				"main_color": "#FFFFFF",
				"grad_color": "#FFFFFF"
			},
			"component": {
				"component-0": {
					"name": "Object",
					"property": {
						"name": "obj1",
						"hidden": 1,
						"define": 0,
						"alignX": 2,
						"alignY": 0,
						"x": 0,
						"y": 0,
						"width": 240,
						"height": 480,
						"main_color": "#EAECEE",
						"grad_color": "#EAECEE",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 0,
						"shadow_color": "#909090",
						"shadow_type": 1
					}
				},
				"component-1": {
					"name": "Image",
					"property": {
						"name": "img1",
						"hidden": 1,
						"define": 0,
						"alignX": 2,
						"alignY": 2,
						"x": -55,
						"y": -30,
						"src": "D:\\GitHub\\GCTRL-Firmware\\icon\\house.png"
					}
				},
				"component-2": {
					"name": "Button",
					"property": {
						"name": "btn1",
						"hidden": 1,
						"define": 0,
						"alignX": 2,
						"alignY": 0,
						"x": -20,
						"y": 30,
						"width": 200,
						"height": 60,
						"toggle": 0,
						"text": "Preview",
						"rel_main_color": "#F1C40F",
						"rel_grad_color": "#F1C40F",
						"pr_main_color": "#B7950B",
						"pr_grad_color": "#B7950B",
						"border_width": 0,
						"border_color": "#0B1928",
						"radius": 6,
						"color": "#FFFFFF",
						"font": "supermarket_40"
					}
				},
				"component-3": {
					"name": "Button",
					"property": {
						"name": "btn2",
						"hidden": 1,
						"define": 0,
						"alignX": 2,
						"alignY": 0,
						"x": -20,
						"y": 110,
						"width": 200,
						"height": 60,
						"toggle": 0,
						"text": "Run",
						"rel_main_color": "#2ECC71",
						"rel_grad_color": "#2ECC71",
						"pr_main_color": "#1D8348",
						"pr_grad_color": "#1D8348",
						"border_width": 0,
						"border_color": "#0B1928",
						"radius": 6,
						"color": "#FFFFFF",
						"font": "supermarket_40"
					}
				},
				"component-4": {
					"name": "Object",
					"property": {
						"name": "obj2",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": -120,
						"y": 0,
						"width": 100,
						"height": 100,
						"main_color": "#000000",
						"grad_color": "#000000",
						"radius": 0,
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