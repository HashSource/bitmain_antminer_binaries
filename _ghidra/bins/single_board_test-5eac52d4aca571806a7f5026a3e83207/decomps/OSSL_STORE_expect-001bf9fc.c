
undefined4 OSSL_STORE_expect(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1[7] != 0) {
    ERR_put_error(0x2c,0x82,0x75,"crypto/store/store_lib.c",0x8c);
    return 0;
  }
  param_1[6] = param_2;
  if (*(code **)(*param_1 + 0x10) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001bfa0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x10))(param_1[1]);
    return uVar1;
  }
  return 1;
}

