
/* WARNING: Unknown calling convention */

void check_asic_number(void)

{
  FILE *pFVar1;
  FILE *pFile;
  FILE *pFile_1;
  int i;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      check_asic_reg_oneChain(chain,0,false);
      if (dev->chain_asic_num[chain] == '0') {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Chain[%d]: find %d asic.\n","driver-btm-soc.c",0x1ce5,
                    "check_asic_number",chain,(uint)dev->chain_asic_num[chain]);
          }
          fclose(pFVar1);
        }
      }
      else {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Chain %d only find %d asic, will power off hash board %d\n",
                    "driver-btm-soc.c",0x1ccd,"check_asic_number",chain,
                    (uint)dev->chain_asic_num[chain],chain);
          }
          fclose(pFVar1);
        }
        hashboard_power_off((uint8_t)chain);
        if (freq_mode == 0) {
          for (i = 0; i < 0x10; i = i + 1) {
            if ((dev->chain_exist[i] != 0) && (dev->chain_asic_num[i] == '0')) {
              hashboard_power_off((uint8_t)i);
            }
          }
          stop_mining("Cannot find all asic.\n");
        }
        else {
          dev->chain_exist[chain] = 0;
          dev->chain_num = dev->chain_num + 0xff;
        }
      }
    }
  }
  return;
}

