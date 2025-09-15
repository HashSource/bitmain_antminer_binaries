
undefined4 tftp_done(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x3c0);
  iVar1 = Curl_pgrsDone();
  if (iVar1 != 0) {
    return 0x2a;
  }
  if (iVar3 != 0) {
    uVar2 = tftp_translate_code(*(undefined4 *)(iVar3 + 8));
    return uVar2;
  }
  return 0;
}

