
int EC_GROUP_cmp(EC_GROUP *a,EC_GROUP *b,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  BIGNUM *b_00;
  BIGNUM *b_01;
  BIGNUM *b_02;
  int iVar2;
  BN_CTX *local_30;
  
  if ((*(int *)(*(int *)a + 4) != *(int *)(*(int *)b + 4)) ||
     (((*(int *)(a + 0x30) != 0 && (*(int *)(b + 0x30) != 0)) &&
      (*(int *)(a + 0x30) != *(int *)(b + 0x30))))) {
    return 1;
  }
  if (ctx == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    local_30 = ctx;
    if (ctx == (BN_CTX *)0x0) {
      return -1;
    }
  }
  else {
    local_30 = (BN_CTX *)0x0;
  }
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  pBVar1 = BN_CTX_get(ctx);
  b_00 = BN_CTX_get(ctx);
  b_01 = BN_CTX_get(ctx);
  b_02 = BN_CTX_get(ctx);
  if (b_02 == (BIGNUM *)0x0) {
LAB_000a13e8:
    BN_CTX_end(ctx);
    if (local_30 == (BN_CTX *)0x0) {
      return -1;
    }
    BN_CTX_free(ctx);
    return -1;
  }
  iVar2 = (**(code **)(*(int *)a + 0x1c))(a,a_00,a_01,pBVar1,ctx);
  if (((iVar2 != 0) && (iVar2 = (**(code **)(*(int *)b + 0x1c))(b,b_00,b_01,b_02,ctx), iVar2 != 0))
     && ((iVar2 = BN_cmp(a_00,b_00), iVar2 == 0 &&
         ((iVar2 = BN_cmp(a_01,b_01), iVar2 == 0 && (iVar2 = BN_cmp(pBVar1,b_02), iVar2 == 0)))))) {
    iVar2 = *(int *)a;
    if (*(code **)(iVar2 + 0x6c) == (code *)0x0) {
      ERR_put_error(0x10,0x71,0x42,DAT_000a143c,0x3e6);
    }
    else if ((iVar2 == **(int **)(a + 4)) && (iVar2 == **(int **)(b + 4))) {
      iVar2 = (**(code **)(iVar2 + 0x6c))(a,*(int **)(a + 4),*(int **)(b + 4),ctx);
      if (iVar2 == 0) {
        pBVar1 = BN_copy(a_00,(BIGNUM *)(a + 8));
        if (((((pBVar1 == (BIGNUM *)0x0) || (a_00->top == 0)) ||
             (pBVar1 = BN_copy(b_00,(BIGNUM *)(b + 8)), pBVar1 == (BIGNUM *)0x0)) ||
            ((b_00->top == 0 ||
             (pBVar1 = BN_copy(a_01,(BIGNUM *)(a + 0x1c)), pBVar1 == (BIGNUM *)0x0)))) ||
           ((*(int *)(a + 0x20) == 0 ||
            ((pBVar1 = BN_copy(b_01,(BIGNUM *)(b + 0x1c)), pBVar1 == (BIGNUM *)0x0 ||
             (*(int *)(b + 0x20) == 0)))))) goto LAB_000a13e8;
        iVar2 = BN_cmp(a_00,b_00);
        if (iVar2 == 0) {
          iVar2 = BN_cmp(a_01,b_01);
          if (iVar2 != 0) {
            iVar2 = 1;
          }
          goto LAB_000a1308;
        }
      }
    }
    else {
      ERR_put_error(0x10,0x71,0x65,DAT_000a143c,0x3ea);
    }
  }
  iVar2 = 1;
LAB_000a1308:
  BN_CTX_end(ctx);
  if (local_30 != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
    return iVar2;
  }
  return iVar2;
}

