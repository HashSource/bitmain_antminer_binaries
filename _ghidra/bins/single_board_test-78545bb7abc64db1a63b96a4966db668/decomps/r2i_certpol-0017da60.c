
int r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  bool bVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  POLICYINFO *a;
  undefined4 *puVar6;
  int iVar7;
  stack_st_CONF_VALUE *section;
  int iVar8;
  POLICYQUALINFO *pPVar9;
  ASN1_IA5STRING *str;
  size_t sVar10;
  stack_st_CONF_VALUE *section_00;
  USERNOTICE *pUVar11;
  int iVar12;
  stack_st_CONF_VALUE *psVar13;
  ASN1_INTEGER *a_00;
  int iVar14;
  stack_st_POLICYQUALINFO *psVar15;
  ASN1_STRING *pAVar16;
  NOTICEREF *pNVar17;
  char *pcVar18;
  stack_st_ASN1_INTEGER *psVar19;
  char *__s;
  int local_64;
  
  psVar2 = X509V3_parse_list(param_3);
  iVar3 = OPENSSL_sk_num();
  if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
    ERR_put_error(0x22,0x82,0x22,"crypto/x509v3/v3_cpols.c",0x65);
  }
  else {
    iVar4 = OPENSSL_sk_new_reserve(0,iVar3);
    if (iVar4 != 0) {
      if (0 < iVar3) {
        bVar1 = false;
        local_64 = 0;
        do {
          puVar6 = (undefined4 *)OPENSSL_sk_value(psVar2,local_64);
          if ((puVar6[2] != 0) || (pcVar18 = (char *)puVar6[1], pcVar18 == (char *)0x0)) {
            ERR_put_error(0x22,0x82,0x86,"crypto/x509v3/v3_cpols.c",0x75);
            ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],",value:",puVar6[2]);
            goto LAB_0017dc16;
          }
          iVar7 = strcmp(pcVar18,"ia5org");
          if (iVar7 != 0) {
            if (*pcVar18 == '@') {
              section = X509V3_get_section(param_2,pcVar18 + 1);
              if (section == (stack_st_CONF_VALUE *)0x0) {
                ERR_put_error(0x22,0x82,0x87,"crypto/x509v3/v3_cpols.c",0x81);
                ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],",value:",puVar6[2]);
              }
              else {
                a = POLICYINFO_new();
                if (a == (POLICYINFO *)0x0) {
LAB_0017dbf2:
                  ERR_put_error(0x22,0x83,0x41,"crypto/x509v3/v3_cpols.c",0xf3);
                }
                else {
                  for (iVar7 = 0; iVar8 = OPENSSL_sk_num(section), iVar7 < iVar8; iVar7 = iVar7 + 1)
                  {
                    puVar6 = (undefined4 *)OPENSSL_sk_value(section,iVar7);
                    pcVar18 = (char *)puVar6[1];
                    iVar8 = strcmp(pcVar18,"policyIdentifier");
                    if (iVar8 == 0) {
                      pAVar5 = OBJ_txt2obj((char *)puVar6[2],0);
                      if (pAVar5 == (ASN1_OBJECT *)0x0) {
                        ERR_put_error(0x22,0x83,0x6e,"crypto/x509v3/v3_cpols.c",0xb7);
                        ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],",value:",
                                           puVar6[2]);
                        goto LAB_0017dc06;
                      }
                      a->policyid = pAVar5;
                    }
                    else {
                      iVar8 = name_cmp(pcVar18,"CPS");
                      if (iVar8 != 0) {
                        iVar8 = name_cmp((char *)puVar6[1],"userNotice");
                        if (iVar8 == 0) {
                          if (*(char *)puVar6[2] == '@') {
                            section_00 = X509V3_get_section(param_2,(char *)puVar6[2] + 1);
                            if (section_00 == (stack_st_CONF_VALUE *)0x0) {
                              ERR_put_error(0x22,0x83,0x87,"crypto/x509v3/v3_cpols.c",0xd7);
                              ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],",value:",
                                                 puVar6[2]);
                            }
                            else {
                              pPVar9 = POLICYQUALINFO_new();
                              if (pPVar9 == (POLICYQUALINFO *)0x0) {
LAB_0017ddd0:
                                ERR_put_error(0x22,0x84,0x41,"crypto/x509v3/v3_cpols.c",0x16e);
                              }
                              else {
                                pAVar5 = OBJ_nid2obj(0xa5);
                                pPVar9->pqualid = pAVar5;
                                if (pAVar5 == (ASN1_OBJECT *)0x0) {
                                  ERR_put_error(0x22,0x84,0x44,"crypto/x509v3/v3_cpols.c",0x128);
                                }
                                else {
                                  pUVar11 = USERNOTICE_new();
                                  if (pUVar11 == (USERNOTICE *)0x0) goto LAB_0017ddd0;
                                  (pPVar9->d).usernotice = pUVar11;
                                  for (iVar8 = 0; iVar12 = OPENSSL_sk_num(section_00),
                                      iVar8 < iVar12; iVar8 = iVar8 + 1) {
                                    puVar6 = (undefined4 *)OPENSSL_sk_value(section_00,iVar8);
                                    pcVar18 = (char *)puVar6[1];
                                    __s = (char *)puVar6[2];
                                    iVar12 = strcmp(pcVar18,"explicitText");
                                    if (iVar12 == 0) {
                                      pcVar18 = strchr(__s,0x3a);
                                      if ((pcVar18 == (char *)0x0) ||
                                         (iVar12 = (int)pcVar18 - (int)__s, iVar12 == -1)) {
LAB_0017ddae:
                                        pAVar16 = ASN1_STRING_type_new(0x1a);
                                        pUVar11->exptext = pAVar16;
                                        if (pAVar16 == (ASN1_STRING *)0x0) goto LAB_0017ddd0;
                                      }
                                      else {
                                        if (iVar12 == 4) {
                                          iVar14 = strncmp(__s,"UTF8",4);
                                          if (iVar14 != 0) goto LAB_0017ddae;
                                          iVar14 = 0xc;
                                        }
                                        else if (iVar12 == 10) {
                                          iVar14 = strncmp(__s,"UTF8String",10);
                                          if (iVar14 != 0) goto LAB_0017ddae;
                                          iVar14 = 0xc;
                                        }
                                        else if (iVar12 == 3) {
                                          iVar14 = strncmp(__s,"BMP",3);
                                          if (iVar14 != 0) goto LAB_0017ddae;
                                          iVar14 = 0x1e;
                                        }
                                        else if (iVar12 == 9) {
                                          iVar14 = strncmp(__s,"BMPSTRING",9);
                                          if (iVar14 != 0) goto LAB_0017ddae;
                                          iVar14 = 0x1e;
                                        }
                                        else {
                                          if (iVar12 == 7) {
                                            iVar14 = strncmp(__s,"VISIBLE",7);
                                          }
                                          else {
                                            if (iVar12 != 0xd) goto LAB_0017ddae;
                                            iVar14 = strncmp(__s,"VISIBLESTRING",0xd);
                                          }
                                          if (iVar14 != 0) goto LAB_0017ddae;
                                          iVar14 = 0x1a;
                                        }
                                        pAVar16 = ASN1_STRING_type_new(iVar14);
                                        pUVar11->exptext = pAVar16;
                                        if (pAVar16 == (ASN1_STRING *)0x0) goto LAB_0017ddd0;
                                        if (iVar12 != 0) {
                                          __s = __s + iVar12 + 1;
                                        }
                                      }
                                      sVar10 = strlen(__s);
                                      iVar12 = ASN1_STRING_set(pAVar16,__s,sVar10);
joined_r0x0017dcc6:
                                      if (iVar12 == 0) goto LAB_0017ddd0;
                                    }
                                    else {
                                      iVar12 = strcmp(pcVar18,"organization");
                                      if (iVar12 == 0) {
                                        pNVar17 = pUVar11->noticeref;
                                        if (pNVar17 == (NOTICEREF *)0x0) {
                                          pNVar17 = NOTICEREF_new();
                                          if (pNVar17 == (NOTICEREF *)0x0) goto LAB_0017ddd0;
                                          pUVar11->noticeref = pNVar17;
                                          __s = (char *)puVar6[2];
                                        }
                                        pAVar16 = pNVar17->organization;
                                        if (bVar1) {
                                          pAVar16->type = 0x16;
                                        }
                                        else {
                                          pAVar16->type = 0x1a;
                                        }
                                        sVar10 = strlen(__s);
                                        iVar12 = ASN1_STRING_set(pAVar16,__s,sVar10);
                                        goto joined_r0x0017dcc6;
                                      }
                                      iVar12 = strcmp(pcVar18,"noticeNumbers");
                                      if (iVar12 != 0) {
                                        ERR_put_error(0x22,0x84,0x8a,"crypto/x509v3/v3_cpols.c",
                                                      0x15e);
                                        ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],
                                                           ",value:",puVar6[2]);
                                        goto LAB_0017ddea;
                                      }
                                      pNVar17 = pUVar11->noticeref;
                                      if (pNVar17 == (NOTICEREF *)0x0) {
                                        pNVar17 = NOTICEREF_new();
                                        if (pNVar17 == (NOTICEREF *)0x0) goto LAB_0017ddd0;
                                        pUVar11->noticeref = pNVar17;
                                        psVar13 = X509V3_parse_list((char *)puVar6[2]);
                                        if (psVar13 != (stack_st_CONF_VALUE *)0x0)
                                        goto LAB_0017dd24;
LAB_0017de92:
                                        ERR_put_error(0x22,0x84,0x8d,"crypto/x509v3/v3_cpols.c",
                                                      0x154);
                                        ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],
                                                           ",value:",puVar6[2]);
                                        OPENSSL_sk_pop_free(psVar13,0x1830d1);
                                        goto LAB_0017ddea;
                                      }
                                      psVar13 = X509V3_parse_list(__s);
                                      if (psVar13 == (stack_st_CONF_VALUE *)0x0) goto LAB_0017de92;
LAB_0017dd24:
                                      iVar12 = OPENSSL_sk_num();
                                      if (iVar12 == 0) goto LAB_0017de92;
                                      psVar19 = pNVar17->noticenos;
                                      iVar12 = 0;
LAB_0017dd54:
                                      iVar14 = OPENSSL_sk_num(psVar13);
                                      if (iVar12 < iVar14) {
                                        iVar14 = OPENSSL_sk_value(psVar13,iVar12);
                                        a_00 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                                *(char **)(iVar14 + 4));
                                        if (a_00 != (ASN1_INTEGER *)0x0) goto code_r0x0017dd48;
                                        ERR_put_error(0x22,0x85,0x8c,"crypto/x509v3/v3_cpols.c",
                                                      0x17f);
                                        goto LAB_0017de48;
                                      }
                                      OPENSSL_sk_pop_free(psVar13,0x1830d1);
                                    }
                                  }
                                  pNVar17 = pUVar11->noticeref;
                                  if ((pNVar17 == (NOTICEREF *)0x0) ||
                                     ((pNVar17->noticenos != (stack_st_ASN1_INTEGER *)0x0 &&
                                      (pNVar17->organization != (ASN1_STRING *)0x0)))) {
                                    X509V3_section_free(param_2,section_00);
                                    psVar15 = a->qualifiers;
                                    if (psVar15 == (stack_st_POLICYQUALINFO *)0x0) {
                                      psVar15 = (stack_st_POLICYQUALINFO *)OPENSSL_sk_new_null();
                                      a->qualifiers = psVar15;
                                    }
                                    iVar8 = OPENSSL_sk_push(psVar15,pPVar9);
                                    if (iVar8 != 0) goto LAB_0017db70;
                                    goto LAB_0017dbf2;
                                  }
                                  ERR_put_error(0x22,0x84,0x8e,"crypto/x509v3/v3_cpols.c",0x167);
                                }
                              }
LAB_0017ddea:
                              POLICYQUALINFO_free(pPVar9);
                              X509V3_section_free(param_2,section_00);
                            }
                          }
                          else {
                            ERR_put_error(0x22,0x83,0x89,"crypto/x509v3/v3_cpols.c",0xd1);
                            ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],",value:",
                                               puVar6[2]);
                          }
                        }
                        else {
                          ERR_put_error(0x22,0x83,0x8a,"crypto/x509v3/v3_cpols.c",0xe5);
                          ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],",value:",
                                             puVar6[2]);
                        }
                        goto LAB_0017dc06;
                      }
                      if (a->qualifiers == (stack_st_POLICYQUALINFO *)0x0) {
                        psVar15 = (stack_st_POLICYQUALINFO *)OPENSSL_sk_new_null();
                        a->qualifiers = psVar15;
                      }
                      pPVar9 = POLICYQUALINFO_new();
                      if ((pPVar9 == (POLICYQUALINFO *)0x0) ||
                         (iVar8 = OPENSSL_sk_push(a->qualifiers,pPVar9), iVar8 == 0))
                      goto LAB_0017dbf2;
                      pAVar5 = OBJ_nid2obj(0xa4);
                      pPVar9->pqualid = pAVar5;
                      if (pAVar5 == (ASN1_OBJECT *)0x0) {
                        ERR_put_error(0x22,0x83,0x44,"crypto/x509v3/v3_cpols.c",0xc5);
                        goto LAB_0017dc06;
                      }
                      str = ASN1_IA5STRING_new();
                      (pPVar9->d).cpsuri = str;
                      if (str == (ASN1_IA5STRING *)0x0) goto LAB_0017dbf2;
                      pcVar18 = (char *)puVar6[2];
                      sVar10 = strlen(pcVar18);
                      iVar8 = ASN1_STRING_set(str,pcVar18,sVar10);
                      if (iVar8 == 0) goto LAB_0017dbf2;
                    }
