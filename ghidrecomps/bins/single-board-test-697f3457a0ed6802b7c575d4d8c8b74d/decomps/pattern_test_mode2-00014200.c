
int pattern_test_mode2(runtime_base_t *runtime,int freq,int *nonce)

{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int *nonce_local;
  int freq_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int counter_limit;
  int patten_check_interval;
  int is_match;
  int one_patten_bin_len;
  int chainid;
  int counter;
  int which_patten;
  int which_core;
  int which_asic;
  
  iVar4 = runtime->chain_id;
  clear_last_test_results();
  (*runtime->set_ticket_mask)(runtime->chain_status[iVar4].fd,app_conf->ticket_mask);
  usleep(100000);
  (*runtime->set_core_timeout)(runtime->chain_status[iVar4].fd,app_conf->core_timeout);
  usleep(100000);
  (*runtime->set_frequency)(runtime->chain_status[iVar4].fd,freq);
  usleep(100000);
  (*runtime->set_nonce_shift)(runtime->chain_status[iVar4].fd,0,&runtime->nonce_shift);
  iVar4 = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  g_patten.start = 1;
  sleep(1);
  which_asic = 0;
  do {
    if (g_patten.asic_num <= which_asic) {
      g_patten.start = 0;
      *nonce = g_patten.recv_nonces;
      return 0;
    }
    for (which_core = 0; which_core < g_patten.core_num; which_core = which_core + 1) {
      for (which_patten = 0; which_patten < g_patten.patten_num; which_patten = which_patten + 1) {
        pthread_mutex_lock(DAT_00014608);
        g_patten.cur_work =
             g_patten.patten_start +
             iVar4 * which_core * g_patten.patten_num +
             iVar4 * g_patten.patten_num * which_asic * g_patten.core_num + iVar4 * which_patten;
        g_patten.cur_asic = which_asic;
        g_patten.cur_core = which_core;
        g_patten.cur_patten = which_patten;
        pthread_mutex_unlock(DAT_00014608);
        g_patten.cur_work[g_patten.work_bin_len + -1] =
             g_patten.cur_work[g_patten.work_bin_len + -1] + 0xff;
        user_send_work(runtime,g_patten.cur_work,1,0);
        iVar3 = __aeabi_idiv(app_conf->slt_work_interval_ms,0x32);
        counter = 0;
        do {
          usleep(50000);
          pthread_mutex_lock(DAT_00014608);
          uVar2 = g_patten.is_nonce_match
                  [g_patten.cur_patten +
                   g_patten.patten_num * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)
                  ];
          pthread_mutex_unlock(DAT_00014608);
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
    }
    which_asic = which_asic + 1;
  } while( true );
}

