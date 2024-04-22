
undefined4 Curl_resolv(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_24;
  
  iVar3 = *param_1;
  *param_4 = 0;
  if (*(int *)(iVar3 + 0x48) != 0) {
    Curl_share_lock(iVar3,3,2);
  }
  uVar4 = 0xffffffff;
  iVar1 = fetch_addr(param_1,param_2,param_3);
  if (iVar1 != 0) {
    uVar4 = 0;
    Curl_infof(iVar3,DAT_0003d848,param_2);
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  }
  if (*(int *)(iVar3 + 0x48) != 0) {
    Curl_share_unlock(iVar3,3);
  }
  if (iVar1 == 0) {
    iVar2 = Curl_ipvalid(param_1);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = Curl_getaddrinfo(param_1,param_2,param_3,&local_24);
    if (iVar2 == 0) {
      if (local_24 != 0) {
        return 0xffffffff;
      }
    }
    else {
      if (*(int *)(iVar3 + 0x48) != 0) {
        Curl_share_lock(iVar3,3,2);
      }
      iVar1 = Curl_cache_addr(iVar3,iVar2,param_2,param_3);
      if (*(int *)(iVar3 + 0x48) != 0) {
        Curl_share_unlock(iVar3,3);
      }
      if (iVar1 == 0) {
        Curl_freeaddrinfo(iVar2);
      }
      else {
        uVar4 = 0;
      }
    }
  }
  *param_4 = iVar1;
  return uVar4;
}

