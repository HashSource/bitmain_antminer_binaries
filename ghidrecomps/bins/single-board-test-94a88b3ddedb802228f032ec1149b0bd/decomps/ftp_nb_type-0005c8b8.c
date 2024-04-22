
void ftp_nb_type(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  
  if (param_2 == 0) {
    cVar2 = 'I';
  }
  else {
    cVar2 = 'A';
  }
  if (*(char *)(param_1 + 0x418) == cVar2) {
    *(undefined4 *)(param_1 + 0x428) = param_3;
    ftp_state_type_resp_part_5(param_1,param_3);
    return;
  }
  iVar1 = Curl_pp_sendf(param_1 + 0x3c0,DAT_0005c8f4,cVar2);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x428) = param_3;
    *(char *)(param_1 + 0x418) = cVar2;
  }
  return;
}

