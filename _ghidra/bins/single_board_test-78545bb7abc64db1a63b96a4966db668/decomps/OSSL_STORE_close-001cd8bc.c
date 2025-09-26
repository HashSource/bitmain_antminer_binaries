
undefined4 OSSL_STORE_close(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x24))(param_1[1]);
    CRYPTO_free(param_1);
    return uVar1;
  }
  return 1;
}

