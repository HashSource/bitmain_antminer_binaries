
_Bool disable_hash_board(STATUS_CODE status_value)

{
  FILE *__stream;
  uint uVar1;
  STATUS_CODE status_value_local;
  FILE *pFile;
  int i;
  
  if (!disable_hash_board::has_disabled_flag) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: disable_pic_dac as status_value %d\n","temperature.c",0x464,
                "disable_hash_board",status_value);
      }
      fclose(__stream);
    }
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 1) {
        disable_pic_dac((uint8_t)i);
      }
    }
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control(uVar1 & 0xffffffbf);
    disable_hash_board::has_disabled_flag = true;
  }
  return disable_hash_board::has_disabled_flag;
}

