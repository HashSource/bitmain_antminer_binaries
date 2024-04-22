
void OBJ_NAME_do_all(int type,fn *fn,void *arg)

{
  int local_14;
  fn *local_10;
  void *local_c;
  
  local_14 = type;
  local_10 = fn;
  local_c = arg;
  lh_doall_arg(names_lh,do_all_fn_LHASH_DOALL_ARG + 1,&local_14);
  return;
}

