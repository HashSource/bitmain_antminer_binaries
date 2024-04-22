
uint ossl_recv(undefined4 *param_1,int param_2,void *param_3,int param_4,undefined4 *param_5)

{
  uint ret_code;
  int iVar1;
  ulong e;
  char *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  char acStack_90 [124];
  
  ERR_clear_error();
  if (param_4 < 0) {
    param_4 = 0x7fffffff;
  }
  ret_code = SSL_read((SSL *)param_1[param_2 * 6 + 0x62],param_3,param_4);
  if ((int)ret_code < 1) {
    iVar1 = SSL_get_error((SSL *)param_1[param_2 * 6 + 0x62],ret_code);
    switch(iVar1) {
    case 0:
    case 6:
      break;
    default:
      ret_code = ret_code >> 0x1f;
      e = ERR_get_error();
      if (e != 0) {
        ret_code = 1;
      }
      if (ret_code != 0) {
        uVar4 = *param_1;
        pcVar2 = ERR_error_string(e,acStack_90);
        piVar3 = __errno_location();
        ret_code = 0xffffffff;
        Curl_failf(uVar4,DAT_00057c58,pcVar2,*piVar3);
        *param_5 = 0x38;
      }
      break;
    case 2:
    case 3:
      ret_code = 0xffffffff;
      *param_5 = 0x51;
    }
  }
  return ret_code;
}

