
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bm1740_get_nonce(void)

{
  pthread_t __th;
  undefined4 local_72c;
  undefined4 uStack_728;
  undefined4 uStack_724;
  undefined4 uStack_720;
  undefined4 local_71c;
  undefined2 local_718;
  undefined local_716;
  undefined local_629;
  undefined auStack_628 [2];
  undefined auStack_626 [198];
  undefined auStack_560 [1356];
  int local_14;
  
  memset(auStack_628,0,200);
  local_14 = 0;
  __th = pthread_self();
  pthread_detach(__th);
  do {
    while( true ) {
      midd_recv_work(auStack_628,0x5d);
      midd_recv_work(&local_629,1);
      local_14 = bm1740_combine_one_nonce(auStack_560,auStack_626,local_629);
      if (local_14 != 0) break;
      bm1740_handle_nonce(auStack_560);
    }
    if ((local_14 < 0) &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (0 < opt_log_level)))) {
      local_72c._0_1_ = s_receive_a_error_nonce_0002bd38[0];
      local_72c._1_1_ = s_receive_a_error_nonce_0002bd38[1];
      local_72c._2_1_ = s_receive_a_error_nonce_0002bd38[2];
      local_72c._3_1_ = s_receive_a_error_nonce_0002bd38[3];
      uStack_728._0_1_ = s_receive_a_error_nonce_0002bd38[4];
      uStack_728._1_1_ = s_receive_a_error_nonce_0002bd38[5];
      uStack_728._2_1_ = s_receive_a_error_nonce_0002bd38[6];
      uStack_728._3_1_ = s_receive_a_error_nonce_0002bd38[7];
      uStack_724._0_1_ = s_receive_a_error_nonce_0002bd38[8];
      uStack_724._1_1_ = s_receive_a_error_nonce_0002bd38[9];
      uStack_724._2_1_ = s_receive_a_error_nonce_0002bd38[10];
      uStack_724._3_1_ = s_receive_a_error_nonce_0002bd38[11];
      uStack_720._0_1_ = s_receive_a_error_nonce_0002bd38[12];
      uStack_720._1_1_ = s_receive_a_error_nonce_0002bd38[13];
      uStack_720._2_1_ = s_receive_a_error_nonce_0002bd38[14];
      uStack_720._3_1_ = s_receive_a_error_nonce_0002bd38[15];
      local_71c._0_1_ = s_receive_a_error_nonce_0002bd38[16];
      local_71c._1_1_ = s_receive_a_error_nonce_0002bd38[17];
      local_71c._2_1_ = s_receive_a_error_nonce_0002bd38[18];
      local_71c._3_1_ = s_receive_a_error_nonce_0002bd38[19];
      local_718 = (undefined2)ram0x0002bd4c;
      local_716 = (undefined)((uint)ram0x0002bd4c >> 0x10);
      _applog(1,&local_72c,0);
    }
  } while( true );
}

