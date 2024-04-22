
int tftp_doing(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  
  iVar1 = tftp_multi_statemach();
  if ((*param_2 == '\0') && (iVar1 == 0)) {
    iVar1 = Curl_pgrsUpdate(param_1);
    if (iVar1 == 0) {
      uVar2 = *param_1;
      curlx_tvnow(&local_18);
      iVar1 = Curl_speedcheck(uVar2,local_18,uStack_14);
    }
    else {
      iVar1 = 0x2a;
    }
  }
  return iVar1;
}

