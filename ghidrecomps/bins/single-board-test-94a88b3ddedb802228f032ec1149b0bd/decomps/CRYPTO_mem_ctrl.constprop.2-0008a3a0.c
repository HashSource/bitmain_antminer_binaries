
undefined4 CRYPTO_mem_ctrl_constprop_2(void)

{
  int iVar1;
  CRYPTO_THREADID *dest;
  int iVar2;
  undefined4 uVar3;
  CRYPTO_THREADID CStack_18;
  
  iVar1 = DAT_0008a424;
  uVar3 = *(undefined4 *)(DAT_0008a424 + 4);
  CRYPTO_lock(9,0x14,DAT_0008a428,0xd4);
  if (*(int *)(iVar1 + 4) << 0x1f < 0) {
    CRYPTO_THREADID_current(&CStack_18);
    if ((*(int *)(iVar1 + 8) == 0) ||
       (iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar1 + 0xc),&CStack_18), iVar2 != 0)) {
      CRYPTO_lock(10,0x14,DAT_0008a428,0xf4);
      CRYPTO_lock(9,0x1b,DAT_0008a428,0xfb);
      CRYPTO_lock(9,0x14,DAT_0008a428,0xfc);
      dest = DAT_0008a42c;
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xfffffffd;
      CRYPTO_THREADID_cpy(dest,&CStack_18);
    }
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  }
  CRYPTO_lock(10,0x14,DAT_0008a428,0x112);
  return uVar3;
}

