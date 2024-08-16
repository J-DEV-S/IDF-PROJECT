#include "myWIFI.c"

void app_main(void)
{
    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_connection();
}
