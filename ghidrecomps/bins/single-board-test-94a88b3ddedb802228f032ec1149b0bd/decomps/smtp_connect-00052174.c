
int smtp_connect(int param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined4 *)(param_1 + 0x3f4) = 0x5227d;
  *(undefined4 *)(param_1 + 0x3f0) = 0x52399;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  *(int *)(param_1 + 0x3ec) = param_1;
  Curl_sasl_init(param_1 + 0x404,saslsmtp);
  Curl_pp_init(param_1 + 0x3c0);
  iVar5 = 0;
  *(undefined1 *)(param_1 + 0x418) = 1;
  pbVar7 = *(byte **)(param_1 + 0x128);
  while( true ) {
    pbVar4 = pbVar7;
    if (pbVar7 != (byte *)0x0) {
      pbVar4 = (byte *)0x1;
    }
    if (iVar5 != 0) {
      pbVar4 = (byte *)0x0;
    }
    if (pbVar4 == (byte *)0x0) break;
    if (*pbVar7 == 0) goto LAB_0005224c;
    pbVar4 = pbVar7;
    pbVar6 = pbVar7;
    if (*pbVar7 == 0x3d) {
LAB_00052202:
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
      if (bVar3 != 0) goto LAB_00052202;
    }
    iVar2 = curl_strnequal(pbVar7,"AUTH=",5);
    iVar5 = 3;
    if (iVar2 != 0) {
      iVar5 = Curl_sasl_parse_url_auth_option
                        (param_1 + 0x404,pbVar4 + 1,(int)pbVar6 - (int)(pbVar4 + 1));
    }
    pbVar7 = pbVar6;
    if (*pbVar6 == 0x3b) {
      pbVar7 = pbVar6 + 1;
    }
  }
  if (iVar5 != 0) {
    return iVar5;
  }
LAB_0005224c:
  iVar5 = smtp_parse_url_path(param_1);
  if (iVar5 != 0) {
    return iVar5;
  }
  *(undefined4 *)(param_1 + 0x3f8) = 1;
  iVar5 = smtp_multi_statemach(param_1,param_2);
  return iVar5;
}

