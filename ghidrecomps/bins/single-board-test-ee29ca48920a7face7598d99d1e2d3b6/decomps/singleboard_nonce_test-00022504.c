
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void singleboard_nonce_test(void)

{
  int iVar1;
  undefined4 local_87c;
  undefined4 uStack_878;
  undefined4 uStack_874;
  undefined4 uStack_870;
  undefined4 local_86c;
  undefined4 local_868;
  undefined local_864;
  undefined auStack_47c [281];
  undefined auStack_363 [281];
  undefined auStack_24a [281];
  undefined auStack_131 [281];
  int local_18;
  int local_14;
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_87c = s_Begin_Nonce_Test____00034860._0_4_;
    uStack_878 = s_Begin_Nonce_Test____00034860._4_4_;
    uStack_874 = s_Begin_Nonce_Test____00034860._8_4_;
    uStack_870 = s_Begin_Nonce_Test____00034860._12_4_;
    local_86c = s_Begin_Nonce_Test____00034860._16_4_;
    local_868._0_1_ = (char)ram0x00034874;
    _applog(2,&local_87c,0);
  }
  memset(auStack_47c,0,0x464);
  memcpy(auStack_131,
         "040000005a0995c5fe39ee678b290a2636ec3c32e26bfafb5711ee687ad3750e00000000bbd08c45cf29d96c4f1e5b9d136f2f0ffc22d6be511e204773afee519a2478db00000000000000000000000000000000000000000000000000000000000000008dc7205ab0f0131c0000000000000000aaaaad5327c5d2a66bda09d1000000000000000000000000"
         ,0x118);
  memcpy(auStack_47c,
         "010203042cb3d32b0b61304401cbe540448a4cacd7e98421a850503e2f0d102f1d3454151484151215484aa0ca1932037525e2eb9a22d3d3ff1502b320f8d9ca56377f56494b2cacf3377482ccd34188c1b25e04187ccf70af6e2244c3c96e5e2e3a6015d32fe451ad000e771eccb5c5e3d6beb470359446494d25e15f87df87c3119ebd9ca813a400000000"
         ,0x118);
  memcpy(auStack_24a,
         "0400000065747d1d1299b3422670ee656f86aa07d5dfefc485c2d2206304e6030000000067669e8d830bc95a3a2b88582f06f835ecfcfe85c92af15d001376fb544a3db40000000000000000000000000000000000000000000000000000000000000000ee060c5ba21f0f1c4809000000000000000000000000000000000400000000000000000000000000"
         ,0x118);
  memcpy(auStack_363,
         "04000000a250abe4ab99767ec31b0eec43786781bf556a27b99436d831ff8e020000000002f24739336a89e32ee1081592a1d2ebbf1321c9484789cf04d3234ad531c3d80000000000000000000000000000000000000000000000000000000000000000abe6ea5add990f1cf408000000000000cda79db66d4176ca36d5ad06000000000000000000000000"
         ,0x118);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_87c._0_1_ = s_pre_sending_work_begin_00034ce8[0];
    local_87c._1_1_ = s_pre_sending_work_begin_00034ce8[1];
    local_87c._2_1_ = s_pre_sending_work_begin_00034ce8[2];
    local_87c._3_1_ = s_pre_sending_work_begin_00034ce8[3];
    uStack_878._0_1_ = s_pre_sending_work_begin_00034ce8[4];
    uStack_878._1_1_ = s_pre_sending_work_begin_00034ce8[5];
    uStack_878._2_1_ = s_pre_sending_work_begin_00034ce8[6];
    uStack_878._3_1_ = s_pre_sending_work_begin_00034ce8[7];
    uStack_874._0_1_ = s_pre_sending_work_begin_00034ce8[8];
    uStack_874._1_1_ = s_pre_sending_work_begin_00034ce8[9];
    uStack_874._2_1_ = s_pre_sending_work_begin_00034ce8[10];
    uStack_874._3_1_ = s_pre_sending_work_begin_00034ce8[11];
    uStack_870._0_1_ = s_pre_sending_work_begin_00034ce8[12];
    uStack_870._1_1_ = s_pre_sending_work_begin_00034ce8[13];
    uStack_870._2_1_ = s_pre_sending_work_begin_00034ce8[14];
    uStack_870._3_1_ = s_pre_sending_work_begin_00034ce8[15];
    local_86c._0_1_ = s_pre_sending_work_begin_00034ce8[16];
    local_86c._1_1_ = s_pre_sending_work_begin_00034ce8[17];
    local_86c._2_1_ = s_pre_sending_work_begin_00034ce8[18];
    local_86c._3_1_ = s_pre_sending_work_begin_00034ce8[19];
    local_868._0_1_ = s_pre_sending_work_begin_00034ce8[20];
    local_868._1_1_ = s_pre_sending_work_begin_00034ce8[21];
    local_868._2_1_ = s_pre_sending_work_begin_00034ce8[22];
    local_868._3_1_ = s_pre_sending_work_begin_00034ce8[23];
    _applog(2,&local_87c,0);
  }
  send_work(auStack_47c,0,0);
  sleep(5);
  show_nonce_detail();
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_87c._0_1_ = s_pre_sending_work_end_00034d00[0];
    local_87c._1_1_ = s_pre_sending_work_end_00034d00[1];
    local_87c._2_1_ = s_pre_sending_work_end_00034d00[2];
    local_87c._3_1_ = s_pre_sending_work_end_00034d00[3];
    uStack_878._0_1_ = s_pre_sending_work_end_00034d00[4];
    uStack_878._1_1_ = s_pre_sending_work_end_00034d00[5];
    uStack_878._2_1_ = s_pre_sending_work_end_00034d00[6];
    uStack_878._3_1_ = s_pre_sending_work_end_00034d00[7];
    uStack_874._0_1_ = s_pre_sending_work_end_00034d00[8];
    uStack_874._1_1_ = s_pre_sending_work_end_00034d00[9];
    uStack_874._2_1_ = s_pre_sending_work_end_00034d00[10];
    uStack_874._3_1_ = s_pre_sending_work_end_00034d00[11];
    uStack_870._0_1_ = s_pre_sending_work_end_00034d00[12];
    uStack_870._1_1_ = s_pre_sending_work_end_00034d00[13];
    uStack_870._2_1_ = s_pre_sending_work_end_00034d00[14];
    uStack_870._3_1_ = s_pre_sending_work_end_00034d00[15];
    local_86c._0_1_ = s_pre_sending_work_end_00034d00[16];
    local_86c._1_1_ = s_pre_sending_work_end_00034d00[17];
    local_86c._2_1_ = s_pre_sending_work_end_00034d00[18];
    local_86c._3_1_ = s_pre_sending_work_end_00034d00[19];
    local_868._0_2_ = (short)ram0x00034d14;
    _applog(2,&local_87c,0);
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_87c._0_1_ = s_normal_send_work_begin_00034d18[0];
    local_87c._1_1_ = s_normal_send_work_begin_00034d18[1];
    local_87c._2_1_ = s_normal_send_work_begin_00034d18[2];
    local_87c._3_1_ = s_normal_send_work_begin_00034d18[3];
    uStack_878._0_1_ = s_normal_send_work_begin_00034d18[4];
    uStack_878._1_1_ = s_normal_send_work_begin_00034d18[5];
    uStack_878._2_1_ = s_normal_send_work_begin_00034d18[6];
    uStack_878._3_1_ = s_normal_send_work_begin_00034d18[7];
    uStack_874._0_1_ = s_normal_send_work_begin_00034d18[8];
    uStack_874._1_1_ = s_normal_send_work_begin_00034d18[9];
    uStack_874._2_1_ = s_normal_send_work_begin_00034d18[10];
    uStack_874._3_1_ = s_normal_send_work_begin_00034d18[11];
    uStack_870._0_1_ = s_normal_send_work_begin_00034d18[12];
    uStack_870._1_1_ = s_normal_send_work_begin_00034d18[13];
    uStack_870._2_1_ = s_normal_send_work_begin_00034d18[14];
    uStack_870._3_1_ = s_normal_send_work_begin_00034d18[15];
    local_86c._0_1_ = s_normal_send_work_begin_00034d18[16];
    local_86c._1_1_ = s_normal_send_work_begin_00034d18[17];
    local_86c._2_1_ = s_normal_send_work_begin_00034d18[18];
    local_86c._3_1_ = s_normal_send_work_begin_00034d18[19];
    local_868._0_1_ = s_normal_send_work_begin_00034d18[20];
    local_868._1_1_ = s_normal_send_work_begin_00034d18[21];
    local_868._2_1_ = s_normal_send_work_begin_00034d18[22];
    local_868._3_1_ = s_normal_send_work_begin_00034d18[23];
    local_864 = (undefined)ram0x00034d30;
    _applog(2,&local_87c,0);
  }
  send_work(auStack_47c,0,0);
  local_14 = app_conf._372_4_;
  while (iVar1 = local_14 + -1, local_14 != 0) {
    local_14 = iVar1;
    sleep(1);
    show_nonce_detail();
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (local_14 = iVar1, 1 < opt_log_level)) {
    local_87c._0_1_ = s_normal_send_work_end_00034d34[0];
    local_87c._1_1_ = s_normal_send_work_end_00034d34[1];
    local_87c._2_1_ = s_normal_send_work_end_00034d34[2];
    local_87c._3_1_ = s_normal_send_work_end_00034d34[3];
    uStack_878._0_1_ = s_normal_send_work_end_00034d34[4];
    uStack_878._1_1_ = s_normal_send_work_end_00034d34[5];
    uStack_878._2_1_ = s_normal_send_work_end_00034d34[6];
    uStack_878._3_1_ = s_normal_send_work_end_00034d34[7];
    uStack_874._0_1_ = s_normal_send_work_end_00034d34[8];
    uStack_874._1_1_ = s_normal_send_work_end_00034d34[9];
    uStack_874._2_1_ = s_normal_send_work_end_00034d34[10];
    uStack_874._3_1_ = s_normal_send_work_end_00034d34[11];
    uStack_870._0_1_ = s_normal_send_work_end_00034d34[12];
    uStack_870._1_1_ = s_normal_send_work_end_00034d34[13];
    uStack_870._2_1_ = s_normal_send_work_end_00034d34[14];
    uStack_870._3_1_ = s_normal_send_work_end_00034d34[15];
    local_86c._0_1_ = s_normal_send_work_end_00034d34[16];
    local_86c._1_1_ = s_normal_send_work_end_00034d34[17];
    local_86c._2_1_ = s_normal_send_work_end_00034d34[18];
    local_86c._3_1_ = s_normal_send_work_end_00034d34[19];
    local_868._0_3_ = (undefined3)ram0x00034d48;
    local_14 = iVar1;
    _applog(2,&local_87c,0);
  }
  for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
    if ((*(uint *)(one_work_nonce_each_asic + ((uint)gChain * 3 + local_18) * 4) <
         (uint)app_conf._376_4_) ||
       ((uint)app_conf._380_4_ <
        *(uint *)(one_work_invalid_nonce_each_asic_2 + ((uint)gChain * 3 + local_18) * 8 + 4))) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf((char *)&local_87c,0x400,"error: asic%d valid [%d   %d], invalid[%d   %d]\n",
                 local_18,*(undefined4 *)
                           (one_work_nonce_each_asic + ((uint)gChain * 3 + local_18) * 4),
                 app_conf._376_4_,
                 *(undefined4 *)
                  (one_work_invalid_nonce_each_asic_2 + ((uint)gChain * 3 + local_18) * 8 + 4),
                 app_conf._380_4_);
        _applog(2,&local_87c,0);
      }
      *(undefined *)((int)&nonce_test_asic_result + local_18) = 0x58;
    }
    else {
      if ((use_syslog != '\0') || ((opt_log_output != '\0' || (1 < opt_log_level)))) {
        snprintf((char *)&local_87c,0x400,"pass : asic%d valid [%d   %d], invalid[%d   %d]\n",
                 local_18,*(undefined4 *)
                           (one_work_nonce_each_asic + ((uint)gChain * 3 + local_18) * 4),
                 app_conf._376_4_,
                 *(undefined4 *)
                  (one_work_invalid_nonce_each_asic_2 + ((uint)gChain * 3 + local_18) * 8 + 4),
                 app_conf._380_4_);
        _applog(2,&local_87c,0);
      }
      *(undefined *)((int)&nonce_test_asic_result + local_18) = 0x4f;
    }
  }
  return;
}

