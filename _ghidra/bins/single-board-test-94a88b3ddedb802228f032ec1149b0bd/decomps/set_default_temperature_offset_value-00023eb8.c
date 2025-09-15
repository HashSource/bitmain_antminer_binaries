
void set_default_temperature_offset_value(int param_1)

{
  byte bVar1;
  FILE *pFVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_c;
  
  local_c = 0;
  iVar5 = *(int *)(temp_chip_index + param_1 * 4);
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: set default temp offset=%d on chip[%d] of chain[%d]\n",
              "driver-bitmain.c",0x1b60,(int)(char)chip_temp_offset[param_1],iVar5,param_1);
    }
    fclose(pFVar2);
  }
  bVar1 = chip_temp_offset[param_1];
  uVar4 = *(uint *)(DEVICEADDR + param_1 * 4);
  enable_read_temperature_from_asic(param_1,(iVar5 + 0x7fffffffU & 0x7f) << 1);
  check_one_asic_reg(param_1,MISC_CONTROL & 0xff,(iVar5 + 0x7fffffffU & 0x7f) << 1);
  do {
    iVar3 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar5 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar3) break;
  } while (local_c < 2);
  local_c = 0;
  set_config(param_1,0,(iVar5 + 0x7fffffffU & 0x7f) << 1,GENERAL_I2C_COMMAND & 0xff,
             uVar4 | bVar1 | 0x1011100);
  do {
    iVar3 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar5 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar3) break;
  } while (local_c < 2);
  local_c = 0;
  set_config(param_1,0,(iVar5 + 0x7fffffffU & 0x7f) << 1,GENERAL_I2C_COMMAND & 0xff,
             *(uint *)(DEVICEADDR + param_1 * 4) | 0x1001100);
  do {
    iVar3 = check_one_asic_reg(param_1,GENERAL_I2C_COMMAND & 0xff,(iVar5 + 0x7fffffffU & 0x7f) << 1)
    ;
    local_c = local_c + 1;
    if (-1 < iVar3) break;
  } while (local_c < 2);
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: chain[%d] ret = 0x%x, read back offset is %d, %d\n","driver-bitmain.c",
              0x1b84,param_1,iVar3,(int)(char)iVar3,(int)(char)chip_temp_offset[param_1]);
    }
    fclose(pFVar2);
  }
  return;
}

