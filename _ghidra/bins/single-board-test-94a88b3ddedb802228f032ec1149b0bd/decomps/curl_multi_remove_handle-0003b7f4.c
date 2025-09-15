
int curl_multi_remove_handle(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0xbab1e)) {
    return 1;
  }
  if ((param_2 == (int *)0x0) || (param_2[0x21e7] != -0x3f212453)) {
    iVar1 = 2;
  }
  else {
    iVar1 = param_2[0x10];
    if (iVar1 != 0) {
      uVar4 = param_2[3];
      piVar3 = (int *)param_2[2];
      piVar2 = piVar3;
      if (piVar3 != (int *)0x0) {
        piVar2 = (int *)(uint)(param_2 == (int *)*piVar3);
      }
      if (uVar4 < 0x11) {
        param_1[4] = param_1[4] + -1;
        Curl_multi_process_pending_handles(param_1);
        piVar3 = (int *)param_2[2];
      }
      if (((piVar3 != (int *)0x0) && (9 < (uint)param_2[3])) && ((uint)param_2[3] < 0x11)) {
        piVar2 = (int *)0x1;
        *piVar3 = (int)param_2;
        *(undefined1 *)((int)piVar3 + 0x1ed) = 1;
      }
      Curl_expire(param_2,0);
      iVar1 = param_2[0xf];
      bVar5 = iVar1 == 2;
      if (bVar5) {
        iVar1 = 0;
      }
      if (bVar5) {
        param_2[0xe] = iVar1;
      }
      if (bVar5) {
        param_2[0xf] = iVar1;
      }
      if (param_2[2] != 0) {
        if (piVar2 == (int *)0x0) {
          Curl_getoff_all_pipelines(param_2);
        }
        else {
          Curl_done(param_2 + 2,param_2[4],uVar4 < 0x11,iVar1,param_4);
        }
      }
      Curl_wildcard_dtor(param_2 + 0x21b6);
      if (param_2[0x219b] != 0) {
        Curl_llist_destroy(param_2[0x219b],0);
        param_2[0x219b] = 0;
      }
      param_2[3] = 0x11;
      param_2[0x160] = 0;
      singlesocket(param_1,param_2);
      if ((undefined4 *)param_2[2] != (undefined4 *)0x0) {
        *(undefined4 *)param_2[2] = 0;
        param_2[2] = 0;
      }
      piVar3 = (int *)param_1[5];
      param_2[0x10] = 0;
      piVar2 = (int *)*piVar3;
      do {
        if (piVar2 == (int *)0x0) {
LAB_0003b8e0:
          iVar1 = *param_2;
          piVar2 = (int *)param_2[1];
          if (piVar2 == (int *)0x0) {
            param_1[1] = iVar1;
          }
          else {
            *piVar2 = iVar1;
            iVar1 = *param_2;
          }
          if (iVar1 == 0) {
            param_1[2] = (int)piVar2;
          }
          else {
            *(int **)(iVar1 + 4) = piVar2;
          }
          param_1[3] = param_1[3] + -1;
          update_timer(param_1);
          return 0;
        }
        if (param_2 == *(int **)(*piVar2 + 4)) {
          Curl_llist_remove(piVar3,piVar2,0);
          goto LAB_0003b8e0;
        }
        piVar2 = (int *)piVar2[2];
      } while( true );
    }
  }
  return iVar1;
}

