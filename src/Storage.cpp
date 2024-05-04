#include <Storage.h>

namespace STORAGE {

  void begin() {
    pref.begin("aurorav2", true);
    loadSettings();
    pref.end();
  }

  void loadSettings() {
    char *buff[32];

    printf("Initializing preferences: free entries, %i \n", pref.freeEntries());

    pref.getBytes("NAME", &settings.name, 32);

    pref.getBytes(KEY_AP_SSID, &settings.ap_ssid, 32);
    pref.getBytes(KEY_AP_PASS, &settings.ap_pass, 32);
    pref.getBytes(KEY_ST_SSID, &settings.st_ssid, 32);
    pref.getBytes(KEY_ST_PASS, &settings.st_pass, 32);

    // MQTT
    pref.getBytes(KEY_MQTT_BROKER_ADDR, &settings.mqtt_broker_addr, 32);
    pref.getBytes(KEY_MQTT_TOPIC_ANNOUNCE, &settings.mqtt_announce_topic, 128);
    pref.getBytes(KEY_MQTT_TOPIC_ROOT, &settings.mqtt_topic_root, 128);

    // Others
    settings.otp_enabled = pref.getBool(KEY_OTP_EN, OTP_EN);
    settings.preserve_state = pref.getBool(KEY_KEEP_STATE, PRESERVE_STATE);

    // Strip
    settings.strip_size = pref.getInt(KEY_STRIP_SIZE);
    settings.strip_pin = pref.getInt(KEY_STRIP_PIN);
    settings.chip_type = pref.getUChar(KEY_CHIP_TYPE);

    printf(
        "Loaded values from eeprom\
          AP_SSID: %s \          
        \n ",
        settings.ap_ssid);
  }

  /** returns a read only copy of settings values */
  const settings_data getSettings() {
    settings_data retval = settings;
    return retval;
  }

  /** Store settings in flash mem*/
  void saveSettings(settings_data s) {
    // TODO:: determine which field changed, validate it and store it without affecting the rest

    // this is a quick n dirty implementation
    pref.begin(SETTINGS_NAMESPACE);
    pref.putBytes(KEY_NAME, s.ap_pass, 32);
    pref.putBytes(KEY_AP_PASS, s.ap_pass, 32);
    pref.putBytes(KEY_AP_SSID, s.ap_ssid, 32);
    pref.putBytes(KEY_ST_PASS, s.st_pass, 32);
    pref.putBytes(KEY_ST_SSID, s.st_ssid, 32);

    pref.putBytes(KEY_MQTT_BROKER_ADDR, s.mqtt_broker_addr, 32);
    pref.putBytes(KEY_MQTT_TOPIC_ANNOUNCE, s.mqtt_announce_topic, 128);
    pref.putBytes(KEY_MQTT_TOPIC_ROOT, s.mqtt_topic_root, 128);

    pref.putBool(KEY_OTP_EN, s.otp_enabled);
    pref.putBool(KEY_KEEP_STATE, s.preserve_state);

    pref.putInt(KEY_STRIP_SIZE, s.strip_size);
    pref.putUChar(KEY_MQTT_BROKER_ADDR, s.strip_pin);

    pref.end();
  }

}  // namespace STORAGE