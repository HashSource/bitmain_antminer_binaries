
int v2i_crld(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  CONF_VALUE *cnf;
  stack_st_CONF_VALUE *section;
  DIST_POINT *pDVar3;
  int iVar4;
  int iVar5;
  stack_st_CONF_VALUE *psVar6;
  GENERAL_NAMES *pGVar7;
  DIST_POINT_NAME *pDVar8;
  X509_NAME *nm;
  GENERAL_NAMES *pGVar9;
  DIST_POINT *a;
  int iVar10;
  char *pcVar11;
  GENERAL_NAMES *pGVar12;
  DIST_POINT_NAME *pDVar13;
  int local_48;
  
  iVar1 = OPENSSL_sk_num(param_3);
  iVar2 = OPENSSL_sk_new_reserve(0,iVar1);
  if (iVar2 == 0) {
    a = (DIST_POINT *)0x0;
    pDVar3 = (DIST_POINT *)0x0;
LAB_0017512a:
    ERR_put_error(0x22,0x86,0x41,"crypto/x509v3/v3_crld.c",0x11d);
LAB_0017504c:
    GENERAL_NAME_free((GENERAL_NAME *)a);
    GENERAL_NAMES_free((GENERAL_NAMES *)pDVar3);
    OPENSSL_sk_pop_free(iVar2,(undefined *)0x1748d5);
    return 0;
  }
  if (0 < iVar1) {
    local_48 = 0;
    do {
      cnf = (CONF_VALUE *)OPENSSL_sk_value(param_3,local_48);
      if (cnf->value == (char *)0x0) {
        section = X509V3_get_section(param_2,cnf->name);
        if (section == (stack_st_CONF_VALUE *)0x0) {
LAB_00175152:
          a = (DIST_POINT *)0x0;
          pDVar3 = a;
          goto LAB_0017504c;
        }
        pDVar3 = DIST_POINT_new();
        iVar10 = 0;
        if (pDVar3 == (DIST_POINT *)0x0) {
LAB_0017503a:
          a = (DIST_POINT *)0x0;
          DIST_POINT_free(pDVar3);
          X509V3_section_free(param_2,section);
          pDVar3 = (DIST_POINT *)0x0;
          goto LAB_0017504c;
        }
        for (; iVar4 = OPENSSL_sk_num(section), iVar10 < iVar4; iVar10 = iVar10 + 1) {
          iVar4 = OPENSSL_sk_value(section,iVar10);
          pcVar11 = *(char **)(iVar4 + 4);
          iVar5 = strcmp(pcVar11,"fullname");
          if (iVar5 == 0) {
            pcVar11 = *(char **)(iVar4 + 8);
            if (*pcVar11 == '@') {
              psVar6 = X509V3_get_section(param_2,pcVar11 + 1);
            }
            else {
              psVar6 = X509V3_parse_list(pcVar11);
            }
            if (psVar6 == (stack_st_CONF_VALUE *)0x0) {
              ERR_put_error(0x22,0x9c,0x96,"crypto/x509v3/v3_crld.c",0x37);
              pGVar9 = (GENERAL_NAMES *)0x0;
              pGVar12 = (GENERAL_NAMES *)0x0;
            }
            else {
              pGVar7 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,psVar6);
              if (*pcVar11 == '@') {
                X509V3_section_free(param_2,psVar6);
              }
              else {
                OPENSSL_sk_pop_free(psVar6,0x1794f9);
              }
              pGVar9 = pGVar7;
              if (pGVar7 == (GENERAL_NAMES *)0x0) {
                pGVar12 = (GENERAL_NAMES *)0x0;
              }
              else {
                pDVar13 = pDVar3->distpoint;
                pGVar12 = (GENERAL_NAMES *)0x0;
                if (pDVar13 == (DIST_POINT_NAME *)0x0) {
LAB_00174f82:
                  pDVar8 = DIST_POINT_NAME_new();
                  pDVar3->distpoint = pDVar8;
                  if (pDVar8 != (DIST_POINT_NAME *)0x0) {
                    if (pGVar9 == (GENERAL_NAMES *)0x0) {
                      (pDVar8->name).fullname = pGVar12;
                      pDVar13 = (DIST_POINT_NAME *)0x1;
                    }
                    else {
                      (pDVar8->name).fullname = pGVar9;
                    }
                    pDVar8->type = (int)pDVar13;
                    goto LAB_00174f14;
                  }
                }
                else {
LAB_0017500c:
                  ERR_put_error(0x22,0x9e,0xa0,"crypto/x509v3/v3_crld.c",0x6e);
                  pGVar9 = pGVar7;
                }
              }
            }
LAB_00175022:
            OPENSSL_sk_pop_free(pGVar9,(undefined *)0x17574d);
            OPENSSL_sk_pop_free(pGVar12,0x16d489);
            goto LAB_0017503a;
          }
          iVar5 = strcmp(pcVar11,"relativename");
          if (iVar5 == 0) {
            nm = X509_NAME_new();
            if (nm != (X509_NAME *)0x0) {
              psVar6 = X509V3_get_section(param_2,*(char **)(iVar4 + 8));
              if (psVar6 != (stack_st_CONF_VALUE *)0x0) {
                iVar4 = X509V3_NAME_from_section(nm,psVar6,0x1001);
                X509V3_section_free(param_2,psVar6);
                pGVar12 = (GENERAL_NAMES *)nm->entries;
                nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
                X509_NAME_free(nm);
                if (iVar4 == 0) {
                  pGVar9 = (GENERAL_NAMES *)0x0;
                }
                else {
                  iVar4 = OPENSSL_sk_num(pGVar12);
                  pGVar9 = (GENERAL_NAMES *)0x0;
                  if (0 < iVar4) {
                    iVar4 = OPENSSL_sk_num(pGVar12);
                    iVar4 = OPENSSL_sk_value(pGVar12,iVar4 + -1);
                    if (*(int *)(iVar4 + 8) == 0) {
                      pDVar13 = pDVar3->distpoint;
                      pGVar7 = (GENERAL_NAMES *)0x0;
                      pGVar9 = (GENERAL_NAMES *)0x0;
                      if (pDVar13 != (DIST_POINT_NAME *)0x0) goto LAB_0017500c;
                      goto LAB_00174f82;
                    }
                    ERR_put_error(0x22,0x9e,0xa1,"crypto/x509v3/v3_crld.c",0x66);
                  }
                }
                goto LAB_00175022;
              }
              ERR_put_error(0x22,0x9e,0x96,"crypto/x509v3/v3_crld.c",0x56);
            }
            goto LAB_0017503a;
          }
          iVar5 = strcmp(pcVar11,"reasons");
          if (iVar5 == 0) {
            pGVar7 = (GENERAL_NAMES *)set_reasons(&pDVar3->reasons,*(undefined4 *)(iVar4 + 8));
joined_r0x001750a2:
            if (pGVar7 == (GENERAL_NAMES *)0x0) goto LAB_0017503a;
          }
          else {
            iVar5 = strcmp(pcVar11,"CRLissuer");
            if (iVar5 == 0) {
              pcVar11 = *(char **)(iVar4 + 8);
              if (*pcVar11 == '@') {
                psVar6 = X509V3_get_section(param_2,pcVar11 + 1);
              }
              else {
                psVar6 = X509V3_parse_list(pcVar11);
              }
              if (psVar6 != (stack_st_CONF_VALUE *)0x0) {
                pGVar7 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,psVar6);
                if (*pcVar11 == '@') {
                  X509V3_section_free(param_2,psVar6);
                }
                else {
                  OPENSSL_sk_pop_free(psVar6,0x1794f9);
                }
                pDVar3->CRLissuer = pGVar7;
                goto joined_r0x001750a2;
              }
              ERR_put_error(0x22,0x9c,0x96,"crypto/x509v3/v3_crld.c",0x37);
              pDVar3->CRLissuer = (GENERAL_NAMES *)0x0;
              goto LAB_0017503a;
            }
          }
LAB_00174f14:
        }
        X509V3_section_free(param_2,section);
        OPENSSL_sk_push(iVar2,pDVar3);
      }
      else {
        a = (DIST_POINT *)v2i_GENERAL_NAME(param_1,param_2,cnf);
        if (a == (DIST_POINT *)0x0) goto LAB_00175152;
        pDVar3 = (DIST_POINT *)GENERAL_NAMES_new();
        if (((pDVar3 == (DIST_POINT *)0x0) || (iVar10 = OPENSSL_sk_push(pDVar3,a), iVar10 == 0)) ||
           (a = DIST_POINT_new(), a == (DIST_POINT *)0x0)) goto LAB_0017512a;
        OPENSSL_sk_push(iVar2,a);
        pDVar13 = DIST_POINT_NAME_new();
        a->distpoint = pDVar13;
        if (pDVar13 == (DIST_POINT_NAME *)0x0) {
          a = (DIST_POINT *)0x0;
          goto LAB_0017512a;
        }
        pDVar13->type = 0;
        (pDVar13->name).fullname = (GENERAL_NAMES *)pDVar3;
      }
      local_48 = local_48 + 1;
    } while (iVar1 != local_48);
  }
  return iVar2;
}

