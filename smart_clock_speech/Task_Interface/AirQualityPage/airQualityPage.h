#pragma once

#ifndef AIRQUALITY_H_
#define AIRQUALITY_H_

#include "task_button.h"
#include "task_interface.h"
#include "task_sensor.h"

void airQuality_disp();

static void prev_Cb();
static void airQuality_draw();
static void airQuality_getVal();
static void init_airQuality_disp();
static void deinit_airQuality_disp();
static void speech_airQuality_cmd(uint8_t* cmd);

#endif
