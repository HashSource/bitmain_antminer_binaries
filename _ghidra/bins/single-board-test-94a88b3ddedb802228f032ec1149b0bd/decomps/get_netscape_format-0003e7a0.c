
void get_netscape_format(int param_1)

{
  char *pcVar1;
  undefined *puVar2;
  char *pcVar3;
  undefined2 *puVar4;
  char *pcVar5;
  char *pcVar6;
  
  puVar2 = &DAT_0013a6fc;
  pcVar1 = "#HttpOnly_";
  if (*(char *)(param_1 + 0x32) == '\0') {
    pcVar1 = "";
  }
  if (*(char *)(param_1 + 0x24) == '\0') {
    pcVar3 = *(char **)(param_1 + 0x14);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "unknown";
    }
    pcVar5 = "FALSE";
  }
  else {
    pcVar3 = *(char **)(param_1 + 0x14);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "unknown";
    }
    else if (*pcVar3 != '.') {
      puVar2 = &DAT_00136984;
    }
    pcVar5 = "TRUE";
  }
  puVar4 = *(undefined2 **)(param_1 + 0xc);
  if (puVar4 == (undefined2 *)0x0) {
    puVar4 = &DAT_00135588;
  }
  pcVar6 = "FALSE";
  if (*(char *)(param_1 + 0x30) != '\0') {
    pcVar6 = "TRUE";
  }
  curl_maprintf("%s%s%s\t%s\t%s\t%s\t%lld\t%s\t%s",pcVar1,puVar2,pcVar3,pcVar5,puVar4,pcVar6);
  return;
}

