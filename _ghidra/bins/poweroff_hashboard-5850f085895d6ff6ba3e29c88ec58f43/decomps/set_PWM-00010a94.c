
void set_PWM(byte param_1)

{
  undefined4 local_14;
  
  local_14 = CONCAT22((short)(((uint)param_1 * 0x32) / 100),
                      (short)((int)((100 - (uint)param_1) * 0x32) / 100));
  set_fan_control(local_14);
  return;
}

