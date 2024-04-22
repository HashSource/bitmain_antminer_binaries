
undefined4
Curl_ssl_initsessions(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x85b0) != 0) {
    return 0;
  }
  iVar1 = (**DAT_0003cd08)(param_2,0x58,param_3,*DAT_0003cd08,param_4);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x85b0) = iVar1;
    *(undefined4 *)(param_1 + 0x2a8) = param_2;
    *(undefined4 *)(param_1 + 0x85b4) = 1;
    return 0;
  }
  return 0x1b;
}

