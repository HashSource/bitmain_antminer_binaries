
void bn_free(undefined4 *param_1,int param_2)

{
  BIGNUM *a;
  
  a = (BIGNUM *)*param_1;
  if (a == (BIGNUM *)0x0) {
    return;
  }
  if (-1 < *(int *)(param_2 + 0x14) << 0x1f) {
    BN_free(a);
    *param_1 = 0;
    return;
  }
  BN_clear_free(a);
  *param_1 = 0;
  return;
}

