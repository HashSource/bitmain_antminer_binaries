
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
  char *pcVar9;
  _STACK *p_Var10;
  _STACK *st;
  X509_INFO *pXVar11;
  char *local_5c;
  int local_58;
  code *local_54;
  char *local_50;
  char *local_4c;
  uchar *local_48;
  uchar *local_44;
  long local_40;
  EVP_CIPHER_INFO EStack_3c;
  
  local_50 = (char *)0x0;
  local_4c = (char *)0x0;
  local_48 = (uchar *)0x0;
  st = &sk->stack;
  if ((sk == (stack_st_X509_INFO *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
    ERR_put_error(9,0x74,0x41,"pem_info.c",0x6b);
    p_Var10 = st;
  }
  else {
    pXVar2 = X509_INFO_new();
    p_Var10 = st;
    if (pXVar2 != (X509_INFO *)0x0) {
LAB_001a581e:
      iVar3 = PEM_read_bio(bp,&local_50,&local_4c,&local_48,&local_40);
      if (iVar3 != 0) {
        do {
          pcVar9 = local_50;
          iVar3 = strcmp(local_50,"CERTIFICATE");
          pXVar11 = pXVar2;
          if ((iVar3 == 0) || (iVar3 = strcmp(pcVar9,"X509 CERTIFICATE"), iVar3 == 0)) {
            if (pXVar2->x509 == (X509 *)0x0) goto code_r0x001a587e;
LAB_001a5850:
            iVar3 = sk_push(st,pXVar2);
            if (iVar3 == 0) goto LAB_001a5a3a;
          }
          else {
            iVar3 = strcmp(pcVar9,"TRUSTED CERTIFICATE");
            if (iVar3 == 0) {
              if (pXVar2->x509 != (X509 *)0x0) goto LAB_001a5850;
              local_54 = (code *)0x157a11;
              local_58 = 0;
              pcVar9 = local_4c;
              goto LAB_001a588a;
            }
            iVar3 = strcmp(pcVar9,"X509 CRL");
            if (iVar3 == 0) {
              if (pXVar2->crl != (X509_CRL *)0x0) goto LAB_001a5850;
              pXVar11 = (X509_INFO *)&pXVar2->crl;
              local_54 = (code *)0x1a1b29;
              local_58 = 0;
              pcVar9 = local_4c;
              goto LAB_001a588a;
            }
            iVar3 = strcmp(pcVar9,"RSA PRIVATE KEY");
            if (iVar3 == 0) {
              if (pXVar2->x_pkey != (X509_PKEY *)0x0) goto LAB_001a5850;
              pXVar2->enc_data = (char *)0x0;
              pXVar2->enc_len = 0;
              pXVar5 = X509_PKEY_new();
              pcVar9 = local_4c;
              pXVar2->x_pkey = pXVar5;
              local_5c = local_4c;
              sVar6 = strlen(local_4c);
              if ((int)sVar6 < 0xb) {
                pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
                local_58 = 6;
                local_54 = (code *)0x1473dd;
                goto LAB_001a588a;
              }
LAB_001a5ab4:
              iVar3 = PEM_get_EVP_CIPHER_INFO(local_5c,&pXVar2->enc_cipher);
              puVar1 = local_48;
              if (iVar3 == 0) goto LAB_001a5a3c;
              local_48 = (uchar *)0x0;
              pXVar2->enc_data = (char *)puVar1;
              pXVar2->enc_len = local_40;
              pcVar9 = local_50;
              goto LAB_001a58ce;
            }
            iVar3 = strcmp(pcVar9,"DSA PRIVATE KEY");
            if (iVar3 != 0) {
              iVar3 = strcmp(pcVar9,"EC PRIVATE KEY");
              if (iVar3 != 0) goto LAB_001a58ce;
              if (pXVar2->x_pkey != (X509_PKEY *)0x0) goto LAB_001a5850;
              pXVar2->enc_data = (char *)0x0;
              pXVar2->enc_len = 0;
              pXVar5 = X509_PKEY_new();
              pcVar9 = local_4c;
              pXVar2->x_pkey = pXVar5;
              local_5c = local_4c;
              sVar6 = strlen(local_4c);
              if (10 < (int)sVar6) goto LAB_001a5ab4;
              pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
              local_58 = 0x198;
              local_54 = (code *)0x18e379;
              goto LAB_001a588a;
            }
            if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
              pXVar2->enc_data = (char *)0x0;
              pXVar2->enc_len = 0;
              pXVar5 = X509_PKEY_new();
              pcVar9 = local_4c;
              pXVar2->x_pkey = pXVar5;
              local_5c = local_4c;
              sVar6 = strlen(local_4c);
              if (10 < (int)sVar6) goto LAB_001a5ab4;
              pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
              local_58 = 0x74;
              local_54 = (code *)0x147731;
              goto LAB_001a588a;
            }
            iVar3 = sk_push(st,pXVar2);
            if (iVar3 == 0) goto LAB_001a5a3c;
          }
          pXVar2 = X509_INFO_new();
          if (pXVar2 == (X509_INFO *)0x0) goto LAB_001a598e;
        } while( true );
      }
      uVar8 = ERR_peek_last_error();
      if ((uVar8 & 0xfff) == 0x6c) {
        ERR_clear_error();
        if ((((pXVar2->x509 == (X509 *)0x0) && (pXVar2->crl == (X509_CRL *)0x0)) &&
            (pXVar2->x_pkey == (X509_PKEY *)0x0)) && (pXVar2->enc_data == (char *)0x0)) {
          iVar3 = 1;
        }
        else {
          iVar3 = sk_push(st,pXVar2);
          if (iVar3 != 0) goto LAB_001a59b8;
        }
        goto LAB_001a5a3c;
      }
      goto LAB_001a5a3a;
    }
  }
LAB_001a598e:
  iVar3 = 0;
  while( true ) {
    iVar7 = sk_num(p_Var10);
    if (iVar7 <= iVar3) break;
    pXVar2 = (X509_INFO *)sk_value(p_Var10,iVar3);
    X509_INFO_free(pXVar2);
    iVar3 = iVar3 + 1;
  }
  st = (_STACK *)0x0;
  if (p_Var10 != &sk->stack) {
    sk_free(p_Var10);
  }
LAB_001a59b8:
  if (local_50 != (char *)0x0) {
    CRYPTO_free(local_50);
  }
  if (local_4c != (char *)0x0) {
    CRYPTO_free(local_4c);
  }
  if (local_48 != (uchar *)0x0) {
    CRYPTO_free(local_48);
  }
  return (stack_st_X509_INFO *)st;
code_r0x001a587e:
  local_54 = (code *)0x1579a5;
  local_58 = 0;
  pcVar9 = local_4c;
LAB_001a588a:
  iVar3 = PEM_get_EVP_CIPHER_INFO(pcVar9,&EStack_3c);
  if ((iVar3 == 0) || (iVar3 = PEM_do_header(&EStack_3c,local_48,&local_40,cb,u), iVar3 == 0))
  goto LAB_001a5a3a;
  local_44 = local_48;
  if (local_58 == 0) {
    iVar3 = (*local_54)(pXVar11,&local_44,local_40);
    pcVar9 = local_50;
    if (iVar3 != 0) goto LAB_001a58ce;
    iVar3 = 0xf3;
  }
  else {
    pEVar4 = d2i_PrivateKey(local_58,(EVP_PKEY **)pXVar11,&local_44,local_40);
    pcVar9 = local_50;
    if (pEVar4 != (EVP_PKEY *)0x0) {
LAB_001a58ce:
      if (pcVar9 != (char *)0x0) {
        CRYPTO_free(pcVar9);
      }
      if (local_4c != (char *)0x0) {
        CRYPTO_free(local_4c);
      }
      if (local_48 != (uchar *)0x0) {
        CRYPTO_free(local_48);
      }
      local_50 = (char *)0x0;
      local_4c = (char *)0x0;
      local_48 = (uchar *)0x0;
      goto LAB_001a581e;
    }
    iVar3 = 0xef;
  }
  ERR_put_error(9,0x74,0xd,"pem_info.c",iVar3);
LAB_001a5a3a:
  iVar3 = 0;
LAB_001a5a3c:
  X509_INFO_free(pXVar2);
  if (iVar3 != 0) goto LAB_001a59b8;
  goto LAB_001a598e;
}

