
/* WARNING: Unknown calling convention */

char * next_name(char *names,uint *len)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar3 = *len;
  cVar1 = names[uVar3];
  if (cVar1 == ' ' || cVar1 == '=') {
    pcVar2 = (char *)0x0;
  }
  else {
    uVar4 = 0;
    if (cVar1 == '\0') {
      pcVar2 = (char *)0x0;
    }
    else {
      cVar1 = names[uVar3 + 2];
      pcVar2 = names + uVar3 + 2;
      if (cVar1 == '\0') {
        uVar4 = 0;
      }
      else if (((cVar1 != '|') && (cVar1 != '=')) && (pcVar5 = pcVar2, cVar1 != ' ')) {
        while( true ) {
          cVar1 = pcVar5[1];
          uVar4 = uVar4 + 1;
          if ((cVar1 == '\0') || (cVar1 == '|')) break;
          if ((cVar1 == '=') || (pcVar5 = pcVar5 + 1, cVar1 == ' ')) break;
        }
      }
      *len = uVar4;
    }
  }
  return pcVar2;
}

