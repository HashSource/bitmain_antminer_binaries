
void ftp_connect(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_0005b588;
  uVar1 = DAT_0005b584;
  iVar3 = *(int *)(*(int *)(param_1 + 0x218) + 0x40);
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined *)(param_1 + 0x1ed) = 0;
  *(undefined4 *)(param_1 + 0x3f0) = uVar2;
  *(int *)(param_1 + 0x3ec) = param_1;
  *(undefined4 *)(param_1 + 0x3f4) = uVar1;
  if ((iVar3 << 0x1f < 0) && (iVar3 = Curl_ssl_connect(param_1,0), iVar3 != 0)) {
    return;
  }
  Curl_pp_init(param_1 + 0x3c0);
  *(undefined4 *)(param_1 + 0x428) = 1;
  ftp_multi_statemach(param_1,param_2);
  return;
}

