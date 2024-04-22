
/* WARNING: Unknown calling convention */

void singleboard_pattern_test(void)

{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char tmp42 [1024];
  int offset;
  int is_match;
  int counter_limit;
  int patten_check_interval;
  int one_patten_bin_len;
  int counter;
  int which_patten;
  int which_core;
  int which_asic;
  int i;
  
  iVar4 = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  g_patten.start = 1;
  sleep(1);
  fan_control('\x05');
  which_asic = 0;
  do {
    if (g_patten.asic_num <= which_asic) {
      g_patten.start = 0;
      sleep(1);
      which_asic = 0;
      while( true ) {
        if (g_patten.asic_num <= which_asic) break;
        printf("ASIC %d result:\n",which_asic);
        iVar4 = g_patten.patten_num * which_asic * g_patten.core_num;
        for (i = 0; g_patten.patten_num * g_patten.core_num - i != 0 &&
                    i <= g_patten.patten_num * g_patten.core_num; i = i + 1) {
          if (g_patten.is_nonce_match[i + iVar4] == '\0') {
            uVar5 = 0x58;
          }
          else {
            uVar5 = 0x4f;
          }
          printf("%c ",uVar5);
          if (i % 10 == 9) {
            putchar(10);
          }
        }
        putchar(10);
        which_asic = which_asic + 1;
      }
      return;
    }
    for (which_core = 0; which_core < g_patten.core_num; which_core = which_core + 1) {
      for (which_patten = 0; which_patten < g_patten.patten_num; which_patten = which_patten + 1) {
        if (hardware_exception == 0) {
          pthread_mutex_lock(DAT_00021334);
          g_patten.cur_work =
               g_patten.patten_start +
               iVar4 * which_core * g_patten.patten_num +
               iVar4 * g_patten.patten_num * which_asic * g_patten.core_num + iVar4 * which_patten;
          g_patten.cur_asic = which_asic;
          g_patten.cur_core = which_core;
          g_patten.cur_patten = which_patten;
          pthread_mutex_unlock(DAT_00021334);
          user_send_work(cgpu.runtime,g_patten.cur_work,1,0);
          iVar3 = __aeabi_idiv(app_conf->send_pattern_timeout,50000);
          counter = 0;
          do {
            usleep(50000);
            pthread_mutex_lock(DAT_00021334);
            uVar2 = g_patten.is_nonce_match
                    [g_patten.cur_patten +
                     g_patten.patten_num *
                     (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)];
            pthread_mutex_unlock(DAT_00021334);
            if (uVar2 == '\x01') break;
            bVar1 = counter < iVar3;
            counter = counter + 1;
          } while (bVar1);
          if (uVar2 != '\x01') {
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"pattern id %d receive failed\n",which_patten);
              _applog(2,tmp42,false);
            }
            dump_str(stderr,(char *)0x0,g_patten.cur_work,g_patten.work_bin_len);
          }
        }
        else {
          if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
            snprintf(tmp42,0x400,"%s hardware error\n","singleboard_pattern_test");
            _applog(1,tmp42,false);
          }
          which_patten = g_patten.patten_num;
          which_core = g_patten.core_num;
          which_asic = g_patten.asic_num;
        }
      }
    }
    which_asic = which_asic + 1;
  } while( true );
}

