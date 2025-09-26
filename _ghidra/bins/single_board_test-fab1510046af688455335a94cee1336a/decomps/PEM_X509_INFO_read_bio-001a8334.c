
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
LAB_001a835e:
      iVar3 = PEM_read_bio(bp,&local_50,&local_4c,&local_48,&local_40);
      if (iVar3 != 0) {
        do {
          pcVar9 = local_50;
          iVar3 = strcmp(local_50,"CERTIFICATE");
          pXVar11 = pXVar2;
          if ((iVar3 == 0) || (iVar3 = strcmp(pcVar9,"X509 CERTIFICATE"), iVar3 == 0)) {
            if (pXVar2->x509 == (X509 *)0x0) goto code_r0x001a83be;
LAB_001a8390:
            iVar3 = sk_push(st,pXVar2);
            if (iVar3 == 0) goto LAB_001a857a;
          }
          else {
            iVar3 = strcmp(pcVar9,"TRUSTED CERTIFICATE");
            if (iVar3 == 0) {
              if (pXVar2->x509 != (X509 *)0x0) goto LAB_001a8390;
              local_54 = (code *)0x15a551;
              local_58 = 0;
              pcVar9 = local_4c;
              goto LAB_001a83ca;
            }
            iVar3 = strcmp(pcVar9,"X509 CRL");
            if (iVar3 == 0) {
              if (pXVar2->crl != (X509_CRL *)0x0) goto LAB_001a8390;
              pXVar11 = (X509_INFO *)&pXVar2->crl;
              local_54 = (code *)0x1a4669;
              local_58 = 0;
              pcVar9 = local_4c;
              goto LAB_001a83ca;
            }
            iVar3 = strcmp(pcVar9,"RSA PRIVATE KEY");
            if (iVar3 == 0) {
              if (pXVar2->x_pkey != (X509_PKEY *)0x0) goto LAB_001a8390;
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
                local_54 = (code *)0x149f1d;
                goto LAB_001a83ca;
              }
LAB_001a85f4:
              iVar3 = PEM_get_EVP_CIPHER_INFO(local_5c,&pXVar2->enc_cipher);
              puVar1 = local_48;
              if (iVar3 == 0) goto LAB_001a857c;
              local_48 = (uchar *)0x0;
              pXVar2->enc_data = (char *)puVar1;
              pXVar2->enc_len = local_40;
              pcVar9 = local_50;
              goto LAB_001a840e;
            }
            iVar3 = strcmp(pcVar9,"DSA PRIVATE KEY");
            if (iVar3 != 0) {
              iVar3 = strcmp(pcVar9,"EC PRIVATE KEY");
              if (iVar3 != 0) goto LAB_001a840e;
              if (pXVar2->x_pkey != (X509_PKEY *)0x0) goto LAB_001a8390;
              pXVar2->enc_data = (char *)0x0;
              pXVar2->enc_len = 0;
              pXVar5 = X509_PKEY_new();
              pcVar9 = local_4c;
              pXVar2->x_pkey = pXVar5;
              local_5c = local_4c;
              sVar6 = strlen(local_4c);
              if (10 < (int)sVar6) goto LAB_001a85f4;
              pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
              local_58 = 0x198;
              local_54 = (code *)0x190eb9;
              goto LAB_001a83ca;
            }
            if (pXVar2->x_pkey == (X509_PKEY *)0x0) {
              pXVar2->enc_data = (char *)0x0;
              pXVar2->enc_len = 0;
              pXVar5 = X509_PKEY_new();
              pcVar9 = local_4c;
              pXVar2->x_pkey = pXVar5;
              local_5c = local_4c;
              sVar6 = strlen(local_4c);
              if (10 < (int)sVar6) goto LAB_001a85f4;
              pXVar11 = (X509_INFO *)&pXVar5->dec_pkey;
              local_58 = 0x74;
              local_54 = (code *)0x14a271;
              goto LAB_001a83ca;
            }
            iVar3 = sk_push(st,pXVar2);
            if (iVar3 == 0) goto LAB_001a857c;
          }
          pXVar2 = X509_INFO_new();
          if (pXVar2 == (X509_INFO *)0x0) goto LAB_001a84ce;
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
          if (iVar3 != 0) goto LAB_001a84f8;
        }
        goto LAB_001a857c;
      }
      goto LAB_001a857a;
    }
  }
LAB_001a84ce:
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
LAB_001a84f8:
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
code_r0x001a83be:
  local_54 = (code *)0x15a4e5;
  local_58 = 0;
  pcVar9 = local_4c;
LAB_001a83ca:
  iVar3 = PEM_get_EVP_CIPHER_INFO(pcVar9,&EStack_3c);
  if ((iVar3 == 0) || (iVar3 = PEM_do_header(&EStack_3c,local_48,&local_40,cb,u), iVar3 == 0))
  goto LAB_001a857a;
  local_44 = local_48;
  if (local_58 == 0) {
    iVar3 = (*local_54)(pXVar11,&local_44,local_40);
    pcVar9 = local_50;
    if (iVar3 != 0) goto LAB_001a840e;
    iVar3 = 0xf3;
  }
  else {
    pEVar4 = d2i_PrivateKey(local_58,(EVP_PKEY **)pXVar11,&local_44,local_40);
    pcVar9 = local_50;
    if (pEVar4 != (EVP_PKEY *)0x0) {
LAB_001a840e:
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
      goto LAB_001a835e;
    }
    iVar3 = 0xef;
  }
  ERR_put_error(9,0x74,0xd,"pem_info.c",iVar3);
LAB_001a857a:
  iVar3 = 0;
LAB_001a857c:
  X509_INFO_free(pXVar2);
  if (iVar3 != 0) goto LAB_001a84f8;
  goto LAB_001a84ce;
}

