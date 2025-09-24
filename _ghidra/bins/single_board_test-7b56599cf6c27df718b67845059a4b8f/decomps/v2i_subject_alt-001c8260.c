
int v2i_subject_alt(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  GENERAL_NAME *pGVar3;
  CONF_VALUE *cnf;
  int iVar4;
  X509_NAME *pXVar5;
  X509_NAME_ENTRY *pXVar6;
  ASN1_STRING *pAVar7;
  ASN1_STRING *a;
  int iVar8;
  int iVar9;
  
  iVar1 = OPENSSL_sk_num(param_3);
  iVar2 = OPENSSL_sk_new_reserve(0,iVar1);
  if (iVar2 == 0) {
    ERR_put_error(0x22,0x9a,0x41,"crypto/x509v3/v3_alt.c",0x136);
    OPENSSL_sk_free(0);
    return 0;
  }
  if (iVar1 < 1) {
    return iVar2;
  }
  iVar9 = 0;
  while( true ) {
    cnf = (CONF_VALUE *)OPENSSL_sk_value(param_3,iVar9);
    iVar4 = name_cmp(cnf->name,"email");
    if (((iVar4 == 0) && (cnf->value != (char *)0x0)) &&
       (iVar4 = strcmp(cnf->value,"copy"), iVar4 == 0)) break;
    iVar4 = name_cmp(cnf->name,"email");
    if (((iVar4 == 0) && (cnf->value != (char *)0x0)) &&
       (iVar4 = strcmp(cnf->value,"move"), iVar4 == 0)) {
      if (param_2 == (X509V3_CTX *)0x0) goto LAB_001c8474;
      if (param_2->flags != 1) {
        if (param_2->subject_cert == (X509 *)0x0) {
          if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_001c8474;
          pXVar5 = (X509_NAME *)X509_REQ_get_subject_name();
        }
        else {
          pXVar5 = X509_get_subject_name(param_2->subject_cert);
        }
        iVar4 = -1;
        while( true ) {
          iVar8 = X509_NAME_get_index_by_NID(pXVar5,0x30,iVar4);
          iVar4 = iVar8 + -1;
          if (iVar8 < 0) break;
          pXVar6 = X509_NAME_get_entry(pXVar5,iVar8);
          pAVar7 = X509_NAME_ENTRY_get_data(pXVar6);
          pAVar7 = ASN1_STRING_dup(pAVar7);
          X509_NAME_delete_entry(pXVar5,iVar8);
          X509_NAME_ENTRY_free(pXVar6);
          if ((pAVar7 == (ASN1_STRING *)0x0) ||
             (a = (ASN1_STRING *)GENERAL_NAME_new(), a == (ASN1_STRING *)0x0)) goto LAB_001c83ee;
          ((_union_851 *)&a->type)->otherName = (OTHERNAME *)pAVar7;
          a->length = 1;
          iVar8 = OPENSSL_sk_push(iVar2,a);
          if (iVar8 == 0) goto LAB_001c8438;
        }
      }
    }
    else {
      pGVar3 = v2i_GENERAL_NAME(param_1,param_2,cnf);
      if (pGVar3 == (GENERAL_NAME *)0x0) goto LAB_001c8408;
      OPENSSL_sk_push(iVar2,pGVar3);
    }
LAB_001c82dc:
    iVar9 = iVar9 + 1;
    if (iVar1 == iVar9) {
      return iVar2;
    }
  }
  if (param_2 != (X509V3_CTX *)0x0) {
    if (param_2->flags != 1) {
      if (param_2->subject_cert == (X509 *)0x0) {
        if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_001c8474;
        pXVar5 = (X509_NAME *)X509_REQ_get_subject_name();
      }
      else {
        pXVar5 = X509_get_subject_name(param_2->subject_cert);
      }
      iVar4 = -1;
      while (iVar4 = X509_NAME_get_index_by_NID(pXVar5,0x30,iVar4), -1 < iVar4) {
        pXVar6 = X509_NAME_get_entry(pXVar5,iVar4);
        pAVar7 = X509_NAME_ENTRY_get_data(pXVar6);
        pAVar7 = ASN1_STRING_dup(pAVar7);
        if ((pAVar7 == (ASN1_STRING *)0x0) ||
           (a = (ASN1_STRING *)GENERAL_NAME_new(), a == (ASN1_STRING *)0x0)) goto LAB_001c83ee;
        ((_union_851 *)&a->type)->otherName = (OTHERNAME *)pAVar7;
        a->length = 1;
        iVar8 = OPENSSL_sk_push(iVar2,a);
        if (iVar8 == 0) goto LAB_001c8438;
      }
    }
    goto LAB_001c82dc;
  }
LAB_001c8474:
  pAVar7 = (ASN1_STRING *)0x0;
  ERR_put_error(0x22,0x7a,0x7d,"crypto/x509v3/v3_alt.c",0x162);
  a = pAVar7;
LAB_001c83fc:
  GENERAL_NAME_free((GENERAL_NAME *)a);
  ASN1_IA5STRING_free(pAVar7);
LAB_001c8408:
  OPENSSL_sk_pop_free(iVar2,(undefined *)0x17574d);
  return 0;
LAB_001c83ee:
  ERR_put_error(0x22,0x7a,0x41,"crypto/x509v3/v3_alt.c",0x176);
  a = (ASN1_STRING *)0x0;
  goto LAB_001c83fc;
LAB_001c8438:
  pAVar7 = (ASN1_STRING *)0x0;
  ERR_put_error(0x22,0x7a,0x41,"crypto/x509v3/v3_alt.c",0x17d);
  goto LAB_001c83fc;
}

