#include <string.h>
#include "interface.h"

//interface_t interface_obj;

// Function success
void interface_construct(interface_t *interface_menu){
	interface_menu->menu = NULL;
	interface_menu->total_menu = 0;
	interface_menu->position = 0;
	interface_menu->offset = 0;
	interface_menu->cursor = 1;
}

// Function success
void interface_begin(interface_t *interface_menu){
	interface_menu->position = 0;
//	GUI_Init();
}

void interface_draw_menu(interface_t *interface_menu){
	uint8_t x = 0, y = 10;
	unsigned char total_menu_show = interface_menu->menu < 5 ? interface_menu->total_menu : 5;
	unsigned char menu_offset = interface_menu->position < 5 ? 0 : interface_menu->position - 4;

	if (((interface_menu->position < interface_menu->offset) || (interface_menu->position >= interface_menu->offset + 4)) && interface_menu->cursor > 0){
		if (interface_menu->offset > menu_offset)
			interface_menu->offset--;
		else
			interface_menu->offset = menu_offset;
	}
	const char *menu_show[total_menu_show];

	if (interface_menu->set_title == 1){
		GUI_DispStringAt(interface_menu->title, x, y-5);
		y+=10;
	}
//	printf("TotMenu:%d\tCursor:%d\tPos:%d\tOffset:%d\r\n",total_menu_show,interface_menu->cursor,interface_menu->position, interface_menu->offset);

	for (uint8_t i = 0; i < (interface_menu->set_title == 1 ? 4 : 5) && i < total_menu_show; i++){
		menu_show[i] = interface_menu->menu[i + interface_menu->offset];
		if (interface_menu->cursor > 0){
			if (interface_menu->position - interface_menu->offset == i){
//				printf("%d\r\n", (interface_menu->position - interface_menu->offset));
				GUI_DispStringAt(">", x+8, y+(10*i));
				if (menu_show[i] != NULL)
					GUI_DispStringAt(menu_show[i], x+16, y+(10*i));
			}
			else{
				GUI_DispStringAt(" ", x+8, y+(10*i));
				if (menu_show[i] != NULL)
					GUI_DispStringAt(menu_show[i], x+16, y+(10*i));
			}
		}
		else{
			if (menu_show[i] != NULL)
				GUI_DispStringAt(menu_show[i], x+5, y+(10*i));
		}
	}
}

// Function success
void interface_next(interface_t *interface_menu){
	interface_menu->position++;
	interface_menu->position = interface_menu->position % interface_menu->total_menu;

//	printf("%d\r\n",interface_menu->position);
}

// Function success
void interface_previous(interface_t *interface_menu){
	interface_menu->position += interface_menu->total_menu;
	interface_menu->position --;
	interface_menu->position = interface_menu->position % interface_menu->total_menu;
//	printf("%d\r\n",interface_menu->position);
}

// Function success
void interface_reset_position(interface_t *interface_menu){
	interface_menu->position = 0;
}

// Function success
uint8_t interface_getPosition(interface_t *interface_menu){
	return interface_menu->position;
}

// Function Success
void interface_set_menu(interface_t *interface_menu, const char **menu, uint8_t total_menu){
	interface_menu->menu = menu;
	interface_menu->total_menu = total_menu;
//	printf("Total Menu: %d\r\n",interface_menu->total_menu);
//	for (uint8_t i = 0; i < total_menu; i++){
//		printf("%s\r\n", interface_menu->menu[i]);
//	}
}

void interface_draw(interface_t *interface_menu){
	//go to first page
		interface_draw_menu(interface_menu);
}

// Function success
void interface_clear(interface_t *interface_menu) {
	return GUI_Clear();
}

void interface_cursor(interface_t *interface_menu, uint8_t cursor){
	interface_menu->cursor = cursor;
}

// Function success
void interface_setTitle(interface_t *interface_menu, const char *title){
	interface_menu->set_title = 1;
	strcpy(interface_menu->title, title);
//	printf("%s\r\n", interface_menu->title);

}
