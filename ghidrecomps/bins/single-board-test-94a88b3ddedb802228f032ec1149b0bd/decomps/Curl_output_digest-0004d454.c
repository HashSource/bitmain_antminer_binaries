
int Curl_output_digest(int *param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 local_30;
  undefined1 auStack_2c [8];
  
  iVar7 = *param_1;
  if (param_2 == 0) {
    puVar4 = (undefined1 *)param_1[0x48];
    piVar5 = (int *)(iVar7 + 0x85d8);
    puVar3 = (undefined1 *)param_1[0x49];
    iVar6 = iVar7 + 0x8620;
    param_1 = param_1 + 0x8e;
  }
  else {
    puVar4 = (undefined1 *)param_1[0x4c];
    puVar3 = (undefined1 *)param_1[0x4d];
    piVar5 = (int *)(iVar7 + 0x85fc);
    iVar6 = iVar7 + 0x8630;
    param_1 = param_1 + 0x8b;
  }
  (*Curl_cfree)(*param_1);
  *param_1 = 0;
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_0013a6fc;
  }
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_0013a6fc;
  }
  if (*piVar5 == 0) {
    *(undefined1 *)(iVar6 + 0xc) = 0;
    return 0;
  }
  if ((*(char *)(iVar6 + 0xe) == '\0') || (pcVar1 = strchr(param_4,0x3f), pcVar1 == (char *)0x0)) {
    iVar2 = (*Curl_cstrdup)(param_4);
  }
  else {
    iVar2 = curl_maprintf(&DAT_00137fbc,(int)pcVar1 - (int)param_4,param_4);
  }
  if (iVar2 != 0) {
    iVar7 = Curl_sasl_create_digest_http_message
                      (iVar7,puVar4,puVar3,param_3,iVar2,piVar5,&local_30,auStack_2c);
    (*Curl_cfree)(iVar2);
    if (iVar7 != 0) {
      return iVar7;
    }
    pcVar1 = "";
    if (param_2 != 0) {
      pcVar1 = "Proxy-";
    }
    iVar7 = curl_maprintf("%sAuthorization: Digest %s\r\n",pcVar1,local_30);
    *param_1 = iVar7;
    (*Curl_cfree)(local_30);
    if (*param_1 != 0) {
      *(undefined1 *)(iVar6 + 0xc) = 1;
      return 0;
    }
  }
  return 0x1b;
}

