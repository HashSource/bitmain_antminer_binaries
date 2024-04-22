
void tls_decrypt_ticket(int param_1,uchar *param_2,int param_3,void *param_4,size_t param_5,
                       SSL_SESSION **param_6)

{
  int iVar1;
  EVP_MD *md;
  EVP_CIPHER *cipher;
  uchar *out;
  SSL_SESSION *pSVar2;
  size_t len;
  int iVar3;
  uchar *local_1c8;
  int local_1c4;
  size_t local_1c0;
  uchar auStack_1bc [64];
  EVP_CIPHER_CTX EStack_17c;
  HMAC_CTX local_f0;
  
  iVar3 = *(int *)(param_1 + 0x170);
  if (param_3 < 0x30) {
    return;
  }
  HMAC_CTX_init(&local_f0);
  EVP_CIPHER_CTX_init(&EStack_17c);
  if (*(code **)(iVar3 + 0x138) == (code *)0x0) {
    iVar1 = memcmp(param_2,(void *)(iVar3 + 0x108),0x10);
    if (iVar1 != 0) {
      return;
    }
    md = EVP_sha256();
    HMAC_Init_ex(&local_f0,(void *)(iVar3 + 0x118),0x10,md,(ENGINE *)0x0);
    cipher = EVP_aes_128_cbc();
    EVP_DecryptInit_ex(&EStack_17c,cipher,(ENGINE *)0x0,(uchar *)(iVar3 + 0x128),param_2 + 0x10);
  }
  else {
    iVar3 = (**(code **)(iVar3 + 0x138))(param_1,param_2,param_2 + 0x10,&EStack_17c,&local_f0,0);
    if (iVar3 < 0) {
      return;
    }
    if (iVar3 == 0) {
      return;
    }
  }
  local_1c0 = EVP_MD_size(local_f0.md);
  if (-1 < (int)local_1c0) {
    len = param_3 - local_1c0;
    HMAC_Update(&local_f0,param_2,len);
    HMAC_Final(&local_f0,auStack_1bc,(uint *)0x0);
    HMAC_CTX_cleanup(&local_f0);
    iVar3 = CRYPTO_memcmp(auStack_1bc,param_2 + len,local_1c0);
    if (iVar3 != 0) {
      EVP_CIPHER_CTX_cleanup(&EStack_17c);
      return;
    }
    iVar3 = EVP_CIPHER_CTX_iv_length(&EStack_17c);
    local_1c8 = param_2 + iVar3 + 0x10;
    iVar3 = EVP_CIPHER_CTX_iv_length(&EStack_17c);
    iVar3 = (-0x10 - iVar3) + len;
    out = (uchar *)CRYPTO_malloc(iVar3,DAT_00070174,0xd57);
    if (out != (uchar *)0x0) {
      EVP_DecryptUpdate(&EStack_17c,out,&local_1c4,local_1c8,iVar3);
      iVar3 = EVP_DecryptFinal(&EStack_17c,out + local_1c4,(int *)&local_1c0);
      if (iVar3 < 1) {
        EVP_CIPHER_CTX_cleanup(&EStack_17c);
        CRYPTO_free(out);
        return;
      }
      local_1c4 = local_1c4 + local_1c0;
      EVP_CIPHER_CTX_cleanup(&EStack_17c);
      local_1c8 = out;
      pSVar2 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1c8,local_1c4);
      CRYPTO_free(out);
      if (pSVar2 != (SSL_SESSION *)0x0) {
        if (param_5 != 0) {
          memcpy(pSVar2->session_id,param_4,param_5);
        }
        pSVar2->session_id_length = param_5;
        *param_6 = pSVar2;
        return;
      }
      ERR_clear_error();
      return;
    }
  }
  EVP_CIPHER_CTX_cleanup(&EStack_17c);
  return;
}

