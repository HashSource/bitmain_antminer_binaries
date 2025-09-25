
undefined4 dh_finish(int param_1)

{
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x20));
  return 1;
}

