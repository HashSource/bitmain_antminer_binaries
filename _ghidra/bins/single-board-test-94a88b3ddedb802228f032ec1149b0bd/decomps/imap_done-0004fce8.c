
uint imap_done(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = *param_1;
  puVar3 = *(undefined4 **)(uVar2 + 0x14c);
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_2 != 0) {
    *(undefined1 *)((int)param_1 + 0x1ed) = 1;
    goto LAB_0004fd02;
  }
  if ((*(char *)(uVar2 + 0x329) != '\0') || (param_2 = 0, puVar3[7] != 0)) goto LAB_0004fd02;
  if (puVar3[3] == 0) {
    param_2 = (uint)*(byte *)(uVar2 + 0x309);
    if (param_2 == 0) goto LAB_0004fd02;
LAB_0004fd84:
    param_2 = Curl_pp_sendf(param_1 + 0xf0,"%s",&DAT_0013a6fc,uVar2,param_4);
    if (param_2 != 0) goto LAB_0004fd02;
    param_1[0xfe] = 0xc;
  }
  else {
    uVar2 = (uint)*(byte *)(uVar2 + 0x309);
    if (uVar2 != 0) goto LAB_0004fd84;
    param_1[0xfe] = 10;
  }
  param_2 = imap_block_statemach(param_1);
LAB_0004fd02:
  (*Curl_cfree)(puVar3[1]);
  pcVar1 = Curl_cfree;
  puVar3[1] = 0;
  (*pcVar1)(puVar3[2]);
  pcVar1 = Curl_cfree;
  puVar3[2] = 0;
  (*pcVar1)(puVar3[3]);
  pcVar1 = Curl_cfree;
  puVar3[3] = 0;
  (*pcVar1)(puVar3[4]);
  pcVar1 = Curl_cfree;
  puVar3[4] = 0;
  (*pcVar1)(puVar3[5]);
  pcVar1 = Curl_cfree;
  puVar3[5] = 0;
  (*pcVar1)(puVar3[6]);
  pcVar1 = Curl_cfree;
  puVar3[6] = 0;
  (*pcVar1)(puVar3[7]);
  puVar3[7] = 0;
  (*Curl_cfree)(puVar3[8]);
  puVar3[8] = 0;
  *puVar3 = 0;
  return param_2;
}

