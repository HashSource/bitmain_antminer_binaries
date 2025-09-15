
void stop_scan(int error_num,uint8_t chain)

{
  uint8_t chain_local;
  int error_num_local;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      disable_pic_dac((uint8_t)i);
    }
  }
  freq_scan_error_code_set(error_num,(uint)chain);
  do {
    process_test();
    sleep(1);
  } while( true );
}

