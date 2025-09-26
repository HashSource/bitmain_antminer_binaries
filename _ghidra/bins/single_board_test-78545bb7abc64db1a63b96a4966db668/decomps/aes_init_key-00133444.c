
int aes_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  AES_KEY *key;
  EVP_CIPHER *cipher;
  ulong uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  key = (AES_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  cipher = EVP_CIPHER_CTX_cipher(param_1);
  uVar1 = EVP_CIPHER_flags(cipher);
  uVar3 = (uVar1 & 0xf0007) - 1;
  bVar4 = uVar3 == 1;
  if (uVar3 < 2) {
    bVar4 = param_4 == 0;
  }
  if (bVar4) {
    iVar2 = EVP_CIPHER_CTX_key_length(param_1);
    iVar2 = AES_set_decrypt_key(param_2,iVar2 << 3,key);
    key[1].rd_key[1] = 0x185aed;
  }
  else {
    iVar2 = EVP_CIPHER_CTX_key_length(param_1);
    iVar2 = AES_set_encrypt_key(param_2,iVar2 << 3,key);
    key[1].rd_key[1] = 0x1856d1;
  }
  if ((uVar1 & 0xf0007) == 2) {
    bVar4 = -1 < iVar2;
    if (bVar4) {
      iVar2 = 1;
    }
    key[1].rd_key[2] = 0x184b61;
    if (bVar4) {
      return iVar2;
    }
  }
  else {
    key[1].rd_key[2] = 0;
    if (-1 < iVar2) {
      return 1;
    }
  }
  ERR_put_error(6,0x85,0x8f,"crypto/evp/e_aes.c",0xa87);
  return 0;
}

