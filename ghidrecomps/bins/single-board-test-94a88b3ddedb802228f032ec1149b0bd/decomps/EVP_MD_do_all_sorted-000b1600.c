
void EVP_MD_do_all_sorted(fn *fn,void *arg)

{
  void *local_10;
  fn *local_c;
  
  local_10 = arg;
  local_c = fn;
  OBJ_NAME_do_all_sorted(1,do_all_md_fn + 1,&local_10);
  return;
}

