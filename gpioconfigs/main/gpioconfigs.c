#include "gpioconfigs.h"
#include "esp_log.h"

// Function to initialize GPIOs
static void gpio_init(void) {
    // Initialize the GPIO array with the pin numbers
    my_gp[0].gpio = 4;
    my_gp[1].gpio = 5;
    my_gp[2].gpio = 18;

    // Set the direction of each GPIO to output
    for(int i_loop = 0; i_loop < 3; i_loop++) {
        gpio_set_direction(my_gp[i_loop].gpio, GPIO_MODE_OUTPUT);
    }
}

// Task function to control GPIO levels, modified to take a void* parameter
static void gpio_control(void *pvParameter) {
    static int level = 0;  // static variable to toggle levels

    // Infinite loop to toggle GPIOs
    while (true) {
        // Toggle the state of each GPIO
        for(int i = 0; i < 3; i++) {
            gpio_set_level(my_gp[i].gpio, level);
            ESP_LOGI(TAG, "GPIO %d set to %d", my_gp[i].gpio, level);
        }

        // Toggle the level for the next call
        level = !level;

        // Delay for 1 second before toggling again
        vTaskDelay(pdMS_TO_TICKS(1000));  // Delay for 1 second
    }
}

void app_main(void) {
    // Initialize GPIOs
    gpio_init();

    // Start the task to control GPIOs periodically
    xTaskCreate(gpio_control, "gpio_task", 2048, NULL, 1, NULL);

    // Main loop does nothing, task runs in the background
    while(true) {
        vTaskDelay(pdMS_TO_TICKS(5000));  // Delay for 5 seconds
    }
}
