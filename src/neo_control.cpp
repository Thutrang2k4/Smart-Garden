#include "neo_control.h"


void neo_control_RPC(void *pvParameters){

    Adafruit_NeoPixel strip(LED_COUNT, NEO_PIN, NEO_GRB + NEO_KHZ800);
    strip.begin();
    // Set all pixels to off to start
    strip.clear();
    strip.show();

    int current_state = 0;

    while(1) {        
        if (xSemaphoreTake(xMutexNeoState, (TickType_t)10) == pdTRUE) 
        {
            current_state = neo_state;
            xSemaphoreGive(xMutexNeoState); 
        } 
        strip.setPixelColor(0, strip.Color(current_state * 255, 0, 0)); // Set pixel 0 to red
        strip.show(); // Update the strip

<<<<<<< HEAD
        // ------------------------------------------------
        // 2. HUMIDITY TO COLOR MAPPING LOGIC (3 Levels)
        // ------------------------------------------------
        uint32_t color = strip.Color(0, 0, 0); // Default Off

        if (xSemaphoreTake(xMutexNeoStates, (TickType_t)10) == pdTRUE) {
            if (numNeoStates > 0) {
                bool found = false;
                for (int i = 0; i < numNeoStates; i++) {
                    if (local_humidity < neoStates[i].humiThreshold) {
                        color = strip.Color(neoStates[i].r, neoStates[i].g, neoStates[i].b);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    color = strip.Color(neoStates[numNeoStates-1].r, neoStates[numNeoStates-1].g, neoStates[numNeoStates-1].b);
                }
            }
            xSemaphoreGive(xMutexNeoStates);
        }

        // ------------------------------------------------
        // 3. DISPLAY COLOR
        // ------------------------------------------------
        // Set pixel 0 to the calculated color. 
        // Note: For Yolo UNO, NeoPixel is usually bright, so you might want 
        // to dim it by using lower values like (50, 0, 0) instead of 255.
        strip.setPixelColor(0, color); 
        strip.show(); // Push data to the LED

        // Task runs every 500 milliseconds to check for updates
        vTaskDelay(pdMS_TO_TICKS(500));
=======
        // Wait for 100 milliseconds
        vTaskDelay(pdMS_TO_TICKS(100));
>>>>>>> parent of 58c4e31 (Update threshold as well as states of the blinky led task)
    }
}