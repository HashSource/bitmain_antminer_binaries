
void EVP_MD_do_all(fn *fn,void *arg)

{
  void *local_18;
  fn *local_14;
  
  OPENSSL_init_crypto(8,0,0);
  local_18 = arg;
  local_14 = fn;
  OBJ_NAME_do_all(1,(fn *)0x12d4e1,&local_18);
  return;
}

