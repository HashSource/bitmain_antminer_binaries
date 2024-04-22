
char * enable_debug(_Bool *flag)

{
  _Bool *flag_local;
  
  *flag = true;
  opt_log_output = true;
  return (char *)0x0;
}

