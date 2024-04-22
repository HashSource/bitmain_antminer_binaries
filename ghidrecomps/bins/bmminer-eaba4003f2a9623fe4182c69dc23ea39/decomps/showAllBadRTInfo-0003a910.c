
/* WARNING: Unknown calling convention */

void showAllBadRTInfo(void)

{
  double dVar1;
  char tmp42 [2048];
  char logstr [1024];
  int j;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Check Chain[J%d] ASIC RT error: (asic index start from 1-%d)\n",i + 1,
                 0x6c);
        _applog(5,tmp42,false);
      }
      for (j = 0; j < 0x6c; j = j + 1) {
        dVar1 = chain_asic_RT[i][j];
        if ((dVar1 != DAT_0003aa70 && dVar1 < DAT_0003aa70 == (NAN(dVar1) || NAN(DAT_0003aa70))) &&
           (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Asic[%02d]=%f\n",j + 1,*(undefined4 *)(chain_asic_RT[i] + j),
                   *(undefined4 *)((int)chain_asic_RT[i] + j * 8 + 4));
          _applog(5,tmp42,false);
        }
      }
    }
  }
  return;
}

