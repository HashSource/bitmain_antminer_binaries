
void imap_block_statemach(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x3f8) != 0) {
    iVar2 = param_4;
    do {
      iVar1 = Curl_pp_statemach(param_1 + 0x3c0,1,param_3,param_4,iVar2);
      param_4 = *(int *)(param_1 + 0x3f8);
      if (param_4 == 0) {
        return;
      }
    } while (iVar1 == 0);
  }
  return;
}

