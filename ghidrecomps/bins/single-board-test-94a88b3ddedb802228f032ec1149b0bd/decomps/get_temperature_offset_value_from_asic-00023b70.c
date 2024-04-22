
int get_temperature_offset_value_from_asic(int param_1)

{
  char cVar1;
  int iVar2;
  FILE *pFVar3;
  int iVar4;
  uint local_c;
  
  local_c = 0;
  printf("\n--- %s\n","get_temperature_offset_value_from_asic");
  iVar4 = *(int *)(temp_chip_index + param_1 * 4);
  enable_read_temperature_from_asic(param_1,(iVar4 + 0x7fffffffU & 0x7f) << 1);
  check_one_asic_reg(param_1,MISC_CONTROL & 0xff,(iVar4 + 0x7fffffffU & 0x7f) << 1);
  do {
    iVar2 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar4 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar2) break;
  } while (local_c < 2);
  local_c = 0;
  set_config(param_1,0,(iVar4 + 0x7fffffffU & 0x7f) << 1,GENERAL_I2C_COMMAND & 0xff,
             *(uint *)(DEVICEADDR + param_1 * 4) | 0x1000100);
  do {
    iVar2 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar4 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar2) break;
  } while (local_c < 2);
  local_c = 0;
  cVar1 = (char)iVar2;
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d: Chain[%d] ASIC temperature is %d\n","driver-bitmain.c",0x1b3b,param_1,
              (int)cVar1);
    }
    fclose(pFVar3);
  }
  set_config(param_1,0,(iVar4 + 0x7fffffffU & 0x7f) << 1,GENERAL_I2C_COMMAND & 0xff,
             *(uint *)(DEVICEADDR + param_1 * 4) | 0x1000000);
  do {
    iVar2 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar4 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar2) break;
  } while (local_c < 2);
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d: Chain[%d] PCB temperature is %d\n","driver-bitmain.c",0x1b48,param_1,
              (int)(char)iVar2);
    }
    fclose(pFVar3);
  }
  if (cVar1 == '\0') {
    chip_temp_offset[param_1] = chip_temp_offset[param_1] + '\x1e';
  }
  else {
    chip_temp_offset[param_1] = ((char)iVar2 - cVar1) + chip_temp_offset[param_1];
  }
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d: Chain[%d] new temp_offset_value = %d\n","driver-bitmain.c",0x1b51,
              param_1,(int)(char)chip_temp_offset[param_1]);
    }
    fclose(pFVar3);
  }
  return (int)(char)chip_temp_offset[param_1];
}

