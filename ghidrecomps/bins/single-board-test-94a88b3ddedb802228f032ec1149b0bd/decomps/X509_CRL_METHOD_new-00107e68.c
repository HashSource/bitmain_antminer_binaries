
void X509_CRL_METHOD_new(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x14,DAT_00107e90,0x1e3);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_1;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    puVar1[4] = param_4;
    *puVar1 = 1;
  }
  return;
}

