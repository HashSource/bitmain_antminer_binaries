
int Curl_output_ntlm_wb(int *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  if (param_2 == 0) {
    piVar6 = param_1 + 0x8e;
    puVar2 = (undefined1 *)param_1[0x48];
    piVar7 = param_1 + 0x9d;
    iVar5 = *param_1 + 0x8620;
  }
  else {
    puVar2 = (undefined1 *)param_1[0x4c];
    piVar6 = param_1 + 0x8b;
    piVar7 = param_1 + 0xa3;
    iVar5 = *param_1 + 0x8630;
  }
  iVar4 = *piVar7;
  *(undefined1 *)(iVar5 + 0xc) = 0;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_0013a6fc;
  }
  if (iVar4 == 2) {
    iVar4 = 0x1b;
    iVar1 = curl_maprintf("TT %s\n",param_1[0xab]);
    if (iVar1 != 0) {
      iVar4 = ntlm_wb_response(param_1,iVar1,*piVar7);
      (*Curl_cfree)(iVar1);
      if (iVar4 == 0) {
        (*Curl_cfree)(*piVar6);
        pcVar3 = "Proxy-";
        if (param_2 == 0) {
          pcVar3 = "";
        }
        iVar1 = curl_maprintf("%sAuthorization: %s\r\n",pcVar3,param_1[0xac]);
        *piVar6 = iVar1;
        *piVar7 = 3;
        *(undefined1 *)(iVar5 + 0xc) = 1;
        Curl_ntlm_wb_cleanup(param_1);
      }
    }
  }
  else if (iVar4 == 3) {
    iVar4 = 0;
    (*Curl_cfree)(*piVar6,puVar2);
    *piVar6 = 0;
    *(undefined1 *)(iVar5 + 0xc) = 1;
  }
  else {
    iVar4 = ntlm_wb_init(param_1);
    if ((iVar4 == 0) && (iVar4 = ntlm_wb_response(param_1,&DAT_0013a46c,*piVar7), iVar4 == 0)) {
      (*Curl_cfree)(*piVar6);
      pcVar3 = "Proxy-";
      if (param_2 == 0) {
        pcVar3 = "";
      }
      iVar5 = curl_maprintf("%sAuthorization: %s\r\n",pcVar3,param_1[0xac]);
      *piVar6 = iVar5;
      (*Curl_cfree)(param_1[0xac]);
      param_1[0xac] = 0;
    }
  }
  return iVar4;
}

