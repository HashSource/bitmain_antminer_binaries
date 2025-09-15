
void CRYPTO_dbg_free(void *addr,int before_p)

{
  void *ptr;
  int iVar1;
  void *ptr_00;
  void *ptr_01;
  CRYPTO_THREADID CStack_44;
  void *local_3c [10];
  
  if (((before_p == 0) && (addr != (void *)0x0)) && ((int)(mh_mode << 0x1f) < 0)) {
    CRYPTO_THREADID_current(&CStack_44);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((int)(mh_mode << 0x1e) < 0) {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    else {
      iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_44);
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (iVar1 == 0) {
        return;
      }
    }
    if (mh != (_LHASH *)0x0) {
      CRYPTO_mem_ctrl_constprop_2();
      local_3c[0] = addr;
      ptr = lh_delete(mh,local_3c);
      if (ptr != (void *)0x0) {
        ptr_00 = *(void **)((int)ptr + 0x20);
        if ((ptr_00 != (void *)0x0) &&
           (iVar1 = *(int *)((int)ptr_00 + 0x18) + -1, *(int *)((int)ptr_00 + 0x18) = iVar1,
           iVar1 < 1)) {
          ptr_01 = *(void **)((int)ptr_00 + 0x14);
          if ((ptr_01 != (void *)0x0) &&
             (iVar1 = *(int *)((int)ptr_01 + 0x18) + -1, *(int *)((int)ptr_01 + 0x18) = iVar1,
             iVar1 < 1)) {
            if (*(int *)((int)ptr_01 + 0x14) != 0) {
              app_info_free();
            }
            CRYPTO_free(ptr_01);
          }
          CRYPTO_free(ptr_00);
        }
        CRYPTO_free(ptr);
      }
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
         (num_disable = num_disable + -1, num_disable == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      }
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
  }
  return;
}

