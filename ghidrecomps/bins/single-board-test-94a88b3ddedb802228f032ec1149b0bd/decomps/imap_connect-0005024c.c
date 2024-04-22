
uint imap_connect(int param_1,undefined *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  
  uVar4 = DAT_0005036c;
  uVar2 = DAT_0005035c;
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined4 *)(param_1 + 0x3f4) = uVar2;
  *(undefined4 *)(param_1 + 0x3f0) = uVar4;
  *(undefined4 *)(param_1 + 0x418) = 0xffffffff;
  *(undefined *)(param_1 + 0x1ed) = 0;
  uVar2 = DAT_00050360;
  *(int *)(param_1 + 0x3ec) = param_1;
  Curl_sasl_init(param_1 + 0x400,uVar2);
  Curl_pp_init(param_1 + 0x3c0);
  uVar8 = 0;
  *(undefined *)(param_1 + 0x414) = 1;
  pbVar10 = *(byte **)(param_1 + 0x128);
  while( true ) {
    pbVar7 = pbVar10;
    if (pbVar10 != (byte *)0x0) {
      pbVar7 = (byte *)0x1;
    }
    if (uVar8 != 0) {
      pbVar7 = (byte *)0x0;
    }
    if ((pbVar7 == (byte *)0x0) || (uVar8 = (uint)*pbVar10, uVar8 == 0)) break;
    pbVar7 = pbVar10;
    pbVar9 = pbVar10;
    if (uVar8 == 0x3d) {
LAB_000502de:
      do {
        pbVar9 = pbVar9 + 1;
      } while (*pbVar9 != 0x3b && *pbVar9 != 0);
    }
    else {
      do {
        pbVar7 = pbVar7 + 1;
        bVar1 = *pbVar7;
        bVar6 = bVar1;
        if (bVar1 != 0) {
          bVar6 = 1;
        }
      } while (bVar1 != 0x3d && bVar1 != 0);
      if (bVar1 == 0x3b) {
        bVar6 = 0;
      }
      else {
        bVar6 = bVar6 & 1;
      }
      pbVar9 = pbVar7;
      if (bVar6 != 0) goto LAB_000502de;
    }
    iVar5 = curl_strnequal(pbVar10,DAT_00050364,5);
    uVar8 = 3;
    if (iVar5 != 0) {
      uVar8 = Curl_sasl_parse_url_auth_option
                        (param_1 + 0x400,pbVar7 + 1,(int)pbVar9 - (int)(pbVar7 + 1));
    }
    pbVar10 = pbVar9;
    if (*pbVar9 == 0x3b) {
      pbVar10 = pbVar9 + 1;
    }
  }
  iVar5 = *(int *)(param_1 + 0x40c);
  if (iVar5 != 0) {
    iVar5 = iVar5 + 0x21;
    bVar11 = iVar5 == 0;
    if (bVar11) {
      iVar5 = -1;
    }
    if (bVar11) {
      *(int *)(param_1 + 0x418) = iVar5;
      goto LAB_00050332;
    }
    iVar5 = 2;
  }
  *(int *)(param_1 + 0x418) = iVar5;
LAB_00050332:
  puVar3 = DAT_00050368;
  if (uVar8 == 0) {
    *(undefined4 *)(param_1 + 0x3f8) = 1;
    *(undefined2 *)(param_1 + 0x420) = *puVar3;
    uVar8 = imap_multi_statemach(param_1,param_2);
    return uVar8;
  }
  return uVar8;
}

