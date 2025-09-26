
undefined4 ct_strict(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 != 0) && (iVar1 = OPENSSL_sk_num(param_2), 0 < iVar1)) {
    iVar3 = 0;
    do {
      OPENSSL_sk_value(param_2,iVar3);
      iVar2 = SCT_get_validation_status();
      iVar3 = iVar3 + 1;
      if (iVar2 == 2) {
        return 1;
      }
    } while (iVar3 != iVar1);
  }
  ERR_put_error(0x14,0x15d,0xd8,"ssl/ssl_lib.c",0x1330);
  return 0;
}

