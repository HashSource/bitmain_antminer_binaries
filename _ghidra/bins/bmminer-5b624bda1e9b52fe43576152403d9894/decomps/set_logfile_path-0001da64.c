
/* WARNING: Unknown calling convention */

char * set_logfile_path(char *arg)

{
  opt_set_charp(arg,&opt_logfile_path);
  return (char *)0x0;
}

