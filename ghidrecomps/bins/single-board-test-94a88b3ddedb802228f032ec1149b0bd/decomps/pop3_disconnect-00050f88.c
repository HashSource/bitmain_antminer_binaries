
void pop3_disconnect(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  
  if (((param_2 == 0) && (*(int *)(param_1 + 0x3ec) != 0)) &&
     (cVar1 = *(char *)(*(int *)(param_1 + 0x3ec) + 0x1f8), cVar1 != '\0')) {
    iVar2 = Curl_pp_sendf(param_1 + 0x3c0,DAT_00050ff4,DAT_00050ff8,cVar1,param_4);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x3f8) = 10;
      do {
        iVar2 = Curl_pp_statemach(param_1 + 0x3c0,1);
        if (*(int *)(param_1 + 0x3f8) == 0) break;
      } while (iVar2 == 0);
    }
  }
  Curl_pp_disconnect(param_1 + 0x3c0);
  Curl_sasl_cleanup(param_1,*(undefined4 *)(param_1 + 0x418));
  (**DAT_00050ff0)(*(undefined4 *)(param_1 + 0x428));
  *(undefined4 *)(param_1 + 0x428) = 0;
  return;
}

