
void CRYPTO_dbg_realloc(void *addr1,void *addr2,int num,char *file,int line,int before_p)

{
  undefined4 *data;
  int iVar1;
  CRYPTO_THREADID CStack_44;
  void *local_3c [9];
  
  if ((before_p == 1) && (addr2 != (void *)0x0)) {
    if (addr1 == (void *)0x0) {
      CRYPTO_dbg_malloc(addr2,num,file,line,0x81);
    }
    else if ((int)(mh_mode << 0x1f) < 0) {
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
      CRYPTO_mem_ctrl_constprop_2();
      local_3c[0] = addr1;
      data = (undefined4 *)lh_delete(mh,local_3c);
      if (data != (undefined4 *)0x0) {
        *data = addr2;
        data[1] = num;
        lh_insert(mh,data);
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

