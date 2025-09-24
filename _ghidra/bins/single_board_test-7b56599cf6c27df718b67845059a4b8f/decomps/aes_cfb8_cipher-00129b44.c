
undefined4
aes_cfb8_cipher(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_24;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  local_24 = EVP_CIPHER_CTX_num(param_1);
  uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
  uVar3 = EVP_CIPHER_CTX_encrypting(param_1);
  CRYPTO_cfb128_8_encrypt
            (param_3,param_2,param_4,iVar1,uVar2,&local_24,uVar3,*(undefined4 *)(iVar1 + 0xf8));
  EVP_CIPHER_CTX_set_num(param_1,local_24);
  return 1;
}

