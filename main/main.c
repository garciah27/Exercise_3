#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_10     // Choose your LED pin
#define BUTTON_PIN GPIO_NUM_11    // Choose your button pin

void app_main(void) {

    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_pullup_dis(LED_PIN);
    gpio_pulldown_dis(LED_PIN);
    gpio_intr_disable(LED_PIN);
    gpio_set_level(LED_PIN, 0); 

    gpio_reset_pin(BUTTON_PIN);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_pullup_dis(BUTTON_PIN);
    gpio_intr_disable(BUTTON_PIN);
    //gpio_set_level(BUTTON_PIN, 1);

    // TO-DO: Configure LED output
    // TO-DO: Configure Button input
    bool BUTTON_STATE = false;
    bool LED_STATE = false;
    bool GPIO_STATE; 

    



    while (1) {
         GPIO_STATE = gpio_get_level(BUTTON_PIN) == 0;

        if (!BUTTON_STATE && GPIO_STATE) {
            BUTTON_STATE = true;
            LED_STATE = !LED_STATE;

            if (LED_STATE) {
                gpio_set_level(LED_PIN, 1);
            }
        } 

        if (BUTTON_STATE && !GPIO_STATE) {
            BUTTON_STATE = false;
            gpio_set_level(LED_PIN, 0);
            LED_STATE = false;

        }
        

        


      vTaskDelay(500 / portTICK_PERIOD_MS); //Use appropriate loop delays
    

    }
}