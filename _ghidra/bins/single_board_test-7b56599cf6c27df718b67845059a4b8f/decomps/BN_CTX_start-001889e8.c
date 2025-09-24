
void BN_CTX_start(BN_CTX *ctx)

{
  int num;
  void *__dest;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((*(int *)(ctx + 0x24) != 0) || (*(int *)(ctx + 0x28) != 0)) {
    *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + 1;
    return;
  }
  iVar1 = *(int *)(ctx + 0x18);
  uVar2 = *(undefined4 *)(ctx + 0x20);
  if (iVar1 == *(int *)(ctx + 0x1c)) {
    num = 0x80;
    uVar3 = 0x20;
    if (iVar1 != 0) {
      uVar3 = (uint)(iVar1 * 3) >> 1;
      num = uVar3 << 2;
    }
    __dest = CRYPTO_malloc(num,"crypto/bn/bn_ctx.c",0x108);
    if (__dest == (void *)0x0) {
      ERR_put_error(3,0x94,0x41,"crypto/bn/bn_ctx.c",0x109);
      ERR_put_error(3,0x81,0x6d,"crypto/bn/bn_ctx.c",0xbd);
      *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + 1;
      return;
    }
    if (*(int *)(ctx + 0x18) != 0) {
      memcpy(__dest,*(void **)(ctx + 0x14),*(int *)(ctx + 0x18) << 2);
    }
    CRYPTO_free(*(void **)(ctx + 0x14));
    iVar1 = *(int *)(ctx + 0x18);
    *(void **)(ctx + 0x14) = __dest;
    *(uint *)(ctx + 0x1c) = uVar3;
  }
  else {
    __dest = *(void **)(ctx + 0x14);
  }
  *(int *)(ctx + 0x18) = iVar1 + 1;
  *(undefined4 *)((int)__dest + iVar1 * 4) = uVar2;
  return;
}

