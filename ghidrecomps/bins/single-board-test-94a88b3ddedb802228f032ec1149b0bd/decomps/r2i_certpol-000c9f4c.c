
_STACK * r2i_certpol(undefined4 param_1,X509V3_CTX *param_2,char *param_3)

{
  bool bVar1;
  _STACK *st;
  _STACK *st_00;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT **val;
  int iVar3;
  undefined4 *puVar4;
  _STACK *section;
  ASN1_OBJECT **ppAVar5;
  size_t sVar6;
  _STACK *section_00;
  ASN1_STRING **ppAVar7;
  int iVar8;
  _STACK *st_01;
  void *pvVar9;
  ASN1_INTEGER *data;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  ASN1_STRING *str;
  ASN1_VALUE *pAVar13;
  _STACK *st_02;
  int iVar14;
  int local_48;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x82,0x41,DAT_000ca4b0,0x93);
  }
  else {
    st_00 = &X509V3_parse_list(param_3)->stack;
    if (st_00 != (_STACK *)0x0) {
      bVar1 = false;
      local_48 = 0;
LAB_000c9fac:
      iVar3 = sk_num(st_00);
      if (iVar3 <= local_48) {
        sk_pop_free(st_00,DAT_000ca4bc);
        return st;
      }
      puVar4 = (undefined4 *)sk_value(st_00,local_48);
      if ((puVar4[2] == 0) && (pcVar12 = (char *)puVar4[1], pcVar12 != (char *)0x0)) {
        iVar3 = strcmp(pcVar12,DAT_000ca210);
        if (iVar3 == 0) {
          bVar1 = true;
LAB_000c9fa6:
          local_48 = local_48 + 1;
          goto LAB_000c9fac;
        }
        if (*pcVar12 != '@') {
          pAVar2 = OBJ_txt2obj(pcVar12,0);
          if (pAVar2 == (ASN1_OBJECT *)0x0) {
            iVar14 = 0xb8;
            iVar3 = 0x6e;
            goto LAB_000ca34e;
          }
          val = (ASN1_OBJECT **)ASN1_item_new(DAT_000ca20c);
          *val = pAVar2;
          iVar3 = sk_push(st,val);
          if (iVar3 != 0) goto LAB_000c9fa6;
LAB_000ca398:
          ASN1_item_free((ASN1_VALUE *)val,DAT_000ca4d0);
          ERR_put_error(0x22,0x82,0x41,DAT_000ca4b0,0xc1);
          goto LAB_000ca0be;
        }
        section = &X509V3_get_section(param_2,pcVar12 + 1)->stack;
        if (section != (_STACK *)0x0) {
          val = (ASN1_OBJECT **)ASN1_item_new(DAT_000ca20c);
          if (val == (ASN1_OBJECT **)0x0) {
LAB_000ca09c:
            ERR_put_error(0x22,0x83,0x41,DAT_000ca220,0x118);
          }
          else {
            for (iVar3 = 0; iVar14 = sk_num(section), iVar3 < iVar14; iVar3 = iVar3 + 1) {
              puVar4 = (undefined4 *)sk_value(section,iVar3);
              pcVar12 = (char *)puVar4[1];
              iVar14 = strcmp(pcVar12,DAT_000ca214);
              if (iVar14 == 0) {
                pAVar2 = OBJ_txt2obj((char *)puVar4[2],0);
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  iVar3 = 0x6e;
                  iVar14 = 0xdc;
                  goto LAB_000ca3d4;
                }
                *val = pAVar2;
              }
              else {
                iVar14 = name_cmp(pcVar12,DAT_000ca218);
                if (iVar14 != 0) {
                  iVar14 = name_cmp((char *)puVar4[1],DAT_000ca22c);
                  if (iVar14 == 0) {
                    if (*(char *)puVar4[2] == '@') {
                      section_00 = &X509V3_get_section(param_2,(char *)puVar4[2] + 1)->stack;
                      if (section_00 != (_STACK *)0x0) {
                        ppAVar5 = (ASN1_OBJECT **)ASN1_item_new(DAT_000ca21c);
                        if (ppAVar5 == (ASN1_OBJECT **)0x0) {
LAB_000ca250:
                          ERR_put_error(0x22,0x84,0x41,DAT_000ca4b0,0x16b);
                        }
                        else {
                          pAVar2 = OBJ_nid2obj(0xa5);
                          *ppAVar5 = pAVar2;
                          if (pAVar2 == (ASN1_OBJECT *)0x0) {
                            ERR_put_error(0x22,0x84,0x44,DAT_000ca4b0,0x12a);
                          }
                          else {
                            pAVar2 = (ASN1_OBJECT *)ASN1_item_new(DAT_000ca230);
                            if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_000ca250;
                            ppAVar5[1] = pAVar2;
                            for (iVar14 = 0; iVar8 = sk_num(section_00), iVar14 < iVar8;
                                iVar14 = iVar14 + 1) {
                              puVar4 = (undefined4 *)sk_value(section_00,iVar14);
                              pcVar12 = (char *)puVar4[1];
                              iVar8 = strcmp(pcVar12,DAT_000ca234);
                              if (iVar8 == 0) {
                                str = ASN1_STRING_type_new(0x1a);
                                pAVar2->ln = (char **)str;
                                if (str == (ASN1_STRING *)0x0) goto LAB_000ca250;
LAB_000ca156:
                                pcVar12 = (char *)puVar4[2];
                                sVar6 = strlen(pcVar12);
                                iVar8 = ASN1_STRING_set(str,pcVar12,sVar6);
                                if (iVar8 == 0) goto LAB_000ca250;
                              }
                              else {
                                iVar8 = strcmp(pcVar12,DAT_000ca238);
                                if (iVar8 == 0) {
                                  ppAVar7 = (ASN1_STRING **)pAVar2->sn;
                                  if (ppAVar7 == (ASN1_STRING **)0x0) {
                                    ppAVar7 = (ASN1_STRING **)ASN1_item_new(DAT_000ca4c0);
                                    if (ppAVar7 == (ASN1_STRING **)0x0) goto LAB_000ca250;
                                    pAVar2->sn = (char *)ppAVar7;
                                  }
                                  str = *ppAVar7;
                                  if (bVar1) {
                                    str->type = 0x16;
                                  }
                                  else {
                                    str->type = 0x1a;
                                  }
                                  goto LAB_000ca156;
                                }
                                iVar8 = strcmp(pcVar12,DAT_000ca23c);
                                if (iVar8 != 0) {
                                  iVar14 = 0x15b;
                                  iVar3 = 0x8a;
LAB_000ca2dc:
                                  ERR_put_error(0x22,0x84,iVar3,DAT_000ca4b0,iVar14);
                                  ERR_add_error_data(6,DAT_000ca4c8,*puVar4,DAT_000ca4cc,puVar4[1],
                                                     DAT_000ca4c4,puVar4[2]);
                                  goto LAB_000ca262;
                                }
                                pAVar13 = (ASN1_VALUE *)pAVar2->sn;
                                if (pAVar13 == (ASN1_VALUE *)0x0) {
                                  pAVar13 = ASN1_item_new(DAT_000ca4c0);
                                  if (pAVar13 != (ASN1_VALUE *)0x0) {
                                    pAVar2->sn = (char *)pAVar13;
                                    st_01 = &X509V3_parse_list((char *)puVar4[2])->stack;
                                    if (st_01 != (_STACK *)0x0) goto LAB_000ca1c2;
LAB_000ca2d0:
                                    iVar3 = 0x8d;
                                    iVar14 = 0x152;
                                    goto LAB_000ca2dc;
                                  }
                                  goto LAB_000ca250;
                                }
                                st_01 = &X509V3_parse_list((char *)puVar4[2])->stack;
                                if (st_01 == (_STACK *)0x0) goto LAB_000ca2d0;
LAB_000ca1c2:
                                iVar8 = sk_num(st_01);
                                if (iVar8 == 0) goto LAB_000ca2d0;
                                st_02 = *(_STACK **)(pAVar13 + 4);
                                iVar8 = 0;
LAB_000ca1f0:
                                iVar10 = sk_num(st_01);
                                if (iVar8 < iVar10) {
                                  pvVar9 = sk_value(st_01,iVar8);
                                  data = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                          *(char **)((int)pvVar9 + 4));
                                  if (data != (ASN1_INTEGER *)0x0) goto code_r0x000ca1e8;
                                  ERR_put_error(0x22,0x85,0x8c,DAT_000ca4b0,0x17c);
                                  goto LAB_000ca28c;
                                }
                                sk_pop_free(st_01,DAT_000ca224);
                              }
                            }
                            piVar11 = (int *)pAVar2->sn;
                            if ((piVar11 == (int *)0x0) || ((piVar11[1] != 0 && (*piVar11 != 0)))) {
                              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section_00);
                              pAVar2 = val[1];
                              if (pAVar2 == (ASN1_OBJECT *)0x0) {
                                pAVar2 = (ASN1_OBJECT *)sk_new_null();
                                val[1] = pAVar2;
                              }
                              iVar14 = sk_push((_STACK *)pAVar2,ppAVar5);
                              if (iVar14 != 0) goto LAB_000ca018;
                              goto LAB_000ca09c;
                            }
                            ERR_put_error(0x22,0x84,0x8e,DAT_000ca4b0,0x164);
                          }
                        }
LAB_000ca262:
                        ASN1_item_free((ASN1_VALUE *)ppAVar5,DAT_000ca4b4);
                        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section_00);
                        goto LAB_000ca0ae;
                      }
                      iVar14 = 0xfc;
                      iVar3 = 0x87;
                    }
                    else {
                      iVar14 = 0xf6;
                      iVar3 = 0x89;
                    }
                  }
                  else {
                    iVar14 = 0x10a;
                    iVar3 = 0x8a;
                  }
LAB_000ca3d4:
                  ERR_put_error(0x22,0x83,iVar3,DAT_000ca4b0,iVar14);
                  ERR_add_error_data(6,DAT_000ca4c8,*puVar4,DAT_000ca4cc,puVar4[1],DAT_000ca4c4,
                                     puVar4[2]);
                  goto LAB_000ca0ae;
                }
                if (val[1] == (ASN1_OBJECT *)0x0) {
                  pAVar2 = (ASN1_OBJECT *)sk_new_null();
                  val[1] = pAVar2;
                }
                ppAVar5 = (ASN1_OBJECT **)ASN1_item_new(DAT_000ca21c);
                if ((ppAVar5 == (ASN1_OBJECT **)0x0) ||
                   (iVar14 = sk_push((_STACK *)val[1],ppAVar5), iVar14 == 0)) goto LAB_000ca09c;
                pAVar2 = OBJ_nid2obj(0xa4);
                *ppAVar5 = pAVar2;
                if (pAVar2 == (ASN1_OBJECT *)0x0) {
                  ERR_put_error(0x22,0x83,0x44,DAT_000ca4b0,0xea);
                  goto LAB_000ca0ae;
                }
                pAVar2 = (ASN1_OBJECT *)ASN1_STRING_type_new(0x16);
                ppAVar5[1] = pAVar2;
                if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_000ca09c;
                pcVar12 = (char *)puVar4[2];
                sVar6 = strlen(pcVar12);
                iVar14 = ASN1_STRING_set((ASN1_STRING *)pAVar2,pcVar12,sVar6);
                if (iVar14 == 0) goto LAB_000ca09c;
              }
LAB_000ca018:
            }
            if (*val != (ASN1_OBJECT *)0x0) {
              X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
              iVar3 = sk_push(st,val);
              if (iVar3 == 0) goto LAB_000ca398;
              goto LAB_000c9fa6;
            }
            ERR_put_error(0x22,0x83,0x8b,DAT_000ca4b0,0x111);
          }
