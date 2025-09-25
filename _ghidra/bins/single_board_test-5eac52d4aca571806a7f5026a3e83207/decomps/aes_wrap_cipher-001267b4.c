
int aes_wrap_cipher(EVP_CIPHER_CTX *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  iVar2 = EVP_CIPHER_CTX_iv_length(param_1);
  if (param_3 == 0) {
    return 0;
  }
  if (param_4 == 0) {
    return -1;
  }
  iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
  if (iVar3 == 0) {
    if (param_4 < 0x10) {
      return -1;
    }
  }
  else if (iVar2 == 4) goto LAB_001267fe;
  if ((param_4 & 7) != 0) {
    return -1;
  }
LAB_001267fe:
  iVar3 = is_partially_overlapping(param_2,param_3,param_4);
  if (iVar3 != 0) {
    ERR_put_error(6,0xaa,0xa2,"crypto/evp/e_aes.c",0xef3);
    return 0;
  }
  if (param_2 != 0) {
    if (iVar2 == 4) {
      iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar2 == 0) {
        iVar1 = CRYPTO_128_unwrap_pad
                          (iVar1,*(undefined4 *)(iVar1 + 0xf8),param_2,param_3,param_4,0x177cc5);
      }
      else {
        iVar1 = CRYPTO_128_wrap_pad(iVar1,*(undefined4 *)(iVar1 + 0xf8),param_2,param_3,param_4,
                                    0x1778a9);
      }
    }
    else {
      iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar2 == 0) {
        iVar1 = CRYPTO_128_unwrap(iVar1,*(undefined4 *)(iVar1 + 0xf8),param_2,param_3,param_4,
                                  0x177cc5);
      }
      else {
        iVar1 = CRYPTO_128_wrap(iVar1,*(undefined4 *)(iVar1 + 0xf8),param_2,param_3,param_4,0x1778a9
                               );
      }
    }
    if (iVar1 == 0) {
      return -1;
    }
    return iVar1;
  }
  iVar1 = EVP_CIPHER_CTX_encrypting(param_1);
  if (iVar1 == 0) {
    return param_4 - 8;
  }
  if (iVar2 == 4) {
    param_4 = param_4 + 7 & 0xfffffff8;
  }
  return param_4 + 8;
}

