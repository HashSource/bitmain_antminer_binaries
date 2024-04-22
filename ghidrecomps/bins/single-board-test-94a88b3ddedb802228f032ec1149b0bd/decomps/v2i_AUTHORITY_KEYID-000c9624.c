
AUTHORITY_KEYID * v2i_AUTHORITY_KEYID(undefined4 param_1,int *param_2,_STACK *param_3)

{
  int iVar1;
  void *pvVar2;
  AUTHORITY_KEYID *pAVar3;
  X509_NAME *pXVar4;
  ASN1_INTEGER *pAVar5;
  _STACK *st;
  GENERAL_NAME *data;
  X509_EXTENSION *ext;
  ASN1_STRING *a;
  uint uVar6;
  uint uVar7;
  int iVar8;
  X509 *x;
  char *__s1;
  ASN1_STRING *pAVar9;
  int iVar10;
  
  iVar10 = 0;
  pAVar9 = (ASN1_STRING *)0x0;
  for (iVar8 = 0; iVar1 = sk_num(param_3), iVar8 < iVar1; iVar8 = iVar8 + 1) {
    pvVar2 = sk_value(param_3,iVar8);
    __s1 = *(char **)((int)pvVar2 + 4);
    iVar1 = strcmp(__s1,DAT_000c9818);
    if (iVar1 == 0) {
      pAVar9 = (ASN1_STRING *)0x1;
      if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
        iVar1 = strcmp(*(char **)((int)pvVar2 + 8),DAT_000c9814);
        if (iVar1 == 0) {
          pAVar9 = (ASN1_STRING *)0x2;
        }
        else {
          pAVar9 = (ASN1_STRING *)0x1;
        }
      }
    }
    else {
      iVar10 = strcmp(__s1,DAT_000c981c);
      if (iVar10 != 0) {
        ERR_put_error(0x22,0x77,0x78,DAT_000c9820,0x8f);
        ERR_add_error_data(2,DAT_000c9824,*(undefined4 *)((int)pvVar2 + 4));
        return (AUTHORITY_KEYID *)0x0;
      }
      iVar10 = 1;
      if (*(char **)((int)pvVar2 + 8) != (char *)0x0) {
        iVar10 = strcmp(*(char **)((int)pvVar2 + 8),DAT_000c9814);
        if (iVar10 == 0) {
          iVar10 = 2;
        }
        else {
          iVar10 = 1;
        }
      }
    }
  }
  if (param_2 != (int *)0x0) {
    x = (X509 *)param_2[1];
    if (x != (X509 *)0x0) {
      uVar7 = 1;
      a = pAVar9;
      if (pAVar9 != (ASN1_STRING *)0x0) {
        iVar8 = X509_get_ext_by_NID(x,0x52,-1);
        if ((iVar8 < 0) || (ext = X509_get_ext(x,iVar8), ext == (X509_EXTENSION *)0x0)) {
          uVar7 = 1;
          a = (ASN1_STRING *)0x0;
        }
        else {
          a = (ASN1_STRING *)X509V3_EXT_d2i(ext);
          uVar7 = 1 - (int)a;
          if ((ASN1_STRING *)0x1 < a) {
            uVar7 = 0;
          }
        }
        if (pAVar9 == (ASN1_STRING *)0x2) {
          uVar6 = uVar7 & 1;
        }
        else {
          uVar6 = 0;
        }
        if (uVar6 != 0) {
          ERR_put_error(0x22,0x77,0x7b,DAT_000c9820,0xa5);
          return (AUTHORITY_KEYID *)0x0;
        }
      }
      if (iVar10 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = uVar7 & 1;
      }
      if ((uVar7 == 0) && (iVar10 != 2)) {
        pAVar3 = AUTHORITY_KEYID_new();
        if (pAVar3 != (AUTHORITY_KEYID *)0x0) {
          st = (_STACK *)0x0;
          pAVar5 = (ASN1_INTEGER *)0x0;
LAB_000c9754:
          pAVar3->issuer = (GENERAL_NAMES *)st;
          pAVar3->serial = pAVar5;
          pAVar3->keyid = a;
          return pAVar3;
        }
        pAVar5 = (ASN1_STRING *)0x0;
        pXVar4 = (X509_NAME *)0x0;
      }
      else {
        pXVar4 = X509_get_issuer_name(x);
        pXVar4 = X509_NAME_dup(pXVar4);
        pAVar5 = X509_get_serialNumber(x);
        pAVar5 = ASN1_STRING_dup(pAVar5);
        if (pXVar4 == (X509_NAME *)0x0 || pAVar5 == (ASN1_STRING *)0x0) {
          ERR_put_error(0x22,0x77,0x7a,DAT_000c9820,0xaf);
        }
        else {
          pAVar3 = AUTHORITY_KEYID_new();
          if (pAVar3 != (AUTHORITY_KEYID *)0x0) {
            st = sk_new_null();
            if (((st != (_STACK *)0x0) && (data = GENERAL_NAME_new(), data != (GENERAL_NAME *)0x0))
               && (iVar10 = sk_push(st,data), iVar10 != 0)) {
              data->type = 4;
              (data->d).directoryName = pXVar4;
              goto LAB_000c9754;
            }
            ERR_put_error(0x22,0x77,0x41,DAT_000c9820,0xbb);
          }
        }
      }
      X509_NAME_free(pXVar4);
      ASN1_STRING_free(pAVar5);
      ASN1_STRING_free(a);
      return (AUTHORITY_KEYID *)0x0;
    }
    if (*param_2 == 1) {
      pAVar3 = AUTHORITY_KEYID_new();
      return pAVar3;
    }
  }
  ERR_put_error(0x22,0x77,0x79,DAT_000c9820,0x99);
  return (AUTHORITY_KEYID *)0x0;
}

