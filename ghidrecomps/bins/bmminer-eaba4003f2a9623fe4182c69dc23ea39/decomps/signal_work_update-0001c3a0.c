
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void signal_work_update(void)

{
  char tmp42 [2048];
  int i;
  
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    tmp42._0_4_ = s_Work_update_message_received_0007311c._0_4_;
    tmp42._4_4_ = s_Work_update_message_received_0007311c._4_4_;
    tmp42._8_4_ = s_Work_update_message_received_0007311c._8_4_;
    tmp42._12_4_ = s_Work_update_message_received_0007311c._12_4_;
    tmp42._16_4_ = s_Work_update_message_received_0007311c._16_4_;
    tmp42._20_4_ = s_Work_update_message_received_0007311c._20_4_;
    tmp42._24_4_ = s_Work_update_message_received_0007311c._24_4_;
    tmp42[28] = (char)ram0x00073138;
    _applog(6,tmp42,false);
  }
  cgtime(&update_tv_start);
  _rd_lock(&mining_thr_lock,"cgminer.c","signal_work_update",0x1521);
  for (i = 0; i < mining_threads; i = i + 1) {
    mining_thr[i]->work_update = true;
  }
  _rd_unlock(&mining_thr_lock,"cgminer.c","signal_work_update",0x1528);
  return;
}

