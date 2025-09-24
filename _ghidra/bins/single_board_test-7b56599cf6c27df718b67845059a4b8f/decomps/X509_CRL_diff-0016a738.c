
X509_CRL * X509_CRL_diff(X509_CRL *param_1,X509_CRL *param_2,EVP_PKEY *param_3,EVP_MD *param_4)

{
  X509_NAME *pXVar1;
  X509_NAME *b;
  int iVar2;
  X509_CRL *x;
  undefined4 uVar3;
  int iVar4;
  X509_EXTENSION *ex;
  ASN1_INTEGER *serial;
  int iVar5;
  X509_REVOKED *local_2c [2];
  
  if ((param_1[1].akid == (AUTHORITY_KEYID *)0x0) && (param_2[1].akid == (AUTHORITY_KEYID *)0x0)) {
    if ((param_1[1].flags == 0) || (param_2[1].flags == 0)) {
      ERR_put_error(0xb,0x69,0x82,"crypto/x509/x509_vfy.c",0x7ce);
    }
    else {
      pXVar1 = (X509_NAME *)X509_CRL_get_issuer();
      b = (X509_NAME *)X509_CRL_get_issuer(param_2);
      iVar2 = X509_NAME_cmp(pXVar1,b);
      if (iVar2 == 0) {
        iVar2 = crl_extension_match(param_1,param_2,0x5a);
        if (iVar2 == 0) {
          ERR_put_error(0xb,0x69,0x6e,"crypto/x509/x509_vfy.c",0x7d8);
        }
        else {
          iVar2 = crl_extension_match(param_1,param_2,0x302);
          if (iVar2 == 0) {
            ERR_put_error(0xb,0x69,0x80,"crypto/x509/x509_vfy.c",0x7dc);
          }
          else {
            iVar2 = ASN1_INTEGER_cmp((ASN1_INTEGER *)param_2[1].flags,
                                     (ASN1_INTEGER *)param_1[1].flags);
            if (iVar2 < 1) {
              ERR_put_error(0xb,0x69,0x84,"crypto/x509/x509_vfy.c",0x7e1);
            }
            else {
              if ((param_3 == (EVP_PKEY *)0x0) ||
                 ((iVar2 = X509_CRL_verify(param_1,param_3), 0 < iVar2 &&
                  (iVar2 = X509_CRL_verify(param_2,param_3), 0 < iVar2)))) {
                x = X509_CRL_new();
                if ((x != (X509_CRL *)0x0) && (iVar2 = X509_CRL_set_version(x,1), iVar2 != 0)) {
                  pXVar1 = (X509_NAME *)X509_CRL_get_issuer(param_2);
                  iVar2 = X509_CRL_set_issuer_name(x,pXVar1);
                  if (iVar2 != 0) {
                    uVar3 = X509_CRL_get0_lastUpdate(param_2);
                    iVar2 = X509_CRL_set1_lastUpdate(x,uVar3);
                    if (iVar2 != 0) {
                      uVar3 = X509_CRL_get0_nextUpdate(param_2);
                      iVar2 = X509_CRL_set1_nextUpdate(x,uVar3);
                      if (iVar2 != 0) {
                        iVar4 = X509_CRL_add1_ext_i2d(x,0x8c,(void *)param_1[1].flags,1,0);
                        iVar2 = 0;
                        while (iVar4 != 0) {
                          iVar4 = X509_CRL_get_ext_count(param_2);
                          if (iVar4 <= iVar2) {
                            uVar3 = X509_CRL_get_REVOKED();
                            iVar2 = 0;
                            goto LAB_0016a866;
                          }
                          ex = X509_CRL_get_ext(param_2,iVar2);
                          iVar4 = X509_CRL_add_ext(x,ex,-1);
                          iVar2 = iVar2 + 1;
                        }
                      }
                    }
                  }
                }
                goto LAB_0016a8aa;
              }
              ERR_put_error(0xb,0x69,0x83,"crypto/x509/x509_vfy.c",0x7e7);
            }
          }
        }
      }
      else {
        ERR_put_error(0xb,0x69,0x81,"crypto/x509/x509_vfy.c",0x7d3);
      }
    }
  }
  else {
    ERR_put_error(0xb,0x69,0x7f,"crypto/x509/x509_vfy.c",0x7c9);
  }
  return (X509_CRL *)0x0;
  while( true ) {
    local_2c[0] = (X509_REVOKED *)X509_REVOKED_dup(serial);
    if (local_2c[0] == (X509_REVOKED *)0x0) goto LAB_0016a8aa;
    iVar4 = X509_CRL_add0_revoked(x,local_2c[0]);
    if (iVar4 == 0) break;
LAB_0016a866:
    do {
      iVar4 = OPENSSL_sk_num(uVar3);
      iVar5 = iVar2 + 1;
      if (iVar4 <= iVar2) {
        if (param_3 == (EVP_PKEY *)0x0 || param_4 == (EVP_MD *)0x0) {
          return x;
        }
        iVar2 = X509_CRL_sign(x,param_3,param_4);
        if (iVar2 != 0) {
          return x;
        }
        goto LAB_0016a8aa;
      }
      serial = (ASN1_INTEGER *)OPENSSL_sk_value(uVar3,iVar2);
      iVar4 = X509_CRL_get0_by_serial(param_1,local_2c,serial);
      iVar2 = iVar5;
    } while (iVar4 != 0);
  }
  X509_REVOKED_free(local_2c[0]);
LAB_0016a8aa:
  ERR_put_error(0xb,0x69,0x41,"crypto/x509/x509_vfy.c",0x825);
  X509_CRL_free(x);
  return (X509_CRL *)0x0;
}

