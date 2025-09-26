
undefined4
aria_ctr_cipher(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_2c [2];
  
  local_2c[0] = EVP_CIPHER_CTX_num();
  uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
  uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
  CRYPTO_ctr128_encrypt(param_3,param_2,param_4,uVar1,uVar2,uVar3,local_2c,0x185efd);
  EVP_CIPHER_CTX_set_num(param_1,local_2c[0]);
  return 1;
}

