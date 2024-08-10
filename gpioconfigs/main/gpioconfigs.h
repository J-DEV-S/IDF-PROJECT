/*
 * GPIO configurations
 * Created on: Aug 8, 2024
 * Author: DEVESH
 */

// Required Libraries
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Tag for logging
#define TAG "test"

// GPIO structure to hold pin configurations
typedef struct {
    int gpio;
} my_gpio_t;

// Array to hold GPIO configurations
my_gpio_t my_gp[10];
