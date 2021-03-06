#pragma once

#include <pebble.h>
#include "config.h"

extern uint32_t connection_icon;
extern GColor bg_color, ticks_color, minute_color, second_color, round_color;;

void set_color() {
	if(persist_read_bool(KEY_INVERT)) {
		connection_icon = RESOURCE_ID_NOT_CONNECTION_STATE_BLACK;
		bg_color = GColorBlack;
		ticks_color = GColorWhite;
		minute_color = GColorWhite;
		second_color = GColorWhite;
	}
	else {
		connection_icon = RESOURCE_ID_NOT_CONNECTION_STATE_WHITE;
		bg_color = GColorWhite;
		ticks_color = GColorBlack;
		minute_color = GColorBlack;
		second_color = GColorBlack;
	}
	
	int red = persist_read_int(KEY_COLOR_RED);
  int green = persist_read_int(KEY_COLOR_GREEN);
  int blue = persist_read_int(KEY_COLOR_BLUE);
	round_color = GColorFromRGB(red, green, blue);
}