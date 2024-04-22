
/* WARNING: Type propagation algorithm not settling */

int Curl_timeleft(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_18 [3];
  
  if (param_3 == 0) {
    iVar3 = *(int *)(param_1 + 0x200);
    bVar2 = 0 < iVar3;
    iVar1 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x200);
    bVar2 = 0 < iVar3;
    if (0 < *(int *)(param_1 + 0x204)) {
      bVar2 = bVar2 | 2;
    }
    iVar1 = 300000;
  }
  if (bVar2 == '\x02') {
    iVar3 = *(int *)(param_1 + 0x204);
  }
  else if (bVar2 == 3) {
    if (*(int *)(param_1 + 0x204) <= iVar3) {
      iVar3 = *(int *)(param_1 + 0x204);
    }
  }
  else if ((bVar2 != 1) && (iVar3 = iVar1, param_3 == 0)) {
    return 0;
  }
  if (param_2 == (undefined4 *)0x0) {
    curlx_tvnow(local_18);
    param_2 = local_18;
  }
  if (param_3 == 0) {
    iVar1 = curlx_tvdiff(*param_2,param_2[1],*(undefined4 *)(param_1 + 0x508),
                         *(undefined4 *)(param_1 + 0x50c));
  }
  else {
    iVar1 = curlx_tvdiff(*param_2,param_2[1],*(undefined4 *)(param_1 + 0x500),
                         *(undefined4 *)(param_1 + 0x504));
  }
  iVar3 = iVar3 - iVar1;
  if (iVar3 == 0) {
    iVar3 = -1;
  }
  return iVar3;
}

