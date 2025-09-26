
AUTHORITY_KEYID * v2i_AUTHORITY_KEYID(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  AUTHORITY_KEYID *pAVar3;
  X509_NAME *pXVar4;
  ASN1_INTEGER *pAVar5;
  GENERAL_NAMES *pGVar6;
  GENERAL_NAME *a;
  X509_EXTENSION *ext;
  ASN1_STRING *a_00;
  bool bVar7;
  bool bVar8;
  int iVar9;
  X509 *x;
  ASN1_STRING *pAVar10;
  int iVar11;
  char *__s1;
  
  iVar11 = 0;
  pAVar10 = (ASN1_STRING *)0x0;
  for (iVar9 = 0; iVar1 = OPENSSL_sk_num(param_3), iVar9 < iVar1; iVar9 = iVar9 + 1) {
    iVar1 = OPENSSL_sk_value(param_3,iVar9);
    __s1 = *(char **)(iVar1 + 4);
    iVar2 = strcmp(__s1,"keyid");
    if (iVar2 == 0) {
      if (*(char **)(iVar1 + 8) == (char *)0x0) {
        pAVar10 = (ASN1_STRING *)0x1;
      }
      else {
        iVar1 = strcmp(*(char **)(iVar1 + 8),"always");
        if (iVar1 == 0) {
          pAVar10 = (ASN1_STRING *)0x2;
        }
        else {
          pAVar10 = (ASN1_STRING *)0x1;
        }
      }
    }
    else {
      iVar11 = strcmp(__s1,"issuer");
      if (iVar11 != 0) {
        ERR_put_error(0x22,0x77,0x78,"crypto/x509v3/v3_akey.c",0x7a);
        ERR_add_error_data(2,"name=",*(undefined4 *)(iVar1 + 4));
        return (AUTHORITY_KEYID *)0x0;
      }
      if (*(char **)(iVar1 + 8) == (char *)0x0) {
        iVar11 = 1;
      }
      else {
        iVar11 = strcmp(*(char **)(iVar1 + 8),"always");
        if (iVar11 == 0) {
          iVar11 = 2;
        }
        else {
          iVar11 = 1;
        }
      }
    }
  }
  if (param_2 != (int *)0x0) {
    x = (X509 *)param_2[1];
    if (x != (X509 *)0x0) {
      bVar8 = true;
      a_00 = pAVar10;
      if (pAVar10 != (ASN1_STRING *)0x0) {
        iVar9 = X509_get_ext_by_NID(x,0x52,-1);
        if ((iVar9 < 0) || (ext = X509_get_ext(x,iVar9), ext == (X509_EXTENSION *)0x0)) {
          bVar8 = true;
          a_00 = (ASN1_STRING *)0x0;
        }
        else {
          a_00 = (ASN1_STRING *)X509V3_EXT_d2i(ext);
          bVar8 = a_00 == (ASN1_STRING *)0x0;
        }
        bVar7 = bVar8;
        if (pAVar10 != (ASN1_STRING *)0x2) {
          bVar7 = false;
        }
        if (bVar7) {
          ERR_put_error(0x22,0x77,0x7b,"crypto/x509v3/v3_akey.c",0x90);
          return (AUTHORITY_KEYID *)0x0;
        }
      }
      if (iVar11 == 0) {
        bVar8 = false;
      }
      if (iVar11 == 2) {
        bVar8 = true;
      }
      if (bVar8) {
        pXVar4 = X509_get_issuer_name(x);
        pXVar4 = X509_NAME_dup(pXVar4);
        pAVar5 = X509_get_serialNumber(x);
        pAVar5 = ASN1_INTEGER_dup(pAVar5);
        if (pAVar5 == (ASN1_STRING *)0x0 || pXVar4 == (X509_NAME *)0x0) {
          a = (GENERAL_NAME *)0x0;
          ERR_put_error(0x22,0x77,0x7a,"crypto/x509v3/v3_akey.c",0x9a);
          pGVar6 = (GENERAL_NAMES *)0x0;
        }
        else {
          pAVar3 = AUTHORITY_KEYID_new();
          if (pAVar3 == (AUTHORITY_KEYID *)0x0) {
            a = (GENERAL_NAME *)0x0;
            pGVar6 = (GENERAL_NAMES *)0x0;
          }
          else {
            pGVar6 = (GENERAL_NAMES *)OPENSSL_sk_new_null();
            if ((pGVar6 == (GENERAL_NAMES *)0x0) ||
               (a = GENERAL_NAME_new(), a == (GENERAL_NAME *)0x0)) {
              a = (GENERAL_NAME *)0x0;
            }
            else {
              iVar11 = OPENSSL_sk_push(pGVar6,a);
              if (iVar11 != 0) {
                a->type = 4;
                (a->d).directoryName = pXVar4;
                goto LAB_001d1356;
              }
            }
            ERR_put_error(0x22,0x77,0x41,"crypto/x509v3/v3_akey.c",0xa6);
          }
        }
      }
      else {
        pAVar3 = AUTHORITY_KEYID_new();
        pAVar5 = (ASN1_INTEGER *)0x0;
        pGVar6 = (GENERAL_NAMES *)0x0;
        if (pAVar3 != (AUTHORITY_KEYID *)0x0) {
LAB_001d1356:
          pAVar3->issuer = pGVar6;
          pAVar3->serial = pAVar5;
          pAVar3->keyid = a_00;
          return pAVar3;
        }
        pAVar5 = (ASN1_STRING *)0x0;
        a = (GENERAL_NAME *)0x0;
        pGVar6 = (GENERAL_NAMES *)0x0;
        pXVar4 = (X509_NAME *)0x0;
      }
      OPENSSL_sk_free(pGVar6);
      GENERAL_NAME_free(a);
      X509_NAME_free(pXVar4);
      ASN1_INTEGER_free(pAVar5);
      ASN1_OCTET_STRING_free(a_00);
      return (AUTHORITY_KEYID *)0x0;
    }
    if (*param_2 == 1) {
      pAVar3 = AUTHORITY_KEYID_new();
      return pAVar3;
    }
  }
  ERR_put_error(0x22,0x77,0x79,"crypto/x509v3/v3_akey.c",0x84);
  return (AUTHORITY_KEYID *)0x0;
}

