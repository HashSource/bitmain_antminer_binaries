
void ec_GFp_mont_group_clear_finish(int param_1)

{
  if (*(BN_MONT_CTX **)(param_1 + 0xa0) != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(BIGNUM **)(param_1 + 0xa4) != (BIGNUM *)0x0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  ec_GFp_simple_group_clear_finish(param_1);
  return;
}

