
char * opt_set_intval(char *arg,int *i)

{
  int *i_local;
  char *arg_local;
  long l;
  char *err;
  
  err = opt_set_longval(arg,&l);
  if ((err == (char *)0x0) && (*i = l, *i != l)) {
    err = arg_bad("value \'%s\' does not fit into an integer",arg);
  }
  return err;
}

