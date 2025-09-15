
int ftp_epsv_disable(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((char)param_1[0x7d] != '\0') {
    Curl_failf(*param_1,"Failed EPSV attempt, exiting\n");
    return 8;
  }
  Curl_infof(*param_1,"Failed EPSV attempt. Disabling EPSV\n",param_3,param_4,param_4);
  *(undefined1 *)((int)param_1 + 0x1fd) = 0;
  *(undefined1 *)(*param_1 + 0x85c8) = 0;
  iVar1 = Curl_pp_sendf(param_1 + 0xf0,"%s",&DAT_0013c774);
  if (iVar1 == 0) {
    param_1[0x10a] = 0x1e;
    param_1[0x107] = param_1[0x107] + 1;
  }
  return iVar1;
}

