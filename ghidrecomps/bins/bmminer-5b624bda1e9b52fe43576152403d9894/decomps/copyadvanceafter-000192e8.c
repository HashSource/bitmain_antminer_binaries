
void copyadvanceafter(char ch,char **param,char **buf)

{
  char cVar1;
  char **ppcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  ppcVar2 = (char **)(int)ch;
  pcVar4 = *ppcVar2;
  cVar1 = *pcVar4;
  do {
    if (cVar1 == '\0') {
LAB_00019320:
      pcVar4 = *param;
      *pcVar4 = '\0';
      *param = pcVar4 + 1;
      return;
    }
    if (cVar1 == ',') {
      *ppcVar2 = pcVar4 + 1;
      goto LAB_00019320;
    }
    if ((cVar1 == '\\') && (pcVar5 = pcVar4 + 1, pcVar4[1] != '\0')) {
      *ppcVar2 = pcVar5;
    }
    else {
      pcVar5 = *ppcVar2;
    }
    pcVar3 = *param;
    pcVar4 = pcVar5 + 1;
    *pcVar3 = *pcVar5;
    *param = pcVar3 + 1;
    *ppcVar2 = pcVar4;
    cVar1 = pcVar5[1];
  } while( true );
}

