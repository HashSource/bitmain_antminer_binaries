
/* WARNING: Type propagation algorithm not settling */

int Curl_output_ntlm(int *param_1,int param_2)

{
  char *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  iVar3 = *param_1;
  if (param_2 == 0) {
    piVar7 = param_1 + 0x8e;
    puVar5 = (undefined1 *)param_1[0x48];
    piVar8 = param_1 + 0x9d;
    puVar2 = (undefined1 *)param_1[0x49];
    iVar4 = iVar3 + 0x8620;
  }
  else {
    puVar5 = (undefined1 *)param_1[0x4c];
    puVar2 = (undefined1 *)param_1[0x4d];
    piVar7 = param_1 + 0x8b;
    piVar8 = param_1 + 0xa3;
    iVar4 = iVar3 + 0x8630;
  }
  iVar6 = *piVar8;
  *(undefined1 *)(iVar4 + 0xc) = 0;
  if (puVar5 == (undefined1 *)0x0) {
    puVar5 = &DAT_0013a6fc;
  }
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_0013a6fc;
  }
  if (iVar6 == 3) {
    *piVar8 = 4;
  }
  else if (iVar6 != 4) {
    if (iVar6 == 2) {
      iVar3 = Curl_sasl_create_ntlm_type3_message(iVar3,puVar5,puVar2,piVar8,local_28,local_28 + 1);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (local_28[0] == 0) {
        return 0;
      }
      (*Curl_cfree)(*piVar7);
      pcVar1 = "Proxy-";
      if (param_2 == 0) {
        pcVar1 = "";
      }
      iVar3 = curl_maprintf("%sAuthorization: NTLM %s\r\n",pcVar1,local_28[0]);
      *piVar7 = iVar3;
      (*Curl_cfree)(local_28[0]);
      if (*piVar7 != 0) {
        *piVar8 = 3;
        *(undefined1 *)(iVar4 + 0xc) = 1;
        return 0;
      }
    }
    else {
      iVar3 = Curl_sasl_create_ntlm_type1_message(puVar5,puVar2,piVar8,local_28,local_28 + 1);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (local_28[0] == 0) {
        return 0;
      }
      (*Curl_cfree)(*piVar7);
      pcVar1 = "Proxy-";
      if (param_2 == 0) {
        pcVar1 = "";
      }
      iVar3 = curl_maprintf("%sAuthorization: NTLM %s\r\n",pcVar1,local_28[0]);
      *piVar7 = iVar3;
      (*Curl_cfree)(local_28[0]);
      if (*piVar7 != 0) {
        return 0;
      }
    }
    return 0x1b;
  }
  (*Curl_cfree)(*piVar7);
  *piVar7 = 0;
  *(undefined1 *)(iVar4 + 0xc) = 1;
  return 0;
}

