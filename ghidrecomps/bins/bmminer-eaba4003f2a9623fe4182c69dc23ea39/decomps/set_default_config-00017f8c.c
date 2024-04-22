
char * set_default_config(char *arg)

{
  char *arg_local;
  
  opt_set_charp(arg,&default_config);
  return (char *)0x0;
}

