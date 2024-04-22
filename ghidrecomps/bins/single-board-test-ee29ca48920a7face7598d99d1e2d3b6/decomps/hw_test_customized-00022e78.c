
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hw_test_customized(void)

{
  undefined4 local_87c;
  undefined4 uStack_878;
  undefined4 uStack_874;
  undefined4 local_870;
  undefined4 local_86c;
  undefined4 uStack_868;
  undefined4 uStack_864;
  undefined4 uStack_860;
  undefined4 local_85c;
  undefined2 local_858;
  undefined local_856;
  undefined auStack_47c [281];
  undefined auStack_363 [281];
  undefined auStack_24a [281];
  undefined auStack_131 [281];
  int local_18;
  int local_14;
  
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
  set_address();
  usleep(200000);
  read_register(0,1,0,0);
  sleep(1);
  local_14 = 0;
  while (local_14 < 0x12d) {
    for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
      send_work(auStack_47c + local_18 * 0x119,0,0);
      sleep(0x1e);
      local_14 = local_14 + 0x1e;
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf((char *)&local_87c,0x400,"seconds %d\n",local_14);
        _applog(2,&local_87c,0);
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        local_87c._0_1_ = s_asic_1_2_3_4_00034e7c[0];
        local_87c._1_1_ = s_asic_1_2_3_4_00034e7c[1];
        local_87c._2_1_ = s_asic_1_2_3_4_00034e7c[2];
        local_87c._3_1_ = s_asic_1_2_3_4_00034e7c[3];
        uStack_878._0_1_ = s_asic_1_2_3_4_00034e7c[4];
        uStack_878._1_1_ = s_asic_1_2_3_4_00034e7c[5];
        uStack_878._2_1_ = s_asic_1_2_3_4_00034e7c[6];
        uStack_878._3_1_ = s_asic_1_2_3_4_00034e7c[7];
        uStack_874._0_1_ = s_asic_1_2_3_4_00034e7c[8];
        uStack_874._1_1_ = s_asic_1_2_3_4_00034e7c[9];
        uStack_874._2_1_ = s_asic_1_2_3_4_00034e7c[10];
        uStack_874._3_1_ = s_asic_1_2_3_4_00034e7c[11];
        local_870._0_1_ = s_asic_1_2_3_4_00034e7c[12];
        local_870._1_1_ = s_asic_1_2_3_4_00034e7c[13];
        local_870._2_1_ = s_asic_1_2_3_4_00034e7c[14];
        local_870._3_1_ = s_asic_1_2_3_4_00034e7c[15];
        local_86c._0_1_ = s_asic_1_2_3_4_00034e7c[16];
        local_86c._1_1_ = s_asic_1_2_3_4_00034e7c[17];
        local_86c._2_1_ = s_asic_1_2_3_4_00034e7c[18];
        local_86c._3_1_ = s_asic_1_2_3_4_00034e7c[19];
        uStack_868._0_1_ = s_asic_1_2_3_4_00034e7c[20];
        uStack_868._1_1_ = s_asic_1_2_3_4_00034e7c[21];
        uStack_868._2_1_ = s_asic_1_2_3_4_00034e7c[22];
        uStack_868._3_1_ = s_asic_1_2_3_4_00034e7c[23];
        uStack_864._0_1_ = s_asic_1_2_3_4_00034e7c[24];
        uStack_864._1_1_ = s_asic_1_2_3_4_00034e7c[25];
        uStack_864._2_1_ = s_asic_1_2_3_4_00034e7c[26];
        uStack_864._3_1_ = s_asic_1_2_3_4_00034e7c[27];
        uStack_860._0_1_ = s_asic_1_2_3_4_00034e7c[28];
        uStack_860._1_1_ = s_asic_1_2_3_4_00034e7c[29];
        uStack_860._2_1_ = s_asic_1_2_3_4_00034e7c[30];
        uStack_860._3_1_ = s_asic_1_2_3_4_00034e7c[31];
        local_85c._0_1_ = s_asic_1_2_3_4_00034e7c[32];
        local_85c._1_1_ = s_asic_1_2_3_4_00034e7c[33];
        local_85c._2_1_ = s_asic_1_2_3_4_00034e7c[34];
        local_85c._3_1_ = s_asic_1_2_3_4_00034e7c[35];
        local_858 = (undefined2)ram0x00034ea0;
        local_856 = (undefined)((uint)ram0x00034ea0 >> 0x10);
        _applog(2,&local_87c,0);
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf((char *)&local_87c,0x400,"valid       %d      %d      %d      %d\n",
                 nonce_num_each_asic._0_4_,nonce_num_each_asic._4_4_,nonce_num_each_asic._8_4_,
                 nonce_invalid_num_each_asic._0_4_);
        _applog(2,&local_87c,0);
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf((char *)&local_87c,0x400,"invalid-1   %d      %d      %d      %d\n",
                 nonce_invalid_num_each_asic_2._0_4_,nonce_invalid_num_each_asic_2._8_4_,
                 nonce_invalid_num_each_asic_2._16_4_,one_work_nonce_each_asic._0_4_);
        _applog(2,&local_87c,0);
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf((char *)&local_87c,0x400,"invalid-2   %d      %d      %d      %d\n",
                 nonce_invalid_num_each_asic_2._4_4_,nonce_invalid_num_each_asic_2._12_4_,
                 nonce_invalid_num_each_asic_2._20_4_,one_work_nonce_each_asic._4_4_);
        _applog(2,&local_87c,0);
      }
    }
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_87c._0_1_ = s_test_finished_00034e60[0];
    local_87c._1_1_ = s_test_finished_00034e60[1];
    local_87c._2_1_ = s_test_finished_00034e60[2];
    local_87c._3_1_ = s_test_finished_00034e60[3];
    uStack_878._0_1_ = s_test_finished_00034e60[4];
    uStack_878._1_1_ = s_test_finished_00034e60[5];
    uStack_878._2_1_ = s_test_finished_00034e60[6];
    uStack_878._3_1_ = s_test_finished_00034e60[7];
    uStack_874._0_1_ = s_test_finished_00034e60[8];
    uStack_874._1_1_ = s_test_finished_00034e60[9];
    uStack_874._2_1_ = s_test_finished_00034e60[10];
    uStack_874._3_1_ = s_test_finished_00034e60[11];
    _applog(2,&local_87c,0);
  }
  return;
}

