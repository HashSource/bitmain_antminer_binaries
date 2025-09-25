
bool OCSP_REQ_CTX_http(undefined4 *param_1,undefined4 param_2,undefined *param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_3 == (undefined *)0x0) {
    param_3 = &DAT_00204984;
  }
  iVar1 = BIO_printf((BIO *)param_1[4],"%s %s HTTP/1.0\r\n",param_2,param_3,param_4);
  if (0 < iVar1) {
    *param_1 = 0x1009;
  }
  return 0 < iVar1;
}

