
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void btm_clear_core_nonce(void)

{
  memset(asic_core_nonce_num_chain,0,0x15f000);
  return;
}

