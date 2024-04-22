
/* WARNING: Unknown calling convention */

void switch_to_mode0(void)

{
  FILE *__stream;
  int fan_pwm;
  FILE *pFile;
  int chain;
  
  g_pulse_mode = '\0';
  for (chain = 0; chain < (int)(uint)dev->chain_num; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: \n\nswitch chain %d\n","driver-btm-soc.c",0xcc3,
                  "switch_to_mode0",chain);
        }
        fclose(__stream);
      }
      fan_pwm = get_reopen_pwm();
      re_open_core_by_chain(fan_pwm,chain,false);
      sleep(0x3c);
    }
  }
  return;
}

