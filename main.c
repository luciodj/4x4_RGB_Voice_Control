/*
\file   main.c

\brief  Main source file.

(c) 2018 Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software and any
derivatives exclusively with Microchip products. It is your responsibility to comply with third party
license terms applicable to your use of third party software (including open source software) that
may accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
FOR A PARTICULAR PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
SOFTWARE.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mcc_generated_files/application_manager.h"
#include "mcc_generated_files/led.h"
#include "mcc_generated_files/sensors_handling.h"
#include "mcc_generated_files/cloud/cloud_service.h"
#include "mcc_generated_files/debug_print.h"
#include "neopixel.h"
#include "json.h"

uint32_t color = 0x00FF00;  // green
uint8_t brightness = 25;
bool onOff = false;
char name[128];

void transition() {
    uint8_t red, green, blue; // take the color input and split in RGB
    if (onOff == true) {
        red   = color >> 16;
        green = color >> 8;
        blue  = color;
        red     = (uint8_t) (red * brightness /100 );
        green   = (uint8_t) (green * brightness / 100);
        blue    = (uint8_t) (blue * brightness /100);
    }
    else {
        red = 0;
        green = 0;
        blue = 0;
    }
    NEO_migrate(red, green, blue);
}

//This handles messages published from the MQTT server when subscribed
void receivedFromCloud(uint8_t *topic, uint8_t *payload)
{
	LED_flashRed();
//	debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "topic: %s", topic);
	debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "payload: %s", payload);
    int t = JSON_getInt(payload, "toggle");
    if (t != -1) {
            onOff = (t != 0);
    }
//    else
//    	debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "t%d, onOff: %d", t, onOff);

    int32_t c = JSON_getInt(payload, "color");
    if (c != -1) {
        color = c;
//        debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "color: 0x%06lx", color);
    }

    uint8_t * np = JSON_getValue(payload, "name");
    if (np != NULL) {
        np++;
        int len = JSON_findQuote(np) - np;
        strncpy(name, (char*)np, len);
        name[len]='\0';
        debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "name: \"%s\"", name);
    }


    int bright = JSON_getInt(payload, "bright");
    if (bright != -1) {
        brightness = bright;
//        debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "bright: %d", bright);
    }

    // execute the transition
    transition();

    // report back state
    static char json[70];
    int len = sprintf(json, "{\"on\":%d,\"brightness\":%d,\"color\":%ld,\"name\":\"%s\"}",
                                onOff,   brightness,       color,         name);
    if (len > 0) {
        CLOUD_publishData((uint8_t*)json, len);
    }
}

// This will get called every CFG_SEND_INTERVAL seconds only while we have a valid Cloud connection
void sendToCloud(void)
{
//   static char json[70];
//   int rawTemperature = SENSORS_getTempValue();
//   int light = SENSORS_getLightValue();
//   int len = sprintf(json, "{\"Light\":%d,\"Temp\":%d}", light,rawTemperature/100);
//   if (len >0) {
//      CLOUD_publishData((uint8_t*)json, len);
//   }

   LED_flashYellow();
}


int main(void)
{
    application_init();
    NEO_init();

    while (1)
    {
      runScheduler();
    }

    return 0;
}
