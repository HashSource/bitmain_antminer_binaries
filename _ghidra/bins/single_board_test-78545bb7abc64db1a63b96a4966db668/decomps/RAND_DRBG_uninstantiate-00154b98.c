
undefined4 RAND_DRBG_uninstantiate(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xf0) != 0) {
    (**(code **)(*(int *)(param_1 + 0xf0) + 0xc))();
    uVar1 = RAND_DRBG_set(param_1,*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0x14));
    return uVar1;
  }
  *(undefined4 *)(param_1 + 0x5c) = 2;
  ERR_put_error(0x24,0x76,0x80,"crypto/rand/drbg_lib.c",0x17e);
  return 0;
}

