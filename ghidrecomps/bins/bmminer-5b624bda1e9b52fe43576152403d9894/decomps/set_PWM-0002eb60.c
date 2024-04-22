
/* WARNING: Unknown calling convention */
/* Local variable temp_pwm_percent:int[r0:4] conflicts with parameter, skipped. */

void set_PWM(uchar pwm_percent)

{
  all_parameters *paVar1;
  uint uVar2;
  
  paVar1 = dev;
  uVar2 = (uint)pwm_percent;
  if (99 < uVar2) {
    uVar2 = 100;
  }
  dev->pwm_percent = (uchar)uVar2;
  uVar2 = (int)(uVar2 * -0x32 + 5000) / 100 | ((int)uVar2 >> 1) << 0x10;
  paVar1->pwm_value = uVar2;
  set_fan_control(uVar2);
  return;
}

