
int Curl_output_ntlm_wb(int *param_1,int param_2)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  iVar2 = DAT_00054b24;
  if (param_2 == 0) {
    piVar6 = param_1 + 0x8e;
    iVar3 = param_1[0x48];
    piVar7 = param_1 + 0x9d;
    iVar5 = *param_1 + 0x8620;
  }
  else {
    iVar3 = param_1[0x4c];
    piVar6 = param_1 + 0x8b;
    piVar7 = param_1 + 0xa3;
    iVar5 = *param_1 + 0x8630;
  }
  iVar4 = *piVar7;
  *(undefined *)(iVar5 + 0xc) = 0;
  if (iVar3 == 0) {
    iVar3 = iVar2;
  }
  if (iVar4 == 2) {
    iVar4 = 0x1b;
    iVar3 = curl_maprintf(DAT_00054b2c,param_1[0xab]);
    ppcVar1 = DAT_00054b28;
    if (iVar3 != 0) {
      iVar4 = ntlm_wb_response(param_1,iVar3,*piVar7);
      (**ppcVar1)(iVar3);
      if (iVar4 == 0) {
        (**ppcVar1)(*piVar6);
        iVar3 = DAT_00054b30;
        if (param_2 == 0) {
          iVar3 = iVar2;
        }
        iVar2 = curl_maprintf(DAT_00054b34,iVar3,param_1[0xac]);
        *piVar6 = iVar2;
        *piVar7 = 3;
        *(undefined *)(iVar5 + 0xc) = 1;
        Curl_ntlm_wb_cleanup(param_1);
      }
    }
  }
  else if (iVar4 == 3) {
    iVar4 = 0;
    (**DAT_00054b28)(*piVar6,iVar3);
    *piVar6 = 0;
    *(undefined *)(iVar5 + 0xc) = 1;
  }
  else {
    iVar4 = ntlm_wb_init(param_1);
    if ((iVar4 == 0) &&
       (iVar4 = ntlm_wb_response(param_1,DAT_00054b38,*piVar7), ppcVar1 = DAT_00054b28, iVar4 == 0))
    {
      (**DAT_00054b28)(*piVar6);
      iVar3 = DAT_00054b30;
      if (param_2 == 0) {
        iVar3 = iVar2;
      }
      iVar2 = curl_maprintf(DAT_00054b34,iVar3,param_1[0xac]);
      *piVar6 = iVar2;
      (**ppcVar1)(param_1[0xac]);
      param_1[0xac] = 0;
    }
  }
  return iVar4;
}

