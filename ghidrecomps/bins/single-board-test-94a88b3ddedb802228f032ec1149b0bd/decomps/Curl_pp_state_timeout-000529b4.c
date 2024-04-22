
int Curl_pp_state_timeout(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  piVar4 = *(int **)(param_1 + 0x2c);
  iVar3 = *piVar4;
  iVar2 = *(int *)(iVar3 + 0x20c);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x28);
  }
  curlx_tvnow(&local_28);
  iVar1 = curlx_tvdiff(local_28,uStack_24,*(undefined4 *)(param_1 + 0x20),
                       *(undefined4 *)(param_1 + 0x24));
  iVar3 = *(int *)(iVar3 + 0x200);
  iVar2 = iVar2 - iVar1;
  if (iVar3 != 0) {
    curlx_tvnow(&local_20);
    iVar1 = curlx_tvdiff(local_20,uStack_1c,piVar4[0x51],piVar4[0x52]);
    iVar3 = iVar3 - iVar1;
    if (iVar3 <= iVar2) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}

