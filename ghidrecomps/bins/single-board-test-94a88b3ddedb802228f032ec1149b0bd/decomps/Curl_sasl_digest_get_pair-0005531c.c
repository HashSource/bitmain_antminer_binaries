
undefined4 Curl_sasl_digest_get_pair(char *param_1,char *param_2,byte *param_3,byte **param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  byte *pbVar11;
  bool bVar12;
  
  cVar5 = *param_1;
  if (cVar5 != '=' && cVar5 != '\0') {
    pcVar9 = param_1 + 0x100;
    pcVar1 = param_1 + 1;
    pcVar7 = param_2;
    do {
      param_1 = pcVar1;
      param_2 = pcVar7 + 1;
      *pcVar7 = cVar5;
      cVar5 = *param_1;
      if (cVar5 == '=' || cVar5 == '\0') break;
      pcVar1 = param_1 + 1;
      pcVar7 = param_2;
    } while (param_1 + 1 != pcVar9);
  }
  *param_2 = '\0';
  if (*param_1 == '=') {
    bVar4 = param_1[1];
    bVar12 = bVar4 == 0x22;
    if (bVar12) {
      bVar4 = param_1[2];
      pbVar11 = (byte *)(param_1 + 2);
    }
    else {
      pbVar11 = (byte *)(param_1 + 1);
    }
    uVar3 = (uint)bVar12;
    if (bVar4 != 0) {
      uVar8 = 0x3fe;
      uVar10 = 0;
      do {
        pbVar11 = pbVar11 + 1;
        if (bVar4 == 0x22) {
          if ((uVar3 & (uVar10 ^ 1)) == 0) goto LAB_00055388;
          uVar6 = 0;
          uVar10 = uVar6;
LAB_00055390:
          bVar4 = *pbVar11;
        }
        else {
          if (bVar4 < 0x23) {
            if ((bVar4 == 10) || (bVar4 == 0xd)) {
              uVar6 = 0;
              goto LAB_00055390;
            }
LAB_00055388:
            *param_3 = bVar4;
            param_3 = param_3 + 1;
            uVar6 = uVar8;
            uVar10 = 0;
            goto LAB_00055390;
          }
          if (bVar4 == 0x2c) {
            uVar6 = uVar3;
            if (uVar3 == 0) goto LAB_00055390;
            goto LAB_00055388;
          }
          if ((bVar4 != 0x5c) || (uVar10 != 0)) goto LAB_00055388;
          *param_3 = 0x5c;
          bVar4 = *pbVar11;
          uVar10 = 1;
          param_3 = param_3 + 1;
          uVar6 = uVar8;
        }
      } while ((bVar4 != 0) && (uVar8 = uVar6 - 1, uVar6 != 0));
    }
    uVar2 = 1;
    *param_3 = 0;
    *param_4 = pbVar11;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

