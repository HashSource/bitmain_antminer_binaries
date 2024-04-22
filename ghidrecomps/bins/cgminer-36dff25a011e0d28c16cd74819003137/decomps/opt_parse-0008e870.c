
_Bool opt_parse(int *argc,char **argv,_func_void_char_ptr_varargs *errlog)

{
  undefined uVar1;
  bool bVar2;
  _func_void_char_ptr_varargs *errlog_local;
  char **argv_local;
  int *argc_local;
  uint offset;
  int ret;
  
  offset = 0;
  opt_argv0 = *argv;
  do {
    ret = parse_one(argc,argv,&offset,errlog);
  } while (ret == 1);
  bVar2 = ret == 0;
  if (bVar2) {
    ret = 1;
  }
  uVar1 = (undefined)ret;
  if (!bVar2) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

