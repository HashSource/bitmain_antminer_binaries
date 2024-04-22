
void freq_tuning_wait_recv_nonce(freq_tuning_info *freq_info)

{
  FILE *__stream;
  uint uVar1;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  int wait_count;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] == false)) &&
       (freq_info->fake_done[chain] == false)) {
      wait_count = 0;
      while ((wait_count < 4 && (valid_nonce_num[chain] < chain_ValidNonce[chain]))) {
        wait_count = wait_count + 1;
        usleep(100000);
      }
    }
  }
  freq_tuning_get_domain_nonce_statistics();
  freq_tuning_parameter_dump(freq_info);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      uVar1 = get_crc_count();
      fprintf(__stream,"%s:%d:%s: ++++ CRC ERROR = %d\n","freq_tuning.c",0x475,
              "freq_tuning_wait_recv_nonce",uVar1);
    }
    fclose(__stream);
  }
  return;
}

