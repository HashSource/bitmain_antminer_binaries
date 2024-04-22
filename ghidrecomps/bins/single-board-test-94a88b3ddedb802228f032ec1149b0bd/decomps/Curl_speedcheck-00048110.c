
undefined4 Curl_speedcheck(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  if ((*(int *)(param_1 + 0x49c) < 0) || (*(int *)(param_1 + 0x224) == 0)) {
    uVar3 = *(uint *)(param_1 + 0x220);
  }
  else {
    iVar1 = Curl_tvlong(*(undefined4 *)(param_1 + 0x588),*(undefined4 *)(param_1 + 0x58c));
    uVar3 = *(uint *)(param_1 + 0x220);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x49c);
      iVar2 = (int)uVar3 >> 0x1f;
      bVar4 = *(uint *)(param_1 + 0x498) < uVar3;
      if ((int)((iVar1 - iVar2) - (uint)bVar4) < 0 !=
          (SBORROW4(iVar1,iVar2) != SBORROW4(iVar1 - iVar2,(uint)bVar4))) {
        iVar1 = curlx_tvdiff(param_2,param_3,*(undefined4 *)(param_1 + 0x588),
                             *(undefined4 *)(param_1 + 0x58c));
        iVar1 = *(int *)(param_1 + 0x224) * 1000 - iVar1;
        if (iVar1 < 1) {
          Curl_failf(param_1,DAT_000481b8,*(undefined4 *)(param_1 + 0x220));
          return 0x1c;
        }
        goto LAB_0004815c;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x588) = param_2;
  *(undefined4 *)(param_1 + 0x58c) = param_3;
  if (uVar3 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x224) * 1000;
LAB_0004815c:
  Curl_expire_latest(param_1,iVar1);
  return 0;
}

