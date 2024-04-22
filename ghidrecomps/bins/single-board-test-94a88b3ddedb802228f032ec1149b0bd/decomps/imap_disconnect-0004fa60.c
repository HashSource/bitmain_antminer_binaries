
undefined4 imap_disconnect(int param_1,int param_2)

{
  code **ppcVar1;
  int iVar2;
  code *pcVar3;
  
  if ((((param_2 == 0) && (*(int *)(param_1 + 0x3ec) != 0)) &&
      (*(char *)(*(int *)(param_1 + 0x3ec) + 0x1f8) != '\0')) &&
     (iVar2 = imap_sendf(param_1,DAT_0004fac0), iVar2 == 0)) {
    *(undefined4 *)(param_1 + 0x3f8) = 0xe;
    imap_block_statemach(param_1);
  }
  ppcVar1 = DAT_0004fabc;
  Curl_pp_disconnect(param_1 + 0x3c0);
  Curl_sasl_cleanup(param_1,*(undefined4 *)(param_1 + 0x410));
  (**ppcVar1)(*(undefined4 *)(param_1 + 0x428));
  pcVar3 = *ppcVar1;
  *(undefined4 *)(param_1 + 0x428) = 0;
  (*pcVar3)(*(undefined4 *)(param_1 + 0x42c));
  *(undefined4 *)(param_1 + 0x42c) = 0;
  return 0;
}

