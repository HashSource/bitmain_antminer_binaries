
void CRYPTO_mem_leaks(bio_st *bio)

{
  uint uVar1;
  ulong uVar2;
  bio_st *local_24;
  int local_20;
  undefined4 local_1c;
  
  if ((mh != (_LHASH *)0x0) || (amih != (_LHASH *)0x0)) {
    CRYPTO_mem_ctrl_constprop_2();
    local_1c = 0;
    local_20 = 0;
    local_24 = bio;
    if ((mh == (_LHASH *)0x0) ||
       (lh_doall_arg(mh,(LHASH_DOALL_ARG_FN_TYPE)0x135e41,&local_24), local_20 == 0)) {
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x2eb);
      uVar1 = mh_mode;
      mh_mode = 0;
      if (mh != (_LHASH *)0x0) {
        lh_free(mh);
        mh = (_LHASH *)0x0;
      }
      if ((amih != (_LHASH *)0x0) && (uVar2 = lh_num_items(amih), uVar2 == 0)) {
        lh_free(amih);
        amih = (_LHASH *)0x0;
      }
      mh_mode = uVar1;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x300);
    }
    else {
      BIO_printf(bio,"%ld bytes leaked in %d chunks\n",local_1c);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
       (num_disable = num_disable + -1, num_disable == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
  return;
}

