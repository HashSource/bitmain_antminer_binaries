
void conn_free(int param_1)

{
  code **ppcVar1;
  code *pcVar2;
  
  if (param_1 != 0) {
    Curl_ssl_close(param_1,0);
    Curl_ssl_close(param_1,1);
    if (*(int *)(param_1 + 0x158) != -1) {
      Curl_closesocket(param_1);
    }
    if (*(int *)(param_1 + 0x154) != -1) {
      Curl_closesocket(param_1);
    }
    if (*(int *)(param_1 + 0x15c) != -1) {
      Curl_closesocket(param_1);
    }
    if (*(int *)(param_1 + 0x160) != -1) {
      Curl_closesocket(param_1);
    }
    ppcVar1 = DAT_00043858;
    Curl_ntlm_wb_cleanup(param_1);
    (**ppcVar1)(*(undefined4 *)(param_1 + 0x120));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x120) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x124));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x124) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 300));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 300) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x128));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x128) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x130));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x130) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x134));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x134) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x22c));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x22c) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x230));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x230) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x238));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x238) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x234));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x234) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x250));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x250) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x23c));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x23c) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x240));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x240) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x244));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x244) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x248));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x248) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x24c));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x24c) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x3b4));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x3b4) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x90));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0x90) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0xa0));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x260));
    *(undefined4 *)(param_1 + 0x260) = 0;
    Curl_llist_destroy(*(undefined4 *)(param_1 + 600),0);
    Curl_llist_destroy(*(undefined4 *)(param_1 + 0x25c),0);
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_1 + 600) = 0;
    *(undefined4 *)(param_1 + 0x25c) = 0;
    (*pcVar2)(*(undefined4 *)(param_1 + 0x45c));
    *(undefined4 *)(param_1 + 0x45c) = 0;
    Curl_free_ssl_config(param_1 + 0x1a8);
    (**ppcVar1)(param_1);
  }
  return;
}

