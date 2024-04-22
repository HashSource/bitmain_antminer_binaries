
void smtp_disconnect(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  
  if ((param_2 == 0) && (*(int *)(param_1 + 0x3ec) != 0)) {
    cVar1 = *(char *)(*(int *)(param_1 + 0x3ec) + 0x1f8);
    if ((cVar1 != '\0') &&
       (iVar2 = Curl_pp_sendf(param_1 + 0x3c0,DAT_00051c64,DAT_00051c68,cVar1,param_4), iVar2 == 0))
    {
      *(undefined4 *)(param_1 + 0x3f8) = 0xc;
      smtp_block_statemach(param_1);
    }
  }
  Curl_pp_disconnect(param_1 + 0x3c0);
  Curl_sasl_cleanup(param_1,*(undefined4 *)(param_1 + 0x414));
  (**DAT_00051c60)(*(undefined4 *)(param_1 + 0x400));
  *(undefined4 *)(param_1 + 0x400) = 0;
  return;
}

