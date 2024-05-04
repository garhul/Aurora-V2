

# Aurora V2 Draft


### Proposed actions:
These is a small list of some core functionalities and ideas

- Get settings
- Set settings
- Restart
- Turn off [duraiton]

- Stream animation frame
- Upload animation
- Set animation bank #
- Set brightness
- Set animation speed
- Play
- Pause
- Clear
- Fill

### Settings
  List of properties in the settings object

  #### WIFI
  - NAME ?`CHAR(32)`
  - AP_SSID ?`CHAR[32]`
  - AP_PASS ?`CHAR[32]`
  - ST_SSID ?`CHAR[32]`
  - ST_PASSWORD `CHAR[32]`

  #### Mosquitto
  - MQTT_BROKER_ADDR `CHAR[40]`
  - MQTT_TOPIC_ROOT `CHAR[40]` aurora/
  - MQTT_ANNOUNCE_TOPIC `CHAR[40]` aurora/announecment

  #### Strip
  - CHIP_TYPE `uint8_t`
  - STRIP_SIZE `uint16_t`
  - STRIP_PIN `uint8_t`

  #### Others
  - ENABLE_OTP `bool` default false
  - PRESERVE_STATE `bool` default false

## AP Mode:
 captive portal
 password protected if password is set




### State management and update

Upon state change the device will issue a message back to the available communication channels


### OTA support