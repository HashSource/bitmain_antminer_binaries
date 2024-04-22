
int ftp_epsv_disable(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x7d) != '\0') {
    Curl_failf(*param_1,DAT_0005c5a8);
    return 8;
  }
  Curl_infof(*param_1,DAT_0005c5ac,param_3,param_4,param_4);
  *(undefined *)((int)param_1 + 0x1fd) = 0;
  uVar2 = DAT_0005c5b4;
  uVar1 = DAT_0005c5b0;
  *(undefined *)(*param_1 + 0x85c8) = 0;
  iVar3 = Curl_pp_sendf(param_1 + 0xf0,uVar1,uVar2);
  if (iVar3 == 0) {
    param_1[0x10a] = 0x1e;
    param_1[0x107] = param_1[0x107] + 1;
  }
  return iVar3;
}

