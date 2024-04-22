
/* WARNING: Unknown calling convention */

_Bool temp_is_air_out_too_high(void)

{
  FILE *__stream;
  FILE *pFile;
  int temp_asic;
  int chain;
  
  chain = 0;
  do {
    if (0xf < chain) {
      return false;
    }
    if (dev->chain_exist[chain] != 0) {
      for (temp_asic = 0; temp_asic < dev->chain_asic_temp_num[chain]; temp_asic = temp_asic + 1) {
        if (((((byte)(dev->TempChipAddr[chain][temp_asic] - 0x28) < 5) ||
             ((byte)(dev->TempChipAddr[chain][temp_asic] + 0x3d) < 5)) &&
            (dev->chain_asic_temp_status[chain][temp_asic] == '\x01')) &&
           (0x44 < dev->chain_asic_temp[chain][temp_asic][0])) {
          if (3 < log_level) {
            print_crt_time_to_file(temp_log,3);
            __stream = fopen(temp_log,"a+");
            if (__stream != (FILE *)0x0) {
              fprintf(__stream,"%s:%d:%s: **high_priority error, temp=%d.\n","temperature.c",0x2a9,
                      "temp_is_air_out_too_high",(int)dev->chain_asic_temp[chain][temp_asic][0]);
            }
            fclose(__stream);
          }
          return true;
        }
      }
    }
    chain = chain + 1;
  } while( true );
}

