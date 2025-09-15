
void open_core_BM1393_pre_open(int chain,uchar num,uchar set)

{
  uint uVar1;
  FILE *__stream;
  uchar set_local;
  uchar num_local;
  int chain_local;
  FILE *pFile;
  uchar i;
  
  if (set != '\0') {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar1 & 0xffff7fdf | 0x8000);
    set_hash_counting_number(0);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: pre open core = %d\n","driver-btm-soc.c",0xf30,
              "open_core_BM1393_pre_open",(uint)num);
    }
    fclose(__stream);
  }
  if (chain == (uint)All_Chain) {
    for (i = '\0'; i < 0x10; i = i + '\x01') {
      if (dev->chain_exist[i] == 1) {
        pre_open_core_one_chain(num,i);
      }
    }
  }
  else {
    pre_open_core_one_chain(num,(uint8_t)chain);
  }
  if (set != '\0') {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | uVar1 | 0x8000);
  }
  return;
}

