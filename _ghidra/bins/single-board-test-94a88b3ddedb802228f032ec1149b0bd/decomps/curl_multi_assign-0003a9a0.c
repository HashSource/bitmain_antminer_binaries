
undefined4 curl_multi_assign(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = sh_getentry(param_1 + 0x48);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    return 0;
  }
  return 5;
}

