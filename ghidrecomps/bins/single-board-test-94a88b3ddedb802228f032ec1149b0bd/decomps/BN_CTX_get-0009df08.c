
BIGNUM * BN_CTX_get(BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  ulong *puVar3;
  uint uVar4;
  BIGNUM *a;
  
  if (*(int *)(ctx + 0x24) != 0) {
    return (BIGNUM *)0x0;
  }
  if (*(int *)(ctx + 0x28) != 0) {
    return (BIGNUM *)0x0;
  }
  uVar2 = *(uint *)(ctx + 0xc);
  if (uVar2 == *(uint *)(ctx + 0x10)) {
    a = (BIGNUM *)CRYPTO_malloc(0x148,DAT_0009e034,0x197);
    if (a == (BIGNUM *)0x0) goto LAB_0009e01a;
    BN_init(a);
    BN_init(a + 1);
    BN_init(a + 2);
    BN_init(a + 3);
    BN_init(a + 4);
    BN_init(a + 5);
    BN_init(a + 6);
    BN_init(a + 7);
    BN_init(a + 8);
    BN_init(a + 9);
    BN_init(a + 10);
    BN_init(a + 0xb);
    BN_init(a + 0xc);
    BN_init(a + 0xd);
    BN_init(a + 0xe);
    BN_init(a + 0xf);
    puVar3 = *(ulong **)(ctx + 8);
    iVar1 = *(int *)ctx;
    a[0x10].top = 0;
    a[0x10].d = puVar3;
    if (iVar1 == 0) {
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
      iVar1 = *(int *)ctx;
      *(int *)(ctx + 4) = iVar1;
      uVar4 = 0;
    }
    else {
      iVar1 = *(int *)(ctx + 4);
      uVar4 = uVar2 & 0xf;
      if (uVar4 == 0) {
        iVar1 = *(int *)(iVar1 + 0x144);
      }
      if (uVar4 == 0) {
        *(int *)(ctx + 4) = iVar1;
      }
    }
    *(uint *)(ctx + 0xc) = uVar2 + 1;
    a = (BIGNUM *)(iVar1 + uVar4 * 0x14);
    if (a == (BIGNUM *)0x0) {
LAB_0009e01a:
      *(undefined4 *)(ctx + 0x28) = 1;
      ERR_put_error(3,0x74,0x6d,DAT_0009e034,0x129);
      return (BIGNUM *)0x0;
    }
  }
  BN_set_word(a,0);
  *(int *)(ctx + 0x20) = *(int *)(ctx + 0x20) + 1;
  return a;
}

