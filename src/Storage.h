#pragma once
#include <Arduino.h>
#include <Preferences.h>

#define SETTINGS_NAMESPACE "ST"
// defaults:
#define OTP_EN false
#define PRESERVE_STATE false  // (saves flash life)

#define KEY_NAME "NAME"
#define KEY_AP_SSID "AP_SS"
#define KEY_AP_PASS "AP_PW"
#define KEY_ST_SSID "ST_SS"
#define KEY_ST_PASS "ST_PW"

#define KEY_MQTT_BROKER_ADDR "MQ_ADDR"
#define KEY_MQTT_TOPIC_ROOT "MQ_TR"
#define KEY_MQTT_TOPIC_ANNOUNCE "MQ_TA"

#define KEY_OTP_EN "OTP"
#define KEY_KEEP_STATE "KST"

#define KEY_CHIP_TYPE "STRP_CHIP"
#define KEY_STRIP_SIZE "STRP_SIZE"
#define KEY_STRIP_PIN "STRP_PIN"

namespace STORAGE {
  Preferences pref;

  // std::set<char*> keys;
  // keys.insert("a");

  // keys.

  enum CHIPS { WS_2811,
               WS_2812,
               WS_2812B,
               WS_2813,
               SK6812 };

  typedef struct {
    char name[32];

    // WIFI
    char ap_ssid[32];
    char ap_pass[32];
    char st_ssid[32];
    char st_pass[32];

    // MQTT
    char mqtt_broker_addr[32];
    char mqtt_topic_root[128];
    char mqtt_announce_topic[128];

    // Others
    bool otp_enabled;
    bool preserve_state;

    // Strip
    uint8_t chip_type;
    uint16_t strip_size;
    uint8_t strip_pin;
  } settings_data;
  settings_data settings;

  void begin();
  void loadSettings();

  const settings_data getSettings();
  const String getSettingsJSON();
  const String gestStateJSON();

}  // namespace STORAGE
