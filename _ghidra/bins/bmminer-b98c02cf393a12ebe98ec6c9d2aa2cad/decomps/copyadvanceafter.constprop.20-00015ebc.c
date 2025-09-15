
void copyadvanceafter_constprop_20(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  pcVar2 = (char *)*param_1;
  cVar1 = *pcVar2;
  do {
    if (cVar1 == '\0') {
LAB_00015ef4:
      puVar4 = (undefined1 *)*param_2;
      *param_2 = puVar4 + 1;
      *puVar4 = 0;
      return;
    }
    if (cVar1 == ',') {
      *param_1 = pcVar2 + 1;
      goto LAB_00015ef4;
    }
    if ((cVar1 == '\\') && (pcVar2[1] != '\0')) {
      *param_1 = pcVar2 + 1;
    }
    puVar3 = (undefined1 *)*param_2;
    *param_2 = puVar3 + 1;
    puVar4 = (undefined1 *)*param_1;
    *param_1 = puVar4 + 1;
    *puVar3 = *puVar4;
    pcVar2 = (char *)*param_1;
    cVar1 = *pcVar2;
  } while( true );
}

