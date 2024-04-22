
void bn_free(BIGNUM **param_1,int param_2)

{
  BIGNUM *a;
  
  a = *param_1;
  if (a != (BIGNUM *)0x0) {
    if (*(int *)(param_2 + 0x14) << 0x1f < 0) {
      BN_clear_free(a);
    }
    else {
      BN_free(a);
    }
    *param_1 = (BIGNUM *)0x0;
  }
  return;
}

