
int CRYPTO_mem_ctrl(int mode)

{
  uint uVar1;
  int iVar2;
  CRYPTO_THREADID CStack_18;
  
  uVar1 = mh_mode;
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
  switch(mode) {
  case 0:
    mh_mode = 0;
    num_disable = 0;
    break;
  case 1:
    mh_mode = 3;
    num_disable = 0;
    break;
  case 2:
    if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
       (num_disable = num_disable + -1, num_disable == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    break;
  case 3:
    if ((int)(mh_mode << 0x1f) < 0) {
      CRYPTO_THREADID_current(&CStack_18);
      if ((num_disable == 0) ||
         (iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_18), iVar2 != 0
         )) {
        CRYPTO_lock(10,0x14,"mem_dbg.c",0xf4);
        CRYPTO_lock(9,0x1b,"mem_dbg.c",0xfb);
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xfc);
        mh_mode = mh_mode & 0xfffffffd;
        CRYPTO_THREADID_cpy((CRYPTO_THREADID *)&disabling_threadid,&CStack_18);
      }
      num_disable = num_disable + 1;
    }
  }
  CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  return uVar1;
}

