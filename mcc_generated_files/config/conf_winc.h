#ifndef CONF_WIFI_M2M_H_INCLUDED
#define CONF_WIFI_M2M_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "conf_winc_pins.h"
#include "../winc/driver/include/m2m_types.h"

/** Module Pin Settings */
// #define CONF_WIFI_M2M_RESET_PIN                 IOPORT_CREATE_PIN(PORTD, 6)
// #define CONF_WIFI_M2M_CHIP_ENABLE_PIN           IOPORT_CREATE_PIN(PORTD, 5)
// #define CONF_WIFI_M2M_WAKE_PIN                  IOPORT_CREATE_PIN(PORTD, 7)

// #define CONF_WIFI_M2M_RESET_PIN                 IOPORT_CREATE_PIN(PORTA, 2)
// #define CONF_WIFI_M2M_CHIP_ENABLE_PIN           IOPORT_CREATE_PIN(PORTC, 0)
// #define CONF_WIFI_M2M_WAKE_PIN                  IOPORT_CREATE_PIN(PORTA, 3)

// #define CONF_WIFI_M2M_INT_PIN                   IOPORT_CREATE_PIN(PORTD, 4)

// #define CONF_WIFI_M2M_INT_PIN                   IOPORT_CREATE_PIN(PORTC, 1)

//#define CONF_WIFI_M2M_INT_vect                  PCINT2_vect
#define CONF_WIFI_M2M_INT_vect					PORTF_PORT_vect


#define CONF_WIFI_M2M_INT_INTFLAG_Msk           (1 << PCINT17)
#define CONF_WIFI_M2M_INT_INTMASK_reg           PCMSK2
#define CONF_WIFI_M2M_INT_INTCTRL_reg           PCICR
#define CONF_WIFI_M2M_INT_INTCTRL_Msk           (1 << PCIE2)

/** INTERRUPT Detect Mode Settings */
#define CONF_WIFI_M2M_EDGE_INTERRUPT            (1)

/** BUS Type Settings */
#define CONF_WIFI_M2M_SPI                       (1)
#define CONF_WINC_USE_SPI                       (1)

/** SPI Settings */
#define CONF_WIFI_M2M_SPI_MODULE                0
#define CONF_WIFI_M2M_SPI_CS_PIN                PA7
// #define CONF_WIFI_M2M_SPI_CS_PIN                IOPORT_CREATE_PIN(PORTB, 2)
// #define CONF_WIFI_M2M_SPI_MISO_PIN              IOPORT_CREATE_PIN(PORTB, 4)
// #define CONF_WIFI_M2M_SPI_MOSI_PIN              IOPORT_CREATE_PIN(PORTB, 3)
// #define CONF_WIFI_M2M_SPI_SCK_PIN               IOPORT_CREATE_PIN(PORTB, 5)

// #define CONF_WIFI_M2M_SPI_CS_PIN                IOPORT_CREATE_PIN(PORTB, 4)
// #define CONF_WIFI_M2M_SPI_MISO_PIN              IOPORT_CREATE_PIN(PORTB, 6)
// #define CONF_WIFI_M2M_SPI_MOSI_PIN              IOPORT_CREATE_PIN(PORTB, 5)
// #define CONF_WIFI_M2M_SPI_SCK_PIN               IOPORT_CREATE_PIN(PORTB, 7)
//#define CONF_WIFI_M2M_SPI_BAUDRATE              (10000000UL)

/** Debug Options */
#define CONF_WIFI_M2M_DEBUG                     (0)
#define CONF_WIFI_M2M_debug_print                    printf

// #define CONF_WINC_DEBUG					(1)
// #define CONF_WINC_PRINTF				printf

// <h> WLAN Configuration

// <s> SSID
// <i> Target WLAN SSID
// <id> main_wlan_ssid
//#define CFG_MAIN_WLAN_SSID "MCHP.IOT"
#define CFG_MAIN_WLAN_SSID "WLAN-4A2X96"

// <y> Authentication
// <i> Target WLAN Authentication
// <M2M_WIFI_SEC_INVALID"> Invalid security type
// <M2M_WIFI_SEC_OPEN"> Wi-Fi network is not secured
// <M2M_WIFI_SEC_WPA_PSK"> Wi-Fi network is secured with WPA/WPA2 personal(PSK)
// <M2M_WIFI_SEC_WEP"> Security type WEP (40 or 104) OPEN OR SHARED
// <M2M_WIFI_SEC_802_1X"> Wi-Fi network is secured with WPA/WPA2 Enterprise.IEEE802.1x user-name/password authentication
// <id> main_wlan_auth
#define CFG_MAIN_WLAN_AUTH M2M_WIFI_SEC_WPA_PSK

// <s> Password
// <i> Target WLAN password
// <id> main_wlan_psk
//#define CFG_MAIN_WLAN_PSK "microchip"
#define CFG_MAIN_WLAN_PSK "7590365358457036"

// </h>

// <h> AP Mode Configuration

// <s> Name
// <i> AP name
// <id> wlan_ap_name
#define CFG_WLAN_AP_NAME "AVR.IoT"

// <s> IP Address
// <i> AP IP Address
// <id> wlan_ap_ip_address
#define CFG_WLAN_AP_IP_ADDRESS {192, 168, 1, 1}

// </h>

#ifdef __cplusplus
}
#endif

#endif /* CONF_WIFI_M2M_H_INCLUDED */
