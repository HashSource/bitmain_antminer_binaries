
BIGNUM * BN_CTX_get(BN_CTX *ctx)

{
  uint uVar1;
  uint uVar2;
  ulong *puVar3;
  int iVar4;
  BIGNUM *a;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  
  if (*(int *)(ctx + 0x24) != 0) {
    return (BIGNUM *)0x0;
  }
  if (*(int *)(ctx + 0x28) != 0) {
    return (BIGNUM *)0x0;
  }
  uVar2 = *(uint *)(ctx + 0xc);
  if (uVar2 == *(uint *)(ctx + 0x10)) {
    uVar2 = *(uint *)(ctx + 0x2c);
    a = (BIGNUM *)CRYPTO_malloc(0x148,"crypto/bn/bn_ctx.c",0x13e);
    if (a == (BIGNUM *)0x0) {
      ERR_put_error(3,0x93,0x41,"crypto/bn/bn_ctx.c",0x13f);
      goto LAB_0018498c;
    }
    pBVar6 = a;
    if ((uVar2 & 8) == 0) {
      do {
        pBVar5 = pBVar6 + 1;
        bn_init(pBVar6);
        pBVar6 = pBVar5;
      } while (pBVar5 != a + 0x10);
    }
    else {
      do {
        bn_init(pBVar6);
        pBVar5 = pBVar6 + 1;
        BN_set_flags(pBVar6,8);
        pBVar6 = pBVar5;
      } while (pBVar5 != a + 0x10);
    }
    iVar4 = *(int *)ctx;
    puVar3 = *(ulong **)(ctx + 8);
    a[0x10].top = 0;
    a[0x10].d = puVar3;
    if (iVar4 == 0) {
      *(BIGNUM **)(ctx + 8) = a;
      *(BIGNUM **)(ctx + 4) = a;
      *(BIGNUM **)ctx = a;
    }
    else {
      puVar3[0x51] = (ulong)a;
      *(BIGNUM **)(ctx + 8) = a;
      *(BIGNUM **)(ctx + 4) = a;
    }
    *(int *)(ctx + 0x10) = *(int *)(ctx + 0x10) + 0x10;
    *(int *)(ctx + 0xc) = *(int *)(ctx + 0xc) + 1;
  }
  else {
    if (uVar2 == 0) {
      iVar4 = *(int *)ctx;
      *(int *)(ctx + 4) = iVar4;
      uVar1 = 0;
    }
    else {
      uVar1 = uVar2 & 0xf;
      if (uVar1 == 0) {
        iVar4 = *(int *)(*(int *)(ctx + 4) + 0x144);
      }
      else {
        iVar4 = *(int *)(ctx + 4);
      }
      if (uVar1 == 0) {
        *(int *)(ctx + 4) = iVar4;
      }
    }
    *(uint *)(ctx + 0xc) = uVar2 + 1;
    a = (BIGNUM *)(iVar4 + uVar1 * 0x14);
    if (a == (BIGNUM *)0x0) {
LAB_0018498c:
      *(undefined4 *)(ctx + 0x28) = 1;
      ERR_put_error(3,0x74,0x6d,"crypto/bn/bn_ctx.c",0xe3);
      return (BIGNUM *)0x0;
    }
  }
  BN_set_word(a,0);
  iVar4 = *(int *)(ctx + 0x20);
  a->flags = a->flags & 0xfffffffb;
  *(int *)(ctx + 0x20) = iVar4 + 1;
  return a;
}

