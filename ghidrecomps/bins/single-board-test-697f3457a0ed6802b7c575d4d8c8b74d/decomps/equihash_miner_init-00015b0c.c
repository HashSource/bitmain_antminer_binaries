
void equihash_miner_init(runtime_base_t *runtime)

{
  runtime_base_t *runtime_local;
  
  runtime->nonce_submit = equihash_nonce_submit + 1;
  return;
}

