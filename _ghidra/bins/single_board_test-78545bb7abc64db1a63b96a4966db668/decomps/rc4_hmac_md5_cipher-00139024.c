
undefined4 rc4_hmac_md5_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  RC4_KEY *key;
  int iVar1;
  size_t len;
  uchar *md;
  MD5_CTX *pMVar2;
  size_t len_00;
  uchar auStack_30 [16];
  
  key = (RC4_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  len = key[1].data[0x43];
  if (len == 0xffffffff) {
    iVar1 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar1 == 0) {
      RC4(key,param_4,param_3,param_2);
      MD5_Update((MD5_CTX *)(key[1].data + 0x2c),param_2,param_4);
    }
    else {
      MD5_Update((MD5_CTX *)(key[1].data + 0x2c),param_3,param_4);
      RC4(key,param_4,param_3,param_2);
    }
  }
  else {
    len_00 = len + 0x10;
    if (len_00 != param_4) {
      return 0;
    }
    iVar1 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar1 == 0) {
      pMVar2 = (MD5_CTX *)(key[1].data + 0x2c);
      RC4(key,len_00,param_3,param_2);
      MD5_Update(pMVar2,param_2,len);
      MD5_Final(auStack_30,pMVar2);
      memcpy(pMVar2,key[1].data + 0x15,0x5c);
      MD5_Update(pMVar2,auStack_30,0x10);
      MD5_Final(auStack_30,pMVar2);
      iVar1 = CRYPTO_memcmp(param_2 + len,auStack_30,0x10);
      if (iVar1 != 0) {
        return 0;
      }
    }
    else {
      pMVar2 = (MD5_CTX *)(key[1].data + 0x2c);
      MD5_Update(pMVar2,param_3,len);
      if (param_3 != param_2) {
        memcpy(param_2,param_3,len);
      }
      md = param_2 + len;
      MD5_Final(md,pMVar2);
      memcpy(pMVar2,key[1].data + 0x15,0x5c);
      MD5_Update(pMVar2,md,0x10);
      MD5_Final(md,pMVar2);
      RC4(key,len_00,param_2,param_2);
    }
  }
  key[1].data[0x43] = 0xffffffff;
  return 1;
}

