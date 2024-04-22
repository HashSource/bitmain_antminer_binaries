
int output_auth_headers(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  code **ppcVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *__s;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_28;
  int local_24;
  
  iVar6 = *(int *)(param_2 + 4);
  iVar7 = *param_1;
  if (iVar6 == 8) {
    iVar6 = Curl_output_ntlm(param_1,param_5);
    uVar4 = DAT_000400d0;
  }
  else if (iVar6 == 0x20) {
    iVar6 = Curl_output_ntlm_wb(param_1,param_5);
    uVar4 = DAT_000400e4;
  }
  else {
    if (iVar6 != 2) {
      if (iVar6 != 1) goto LAB_0003ffa4;
      if (param_5 == '\0') {
        if ((*(char *)((int)param_1 + 0x1f1) == '\0') ||
           (iVar6 = Curl_checkheaders(param_1,DAT_000400ec), iVar6 != 0)) goto LAB_0003ffba;
        iVar9 = *param_1;
        piVar8 = param_1 + 0x8e;
        iVar5 = param_1[0x48];
        iVar6 = param_1[0x49];
      }
      else {
        if ((*(char *)((int)param_1 + 0x1f2) == '\0') ||
           (iVar6 = Curl_checkProxyheaders(param_1,DAT_00040104), iVar6 != 0)) {
LAB_0003ffba:
          *(undefined *)(param_2 + 0xc) = 1;
LAB_0003ffa4:
          *(undefined *)(param_2 + 0xd) = 0;
          return 0;
        }
        piVar8 = param_1 + 0x8b;
        iVar9 = *param_1;
        iVar5 = param_1[0x4c];
        iVar6 = param_1[0x4d];
      }
      local_24 = 0;
      __s = (char *)(iVar9 + 0x59c);
      local_28 = local_24;
      curl_msnprintf(__s,0x4001,DAT_000400f0,iVar5,iVar6);
      sVar2 = strlen(__s);
      iVar6 = Curl_base64_encode(iVar9,__s,sVar2,&local_24,&local_28);
      ppcVar1 = DAT_000400f4;
      if (iVar6 != 0) {
        return iVar6;
      }
      if (local_24 == 0) {
        return 9;
      }
      (**DAT_000400f4)(*piVar8);
      iVar6 = DAT_000400e0;
      if (param_5 != '\0') {
        iVar6 = DAT_000400f8;
      }
      iVar6 = curl_maprintf(DAT_000400fc,iVar6,local_24);
      *piVar8 = iVar6;
      (**ppcVar1)(local_24);
      uVar4 = DAT_00040100;
      if (*piVar8 == 0) {
        return 0x1b;
      }
      *(undefined *)(param_2 + 0xc) = 1;
      goto LAB_0003ffcc;
    }
    iVar6 = Curl_output_digest(param_1,param_5);
    uVar4 = DAT_000400e8;
  }
  if (iVar6 != 0) {
    return iVar6;
  }
LAB_0003ffcc:
  if (param_5 == '\0') {
    iVar6 = param_1[0x48];
    uVar3 = DAT_000400dc;
    if (param_1[0x48] == 0) {
      iVar6 = DAT_000400e0;
    }
  }
  else {
    iVar6 = param_1[0x4c];
    uVar3 = DAT_000400d4;
    if (param_1[0x4c] == 0) {
      iVar6 = DAT_000400e0;
    }
  }
  Curl_infof(iVar7,DAT_000400d8,uVar3,uVar4,iVar6);
  *(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xc) ^ 1;
  return 0;
}

