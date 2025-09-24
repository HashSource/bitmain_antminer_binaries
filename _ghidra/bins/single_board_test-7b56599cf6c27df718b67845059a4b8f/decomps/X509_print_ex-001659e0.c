
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  byte *pbVar1;
  uint uVar2;
  ASN1_INTEGER *a;
  int iVar3;
  X509_ALGOR *alg;
  X509_PUBKEY *pub;
  EVP_PKEY *pkey;
  ASN1_TIME *pAVar4;
  int iVar5;
  X509_NAME *pXVar6;
  stack_st_X509_EXTENSION *exts;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  ASN1_STRING *local_30;
  ASN1_OBJECT *local_2c [2];
  
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar10 = 0xc;
    uVar9 = 10;
  }
  else {
    uVar9 = 0x20;
    if (nmflag == 0) {
      iVar10 = 0x10;
    }
    else {
      iVar10 = 0;
    }
  }
  if (((int)(cflag << 0x1f) < 0) ||
     ((iVar5 = BIO_write(bp,"Certificate:\n",0xd), 0 < iVar5 &&
      (iVar5 = BIO_write(bp,&DAT_0021f3e4,10), 0 < iVar5)))) {
    if (-1 < (int)(cflag << 0x1e)) {
      uVar2 = X509_get_version(x);
      if (uVar2 < 3) {
        iVar5 = BIO_printf(bp,"%8sVersion: %ld (0x%lx)\n","",uVar2 + 1,uVar2);
      }
      else {
        iVar5 = BIO_printf(bp,"%8sVersion: Unknown (%ld)\n","",uVar2);
      }
      if (iVar5 < 1) goto LAB_00165a84;
    }
    if ((int)(cflag << 0x1d) < 0) {
LAB_00165a14:
      if ((cflag & 8) == 0) {
        alg = (X509_ALGOR *)X509_get0_tbs_sigalg(x);
        iVar5 = BIO_puts(bp,"    ");
        if ((iVar5 < 1) || (iVar5 = X509_signature_print(bp,alg,(ASN1_STRING *)0x0), iVar5 < 1))
        goto LAB_00165a84;
      }
      if ((int)(cflag << 0x1b) < 0) {
LAB_00165a22:
        if ((int)(cflag << 0x1a) < 0) {
LAB_00165a28:
          if ((int)(cflag << 0x19) < 0) {
LAB_00165a2e:
            if ((cflag & 0x80) == 0) {
              pub = (X509_PUBKEY *)X509_get_X509_PUBKEY(x);
              X509_PUBKEY_get0_param(local_2c,(uchar **)0x0,(int *)0x0,(X509_ALGOR **)0x0,pub);
              iVar10 = BIO_write(bp,"        Subject Public Key Info:\n",0x21);
              if ((((iVar10 < 1) ||
                   (iVar10 = BIO_printf(bp,"%12sPublic Key Algorithm: ",""), iVar10 < 1)) ||
                  (iVar10 = i2a_ASN1_OBJECT(bp,local_2c[0]), iVar10 < 1)) ||
                 (iVar10 = BIO_puts(bp,"\n"), iVar10 < 1)) goto LAB_00165a84;
              pkey = (EVP_PKEY *)X509_get0_pubkey(x);
              if (pkey == (EVP_PKEY *)0x0) {
                BIO_printf(bp,"%12sUnable to load Public Key\n","");
                ERR_print_errors(bp);
              }
              else {
                EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
              }
            }
            if (((int)(cflag << 0x13) < 0) ||
               (((X509_get0_uids(x,&local_30,local_2c), local_30 == (ASN1_STRING *)0x0 ||
                 ((iVar10 = BIO_printf(bp,"%8sIssuer Unique ID: ",""), 0 < iVar10 &&
                  (iVar10 = X509_signature_dump(bp,local_30,0xc), iVar10 != 0)))) &&
                ((local_2c[0] == (ASN1_OBJECT *)0x0 ||
                 ((iVar10 = BIO_printf(bp,"%8sSubject Unique ID: ",""), 0 < iVar10 &&
                  (iVar10 = X509_signature_dump(bp,(ASN1_STRING *)local_2c[0],0xc), iVar10 != 0)))))
                ))) {
              if (-1 < (int)(cflag << 0x17)) {
                exts = (stack_st_X509_EXTENSION *)X509_get0_extensions(x);
                X509V3_extensions_print(bp,"X509v3 extensions",exts,cflag,8);
              }
              if ((cflag & 0x200) == 0) {
                X509_get0_signature(local_2c,&local_30,x);
                iVar10 = X509_signature_print(bp,(X509_ALGOR *)local_30,(ASN1_STRING *)local_2c[0]);
                if (iVar10 < 1) goto LAB_00165a84;
              }
              if ((cflag & 0x400) == 0) {
                iVar10 = X509_aux_print(bp,x);
                if (iVar10 != 0) {
                  iVar10 = 1;
                }
              }
              else {
                iVar10 = 1;
              }
              goto LAB_00165a86;
            }
          }
          else {
            iVar5 = BIO_printf(bp,"        Subject:%c",uVar9);
            if (0 < iVar5) {
              pXVar6 = X509_get_subject_name(x);
              iVar10 = X509_NAME_print_ex(bp,pXVar6,iVar10,nmflag);
              if ((-1 < iVar10) && (iVar10 = BIO_write(bp,"\n",1), 0 < iVar10)) goto LAB_00165a2e;
            }
          }
        }
        else {
          iVar5 = BIO_write(bp,"        Validity\n",0x11);
          if ((0 < iVar5) && (iVar5 = BIO_write(bp,"            Not Before: ",0x18), 0 < iVar5)) {
            pAVar4 = (ASN1_TIME *)X509_get0_notBefore(x);
            iVar5 = ASN1_TIME_print(bp,pAVar4);
            if ((iVar5 != 0) && (iVar5 = BIO_write(bp,"\n            Not After : ",0x19), 0 < iVar5)
               ) {
              pAVar4 = (ASN1_TIME *)X509_get0_notAfter(x);
              iVar5 = ASN1_TIME_print(bp,pAVar4);
              if ((iVar5 != 0) && (iVar5 = BIO_write(bp,"\n",1), 0 < iVar5)) goto LAB_00165a28;
            }
          }
        }
      }
      else {
        iVar5 = BIO_printf(bp,"        Issuer:%c",uVar9);
        if (0 < iVar5) {
          pXVar6 = X509_get_issuer_name(x);
          iVar5 = X509_NAME_print_ex(bp,pXVar6,iVar10,nmflag);
          if ((-1 < iVar5) && (iVar5 = BIO_write(bp,"\n",1), 0 < iVar5)) goto LAB_00165a22;
        }
      }
    }
    else {
      iVar5 = BIO_write(bp,"        Serial Number:",0x16);
      if (0 < iVar5) {
        a = X509_get_serialNumber(x);
        if (a->length < 5) {
          ERR_set_mark();
          iVar5 = ASN1_INTEGER_get(a);
          ERR_pop_to_mark();
          if (iVar5 != -1) {
            if (a->type == 0x102) {
              iVar5 = -iVar5;
              pcVar7 = "-";
            }
            else {
              pcVar7 = "";
            }
            iVar5 = BIO_printf(bp," %s%lu (%s0x%lx)\n",pcVar7,iVar5,pcVar7,iVar5);
            if (0 < iVar5) goto LAB_00165a14;
            goto LAB_00165a84;
          }
        }
        if (a->type == 0x102) {
          pcVar7 = " (Negative)";
        }
        else {
          pcVar7 = "";
        }
        iVar5 = BIO_printf(bp,"\n%12s%s","",pcVar7);
        if (0 < iVar5) {
          iVar5 = 0;
          do {
            if (a->length <= iVar5) goto LAB_00165a14;
            pbVar1 = a->data + iVar5;
            iVar5 = iVar5 + 1;
            if (a->length == iVar5) {
              uVar8 = 10;
            }
            else {
              uVar8 = 0x3a;
            }
            iVar3 = BIO_printf(bp,"%02x%c",(uint)*pbVar1,uVar8);
          } while (0 < iVar3);
        }
      }
    }
  }
LAB_00165a84:
  iVar10 = 0;
LAB_00165a86:
  CRYPTO_free((void *)0x0);
  return iVar10;
}

