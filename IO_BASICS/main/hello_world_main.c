#include <stdio.h>
#include "gpioconfigs.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static void gpio_init(void)
{
    int i_loop=0;

    my_gpio[0].gpio =   5;
    my_gpio[0].mode =   GPIO_MODE_OUTPUT;

    for(i_loop=0;i_loop<1;i_loop++)
    {
        gpio_set_direction(my_gpio[i_loop].gpio, !my_gpio[i_loop].mode);
    }
}

void app_main()
{
    while(true)
    {
        vTaskDelay(5000);
        gpio_init();
    }
}