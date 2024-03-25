#ifndef TIMEDATEPAGE_H_
#define TIMEDATEPAGE_H_

#include "task_button.h"
#include "task_interface.h"

static void init_rtc_disp();
static void deinit_rtc_disp();
void rtc_disp();
static void rtc_draw();

static void increment_var_cb();
static void decrement_var_cb();
static void switch_var_cb();
static void confirm_cb();
static void back_rtc_cb();

#endif
