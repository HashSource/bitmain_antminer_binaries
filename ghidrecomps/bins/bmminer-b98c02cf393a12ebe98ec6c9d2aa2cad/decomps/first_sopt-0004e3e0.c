
char * first_sopt(undefined4 param_1)

{
  char *pcVar1;
  undefined4 local_14 [2];
  
  local_14[0] = 0;
  pcVar1 = (char *)first_opt(param_1,local_14);
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      return (char *)0x0;
    }
    if (*pcVar1 != '-') break;
    pcVar1 = (char *)next_opt(pcVar1,param_1,local_14);
  }
  return pcVar1;
}

