
int CRYPTO_mem_ctrl(int mode)

{
  char *file;
  CRYPTO_THREADID *dest;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  CRYPTO_THREADID CStack_18;
  
  iVar2 = DAT_0008a534;
  iVar4 = *(int *)(DAT_0008a534 + 4);
  CRYPTO_lock(9,0x14,DAT_0008a538,0xd4);
  iVar1 = DAT_0008a534;
  switch(mode) {
  case 0:
    *(undefined4 *)(iVar2 + 4) = 0;
    *(undefined4 *)(iVar2 + 8) = 0;
    break;
  case 1:
    *(undefined4 *)(iVar2 + 4) = 3;
    *(undefined4 *)(iVar2 + 8) = 0;
    break;
  case 2:
    uVar3 = *(uint *)(iVar2 + 4);
    if ((((int)(uVar3 << 0x1f) < 0) && (*(int *)(DAT_0008a534 + 8) != 0)) &&
       (iVar2 = *(int *)(DAT_0008a534 + 8) + -1, *(int *)(DAT_0008a534 + 8) = iVar2,
       file = DAT_0008a538, iVar2 == 0)) {
      *(uint *)(iVar1 + 4) = uVar3 | 2;
      CRYPTO_lock(10,0x1b,file,0x109);
    }
    break;
  case 3:
    if (*(int *)(iVar2 + 4) << 0x1f < 0) {
      CRYPTO_THREADID_current(&CStack_18);
      if ((*(int *)(iVar1 + 8) == 0) ||
         (iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar1 + 0xc),&CStack_18), iVar1 != 0)) {
        CRYPTO_lock(10,0x14,DAT_0008a538,0xf4);
        CRYPTO_lock(9,0x1b,DAT_0008a538,0xfb);
        CRYPTO_lock(9,0x14,DAT_0008a538,0xfc);
        dest = DAT_0008a53c;
        *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfffffffd;
        CRYPTO_THREADID_cpy(dest,&CStack_18);
      }
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
    }
  }
  CRYPTO_lock(10,0x14,DAT_0008a538,0x112);
  return iVar4;
}

