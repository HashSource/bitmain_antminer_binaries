
undefined4 nonce_scanhash(void)

{
  longlong lVar1;
  int iVar2;
  time_t tVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  longlong lVar7;
  undefined auStack_b88 [360];
  char acStack_a20 [1024];
  undefined4 local_620;
  undefined4 local_61c;
  undefined *local_618;
  undefined auStack_614 [136];
  undefined4 uStack_58c;
  undefined auStack_588 [1344];
  byte local_48;
  undefined local_47;
  undefined4 local_40;
  byte local_3c;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  
  local_30 = 0;
  local_34 = 0;
  memset(auStack_614,0,0x8c);
  pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
  local_1c = nonce_fifo._8_4_;
  pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
  lVar1 = CONCAT44(t1_8879._4_4_,(undefined4)t1_8879);
  lVar7 = CONCAT44(t0_8878._4_4_,(undefined4)t0_8878);
  while (t0_8878._4_4_ = (undefined4)((ulonglong)lVar7 >> 0x20), t0_8878._0_4_ = (undefined4)lVar7,
        t1_8879._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20), t1_8879._0_4_ = (undefined4)lVar1,
        local_1c != 0) {
    t1_8879 = lVar1;
    t0_8878 = lVar7;
    pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
    local_1c = local_1c + -1;
    nonce_fifo._8_4_ = nonce_fifo._8_4_ + -1;
    memcpy(auStack_588,nonce_fifo + nonce_fifo._4_4_ * 0x54d + 0xc,0x54d);
    pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
    pthread_mutex_lock((pthread_mutex_t *)g_rt_nonce_mutex);
    memcpy(g_rt_nonce,auStack_588,0x54d);
    pthread_mutex_unlock((pthread_mutex_t *)g_rt_nonce_mutex);
    if ((local_3c != 0) &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
      snprintf(acStack_a20,0x400,"Error:scanhash chainid=%u\n",(uint)local_3c);
      _applog(2,acStack_a20,0);
    }
    work_list_find(local_47,auStack_614);
    *(undefined4 *)(auStack_b88 + (0x5fc - g_nonce_shift)) = local_40;
    local_620 = 200;
    local_61c = 9;
    local_618 = auStack_b88;
    digestInit(auStack_b88,200,9);
    blake2b_update(auStack_b88,auStack_614,0x8c,0);
    local_34 = sortValidator(&local_620,auStack_588);
    local_30 = targetValidator(auStack_614,auStack_588);
    if (g_new_work != '\0') {
      memset(one_work_nonce_each_asic,0,0xc);
      memset(one_work_invalid_nonce_each_asic,0,0xc);
      memset(one_work_invalid_nonce_each_asic_2,0,0x18);
      g_new_work = '\0';
      tVar3 = time((time_t *)0x0);
      local_38 = tVar3 + -1;
    }
    if (local_34 == 0) {
      valid_nonce_total = valid_nonce_total + 1;
      submit_nonce = submit_nonce + 1;
      for (local_20 = 0; local_20 < 1; local_20 = local_20 + 1) {
        for (local_24 = 0; local_24 < 3; local_24 = local_24 + 1) {
          uVar4 = __udivsi3(local_48,addr_interval);
          if (uVar4 == local_24) {
            *(int *)(one_work_nonce_each_asic + (local_20 * 3 + local_24) * 4) =
                 *(int *)(one_work_nonce_each_asic + (local_20 * 3 + local_24) * 4) + 1;
            *(int *)(nonce_num_each_asic + (local_20 * 3 + local_24) * 4) =
                 *(int *)(nonce_num_each_asic + (local_20 * 3 + local_24) * 4) + 1;
            if (g_patten._128_4_ != 0) {
              is_patten_match(local_24,&local_40,auStack_588);
            }
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
              snprintf(acStack_a20,0x400,
                       "Success:valid nonce: chainid=%d chipaddr=%02x nonces=%d total=%d tm=%d err=%d\n"
                       ,local_20,(uint)local_48,
                       *(undefined4 *)(one_work_nonce_each_asic + (local_20 * 3 + local_24) * 4),
                       submit_nonce,local_30,local_34);
              _applog(1,acStack_a20,0);
            }
          }
        }
      }
      if ((app_conf._44_4_ == 1) &&
         (uVar4 = target_zero_cal(g_work_info), iVar2 = golden_nonce_8875, uVar4 <= local_30)) {
        bVar6 = 0xfffffffe < (uint)total_8876;
        total_8876._0_4_ = (uint)total_8876 + 1;
        total_8876._4_4_ = total_8876._4_4_ + (uint)bVar6;
        if ((use_syslog != '\0') || ((opt_log_output != '\0' || (2 < opt_log_level)))) {
          golden_nonce_8875 = golden_nonce_8875 + 1;
          snprintf(acStack_a20,0x400,"Golden Nonce Found! %d\n",iVar2);
          _applog(3,acStack_a20,0);
        }
        print_solver_line(auStack_588,auStack_614,g_work_info._428_4_,DAT_0001bcc4);
        bVar6 = 0xfffffffe < (uint)total_shares_8877;
        total_shares_8877._0_4_ = (uint)total_shares_8877 + 1;
        total_shares_8877._4_4_ = total_shares_8877._4_4_ + (uint)bVar6;
        lVar7 = now();
        uVar4 = (uint)((ulonglong)lVar7 >> 0x20);
        lVar1 = t0_8878 + CONCAT44(status_period_8880._4_4_,(undefined4)status_period_8880);
        uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
        bVar6 = uVar4 <= uVar5;
        if (uVar5 == uVar4) {
          bVar6 = (uint)lVar7 <= (uint)lVar1;
        }
        t1_8879 = lVar7;
        if (!bVar6) {
          t0_8878 = lVar7;
          printf("status: %lld %lld\n",(uint)total_8876,(uint)total_8876,total_8876._4_4_,
                 (uint)total_shares_8877,total_shares_8877._4_4_);
          fflush(stdout);
        }
      }
    }
    else {
      invalid_nonce_total = invalid_nonce_total + 1;
      for (local_28 = 0; local_28 < 1; local_28 = local_28 + 1) {
        for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
          uVar4 = __udivsi3(local_48,addr_interval);
          if (uVar4 == local_2c) {
            if (local_34 == 1) {
              *(int *)(nonce_invalid_num_each_asic_2 + (local_28 * 3 + local_2c) * 8) =
                   *(int *)(nonce_invalid_num_each_asic_2 + (local_28 * 3 + local_2c) * 8) + 1;
              *(int *)(one_work_invalid_nonce_each_asic_2 + (local_28 * 3 + local_2c) * 8) =
                   *(int *)(one_work_invalid_nonce_each_asic_2 + (local_28 * 3 + local_2c) * 8) + 1;
            }
            else if (local_34 == 2) {
              *(int *)(nonce_invalid_num_each_asic_2 + (local_28 * 3 + local_2c) * 8 + 4) =
                   *(int *)(nonce_invalid_num_each_asic_2 + (local_28 * 3 + local_2c) * 8 + 4) + 1;
              *(int *)(one_work_invalid_nonce_each_asic_2 + (local_28 * 3 + local_2c) * 8 + 4) =
                   *(int *)(one_work_invalid_nonce_each_asic_2 + (local_28 * 3 + local_2c) * 8 + 4)
                   + 1;
            }
            *(int *)(one_work_invalid_nonce_each_asic + (local_28 * 3 + local_2c) * 4) =
                 *(int *)(one_work_invalid_nonce_each_asic + (local_28 * 3 + local_2c) * 4) + 1;
            *(int *)(nonce_invalid_num_each_asic + (local_28 * 3 + local_2c) * 4) =
                 *(int *)(nonce_invalid_num_each_asic + (local_28 * 3 + local_2c) * 4) + 1;
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
              snprintf(acStack_a20,0x400,
                       "Fail:invalid nonce: chainid=%d chipaddr=%02x nonces=%d tm=%d errtype=%d\n",
                       local_28,(uint)local_48,
                       *(undefined4 *)
                        (one_work_invalid_nonce_each_asic + (local_28 * 3 + local_2c) * 4),local_30,
                       local_34);
              _applog(0,acStack_a20,0);
            }
          }
        }
      }
    }
    dump_str(app_conf._0_4_,0,auStack_614,0x8c);
    dump_str(app_conf._0_4_,0,auStack_588,0x540);
    pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
    if ((uint)nonce_fifo._4_4_ < 0x1fe) {
      nonce_fifo._4_4_ = nonce_fifo._4_4_ + 1;
    }
    else {
      nonce_fifo._4_4_ = 0;
    }
    pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
    lVar1 = t1_8879;
    lVar7 = t0_8878;
  }
  return 0;
}

