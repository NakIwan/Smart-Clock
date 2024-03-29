#include "task_interface.h"
#include "main_page.h"
#include "interface.h"
#include "menuDisp.h"

cyhal_i2c_t i2c;
uint8_t this_page = 0;

void displayOled(void *arg){

	const cyhal_i2c_cfg_t i2c_cfg =
	{
			.is_slave 		 = false,
			.address  		 = 0,
			.frequencyhal_hz = 400000
	};

	cyhal_i2c_init(&i2c, P6_1, P6_0, NULL);
	cyhal_i2c_configure(&i2c, &i2c_cfg);

	mtb_ssd1306_init_i2c(&i2c);
	GUI_Init();
	GUI_Clear();

	while (!systemReady){
		vTaskDelay(5);
	}

	while(1){
			main_page();
		if (this_page == MENU_PAGE_ID)
			menu_disp();

		vTaskDelay(10);
	}
}
