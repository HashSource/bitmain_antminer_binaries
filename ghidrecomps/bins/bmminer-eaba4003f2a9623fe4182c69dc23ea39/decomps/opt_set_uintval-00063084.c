
char * opt_set_uintval(char *arg,uint *ui)

{
  uint *ui_local;
  char *arg_local;
  int i;
  char *err;
  
  err = opt_set_intval(arg,&i);
  if (err == (char *)0x0) {
    if (i < 0) {
      err = arg_bad("\'%s\' is negative",arg);
    }
    else {
      *ui = i;
      err = (char *)0x0;
    }
  }
  return err;
}

