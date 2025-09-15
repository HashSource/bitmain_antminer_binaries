
char * Curl_sasl_start(int *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *__s;
  int iVar7;
  int iVar8;
  int local_30;
  int local_2c [2];
  
  iVar1 = *param_2;
  local_30 = 0;
  uVar4 = param_1[3] & param_1[2];
  param_1[4] = 0;
  *(char *)((int)param_1 + 0x16) = (char)param_3;
  local_2c[0] = 0;
  *param_4 = 0;
  iVar3 = local_30;
  if (((int)(uVar4 << 0x1a) < 0) && (*(char *)param_2[0x49] == '\0')) {
    param_1[4] = 0x20;
    if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
      __s = "EXTERNAL";
      pcVar6 = (char *)sasl_create_login_message(iVar1,param_2[0x48],&local_30,local_2c);
      iVar8 = 0x10;
      iVar7 = 4;
      goto LAB_0005608a;
    }
    iVar8 = 0x10;
    iVar7 = 4;
    pcVar6 = "EXTERNAL";
  }
  else if (*(char *)((int)param_2 + 0x1f1) == '\0') {
    iVar8 = 0x10;
    pcVar6 = (char *)0x0;
    iVar7 = 0;
  }
  else if ((int)(uVar4 << 0x1c) < 0) {
    iVar8 = 0x10;
    param_1[4] = 8;
    iVar7 = 6;
    pcVar6 = "DIGEST-MD5";
  }
  else if ((int)(uVar4 << 0x1d) < 0) {
    iVar8 = 0x10;
    param_1[4] = 4;
    iVar7 = 5;
    pcVar6 = "CRAM-MD5";
  }
  else if ((int)(uVar4 << 0x19) < 0) {
    param_1[4] = 0x40;
    if ((param_3 == 0) && (*(char *)(iVar1 + 0x408) == '\0')) {
      iVar8 = 9;
      iVar7 = 8;
      pcVar6 = "NTLM";
    }
    else {
      pcVar6 = (char *)Curl_sasl_create_ntlm_type1_message
                                 (param_2[0x48],param_2[0x49],param_2 + 0x9d,&local_30,local_2c);
      iVar8 = 9;
      iVar7 = 8;
      __s = "NTLM";
LAB_0005608a:
      iVar3 = local_30;
      if (pcVar6 != (char *)0x0) goto LAB_00056036;
      pcVar6 = __s;
      if (((local_30 != 0) && (uVar4 = *(uint *)(*param_1 + 0xc), uVar4 != 0)) &&
         (sVar2 = strlen(__s), uVar4 < sVar2 + local_2c[0])) {
        (*Curl_cfree)(iVar3);
        local_30 = 0;
        iVar3 = 0;
      }
    }
  }
  else if (((int)(uVar4 << 0x17) < 0) && (iVar5 = param_2[0x4b], iVar5 != 0)) {
    param_1[4] = 0x100;
    if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
      iVar8 = 0xe;
      iVar7 = 0xd;
      pcVar6 = (char *)sasl_create_oauth_bearer_message
                                 (iVar1,param_2[0x48],param_2[0x26],param_2[0x2c],iVar5,&local_30,
                                  local_2c);
      __s = "OAUTHBEARER";
      goto LAB_0005608a;
    }
    iVar8 = 0xe;
    iVar7 = 0xd;
    pcVar6 = "OAUTHBEARER";
  }
  else if (((int)(uVar4 << 0x18) < 0) && (iVar7 = param_2[0x4b], iVar7 != 0)) {
    param_1[4] = 0x80;
    if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
      iVar8 = 0x10;
      pcVar6 = (char *)sasl_create_oauth_bearer_message
                                 (iVar1,param_2[0x48],0,0,iVar7,&local_30,local_2c);
      iVar7 = 0xd;
      __s = "XOAUTH2";
      goto LAB_0005608a;
    }
    iVar8 = 0x10;
    iVar7 = 0xd;
    pcVar6 = "XOAUTH2";
  }
  else if ((int)(uVar4 << 0x1f) < 0) {
    param_1[4] = 1;
    if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
      iVar8 = 3;
      pcVar6 = (char *)sasl_create_login_message(iVar1,param_2[0x48],&local_30,local_2c);
      iVar7 = 2;
      __s = "LOGIN";
      goto LAB_0005608a;
    }
    iVar8 = 3;
    iVar7 = 2;
    pcVar6 = "LOGIN";
  }
  else if ((uVar4 & 2) == 0) {
    iVar8 = 0x10;
    pcVar6 = (char *)0x0;
    iVar7 = 0;
  }
  else {
    param_1[4] = 2;
    if ((param_3 != 0) || (*(char *)(iVar1 + 0x408) != '\0')) {
      iVar8 = 0x10;
      pcVar6 = (char *)sasl_create_plain_message
                                 (iVar1,param_2[0x48],param_2[0x49],&local_30,local_2c);
      __s = "PLAIN";
      iVar7 = 1;
      goto LAB_0005608a;
    }
    pcVar6 = "PLAIN";
    iVar8 = 0x10;
    iVar7 = 1;
  }
  if ((pcVar6 != (char *)0x0) &&
     (pcVar6 = (char *)(**(code **)(*param_1 + 0x10))(param_2,pcVar6), iVar3 = local_30,
     pcVar6 == (char *)0x0)) {
    if (local_30 == 0) {
      iVar8 = iVar7;
    }
    *param_4 = 1;
    param_1[1] = iVar8;
  }
LAB_00056036:
  (*Curl_cfree)(iVar3);
  return pcVar6;
}

