
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bm1740_combine_one_nonce(int param_1,byte *param_2,byte param_3)

{
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined2 local_110;
  undefined local_10e;
  undefined local_20;
  undefined local_1f;
  int local_1c;
  byte local_16;
  byte local_15;
  int local_14;
  
  local_15 = *param_2 & 0xf;
  local_16 = param_2[3];
  local_14 = 1;
  if ((local_16 == *(byte *)(param_1 + 0x542)) || (retransmit_6460 != 1)) {
    memcpy(g_nonce_list + (uint)local_15 * 0x5b,param_2,0x5b);
    if ((local_15 == 0xf) &&
       (((retransmit_6460 == 0 &&
         (local_14 = bm1740_verify_nonce_integrality(param_1), 0 < local_14)) && (g_txok_en == 1))))
    {
      local_1f = 0;
      local_20 = *(undefined *)(param_1 + 0x540);
      local_1c = local_14;
      midd_ioctl(*(undefined4 *)(g_chain + (uint)param_3 * 0x28),0xc,&local_20);
      retransmit_6460 = 1;
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        local_120._0_1_ = s_enable_retransmit_0002bd24[0];
        local_120._1_1_ = s_enable_retransmit_0002bd24[1];
        local_120._2_1_ = s_enable_retransmit_0002bd24[2];
        local_120._3_1_ = s_enable_retransmit_0002bd24[3];
        uStack_11c._0_1_ = s_enable_retransmit_0002bd24[4];
        uStack_11c._1_1_ = s_enable_retransmit_0002bd24[5];
        uStack_11c._2_1_ = s_enable_retransmit_0002bd24[6];
        uStack_11c._3_1_ = s_enable_retransmit_0002bd24[7];
        uStack_118._0_1_ = s_enable_retransmit_0002bd24[8];
        uStack_118._1_1_ = s_enable_retransmit_0002bd24[9];
        uStack_118._2_1_ = s_enable_retransmit_0002bd24[10];
        uStack_118._3_1_ = s_enable_retransmit_0002bd24[11];
        uStack_114._0_1_ = s_enable_retransmit_0002bd24[12];
        uStack_114._1_1_ = s_enable_retransmit_0002bd24[13];
        uStack_114._2_1_ = s_enable_retransmit_0002bd24[14];
        uStack_114._3_1_ = s_enable_retransmit_0002bd24[15];
        local_110 = (undefined2)ram0x0002bd34;
        local_10e = (undefined)((uint)ram0x0002bd34 >> 0x10);
        _applog(3,&local_120,0);
      }
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      local_120 = s_retransmit____1_0002bd10._0_4_;
      uStack_11c = s_retransmit____1_0002bd10._4_4_;
      uStack_118 = s_retransmit____1_0002bd10._8_4_;
      uStack_114 = s_retransmit____1_0002bd10._12_4_;
      local_110 = CONCAT11(local_110._1_1_,(char)ram0x0002bd20);
      _applog(3,&local_120,0);
    }
    retransmit_6460 = 0;
    local_14 = bm1740_verify_nonce_integrality(param_1);
    memcpy(g_nonce_list + (uint)local_15 * 0x5b,param_2,0x5b);
  }
  return local_14;
}

