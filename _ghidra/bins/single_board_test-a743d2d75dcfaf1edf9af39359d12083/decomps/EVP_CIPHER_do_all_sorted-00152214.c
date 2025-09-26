
void EVP_CIPHER_do_all_sorted(fn *fn,void *arg)

{
  void *local_10;
  fn *local_c;
  
  local_10 = arg;
  local_c = fn;
  OBJ_NAME_do_all_sorted(2,(fn *)0x1520c1,&local_10);
  return;
}

