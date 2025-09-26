
CRYPTO_THREADID * BN_BLINDING_thread_id(BN_BLINDING *param_1)

{
  return (CRYPTO_THREADID *)(param_1 + 0x14);
}

