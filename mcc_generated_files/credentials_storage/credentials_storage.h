/*
    \file   credentials_storage.h

    \brief  Credential Storage header file.

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


#ifndef CREDENTIALS_STORAGE_H
#define CREDENTIALS_STORAGE_H

#define MAX_WIFI_CREDENTIALS_LENGTH 31

extern char ssid[MAX_WIFI_CREDENTIALS_LENGTH];
extern char pass[MAX_WIFI_CREDENTIALS_LENGTH];
extern char authType[2];

void CREDENTIALS_STORAGE_read(char *ssidbuf, char *passwordbuf, char *sec);
void CREDENTIALS_STORAGE_save(char *ssidbuf, char *passwordbuf, char *sec);
uint8_t CREDENTIALS_STORAGE_getDebugSeverity(void);
void CREDENTIALS_STORAGE_setDebugSeverity(uint8_t s);

#endif /* CREDENTIALS_STORAGE_H */