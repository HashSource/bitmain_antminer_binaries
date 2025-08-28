
void show_pool_status(pool *pool,uint64_t nonce2)

{
  char *pcVar1;
  uint64_t nonce2_local;
  pool *pool_local;
  char *buf_hex;
  int i;
  
  pcVar1 = bin2hex(pool->coinbase,pool->coinbase_len);
  nonce2_local._0_4_ = (undefined4)nonce2;
  nonce2_local._4_4_ = (undefined4)(nonce2 >> 0x20);
  printf("%s: nonce2 0x%x\n","show_pool_status",(undefined4)nonce2_local,nonce2_local._4_4_);
  printf("%s: coinbase : %s\n","show_pool_status",pcVar1);
  free(pcVar1);
  for (i = 0; i < pool->merkles; i = i + 1) {
    pcVar1 = bin2hex((pool->swork).merkle_bin[i],0x20);
    printf("%s: merkle_bin %d : %s\n","show_pool_status",i,pcVar1);
    free(pcVar1);
  }
  return;
}

