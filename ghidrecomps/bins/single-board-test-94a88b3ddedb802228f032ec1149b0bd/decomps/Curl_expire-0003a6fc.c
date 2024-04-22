
void Curl_expire(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  int iStack_24;
  int local_20;
  int local_1c;
  
  iVar2 = *(int *)(param_1 + 0x40);
  if (iVar2 != 0) {
    if (param_2 == 0) {
      if ((*(int *)(param_1 + 0x864c) != 0) || (*(int *)(param_1 + 0x8650) != 0)) {
        iVar3 = *(int *)(param_1 + 0x866c);
        iVar2 = Curl_splayremovebyaddr
                          (*(undefined4 *)(iVar2 + 0x44),param_1 + 0x8654,
                           (undefined4 *)(iVar2 + 0x44));
        if (iVar2 != 0) {
          Curl_infof(param_1,DAT_0003a814,iVar2);
        }
        while (*(int *)(iVar3 + 0xc) != 0) {
          Curl_llist_remove(iVar3,*(undefined4 *)(iVar3 + 4),0);
        }
        *(undefined4 *)(param_1 + 0x8650) = 0;
        *(undefined4 *)(param_1 + 0x864c) = 0;
      }
    }
    else {
      curlx_tvnow(&local_28);
      local_20 = local_28 + param_2 / 1000;
      local_1c = (param_2 % 1000) * 1000 + iStack_24;
      if (999999 < local_1c) {
        local_20 = local_20 + 1;
        local_1c = local_1c + -1000000;
      }
      piVar4 = (int *)(param_1 + 0x864c);
      if ((*(int *)(param_1 + 0x864c) != 0) || (*(int *)(param_1 + 0x8650) != 0)) {
        iVar3 = curlx_tvdiff(local_20,local_1c,*piVar4,*(undefined4 *)(param_1 + 0x8650));
        if (0 < iVar3) {
          multi_addtimeout(*(undefined4 *)(param_1 + 0x866c),&local_20);
          return;
        }
        multi_addtimeout(*(undefined4 *)(param_1 + 0x866c),piVar4);
        iVar3 = Curl_splayremovebyaddr
                          (*(undefined4 *)(iVar2 + 0x44),param_1 + 0x8654,
                           (undefined4 *)(iVar2 + 0x44));
        if (iVar3 != 0) {
          Curl_infof(param_1,DAT_0003a810,iVar3);
        }
      }
      uVar1 = *(undefined4 *)(iVar2 + 0x44);
      *piVar4 = local_20;
      *(int *)(param_1 + 0x8650) = local_1c;
      *(int *)(param_1 + 0x8668) = param_1;
      uVar1 = Curl_splayinsert(local_20,local_1c,uVar1,param_1 + 0x8654);
      *(undefined4 *)(iVar2 + 0x44) = uVar1;
    }
  }
  return;
}

