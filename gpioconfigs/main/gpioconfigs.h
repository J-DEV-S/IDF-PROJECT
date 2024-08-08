/*
gpio configs are given here,
Created on: Aug 8, 2024
author: DEVESH
*/

//#ifdef GPIOCONFIGS_H
//#define GPIOCONFIGS_H

//REQUIRED GPIOS:
#define GPIO_4      4
#define GPIO_5      5
#define GPIO_6      6

typedef struct 
{
    int gpio;
    int mode;

} my_gpio_t;

my_gpio_t my_gp[10];

//#endif
