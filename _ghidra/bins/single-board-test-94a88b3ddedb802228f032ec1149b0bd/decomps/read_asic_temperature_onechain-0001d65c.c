
char read_asic_temperature_onechain(int param_1,byte param_2)

{
  int iVar1;
  FILE *__stream;
  char local_d;
  uint local_c;
  
  local_c = 0;
  local_d = '\0';
  enable_read_temperature_from_asic(param_1,param_2);
  check_one_asic_reg(param_1,MISC_CONTROL & 0xff,param_2);
  do {
    iVar1 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,param_2);
    local_c = local_c + 1;
    if (-1 < iVar1) break;
  } while (local_c < 3);
  local_c = 0;
  if (-1 < iVar1) {
    local_d = (char)iVar1;
  }
  set_config(param_1,0,param_2,GENERAL_I2C_COMMAND & 0xff,
             *(uint *)(DEVICEADDR + param_1 * 4) | 0x1000000);
  do {
    iVar1 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,param_2);
    local_c = local_c + 1;
    if (-1 < iVar1) break;
  } while (local_c < 3);
  if ((-1 < iVar1) && (local_d = (char)iVar1, 5 < log_level)) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: ASIC[%d] local temperature is %d on Chain[%d]\n","driver-bitmain.c",
              0x9a8,(uint)param_2,(int)local_d,param_1);
    }
    fclose(__stream);
  }
  return local_d;
}

