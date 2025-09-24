
void online_mode_retry_test(int chain)

{
  int chain_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : online mode retry test\n","online_mode_retry_test");
  builtin_strncpy(tmp1,"online mode retry te",0x14);
  tmp1[0x14] = 's';
  tmp1[0x15] = 't';
  tmp1[0x16] = '\0';
  log_to_file(tmp1,time_stamp);
  stop_threads();
  power_down_and_fan(chain);
  cancle_pause_recv_nonce();
  sleep(10);
  return;
}

