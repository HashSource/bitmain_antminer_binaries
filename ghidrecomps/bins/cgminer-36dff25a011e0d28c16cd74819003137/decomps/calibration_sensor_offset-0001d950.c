
int32_t calibration_sensor_offset(int32_t chain)

{
  uint8_t uVar1;
  FILE *pFVar2;
  int32_t chain_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  uint32_t ret;
  uint32_t i;
  
  get_temp_info_from_default_by_chain(chain);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: chain[%d] temp chip I2C addr=0x%02x\n","temperature.c",0x133,
              "calibration_sensor_offset",chain,0x98);
    }
    fclose(pFVar2);
  }
  dev->chain_asic_temp_num[chain] = (char)temp_info[chain].num;
  i = 0;
  while( true ) {
    if ((uint)(int)dev->chain_asic_temp_num[chain] <= i) {
      return 0;
    }
    dev->TempChipAddr[chain][i] = (temp_info[chain].pos[i] + -1) * '\x05';
    middle_Offset[chain][i] = temp_info[chain].offset[i];
    set_misc_control((uchar)chain,'\0',dev->TempChipAddr[chain][i],1);
    check_asic_reg_with_addr(0x18,dev->TempChipAddr[chain][i],chain,1);
    uVar1 = check_reg_temp(0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
    dev->TempChipType[chain][i] = uVar1;
    if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
       (dev->TempChipType[chain][i] != 'A')) break;
    check_reg_temp('\t','\x04','\x01',dev->TempChipAddr[chain][i],chain);
    update_middle_offset(chain,i);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Chain[%d] chip[%d] use PIC middle temp offset=%d, typeID=%02x\n",
                "temperature.c",0x159,"calibration_sensor_offset",chain,
                dev->TempChipAddr[chain][i] / 5,(int)middle_Offset[chain][i],
                (uint)dev->TempChipType[chain][i]);
      }
      fclose(pFVar2);
    }
    i = i + 1;
  }
  dev->chain_asic_temp_num[chain] = '\0';
  if (log_level < 4) {
    return 0;
  }
  print_crt_time_to_file(log_file,3);
  pFVar2 = fopen(log_file,"a+");
  if (pFVar2 != (FILE *)0x0) {
    fprintf(pFVar2,"%s:%d:%s: wrong temp chip type!!!\n","temperature.c",0x14c,
            "calibration_sensor_offset");
  }
  fclose(pFVar2);
  return 0;
}

