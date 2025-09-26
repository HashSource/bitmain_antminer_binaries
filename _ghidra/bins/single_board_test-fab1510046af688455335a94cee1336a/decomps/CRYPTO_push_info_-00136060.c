
int CRYPTO_push_info_(char *info,char *file,int line)

{
  CRYPTO_THREADID *id;
  void *pvVar1;
  int iVar2;
  CRYPTO_THREADID CStack_28;
  
  if ((int)(mh_mode << 0x1f) < 0) {
    CRYPTO_THREADID_current(&CStack_28);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((int)(mh_mode << 0x1e) < 0) {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    else {
      iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_28);
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (iVar2 == 0) {
        return 0;
      }
    }
    CRYPTO_mem_ctrl_constprop_2();
    id = (CRYPTO_THREADID *)CRYPTO_malloc(0x1c,"mem_dbg.c",0x18d);
    if (id != (CRYPTO_THREADID *)0x0) {
      if ((amih == (_LHASH *)0x0) &&
         (amih = lh_new((LHASH_HASH_FN_TYPE)0x135c85,(LHASH_COMP_FN_TYPE)0x135e45),
         amih == (_LHASH *)0x0)) {
        CRYPTO_free(id);
      }
      else {
        CRYPTO_THREADID_current(id);
        id[1].ptr = file;
        id[1].val = line;
        id[2].ptr = info;
        id[3].ptr = (void *)0x1;
        id[2].val = 0;
        pvVar1 = lh_insert(amih,id);
        if (pvVar1 != (void *)0x0) {
          id[2].val = (ulong)pvVar1;
        }
      }
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
       (num_disable = num_disable + -1, num_disable == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
  return 0;
}

