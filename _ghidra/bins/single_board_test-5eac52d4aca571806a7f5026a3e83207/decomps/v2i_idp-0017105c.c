
ISSUING_DIST_POINT * v2i_idp(undefined4 param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  GENERAL_NAMES *pGVar1;
  ISSUING_DIST_POINT *a;
  int iVar2;
  CONF_VALUE *value;
  stack_st_CONF_VALUE *psVar3;
  GENERAL_NAMES *pGVar4;
  DIST_POINT_NAME *pDVar5;
  X509_NAME *nm;
  char *line;
  int iVar6;
  char *__s1;
  GENERAL_NAMES *pGVar7;
  
  a = ISSUING_DIST_POINT_new();
  if (a == (ISSUING_DIST_POINT *)0x0) {
    ERR_put_error(0x22,0x9d,0x41,"crypto/x509v3/v3_crld.c",0x193);
  }
  else {
    iVar6 = 0;
    while( true ) {
      iVar2 = OPENSSL_sk_num(param_3);
      if (iVar2 <= iVar6) {
        return a;
      }
      value = (CONF_VALUE *)OPENSSL_sk_value(param_3,iVar6);
      __s1 = value->name;
      line = value->value;
      iVar2 = strcmp(__s1,"fullname");
      if (iVar2 == 0) break;
      iVar2 = strcmp(__s1,"relativename");
      if (iVar2 == 0) {
        nm = X509_NAME_new();
        if (nm != (X509_NAME *)0x0) {
          psVar3 = X509V3_get_section(param_2,value->value);
          if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
            iVar2 = X509V3_NAME_from_section(nm,psVar3,0x1001);
            X509V3_section_free(param_2,psVar3);
            pGVar7 = (GENERAL_NAMES *)nm->entries;
            nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
            X509_NAME_free(nm);
            if (iVar2 == 0) {
              pGVar4 = (GENERAL_NAMES *)0x0;
            }
            else {
              iVar2 = OPENSSL_sk_num(pGVar7);
              pGVar4 = (GENERAL_NAMES *)0x0;
              if (0 < iVar2) {
                iVar2 = OPENSSL_sk_num(pGVar7);
                iVar2 = OPENSSL_sk_value(pGVar7,iVar2 + -1);
                pGVar1 = *(GENERAL_NAMES **)(iVar2 + 8);
                if (*(GENERAL_NAMES **)(iVar2 + 8) == (GENERAL_NAMES *)0x0) goto LAB_00171164;
                ERR_put_error(0x22,0x9e,0xa1,"crypto/x509v3/v3_crld.c",0x66);
              }
            }
            goto LAB_00171214;
          }
          ERR_put_error(0x22,0x9e,0x96,"crypto/x509v3/v3_crld.c",0x56);
        }
        goto LAB_0017122c;
      }
      iVar2 = strcmp(__s1,"onlyuser");
      if (iVar2 == 0) {
        iVar2 = X509V3_get_value_bool(value,&a->onlyuser);
      }
      else {
        iVar2 = strcmp(__s1,"onlyCA");
        if (iVar2 == 0) {
          iVar2 = X509V3_get_value_bool(value,&a->onlyCA);
        }
        else {
          iVar2 = strcmp(__s1,"onlyAA");
          if (iVar2 == 0) {
            iVar2 = X509V3_get_value_bool(value,&a->onlyattr);
          }
          else {
            iVar2 = strcmp(__s1,"indirectCRL");
            if (iVar2 == 0) {
              iVar2 = X509V3_get_value_bool(value,&a->indirectCRL);
            }
            else {
              iVar2 = strcmp(__s1,"onlysomereasons");
              if (iVar2 != 0) {
                ERR_put_error(0x22,0x9d,0x6a,"crypto/x509v3/v3_crld.c",0x18b);
                ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",
                                   value->value);
                goto LAB_0017122c;
              }
              iVar2 = set_reasons(&a->onlysomereasons,line);
            }
          }
        }
      }
      if (iVar2 == 0) goto LAB_0017122c;
LAB_001710fe:
      iVar6 = iVar6 + 1;
    }
    if (*line == '@') {
      psVar3 = X509V3_get_section(param_2,line + 1);
    }
    else {
      psVar3 = X509V3_parse_list(line);
    }
    if (psVar3 == (stack_st_CONF_VALUE *)0x0) {
      ERR_put_error(0x22,0x9c,0x96,"crypto/x509v3/v3_crld.c",0x37);
      pGVar4 = (GENERAL_NAMES *)0x0;
      pGVar7 = (GENERAL_NAMES *)0x0;
    }
    else {
      pGVar4 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,psVar3);
      if (*line == '@') {
        X509V3_section_free(param_2,psVar3);
      }
      else {
        OPENSSL_sk_pop_free(psVar3,0x1752a9);
      }
      if (pGVar4 == (GENERAL_NAMES *)0x0) {
        pGVar7 = (GENERAL_NAMES *)0x0;
      }
      else {
        pGVar7 = (GENERAL_NAMES *)0x0;
        pGVar1 = pGVar4;
LAB_00171164:
        pGVar4 = pGVar1;
        if (a->distpoint == (DIST_POINT_NAME *)0x0) {
          pDVar5 = DIST_POINT_NAME_new();
          a->distpoint = pDVar5;
          if (pDVar5 != (DIST_POINT_NAME *)0x0) {
            if (pGVar4 == (GENERAL_NAMES *)0x0) {
              (pDVar5->name).fullname = pGVar7;
            }
            else {
              (pDVar5->name).fullname = pGVar4;
            }
            pDVar5->type = (uint)(pGVar4 == (GENERAL_NAMES *)0x0);
            goto LAB_001710fe;
          }
        }
        else {
          ERR_put_error(0x22,0x9e,0xa0,"crypto/x509v3/v3_crld.c",0x6e);
        }
      }
    }
LAB_00171214:
    OPENSSL_sk_pop_free(pGVar4,0x1714fd);
    OPENSSL_sk_pop_free(pGVar7,0x169239);
  }
LAB_0017122c:
  ISSUING_DIST_POINT_free(a);
  return (ISSUING_DIST_POINT *)0x0;
}

