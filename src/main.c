#include <driver/ledc.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main()
{
  // setup the timer
  ledc_timer_config_t ledc_timer = {
      .duty_resolution = LEDC_TIMER_8_BIT,
      .freq_hz = 228000,
      .speed_mode = LEDC_HIGH_SPEED_MODE,
      .timer_num = LEDC_TIMER_0};

  ledc_timer_config(&ledc_timer);

  // configure the duty cycle and gpio number
  ledc_channel_config_t ledc_channel = {
      .channel = LEDC_CHANNEL_0,
      .duty = (40 * 256) / 100,
      .gpio_num = GPIO_NUM_21,
      .speed_mode = LEDC_HIGH_SPEED_MODE,
      .timer_sel = LEDC_TIMER_0};

  ledc_channel_config(&ledc_channel);

  while (true)
  {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}