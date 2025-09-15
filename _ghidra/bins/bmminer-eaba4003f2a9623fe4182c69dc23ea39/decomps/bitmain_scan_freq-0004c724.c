
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bitmain_scan_freq(void)

{
  _Bool _Var1;
  int iVar2;
  char tmp42 [2048];
  int max_freq;
  int max_freq_index;
  int counter;
  int chain;
  
  puts("===Open Power Supply Output===");
  system("echo 907 > /sys/class/gpio/export");
  system("echo out > /sys/class/gpio/gpio907/direction");
  system("echo 0 > /sys/class/gpio/gpio907/value");
  scanfreq_prepare();
  _Var1 = scanfreq_needed();
  if (!_Var1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      builtin_strncpy(tmp42,"scan freq is not needed\n",0x18);
      tmp42[0x18] = '\0';
      _applog(5,tmp42,false);
    }
    return;
  }
  pthread_create(&receive_id,(pthread_attr_t *)0x0,(__start_routine *)0x490c9,(void *)0x0);
  pthread_detach(receive_id);
  while( true ) {
    memset(core_hash_clock_counter,0xff,0x400000);
    scanfreq_get_next_freq();
    _Var1 = scanfreq_is_all_finished();
    if (_Var1) break;
    iVar2 = scanfreq_get_max_freq_index();
    iVar2 = freq_pll_1393[scanfreq_info.scan_index[iVar2]].freq;
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
        freq_one_board[chain] = (uchar)scanfreq_info.scan_index[scanfreq_info.current_index[chain]];
        freq_one_board_backup[chain] = freq_one_board[chain];
        if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
          snprintf(tmp42,0x800,"\n\nScan frequency Chain[%d], Freq[%dM]\n",chain,
                   freq_pll_1393[freq_one_board[chain]].freq);
          _applog(5,tmp42,false);
        }
      }
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"\n\nMax scan frequency [%dM]\n",iVar2);
      _applog(5,tmp42,false);
    }
    scanfreq_init(iVar2);
    for (counter = 0; counter < 1; counter = counter + 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"\n\nsend counter [%d]\n",counter);
        _applog(5,tmp42,false);
      }
      puts("Reset Rlt");
      scanfreq_reset_result();
      puts("Begin to Send Work");
      pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0x48565,(void *)0x0);
      pthread_join(send_id,(void **)0x0);
      scanfreq_print_nonce_info();
      scanfreq_check_result();
    }
    if (pic_heart_beat != (thr_info *)0x0) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      pthread_cancel(pic_heart_beat->pth);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
    if (read_temp_id != (thr_info *)0x0) {
      pthread_mutex_lock((pthread_mutex_t *)&opencore_readtemp_mutex);
      pthread_cancel(read_temp_id->pth);
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s: cancel thread for read temp\n","bitmain_scan_freq");
        _applog(5,tmp42,false);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&opencore_readtemp_mutex);
    }
  }
  scanfreq_finish();
  do {
    sleep(1);
  } while( true );
}

