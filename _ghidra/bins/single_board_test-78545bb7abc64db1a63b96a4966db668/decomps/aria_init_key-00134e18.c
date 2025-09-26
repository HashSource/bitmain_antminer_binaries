
undefined4 aria_init_key(EVP_CIPHER_CTX *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  EVP_CIPHER *cipher;
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  
  cipher = EVP_CIPHER_CTX_cipher(param_1);
  uVar1 = EVP_CIPHER_flags(cipher);
  if ((param_4 == 0) && ((uVar1 & 0xf0007) - 1 < 2)) {
    iVar2 = EVP_CIPHER_CTX_key_length(param_1);
    uVar3 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    iVar2 = aria_set_decrypt_key(param_2,iVar2 << 3,uVar3);
  }
  else {
    iVar2 = EVP_CIPHER_CTX_key_length(param_1);
    uVar3 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    iVar2 = aria_set_encrypt_key(param_2,iVar2 << 3,uVar3);
  }
  if (iVar2 < 0) {
    ERR_put_error(6,0xb9,0xb0,"crypto/evp/e_aria.c",0x49);
    return 0;
  }
  return 1;
}

