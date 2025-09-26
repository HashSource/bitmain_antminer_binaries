
stack_st_X509_INFO * PEM_X509_INFO_read_bio(BIO *bp,stack_st_X509_INFO *sk,undefined1 *cb,void *u)

{
  uchar *puVar1;
  X509_INFO *pXVar2;
  int iVar3;
  EVP_PKEY *pEVar4;
  X509_PKEY *pXVar5;
  size_t sVar6;
  int iVar7;
  ulong uVar8;
  stack_st_X509_INFO *psVar9;
  char *__s1;
  bool bVar10;
  X509_INFO *local_5c;
  code *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  uchar *local_48;
  uchar *local_44;
  long local_40;
  EVP_CIPHER_INFO EStack_3c;
  
  local_50 = (char *)0x0;
  local_4c = (char *)0x0;
  local_48 = (uchar *)0x0;
  psVar9 = sk;
  if ((sk == (stack_st_X509_INFO *)0x0) &&
     (psVar9 = (stack_st_X509_INFO *)OPENSSL_sk_new_null(), psVar9 == (stack_st_X509_INFO *)0x0)) {
    ERR_put_error(9,0x74,0x41,"crypto/pem/pem_info.c",0x36);
    pXVar2 = (X509_INFO *)0x0;
  }
  else {
    pXVar2 = X509_INFO_new();
    if (pXVar2 != (X509_INFO *)0x0) {
LAB_001c2c60:
      iVar3 = PEM_read_bio(bp,&local_50,&local_4c,&local_48,&local_40);
      if (iVar3 != 0) {
        do {
          __s1 = local_50;
          iVar3 = strcmp(local_50,"CERTIFICATE");
          local_5c = pXVar2;
          if ((iVar3 == 0) || (iVar3 = strcmp(__s1,"X509 CERTIFICATE"), iVar3 == 0)) {
            if (pXVar2->x509 == (X509 *)0x0) goto code_r0x001c2cbc;
          }
          else {
            iVar3 = strcmp(__s1,"TRUSTED CERTIFICATE");
            if (iVar3 == 0) {
              if (pXVar2->x509 == (X509 *)0x0) {
                local_58 = (code *)0x1781a5;
                goto LAB_001c2cc6;
              }
            }
            else {
              iVar3 = strcmp(__s1,"X509 CRL");
              if (iVar3 == 0) {
                if (pXVar2->crl == (X509_CRL *)0x0) {
                  local_5c = (X509_INFO *)&pXVar2->crl;
                  local_58 = (code *)0x176e09;
                  goto LAB_001c2cc6;
                }
              }
              else {
                iVar3 = strcmp(__s1,"RSA PRIVATE KEY");
                if (iVar3 == 0) {
                  if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                    pXVar2->enc_data = (char *)0x0;
                    pXVar2->enc_len = 0;
                    pXVar5 = X509_PKEY_new();
                    pXVar2->x_pkey = pXVar5;
                    if (pXVar5 != (X509_PKEY *)0x0) {
                      local_5c = (X509_INFO *)&pXVar5->dec_pkey;
                      iVar3 = 6;
                      local_54 = local_4c;
                      sVar6 = strlen(local_4c);
                      iVar7 = 0x5ec;
                      goto LAB_001c2da2;
                    }
                    goto LAB_001c2df4;
                  }
                }
                else {
                  iVar3 = strcmp(__s1,"DSA PRIVATE KEY");
                  if (iVar3 == 0) {
                    if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                      pXVar2->enc_data = (char *)0x0;
                      pXVar2->enc_len = 0;
                      pXVar5 = X509_PKEY_new();
                      pXVar2->x_pkey = pXVar5;
                      if (pXVar5 != (X509_PKEY *)0x0) {
                        local_5c = (X509_INFO *)&pXVar5->dec_pkey;
                        iVar3 = 0x74;
                        local_54 = local_4c;
                        sVar6 = strlen(local_4c);
                        iVar7 = 0x7b8;
                        goto LAB_001c2da2;
                      }
                      goto LAB_001c2df4;
                    }
                  }
                  else {
                    iVar3 = strcmp(__s1,"EC PRIVATE KEY");
                    if (iVar3 != 0) goto LAB_001c2d18;
                    if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
                      pXVar2->enc_data = (char *)0x0;
                      pXVar2->enc_len = 0;
                      pXVar5 = X509_PKEY_new();
                      pXVar2->x_pkey = pXVar5;
                      if (pXVar5 == (X509_PKEY *)0x0) goto LAB_001c2df4;
                      local_5c = (X509_INFO *)&pXVar5->dec_pkey;
                      iVar3 = 0x198;
                      local_54 = local_4c;
                      sVar6 = strlen(local_4c);
                      iVar7 = 1000;
LAB_001c2da2:
                      local_58 = *(code **)((int)&_GLOBAL_OFFSET_TABLE_ + iVar7);
                      if ((int)sVar6 < 0xb) goto LAB_001c2cd0;
                      iVar3 = PEM_get_EVP_CIPHER_INFO(local_54,&pXVar2->enc_cipher);
                      puVar1 = local_48;
                      if (iVar3 == 0) goto LAB_001c2df4;
                      local_48 = (uchar *)0x0;
                      pXVar2->enc_data = (char *)puVar1;
                      pXVar2->enc_len = local_40;
                      __s1 = local_50;
                      goto LAB_001c2d18;
                    }
                  }
                }
              }
            }
          }
          iVar3 = OPENSSL_sk_push(psVar9,pXVar2);
          if ((iVar3 == 0) || (pXVar2 = X509_INFO_new(), pXVar2 == (X509_INFO *)0x0))
          goto LAB_001c2df4;
        } while( true );
      }
      uVar8 = ERR_peek_last_error();
      if ((uVar8 & 0xfff) == 0x6c) {
        ERR_clear_error();
        if ((((pXVar2->x509 == (X509 *)0x0) && (pXVar2->crl == (X509_CRL *)0x0)) &&
            (pXVar2->x_pkey == (X509_PKEY *)0x0)) && (pXVar2->enc_data == (char *)0x0)) {
LAB_001c2f1a:
          X509_INFO_free(pXVar2);
          goto LAB_001c2e24;
        }
        iVar3 = OPENSSL_sk_push(psVar9,pXVar2);
        if (iVar3 != 0) {
          pXVar2 = (X509_INFO *)0x0;
          goto LAB_001c2f1a;
        }
      }
    }
  }
