
char * Curl_sasl_start(int *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  code **ppcVar7;
  char *__s;
  int iVar8;
  int iVar9;
  int local_30;
  int local_2c [2];
  
  iVar1 = *param_2;
  local_30 = 0;
  uVar5 = param_1[3] & param_1[2];
  param_1[4] = 0;
  *(char *)((int)param_1 + 0x16) = (char)param_3;
  local_2c[0] = 0;
  *param_4 = 0;
  iVar4 = local_30;
  if (((int)(uVar5 << 0x1a) < 0) && (*(char *)param_2[0x49] == '\0')) {
    param_1[4] = 0x20;
    __s = DAT_00056240;
    if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
      pcVar2 = (char *)sasl_create_login_message(iVar1,param_2[0x48],&local_30,local_2c);
      iVar9 = 0x10;
      iVar8 = 4;
      goto LAB_0005608a;
    }
    iVar9 = 0x10;
    iVar8 = 4;
    ppcVar7 = DAT_0005623c;
    pcVar2 = DAT_00056240;
  }
  else {
    ppcVar7 = DAT_0005623c;
    if (*(char *)((int)param_2 + 0x1f1) == '\0') {
      iVar9 = 0x10;
      pcVar2 = (char *)0x0;
      iVar8 = 0;
    }
    else if ((int)(uVar5 << 0x1c) < 0) {
      iVar9 = 0x10;
      param_1[4] = 8;
      iVar8 = 6;
      ppcVar7 = DAT_0005623c;
      pcVar2 = DAT_00056248;
    }
    else if ((int)(uVar5 << 0x1d) < 0) {
      iVar9 = 0x10;
      param_1[4] = 4;
      iVar8 = 5;
      ppcVar7 = DAT_0005623c;
      pcVar2 = DAT_00056244;
    }
    else if ((int)(uVar5 << 0x19) < 0) {
      param_1[4] = 0x40;
      if ((param_3 == 0) && (*(char *)(iVar1 + 0x408) == '\0')) {
        iVar9 = 9;
        iVar8 = 8;
        ppcVar7 = DAT_0005623c;
        pcVar2 = DAT_00056250;
      }
      else {
        pcVar2 = (char *)Curl_sasl_create_ntlm_type1_message
                                   (param_2[0x48],param_2[0x49],param_2 + 0x9d,&local_30,local_2c);
        iVar9 = 9;
        iVar8 = 8;
        __s = DAT_00056250;
LAB_0005608a:
        iVar4 = local_30;
        ppcVar7 = DAT_0005623c;
        if (pcVar2 != (char *)0x0) goto LAB_00056036;
        pcVar2 = __s;
        if (((local_30 != 0) && (uVar5 = *(uint *)(*param_1 + 0xc), uVar5 != 0)) &&
           (sVar3 = strlen(__s), ppcVar7 = DAT_0005623c, uVar5 < sVar3 + local_2c[0])) {
          (**DAT_0005623c)(iVar4);
          local_30 = 0;
          iVar4 = 0;
        }
      }
    }
    else if (((int)(uVar5 << 0x17) < 0) && (iVar6 = param_2[0x4b], iVar6 != 0)) {
      param_1[4] = 0x100;
      if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
        iVar9 = 0xe;
        iVar8 = 0xd;
        pcVar2 = (char *)sasl_create_oauth_bearer_message
                                   (iVar1,param_2[0x48],param_2[0x26],param_2[0x2c],iVar6,&local_30,
                                    local_2c);
        __s = DAT_0005624c;
        goto LAB_0005608a;
      }
      iVar9 = 0xe;
      iVar8 = 0xd;
      ppcVar7 = DAT_0005623c;
      pcVar2 = DAT_0005624c;
    }
    else if (((int)(uVar5 << 0x18) < 0) && (iVar8 = param_2[0x4b], iVar8 != 0)) {
      param_1[4] = 0x80;
      if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
        iVar9 = 0x10;
        pcVar2 = (char *)sasl_create_oauth_bearer_message
                                   (iVar1,param_2[0x48],0,0,iVar8,&local_30,local_2c);
        iVar8 = 0xd;
        __s = DAT_00056254;
        goto LAB_0005608a;
      }
      iVar9 = 0x10;
      iVar8 = 0xd;
      ppcVar7 = DAT_0005623c;
      pcVar2 = DAT_00056254;
    }
    else if ((int)(uVar5 << 0x1f) < 0) {
      param_1[4] = 1;
      if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
        iVar9 = 3;
        pcVar2 = (char *)sasl_create_login_message(iVar1,param_2[0x48],&local_30,local_2c);
        iVar8 = 2;
        __s = DAT_00056258;
        goto LAB_0005608a;
      }
      iVar9 = 3;
      iVar8 = 2;
      ppcVar7 = DAT_0005623c;
      pcVar2 = DAT_00056258;
    }
    else if ((uVar5 & 2) == 0) {
      iVar9 = 0x10;
      pcVar2 = (char *)0x0;
      iVar8 = 0;
    }
    else {
      param_1[4] = 2;
      if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
        iVar9 = 0x10;
        pcVar2 = (char *)sasl_create_plain_message
                                   (iVar1,param_2[0x48],param_2[0x49],&local_30,local_2c);
        iVar8 = 1;
        __s = DAT_0005625c;
        goto LAB_0005608a;
      }
      iVar9 = 0x10;
      iVar8 = 1;
      ppcVar7 = DAT_0005623c;
      pcVar2 = DAT_0005625c;
    }
  }
  if ((pcVar2 != (char *)0x0) &&
     (pcVar2 = (char *)(**(code **)(*param_1 + 0x10))(param_2,pcVar2), iVar4 = local_30,
     pcVar2 == (char *)0x0)) {
    if (local_30 == 0) {
      iVar9 = iVar8;
    }
    *param_4 = 1;
    param_1[1] = iVar9;
  }
LAB_00056036:
  (**ppcVar7)(iVar4);
  return pcVar2;
}

