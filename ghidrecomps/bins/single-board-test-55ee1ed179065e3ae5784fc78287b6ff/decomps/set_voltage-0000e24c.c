
void set_voltage(undefined param_1,undefined param_2,char param_3)

{
  byte bVar1;
  double dVar2;
  uint local_14;
  undefined8 local_10;
  
  local_10 = 0.0;
  switch(pattern_test_time) {
  case 0:
    local_14 = Conf._160_4_;
    break;
  case 1:
    local_14 = Conf._164_4_;
    break;
  case 2:
    local_14 = Conf._168_4_;
    break;
  case 3:
    local_14 = Conf._172_4_;
    break;
  case 4:
    local_14 = Conf._176_4_;
    break;
  case 5:
    local_14 = Conf._180_4_;
    break;
  case 6:
    local_14 = Conf._184_4_;
    break;
  case 7:
    local_14 = Conf._188_4_;
    break;
  case 8:
    local_14 = Conf._192_4_;
    break;
  default:
    local_14 = Conf._160_4_;
    printf("\n--- %s: Can\'t find voltage%d\n",(uint)pattern_test_time);
  }
  Conf._156_4_ = local_14;
  if (param_3 != '\0') {
    local_14 = local_14 + Conf._228_4_;
  }
  if (Conf._116_4_ == 0x6ba) {
    local_10 = DAT_0000e4c0 - ((double)(ulonglong)local_14 * DAT_0000e4b0) / DAT_0000e4b8;
  }
  else if (Conf._116_4_ == 0x6bd) {
    local_10 = DAT_0000e4d0 - ((double)(ulonglong)local_14 * DAT_0000e4c8) / DAT_0000e4b8;
  }
  dVar2 = (double)CONCAT44(DAT_0000e4d8._4_4_,(undefined4)DAT_0000e4d8);
  if (local_10 != dVar2 && local_10 < dVar2 == (NAN(local_10) || NAN(dVar2))) {
    local_10 = (double)CONCAT44(DAT_0000e4d8._4_4_,(undefined4)DAT_0000e4d8);
  }
  if ((int)((uint)(local_10 < 0.0) << 0x1f) < 0) {
    local_10 = 0.0;
  }
  bVar1 = (0.0 < local_10) * (char)(longlong)local_10;
  printf("\n--- %s: real voltage = %d, temp_voltage = %.6f, Pic_Voltage = %d\n","set_voltage",
         local_14,local_10._4_4_,(undefined4)local_10,local_10._4_4_,(uint)bVar1);
  if (Conf._116_4_ == 0x6ba) {
    set_PIC16F1704_voltage(param_1,param_2,bVar1);
  }
  else if (Conf._116_4_ == 0x6bd) {
    power_set_voltage(bVar1);
  }
  usleep(100000);
  return;
}

