
void * check_nonce(void *args)

{
  int asic_index_00;
  void *args_local;
  int nonceNum;
  nonce_rb_format nonce_tmp;
  int asic_index;
  runtime_base_t *runtime;
  
  nonceNum = 0;
  nonce_fifo_num(&nonceNum);
  while (nonceNum != 0) {
    nonceNum = nonceNum + -1;
    pop_nonce(&nonce_tmp);
    asic_index_00 = __aeabi_idiv(nonce_tmp.chip_addr,*(undefined4 *)((int)args + 0x6f0));
    is_patten_match(asic_index_00,nonce_tmp.chip_nonce,nonce_tmp.Nonce);
  }
  return (void *)0x0;
}

