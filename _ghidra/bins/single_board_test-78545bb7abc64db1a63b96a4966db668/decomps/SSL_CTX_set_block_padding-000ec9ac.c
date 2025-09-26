
undefined4 SSL_CTX_set_block_padding(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    param_4 = 0;
  }
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x230) = param_4;
    uVar1 = 1;
  }
  else if (param_2 < 0x4001) {
    *(uint *)(param_1 + 0x230) = param_2;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

