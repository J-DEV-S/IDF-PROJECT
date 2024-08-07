#ifndef MAIN_H
#define MAIN_H
 
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_mac.h"
#include "esp_http_client.h"
#include "esp_http_server.h"
#include <string.h>
#include "esp_tls.h"

#define MAX_HTTP_RECV_BUFFER 512
#define MAX_HTTP_OUTPUT_BUFFER 2048

#define SSID "Santaharaj"
#define PASS "devesh@12345"

#endif