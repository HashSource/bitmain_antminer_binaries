
undefined4 ssl_cert_get_cert_store(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xe8);
  if (param_3 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0xec);
  }
  *param_2 = uVar1;
  return 1;
}

