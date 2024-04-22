
char * opt_set_ulongval(char *arg,ulong *ul)

{
  ulong *ul_local;
  char *arg_local;
  long l;
  char *err;
  
  err = opt_set_longval(arg,&l);
  if (err == (char *)0x0) {
    *ul = l;
    if (l < 0) {
      err = arg_bad("\'%s\' is negative",arg);
    }
    else {
      err = (char *)0x0;
    }
  }
  return err;
}

