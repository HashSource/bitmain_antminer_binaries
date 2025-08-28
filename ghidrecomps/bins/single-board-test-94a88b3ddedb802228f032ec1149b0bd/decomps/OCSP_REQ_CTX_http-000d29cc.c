
bool OCSP_REQ_CTX_http(undefined4 *param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4
                      )

{
  int iVar1;
  undefined2 *puVar2;
  
  puVar2 = &DAT_00135588;
  if (param_3 != (undefined2 *)0x0) {
    puVar2 = param_3;
  }
  iVar1 = BIO_printf((BIO *)param_1[4],"%s %s HTTP/1.0\r\n",param_2,puVar2,param_4);
  if (0 < iVar1) {
    *param_1 = 0x1009;
  }
  return 0 < iVar1;
}

