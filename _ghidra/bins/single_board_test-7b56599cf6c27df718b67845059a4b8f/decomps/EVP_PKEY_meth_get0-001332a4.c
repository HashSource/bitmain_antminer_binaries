
undefined *
EVP_PKEY_meth_get0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 extraout_r2;
  
  if (param_1 < 0x12) {
    return (&standard_methods)[param_1];
  }
  if (app_pkey_methods != 0) {
    uVar1 = OPENSSL_sk_num(app_pkey_methods);
    if (param_1 - 0x12 < uVar1) {
      puVar2 = (undefined *)OPENSSL_sk_value(app_pkey_methods,param_1 - 0x12,extraout_r2,param_4);
      return puVar2;
    }
  }
  return (undefined *)0x0;
}

