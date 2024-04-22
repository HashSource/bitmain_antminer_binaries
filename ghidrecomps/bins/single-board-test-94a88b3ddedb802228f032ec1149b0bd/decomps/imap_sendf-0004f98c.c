
undefined4 imap_sendf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *(int *)(param_1 + 0x41c) = (*(int *)(param_1 + 0x41c) + 1) % 1000;
  uVar2 = 0x1b;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = curlx_sltosi(*(int *)(param_1 + 0x44) % 0x1a);
  curl_msnprintf(param_1 + 0x420,5,DAT_0004fa30,iVar1 + 0x41,*(undefined4 *)(param_1 + 0x41c));
  iVar1 = curl_maprintf(DAT_0004fa34,param_1 + 0x420,param_2);
  if (iVar1 != 0) {
    uVar2 = Curl_pp_vsendf(param_1 + 0x3c0,iVar1,&uStack_8);
    (**DAT_0004fa38)(iVar1);
  }
  return uVar2;
}

