
EC_KEY * EC_KEY_new_method(ENGINE *param_1)

{
  EC_KEY *key;
  int iVar1;
  undefined4 uVar2;
  int line;
  
  key = (EC_KEY *)CRYPTO_zalloc(0x30,"crypto/ec/ec_kmeth.c",0x4b);
  if (key == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xf5,0x41,"crypto/ec/ec_kmeth.c",0x4e);
    return (EC_KEY *)0x0;
  }
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(key + 0x20) = 1;
  DataMemoryBarrier(0x1b);
  iVar1 = CRYPTO_THREAD_lock_new();
  *(int *)(key + 0x2c) = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xf5,0x41,"crypto/ec/ec_kmeth.c",0x55);
    CRYPTO_free(key);
    return (EC_KEY *)0x0;
  }
  uVar2 = EC_KEY_get_default_method();
  *(undefined4 *)key = uVar2;
  if (param_1 == (ENGINE *)0x0) {
    param_1 = (ENGINE *)ENGINE_get_default_EC();
    *(ENGINE **)(key + 4) = param_1;
    if (param_1 != (ENGINE *)0x0) goto LAB_00119ad0;
LAB_00119ad8:
    *(undefined4 *)(key + 8) = 1;
    *(undefined4 *)(key + 0x1c) = 4;
    iVar1 = CRYPTO_new_ex_data(8,key,(CRYPTO_EX_DATA *)(key + 0x28));
    if (iVar1 != 0) {
      if ((*(code **)(*(int *)key + 8) == (code *)0x0) ||
         (iVar1 = (**(code **)(*(int *)key + 8))(key), iVar1 != 0)) {
        return key;
      }
      ERR_put_error(0x10,0xf5,0x46,"crypto/ec/ec_kmeth.c",0x75);
    }
  }
  else {
    iVar1 = ENGINE_init(param_1);
    line = 0x5e;
    if (iVar1 != 0) {
      *(ENGINE **)(key + 4) = param_1;
LAB_00119ad0:
      iVar1 = ENGINE_get_EC(param_1);
      *(int *)key = iVar1;
      if (iVar1 != 0) goto LAB_00119ad8;
      line = 0x67;
    }
    ERR_put_error(0x10,0xf5,0x26,"crypto/ec/ec_kmeth.c",line);
  }
  EC_KEY_free(key);
  return (EC_KEY *)0x0;
}

