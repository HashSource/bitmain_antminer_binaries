
void CRYPTO_mem_leaks_fp(FILE *param_1)

{
  BIO_METHOD *type;
  BIO *bp;
  
  if (mh != 0) {
    CRYPTO_mem_ctrl_constprop_2();
    type = BIO_s_file();
    bp = BIO_new(type);
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
       (num_disable = num_disable + -1, num_disable == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    if (bp != (BIO *)0x0) {
      BIO_ctrl(bp,0x6a,0,param_1);
      CRYPTO_mem_leaks(bp);
      BIO_free(bp);
      return;
    }
  }
  return;
}

