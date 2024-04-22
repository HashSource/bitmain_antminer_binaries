
char * first_lopt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined8 uVar4;
  
  uVar4 = first_opt();
  piVar3 = (int *)((ulonglong)uVar4 >> 0x20);
  pcVar2 = (char *)uVar4;
  if (pcVar2 != (char *)0x0) {
    cVar1 = *pcVar2;
    while( true ) {
      if (cVar1 == '-') {
        *piVar3 = *piVar3 + -1;
        return pcVar2 + 1;
      }
      pcVar2 = (char *)next_opt(pcVar2,param_1,piVar3,cVar1,param_4);
      if (pcVar2 == (char *)0x0) break;
      cVar1 = *pcVar2;
    }
  }
  return (char *)0x0;
}