LAB_0017db70:
                  }
                  if (a->policyid != (ASN1_OBJECT *)0x0) {
                    X509V3_section_free(param_2,section);
                    iVar7 = OPENSSL_sk_push(iVar4,a);
                    if (iVar7 == 0) goto LAB_0017dfda;
                    goto LAB_0017daf2;
                  }
                  ERR_put_error(0x22,0x83,0x8b,"crypto/x509v3/v3_cpols.c",0xec);
                }
LAB_0017dc06:
                POLICYINFO_free(a);
                X509V3_section_free(param_2,section);
              }
            }
            else {
              pAVar5 = OBJ_txt2obj(pcVar18,0);
              if (pAVar5 == (ASN1_OBJECT *)0x0) {
                ERR_put_error(0x22,0x82,0x6e,"crypto/x509v3/v3_cpols.c",0x8d);
                ERR_add_error_data(6,"section:",*puVar6,",name:",puVar6[1],",value:",puVar6[2]);
              }
              else {
                a = POLICYINFO_new();
                if (a == (POLICYINFO *)0x0) {
                  ASN1_OBJECT_free(pAVar5);
                  iVar3 = 0x94;
                }
                else {
                  a->policyid = pAVar5;
                  iVar7 = OPENSSL_sk_push(iVar4,a);
                  if (iVar7 != 0) goto LAB_0017daf2;
LAB_0017dfda:
                  POLICYINFO_free(a);
                  iVar3 = 0x9b;
                }
                ERR_put_error(0x22,0x82,0x41,"crypto/x509v3/v3_cpols.c",iVar3);
              }
            }
            goto LAB_0017dc16;
          }
          bVar1 = true;
LAB_0017daf2:
          local_64 = local_64 + 1;
        } while (local_64 != iVar3);
      }
      OPENSSL_sk_pop_free(psVar2,0x1830d1);
      return iVar4;
    }
    ERR_put_error(0x22,0x82,0x41,"crypto/x509v3/v3_cpols.c",0x6b);
LAB_0017dc16:
    OPENSSL_sk_pop_free(psVar2,0x1830d1);
    OPENSSL_sk_pop_free(iVar4,(undefined *)0x17d8bd);
  }
  return 0;
code_r0x0017dd48:
  iVar14 = OPENSSL_sk_push(psVar19,a_00);
  iVar12 = iVar12 + 1;
  if (iVar14 == 0) {
    ASN1_INTEGER_free(a_00);
    ERR_put_error(0x22,0x85,0x41,"crypto/x509v3/v3_cpols.c",0x189);
LAB_0017de48:
    OPENSSL_sk_pop_free(psVar13,0x1830d1);
    goto LAB_0017ddea;
  }
  goto LAB_0017dd54;
}