LAB_001c2df4:
  X509_INFO_free(pXVar2);
  iVar3 = 0;
  while( true ) {
    iVar7 = OPENSSL_sk_num(psVar9);
    if (iVar7 <= iVar3) break;
    pXVar2 = (X509_INFO *)OPENSSL_sk_value(psVar9,iVar3);
    X509_INFO_free(pXVar2);
    iVar3 = iVar3 + 1;
  }
  bVar10 = sk != psVar9;
  psVar9 = (stack_st_X509_INFO *)0x0;
  if (bVar10) {
    OPENSSL_sk_free();
  }
LAB_001c2e24:
  CRYPTO_free(local_50);
  CRYPTO_free(local_4c);
  CRYPTO_free(local_48);
  return psVar9;
code_r0x001c2cbc:
  local_58 = (code *)0x178125;
LAB_001c2cc6:
  iVar3 = 0;
  local_54 = local_4c;
LAB_001c2cd0:
  iVar7 = PEM_get_EVP_CIPHER_INFO(local_54,&EStack_3c);
  if ((iVar7 == 0) || (iVar7 = PEM_do_header(&EStack_3c,local_48,&local_40,cb,u), iVar7 == 0))
  goto LAB_001c2df4;
  local_44 = local_48;
  if (iVar3 == 0) {
    iVar3 = (*local_58)(local_5c,&local_44,local_40);
    __s1 = local_50;
    if (iVar3 == 0) {
      iVar3 = 0xc4;
      goto LAB_001c2de8;
    }
  }
  else {
    pEVar4 = d2i_PrivateKey(iVar3,(EVP_PKEY **)local_5c,&local_44,local_40);
    __s1 = local_50;
    if (pEVar4 == (EVP_PKEY *)0x0) {
      iVar3 = 0xc0;
LAB_001c2de8:
      ERR_put_error(9,0x74,0xd,"crypto/pem/pem_info.c",iVar3);
      goto LAB_001c2df4;
    }
  }
LAB_001c2d18:
  CRYPTO_free(__s1);
  local_50 = (char *)0x0;
  CRYPTO_free(local_4c);
  local_4c = (char *)0x0;
  CRYPTO_free(local_48);
  local_48 = (uchar *)0x0;
  goto LAB_001c2c60;
}

