
int pop3_connect(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  
  uVar3 = DAT_00051310;
  uVar2 = DAT_00051300;
  iVar8 = 0;
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined4 *)(param_1 + 0x3f0) = uVar3;
  *(undefined4 *)(param_1 + 0x3f4) = uVar2;
  *(undefined4 *)(param_1 + 0x424) = 0xffffffff;
  *(undefined *)(param_1 + 0x1ed) = 0;
  uVar2 = DAT_00051304;
  *(int *)(param_1 + 0x3ec) = param_1;
  Curl_sasl_init(param_1 + 0x408,uVar2);
  Curl_pp_init(param_1 + 0x3c0);
  *(undefined *)(param_1 + 0x41c) = 1;
  pbVar10 = *(byte **)(param_1 + 0x128);
  while( true ) {
    pbVar6 = pbVar10;
    if (pbVar10 != (byte *)0x0) {
      pbVar6 = (byte *)0x1;
    }
    if (iVar8 != 0) {
      pbVar6 = (byte *)0x0;
    }
    if (pbVar6 == (byte *)0x0) goto LAB_000512bc;
    if (*pbVar10 == 0) break;
    pbVar6 = pbVar10;
    if (*pbVar10 == 0x3d) {
LAB_0005125a:
      pbVar7 = pbVar6 + 1;
      do {
        pbVar9 = pbVar7;
        pbVar7 = pbVar9 + 1;
      } while (*pbVar9 != 0x3b && *pbVar9 != 0);
    }
    else {
      do {
        pbVar6 = pbVar6 + 1;
        bVar1 = *pbVar6;
        bVar5 = bVar1;
        if (bVar1 != 0) {
          bVar5 = 1;
        }
      } while (bVar1 != 0x3d && bVar1 != 0);
      if (bVar1 == 0x3b) {
        bVar5 = 0;
      }
      else {
        bVar5 = bVar5 & 1;
      }
      if (bVar5 != 0) goto LAB_0005125a;
      pbVar7 = (byte *)0x0;
      pbVar9 = pbVar6;
    }
    iVar8 = curl_strnequal(pbVar10,DAT_00051308,5,pbVar7,param_4);
    if (iVar8 == 0) {
      iVar8 = 3;
    }
    else {
      pbVar6 = pbVar6 + 1;
      iVar8 = Curl_sasl_parse_url_auth_option(param_1 + 0x408,pbVar6,(int)pbVar9 - (int)pbVar6);
      if ((iVar8 != 0) &&
         (iVar4 = curl_strnequal(pbVar6,DAT_0005130c,(int)pbVar9 - (int)pbVar6), iVar4 != 0)) {
        iVar8 = 0;
        *(undefined4 *)(param_1 + 0x424) = 2;
        *(undefined4 *)(param_1 + 0x414) = 0;
      }
    }
    pbVar10 = pbVar9;
    if (*pbVar9 == 0x3b) {
      pbVar10 = pbVar9 + 1;
    }
  }
  iVar8 = 0;
LAB_000512bc:
  if (*(int *)(param_1 + 0x424) != 2) {
    iVar4 = *(int *)(param_1 + 0x414);
    if (iVar4 != 0) {
      iVar4 = iVar4 + 0x21;
      bVar11 = iVar4 == 0;
      if (bVar11) {
        iVar4 = -1;
      }
      if (bVar11) {
        *(int *)(param_1 + 0x424) = iVar4;
        goto LAB_000512de;
      }
      iVar4 = 4;
    }
    *(int *)(param_1 + 0x424) = iVar4;
  }
LAB_000512de:
  if (iVar8 == 0) {
    *(undefined4 *)(param_1 + 0x3f8) = 1;
    iVar8 = pop3_multi_statemach(param_1,param_2);
    return iVar8;
  }
  return iVar8;
}

