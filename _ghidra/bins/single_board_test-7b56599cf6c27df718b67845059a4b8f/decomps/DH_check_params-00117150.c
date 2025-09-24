
undefined4 DH_check_params(int param_1,uint *param_2)

{
  BN_CTX *ctx;
  BIGNUM *a;
  int iVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  
  *param_2 = 0;
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    a = BN_CTX_get(ctx);
    if (a != (BIGNUM *)0x0) {
      iVar1 = BN_is_odd(*(undefined4 *)(param_1 + 8));
      if (iVar1 == 0) {
        *param_2 = *param_2 | 1;
      }
      iVar1 = BN_is_negative(*(undefined4 *)(param_1 + 0xc));
      if (((iVar1 != 0) || (iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 0xc)), iVar1 != 0)) ||
         (iVar1 = BN_is_one(*(undefined4 *)(param_1 + 0xc)), iVar1 != 0)) {
        *param_2 = *param_2 | 8;
      }
      pBVar2 = BN_copy(a,*(BIGNUM **)(param_1 + 8));
      if ((pBVar2 != (BIGNUM *)0x0) && (iVar1 = BN_sub_word(a,1), iVar1 != 0)) {
        iVar1 = BN_cmp(*(BIGNUM **)(param_1 + 0xc),a);
        if (-1 < iVar1) {
          *param_2 = *param_2 | 8;
        }
        uVar3 = 1;
        goto LAB_001171a6;
      }
    }
  }
  uVar3 = 0;
LAB_001171a6:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return uVar3;
}

