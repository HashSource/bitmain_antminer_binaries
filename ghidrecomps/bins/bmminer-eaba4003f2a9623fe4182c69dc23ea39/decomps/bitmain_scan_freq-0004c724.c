
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

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
      tmp42[0] = s_scan_freq_is_not_needed_00078b98[0];
      tmp42[1] = s_scan_freq_is_not_needed_00078b98[1];
      tmp42[2] = s_scan_freq_is_not_needed_00078b98[2];
      tmp42[3] = s_scan_freq_is_not_needed_00078b98[3];
      tmp42[4] = s_scan_freq_is_not_needed_00078b98[4];
      tmp42[5] = s_scan_freq_is_not_needed_00078b98[5];
      tmp42[6] = s_scan_freq_is_not_needed_00078b98[6];
      tmp42[7] = s_scan_freq_is_not_needed_00078b98[7];
      tmp42[8] = s_scan_freq_is_not_needed_00078b98[8];
      tmp42[9] = s_scan_freq_is_not_needed_00078b98[9];
      tmp42[10] = s_scan_freq_is_not_needed_00078b98[10];
      tmp42[11] = s_scan_freq_is_not_needed_00078b98[11];
      tmp42[12] = s_scan_freq_is_not_needed_00078b98[12];
      tmp42[13] = s_scan_freq_is_not_needed_00078b98[13];
      tmp42[14] = s_scan_freq_is_not_needed_00078b98[14];
      tmp42[15] = s_scan_freq_is_not_needed_00078b98[15];
      tmp42[16] = s_scan_freq_is_not_needed_00078b98[16];
      tmp42[17] = s_scan_freq_is_not_needed_00078b98[17];
      tmp42[18] = s_scan_freq_is_not_needed_00078b98[18];
      tmp42[19] = s_scan_freq_is_not_needed_00078b98[19];
      tmp42[20] = s_scan_freq_is_not_needed_00078b98[20];
      tmp42[21] = s_scan_freq_is_not_needed_00078b98[21];
      tmp42[22] = s_scan_freq_is_not_needed_00078b98[22];
      tmp42[23] = s_scan_freq_is_not_needed_00078b98[23];
      tmp42[24] = (char)ram0x00078bb0;
      _applog(5,tmp42,false);
    }
    return;
  }
  pthread_create(&receive_id,(pthread_attr_t *)0x0,scanfreq_receive_nonce_register + 1,(void *)0x0);
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
      pthread_create(&send_id,(pthread_attr_t *)0x0,scanfreq_send_work + 1,(void *)0x0);
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

