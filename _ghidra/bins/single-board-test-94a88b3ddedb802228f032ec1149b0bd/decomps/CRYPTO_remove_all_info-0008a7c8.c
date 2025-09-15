
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_remove_all_info(void)

{
  _LHASH *lh;
  void *ptr;
  int iVar1;
  void *data;
  _LHASH *p_Var2;
  CRYPTO_THREADID CStack_44;
  CRYPTO_THREADID aCStack_3c [4];
  
  if ((int)(mh_mode << 0x1f) < 0) {
    CRYPTO_THREADID_current(&CStack_44);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((int)(mh_mode << 0x1e) < 0) {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    else {
      iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_44);
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (iVar1 == 0) goto LAB_0008a7d6;
    }
    CRYPTO_mem_ctrl_constprop_2();
    p_Var2 = amih;
    if (amih != (_LHASH *)0x0) {
      p_Var2 = (_LHASH *)0x0;
      do {
        while( true ) {
          CRYPTO_THREADID_current(aCStack_3c);
          ptr = lh_delete(amih,aCStack_3c);
          lh = amih;
          if (ptr == (void *)0x0) goto LAB_0008a86a;
          data = *(void **)((int)ptr + 0x14);
          if (data != (void *)0x0) {
            *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + 1;
            lh_insert(lh,data);
          }
          iVar1 = *(int *)((int)ptr + 0x18) + -1;
          *(int *)((int)ptr + 0x18) = iVar1;
          if (0 < iVar1) break;
          *(undefined4 *)((int)ptr + 0x14) = 0;
          if (data != (void *)0x0) {
            *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + -1;
          }
          CRYPTO_free(ptr);
          p_Var2 = (_LHASH *)((int)&p_Var2->b + 1);
          if (amih == (_LHASH *)0x0) goto LAB_0008a86a;
        }
        p_Var2 = (_LHASH *)((int)&p_Var2->b + 1);
      } while (amih != (_LHASH *)0x0);
    }
LAB_0008a86a:
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
       (num_disable = num_disable + -1, num_disable == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
  else {
LAB_0008a7d6:
    p_Var2 = (_LHASH *)0x0;
  }
  return (int)p_Var2;
}

