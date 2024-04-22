
void get_asic_sweep_stat(char *infoStr)

{
  char *infoStr_local;
  
  sprintf(infoStr,"%d %d %d",(uint)sweep_failed_few_succeed_freq,(uint)sweep_failed_base_freq,
          (uint)sweep_failed_middle_freq);
  return;
}

