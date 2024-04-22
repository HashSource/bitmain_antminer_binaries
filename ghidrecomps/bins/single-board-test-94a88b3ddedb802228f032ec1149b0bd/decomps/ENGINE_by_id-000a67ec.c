
ENGINE * ENGINE_by_id(char *id)

{
  char **ppcVar1;
  int iVar2;
  char *pcVar3;
  ENGINE *e;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char **ppcVar7;
  char *pcVar8;
  char *pcVar9;
  
  if (id == (char *)0x0) {
    ERR_put_error(0x26,0x6a,0x43,DAT_000a6958,0x149);
    return (ENGINE *)0x0;
  }
  CRYPTO_lock(9,0x1e,DAT_000a6958,0x14c);
  for (ppcVar7 = (char **)*DAT_000a695c; ppcVar7 != (char **)0x0; ppcVar7 = (char **)ppcVar7[0x1b])
  {
    iVar2 = strcmp(id,*ppcVar7);
    if (iVar2 == 0) {
      if ((int)ppcVar7[0x15] << 0x1d < 0) {
        ppcVar1 = (char **)ENGINE_new();
        if (ppcVar1 == (char **)0x0) break;
        pcVar8 = ppcVar7[1];
        pcVar6 = ppcVar7[3];
        pcVar3 = ppcVar7[5];
        *ppcVar1 = *ppcVar7;
        ppcVar1[1] = pcVar8;
        pcVar8 = ppcVar7[6];
        pcVar5 = ppcVar7[4];
        ppcVar1[2] = ppcVar7[2];
        pcVar4 = ppcVar7[7];
        pcVar9 = ppcVar7[0xf];
        ppcVar1[3] = pcVar6;
        ppcVar1[7] = pcVar4;
        pcVar4 = ppcVar7[8];
        pcVar6 = ppcVar7[0x11];
        ppcVar1[5] = pcVar3;
        ppcVar1[8] = pcVar4;
        pcVar3 = ppcVar7[9];
        ppcVar1[6] = pcVar8;
        ppcVar1[4] = pcVar5;
        ppcVar1[9] = pcVar3;
        pcVar3 = ppcVar7[10];
        ppcVar1[0xf] = pcVar9;
        ppcVar1[10] = pcVar3;
        ppcVar1[0xb] = ppcVar7[0xb];
        ppcVar1[0xd] = ppcVar7[0xd];
        ppcVar1[0xe] = ppcVar7[0xe];
        ppcVar1[0x10] = ppcVar7[0x10];
        ppcVar1[0x11] = pcVar6;
        pcVar3 = ppcVar7[0x14];
        pcVar8 = ppcVar7[0x15];
        ppcVar1[0x12] = ppcVar7[0x12];
        ppcVar1[0x14] = pcVar3;
        ppcVar1[0x15] = pcVar8;
      }
      else {
        ppcVar7[0x16] = ppcVar7[0x16] + 1;
        ppcVar1 = ppcVar7;
      }
      CRYPTO_lock(10,0x1e,DAT_000a6958,0x163);
      return (ENGINE *)ppcVar1;
    }
  }
  CRYPTO_lock(10,0x1e,DAT_000a6958,0x163);
  iVar2 = strcmp(id,DAT_000a6960);
  if (iVar2 != 0) {
    pcVar3 = getenv(DAT_000a6964);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = DAT_000a6968;
    }
    e = ENGINE_by_id(DAT_000a6960);
    if (e != (ENGINE *)0x0) {
      iVar2 = ENGINE_ctrl_cmd_string(e,DAT_000a696c,id,0);
      if ((((iVar2 != 0) &&
           (iVar2 = ENGINE_ctrl_cmd_string(e,DAT_000a6970,DAT_000a6974,0), iVar2 != 0)) &&
          (iVar2 = ENGINE_ctrl_cmd_string(e,DAT_000a6978,pcVar3,0), iVar2 != 0)) &&
         ((iVar2 = ENGINE_ctrl_cmd_string(e,DAT_000a697c,DAT_000a6980,0), iVar2 != 0 &&
          (iVar2 = ENGINE_ctrl_cmd_string(e,DAT_000a6984,(char *)0x0,0), iVar2 != 0)))) {
        return e;
      }
      goto LAB_000a68c2;
    }
  }
  e = (ENGINE *)0x0;
LAB_000a68c2:
  ENGINE_free(e);
  ERR_put_error(0x26,0x6a,0x74,DAT_000a6958,0x185);
  ERR_add_error_data(2,DAT_000a6988,id);
  return (ENGINE *)0x0;
}

