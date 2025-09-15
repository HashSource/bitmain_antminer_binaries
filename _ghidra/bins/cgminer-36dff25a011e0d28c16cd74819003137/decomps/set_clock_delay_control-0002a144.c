
void set_clock_delay_control(uint8_t chain)

{
  FILE *pFVar1;
  uint8_t chain_local;
  clock_delay_ctrl_t reg;
  core_cmd core;
  FILE *pFile_1;
  FILE *pFile;
  uint8_t i;
  
  i = '\0';
  core.reserved = '\0';
  core._15_1_ = 0;
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\x01';
  core.core_mode = '\x01';
  core.core_id = 0;
  core.cmd_type = '\0';
  core.reg_data = 0x34;
  core.rw_falg = '\x01';
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: set CLOCK_DELAY_CTRL to 0x%02x\n","driver-btm-soc.c",0x10b3,
              "set_clock_delay_control",core.reg_data);
    }
    fclose(pFVar1);
  }
  if (chain != All_Chain) {
    i = chain;
  }
  do {
    if (0xf < i) {
      return;
    }
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      core.chain = i;
      set_core_cmd_BM1391(&core);
      if (chain != All_Chain) {
        if (log_level < 4) {
          return;
        }
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: singe chain mode\n","driver-btm-soc.c",0x10c2,
                  "set_clock_delay_control");
        }
        fclose(pFVar1);
        return;
      }
    }
    i = i + '\x01';
  } while( true );
}

