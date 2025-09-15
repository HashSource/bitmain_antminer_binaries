
void singleboard_step_increase_frequency(undefined4 param_1,undefined4 param_2)

{
  char local_41c [1024];
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
    builtin_strncpy(local_41c,"init freq done\n",0x10);
    _applog(2,local_41c,0);
  }
  return;
}

