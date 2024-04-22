
void BN_CTX_start(BN_CTX *ctx)

{
  int num;
  int iVar1;
  void *__dest;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(ctx + 0x24);
  if ((iVar1 == 0) && (*(int *)(ctx + 0x28) == 0)) {
    iVar1 = *(int *)(ctx + 0x18);
    uVar2 = *(undefined4 *)(ctx + 0x20);
    if (iVar1 == *(int *)(ctx + 0x1c)) {
      num = 0x80;
      uVar3 = 0x20;
      if (iVar1 != 0) {
        uVar3 = (uint)(iVar1 * 3) >> 1;
        num = uVar3 << 2;
      }
      __dest = CRYPTO_malloc(num,DAT_0009deac,0x152);
      if (__dest == (void *)0x0) {
        ERR_put_error(3,0x81,0x6d,DAT_0009deac,0x106);
        iVar1 = *(int *)(ctx + 0x24);
        goto LAB_0009de36;
      }
      if (*(int *)(ctx + 0x18) != 0) {
        memcpy(__dest,*(void **)(ctx + 0x14),*(int *)(ctx + 0x18) << 2);
      }
      if (*(int *)(ctx + 0x1c) != 0) {
        CRYPTO_free(*(void **)(ctx + 0x14));
      }
      iVar1 = *(int *)(ctx + 0x18);
      *(void **)(ctx + 0x14) = __dest;
      *(uint *)(ctx + 0x1c) = uVar3;
    }
    else {
      __dest = *(void **)(ctx + 0x14);
    }
    *(undefined4 *)((int)__dest + iVar1 * 4) = uVar2;
    *(int *)(ctx + 0x18) = iVar1 + 1;
  }
  else {
LAB_0009de36:
    *(int *)(ctx + 0x24) = iVar1 + 1;
  }
  return;
}

