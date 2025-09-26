
void CRYPTO_mem_leaks_cb(undefined1 *cb)

{
  undefined1 *local_c;
  
  if (mh != (_LHASH *)0x0) {
    local_c = cb;
    CRYPTO_lock(9,0x1b,"mem_dbg.c",0x33a);
    lh_doall_arg(mh,(LHASH_DOALL_ARG_FN_TYPE)0x135c69,&local_c);
    CRYPTO_lock(10,0x1b,"mem_dbg.c",0x33d);
  }
  return;
}

