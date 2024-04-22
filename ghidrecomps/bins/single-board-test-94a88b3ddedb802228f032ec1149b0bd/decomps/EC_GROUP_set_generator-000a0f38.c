
int EC_GROUP_set_generator(EC_GROUP *group,EC_POINT *generator,BIGNUM *order,BIGNUM *cofactor)

{
  int iVar1;
  BIGNUM *pBVar2;
  BN_CTX *ctx;
  BN_MONT_CTX *mont;
  int *ptr;
  code *pcVar3;
  
  if (generator == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0x6f,0x43,DAT_000a10a0,0x129);
    return 0;
  }
  ptr = *(int **)(group + 4);
  if (ptr != (int *)0x0) {
LAB_000a0f50:
    pcVar3 = *(code **)(*ptr + 0x34);
    if (pcVar3 == (code *)0x0) {
      ERR_put_error(0x10,0x72,0x42,DAT_000a10a0,0x2f5);
      return 0;
    }
    if (*ptr == *(int *)generator) {
      if (((int *)generator != ptr) && (iVar1 = (*pcVar3)(ptr,generator), iVar1 == 0)) {
        return 0;
      }
      if (order == (BIGNUM *)0x0) {
        BN_set_word((BIGNUM *)(group + 8),0);
      }
      else {
        pBVar2 = BN_copy((BIGNUM *)(group + 8),order);
        if (pBVar2 == (BIGNUM *)0x0) {
          return 0;
        }
      }
      if (cofactor == (BIGNUM *)0x0) {
        BN_set_word((BIGNUM *)(group + 0x1c),0);
      }
      else {
        pBVar2 = BN_copy((BIGNUM *)(group + 0x1c),cofactor);
        if (pBVar2 == (BIGNUM *)0x0) {
          return 0;
        }
      }
      ctx = BN_CTX_new();
      if (*(int *)(group + 0x34) < 0) {
        if (*(BN_MONT_CTX **)(group + 0xac) != (BN_MONT_CTX *)0x0) {
          BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0xac));
          *(undefined4 *)(group + 0xac) = 0;
        }
        if (ctx == (BN_CTX *)0x0) {
          return 1;
        }
        mont = BN_MONT_CTX_new();
        *(BN_MONT_CTX **)(group + 0xac) = mont;
        if ((mont != (BN_MONT_CTX *)0x0) &&
           (iVar1 = BN_MONT_CTX_set(mont,(BIGNUM *)(group + 8),ctx), iVar1 == 0)) {
          BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0xac));
          *(undefined4 *)(group + 0xac) = 0;
        }
      }
      else if (ctx == (BN_CTX *)0x0) {
        return 1;
      }
      BN_CTX_free(ctx);
      return 1;
    }
    ERR_put_error(0x10,0x72,0x65,DAT_000a10a0,0x2f9);
    return 0;
  }
  if (*(int *)(*(int *)group + 0x28) == 0) {
    ERR_put_error(0x10,0x79,0x42,DAT_000a10a0,0x2c7);
  }
  else {
    ptr = (int *)CRYPTO_malloc(0x44,DAT_000a10a0,0x2cb);
    if (ptr == (int *)0x0) {
      ERR_put_error(0x10,0x79,0x41,DAT_000a10a0,0x2cd);
    }
    else {
      iVar1 = *(int *)group;
      *ptr = iVar1;
      iVar1 = (**(code **)(iVar1 + 0x28))();
      if (iVar1 != 0) {
        *(int **)(group + 4) = ptr;
        goto LAB_000a0f50;
      }
      CRYPTO_free(ptr);
    }
  }
  *(undefined4 *)(group + 4) = 0;
  return 0;
}

