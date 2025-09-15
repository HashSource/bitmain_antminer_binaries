
int read_asic_temperature(int param_1)

{
  int iVar1;
  FILE *__stream;
  int iVar2;
  char local_d;
  uint local_c;
  
  local_c = 0;
  iVar2 = *(int *)(temp_chip_index + param_1 * 4);
  enable_read_temperature_from_asic(param_1,(iVar2 + 0x7fffffffU & 0x7f) << 1);
  check_one_asic_reg(param_1,MISC_CONTROL & 0xff,(iVar2 + 0x7fffffffU & 0x7f) << 1);
  do {
    iVar1 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar2 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar1) break;
  } while (local_c < 2);
  local_c = 0;
  set_config(param_1,0,(iVar2 + 0x7fffffffU & 0x7f) << 1,GENERAL_I2C_COMMAND & 0xff,
             *(uint *)(DEVICEADDR + param_1 * 4) | 0x1000100);
  do {
    iVar1 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar2 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar1) break;
  } while (local_c < 2);
  if (iVar1 < 0) {
    local_d = -0x17;
  }
  else {
    local_d = (char)iVar1;
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: ASIC temperature is %d on Chain[%d]\n","driver-bitmain.c",0x1baa,
                (int)local_d,param_1);
      }
      fclose(__stream);
    }
  }
  return (int)local_d;
}