LAB_000ca0ae:
          ASN1_item_free((ASN1_VALUE *)val,DAT_000ca20c);
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
          goto LAB_000ca0be;
        }
        iVar14 = 0xac;
        iVar3 = 0x87;
      }
      else {
        iVar3 = 0x86;
        iVar14 = 0xa0;
      }
LAB_000ca34e:
      ERR_put_error(0x22,0x82,iVar3,DAT_000ca4b0,iVar14);
      ERR_add_error_data(6,DAT_000ca4c8,*puVar4,DAT_000ca4cc,puVar4[1],DAT_000ca4c4,puVar4[2]);
      goto LAB_000ca0be;
    }
    ERR_put_error(0x22,0x82,0x22,DAT_000ca4b0,0x98);
LAB_000ca0be:
    sk_pop_free(st_00,DAT_000ca224);
    sk_pop_free(st,DAT_000ca228);
  }
  return (_STACK *)0x0;
code_r0x000ca1e8:
  iVar10 = sk_push(st_02,data);
  iVar8 = iVar8 + 1;
  if (iVar10 == 0) {
    ERR_put_error(0x22,0x85,0x41,DAT_000ca4b0,0x185);
LAB_000ca28c:
    sk_pop_free(st_02,DAT_000ca4b8);
    sk_pop_free(st_01,DAT_000ca4bc);
    goto LAB_000ca262;
  }
  goto LAB_000ca1f0;
}

