
uint pkey_rsa_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,size_t param_5)

{
  size_t m_length;
  int iVar1;
  uint uVar2;
  void *__dest;
  uchar *EM;
  int iVar3;
  int iVar4;
  RSA *rsa;
  uint local_2c [2];
  
  iVar4 = *(int *)(param_1 + 0x14);
  rsa = *(RSA **)(*(int *)(param_1 + 8) + 0x18);
  if (*(EVP_MD **)(iVar4 + 0x18) == (EVP_MD *)0x0) {
    local_2c[0] = RSA_private_encrypt(param_5,param_4,param_2,rsa,*(int *)(iVar4 + 0x14));
    goto LAB_0014ea1a;
  }
  m_length = EVP_MD_size(*(EVP_MD **)(iVar4 + 0x18));
  if (m_length != param_5) {
    ERR_put_error(4,0x8e,0x8f,"crypto/rsa/rsa_pmeth.c",0x86);
    return -1;
  }
  iVar1 = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x18));
  iVar3 = *(int *)(iVar4 + 0x14);
  if (iVar1 == 0x5f) {
    if (iVar3 != 1) {
      return -1;
    }
    iVar4 = RSA_sign_ASN1_OCTET_STRING(0,param_4,m_length,param_2,local_2c,rsa);
  }
  else {
    if (iVar3 == 5) {
      uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
      if (uVar2 < m_length + 1) {
        ERR_put_error(4,0x8e,0x78,"crypto/rsa/rsa_pmeth.c",0x96);
        return -1;
      }
      __dest = *(void **)(iVar4 + 0x28);
      if (__dest == (void *)0x0) {
        iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        __dest = CRYPTO_malloc(iVar1,"crypto/rsa/rsa_pmeth.c",0x6a);
        *(void **)(iVar4 + 0x28) = __dest;
        if (__dest == (void *)0x0) {
          ERR_put_error(4,0xa7,0x41,"crypto/rsa/rsa_pmeth.c",0x6b);
          ERR_put_error(4,0x8e,0x41,"crypto/rsa/rsa_pmeth.c",0x9a);
          return -1;
        }
      }
      memcpy(__dest,param_4,m_length);
      iVar3 = *(int *)(iVar4 + 0x28);
      iVar1 = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x18));
      iVar1 = RSA_X931_hash_id(iVar1);
      *(char *)(iVar3 + m_length) = (char)iVar1;
      local_2c[0] = RSA_private_encrypt(m_length + 1,*(uchar **)(iVar4 + 0x28),param_2,rsa,5);
      goto LAB_0014ea1a;
    }
    if (iVar3 != 1) {
      if (iVar3 != 6) {
        return -1;
      }
      EM = *(uchar **)(iVar4 + 0x28);
      if (EM == (uchar *)0x0) {
        iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        EM = (uchar *)CRYPTO_malloc(iVar1,"crypto/rsa/rsa_pmeth.c",0x6a);
        *(uchar **)(iVar4 + 0x28) = EM;
        if (EM == (uchar *)0x0) {
          ERR_put_error(4,0xa7,0x41,"crypto/rsa/rsa_pmeth.c",0x6b);
          return -1;
        }
      }
      iVar1 = RSA_padding_add_PKCS1_PSS_mgf1
                        (rsa,EM,param_4,*(EVP_MD **)(iVar4 + 0x18),*(EVP_MD **)(iVar4 + 0x1c),
                         *(int *)(iVar4 + 0x20));
      if (iVar1 == 0) {
        return -1;
      }
      iVar1 = RSA_size(rsa);
      local_2c[0] = RSA_private_encrypt(iVar1,*(uchar **)(iVar4 + 0x28),param_2,rsa,3);
      goto LAB_0014ea1a;
    }
    iVar4 = EVP_MD_type(*(EVP_MD **)(iVar4 + 0x18));
    iVar4 = RSA_sign(iVar4,param_4,m_length,param_2,local_2c,rsa);
  }
  if (iVar4 < 1) {
    return iVar4;
  }
LAB_0014ea1a:
  if (-1 < (int)local_2c[0]) {
    *param_3 = local_2c[0];
    local_2c[0] = 1;
  }
  return local_2c[0];
}

