
void set_clock_delay_control(uint8_t chain,uint8_t pulse_mode)

{
  FILE *pFVar1;
  byte bVar2;
  uint8_t pulse_mode_local;
  uint8_t chain_local;
  core_cmd core;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile;
  FILE *pFile_1;
  uint8_t core_data;
  uint8_t i;
  
  i = '\0';
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\0';
  core.core_mode = '\0';
  core.core_id = '\0';
  core.cmd_type = '\0';
  core.rw_falg = '\0';
  core.reserved = '\0';
  core.reg_data = 0;
  if (pulse_mode == '\0') {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: set mode 0\n","driver-btm-soc.c",0xf4f,"set_clock_delay_control");
      }
      fclose(pFVar1);
    }
    g_Clock_delay_control = g_Clock_delay_control & 0xfd;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: set mode 2\n","driver-btm-soc.c",0xf54,"set_clock_delay_control");
      }
      fclose(pFVar1);
    }
    g_Clock_delay_control = g_Clock_delay_control | 2;
  }
  bVar2 = g_Clock_delay_control | 4;
  core.chip_addr = '\0';
  core.mode = '\x01';
  core.core_mode = '\x01';
  core.reg_data = (uint)bVar2;
  core.core_id = '\0';
  core.cmd_type = '\0';
  core.rw_falg = '\x01';
  g_Clock_delay_control = bVar2;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: core_data = 0x%02x\n","driver-btm-soc.c",0xf62,
              "set_clock_delay_control",(uint)bVar2);
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
      set_core_cmd_BM1393(&core);
      if (chain != All_Chain) {
        if (log_level < 4) {
          return;
        }
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: single chain mode\n","driver-btm-soc.c",0xf70,
                  "set_clock_delay_control");
        }
        fclose(pFVar1);
        return;
      }
    }
    i = i + '\x01';
  } while( true );
}

