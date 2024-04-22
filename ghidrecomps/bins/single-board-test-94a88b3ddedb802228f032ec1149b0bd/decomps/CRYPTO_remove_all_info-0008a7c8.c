
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_remove_all_info(void)

{
  char *file;
  void *ptr;
  _LHASH *lh;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *data;
  int iVar5;
  CRYPTO_THREADID CStack_44;
  CRYPTO_THREADID aCStack_3c [4];
  
  iVar2 = DAT_0008a8cc;
  if (*(int *)(DAT_0008a8cc + 4) << 0x1f < 0) {
    CRYPTO_THREADID_current(&CStack_44);
    CRYPTO_lock(5,0x14,DAT_0008a8d0,0x11d);
    if (*(int *)(iVar2 + 4) << 0x1e < 0) {
      CRYPTO_lock(6,0x14,DAT_0008a8d0,0x122);
    }
    else {
      iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar2 + 0xc),&CStack_44);
      CRYPTO_lock(6,0x14,DAT_0008a8d0,0x122);
      if (iVar1 == 0) goto LAB_0008a7d6;
    }
    CRYPTO_mem_ctrl_constprop_2();
    iVar1 = DAT_0008a8cc;
    iVar5 = *(int *)(iVar2 + 0x14);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        while( true ) {
          CRYPTO_THREADID_current(aCStack_3c);
          ptr = lh_delete(*(_LHASH **)(iVar2 + 0x14),aCStack_3c);
          if (ptr == (void *)0x0) goto LAB_0008a86a;
          data = *(void **)((int)ptr + 0x14);
          if (data != (void *)0x0) {
            lh = *(_LHASH **)(iVar1 + 0x14);
            *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + 1;
            lh_insert(lh,data);
          }
          iVar3 = *(int *)((int)ptr + 0x18) + -1;
          *(int *)((int)ptr + 0x18) = iVar3;
          if (0 < iVar3) break;
          *(undefined4 *)((int)ptr + 0x14) = 0;
          if (data != (void *)0x0) {
            *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + -1;
          }
          CRYPTO_free(ptr);
          iVar5 = iVar5 + 1;
          if (*(int *)(iVar2 + 0x14) == 0) goto LAB_0008a86a;
        }
        iVar5 = iVar5 + 1;
      } while (*(int *)(iVar2 + 0x14) != 0);
    }
LAB_0008a86a:
    CRYPTO_lock(9,0x14,DAT_0008a8d0,0xd4);
    iVar1 = DAT_0008a8cc;
    uVar4 = *(uint *)(iVar2 + 4);
    if ((((int)(uVar4 << 0x1f) < 0) && (*(int *)(DAT_0008a8cc + 8) != 0)) &&
       (iVar2 = *(int *)(DAT_0008a8cc + 8) + -1, *(int *)(DAT_0008a8cc + 8) = iVar2,
       file = DAT_0008a8d0, iVar2 == 0)) {
      *(uint *)(iVar1 + 4) = uVar4 | 2;
      CRYPTO_lock(10,0x1b,file,0x109);
    }
    CRYPTO_lock(10,0x14,DAT_0008a8d0,0x112);
  }
  else {
LAB_0008a7d6:
    iVar5 = 0;
  }
  return iVar5;
}

