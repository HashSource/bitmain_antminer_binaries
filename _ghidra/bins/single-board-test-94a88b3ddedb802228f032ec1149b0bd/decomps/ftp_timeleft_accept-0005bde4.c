
int ftp_timeleft_accept(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  iVar3 = *(int *)(param_1 + 0x208);
  if (iVar3 < 1) {
    iVar3 = 60000;
  }
  curlx_tvnow(&local_28);
  local_20 = local_28;
  uStack_1c = uStack_24;
  iVar2 = Curl_timeleft(param_1,&local_20,0);
  iVar1 = iVar2;
  if (iVar2 != 0) {
    iVar1 = iVar2 - iVar3;
  }
  if (iVar1 < 0 == (iVar2 != 0 && SBORROW4(iVar2,iVar3))) {
    iVar2 = curlx_tvdiff(local_20,uStack_1c,*(undefined4 *)(param_1 + 0x510),
                         *(undefined4 *)(param_1 + 0x514));
    iVar2 = iVar3 - iVar2;
    if (iVar2 == 0) {
      iVar2 = -1;
    }
  }
  return iVar2;
}

