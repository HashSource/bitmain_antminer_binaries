
/* WARNING: Unknown calling convention */

void reopen_once(void)

{
  FILE *__stream;
  int fan_pwm;
  FILE *pFile;
  int chain;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,
              "%s:%d:%s: in normal environment temperature, start reopen for hash rate loss",
              "driver-btm-soc.c",0xd78,"reopen_once");
    }
    fclose(__stream);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      fan_pwm = get_reopen_pwm();
      re_open_core_by_chain(fan_pwm,chain,false);
      sleep(0x1e);
      reCalculateAVG();
      recalc_hashrate();
    }
  }
  return;
}

