
char * next_lopt(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  char *pcVar1;
  
  pcVar1 = (char *)next_opt();
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      return (char *)0x0;
    }
    if (*pcVar1 == '-') break;
    pcVar1 = (char *)next_opt(pcVar1,param_2,param_3,*pcVar1,param_4);
  }
  *param_3 = *param_3 + -1;
  return pcVar1 + 1;
}

