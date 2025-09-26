
undefined4 OPENSSL_sk_push(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = OPENSSL_sk_insert(param_1,param_2,*param_1);
    return uVar1;
  }
  return 0xffffffff;
}

