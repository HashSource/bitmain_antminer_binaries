
undefined4 curl_easy_perform(int param_1)

{
  int iVar1;
  int extraout_r2;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int local_d0;
  int local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  sigaction sStack_b8;
  char local_2c;
  
  if (param_1 == 0) {
    return 0x2b;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    Curl_failf(param_1,"easy handle already used in multi handle");
    return 2;
  }
  iVar4 = *(int *)(param_1 + 0x44);
  if (iVar4 == 0) {
    iVar4 = Curl_multi_handle(1,3);
    if (iVar4 == 0) {
      return 0x1b;
    }
    *(int *)(param_1 + 0x44) = iVar4;
  }
  curl_multi_setopt(iVar4,6,*(undefined4 *)(param_1 + 0x438));
  iVar1 = curl_multi_add_handle(iVar4,param_1);
  if (iVar1 != 0) {
    curl_multi_cleanup(iVar4);
    if (iVar1 == 3) {
      return 0x1b;
    }
    return 2;
  }
  local_2c = *(char *)(param_1 + 0x324);
  if (local_2c == '\0') {
    sigpipe_ignore_isra_1_part_2(&sStack_b8);
  }
  *(int *)(param_1 + 0x40) = iVar4;
  uVar5 = 0;
  do {
    local_d0 = 0;
    curlx_tvnow(&local_c8);
    iVar1 = curl_multi_wait(iVar4,0,0,1000,&local_cc);
    if (iVar1 != 0) {
LAB_000388c8:
      if (iVar1 == 3) {
        uVar3 = 0x1b;
      }
      else {
        uVar3 = 0x2b;
      }
      goto LAB_000388ae;
    }
    if (local_cc == 0) {
      curlx_tvnow(&local_c0);
      iVar1 = curlx_tvdiff(local_c0,uStack_bc,local_c8,uStack_c4);
      if (iVar1 < 0xb) {
        uVar2 = uVar5 + 1;
        if (2 < (int)uVar2) {
          iVar1 = extraout_r2;
          if ((int)uVar2 < 10) {
            iVar1 = 1;
          }
          if (uVar2 == 9 || (int)(uVar5 - 8) < 0 != SBORROW4(uVar2,9)) {
            iVar1 = iVar1 << (uVar5 & 0xff);
          }
          else {
            iVar1 = 1000;
          }
          Curl_wait_ms(iVar1);
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
    iVar1 = curl_multi_perform(iVar4,&local_d0);
    if (iVar1 != 0) goto LAB_000388c8;
    uVar5 = uVar2;
  } while ((local_d0 != 0) || (iVar1 = curl_multi_info_read(iVar4,&local_cc), iVar1 == 0));
  uVar3 = *(undefined4 *)(iVar1 + 8);
LAB_000388ae:
  curl_multi_remove_handle(iVar4,param_1);
  if (local_2c == '\0') {
    sigaction(0xd,&sStack_b8,(sigaction *)0x0);
    return uVar3;
  }
  return uVar3;
}

