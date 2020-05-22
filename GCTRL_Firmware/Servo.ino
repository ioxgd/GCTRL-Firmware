#define SERVO_PIN 14

extern pwm_fpio_set_t pwm_pins[];

void servoWrite(uint8_t angle) {
  int8_t _pin = k210FpioSet(MD_PIN_MAP(SERVO_PIN));
  if (_pin >= 0) {
    pwm_set_frequency(pwm_pins[_pin].device, pwm_pins[_pin].channel, 50, (0.5 / 20.0) + ((angle / 180.0) * (2.0 / 20.0)));
    pwm_set_enable(pwm_pins[_pin].device, pwm_pins[_pin].channel, 1);
  }
}