
void set_PWM(byte param_1)

{
  undefined4 local_18;
  uint local_14;
  
  local_14 = (uint)param_1;
  if (local_14 < 0x14) {
    local_14 = 0x14;
  }
  if (100 < local_14) {
    local_14 = 100;
  }
  local_18 = CONCAT22((short)((local_14 * 0x32) / 100),(short)((int)((100 - local_14) * 0x32) / 100)
                     );
  set_fan_control(local_18);
  return;
}

