
int Curl_output_digest(int *param_1,int param_2,undefined4 param_3,char *param_4)

{
  code **ppcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 local_30;
  undefined auStack_2c [8];
  
  ppcVar1 = DAT_0004d578;
  iVar8 = *param_1;
  if (param_2 == 0) {
    iVar5 = param_1[0x48];
    piVar6 = (int *)(iVar8 + 0x85d8);
    iVar4 = param_1[0x49];
    iVar7 = iVar8 + 0x8620;
    param_1 = param_1 + 0x8e;
  }
  else {
    iVar5 = param_1[0x4c];
    iVar4 = param_1[0x4d];
    piVar6 = (int *)(iVar8 + 0x85fc);
    iVar7 = iVar8 + 0x8630;
    param_1 = param_1 + 0x8b;
  }
  (**DAT_0004d578)(*param_1);
  iVar3 = DAT_0004d564;
  *param_1 = 0;
  if (iVar5 == 0) {
    iVar5 = iVar3;
  }
  if (iVar4 == 0) {
    iVar4 = iVar3;
  }
  if (*piVar6 == 0) {
    *(undefined *)(iVar7 + 0xc) = 0;
    return 0;
  }
  if ((*(char *)(iVar7 + 0xe) == '\0') || (pcVar2 = strchr(param_4,0x3f), pcVar2 == (char *)0x0)) {
    iVar3 = (**DAT_0004d574)(param_4);
  }
  else {
    iVar3 = curl_maprintf(DAT_0004d568,(int)pcVar2 - (int)param_4,param_4);
  }
  if (iVar3 != 0) {
    iVar8 = Curl_sasl_create_digest_http_message
                      (iVar8,iVar5,iVar4,param_3,iVar3,piVar6,&local_30,auStack_2c);
    (**ppcVar1)(iVar3);
    if (iVar8 != 0) {
      return iVar8;
    }
    iVar8 = DAT_0004d564;
    if (param_2 != 0) {
      iVar8 = DAT_0004d56c;
    }
    iVar8 = curl_maprintf(DAT_0004d570,iVar8,local_30);
    *param_1 = iVar8;
    (**ppcVar1)(local_30);
    if (*param_1 != 0) {
      *(undefined *)(iVar7 + 0xc) = 1;
      return 0;
    }
  }
  return 0x1b;
}

