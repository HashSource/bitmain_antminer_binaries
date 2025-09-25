
int PKCS12_parse(PKCS12 *p12,char *pass,EVP_PKEY **pkey,X509 **cert,stack_st_X509 **ca)

{
  int iVar1;
  stack_st_PKCS7 *psVar2;
  int iVar3;
  PKCS7 *p7;
  stack_st_PKCS12_SAFEBAG *psVar4;
  stack_st_X509 *psVar5;
  int iVar6;
  X509 *x509;
  stack_st_X509 **ppsVar7;
  
  if (pkey != (EVP_PKEY **)0x0) {
    *pkey = (EVP_PKEY *)0x0;
  }
  if (cert != (X509 **)0x0) {
    *cert = (X509 *)0x0;
  }
  if (p12 == (PKCS12 *)0x0) {
    ERR_put_error(0x23,0x76,0x69,"crypto/pkcs12/p12_kiss.c",0x2f);
    return 0;
  }
  if ((pass == (char *)0x0) || (*pass == '\0')) {
    iVar1 = PKCS12_verify_mac(p12,(char *)0x0,0);
    pass = (char *)0x0;
    if (iVar1 == 0) {
      pass = "";
      iVar1 = PKCS12_verify_mac(p12,"",0);
      if (iVar1 == 0) {
        ERR_put_error(0x23,0x76,0x71,"crypto/pkcs12/p12_kiss.c",0x42);
        x509 = (X509 *)0x0;
        iVar1 = 0;
        goto LAB_001d11d6;
      }
    }
  }
  else {
    iVar1 = PKCS12_verify_mac(p12,pass,-1);
    if (iVar1 == 0) {
      ERR_put_error(0x23,0x76,0x71,"crypto/pkcs12/p12_kiss.c",0x46);
      x509 = (X509 *)0x0;
      iVar1 = 0;
      goto LAB_001d11d6;
    }
  }
  iVar1 = OPENSSL_sk_new_null();
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x76,0x41,"crypto/pkcs12/p12_kiss.c",0x4e);
    x509 = (X509 *)0x0;
  }
  else {
    psVar2 = PKCS12_unpack_authsafes(p12);
    if (psVar2 != (stack_st_PKCS7 *)0x0) {
      for (iVar6 = 0; iVar3 = OPENSSL_sk_num(psVar2), iVar6 < iVar3; iVar6 = iVar6 + 1) {
        p7 = (PKCS7 *)OPENSSL_sk_value(psVar2,iVar6);
        iVar3 = OBJ_obj2nid(p7->type);
        if (iVar3 == 0x15) {
          psVar4 = PKCS12_unpack_p7data(p7);
joined_r0x001d11b2:
          if (psVar4 == (stack_st_PKCS12_SAFEBAG *)0x0) {
            OPENSSL_sk_pop_free(psVar2,0x143001,pkey);
            goto LAB_001d11c2;
          }
          iVar3 = parse_bags_constprop_1(psVar4,pass,pkey,iVar1);
          if (iVar3 == 0) {
            OPENSSL_sk_pop_free(psVar4,0x1d0f8d);
            OPENSSL_sk_pop_free(psVar2,0x143001);
            goto LAB_001d11c2;
          }
          OPENSSL_sk_pop_free(psVar4,0x1d0f8d);
        }
        else if (iVar3 == 0x1a) {
          psVar4 = PKCS12_unpack_p7encdata(p7,pass,-1);
          goto joined_r0x001d11b2;
        }
      }
      OPENSSL_sk_pop_free(psVar2,0x143001);
      x509 = (X509 *)OPENSSL_sk_pop(iVar1);
      do {
        if (x509 == (X509 *)0x0) {
          OPENSSL_sk_pop_free(iVar1,(undefined *)0x16a341);
          return 1;
        }
        ppsVar7 = ca;
        if (((pkey == (EVP_PKEY **)0x0) || (*pkey == (EVP_PKEY *)0x0 || cert == (X509 **)0x0)) ||
           (*cert != (X509 *)0x0)) {
          if (ca != (stack_st_X509 **)0x0) {
            ppsVar7 = (stack_st_X509 **)0x1;
          }
        }
        else {
          ERR_set_mark();
          iVar6 = X509_check_private_key(x509,*pkey);
          if (iVar6 == 0) {
            if (ca != (stack_st_X509 **)0x0) {
              ppsVar7 = (stack_st_X509 **)0x1;
            }
          }
          else {
            *cert = x509;
            x509 = (X509 *)0x0;
            ppsVar7 = (stack_st_X509 **)0x0;
          }
          ERR_pop_to_mark();
        }
        if (ppsVar7 != (stack_st_X509 **)0x0) {
          psVar5 = *ca;
          if (psVar5 == (stack_st_X509 *)0x0) {
            psVar5 = (stack_st_X509 *)OPENSSL_sk_new_null();
            *ca = psVar5;
            if (psVar5 == (stack_st_X509 *)0x0) goto LAB_001d11d6;
          }
          iVar6 = OPENSSL_sk_push(psVar5,x509);
          if (iVar6 == 0) goto LAB_001d11d6;
          x509 = (X509 *)0x0;
        }
        X509_free(x509);
        x509 = (X509 *)OPENSSL_sk_pop(iVar1);
      } while( true );
    }
LAB_001d11c2:
    x509 = (X509 *)0x0;
    ERR_put_error(0x23,0x76,0x72,"crypto/pkcs12/p12_kiss.c",0x53);
  }
LAB_001d11d6:
  if (pkey != (EVP_PKEY **)0x0) {
    EVP_PKEY_free(*pkey);
    *pkey = (EVP_PKEY *)0x0;
  }
  if (cert != (X509 **)0x0) {
    X509_free(*cert);
    *cert = (X509 *)0x0;
  }
  X509_free(x509);
  OPENSSL_sk_pop_free(iVar1,(undefined *)0x16a341);
  return 0;
}

