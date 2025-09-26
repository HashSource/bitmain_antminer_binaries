
void EVP_CIPHER_do_all_sorted(fn *fn,void *arg)

{
  void *local_18;
  fn *local_14;
  
  OPENSSL_init_crypto(4,0,0);
  local_18 = arg;
  local_14 = fn;
  OBJ_NAME_do_all_sorted(2,(fn *)0x13b2e5,&local_18);
  return;
}

