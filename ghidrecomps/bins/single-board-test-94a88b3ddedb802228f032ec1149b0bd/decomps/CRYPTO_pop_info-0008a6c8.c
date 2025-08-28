
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_pop_info(void)

{
  _LHASH *lh;
  void *ptr;
  int iVar1;
  void *data;
  CRYPTO_THREADID CStack_3c;
  CRYPTO_THREADID aCStack_34 [4];
  
  if (-1 < (int)(mh_mode << 0x1f)) {
    return 0;
  }
  CRYPTO_THREADID_current(&CStack_3c);
  CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
  if ((int)(mh_mode << 0x1e) < 0) {
    CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
  }
  else {
    iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_3c);
    CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    if (iVar1 == 0) {
      return 0;
    }
  }
  CRYPTO_mem_ctrl_constprop_2();
  if (amih != (_LHASH *)0x0) {
    CRYPTO_THREADID_current(aCStack_34);
    ptr = lh_delete(amih,aCStack_34);
    lh = amih;
    if (ptr != (void *)0x0) {
      data = *(void **)((int)ptr + 0x14);
      if (data != (void *)0x0) {
        *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + 1;
        lh_insert(lh,data);
      }
      iVar1 = *(int *)((int)ptr + 0x18) + -1;
      *(int *)((int)ptr + 0x18) = iVar1;
      if (iVar1 < 1) {
        *(undefined4 *)((int)ptr + 0x14) = 0;
        if (data != (void *)0x0) {
          *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + -1;
        }
        iVar1 = 1;
        CRYPTO_free(ptr);
      }
      else {
        iVar1 = 1;
      }
      goto LAB_0008a744;
    }
  }
  iVar1 = 0;
LAB_0008a744:
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
  if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
     (num_disable = num_disable + -1, num_disable == 0)) {
    mh_mode = mh_mode | 2;
    CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
  }
  CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  return iVar1;
}

