
/* WARNING: Unknown calling convention */

void low_temp_process_parm_init(void)

{
  _Bool _Var1;
  FILE *__stream;
  FILE *pFile;
  int delta_temp;
  int chain;
  
  if (!low_temp_process_parm_init::minor_type_init) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if ((dev->chain_exist[chain] != 0) &&
         (low_temp_process_parm_init::minor_types = g_minor_type[chain], 3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: chip miner_type = [%d]\n","driver-btm-soc.c",0xb64,
                  "low_temp_process_parm_init",low_temp_process_parm_init::minor_types);
        }
        fclose(__stream);
      }
    }
    low_temp_process_parm_init::minor_type_init = true;
  }
  _Var1 = is_T11();
  if (_Var1) {
    if (low_temp_process_parm_init::minor_types == PKG_BSL) {
      low_temp_process_parm[0].low_temp = 0xc;
      low_temp_process_parm[0].middle_temp = 0x16;
      low_temp_process_parm[0].high_temp = 0x1b;
      low_temp_process_parm[0].delta_vol = 0.2;
      low_temp_process_parm[1].low_temp = 0x12;
      low_temp_process_parm[1].middle_temp = 0x1a;
      low_temp_process_parm[1].high_temp = 0x1f;
      low_temp_process_parm[1].delta_vol = 0.3;
    }
    else if (low_temp_process_parm_init::minor_types == PKG_CE) {
      low_temp_process_parm[0].low_temp = 0xc;
      low_temp_process_parm[0].middle_temp = 0x18;
      low_temp_process_parm[0].high_temp = 0x1d;
      low_temp_process_parm[0].delta_vol = 0.2;
      low_temp_process_parm[1].low_temp = 0x1c;
      low_temp_process_parm[1].middle_temp = 0x25;
      low_temp_process_parm[1].high_temp = 0x2a;
      low_temp_process_parm[1].delta_vol = 0.2;
    }
    else if (low_temp_process_parm_init::minor_types == PKG_B_BGM) {
      low_temp_process_parm[0].low_temp = 0x17;
      low_temp_process_parm[0].middle_temp = 0x19;
      low_temp_process_parm[0].high_temp = 0x1e;
      low_temp_process_parm[0].delta_vol = 0.2;
      low_temp_process_parm[1].low_temp = 0x1c;
      low_temp_process_parm[1].middle_temp = 0x20;
      low_temp_process_parm[1].high_temp = 0x25;
      low_temp_process_parm[1].delta_vol = 0.2;
    }
    else if (low_temp_process_parm_init::minor_types == PKG_BE) {
      low_temp_process_parm[0].low_temp = 0x17;
      low_temp_process_parm[0].middle_temp = 0x23;
      low_temp_process_parm[0].high_temp = 0x28;
      low_temp_process_parm[0].delta_vol = 0.6;
      low_temp_process_parm[1].low_temp = 0x17;
      low_temp_process_parm[1].middle_temp = 0x23;
      low_temp_process_parm[1].high_temp = 0x28;
      low_temp_process_parm[1].delta_vol = 1.5;
    }
    else {
      low_temp_process_parm[0].low_temp = 0xc;
      low_temp_process_parm[0].middle_temp = 0x18;
      low_temp_process_parm[0].high_temp = 0x1d;
      low_temp_process_parm[0].delta_vol = 0.5;
      low_temp_process_parm[1].low_temp = 0x1c;
      low_temp_process_parm[1].middle_temp = 0x25;
      low_temp_process_parm[1].high_temp = 0x2a;
      low_temp_process_parm[1].delta_vol = 0.3;
    }
  }
  else {
    low_temp_process_parm[0].low_temp = 0x16;
    low_temp_process_parm[0].middle_temp = 0x1a;
    low_temp_process_parm[0].high_temp = 0x1f;
    low_temp_process_parm[0].delta_vol = 1.5;
    low_temp_process_parm[1].low_temp = 0x16;
    low_temp_process_parm[1].middle_temp = 0x1a;
    low_temp_process_parm[1].high_temp = 0x1f;
    low_temp_process_parm[1].delta_vol = 1.7;
  }
  return;
}

