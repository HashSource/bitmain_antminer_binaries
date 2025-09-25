
undefined4 OSSL_STORE_supports_search(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_20 [7];
  
  if (*(code **)(*param_1 + 0x14) != (code *)0x0) {
    local_20[0] = param_2;
    uVar1 = (**(code **)(*param_1 + 0x14))(0,local_20);
    return uVar1;
  }
  return 0;
}

