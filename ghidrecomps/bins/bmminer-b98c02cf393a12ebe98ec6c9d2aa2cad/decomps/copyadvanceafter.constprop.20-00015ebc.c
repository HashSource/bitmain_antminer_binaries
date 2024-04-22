
void copyadvanceafter_constprop_20(char **param_1,char **param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = *param_1;
  cVar1 = *pcVar2;
  do {
    if (cVar1 == '\0') {
LAB_00015ef4:
      pcVar2 = *param_2;
      *param_2 = pcVar2 + 1;
      *pcVar2 = '\0';
      return;
    }
    if (cVar1 == ',') {
      *param_1 = pcVar2 + 1;
      goto LAB_00015ef4;
    }
    if ((cVar1 == '\\') && (pcVar2[1] != '\0')) {
      *param_1 = pcVar2 + 1;
    }
    pcVar3 = *param_2;
    *param_2 = pcVar3 + 1;
    pcVar2 = *param_1;
    *param_1 = pcVar2 + 1;
    *pcVar3 = *pcVar2;
    pcVar2 = *param_1;
    cVar1 = *pcVar2;
  } while( true );
}

