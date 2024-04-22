
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  byte *pbVar1;
  long lVar2;
  ASN1_INTEGER *a;
  int iVar3;
  EVP_PKEY *pkey;
  X509_NAME *pXVar4;
  char *pcVar5;
  ASN1_UTCTIME *pAVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  X509_CINF *pXVar12;
  undefined4 uVar13;
  uchar *puVar14;
  uint uVar15;
  
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar11 = 0xc;
    uVar13 = 10;
  }
  else {
    iVar11 = 0;
    uVar13 = 0x20;
  }
  if (nmflag == 0) {
    iVar11 = 0x10;
  }
  pXVar12 = x->cert_info;
  if (-1 < (int)(cflag << 0x1f)) {
    iVar10 = BIO_write(bp,DAT_000b8adc,0xd);
    if (iVar10 < 1) {
      return 0;
    }
    iVar10 = BIO_write(bp,DAT_000b8ae0,10);
    if (iVar10 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1e)) {
    lVar2 = ASN1_INTEGER_get(x->cert_info->version);
    iVar10 = BIO_printf(bp,DAT_000b8ae4,DAT_000b8ae8,lVar2 + 1,lVar2);
    if (iVar10 < 1) {
      return 0;
    }
  }
  if ((cflag & 4) == 0) {
    uVar15 = cflag & 4;
    iVar10 = BIO_write(bp,DAT_000b8aec,0x16);
    if (iVar10 < 1) {
      return 0;
    }
    a = X509_get_serialNumber(x);
    if (a->length < 5) {
      iVar10 = ASN1_INTEGER_get(a);
      uVar8 = DAT_000b8c80;
      if (a->type == 0x102) {
        iVar10 = -iVar10;
        uVar8 = DAT_000b8c7c;
      }
      iVar10 = BIO_printf(bp,DAT_000b8c78,uVar8,iVar10,uVar8,iVar10);
      if (iVar10 < 1) {
        return 0;
      }
    }
    else {
      pcVar5 = DAT_000b8af4;
      uVar7 = DAT_000b8ae8;
      uVar9 = DAT_000b8af0;
      if (a->type != 0x102) {
        uVar9 = DAT_000b8ae8;
      }
      while( true ) {
        iVar10 = BIO_printf(bp,pcVar5,uVar7,uVar9);
        if (iVar10 < 1) {
          return 0;
        }
        if (a->length <= (int)uVar15) break;
        pbVar1 = a->data + uVar15;
        uVar15 = uVar15 + 1;
        pcVar5 = DAT_000b8af8;
        uVar7 = (uint)*pbVar1;
        if (a->length == uVar15) {
          uVar9 = 10;
        }
        else {
          uVar9 = 0x3a;
        }
      }
    }
  }
  if (((cflag & 8) == 0) &&
     (iVar10 = X509_signature_print(bp,pXVar12->signature,(ASN1_STRING *)0x0), iVar10 < 1)) {
    return 0;
  }
  if (-1 < (int)(cflag << 0x1b)) {
    iVar10 = BIO_printf(bp,DAT_000b8afc,uVar13);
    if (iVar10 < 1) {
      return 0;
    }
    pXVar4 = X509_get_issuer_name(x);
    iVar10 = X509_NAME_print_ex(bp,pXVar4,iVar11,nmflag);
    if (iVar10 < 0) {
      return 0;
    }
    iVar10 = BIO_write(bp,DAT_000b8b00,1);
    if (iVar10 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1a)) {
    iVar10 = BIO_write(bp,DAT_000b8b18,0x11);
    if (iVar10 < 1) {
      return 0;
    }
    iVar10 = BIO_write(bp,DAT_000b8b1c,0x18);
    if (iVar10 < 1) {
      return 0;
    }
    pAVar6 = x->cert_info->validity->notBefore;
    if (pAVar6->type == 0x17) {
      iVar10 = ASN1_UTCTIME_print(bp,pAVar6);
    }
    else {
      if (pAVar6->type != 0x18) goto LAB_000b8a24;
      iVar10 = ASN1_GENERALIZEDTIME_print(bp,pAVar6);
    }
    if (iVar10 == 0) {
      return 0;
    }
    iVar10 = BIO_write(bp,DAT_000b8b28,0x19);
    if (iVar10 < 1) {
      return 0;
    }
    pAVar6 = x->cert_info->validity->notAfter;
    if (pAVar6->type == 0x17) {
      iVar10 = ASN1_UTCTIME_print(bp,pAVar6);
    }
    else {
      if (pAVar6->type != 0x18) {
LAB_000b8a24:
        BIO_write(bp,DAT_000b8b20,0xe);
        return 0;
      }
      iVar10 = ASN1_GENERALIZEDTIME_print(bp,pAVar6);
    }
    if (iVar10 == 0) {
      return 0;
    }
    iVar10 = BIO_write(bp,DAT_000b8b00,1);
    if (iVar10 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x19)) {
    iVar10 = BIO_printf(bp,DAT_000b8b24,uVar13);
    if (iVar10 < 1) {
      return 0;
    }
    pXVar4 = X509_get_subject_name(x);
    iVar11 = X509_NAME_print_ex(bp,pXVar4,iVar11,nmflag);
    if (iVar11 < 0) {
      return 0;
    }
    iVar11 = BIO_write(bp,DAT_000b8b00,1);
    if (iVar11 < 1) {
      return 0;
    }
  }
  if ((cflag & 0x80) == 0) {
    iVar11 = BIO_write(bp,DAT_000b8b10,0x21);
    if (iVar11 < 1) {
      return 0;
    }
    iVar11 = BIO_printf(bp,DAT_000b8b14,DAT_000b8ae8);
    if (iVar11 < 1) {
      return 0;
    }
    iVar11 = i2a_ASN1_OBJECT(bp,pXVar12->key->algor->algorithm);
    if (iVar11 < 1) {
      return 0;
    }
    iVar11 = BIO_puts(bp,DAT_000b8b00);
    if (iVar11 < 1) {
      return 0;
    }
    pkey = X509_get_pubkey(x);
    if (pkey == (EVP_PKEY *)0x0) {
      BIO_printf(bp,DAT_000b8c98,DAT_000b8c80);
      ERR_print_errors(bp);
    }
    else {
      EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
      EVP_PKEY_free(pkey);
    }
  }
  if ((cflag & 0x1000) == 0) {
    if (pXVar12->issuerUID != (ASN1_BIT_STRING *)0x0) {
      iVar11 = BIO_printf(bp,DAT_000b8b04,DAT_000b8ae8);
      if (iVar11 < 1) {
        return 0;
      }
      iVar11 = pXVar12->issuerUID->length;
      puVar14 = pXVar12->issuerUID->data;
      if (0 < iVar11) {
        iVar10 = 0;
        while( true ) {
          if (iVar10 == (iVar10 / 0x12) * 0x12) {
            iVar3 = BIO_write(bp,DAT_000b8b00,1);
            if (iVar3 < 1) {
              return 0;
            }
            iVar3 = BIO_indent(bp,0xc,0xc);
            if (iVar3 < 1) {
              return 0;
            }
          }
          uVar15 = (uint)puVar14[iVar10];
          iVar10 = iVar10 + 1;
          if (iVar11 == iVar10) break;
          iVar3 = BIO_printf(bp,DAT_000b8b08,uVar15,DAT_000b8b0c);
          if (iVar3 < 1) {
            return 0;
          }
        }
        iVar11 = BIO_printf(bp,DAT_000b8c88,uVar15,DAT_000b8c80);
        if (iVar11 < 1) {
          return 0;
        }
      }
      iVar11 = BIO_write(bp,DAT_000b8c8c,1);
      if (iVar11 != 1) {
        return 0;
      }
    }
    if (pXVar12->subjectUID != (ASN1_BIT_STRING *)0x0) {
      iVar11 = BIO_printf(bp,DAT_000b8c90,DAT_000b8c80);
      if (iVar11 < 1) {
        return 0;
      }
      iVar11 = pXVar12->subjectUID->length;
      puVar14 = pXVar12->subjectUID->data;
      if (0 < iVar11) {
        iVar10 = 0;
        while( true ) {
          if (iVar10 == (iVar10 / 0x12) * 0x12) {
            iVar3 = BIO_write(bp,DAT_000b8c8c,1);
            if (iVar3 < 1) {
              return 0;
            }
            iVar3 = BIO_indent(bp,0xc,0xc);
            if (iVar3 < 1) {
              return 0;
            }
          }
          uVar15 = (uint)puVar14[iVar10];
          iVar10 = iVar10 + 1;
          if (iVar11 == iVar10) break;
          iVar3 = BIO_printf(bp,DAT_000b8c88,uVar15,DAT_000b8c94);
          if (iVar3 < 1) {
            return 0;
          }
        }
        iVar11 = BIO_printf(bp,DAT_000b8c88,uVar15,DAT_000b8c80);
        if (iVar11 < 1) {
          return 0;
        }
      }
      iVar11 = BIO_write(bp,DAT_000b8c8c,1);
      if (iVar11 != 1) {
        return 0;
      }
    }
  }
  if (-1 < (int)(cflag << 0x17)) {
    X509V3_extensions_print(bp,DAT_000b8c84,pXVar12->extensions,cflag,8);
  }
  if ((-1 < (int)(cflag << 0x16)) &&
     (iVar11 = X509_signature_print(bp,x->sig_alg,x->signature), iVar11 < 1)) {
    return 0;
  }
  if ((cflag & 0x400) != 0) {
    return 1;
  }
  iVar11 = X509_CERT_AUX_print(bp,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
  if (iVar11 != 0) {
    return 1;
  }
  return 0;
}

