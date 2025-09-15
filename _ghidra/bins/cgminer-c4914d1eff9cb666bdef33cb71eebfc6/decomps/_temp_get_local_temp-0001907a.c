
int _temp_get_local_temp(float *p_temp)

{
  int16_t iVar1;
  uint uVar2;
  FILE *__stream;
  int iVar3;
  float *p_temp_local;
  FILE *pFile;
  int local_temp;
  uint8_t reg_temp;
  int chip_addr;
  int ret;
  float sum;
  int good_air_in;
  int bad_air_in;
  int min;
  int max;
  int i;
  int chain;
  
  max = -1000;
  min = 1000;
  bad_air_in = 0;
  good_air_in = 0;
  sum = 0.0;
  ret = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
        if (dev->TempChipAddr[chain][i] >> 2 == 0x1e) {
          uVar2 = check_reg_temp(DEVICEADDR[chain],0,'\0','\0',dev->TempChipAddr[chain][i],chain);
          if ((byte)uVar2 == 0) {
            bad_air_in = bad_air_in + 1;
          }
          else {
            iVar1 = get_local((ushort)(byte)uVar2);
            iVar3 = (int)iVar1;
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              __stream = fopen(log_file,"a+");
              if (__stream != (FILE *)0x0) {
                fprintf(__stream,"%s:%d:%s: sensor[%d] = %d, reg_temp = %d\n","temperature.c",0x529,
                        "_temp_get_local_temp",0x1f,iVar3,uVar2 & 0xff);
              }
              fclose(__stream);
            }
            good_air_in = good_air_in + 1;
            sum = sum + (float)(longlong)iVar3;
            if (iVar3 < min) {
              min = iVar3;
            }
            if (max < iVar3) {
              max = iVar3;
            }
          }
        }
      }
    }
  }
  iVar3 = good_air_in + -2;
  if ((iVar3 == 0) || (iVar3 < bad_air_in)) {
    ret = -1;
  }
  else {
    *p_temp = ((sum - (float)(longlong)max) - (float)(longlong)min) / (float)(longlong)iVar3;
  }
  return ret;
}

