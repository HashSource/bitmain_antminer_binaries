
int Curl_output_ntlm(int *param_1,int param_2)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int local_28;
  undefined4 local_24;
  
  iVar2 = DAT_000544c8;
  local_28 = 0;
  local_24 = 0;
  iVar4 = *param_1;
  if (param_2 == 0) {
    piVar8 = param_1 + 0x8e;
    iVar6 = param_1[0x48];
    piVar9 = param_1 + 0x9d;
    iVar3 = param_1[0x49];
    iVar5 = iVar4 + 0x8620;
  }
  else {
    iVar6 = param_1[0x4c];
    iVar3 = param_1[0x4d];
    piVar8 = param_1 + 0x8b;
    piVar9 = param_1 + 0xa3;
    iVar5 = iVar4 + 0x8630;
  }
  iVar7 = *piVar9;
  *(undefined *)(iVar5 + 0xc) = 0;
  if (iVar6 == 0) {
    iVar6 = iVar2;
  }
  if (iVar3 == 0) {
    iVar3 = iVar2;
  }
  if (iVar7 == 3) {
    *piVar9 = 4;
  }
  else if (iVar7 != 4) {
    if (iVar7 == 2) {
      iVar4 = Curl_sasl_create_ntlm_type3_message(iVar4,iVar6,iVar3,piVar9,&local_28,&local_24);
      ppcVar1 = DAT_000544cc;
      if (iVar4 != 0) {
        return iVar4;
      }
      if (local_28 == 0) {
        return 0;
      }
      (**DAT_000544cc)(*piVar8);
      iVar4 = DAT_000544d0;
      if (param_2 == 0) {
        iVar4 = iVar2;
      }
      iVar2 = curl_maprintf(DAT_000544d4,iVar4,local_28);
      *piVar8 = iVar2;
      (**ppcVar1)(local_28);
      if (*piVar8 != 0) {
        *piVar9 = 3;
        *(undefined *)(iVar5 + 0xc) = 1;
        return 0;
      }
    }
    else {
      iVar4 = Curl_sasl_create_ntlm_type1_message(iVar6,iVar3,piVar9,&local_28,&local_24);
      ppcVar1 = DAT_000544cc;
      if (iVar4 != 0) {
        return iVar4;
      }
      if (local_28 == 0) {
        return 0;
      }
      (**DAT_000544cc)(*piVar8);
      iVar4 = DAT_000544d0;
      if (param_2 == 0) {
        iVar4 = iVar2;
      }
      iVar2 = curl_maprintf(DAT_000544d4,iVar4,local_28);
      *piVar8 = iVar2;
      (**ppcVar1)(local_28);
      if (*piVar8 != 0) {
        return 0;
      }
    }
    return 0x1b;
  }
  (**DAT_000544cc)(*piVar8);
  *piVar8 = 0;
  *(undefined *)(iVar5 + 0xc) = 1;
  return 0;
}

