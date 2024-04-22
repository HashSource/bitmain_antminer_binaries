
/* WARNING: Unknown calling convention */

void * check_system_work(void)

{
  all_parameters *paVar1;
  int iVar2;
  undefined4 uVar3;
  char tmp42 [2048];
  timeval diff;
  char logstr [1024];
  timeval tv_reboot_start;
  timeval tv_reboot;
  timeval tv_end;
  timeval tv_start;
  int error_asic;
  int offset;
  int run_counter;
  int avg_num;
  int asic_num;
  int j;
  int i;
  
  cgtime(&tv_end);
  cgtime(&tv_reboot);
  copy_time(&tv_start,&tv_end);
  copy_time(&tv_reboot_start,&tv_reboot);
  run_counter = 0;
  do {
    while (doTestPatten != false) {
      cgsleep_ms(100);
    }
    cgtime(&tv_end);
    cgtime(&tv_reboot);
    diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    if (tv_end.tv_usec - tv_start.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
    }
    if ((0x3c < diff.tv_sec) || ((global_stop != false && (0x1e < diff.tv_sec)))) {
      run_counter = run_counter + 1;
      asic_num = 0;
      avg_num = 0;
      for (i = 0; i < 0x10; i = i + 1) {
        if (dev->chain_exist[i] != 0) {
          asic_num = asic_num + (uint)dev->chain_asic_num[i];
          for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
            iVar2 = nonce_times % 0x3c;
            uVar3 = *(undefined4 *)((int)dev->chain_asic_nonce[i] + j * 8 + 4);
            *(undefined4 *)(nonce_num[i][j] + iVar2) = *(undefined4 *)(dev->chain_asic_nonce[i] + j)
            ;
            *(undefined4 *)((int)nonce_num[i][j] + iVar2 * 8 + 4) = uVar3;
            avg_num = *(int *)(dev->chain_asic_nonce[i] + j) + avg_num;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: chain %d asic %d asic_nonce_num %d","check_system_work",i,j,
                       *(undefined4 *)(dev->chain_asic_nonce[i] + j),
                       *(undefined4 *)((int)dev->chain_asic_nonce[i] + j * 8 + 4));
              _applog(7,tmp42,false);
            }
          }
        }
      }
      nonce_times = nonce_times + 1;
      memset(nonce_num10_string,0,0x1000);
      memset(nonce_num30_string,0,0x1000);
      memset(nonce_num60_string,0,0x1000);
      get_lastn_nonce_num(nonce_num10_string,10);
      get_lastn_nonce_num(nonce_num30_string,0x1e);
      get_lastn_nonce_num(nonce_num60_string,0x3c);
      if (asic_num != 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: avg_num %d asic_num %d","check_system_work",avg_num,asic_num);
          _applog(7,tmp42,false);
        }
        __aeabi_idiv(avg_num,asic_num);
      }
      for (i = 0; i < 0x10; i = i + 1) {
        if (dev->chain_exist[i] != 0) {
          offset = 0;
          for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
            if ((j & 7U) == 0) {
              dev->chain_asic_status_string[i][j + offset] = ' ';
              offset = offset + 1;
            }
            iVar2 = get_asic_nonce_num(i,j,1);
            if (iVar2 < 2) {
              dev->chain_asic_status_string[i][j + offset] = 'o';
              if (status_error != true) {
                x_time[i][j] = x_time[i][j] + 1;
              }
            }
            else {
              dev->chain_asic_status_string[i][j + offset] = 'o';
            }
            paVar1 = dev;
            *(undefined4 *)(dev->chain_asic_nonce[i] + j) = 0;
            *(undefined4 *)((int)paVar1->chain_asic_nonce[i] + j * 8 + 4) = 0;
          }
          dev->chain_asic_status_string[i][j + offset] = '\0';
        }
      }
      if (0x3c < run_counter) {
        run_counter = 0;
      }
      copy_time(&tv_start,&tv_end);
    }
    cgsleep_ms(1000);
  } while( true );
}

