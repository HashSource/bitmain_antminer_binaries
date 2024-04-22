
int checkprotoprefix(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (-1 < *(int *)(*(int *)(param_2 + 0x218) + 0x3c) << 0xd) {
    iVar1 = checkhttpprefix();
    return iVar1;
  }
  iVar1 = Curl_raw_nequal(DAT_0003fe30,param_3,5);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

