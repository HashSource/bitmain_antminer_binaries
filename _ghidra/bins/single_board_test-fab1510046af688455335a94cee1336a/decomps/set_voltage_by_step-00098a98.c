
_Bool set_voltage_by_step(uint32_t pre_voltage,uint32_t target_voltage,uint8_t step_num)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int32_t iVar6;
  char extraout_r1;
  char extraout_r1_00;
  uint8_t step_num_local;
  uint32_t target_voltage_local;
  uint32_t pre_voltage_local;
  char tmp42 [256];
  uint8_t step_length;
  uint8_t target_N;
  uint8_t pre_N;
  uint8_t i;
  uint8_t setting_N;
  uint8_t N_gap;
  
  setting_N = '\0';
  snprintf(tmp42,0x100,"pre_voltage = %d, target_voltage = %d, step_num = %d",pre_voltage,
           target_voltage,(uint)step_num);
  puts(tmp42);
  uVar4 = bitmain_convert_V_to_N((double)pre_voltage / 100.0);
  bVar1 = (byte)uVar4;
  uVar5 = bitmain_convert_V_to_N((double)target_voltage / 100.0);
  bVar2 = (byte)uVar5;
  if ((uVar5 & 0xff) < (uVar4 & 0xff)) {
    N_gap = bVar1 - bVar2;
  }
  else {
    if ((uVar5 & 0xff) <= (uVar4 & 0xff)) {
      builtin_strncpy(tmp42,"target_voltage = pre_voltage. Don\'t need do anything",0x34);
      tmp42[0x34] = '.';
      tmp42[0x35] = '\0';
      puts(tmp42);
      return true;
    }
    N_gap = bVar2 - bVar1;
  }
  bVar3 = __aeabi_uidiv(N_gap,step_num);
  snprintf(tmp42,0x100,"pre_N = %d, target_N = %d, N_gap = %d, step_length = %d",uVar4 & 0xff,
           uVar5 & 0xff,(uint)N_gap,(uint)bVar3);
  puts(tmp42);
  if (bVar3 == 0) {
    for (i = '\0'; i < N_gap; i = i + '\x01') {
      if ((uVar5 & 0xff) < (uVar4 & 0xff)) {
        setting_N = bVar1 - 1;
      }
      else {
        setting_N = bVar1 + 1;
      }
    }
    iVar6 = bitmain_set_voltage_by_n(setting_N);
    if ((iVar6 != 0) && (iVar6 = bitmain_set_voltage_by_n(setting_N), iVar6 != 0)) {
      builtin_strncpy(tmp42,"Set APW voltage by N fail",0x1a);
      puts(tmp42);
      return false;
    }
  }
  else {
    for (i = '\0'; i < step_num; i = i + '\x01') {
      if (i == '\0') {
        if (bVar2 < bVar1) {
          __aeabi_uidivmod(N_gap,step_num);
          setting_N = (bVar1 - bVar3) - extraout_r1;
        }
        else {
          __aeabi_uidivmod(N_gap,step_num);
          setting_N = extraout_r1_00 + bVar3 + bVar1;
        }
      }
      else if (bVar2 < bVar1) {
        setting_N = setting_N - bVar3;
      }
      else {
        setting_N = bVar3 + setting_N;
      }
      uVar4 = bitmain_set_voltage_by_n(setting_N);
      if ((uVar4 != setting_N) && (uVar4 = bitmain_set_voltage_by_n(setting_N), uVar4 != setting_N))
      {
        snprintf(tmp42,0x100,"Set APW voltage by N = %d fail",(uint)setting_N);
        puts(tmp42);
        return false;
      }
    }
  }
  return true;
}

