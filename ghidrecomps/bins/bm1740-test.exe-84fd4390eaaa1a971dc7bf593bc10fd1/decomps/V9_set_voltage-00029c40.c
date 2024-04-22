
void V9_set_voltage(undefined param_1,undefined param_2,char param_3)

{
  double dVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  uint local_c;
  
  switch(pattern_test_time) {
  case 0:
    local_c = Conf._156_4_;
    break;
  case 1:
    local_c = Conf._160_4_;
    break;
  case 2:
    local_c = Conf._164_4_;
    break;
  case 3:
    local_c = Conf._168_4_;
    break;
  case 4:
    local_c = Conf._172_4_;
    break;
  case 5:
    local_c = Conf._176_4_;
    break;
  case 6:
    local_c = Conf._180_4_;
    break;
  case 7:
    local_c = Conf._184_4_;
    break;
  case 8:
    local_c = Conf._188_4_;
    break;
  default:
    local_c = Conf._156_4_;
    printf("\n--- %s: Can\'t find voltage%d\n",(uint)pattern_test_time);
  }
  if (param_3 != '\0') {
    local_c = local_c + Conf._240_4_;
  }
  dVar1 = DAT_00029df8 - ((double)(ulonglong)local_c * DAT_00029de8) / DAT_00029df0;
  iVar2 = (uint)(0.0 < dVar1) * (int)(longlong)dVar1;
  local_18 = SUB84(dVar1,0);
  uStack_14 = (undefined4)((ulonglong)dVar1 >> 0x20);
  printf("\n--- %s: real voltage = %d, temp_voltage = %.6f, Pic_Voltage = %d\n","V9_set_voltage",
         local_c,iVar2,local_18,uStack_14,iVar2);
  set_PIC16F1704_voltage(param_1,param_2,iVar2);
  usleep(100000);
  return;
}

