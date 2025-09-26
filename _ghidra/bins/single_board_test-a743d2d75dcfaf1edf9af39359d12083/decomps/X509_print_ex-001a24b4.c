
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  long lVar1;
  ASN1_INTEGER *a;
  int iVar2;
  EVP_PKEY *pkey;
  X509_NAME *pXVar3;
  char *pcVar4;
  ASN1_UTCTIME *pAVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  X509_CINF *pXVar10;
  undefined4 uVar11;
  uchar *puVar12;
  uint uVar13;
  
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar9 = 0xc;
    uVar11 = 10;
  }
  else {
    iVar9 = 0;
    uVar11 = 0x20;
  }
  if (nmflag == 0) {
    iVar9 = 0x10;
  }
  pXVar10 = x->cert_info;
  if (-1 < (int)(cflag << 0x1f)) {
    iVar8 = BIO_write(bp,"Certificate:\n",0xd);
    if (iVar8 < 1) {
      return 0;
    }
    iVar8 = BIO_write(bp,"    Data:\n",10);
    if (iVar8 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1e)) {
    lVar1 = ASN1_INTEGER_get(x->cert_info->version);
    iVar8 = BIO_printf(bp,"%8sVersion: %lu (0x%lx)\n","",lVar1 + 1,lVar1);
    if (iVar8 < 1) {
      return 0;
    }
  }
  if ((cflag & 4) == 0) {
    uVar13 = cflag & 4;
    iVar8 = BIO_write(bp,"        Serial Number:",0x16);
    if (iVar8 < 1) {
      return 0;
    }
    a = X509_get_serialNumber(x);
    if (a->length < 5) {
      iVar8 = ASN1_INTEGER_get(a);
      if (a->type == 0x102) {
        pcVar4 = "-";
        iVar8 = -iVar8;
      }
      else {
        pcVar4 = "";
      }
      iVar8 = BIO_printf(bp," %s%lu (%s0x%lx)\n",pcVar4,iVar8,pcVar4,iVar8);
      if (iVar8 < 1) {
        return 0;
      }
    }
    else {
      pcVar6 = "";
      pcVar7 = " (Negative)";
      pcVar4 = "\n%12s%s";
      if (a->type != 0x102) {
        pcVar7 = "";
      }
      while( true ) {
        iVar8 = BIO_printf(bp,pcVar4,pcVar6,pcVar7);
        if (iVar8 < 1) {
          return 0;
        }
        pcVar4 = "%02x%c";
        if (a->length <= (int)uVar13) break;
        pcVar6 = (char *)(uint)a->data[uVar13];
        uVar13 = uVar13 + 1;
        if (a->length == uVar13) {
          pcVar7 = (char *)0xa;
        }
        else {
          pcVar7 = (char *)0x3a;
        }
      }
    }
  }
  if (((cflag & 8) == 0) &&
     (iVar8 = X509_signature_print(bp,pXVar10->signature,(ASN1_STRING *)0x0), iVar8 < 1)) {
    return 0;
  }
  if (-1 < (int)(cflag << 0x1b)) {
    iVar8 = BIO_printf(bp,"        Issuer:%c",uVar11);
    if (iVar8 < 1) {
      return 0;
    }
    pXVar3 = X509_get_issuer_name(x);
    iVar8 = X509_NAME_print_ex(bp,pXVar3,iVar9,nmflag);
    if (iVar8 < 0) {
      return 0;
    }
    iVar8 = BIO_write(bp,"\n",1);
    if (iVar8 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1a)) {
    iVar8 = BIO_write(bp,"        Validity\n",0x11);
    if (iVar8 < 1) {
      return 0;
    }
    iVar8 = BIO_write(bp,"            Not Before: ",0x18);
    if (iVar8 < 1) {
      return 0;
    }
    pAVar5 = x->cert_info->validity->notBefore;
    if (pAVar5->type == 0x17) {
      iVar8 = ASN1_UTCTIME_print(bp,pAVar5);
    }
    else {
      if (pAVar5->type != 0x18) goto LAB_001a273c;
      iVar8 = ASN1_GENERALIZEDTIME_print(bp,pAVar5);
    }
    if (iVar8 == 0) {
      return 0;
    }
    iVar8 = BIO_write(bp,"\n            Not After : ",0x19);
    if (iVar8 < 1) {
      return 0;
    }
    pAVar5 = x->cert_info->validity->notAfter;
    if (pAVar5->type == 0x17) {
      iVar8 = ASN1_UTCTIME_print(bp,pAVar5);
    }
    else {
      if (pAVar5->type != 0x18) {
LAB_001a273c:
        BIO_write(bp,"Bad time value",0xe);
        return 0;
      }
      iVar8 = ASN1_GENERALIZEDTIME_print(bp,pAVar5);
    }
    if (iVar8 == 0) {
      return 0;
    }
    iVar8 = BIO_write(bp,"\n",1);
    if (iVar8 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x19)) {
    iVar8 = BIO_printf(bp,"        Subject:%c",uVar11);
    if (iVar8 < 1) {
      return 0;
    }
    pXVar3 = X509_get_subject_name(x);
    iVar9 = X509_NAME_print_ex(bp,pXVar3,iVar9,nmflag);
    if (iVar9 < 0) {
      return 0;
    }
    iVar9 = BIO_write(bp,"\n",1);
    if (iVar9 < 1) {
      return 0;
    }
  }
  if ((cflag & 0x80) == 0) {
    iVar9 = BIO_write(bp,"        Subject Public Key Info:\n",0x21);
    if (iVar9 < 1) {
      return 0;
    }
    iVar9 = BIO_printf(bp,"%12sPublic Key Algorithm: ","");
    if (iVar9 < 1) {
      return 0;
    }
    iVar9 = i2a_ASN1_OBJECT(bp,pXVar10->key->algor->algorithm);
    if (iVar9 < 1) {
      return 0;
    }
    iVar9 = BIO_puts(bp,"\n");
    if (iVar9 < 1) {
      return 0;
    }
    pkey = X509_get_pubkey(x);
    if (pkey == (EVP_PKEY *)0x0) {
      BIO_printf(bp,"%12sUnable to load Public Key\n","");
      ERR_print_errors(bp);
    }
    else {
      EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
      EVP_PKEY_free(pkey);
    }
  }
  if ((cflag & 0x1000) == 0) {
    if (pXVar10->issuerUID != (ASN1_BIT_STRING *)0x0) {
      iVar9 = BIO_printf(bp,"%8sIssuer Unique ID: ","");
      if (iVar9 < 1) {
        return 0;
      }
      iVar9 = pXVar10->issuerUID->length;
      puVar12 = pXVar10->issuerUID->data;
      if (0 < iVar9) {
        iVar8 = 0;
        while( true ) {
          if (iVar8 == (iVar8 / 0x12) * 0x12) {
            iVar2 = BIO_write(bp,"\n",1);
            if (iVar2 < 1) {
              return 0;
            }
            iVar2 = BIO_indent(bp,0xc,0xc);
            if (iVar2 < 1) {
              return 0;
            }
          }
          uVar13 = (uint)puVar12[iVar8];
          iVar8 = iVar8 + 1;
          if (iVar9 == iVar8) break;
          iVar2 = BIO_printf(bp,"%02x%s",uVar13,":");
          if (iVar2 < 1) {
            return 0;
          }
        }
        iVar9 = BIO_printf(bp,"%02x%s",uVar13,"");
        if (iVar9 < 1) {
          return 0;
        }
      }
      iVar9 = BIO_write(bp,"\n",1);
      if (iVar9 != 1) {
        return 0;
      }
    }
    if (pXVar10->subjectUID != (ASN1_BIT_STRING *)0x0) {
      iVar9 = BIO_printf(bp,"%8sSubject Unique ID: ","");
      if (iVar9 < 1) {
        return 0;
      }
      iVar9 = pXVar10->subjectUID->length;
      puVar12 = pXVar10->subjectUID->data;
      if (0 < iVar9) {
        iVar8 = 0;
        while( true ) {
          if (iVar8 == (iVar8 / 0x12) * 0x12) {
            iVar2 = BIO_write(bp,"\n",1);
            if (iVar2 < 1) {
              return 0;
            }
            iVar2 = BIO_indent(bp,0xc,0xc);
            if (iVar2 < 1) {
              return 0;
            }
          }
          uVar13 = (uint)puVar12[iVar8];
          iVar8 = iVar8 + 1;
          if (iVar9 == iVar8) break;
          iVar2 = BIO_printf(bp,"%02x%s",uVar13,":");
          if (iVar2 < 1) {
            return 0;
          }
        }
        iVar9 = BIO_printf(bp,"%02x%s",uVar13,"");
        if (iVar9 < 1) {
          return 0;
        }
      }
      iVar9 = BIO_write(bp,"\n",1);
      if (iVar9 != 1) {
        return 0;
      }
    }
  }
  if (-1 < (int)(cflag << 0x17)) {
    X509V3_extensions_print(bp,"X509v3 extensions",pXVar10->extensions,cflag,8);
  }
  if ((-1 < (int)(cflag << 0x16)) &&
     (iVar9 = X509_signature_print(bp,x->sig_alg,x->signature), iVar9 < 1)) {
    return 0;
  }
  if ((cflag & 0x400) != 0) {
    return 1;
  }
  iVar9 = X509_CERT_AUX_print(bp,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
  if (iVar9 != 0) {
    return 1;
  }
  return 0;
}

