
/* WARNING: Unknown calling convention */

void scanfreq_check_asic_num(void)

{
  char tmp42 [2048];
  int retry_count;
  int i;
  
  check_asic_reg(0);
  cgsleep_ms(10);
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      retry_count = 0;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Chain[J%d] has %d asic\n",i,(uint)dev->chain_asic_num[i]);
        _applog(5,tmp42,false);
      }
      for (; (dev->chain_asic_num[i] != 'l' && (retry_count < 6)); retry_count = retry_count + 1) {
        dev->chain_asic_num[i] = '\0';
        set_reset_hashboard(i,1);
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        dsPIC33EP16GS202_enable_pic_dc_dc((uchar)i,'\0');
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        sleep(1);
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        dsPIC33EP16GS202_enable_pic_dc_dc((uchar)i,'\x01');
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        sleep(2);
        set_reset_hashboard(i,0);
        sleep(1);
        check_asic_reg_oneChain(i,0);
        if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
          snprintf(tmp42,0x800,"retry Chain[J%d] has %d asic\n",i,(uint)dev->chain_asic_num[i]);
          _applog(5,tmp42,false);
        }
      }
      if (dev->chain_asic_num[i] == '\0') {
        dev->chain_exist[i] = 0;
      }
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] != 0) &&
       (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Chain%d has %d ASICs",i + 1,(uint)dev->chain_asic_num[i]);
      _applog(5,tmp42,false);
    }
  }
  return;
}

