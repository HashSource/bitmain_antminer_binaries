
uint imap_done(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  uVar2 = *param_1;
  puVar4 = *(undefined4 **)(uVar2 + 0x14c);
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_2 != 0) {
    *(undefined *)((int)param_1 + 0x1ed) = 1;
    goto LAB_0004fd02;
  }
  if ((*(char *)(uVar2 + 0x329) != '\0') || (param_2 = 0, puVar4[7] != 0)) goto LAB_0004fd02;
  if (puVar4[3] == 0) {
    param_2 = (uint)*(byte *)(uVar2 + 0x309);
    if (param_2 == 0) goto LAB_0004fd02;
LAB_0004fd84:
    param_2 = Curl_pp_sendf(param_1 + 0xf0,DAT_0004fda4,DAT_0004fda8,uVar2,param_4);
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
  ppcVar1 = DAT_0004fda0;
  (**DAT_0004fda0)(puVar4[1]);
  pcVar3 = *ppcVar1;
  puVar4[1] = 0;
  (*pcVar3)(puVar4[2]);
  pcVar3 = *ppcVar1;
  puVar4[2] = 0;
  (*pcVar3)(puVar4[3]);
  pcVar3 = *ppcVar1;
  puVar4[3] = 0;
  (*pcVar3)(puVar4[4]);
  pcVar3 = *ppcVar1;
  puVar4[4] = 0;
  (*pcVar3)(puVar4[5]);
  pcVar3 = *ppcVar1;
  puVar4[5] = 0;
  (*pcVar3)(puVar4[6]);
  pcVar3 = *ppcVar1;
  puVar4[6] = 0;
  (*pcVar3)(puVar4[7]);
  puVar4[7] = 0;
  (**ppcVar1)(puVar4[8]);
  puVar4[8] = 0;
  *puVar4 = 0;
  return param_2;
}

