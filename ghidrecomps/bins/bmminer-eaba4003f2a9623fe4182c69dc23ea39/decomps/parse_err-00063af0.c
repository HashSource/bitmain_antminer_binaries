
int parse_err(_func_void_char_ptr_varargs *errlog,char *argv0,char *arg,uint len,char *problem)

{
  uint len_local;
  char *arg_local;
  char *argv0_local;
  _func_void_char_ptr_varargs *errlog_local;
  
  (*errlog)("%s: %.*s: %s",argv0,len,arg,problem);
  return -1;
}

