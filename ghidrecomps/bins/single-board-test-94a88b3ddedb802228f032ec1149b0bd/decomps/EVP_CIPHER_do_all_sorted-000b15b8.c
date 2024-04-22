
void EVP_CIPHER_do_all_sorted(fn *fn,void *arg)

{
  void *local_10;
  fn *local_c;
  
  local_10 = arg;
  local_c = fn;
  OBJ_NAME_do_all_sorted(2,do_all_cipher_fn + 1,&local_10);
  return;
}

