
undefined4
SSL_bytes_to_cipher_list
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 local_18;
  int local_14;
  
  if (-1 < param_3) {
    local_18 = param_2;
    local_14 = param_3;
    uVar1 = bytes_to_cipher_list(param_1,&local_18,param_5,param_6,param_4,0);
    return uVar1;
  }
  return 0;
}

