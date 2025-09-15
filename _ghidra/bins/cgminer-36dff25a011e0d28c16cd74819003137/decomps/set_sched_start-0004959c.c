
char * set_sched_start(char *arg)

{
  char *pcVar1;
  char *arg_local;
  
  pcVar1 = set_schedtime(arg,&schedstart);
  return pcVar1;
}

