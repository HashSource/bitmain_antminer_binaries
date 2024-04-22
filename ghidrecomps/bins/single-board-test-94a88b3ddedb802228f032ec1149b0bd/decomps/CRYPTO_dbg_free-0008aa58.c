
void CRYPTO_dbg_free(void *addr,int before_p)

{
  char *file;
  void *ptr;
  int iVar1;
  int iVar2;
  uint uVar3;
  void *ptr_00;
  void *ptr_01;
  CRYPTO_THREADID CStack_44;
  void *local_3c [10];
  
  iVar1 = DAT_0008ab50;
  if (((before_p == 0) && (addr != (void *)0x0)) && (*(int *)(DAT_0008ab50 + 4) << 0x1f < 0)) {
    CRYPTO_THREADID_current(&CStack_44);
    CRYPTO_lock(5,0x14,DAT_0008ab54,0x11d);
    if (*(int *)(iVar1 + 4) << 0x1e < 0) {
      CRYPTO_lock(6,0x14,DAT_0008ab54,0x122);
    }
    else {
      iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar1 + 0xc),&CStack_44);
      CRYPTO_lock(6,0x14,DAT_0008ab54,0x122);
      if (iVar2 == 0) {
        return;
      }
    }
    iVar2 = DAT_0008ab50;
    if (*(int *)(iVar1 + 0x18) != 0) {
      CRYPTO_mem_ctrl_constprop_2();
      local_3c[0] = addr;
      ptr = lh_delete(*(_LHASH **)(iVar2 + 0x18),local_3c);
      if (ptr != (void *)0x0) {
        ptr_00 = *(void **)((int)ptr + 0x20);
        if ((ptr_00 != (void *)0x0) &&
           (iVar2 = *(int *)((int)ptr_00 + 0x18) + -1, *(int *)((int)ptr_00 + 0x18) = iVar2,
           iVar2 < 1)) {
          ptr_01 = *(void **)((int)ptr_00 + 0x14);
          if ((ptr_01 != (void *)0x0) &&
             (iVar2 = *(int *)((int)ptr_01 + 0x18) + -1, *(int *)((int)ptr_01 + 0x18) = iVar2,
             iVar2 < 1)) {
            if (*(int *)((int)ptr_01 + 0x14) != 0) {
              app_info_free();
            }
            CRYPTO_free(ptr_01);
          }
          CRYPTO_free(ptr_00);
        }
        CRYPTO_free(ptr);
      }
      CRYPTO_lock(9,0x14,DAT_0008ab54,0xd4);
      iVar2 = DAT_0008ab50;
      uVar3 = *(uint *)(iVar1 + 4);
      if ((((int)(uVar3 << 0x1f) < 0) && (*(int *)(DAT_0008ab50 + 8) != 0)) &&
         (iVar1 = *(int *)(DAT_0008ab50 + 8) + -1, *(int *)(DAT_0008ab50 + 8) = iVar1,
         file = DAT_0008ab54, iVar1 == 0)) {
        *(uint *)(iVar2 + 4) = uVar3 | 2;
        CRYPTO_lock(10,0x1b,file,0x109);
      }
      CRYPTO_lock(10,0x14,DAT_0008ab54,0x112);
    }
  }
  return;
}

