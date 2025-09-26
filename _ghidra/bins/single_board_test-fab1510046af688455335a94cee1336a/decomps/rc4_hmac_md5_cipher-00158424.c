
undefined4 rc4_hmac_md5_cipher(int param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  int iVar1;
  RC4_KEY *key;
  size_t len;
  uchar *md;
  MD5_CTX *pMVar2;
  size_t len_00;
  uchar auStack_30 [20];
  
  key = *(RC4_KEY **)(param_1 + 0x60);
  len = key->data[0x84];
  if (len == 0xffffffff) {
    if (*(int *)(param_1 + 8) == 0) {
      RC4(key,param_4,param_3,param_2);
      MD5_Update((MD5_CTX *)(key->data + 0x6d),param_2,param_4);
    }
    else {
      MD5_Update((MD5_CTX *)(key->data + 0x6d),param_3,param_4);
      RC4(key,param_4,param_3,param_2);
    }
  }
  else {
    len_00 = len + 0x10;
    if (len_00 != param_4) {
      return 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      pMVar2 = (MD5_CTX *)(key->data + 0x6d);
      RC4(key,len_00,param_3,param_2);
      MD5_Update(pMVar2,param_2,len);
      MD5_Final(auStack_30,pMVar2);
      memcpy(pMVar2,key->data + 0x56,0x5c);
      MD5_Update(pMVar2,auStack_30,0x10);
      MD5_Final(auStack_30,pMVar2);
      iVar1 = CRYPTO_memcmp(param_2 + len,auStack_30,0x10);
      if (iVar1 != 0) {
        return 0;
      }
    }
    else {
      pMVar2 = (MD5_CTX *)(key->data + 0x6d);
      MD5_Update(pMVar2,param_3,len);
      if (param_3 != param_2) {
        memcpy(param_2,param_3,len);
      }
      md = param_2 + len;
      MD5_Final(md,pMVar2);
      memcpy(pMVar2,key->data + 0x56,0x5c);
      MD5_Update(pMVar2,md,0x10);
      MD5_Final(md,pMVar2);
      RC4(key,len_00,param_2,param_2);
    }
  }
  key->data[0x84] = 0xffffffff;
  return 1;
}

