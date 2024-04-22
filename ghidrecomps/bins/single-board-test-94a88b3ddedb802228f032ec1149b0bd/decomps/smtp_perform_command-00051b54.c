
void smtp_perform_command(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  
  piVar1 = param_1 + 0xf0;
  puVar3 = *(undefined4 **)(*(int *)(*param_1 + 0x14c) + 8);
  pcVar4 = *(char **)(*(int *)(*param_1 + 0x14c) + 4);
  if (puVar3 == (undefined4 *)0x0) {
    if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
      pcVar4 = DAT_00051ba4;
    }
    iVar2 = Curl_pp_sendf(piVar1,DAT_00051ba8,pcVar4);
  }
  else if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
    iVar2 = Curl_pp_sendf(piVar1,DAT_00051b9c,DAT_00051ba0,*puVar3);
  }
  else {
    iVar2 = Curl_pp_sendf(piVar1,DAT_00051b9c,pcVar4,*puVar3);
  }
  if (iVar2 == 0) {
    param_1[0xfe] = 7;
  }
  return;
}

