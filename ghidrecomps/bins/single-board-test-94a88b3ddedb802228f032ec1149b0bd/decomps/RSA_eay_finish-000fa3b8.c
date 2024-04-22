
undefined4 RSA_eay_finish(int param_1)

{
  if (*(BN_MONT_CTX **)(param_1 + 0x40) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x40));
  }
  if (*(BN_MONT_CTX **)(param_1 + 0x44) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x44));
  }
  if (*(BN_MONT_CTX **)(param_1 + 0x48) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x48));
  }
  return 1;
}

