
undefined4 sm4_init_key(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = EVP_CIPHER_CTX_get_cipher_data();
  SM4_set_key(param_2,uVar1);
  return 1;
}

