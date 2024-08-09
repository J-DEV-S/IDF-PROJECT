#include <stdio.h>
#include "gpioconfigs.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static void gpio_init(void)
{
    int i_loop=0;

    my_gp[0].gpio =   4;
    my_gp[1].gpio =   5;
    my_gp[2].gpio =   6;

    for(i_loop=0;i_loop<3;i_loop++)
    {
        gpio_set_direction(my_gp[i_loop].gpio, GPIO_MODE_OUTPUT);
    }
}

static void gpio_control(void)
{
    int i=0,level=0;
    for(i=0;i<3;i++)
    {
        gpio_set_level(my_gp[i].gpio,!level);
        LOGI("in");
    }

}

void app_main()
{
    gpio_init();
    void *p;
    p=&gpio_control;

    while(true)
    {
        vTaskDelay(5000);
        xTaskCreate(gpio_control, "gpio", 1024, NULL, 1, NULL);

    }
}