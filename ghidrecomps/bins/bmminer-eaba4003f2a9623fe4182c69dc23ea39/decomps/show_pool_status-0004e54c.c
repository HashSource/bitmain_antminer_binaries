
void show_pool_status(pool *pool,uint64_t nonce2)

{
  char *pcVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint64_t nonce2_local;
  pool *pool_local;
  char *buf_hex;
  int i;
  
  pcVar1 = bin2hex(pool->coinbase,pool->coinbase_len);
  printf("%s: nonce2 0x%x\n","show_pool_status",in_r2,in_r3);
  printf("%s: coinbase : %s\n","show_pool_status",pcVar1);
  free(pcVar1);
  for (i = 0; i < pool->merkles; i = i + 1) {
    pcVar1 = bin2hex((pool->swork).merkle_bin[i],0x20);
    printf("%s: merkle_bin %d : %s\n","show_pool_status",i,pcVar1);
    free(pcVar1);
  }
  return;
}

