
undefined4 OSSL_STORE_find(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[7] == 0) {
    if (*(code **)(*param_1 + 0x14) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c3c9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(*param_1 + 0x14))(param_1[1]);
      return uVar1;
    }
    ERR_put_error(0x2c,0x83,0x76,"crypto/store/store_lib.c",0x9f);
  }
  else {
    ERR_put_error(0x2c,0x83,0x75,"crypto/store/store_lib.c",0x9a);
  }
  return 0;
}

