
undefined4
aes_ctr_cipher(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_24 [2];
  
  local_24[0] = EVP_CIPHER_CTX_num();
  iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  if (*(int *)(iVar1 + 0xfc) == 0) {
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
    CRYPTO_ctr128_encrypt
              (param_3,param_2,param_4,iVar1,uVar2,uVar3,local_24,*(undefined4 *)(iVar1 + 0xf8));
  }
  else {
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
    CRYPTO_ctr128_encrypt_ctr32
              (param_3,param_2,param_4,iVar1,uVar2,uVar3,local_24,*(undefined4 *)(iVar1 + 0xfc));
  }
  EVP_CIPHER_CTX_set_num(param_1,local_24[0]);
  return 1;
}

