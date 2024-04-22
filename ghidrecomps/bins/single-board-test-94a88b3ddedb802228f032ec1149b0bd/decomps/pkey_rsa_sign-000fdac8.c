
uint pkey_rsa_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,uint param_5)

{
  uint m_length;
  int iVar1;
  uint uVar2;
  void *__dest;
  uchar *EM;
  int iVar3;
  int iVar4;
  RSA *rsa;
  uint local_2c [2];
  
  iVar4 = *(int *)(param_1 + 0x14);
  rsa = *(RSA **)(*(int *)(param_1 + 8) + 0x14);
  if (*(EVP_MD **)(iVar4 + 0x14) == (EVP_MD *)0x0) {
    local_2c[0] = RSA_private_encrypt(param_5,param_4,param_2,rsa,*(int *)(iVar4 + 0x10));
LAB_000fdb34:
    if (-1 < (int)local_2c[0]) {
      *param_3 = local_2c[0];
      local_2c[0] = 1;
    }
  }
  else {
    m_length = EVP_MD_size(*(EVP_MD **)(iVar4 + 0x14));
    if (m_length != param_5) {
      ERR_put_error(4,0x8e,0x8f,DAT_000fdc40,0xe4);
      return -1;
    }
    iVar1 = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x14));
    iVar3 = *(int *)(iVar4 + 0x10);
    if (iVar1 == 0x5f) {
      if (iVar3 == 1) {
        iVar4 = RSA_sign_ASN1_OCTET_STRING(0x5f,param_4,m_length,param_2,local_2c,rsa);
joined_r0x000fdb72:
        if (iVar4 < 1) {
          return iVar4;
        }
        goto LAB_000fdb34;
      }
    }
    else if (iVar3 == 5) {
      uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
      if (m_length + 1 <= uVar2) {
        __dest = *(void **)(iVar4 + 0x20);
        if (__dest == (void *)0x0) {
          iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
          __dest = CRYPTO_malloc(iVar1,DAT_000fdc40,0x9c);
          *(void **)(iVar4 + 0x20) = __dest;
          if (__dest == (void *)0x0) {
            ERR_put_error(4,0x8e,0x41,DAT_000fdc40,0x106);
            return -1;
          }
        }
        memcpy(__dest,param_4,m_length);
        iVar3 = *(int *)(iVar4 + 0x20);
        iVar1 = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x14));
        iVar1 = RSA_X931_hash_id(iVar1);
        *(char *)(iVar3 + m_length) = (char)iVar1;
        local_2c[0] = RSA_private_encrypt(m_length + 1,*(uchar **)(iVar4 + 0x20),param_2,rsa,5);
        goto LAB_000fdb34;
      }
      ERR_put_error(4,0x8e,0x78,DAT_000fdc40,0x102);
    }
    else {
      if (iVar3 == 1) {
        iVar4 = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x14));
        iVar4 = RSA_sign(iVar4,param_4,m_length,param_2,local_2c,rsa);
        goto joined_r0x000fdb72;
      }
      if (iVar3 == 6) {
        EM = *(uchar **)(iVar4 + 0x20);
        if (EM == (uchar *)0x0) {
          iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
          EM = (uchar *)CRYPTO_malloc(iVar1,DAT_000fdc40,0x9c);
          *(uchar **)(iVar4 + 0x20) = EM;
          if (EM == (uchar *)0x0) goto LAB_000fdb56;
        }
        iVar1 = RSA_padding_add_PKCS1_PSS_mgf1
                          (rsa,EM,param_4,*(EVP_MD **)(iVar4 + 0x14),*(EVP_MD **)(iVar4 + 0x18),
                           *(int *)(iVar4 + 0x1c));
        if (iVar1 != 0) {
          iVar1 = RSA_size(rsa);
          local_2c[0] = RSA_private_encrypt(iVar1,*(uchar **)(iVar4 + 0x20),param_2,rsa,3);
          goto LAB_000fdb34;
        }
      }
    }
LAB_000fdb56:
    local_2c[0] = 0xffffffff;
  }
  return local_2c[0];
}

