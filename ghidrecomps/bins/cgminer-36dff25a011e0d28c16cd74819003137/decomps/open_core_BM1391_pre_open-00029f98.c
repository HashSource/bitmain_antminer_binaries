
void open_core_BM1391_pre_open(int chain,uint num,uchar set)

{
  uint uVar1;
  FILE *__stream;
  uchar set_local;
  uint num_local;
  int chain_local;
  FILE *pFile;
  int i;
  
  if (set != '\0') {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control(uVar1 & 0xffff701f | 0x8100);
    set_hash_counting_number(0);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: pre open core = %d\n","driver-btm-soc.c",0x1039,
              "open_core_BM1391_pre_open",num);
    }
    fclose(__stream);
  }
  if (chain == (uint)All_Chain) {
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 1) {
        pre_open_core_one_chain(num,(uint8_t)i);
      }
    }
  }
  else {
    pre_open_core_one_chain(num,(uint8_t)chain);
  }
  if (set != '\0') {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control(uVar1 | 0x8000 | (opt_multi_version & 0xfU) << 8);
  }
  return;
}

