
void singleboard_step_increase_frequency(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_41c;
  undefined4 uStack_418;
  undefined4 uStack_414;
  undefined4 uStack_410;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
  local_18 = get_index_by_freq(param_2);
  local_14 = get_index_by_freq(param_1);
  while( true ) {
    sleep(10);
    if (local_18 - local_14 < 6) {
      local_14 = local_18;
    }
    else {
      local_14 = local_14 + 5;
    }
    local_1c = get_freq_by_index(local_14);
    set_frequency(local_1c);
    if (local_14 == local_18) break;
    show_nonce_detail();
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_41c._0_1_ = s_init_freq_done_0003439c[0];
    local_41c._1_1_ = s_init_freq_done_0003439c[1];
    local_41c._2_1_ = s_init_freq_done_0003439c[2];
    local_41c._3_1_ = s_init_freq_done_0003439c[3];
    uStack_418._0_1_ = s_init_freq_done_0003439c[4];
    uStack_418._1_1_ = s_init_freq_done_0003439c[5];
    uStack_418._2_1_ = s_init_freq_done_0003439c[6];
    uStack_418._3_1_ = s_init_freq_done_0003439c[7];
    uStack_414._0_1_ = s_init_freq_done_0003439c[8];
    uStack_414._1_1_ = s_init_freq_done_0003439c[9];
    uStack_414._2_1_ = s_init_freq_done_0003439c[10];
    uStack_414._3_1_ = s_init_freq_done_0003439c[11];
    uStack_410._0_1_ = s_init_freq_done_0003439c[12];
    uStack_410._1_1_ = s_init_freq_done_0003439c[13];
    uStack_410._2_1_ = s_init_freq_done_0003439c[14];
    uStack_410._3_1_ = s_init_freq_done_0003439c[15];
    _applog(2,&local_41c,0);
  }
  return;
}

