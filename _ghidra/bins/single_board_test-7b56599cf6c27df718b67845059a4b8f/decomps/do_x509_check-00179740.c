
int * do_x509_check(X509 *param_1,char *param_2,size_t param_3,uint param_4,int param_5,int *param_6
                   )

{
  bool bVar1;
  GENERAL_NAMES *a;
  int iVar2;
  int *piVar3;
  X509_NAME *name;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *in;
  size_t sVar4;
  size_t *psVar5;
  void *__s1;
  int iVar6;
  int *piVar7;
  size_t sVar8;
  int iVar9;
  uint local_3c;
  code *local_34;
  uchar *local_2c [2];
  
  local_3c = param_4 & 0xffff7fff;
  if (param_5 == 1) {
    sVar8 = 0x16;
    iVar9 = 0x30;
    local_34 = (code *)0x179985;
  }
  else if (param_5 == 2) {
    if ((1 < param_3) && (*param_2 == '.')) {
      local_3c = local_3c | 0x8000;
    }
    if ((int)(local_3c << 0x1e) < 0) {
      sVar8 = 0x16;
      iVar9 = 0xd;
      local_34 = (code *)0x179451;
    }
    else {
      sVar8 = 0x16;
      iVar9 = 0xd;
      local_34 = (code *)0x179a61;
    }
  }
  else {
    sVar8 = 4;
    iVar9 = 0;
    local_34 = (code *)0x17954d;
  }
  if (param_3 == 0) {
    param_3 = strlen(param_2);
  }
  a = (GENERAL_NAMES *)X509_get_ext_d2i(param_1,0x55,(int *)0x0,(int *)0x0);
  if (a != (GENERAL_NAMES *)0x0) {
    bVar1 = false;
    for (iVar6 = 0; iVar2 = OPENSSL_sk_num(a), iVar6 < iVar2; iVar6 = iVar6 + 1) {
      piVar3 = (int *)OPENSSL_sk_value(a,iVar6);
      if (param_5 == *piVar3) {
        psVar5 = (size_t *)piVar3[1];
        __s1 = (void *)psVar5[2];
        if (((__s1 != (void *)0x0) && (sVar4 = *psVar5, sVar4 != 0)) && (sVar8 == psVar5[1])) {
          if (sVar8 == 0x16) {
            piVar7 = (int *)(*local_34)(__s1,sVar4,param_2,param_3,local_3c);
            piVar3 = param_6;
            if (param_6 != (int *)0x0) {
              piVar3 = piVar7;
            }
            if ((param_6 != (int *)0x0 && piVar7 != (int *)0x0) && -1 < (int)piVar3) {
              param_3 = *psVar5;
              __s1 = (void *)psVar5[2];
              goto LAB_001797f0;
            }
            if (piVar7 != (int *)0x0) goto LAB_0017980c;
          }
          else if ((sVar4 == param_3) && (iVar2 = memcmp(__s1,param_2,param_3), iVar2 == 0)) {
            piVar7 = (int *)0x1;
            if (param_6 == (int *)0x0) {
              piVar7 = (int *)0x1;
              goto LAB_0017980c;
            }
LAB_001797f0:
            iVar9 = CRYPTO_strndup(__s1,param_3,"crypto/x509v3/v3_utl.c",0x343);
            *param_6 = iVar9;
            if (iVar9 == 0) {
              piVar7 = (int *)0xffffffff;
            }
LAB_0017980c:
            GENERAL_NAMES_free(a);
            return piVar7;
          }
        }
        bVar1 = true;
      }
    }
    GENERAL_NAMES_free(a);
    if ((bVar1) && (-1 < (int)(local_3c << 0x1f))) {
      return (int *)0x0;
    }
  }
  if ((iVar9 != 0) && (-1 < (int)(local_3c << 0x1a))) {
    name = X509_get_subject_name(param_1);
    iVar6 = -1;
    while (iVar6 = X509_NAME_get_index_by_NID(name,iVar9,iVar6), -1 < iVar6) {
      ne = X509_NAME_get_entry(name,iVar6);
      in = X509_NAME_ENTRY_get_data(ne);
      if ((in->data != (uchar *)0x0) && (in->length != 0)) {
        iVar2 = ASN1_STRING_to_UTF8(local_2c,in);
        if (iVar2 < 0) {
          return (int *)0xffffffff;
        }
        piVar7 = (int *)(*local_34)(local_2c[0],iVar2,param_2,param_3,local_3c);
        piVar3 = param_6;
        if (param_6 != (int *)0x0) {
          piVar3 = piVar7;
        }
        if ((param_6 != (int *)0x0 && piVar7 != (int *)0x0) && -1 < (int)piVar3) {
          iVar9 = CRYPTO_strndup(local_2c[0],iVar2,"crypto/x509v3/v3_utl.c",0x354);
          *param_6 = iVar9;
          if (iVar9 == 0) {
            CRYPTO_free(local_2c[0]);
            return (int *)0xffffffff;
          }
          CRYPTO_free(local_2c[0]);
          return piVar7;
        }
        CRYPTO_free(local_2c[0]);
        if (piVar7 != (int *)0x0) {
          return piVar7;
        }
      }
    }
  }
  return (int *)0x0;
}

