
undefined4 bm1740_handle_nonce(void *param_1)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  char acStack_8f8 [100];
  char acStack_894 [256];
  undefined4 local_794;
  undefined4 local_790;
  undefined *local_78c;
  undefined auStack_788 [364];
  undefined auStack_61c [1344];
  undefined auStack_dc [116];
  undefined auStack_68 [24];
  undefined8 local_50;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  memset(auStack_dc,0,0x8c);
  memset(auStack_61c,0,0x540);
  local_38 = 0;
  memcpy(auStack_dc,g_test_header,0x8c);
  memcpy(auStack_68,(void *)((int)param_1 + 0x548),4);
  memcpy(auStack_61c,param_1,0x540);
  local_794 = 200;
  local_790 = 9;
  local_78c = auStack_788;
  digestInit(auStack_788,200,9);
  blake2b_update(auStack_788,auStack_dc,0x8c,0);
  local_3c = now();
  local_38 = sortValidator(&local_794,auStack_61c);
  local_40 = now();
  local_44 = targetValidator(auStack_dc,auStack_61c);
  if ((local_38 != 0) || (local_44 < g_tm)) {
    printf("valid = %d, ticket mask=%d\n",local_38,local_44);
    return 0;
  }
  printf("receive a valid nonce tm=%d\n",local_44);
  asic_nonce_6391 = asic_nonce_6391 + 1;
  local_50 = now();
  uVar2 = (uint)((ulonglong)(local_50 - time_first_6394) >> 0x20);
  bVar3 = uVar2 <= DAT_000130d4;
  if (DAT_000130d4 == uVar2) {
    bVar3 = (uint)(local_50 - time_first_6394) <= DAT_000130d0;
  }
  if (!bVar3) {
    time_first_6394 = local_50;
    *(int *)(asic_nonce_table_6392 + k_6393 * 4) = asic_nonce_6391;
    k_6393 = k_6393 + 1;
    if (9 < k_6393) {
      k_6393 = 0;
    }
    memset(acStack_8f8,0,100);
    sprintf(acStack_8f8,"hashrate-table:%d %d %d %d %d %d %d %d %d %d",asic_nonce_table_6392._0_4_,
            asic_nonce_table_6392._4_4_,asic_nonce_table_6392._8_4_,asic_nonce_table_6392._12_4_,
            asic_nonce_table_6392._16_4_,asic_nonce_table_6392._20_4_,asic_nonce_table_6392._24_4_,
            asic_nonce_table_6392._28_4_,asic_nonce_table_6392._32_4_,asic_nonce_table_6392._36_4_);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_894,0x100,"%s\n",acStack_8f8);
      _applog(3,acStack_894,0);
    }
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_894,0x100,"cpu calcute diff time = %d\n",local_40 - local_3c);
      _applog(3,acStack_894,0);
    }
    asic_nonce_6391 = 0;
  }
  for (local_24 = 0; local_24 < 1; local_24 = local_24 + 1) {
    for (local_28 = 0; local_28 < 4; local_28 = local_28 + 1) {
      if ((uint)*(byte *)((int)param_1 + 0x540) == addr_interval * local_28) {
        *(int *)(&nonce_num_each_asic + (local_24 * 4 + local_28) * 4) =
             *(int *)(&nonce_num_each_asic + (local_24 * 4 + local_28) * 4) + 1;
      }
    }
  }
  local_2c = 0;
  local_30 = 0;
  lVar1 = time_first_6394;
  while( true ) {
    time_first_6394._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
    time_first_6394._0_4_ = (undefined4)lVar1;
    if (0 < local_30) break;
    for (local_34 = 0; local_34 < 4; local_34 = local_34 + 1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        time_first_6394 = lVar1;
        snprintf(acStack_894,0x100,"receive a valid chainid=%d asicid=%d nonce=%d\n",local_30,
                 local_34,*(undefined4 *)(&nonce_num_each_asic + (local_30 * 4 + local_34) * 4));
        _applog(0,acStack_894,0);
        lVar1 = time_first_6394;
      }
      if (5 < *(uint *)(&nonce_num_each_asic + (local_30 * 4 + local_34) * 4)) {
        local_2c = local_2c + 1;
      }
    }
    local_30 = local_30 + 1;
  }
  if (local_2c < 4) {
    return 0;
  }
  nonce_ok = 1;
  return 0;
}

