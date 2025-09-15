
undefined4 dsa_finish(int param_1)

{
  if (*(BN_MONT_CTX **)(param_1 + 0x2c) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x2c));
  }
  return 1;
}

