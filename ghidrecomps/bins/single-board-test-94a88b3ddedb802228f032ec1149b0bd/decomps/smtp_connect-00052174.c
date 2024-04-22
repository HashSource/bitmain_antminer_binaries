
int smtp_connect(int param_1,undefined *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  uVar3 = DAT_00052278;
  uVar2 = DAT_0005226c;
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined4 *)(param_1 + 0x3f4) = uVar2;
  *(undefined4 *)(param_1 + 0x3f0) = uVar3;
  uVar2 = DAT_00052270;
  *(undefined *)(param_1 + 0x1ed) = 0;
  *(int *)(param_1 + 0x3ec) = param_1;
  Curl_sasl_init(param_1 + 0x404,uVar2);
  Curl_pp_init(param_1 + 0x3c0);
  iVar7 = 0;
  *(undefined *)(param_1 + 0x418) = 1;
  pbVar9 = *(byte **)(param_1 + 0x128);
  while( true ) {
    pbVar6 = pbVar9;
    if (pbVar9 != (byte *)0x0) {
      pbVar6 = (byte *)0x1;
    }
    if (iVar7 != 0) {
      pbVar6 = (byte *)0x0;
    }
    if (pbVar6 == (byte *)0x0) break;
    if (*pbVar9 == 0) goto LAB_0005224c;
    pbVar6 = pbVar9;
    pbVar8 = pbVar9;
    if (*pbVar9 == 0x3d) {
LAB_00052202:
      do {
        pbVar8 = pbVar8 + 1;
      } while (*pbVar8 != 0x3b && *pbVar8 != 0);
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
      pbVar8 = pbVar6;
      if (bVar5 != 0) goto LAB_00052202;
    }
    iVar4 = curl_strnequal(pbVar9,DAT_00052274,5);
    iVar7 = 3;
    if (iVar4 != 0) {
      iVar7 = Curl_sasl_parse_url_auth_option
                        (param_1 + 0x404,pbVar6 + 1,(int)pbVar8 - (int)(pbVar6 + 1));
    }
    pbVar9 = pbVar8;
    if (*pbVar8 == 0x3b) {
      pbVar9 = pbVar8 + 1;
    }
  }
  if (iVar7 != 0) {
    return iVar7;
  }
LAB_0005224c:
  iVar7 = smtp_parse_url_path(param_1);
  if (iVar7 != 0) {
    return iVar7;
  }
  *(undefined4 *)(param_1 + 0x3f8) = 1;
  iVar7 = smtp_multi_statemach(param_1,param_2);
  return iVar7;
}

