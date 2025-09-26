
void OBJ_NAME_do_all(int type,fn *fn,void *arg)

{
  int local_14;
  fn *local_10;
  void *local_c;
  
  local_14 = type;
  local_10 = fn;
  local_c = arg;
  OPENSSL_LH_doall_arg(names_lh,0x14bc05,&local_14);
  return;
}

