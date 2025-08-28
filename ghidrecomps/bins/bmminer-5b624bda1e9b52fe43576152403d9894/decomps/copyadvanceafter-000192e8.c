
void copyadvanceafter(char ch,char **param,char **buf)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  puVar2 = (undefined4 *)(int)ch;
  pcVar4 = (char *)*puVar2;
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
      *puVar2 = pcVar4 + 1;
      goto LAB_00019320;
    }
    if ((cVar1 == '\\') && (pcVar5 = pcVar4 + 1, pcVar4[1] != '\0')) {
      *puVar2 = pcVar5;
    }
    else {
      pcVar5 = (char *)*puVar2;
    }
    pcVar3 = *param;
    pcVar4 = pcVar5 + 1;
    *pcVar3 = *pcVar5;
    *param = pcVar3 + 1;
    *puVar2 = pcVar4;
    cVar1 = pcVar5[1];
  } while( true );
}

