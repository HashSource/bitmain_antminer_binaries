
void get_netscape_format(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar1 = DAT_0003e834;
  if (*(char *)(param_1 + 0x32) == '\0') {
    uVar1 = DAT_0003e830;
  }
  uVar2 = DAT_0003e830;
  if (*(char *)(param_1 + 0x24) == '\0') {
    pcVar3 = *(char **)(param_1 + 0x14);
    uVar6 = DAT_0003e848;
    if (*(char **)(param_1 + 0x14) == (char *)0x0) {
      pcVar3 = DAT_0003e844;
    }
  }
  else {
    pcVar4 = *(char **)(param_1 + 0x14);
    pcVar3 = DAT_0003e844;
    uVar6 = DAT_0003e84c;
    if ((pcVar4 != (char *)0x0) && (pcVar3 = pcVar4, *pcVar4 != '.')) {
      uVar2 = DAT_0003e840;
    }
  }
  iVar5 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar5 = DAT_0003e838;
  }
  uVar7 = DAT_0003e848;
  if (*(char *)(param_1 + 0x30) != '\0') {
    uVar7 = DAT_0003e84c;
  }
  curl_maprintf(DAT_0003e83c,uVar1,uVar2,pcVar3,uVar6,iVar5,uVar7);
  return;
}

