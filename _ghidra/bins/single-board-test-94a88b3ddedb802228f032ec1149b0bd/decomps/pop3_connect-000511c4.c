
int pop3_connect(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  
  iVar6 = 0;
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined4 *)(param_1 + 0x3f0) = 0x51715;
  *(undefined4 *)(param_1 + 0x3f4) = 0x51315;
  *(undefined4 *)(param_1 + 0x424) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  *(int *)(param_1 + 0x3ec) = param_1;
  Curl_sasl_init(param_1 + 0x408,saslpop3);
  Curl_pp_init(param_1 + 0x3c0);
  *(undefined1 *)(param_1 + 0x41c) = 1;
  pbVar8 = *(byte **)(param_1 + 0x128);
  while( true ) {
    pbVar4 = pbVar8;
    if (pbVar8 != (byte *)0x0) {
      pbVar4 = (byte *)0x1;
    }
    if (iVar6 != 0) {
      pbVar4 = (byte *)0x0;
    }
    if (pbVar4 == (byte *)0x0) goto LAB_000512bc;
    if (*pbVar8 == 0) break;
    pbVar4 = pbVar8;
    if (*pbVar8 == 0x3d) {
LAB_0005125a:
      pbVar5 = pbVar4 + 1;
      do {
        pbVar7 = pbVar5;
        pbVar5 = pbVar7 + 1;
      } while (*pbVar7 != 0x3b && *pbVar7 != 0);
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
      if (bVar3 != 0) goto LAB_0005125a;
      pbVar5 = (byte *)0x0;
      pbVar7 = pbVar4;
    }
    iVar6 = curl_strnequal(pbVar8,"AUTH=",5,pbVar5,param_4);
    if (iVar6 == 0) {
      iVar6 = 3;
    }
    else {
      pbVar4 = pbVar4 + 1;
      iVar6 = Curl_sasl_parse_url_auth_option(param_1 + 0x408,pbVar4,(int)pbVar7 - (int)pbVar4);
      if ((iVar6 != 0) &&
         (iVar2 = curl_strnequal(pbVar4,"+APOP",(int)pbVar7 - (int)pbVar4), iVar2 != 0)) {
        iVar6 = 0;
        *(undefined4 *)(param_1 + 0x424) = 2;
        *(undefined4 *)(param_1 + 0x414) = 0;
      }
    }
    pbVar8 = pbVar7;
    if (*pbVar7 == 0x3b) {
      pbVar8 = pbVar7 + 1;
    }
  }
  iVar6 = 0;
LAB_000512bc:
  if (*(int *)(param_1 + 0x424) != 2) {
    iVar2 = *(int *)(param_1 + 0x414);
    if (iVar2 != 0) {
      iVar2 = iVar2 + 0x21;
      bVar9 = iVar2 == 0;
      if (bVar9) {
        iVar2 = -1;
      }
      if (bVar9) {
        *(int *)(param_1 + 0x424) = iVar2;
        goto LAB_000512de;
      }
      iVar2 = 4;
    }
    *(int *)(param_1 + 0x424) = iVar2;
  }
LAB_000512de:
  if (iVar6 == 0) {
    *(undefined4 *)(param_1 + 0x3f8) = 1;
    iVar6 = pop3_multi_statemach(param_1,param_2);
    return iVar6;
  }
  return iVar6;
}

