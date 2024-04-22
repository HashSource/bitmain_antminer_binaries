
void pt_handle(int param_1,undefined4 param_2,byte param_3)

{
  ushort uVar1;
  undefined4 local_420;
  undefined4 uStack_41c;
  undefined4 uStack_418;
  undefined4 uStack_414;
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  FILE *local_20;
  ushort local_1a;
  int local_18;
  int local_14;
  
  local_18 = param_1;
  uVar1 = CRC16_v1(param_1 + 2,0x402);
  local_1a = uVar1 >> 8 | uVar1 << 8;
  if (local_1a == *(ushort *)(local_18 + 0x404)) {
    local_20 = fopen("./pattern_result.txt","a+");
    if (local_20 == (FILE *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        local_420._0_1_ = s_open_failed_pattern_result_txt_00033b78[0];
        local_420._1_1_ = s_open_failed_pattern_result_txt_00033b78[1];
        local_420._2_1_ = s_open_failed_pattern_result_txt_00033b78[2];
        local_420._3_1_ = s_open_failed_pattern_result_txt_00033b78[3];
        uStack_41c._0_1_ = s_open_failed_pattern_result_txt_00033b78[4];
        uStack_41c._1_1_ = s_open_failed_pattern_result_txt_00033b78[5];
        uStack_41c._2_1_ = s_open_failed_pattern_result_txt_00033b78[6];
        uStack_41c._3_1_ = s_open_failed_pattern_result_txt_00033b78[7];
        uStack_418._0_1_ = s_open_failed_pattern_result_txt_00033b78[8];
        uStack_418._1_1_ = s_open_failed_pattern_result_txt_00033b78[9];
        uStack_418._2_1_ = s_open_failed_pattern_result_txt_00033b78[10];
        uStack_418._3_1_ = s_open_failed_pattern_result_txt_00033b78[11];
        uStack_414._0_1_ = s_open_failed_pattern_result_txt_00033b78[12];
        uStack_414._1_1_ = s_open_failed_pattern_result_txt_00033b78[13];
        uStack_414._2_1_ = s_open_failed_pattern_result_txt_00033b78[14];
        uStack_414._3_1_ = s_open_failed_pattern_result_txt_00033b78[15];
        local_410._0_1_ = s_open_failed_pattern_result_txt_00033b78[16];
        local_410._1_1_ = s_open_failed_pattern_result_txt_00033b78[17];
        local_410._2_1_ = s_open_failed_pattern_result_txt_00033b78[18];
        local_410._3_1_ = s_open_failed_pattern_result_txt_00033b78[19];
        uStack_40c._0_1_ = s_open_failed_pattern_result_txt_00033b78[20];
        uStack_40c._1_1_ = s_open_failed_pattern_result_txt_00033b78[21];
        uStack_40c._2_1_ = s_open_failed_pattern_result_txt_00033b78[22];
        uStack_40c._3_1_ = s_open_failed_pattern_result_txt_00033b78[23];
        uStack_408._0_1_ = s_open_failed_pattern_result_txt_00033b78[24];
        uStack_408._1_1_ = s_open_failed_pattern_result_txt_00033b78[25];
        uStack_408._2_1_ = s_open_failed_pattern_result_txt_00033b78[26];
        uStack_408._3_1_ = s_open_failed_pattern_result_txt_00033b78[27];
        uStack_404._0_1_ = s_open_failed_pattern_result_txt_00033b78[28];
        uStack_404._1_1_ = s_open_failed_pattern_result_txt_00033b78[29];
        uStack_404._2_1_ = s_open_failed_pattern_result_txt_00033b78[30];
        uStack_404._3_1_ = s_open_failed_pattern_result_txt_00033b78[31];
        _applog(2,&local_420,0);
      }
    }
    else {
      for (local_14 = 0; local_14 < 0x80; local_14 = local_14 + 1) {
        dump_str(local_20,0,local_14 * 8 + local_18 + 4,8);
      }
      fclose(local_20);
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf((char *)&local_420,0x400,"chainid=%d cal crc = %04x, chip crc = %04x\n",(uint)param_3
               ,(uint)local_1a,(uint)*(ushort *)(local_18 + 0x404));
      _applog(2,&local_420,0);
    }
    pattern_test_crc_error = 1;
  }
  return;
}

