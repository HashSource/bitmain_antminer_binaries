
int Curl_fetch_addr(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x48) != 0) {
    Curl_share_lock(iVar2,3,2,*(int *)(iVar2 + 0x48),param_4);
  }
  iVar1 = fetch_addr(param_1,param_2,param_3);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  }
  if (*(int *)(iVar2 + 0x48) != 0) {
    Curl_share_unlock(iVar2,3);
  }
  return iVar1;
}

