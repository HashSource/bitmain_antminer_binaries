
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_pop_info(void)

{
  int iVar1;
  char *file;
  void *ptr;
  _LHASH *lh;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *data;
  CRYPTO_THREADID CStack_3c;
  CRYPTO_THREADID aCStack_34 [4];
  
  iVar2 = DAT_0008a7c0;
  if (-1 < *(int *)(DAT_0008a7c0 + 4) << 0x1f) {
    return 0;
  }
  CRYPTO_THREADID_current(&CStack_3c);
  CRYPTO_lock(5,0x14,DAT_0008a7c4,0x11d);
  if (*(int *)(iVar2 + 4) << 0x1e < 0) {
    CRYPTO_lock(6,0x14,DAT_0008a7c4,0x122);
  }
  else {
    iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar2 + 0xc),&CStack_3c);
    CRYPTO_lock(6,0x14,DAT_0008a7c4,0x122);
    if (iVar3 == 0) {
      return 0;
    }
  }
  CRYPTO_mem_ctrl_constprop_2();
  iVar3 = DAT_0008a7c0;
  if (*(int *)(iVar2 + 0x14) != 0) {
    CRYPTO_THREADID_current(aCStack_34);
    ptr = lh_delete(*(_LHASH **)(iVar3 + 0x14),aCStack_34);
    if (ptr != (void *)0x0) {
      data = *(void **)((int)ptr + 0x14);
      if (data != (void *)0x0) {
        lh = *(_LHASH **)(iVar3 + 0x14);
        *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + 1;
        lh_insert(lh,data);
      }
      iVar3 = *(int *)((int)ptr + 0x18) + -1;
      *(int *)((int)ptr + 0x18) = iVar3;
      if (iVar3 < 1) {
        *(undefined4 *)((int)ptr + 0x14) = 0;
        if (data != (void *)0x0) {
          *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + -1;
        }
        iVar3 = 1;
        CRYPTO_free(ptr);
      }
      else {
        iVar3 = 1;
      }
      goto LAB_0008a744;
    }
  }
  iVar3 = 0;
LAB_0008a744:
  CRYPTO_lock(9,0x14,DAT_0008a7c4,0xd4);
  iVar1 = DAT_0008a7c0;
  uVar4 = *(uint *)(iVar2 + 4);
  if ((((int)(uVar4 << 0x1f) < 0) && (*(int *)(DAT_0008a7c0 + 8) != 0)) &&
     (iVar2 = *(int *)(DAT_0008a7c0 + 8) + -1, *(int *)(DAT_0008a7c0 + 8) = iVar2,
     file = DAT_0008a7c4, iVar2 == 0)) {
    *(uint *)(iVar1 + 4) = uVar4 | 2;
    CRYPTO_lock(10,0x1b,file,0x109);
  }
  CRYPTO_lock(10,0x14,DAT_0008a7c4,0x112);
  return iVar3;
}

