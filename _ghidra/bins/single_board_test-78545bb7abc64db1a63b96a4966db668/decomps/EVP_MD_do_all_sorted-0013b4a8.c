
void EVP_MD_do_all_sorted(fn *fn,void *arg)

{
  void *local_18;
  fn *local_14;
  
  OPENSSL_init_crypto(8,0,0);
  local_18 = arg;
  local_14 = fn;
  OBJ_NAME_do_all_sorted(1,(fn *)0x13b309,&local_18);
  return;
}

