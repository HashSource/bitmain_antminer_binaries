
int output_auth_headers(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  size_t sVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_28;
  int local_24;
  
  iVar5 = *(int *)(param_2 + 4);
  iVar7 = *param_1;
  if (iVar5 == 8) {
    iVar5 = Curl_output_ntlm(param_1,param_5);
    if (iVar5 != 0) {
      return iVar5;
    }
    pcVar6 = "NTLM";
    goto LAB_0003ffcc;
  }
  if (iVar5 == 0x20) {
    iVar5 = Curl_output_ntlm_wb(param_1,param_5);
    if (iVar5 != 0) {
      return iVar5;
    }
    pcVar6 = "NTLM_WB";
    goto LAB_0003ffcc;
  }
  if (iVar5 == 2) {
    iVar5 = Curl_output_digest(param_1,param_5);
    if (iVar5 != 0) {
      return iVar5;
    }
    pcVar6 = "Digest";
    goto LAB_0003ffcc;
  }
  if (iVar5 != 1) goto LAB_0003ffa4;
  if (param_5 == '\0') {
    if ((*(char *)((int)param_1 + 0x1f1) != '\0') &&
       (iVar5 = Curl_checkheaders(param_1,"Authorization:"), iVar5 == 0)) {
      iVar9 = *param_1;
      piVar8 = param_1 + 0x8e;
      iVar4 = param_1[0x48];
      iVar5 = param_1[0x49];
      goto LAB_0004003e;
    }
  }
  else if ((*(char *)((int)param_1 + 0x1f2) != '\0') &&
          (iVar5 = Curl_checkProxyheaders(param_1,"Proxy-authorization:"), iVar5 == 0)) {
    piVar8 = param_1 + 0x8b;
    iVar9 = *param_1;
    iVar4 = param_1[0x4c];
    iVar5 = param_1[0x4d];
LAB_0004003e:
    local_24 = 0;
    pcVar6 = (char *)(iVar9 + 0x59c);
    local_28 = local_24;
    curl_msnprintf(pcVar6,0x4001,"%s:%s",iVar4,iVar5);
    sVar1 = strlen(pcVar6);
    iVar5 = Curl_base64_encode(iVar9,pcVar6,sVar1,&local_24,&local_28);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (local_24 == 0) {
      return 9;
    }
    (*Curl_cfree)(*piVar8);
    pcVar6 = "";
    if (param_5 != '\0') {
      pcVar6 = "Proxy-";
    }
    iVar5 = curl_maprintf("%sAuthorization: Basic %s\r\n",pcVar6,local_24);
    *piVar8 = iVar5;
    (*Curl_cfree)(local_24);
    if (*piVar8 == 0) {
      return 0x1b;
    }
    pcVar6 = "Basic";
    *(undefined1 *)(param_2 + 0xc) = 1;
LAB_0003ffcc:
    if (param_5 == '\0') {
      puVar2 = (undefined1 *)param_1[0x48];
      pcVar3 = "Server";
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_0013a6fc;
      }
    }
    else {
      puVar2 = (undefined1 *)param_1[0x4c];
      pcVar3 = "Proxy";
      if (puVar2 == (undefined1 *)0x0) {
        pcVar3 = "Proxy";
        puVar2 = &DAT_0013a6fc;
      }
    }
    Curl_infof(iVar7,"%s auth using %s with user \'%s\'\n",pcVar3,pcVar6,puVar2);
    *(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xc) ^ 1;
    return 0;
  }
  *(undefined1 *)(param_2 + 0xc) = 1;
LAB_0003ffa4:
  *(undefined1 *)(param_2 + 0xd) = 0;
  return 0;
}

