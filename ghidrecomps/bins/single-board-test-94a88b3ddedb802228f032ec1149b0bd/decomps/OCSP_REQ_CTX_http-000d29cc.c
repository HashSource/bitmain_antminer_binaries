
bool OCSP_REQ_CTX_http(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = DAT_000d29f4;
  if (param_3 != 0) {
    iVar1 = param_3;
  }
  iVar1 = BIO_printf((BIO *)param_1[4],DAT_000d29f8,param_2,iVar1,param_4);
  if (0 < iVar1) {
    *param_1 = 0x1009;
  }
  return 0 < iVar1;
}

