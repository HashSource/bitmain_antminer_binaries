
_STACK * r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  bool bVar1;
  _STACK *st;
  _STACK *st_00;
  ASN1_OBJECT *pAVar2;
  ASN1_VALUE *val;
  int iVar3;
  undefined4 *puVar4;
  _STACK *section;
  ASN1_VALUE *pAVar5;
  ASN1_STRING *pAVar6;
  size_t sVar7;
  ASN1_VALUE *pAVar8;
  int iVar9;
  _STACK *st_01;
  void *pvVar10;
  ASN1_INTEGER *data;
  int iVar11;
  _STACK *p_Var12;
  int *piVar13;
  char *pcVar14;
  ASN1_VALUE *pAVar15;
  _STACK *st_02;
  int iVar16;
  int local_48;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0x93);
  }
  else {
    st_00 = &X509V3_parse_list(param_3)->stack;
    if (st_00 != (_STACK *)0x0) {
      bVar1 = false;
      local_48 = 0;
LAB_000c9fac:
      iVar3 = sk_num(st_00);
      if (iVar3 <= local_48) {
        sk_pop_free(st_00,(func *)0xc7009);
        return st;
      }
      puVar4 = (undefined4 *)sk_value(st_00,local_48);
      if ((puVar4[2] == 0) && (pcVar14 = (char *)puVar4[1], pcVar14 != (char *)0x0)) {
        iVar3 = strcmp(pcVar14,"ia5org");
        if (iVar3 == 0) {
          bVar1 = true;
LAB_000c9fa6:
          local_48 = local_48 + 1;
          goto LAB_000c9fac;
        }
        if (*pcVar14 != '@') {
          pAVar2 = OBJ_txt2obj(pcVar14,0);
          if (pAVar2 == (ASN1_OBJECT *)0x0) {
            iVar16 = 0xb8;
            iVar3 = 0x6e;
            goto LAB_000ca34e;
          }
          val = ASN1_item_new((ASN1_ITEM *)&POLICYINFO_it);
          *(ASN1_OBJECT **)val = pAVar2;
          iVar3 = sk_push(st,val);
          if (iVar3 != 0) goto LAB_000c9fa6;
LAB_000ca398:
          ASN1_item_free(val,(ASN1_ITEM *)&POLICYINFO_it);
          ERR_put_error(0x22,0x82,0x41,"v3_cpols.c",0xc1);
          goto LAB_000ca0be;
        }
        section = &X509V3_get_section(param_2,pcVar14 + 1)->stack;
        if (section != (_STACK *)0x0) {
          val = ASN1_item_new((ASN1_ITEM *)&POLICYINFO_it);
          if (val == (ASN1_VALUE *)0x0) {
LAB_000ca09c:
            ERR_put_error(0x22,0x83,0x41,"v3_cpols.c",0x118);
          }
          else {
            for (iVar3 = 0; iVar16 = sk_num(section), iVar3 < iVar16; iVar3 = iVar3 + 1) {
              puVar4 = (undefined4 *)sk_value(section,iVar3);
              pcVar14 = (char *)puVar4[1];
              iVar16 = strcmp(pcVar14,"policyIdentifier");
              if (iVar16 == 0) {
                pAVar2 = OBJ_txt2obj((char *)puVar4[2],0);
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  iVar3 = 0x6e;
                  iVar16 = 0xdc;
                  goto LAB_000ca3d4;
                }
                *(ASN1_OBJECT **)val = pAVar2;
              }
              else {
                iVar16 = name_cmp(pcVar14,"CPS");
                if (iVar16 != 0) {
                  iVar16 = name_cmp((char *)puVar4[1],"userNotice");
                  if (iVar16 == 0) {
                    if (*(char *)puVar4[2] == '@') {
                      p_Var12 = &X509V3_get_section(param_2,(char *)puVar4[2] + 1)->stack;
                      if (p_Var12 != (_STACK *)0x0) {
                        pAVar5 = ASN1_item_new((ASN1_ITEM *)POLICYQUALINFO_it);
                        if (pAVar5 == (ASN1_VALUE *)0x0) {
LAB_000ca250:
                          ERR_put_error(0x22,0x84,0x41,"v3_cpols.c",0x16b);
                        }
                        else {
                          pAVar2 = OBJ_nid2obj(0xa5);
                          *(ASN1_OBJECT **)pAVar5 = pAVar2;
                          if (pAVar2 == (ASN1_OBJECT *)0x0) {
                            ERR_put_error(0x22,0x84,0x44,"v3_cpols.c",0x12a);
                          }
                          else {
                            pAVar8 = ASN1_item_new((ASN1_ITEM *)USERNOTICE_it);
                            if (pAVar8 == (ASN1_VALUE *)0x0) goto LAB_000ca250;
                            *(ASN1_VALUE **)(pAVar5 + 4) = pAVar8;
                            for (iVar16 = 0; iVar9 = sk_num(p_Var12), iVar16 < iVar9;
                                iVar16 = iVar16 + 1) {
                              puVar4 = (undefined4 *)sk_value(p_Var12,iVar16);
                              pcVar14 = (char *)puVar4[1];
                              iVar9 = strcmp(pcVar14,"explicitText");
                              if (iVar9 == 0) {
                                pAVar6 = ASN1_STRING_type_new(0x1a);
                                *(ASN1_STRING **)(pAVar8 + 4) = pAVar6;
                                if (pAVar6 == (ASN1_STRING *)0x0) goto LAB_000ca250;
LAB_000ca156:
                                pcVar14 = (char *)puVar4[2];
                                sVar7 = strlen(pcVar14);
                                iVar9 = ASN1_STRING_set(pAVar6,pcVar14,sVar7);
                                if (iVar9 == 0) goto LAB_000ca250;
                              }
                              else {
                                iVar9 = strcmp(pcVar14,"organization");
                                if (iVar9 == 0) {
                                  pAVar15 = *(ASN1_VALUE **)pAVar8;
                                  if (pAVar15 == (ASN1_VALUE *)0x0) {
                                    pAVar15 = ASN1_item_new((ASN1_ITEM *)NOTICEREF_it);
                                    if (pAVar15 == (ASN1_VALUE *)0x0) goto LAB_000ca250;
                                    *(ASN1_VALUE **)pAVar8 = pAVar15;
                                  }
                                  pAVar6 = *(ASN1_STRING **)pAVar15;
                                  if (bVar1) {
                                    pAVar6->type = 0x16;
                                  }
                                  else {
                                    pAVar6->type = 0x1a;
                                  }
                                  goto LAB_000ca156;
                                }
                                iVar9 = strcmp(pcVar14,"noticeNumbers");
                                if (iVar9 != 0) {
                                  iVar16 = 0x15b;
                                  iVar3 = 0x8a;
LAB_000ca2dc:
                                  ERR_put_error(0x22,0x84,iVar3,"v3_cpols.c",iVar16);
                                  ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],
                                                     ",value:",puVar4[2]);
                                  goto LAB_000ca262;
                                }
                                pAVar15 = *(ASN1_VALUE **)pAVar8;
                                if (pAVar15 == (ASN1_VALUE *)0x0) {
                                  pAVar15 = ASN1_item_new((ASN1_ITEM *)NOTICEREF_it);
                                  if (pAVar15 != (ASN1_VALUE *)0x0) {
                                    *(ASN1_VALUE **)pAVar8 = pAVar15;
                                    st_01 = &X509V3_parse_list((char *)puVar4[2])->stack;
                                    if (st_01 != (_STACK *)0x0) goto LAB_000ca1c2;
LAB_000ca2d0:
                                    iVar3 = 0x8d;
                                    iVar16 = 0x152;
                                    goto LAB_000ca2dc;
                                  }
                                  goto LAB_000ca250;
                                }
                                st_01 = &X509V3_parse_list((char *)puVar4[2])->stack;
                                if (st_01 == (_STACK *)0x0) goto LAB_000ca2d0;
LAB_000ca1c2:
                                iVar9 = sk_num(st_01);
                                if (iVar9 == 0) goto LAB_000ca2d0;
                                st_02 = *(_STACK **)(pAVar15 + 4);
                                iVar9 = 0;
LAB_000ca1f0:
                                iVar11 = sk_num(st_01);
                                if (iVar9 < iVar11) {
                                  pvVar10 = sk_value(st_01,iVar9);
                                  data = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                          *(char **)((int)pvVar10 + 4));
                                  if (data != (ASN1_INTEGER *)0x0) goto code_r0x000ca1e8;
                                  ERR_put_error(0x22,0x85,0x8c,"v3_cpols.c",0x17c);
                                  goto LAB_000ca28c;
                                }
                                sk_pop_free(st_01,(func *)0xc7009);
                              }
                            }
                            piVar13 = *(int **)pAVar8;
                            if ((piVar13 == (int *)0x0) || ((piVar13[1] != 0 && (*piVar13 != 0)))) {
                              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var12);
                              p_Var12 = *(_STACK **)(val + 4);
                              if (p_Var12 == (_STACK *)0x0) {
                                p_Var12 = sk_new_null();
                                *(_STACK **)(val + 4) = p_Var12;
                              }
                              iVar16 = sk_push(p_Var12,pAVar5);
                              if (iVar16 != 0) goto LAB_000ca018;
                              goto LAB_000ca09c;
                            }
                            ERR_put_error(0x22,0x84,0x8e,"v3_cpols.c",0x164);
                          }
                        }
LAB_000ca262:
                        ASN1_item_free(pAVar5,(ASN1_ITEM *)POLICYQUALINFO_it);
                        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var12);
                        goto LAB_000ca0ae;
                      }
                      iVar16 = 0xfc;
                      iVar3 = 0x87;
                    }
                    else {
                      iVar16 = 0xf6;
                      iVar3 = 0x89;
                    }
                  }
                  else {
                    iVar16 = 0x10a;
                    iVar3 = 0x8a;
                  }
LAB_000ca3d4:
                  ERR_put_error(0x22,0x83,iVar3,"v3_cpols.c",iVar16);
                  ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
                  goto LAB_000ca0ae;
                }
                if (*(int *)(val + 4) == 0) {
                  p_Var12 = sk_new_null();
                  *(_STACK **)(val + 4) = p_Var12;
                }
                pAVar5 = ASN1_item_new((ASN1_ITEM *)POLICYQUALINFO_it);
                if ((pAVar5 == (ASN1_VALUE *)0x0) ||
                   (iVar16 = sk_push(*(_STACK **)(val + 4),pAVar5), iVar16 == 0)) goto LAB_000ca09c;
                pAVar2 = OBJ_nid2obj(0xa4);
                *(ASN1_OBJECT **)pAVar5 = pAVar2;
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  ERR_put_error(0x22,0x83,0x44,"v3_cpols.c",0xea);
                  goto LAB_000ca0ae;
                }
                pAVar6 = ASN1_STRING_type_new(0x16);
                *(ASN1_STRING **)(pAVar5 + 4) = pAVar6;
                if (pAVar6 == (ASN1_STRING *)0x0) goto LAB_000ca09c;
                pcVar14 = (char *)puVar4[2];
                sVar7 = strlen(pcVar14);
                iVar16 = ASN1_STRING_set(pAVar6,pcVar14,sVar7);
                if (iVar16 == 0) goto LAB_000ca09c;
              }
