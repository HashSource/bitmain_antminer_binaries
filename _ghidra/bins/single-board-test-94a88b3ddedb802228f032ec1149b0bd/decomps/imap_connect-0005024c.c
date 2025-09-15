
uint imap_connect(int param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined4 *)(param_1 + 0x3f4) = 0x4fec9;
  *(undefined4 *)(param_1 + 0x3f0) = 0x50929;
  *(undefined4 *)(param_1 + 0x418) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  *(int *)(param_1 + 0x3ec) = param_1;
  Curl_sasl_init(param_1 + 0x400,saslimap);
  Curl_pp_init(param_1 + 0x3c0);
  uVar5 = 0;
  *(undefined1 *)(param_1 + 0x414) = 1;
  pbVar7 = *(byte **)(param_1 + 0x128);
  while( true ) {
    pbVar4 = pbVar7;
    if (pbVar7 != (byte *)0x0) {
      pbVar4 = (byte *)0x1;
    }
    if (uVar5 != 0) {
      pbVar4 = (byte *)0x0;
    }
    if ((pbVar4 == (byte *)0x0) || (uVar5 = (uint)*pbVar7, uVar5 == 0)) break;
    pbVar4 = pbVar7;
    pbVar6 = pbVar7;
    if (uVar5 == 0x3d) {
LAB_000502de:
      do {
        pbVar6 = pbVar6 + 1;
      } while (*pbVar6 != 0x3b && *pbVar6 != 0);
    }
    else {
      do {
        pbVar4 = pbVar4 + 1;
        bVar1 = *pbVar4;
        bVar3 = bVar1;
        if (bVar1 != 0) {
          bVar3 = 1;
        }
      } while (bVar1 != 0x3d && bVar1 != 0);
      if (bVar1 == 0x3b) {
        bVar3 = 0;
      }
      else {
        bVar3 = bVar3 & 1;
      }
      pbVar6 = pbVar4;
      if (bVar3 != 0) goto LAB_000502de;
    }
    iVar2 = curl_strnequal(pbVar7,"AUTH=",5);
    uVar5 = 3;
    if (iVar2 != 0) {
      uVar5 = Curl_sasl_parse_url_auth_option
                        (param_1 + 0x400,pbVar4 + 1,(int)pbVar6 - (int)(pbVar4 + 1));
    }
    pbVar7 = pbVar6;
    if (*pbVar6 == 0x3b) {
      pbVar7 = pbVar6 + 1;
    }
  }
  iVar2 = *(int *)(param_1 + 0x40c);
  if (iVar2 != 0) {
    iVar2 = iVar2 + 0x21;
    bVar8 = iVar2 == 0;
    if (bVar8) {
      iVar2 = -1;
    }
    if (bVar8) {
      *(int *)(param_1 + 0x418) = iVar2;
      goto LAB_00050332;
    }
    iVar2 = 2;
  }
  *(int *)(param_1 + 0x418) = iVar2;
LAB_00050332:
  if (uVar5 == 0) {
    *(undefined4 *)(param_1 + 0x3f8) = 1;
    *(undefined2 *)(param_1 + 0x420) = 0x2a;
    uVar5 = imap_multi_statemach(param_1,param_2);
    return uVar5;
  }
  return uVar5;
}

