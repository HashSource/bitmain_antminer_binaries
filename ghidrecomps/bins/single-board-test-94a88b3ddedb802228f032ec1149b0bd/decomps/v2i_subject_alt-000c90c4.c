
_STACK * v2i_subject_alt(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  int iVar1;
  CONF_VALUE *cnf;
  X509_NAME *pXVar2;
  int iVar3;
  X509_NAME_ENTRY *pXVar4;
  ASN1_STRING *pAVar5;
  GENERAL_NAME *pGVar6;
  int iVar7;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x9a,0x41,DAT_000c9314,0x13c);
  }
  else {
    for (iVar7 = 0; iVar1 = sk_num(param_3), iVar7 < iVar1; iVar7 = iVar7 + 1) {
      cnf = (CONF_VALUE *)sk_value(param_3,iVar7);
      iVar1 = name_cmp(cnf->name,DAT_000c9308);
      if (((iVar1 == 0) && (cnf->value != (char *)0x0)) &&
         (iVar1 = strcmp(cnf->value,DAT_000c9310), iVar1 == 0)) {
        if (param_2 == (X509V3_CTX *)0x0) {
LAB_000c92c0:
          pGVar6 = (GENERAL_NAME *)0x0;
          ERR_put_error(0x22,0x7a,0x7d,DAT_000c9314,0x164);
          pAVar5 = (ASN1_STRING *)0x0;
LAB_000c91be:
          GENERAL_NAME_free(pGVar6);
          ASN1_STRING_free(pAVar5);
LAB_000c91ca:
          sk_pop_free(st,DAT_000c9318);
          return (_STACK *)0x0;
        }
        if (param_2->flags != 1) {
          if (param_2->subject_cert == (X509 *)0x0) {
            if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_000c92c0;
            pXVar2 = param_2->subject_req->req_info->subject;
          }
          else {
            pXVar2 = X509_get_subject_name(param_2->subject_cert);
          }
          iVar1 = -1;
          while (iVar1 = X509_NAME_get_index_by_NID(pXVar2,0x30,iVar1), -1 < iVar1) {
            pXVar4 = X509_NAME_get_entry(pXVar2,iVar1);
            pAVar5 = X509_NAME_ENTRY_get_data(pXVar4);
            pAVar5 = ASN1_STRING_dup(pAVar5);
            if ((pAVar5 == (ASN1_STRING *)0x0) ||
               (pGVar6 = GENERAL_NAME_new(), pGVar6 == (GENERAL_NAME *)0x0)) {
              pGVar6 = (GENERAL_NAME *)0x0;
              ERR_put_error(0x22,0x7a,0x41,DAT_000c9314,0x179);
              goto LAB_000c91be;
            }
            pGVar6->type = 1;
            (pGVar6->d).otherName = (OTHERNAME *)pAVar5;
            iVar3 = sk_push(st,pGVar6);
            if (iVar3 == 0) {
              ERR_put_error(0x22,0x7a,0x41,DAT_000c9314,0x180);
              pAVar5 = (ASN1_STRING *)0x0;
              goto LAB_000c91be;
            }
          }
        }
      }
      else {
        iVar1 = name_cmp(cnf->name,DAT_000c9308);
        if (((iVar1 == 0) && (cnf->value != (char *)0x0)) &&
           (iVar1 = strcmp(cnf->value,DAT_000c930c), iVar1 == 0)) {
          if (param_2 == (X509V3_CTX *)0x0) {
LAB_000c92d8:
            pGVar6 = (GENERAL_NAME *)0x0;
            ERR_put_error(0x22,0x7a,0x7d,DAT_000c9314,0x164);
            pAVar5 = (ASN1_STRING *)0x0;
LAB_000c9272:
            GENERAL_NAME_free(pGVar6);
            ASN1_STRING_free(pAVar5);
            goto LAB_000c91ca;
          }
          if (param_2->flags != 1) {
            if (param_2->subject_cert == (X509 *)0x0) {
              if (param_2->subject_req == (X509_REQ *)0x0) goto LAB_000c92d8;
              pXVar2 = param_2->subject_req->req_info->subject;
            }
            else {
              pXVar2 = X509_get_subject_name(param_2->subject_cert);
            }
            iVar1 = -1;
            while( true ) {
              iVar3 = X509_NAME_get_index_by_NID(pXVar2,0x30,iVar1);
              iVar1 = iVar3 + -1;
              if (iVar3 < 0) break;
              pXVar4 = X509_NAME_get_entry(pXVar2,iVar3);
              pAVar5 = X509_NAME_ENTRY_get_data(pXVar4);
              pAVar5 = ASN1_STRING_dup(pAVar5);
              X509_NAME_delete_entry(pXVar2,iVar3);
              X509_NAME_ENTRY_free(pXVar4);
              if ((pAVar5 == (ASN1_STRING *)0x0) ||
                 (pGVar6 = GENERAL_NAME_new(), pGVar6 == (GENERAL_NAME *)0x0)) {
                pGVar6 = (GENERAL_NAME *)0x0;
                ERR_put_error(0x22,0x7a,0x41,DAT_000c9314,0x179);
                goto LAB_000c9272;
              }
              (pGVar6->d).otherName = (OTHERNAME *)pAVar5;
              pGVar6->type = 1;
              iVar3 = sk_push(st,pGVar6);
              if (iVar3 == 0) {
                ERR_put_error(0x22,0x7a,0x41,DAT_000c9314,0x180);
                pAVar5 = (ASN1_STRING *)0x0;
                goto LAB_000c9272;
              }
            }
          }
        }
        else {
          pGVar6 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)0x0,param_1,param_2,cnf,0);
          if (pGVar6 == (GENERAL_NAME *)0x0) goto LAB_000c91ca;
          sk_push(st,pGVar6);
        }
      }
    }
  }
  return st;
}

