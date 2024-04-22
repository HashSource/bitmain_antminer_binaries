
int curl_multi_perform(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined auStack_b0 [144];
  
  curlx_tvnow(&local_b8);
  if ((param_1 == (int *)0x0) || (*param_1 != 0xbab1e)) {
    iVar4 = 1;
  }
  else {
    piVar2 = (int *)param_1[1];
    if (piVar2 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      do {
        piVar3 = piVar2 + 0x21b6;
        if (((*(char *)(piVar2 + 0x105) != '\0') && (piVar2[0x21b9] == 0)) &&
           (iVar1 = Curl_wildcard_init(piVar3), iVar1 != 0)) {
          return 3;
        }
        sigpipe_ignore_isra_2(*(undefined *)(piVar2 + 0xc9),auStack_b0);
        iVar1 = multi_runsingle(param_1,local_b8,uStack_b4,piVar2);
        sigpipe_restore(auStack_b0);
        if (*(char *)(piVar2 + 0x105) == '\0') {
LAB_0003b57c:
          if (iVar1 != 0) {
            iVar4 = iVar1;
          }
        }
        else if ((*piVar3 == 6) || (iVar1 != 0)) {
          Curl_wildcard_dtor(piVar3);
          goto LAB_0003b57c;
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)0x0);
    }
    do {
      iVar1 = Curl_splaygetbest(local_b8,uStack_b4,param_1[0x11],&local_bc);
      param_1[0x11] = iVar1;
      if (local_bc == 0) break;
      add_next_timeout(local_b8,uStack_b4,param_1,*(undefined4 *)(local_bc + 0x14));
    } while (local_bc != 0);
    *param_2 = param_1[4];
    if (iVar4 < 1) {
      update_timer(param_1);
    }
  }
  return iVar4;
}

