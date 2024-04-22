
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
    local_87c = s_Begin_Nonce_Test____000343ac._0_4_;
    uStack_878 = s_Begin_Nonce_Test____000343ac._4_4_;
    uStack_874 = s_Begin_Nonce_Test____000343ac._8_4_;
    uStack_870 = s_Begin_Nonce_Test____000343ac._12_4_;
    local_86c = s_Begin_Nonce_Test____000343ac._16_4_;
    local_868._0_1_ = (char)ram0x000343c0;
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
    local_87c._0_1_ = s_pre_sending_work_begin_00034834[0];
    local_87c._1_1_ = s_pre_sending_work_begin_00034834[1];
    local_87c._2_1_ = s_pre_sending_work_begin_00034834[2];
    local_87c._3_1_ = s_pre_sending_work_begin_00034834[3];
    uStack_878._0_1_ = s_pre_sending_work_begin_00034834[4];
    uStack_878._1_1_ = s_pre_sending_work_begin_00034834[5];
    uStack_878._2_1_ = s_pre_sending_work_begin_00034834[6];
    uStack_878._3_1_ = s_pre_sending_work_begin_00034834[7];
    uStack_874._0_1_ = s_pre_sending_work_begin_00034834[8];
    uStack_874._1_1_ = s_pre_sending_work_begin_00034834[9];
    uStack_874._2_1_ = s_pre_sending_work_begin_00034834[10];
    uStack_874._3_1_ = s_pre_sending_work_begin_00034834[11];
    uStack_870._0_1_ = s_pre_sending_work_begin_00034834[12];
    uStack_870._1_1_ = s_pre_sending_work_begin_00034834[13];
    uStack_870._2_1_ = s_pre_sending_work_begin_00034834[14];
    uStack_870._3_1_ = s_pre_sending_work_begin_00034834[15];
    local_86c._0_1_ = s_pre_sending_work_begin_00034834[16];
    local_86c._1_1_ = s_pre_sending_work_begin_00034834[17];
    local_86c._2_1_ = s_pre_sending_work_begin_00034834[18];
    local_86c._3_1_ = s_pre_sending_work_begin_00034834[19];
    local_868._0_1_ = s_pre_sending_work_begin_00034834[20];
    local_868._1_1_ = s_pre_sending_work_begin_00034834[21];
    local_868._2_1_ = s_pre_sending_work_begin_00034834[22];
    local_868._3_1_ = s_pre_sending_work_begin_00034834[23];
    _applog(2,&local_87c,0);
  }
  send_work(auStack_47c,0,0);
  sleep(5);
  show_nonce_detail();
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_87c._0_1_ = s_pre_sending_work_end_0003484c[0];
    local_87c._1_1_ = s_pre_sending_work_end_0003484c[1];
    local_87c._2_1_ = s_pre_sending_work_end_0003484c[2];
    local_87c._3_1_ = s_pre_sending_work_end_0003484c[3];
    uStack_878._0_1_ = s_pre_sending_work_end_0003484c[4];
    uStack_878._1_1_ = s_pre_sending_work_end_0003484c[5];
    uStack_878._2_1_ = s_pre_sending_work_end_0003484c[6];
    uStack_878._3_1_ = s_pre_sending_work_end_0003484c[7];
    uStack_874._0_1_ = s_pre_sending_work_end_0003484c[8];
    uStack_874._1_1_ = s_pre_sending_work_end_0003484c[9];
    uStack_874._2_1_ = s_pre_sending_work_end_0003484c[10];
    uStack_874._3_1_ = s_pre_sending_work_end_0003484c[11];
    uStack_870._0_1_ = s_pre_sending_work_end_0003484c[12];
    uStack_870._1_1_ = s_pre_sending_work_end_0003484c[13];
    uStack_870._2_1_ = s_pre_sending_work_end_0003484c[14];
    uStack_870._3_1_ = s_pre_sending_work_end_0003484c[15];
    local_86c._0_1_ = s_pre_sending_work_end_0003484c[16];
    local_86c._1_1_ = s_pre_sending_work_end_0003484c[17];
    local_86c._2_1_ = s_pre_sending_work_end_0003484c[18];
    local_86c._3_1_ = s_pre_sending_work_end_0003484c[19];
    local_868._0_2_ = (short)ram0x00034860;
    _applog(2,&local_87c,0);
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_87c._0_1_ = s_normal_send_work_begin_00034864[0];
    local_87c._1_1_ = s_normal_send_work_begin_00034864[1];
    local_87c._2_1_ = s_normal_send_work_begin_00034864[2];
    local_87c._3_1_ = s_normal_send_work_begin_00034864[3];
    uStack_878._0_1_ = s_normal_send_work_begin_00034864[4];
    uStack_878._1_1_ = s_normal_send_work_begin_00034864[5];
    uStack_878._2_1_ = s_normal_send_work_begin_00034864[6];
    uStack_878._3_1_ = s_normal_send_work_begin_00034864[7];
    uStack_874._0_1_ = s_normal_send_work_begin_00034864[8];
    uStack_874._1_1_ = s_normal_send_work_begin_00034864[9];
    uStack_874._2_1_ = s_normal_send_work_begin_00034864[10];
    uStack_874._3_1_ = s_normal_send_work_begin_00034864[11];
    uStack_870._0_1_ = s_normal_send_work_begin_00034864[12];
    uStack_870._1_1_ = s_normal_send_work_begin_00034864[13];
    uStack_870._2_1_ = s_normal_send_work_begin_00034864[14];
    uStack_870._3_1_ = s_normal_send_work_begin_00034864[15];
    local_86c._0_1_ = s_normal_send_work_begin_00034864[16];
    local_86c._1_1_ = s_normal_send_work_begin_00034864[17];
    local_86c._2_1_ = s_normal_send_work_begin_00034864[18];
    local_86c._3_1_ = s_normal_send_work_begin_00034864[19];
    local_868._0_1_ = s_normal_send_work_begin_00034864[20];
    local_868._1_1_ = s_normal_send_work_begin_00034864[21];
    local_868._2_1_ = s_normal_send_work_begin_00034864[22];
    local_868._3_1_ = s_normal_send_work_begin_00034864[23];
    local_864 = (undefined)ram0x0003487c;
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
    local_87c._0_1_ = s_normal_send_work_end_00034880[0];
    local_87c._1_1_ = s_normal_send_work_end_00034880[1];
    local_87c._2_1_ = s_normal_send_work_end_00034880[2];
    local_87c._3_1_ = s_normal_send_work_end_00034880[3];
    uStack_878._0_1_ = s_normal_send_work_end_00034880[4];
    uStack_878._1_1_ = s_normal_send_work_end_00034880[5];
    uStack_878._2_1_ = s_normal_send_work_end_00034880[6];
    uStack_878._3_1_ = s_normal_send_work_end_00034880[7];
    uStack_874._0_1_ = s_normal_send_work_end_00034880[8];
    uStack_874._1_1_ = s_normal_send_work_end_00034880[9];
    uStack_874._2_1_ = s_normal_send_work_end_00034880[10];
    uStack_874._3_1_ = s_normal_send_work_end_00034880[11];
    uStack_870._0_1_ = s_normal_send_work_end_00034880[12];
    uStack_870._1_1_ = s_normal_send_work_end_00034880[13];
    uStack_870._2_1_ = s_normal_send_work_end_00034880[14];
    uStack_870._3_1_ = s_normal_send_work_end_00034880[15];
    local_86c._0_1_ = s_normal_send_work_end_00034880[16];
    local_86c._1_1_ = s_normal_send_work_end_00034880[17];
    local_86c._2_1_ = s_normal_send_work_end_00034880[18];
    local_86c._3_1_ = s_normal_send_work_end_00034880[19];
    local_868._0_3_ = (undefined3)ram0x00034894;
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

