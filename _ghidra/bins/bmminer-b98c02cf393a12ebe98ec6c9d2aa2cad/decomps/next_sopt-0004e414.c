
char * next_sopt(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 local_14 [2];
  
  local_14[0] = 1;
  pcVar1 = (char *)next_opt(param_1,param_2,local_14);
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      return (char *)0x0;
    }
    if (*pcVar1 != '-') break;
    pcVar1 = (char *)next_opt(pcVar1,param_2,local_14);
  }
  return pcVar1;
}