LAB_000ca018:
            }
            if (*(int *)val != 0) {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
              iVar3 = sk_push(st,val);
              if (iVar3 == 0) goto LAB_000ca398;
              goto LAB_000c9fa6;
            }
            ERR_put_error(0x22,0x83,0x8b,"v3_cpols.c",0x111);
          }
LAB_000ca0ae:
          ASN1_item_free(val,(ASN1_ITEM *)&POLICYINFO_it);
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
          goto LAB_000ca0be;
        }
        iVar16 = 0xac;
        iVar3 = 0x87;
      }
      else {
        iVar3 = 0x86;
        iVar16 = 0xa0;
      }
LAB_000ca34e:
      ERR_put_error(0x22,0x82,iVar3,"v3_cpols.c",iVar16);
      ERR_add_error_data(6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
      goto LAB_000ca0be;
    }
    ERR_put_error(0x22,0x82,0x22,"v3_cpols.c",0x98);
LAB_000ca0be:
    sk_pop_free(st_00,(func *)0xc7009);
    sk_pop_free(st,(func *)0xc9f41);
  }
  return (_STACK *)0x0;
code_r0x000ca1e8:
  iVar11 = sk_push(st_02,data);
  iVar9 = iVar9 + 1;
  if (iVar11 == 0) {
    ERR_put_error(0x22,0x85,0x41,"v3_cpols.c",0x185);
LAB_000ca28c:
    sk_pop_free(st_02,(func *)0xbd009);
    sk_pop_free(st_01,(func *)0xc7009);
    goto LAB_000ca262;
  }
  goto LAB_000ca1f0;
}

