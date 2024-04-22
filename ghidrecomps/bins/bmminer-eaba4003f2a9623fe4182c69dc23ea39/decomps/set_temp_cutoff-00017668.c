
char * set_temp_cutoff(char *arg)

{
  int iVar1;
  char *pcVar2;
  char *arg_local;
  int val;
  
  if ((arg == (char *)0x0) || (*arg == '\0')) {
    pcVar2 = "Invalid parameters for set temp cutoff";
  }
  else {
    iVar1 = atoi(arg);
    if ((iVar1 < 0) || (200 < iVar1)) {
      pcVar2 = "Invalid value passed to set temp cutoff";
    }
    else {
      pcVar2 = (char *)0x0;
      temp_cutoff_str = arg;
    }
  }
  return pcVar2;
}

