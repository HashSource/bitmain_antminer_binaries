
/* WARNING: Unknown calling convention */

char * set_default_config(char *arg)

{
  opt_set_charp(arg,&default_config);
  return (char *)0x0;
}

