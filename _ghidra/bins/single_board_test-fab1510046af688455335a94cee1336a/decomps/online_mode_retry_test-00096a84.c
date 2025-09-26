
void online_mode_retry_test(int chain)

{
  int chain_local;
  char tmp42 [256];
  
  builtin_strncpy(tmp42,"online mode retry te",0x14);
  tmp42[0x14] = 's';
  tmp42[0x15] = 't';
  tmp42[0x16] = '\0';
  puts(tmp42);
  stop_threads();
  power_down_and_fan(chain);
  cancle_pause_recv_nonce();
  sleep(10);
  return;
}

