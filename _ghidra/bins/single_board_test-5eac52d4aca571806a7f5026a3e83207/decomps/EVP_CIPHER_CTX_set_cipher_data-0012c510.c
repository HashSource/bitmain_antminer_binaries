
undefined4 EVP_CIPHER_CTX_set_cipher_data(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x60) = param_2;
  return uVar1;
}

