
undefined4 nonce_scanhash(void)

{
  longlong lVar1;
  int iVar2;
  time_t tVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  longlong lVar7;
  undefined auStack_b98 [360];
  char acStack_a30 [1024];
  undefined4 local_630;
  undefined4 local_62c;
  undefined *local_628;
  undefined auStack_624 [136];
  uint uStack_59c;
  undefined auStack_598 [1344];
  byte local_58;
  uint local_50;
  byte local_4c;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_34 = 0;
  local_38 = 0;
  memset(auStack_624,0,0x8c);
  pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
  local_20 = nonce_fifo._8_4_;
  pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
  lVar1 = CONCAT44(t1_8899._4_4_,(undefined4)t1_8899);
  lVar7 = CONCAT44(t0_8898._4_4_,(undefined4)t0_8898);
  while (t0_8898._4_4_ = (undefined4)((ulonglong)lVar7 >> 0x20), t0_8898._0_4_ = (undefined4)lVar7,
        t1_8899._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20), t1_8899._0_4_ = (undefined4)lVar1,
        local_20 != 0) {
    t1_8899 = lVar1;
    t0_8898 = lVar7;
    pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
    local_20 = local_20 + -1;
    nonce_fifo._8_4_ = nonce_fifo._8_4_ + -1;
    memcpy(auStack_598,nonce_fifo + nonce_fifo._4_4_ * 0x54d + 0xc,0x54d);
    pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
    pthread_mutex_lock((pthread_mutex_t *)g_rt_nonce_mutex);
    memcpy(g_rt_nonce,auStack_598,0x54d);
    pthread_mutex_unlock((pthread_mutex_t *)g_rt_nonce_mutex);
    if ((local_4c != 0) &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
      snprintf(acStack_a30,0x400,"Error:scanhash chainid=%u\n",(uint)local_4c);
      _applog(2,acStack_a30,0);
    }
    memcpy(auStack_624,g_work_header,0x8c);
    *(uint *)(auStack_b98 + (0x5fc - g_nonce_shift)) = local_50;
    local_630 = 200;
    local_62c = 9;
    local_628 = auStack_b98;
    digestInit(auStack_b98,200,9);
    blake2b_update(auStack_b98,auStack_624,0x8c,0);
    local_38 = sortValidator(&local_630,auStack_598);
    local_34 = targetValidator(auStack_624,auStack_598);
    if (g_new_work != '\0') {
      memset(one_work_nonce_each_asic,0,0xc);
      memset(one_work_invalid_nonce_each_asic,0,0xc);
      memset(one_work_invalid_nonce_each_asic_2,0,0x18);
      g_new_work = '\0';
      tVar3 = time((time_t *)0x0);
      local_1c = tVar3 + -1;
    }
    if (local_38 == 0) {
      valid_nonce_total = valid_nonce_total + 1;
      submit_nonce = submit_nonce + 1;
      for (local_24 = 0; local_24 < 1; local_24 = local_24 + 1) {
        for (local_28 = 0; local_28 < 3; local_28 = local_28 + 1) {
          uVar4 = __udivsi3(local_58,addr_interval);
          if (uVar4 == local_28) {
            *(int *)(one_work_nonce_each_asic + (local_24 * 3 + local_28) * 4) =
                 *(int *)(one_work_nonce_each_asic + (local_24 * 3 + local_28) * 4) + 1;
            *(int *)(nonce_num_each_asic + (local_24 * 3 + local_28) * 4) =
                 *(int *)(nonce_num_each_asic + (local_24 * 3 + local_28) * 4) + 1;
            if (g_patten._124_4_ != 0) {
              is_patten_match(local_28,&local_50,auStack_598);
            }
            local_3c = cal_avg_hashrate(local_1c,*(undefined4 *)
                                                  (one_work_nonce_each_asic +
                                                  (local_24 * 3 + local_28) * 4));
            local_40 = cal_rt_hashrate(*(undefined4 *)
                                        (one_work_nonce_each_asic + (local_24 * 3 + local_28) * 4),
                                       0x3c);
            local_44 = local_50 << 0x18 | (local_50 >> 8 & 0xff) << 0x10 |
                       (local_50 >> 0x10 & 0xff) << 8 | local_50 >> 0x18;
            local_48 = cal_factor_hashrate(local_44,*(undefined4 *)
                                                     (one_work_nonce_each_asic +
                                                     (local_24 * 3 + local_28) * 4));
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
              snprintf(acStack_a30,0x400,
                       "Success:valid nonce: chainid=%d chipaddr=%02x nonces=%d total=%d tm=%d err=%d avg=%.2f rt=%.2f factor=%.2f\n"
                       ,local_24,(uint)local_58,
                       *(undefined4 *)(one_work_nonce_each_asic + (local_24 * 3 + local_28) * 4),
                       submit_nonce,local_34,local_38);
              _applog(1,acStack_a30,0);
            }
          }
        }
      }
      if ((app_conf._44_4_ == 1) &&
         (uVar4 = target_zero_cal(g_work_info), iVar2 = golden_nonce_8895, uVar4 <= local_34)) {
        bVar6 = 0xfffffffe < (uint)total_8896;
        total_8896._0_4_ = (uint)total_8896 + 1;
        total_8896._4_4_ = total_8896._4_4_ + (uint)bVar6;
        if ((use_syslog != '\0') || ((opt_log_output != '\0' || (2 < opt_log_level)))) {
          golden_nonce_8895 = golden_nonce_8895 + 1;
          snprintf(acStack_a30,0x400,"Golden Nonce Found! %d\n",iVar2);
          _applog(3,acStack_a30,0);
        }
        print_solver_line(auStack_598,auStack_624,g_work_info._428_4_,DAT_0001c320);
        bVar6 = 0xfffffffe < (uint)total_shares_8897;
        total_shares_8897._0_4_ = (uint)total_shares_8897 + 1;
        total_shares_8897._4_4_ = total_shares_8897._4_4_ + (uint)bVar6;
        lVar7 = now();
        uVar4 = (uint)((ulonglong)lVar7 >> 0x20);
        lVar1 = t0_8898 + CONCAT44(status_period_8900._4_4_,(undefined4)status_period_8900);
        uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
        bVar6 = uVar4 <= uVar5;
        if (uVar5 == uVar4) {
          bVar6 = (uint)lVar7 <= (uint)lVar1;
        }
        t1_8899 = lVar7;
        if (!bVar6) {
          t0_8898 = lVar7;
          printf("status: %lld %lld\n",(uint)total_8896,(uint)total_8896,total_8896._4_4_,
                 (uint)total_shares_8897,total_shares_8897._4_4_);
          fflush(stdout);
        }
      }
    }
    else {
      invalid_nonce_total = invalid_nonce_total + 1;
      for (local_2c = 0; local_2c < 1; local_2c = local_2c + 1) {
        for (local_30 = 0; local_30 < 3; local_30 = local_30 + 1) {
          uVar4 = __udivsi3(local_58,addr_interval);
          if (uVar4 == local_30) {
            if (local_38 == 1) {
              *(int *)(nonce_invalid_num_each_asic_2 + (local_2c * 3 + local_30) * 8) =
                   *(int *)(nonce_invalid_num_each_asic_2 + (local_2c * 3 + local_30) * 8) + 1;
              *(int *)(one_work_invalid_nonce_each_asic_2 + (local_2c * 3 + local_30) * 8) =
                   *(int *)(one_work_invalid_nonce_each_asic_2 + (local_2c * 3 + local_30) * 8) + 1;
            }
            else if (local_38 == 2) {
              *(int *)(nonce_invalid_num_each_asic_2 + (local_2c * 3 + local_30) * 8 + 4) =
                   *(int *)(nonce_invalid_num_each_asic_2 + (local_2c * 3 + local_30) * 8 + 4) + 1;
              *(int *)(one_work_invalid_nonce_each_asic_2 + (local_2c * 3 + local_30) * 8 + 4) =
                   *(int *)(one_work_invalid_nonce_each_asic_2 + (local_2c * 3 + local_30) * 8 + 4)
                   + 1;
            }
            *(int *)(one_work_invalid_nonce_each_asic + (local_2c * 3 + local_30) * 4) =
                 *(int *)(one_work_invalid_nonce_each_asic + (local_2c * 3 + local_30) * 4) + 1;
            *(int *)(nonce_invalid_num_each_asic + (local_2c * 3 + local_30) * 4) =
                 *(int *)(nonce_invalid_num_each_asic + (local_2c * 3 + local_30) * 4) + 1;
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
              snprintf(acStack_a30,0x400,
                       "Fail:invalid nonce: chainid=%d chipaddr=%02x nonces=%d tm=%d errtype=%d\n",
                       local_2c,(uint)local_58,
                       *(undefined4 *)
                        (one_work_invalid_nonce_each_asic + (local_2c * 3 + local_30) * 4),local_34,
                       local_38);
              _applog(0,acStack_a30,0);
            }
          }
        }
      }
    }
    dump_str(app_conf._0_4_,0,auStack_624,0x8c);
    pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
    if ((uint)nonce_fifo._4_4_ < 0x1fe) {
      nonce_fifo._4_4_ = nonce_fifo._4_4_ + 1;
    }
    else {
      nonce_fifo._4_4_ = 0;
    }
    pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
    lVar1 = t1_8899;
    lVar7 = t0_8898;
  }
  return 0;
}

