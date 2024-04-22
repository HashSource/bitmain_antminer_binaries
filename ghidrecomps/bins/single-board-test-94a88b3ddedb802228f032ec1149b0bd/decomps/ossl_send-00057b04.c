
int ossl_send(undefined4 *param_1,int param_2,void *param_3,int param_4,undefined4 *param_5)

{
  int ret_code;
  char *pcVar1;
  char **ppcVar2;
  ulong e;
  undefined4 uVar3;
  undefined4 uVar4;
  char acStack_90 [124];
  
  ERR_clear_error();
  if (param_4 < 0) {
    param_4 = 0x7fffffff;
  }
  ret_code = SSL_write((SSL *)param_1[param_2 * 6 + 0x62],param_3,param_4);
  if (ret_code < 1) {
    pcVar1 = (char *)SSL_get_error((SSL *)param_1[param_2 * 6 + 0x62],ret_code);
    switch(pcVar1) {
    case (char *)0x1:
      e = ERR_get_error();
      uVar3 = *param_1;
      pcVar1 = ERR_error_string(e,acStack_90);
      uVar4 = DAT_00057ba0;
      break;
    case (char *)0x2:
    case (char *)0x3:
      *param_5 = 0x51;
      return -1;
    default:
      uVar3 = *param_1;
      uVar4 = DAT_00057ba4;
      break;
    case (char *)0x5:
      ppcVar2 = (char **)__errno_location();
      pcVar1 = *ppcVar2;
      uVar3 = *param_1;
      uVar4 = DAT_00057b9c;
    }
    Curl_failf(uVar3,uVar4,pcVar1);
    ret_code = -1;
    *param_5 = 0x37;
  }
  else {
    *param_5 = 0;
  }
  return ret_code;
}

