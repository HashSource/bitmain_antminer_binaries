
void Curl_expire_latest(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
  curlx_tvnow(&local_20);
  iVar1 = param_2 / 1000 + local_20;
  iVar2 = (param_2 % 1000) * 1000 + local_1c;
  if (999999 < iVar2) {
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1000000;
  }
  if (((*(int *)(param_1 + 0x864c) != 0) || (*(int *)(param_1 + 0x8650) != 0)) &&
     (local_20 = iVar1, local_1c = iVar2,
     iVar1 = curlx_tvdiff(iVar1,iVar2,*(undefined4 *)(param_1 + 0x864c),
                          *(undefined4 *)(param_1 + 0x8650)), 0 < iVar1)) {
    return;
  }
  Curl_expire(param_1,param_2);
  return;
}

