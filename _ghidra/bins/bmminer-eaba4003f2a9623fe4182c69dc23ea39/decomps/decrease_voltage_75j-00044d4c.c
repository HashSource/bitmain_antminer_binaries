
int decrease_voltage_75j(uchar which_chain,int opencore_vol,int target_vol,int step)

{
  int iVar1;
  int step_local;
  int target_vol_local;
  int opencore_vol_local;
  uchar which_chain_local;
  char tmp42 [2048];
  int diff;
  int tmp_vol;
  
  if ((((opencore_vol < 0x6ae) || (0x7d9 < opencore_vol)) || (target_vol < 0x6ae)) ||
     (0x7d9 < target_vol)) {
    if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
      memcpy(tmp42,"error: input vol is not right [1710,2009], restart program please!",0x43);
      _applog(5,tmp42,false);
    }
    iVar1 = -1;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    tmp_vol = opencore_vol;
    while( true ) {
      iVar1 = (tmp_vol - target_vol) / 2;
      tmp_vol = tmp_vol - iVar1;
      sleep(3);
      if (iVar1 < 3) break;
      set_voltage_s11_into_PIC_without_disable(which_chain,tmp_vol);
      printf("the vol is %d...\n",tmp_vol);
    }
    set_voltage_s11_into_PIC_without_disable(which_chain,target_vol);
    printf("the final vol is %d\n",target_vol);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    iVar1 = 0;
  }
  return iVar1;
}

