
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void equihash_miner_join(void)

{
  pthread_join(p_miner,(void **)0x0);
  return;
}

