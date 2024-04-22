
undefined4 Curl_close(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  code *pcVar2;
  
  if (param_1 != 0) {
    Curl_expire(param_1,0,param_3,param_4,param_4);
    if (*(int *)(param_1 + 0x40) != 0) {
      curl_multi_remove_handle(*(int *)(param_1 + 0x40),param_1);
    }
    if (*(int *)(param_1 + 0x44) != 0) {
      curl_multi_cleanup();
    }
    if (*(int *)(param_1 + 0x866c) != 0) {
      Curl_llist_destroy(*(int *)(param_1 + 0x866c),0);
      *(undefined4 *)(param_1 + 0x866c) = 0;
    }
    ppcVar1 = DAT_00043b88;
    *(undefined4 *)(param_1 + 0x879c) = 0;
    if (*(char *)(param_1 + 0x8692) != '\0') {
      (**ppcVar1)(*(undefined4 *)(param_1 + 0x8694));
    }
    (**ppcVar1)(*(undefined4 *)(param_1 + 0x8688));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x8688) = 0;
    *(undefined4 *)(param_1 + 0x868c) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x14c));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x14c) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x13c) = 0;
    Curl_ssl_close_all(param_1);
    (**ppcVar1)(*(undefined4 *)(param_1 + 0x85ac));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x85ac) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x85c4));
    *(undefined4 *)(param_1 + 0x85c4) = 0;
    Curl_ssl_free_certinfo(param_1);
    (**ppcVar1)(*(undefined4 *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x13c) = 0;
    if (*(char *)(param_1 + 0x45c) != '\0') {
      (**DAT_00043b88)(*(undefined4 *)(param_1 + 0x458));
      *(undefined *)(param_1 + 0x45c) = 0;
    }
    *(undefined4 *)(param_1 + 0x458) = 0;
    if (*(char *)(param_1 + 0x454) != '\0') {
      (**ppcVar1)(*(undefined4 *)(param_1 + 0x450));
      *(undefined *)(param_1 + 0x454) = 0;
    }
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x450) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x594));
    *(undefined4 *)(param_1 + 0x594) = 0;
    Curl_flush_cookies(param_1,1);
    Curl_digest_cleanup(param_1);
    (**ppcVar1)(*(undefined4 *)(param_1 + 0x871c));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x871c) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x8720));
    *(undefined4 *)(param_1 + 0x8720) = 0;
    if (*(int *)(param_1 + 0x48) != 0) {
      Curl_share_lock(param_1,1,2);
      *(int *)(*(int *)(param_1 + 0x48) + 4) = *(int *)(*(int *)(param_1 + 0x48) + 4) + -1;
      Curl_share_unlock(param_1,1);
    }
    Curl_freeset(param_1);
    (**ppcVar1)(param_1);
  }
  return 0;
}

