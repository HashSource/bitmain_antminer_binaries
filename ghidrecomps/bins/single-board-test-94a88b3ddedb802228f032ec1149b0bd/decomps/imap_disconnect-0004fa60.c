
undefined4 imap_disconnect(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  
  if ((((param_2 == 0) && (*(int *)(param_1 + 0x3ec) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x3ec) + 0x1f8) != '\0')) &&
     (iVar2 = imap_sendf(param_1,"LOGOUT"), iVar2 == 0)) {
    *(undefined4 *)(param_1 + 0x3f8) = 0xe;
    imap_block_statemach(param_1);
  }
  Curl_pp_disconnect(param_1 + 0x3c0);
  Curl_sasl_cleanup(param_1,*(undefined4 *)(param_1 + 0x410));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x428));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0x428) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0x42c));
  *(undefined4 *)(param_1 + 0x42c) = 0;
  return 0;
}

