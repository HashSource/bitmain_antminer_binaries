
void save_freq_toPIC(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_3c;
  int local_38;
  undefined auStack_34 [8];
  FILE *local_2c;
  FILE *local_28;
  FILE *local_24;
  FILE *local_20;
  FILE *local_1c;
  undefined4 local_18;
  undefined local_12;
  byte local_11;
  uint local_10;
  int local_c;
  
  local_11 = 0;
  local_12 = 0;
  get_mac(&DAT_00130d1c,auStack_34);
  *(undefined4 *)(chain_vol_added + param_1 * 4) = 0;
  local_11 = getPICvoltageFromValue(*(undefined4 *)(chain_vol_value + param_1 * 4));
  local_18 = *(undefined4 *)(chain_vol_value + param_1 * 4);
  if (3 < log_level) {
    local_1c = fopen(log_file,"a+");
    if (local_1c != (FILE *)0x0) {
      fprintf(local_1c,
              "%s:%d: special fix hash_voltage pic value = %d [%d] of Chain[%d], voladded=%d\n",
              "main.c",0x19ba,(uint)local_11,local_18,param_1,
              *(undefined4 *)(chain_vol_added + param_1 * 4));
    }
    fclose(local_1c);
  }
  set_pic_voltage(param_1 & 0xff,local_11);
  puts("\nwrite freq index into pic");
  chain_pic_buf[param_1 * 0x80] = 0x7d;
  if (3 < log_level) {
    local_20 = fopen(log_file,"a+");
    if (local_20 != (FILE *)0x0) {
      fprintf(local_20,"%s:%d: \nWrite freq to PIC : \n","main.c",0x1a6e);
    }
    fclose(local_20);
  }
  for (local_10 = 0; (int)local_10 < 0x54; local_10 = local_10 + 1) {
    if (g_is_low_power_hashrate_scan == '\0') {
      *(char *)(param_1 * 0x80 + local_10 + 0x1a3fbbe) =
           (char)*(undefined4 *)(local_10 * 4 + param_2);
    }
    else {
      local_38 = 0;
      local_3c = 0;
      local_c = 0;
      while ((local_c < 4 &&
             (getBoardTestVoltageAndFreqForS11LowPowerMode(local_c,&local_3c,&local_38),
             *(int *)(local_10 * 4 + param_2) != local_38))) {
        local_c = local_c + 1;
      }
      if ((local_10 & 3) == 0) {
        uVar1 = local_10 + 3;
        if (-1 < (int)local_10) {
          uVar1 = local_10;
        }
        *(undefined *)(param_1 * 0x80 + ((int)uVar1 >> 2) + 0x1a3fc17) = 0;
      }
      uVar1 = local_10 + 3;
      if (-1 < (int)local_10) {
        uVar1 = local_10;
      }
      uVar2 = local_10 & 3;
      if ((int)local_10 < 1) {
        uVar2 = -(-local_10 & 3);
      }
      *(byte *)(param_1 * 0x80 + ((int)uVar1 >> 2) + 0x1a3fc17) =
           (byte)(local_c << ((uVar2 & 0x7f) << 1)) |
           *(byte *)(param_1 * 0x80 + ((int)uVar1 >> 2) + 0x1a3fc17);
    }
    if (1 < log_level) {
      local_24 = fopen(log_file,"a+");
      if (local_24 != (FILE *)0x0) {
        fprintf(local_24,"Freq[%02d]=%s\t",local_10,
                *(undefined4 *)(freq_pll_1385 + *(int *)(local_10 * 4 + param_2) * 0x10));
      }
      fclose(local_24);
    }
    if (((int)local_10 % 7 == 0) && (1 < log_level)) {
      local_28 = fopen(log_file,"a+");
      if (local_28 != (FILE *)0x0) {
        fputc(10,local_28);
      }
      fclose(local_28);
    }
  }
  if (3 < log_level) {
    local_2c = fopen(log_file,"a+");
    if (local_2c != (FILE *)0x0) {
      fputc(10,local_2c);
    }
    fclose(local_2c);
  }
  return;
}

