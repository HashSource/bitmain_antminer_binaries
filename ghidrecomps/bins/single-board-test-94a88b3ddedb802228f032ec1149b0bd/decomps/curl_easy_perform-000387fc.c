
undefined4 curl_easy_perform(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int local_d0;
  int local_cc;
  int local_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  sigaction sStack_b8;
  char local_2c;
  
  if (param_1 == 0) {
    return 0x2b;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    Curl_failf(param_1,DAT_00038928);
    return 2;
  }
  iVar5 = *(int *)(param_1 + 0x44);
  if (iVar5 == 0) {
    iVar5 = Curl_multi_handle(1,3);
    if (iVar5 == 0) {
      return 0x1b;
    }
    *(int *)(param_1 + 0x44) = iVar5;
  }
  curl_multi_setopt(iVar5,6,*(undefined4 *)(param_1 + 0x438));
  iVar1 = curl_multi_add_handle(iVar5,param_1);
  if (iVar1 != 0) {
    curl_multi_cleanup(iVar5);
    if (iVar1 == 3) {
      return 0x1b;
    }
    return 2;
  }
  local_2c = *(char *)(param_1 + 0x324);
  if (local_2c == '\0') {
    sigpipe_ignore_isra_1_part_2(&sStack_b8);
  }
  *(int *)(param_1 + 0x40) = iVar5;
  uVar6 = 0;
  do {
    local_d0 = 0;
    curlx_tvnow(&local_c8);
    iVar1 = curl_multi_wait(iVar5,0,0,1000,&local_cc);
    if (iVar1 != 0) {
LAB_000388c8:
      if (iVar1 == 3) {
        uVar4 = 0x1b;
      }
      else {
        uVar4 = 0x2b;
      }
      goto LAB_000388ae;
    }
    if (local_cc == 0) {
      curlx_tvnow(&local_c0);
      iVar1 = local_c8;
      iVar2 = curlx_tvdiff(local_c0,uStack_bc,local_c8,uStack_c4);
      if (iVar2 < 0xb) {
        uVar3 = uVar6 + 1;
        if (2 < (int)uVar3) {
          if ((int)uVar3 < 10) {
            iVar1 = 1;
          }
          if (uVar3 == 9 || (int)(uVar6 - 8) < 0 != SBORROW4(uVar3,9)) {
            iVar1 = iVar1 << (uVar6 & 0xff);
          }
          else {
            iVar1 = 1000;
          }
          Curl_wait_ms(iVar1);
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
    iVar1 = curl_multi_perform(iVar5,&local_d0);
    if (iVar1 != 0) goto LAB_000388c8;
    uVar6 = uVar3;
  } while ((local_d0 != 0) || (iVar1 = curl_multi_info_read(iVar5,&local_cc), iVar1 == 0));
  uVar4 = *(undefined4 *)(iVar1 + 8);
LAB_000388ae:
  curl_multi_remove_handle(iVar5,param_1);
  if (local_2c == '\0') {
    sigaction(0xd,&sStack_b8,(sigaction *)0x0);
    return uVar4;
  }
  return uVar4;
}

