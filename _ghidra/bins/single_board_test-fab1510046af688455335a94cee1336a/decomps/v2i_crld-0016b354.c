
_STACK * v2i_crld(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  int iVar1;
  CONF_VALUE *cnf;
  _STACK *p_Var2;
  ASN1_VALUE *pAVar3;
  int iVar4;
  void *pvVar5;
  _STACK *p_Var6;
  GENERAL_NAMES *pGVar7;
  int iVar8;
  char *pcVar9;
  _STACK *local_38;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    p_Var2 = (_STACK *)0x0;
    p_Var6 = (_STACK *)0x0;
LAB_0016b4b4:
    ERR_put_error(0x22,0x86,0x41,"v3_crld.c",0x150);
LAB_0016b4c6:
    GENERAL_NAME_free((GENERAL_NAME *)p_Var6);
    GENERAL_NAMES_free((GENERAL_NAMES *)p_Var2);
    local_38 = (_STACK *)0x0;
    sk_pop_free(st,(func *)0x16afed);
  }
  else {
    for (iVar8 = 0; iVar1 = sk_num(param_3), local_38 = st, iVar8 < iVar1; iVar8 = iVar8 + 1) {
      cnf = (CONF_VALUE *)sk_value(param_3,iVar8);
      if (cnf->value == (char *)0x0) {
        p_Var2 = &X509V3_get_section(param_2,cnf->name)->stack;
        if (p_Var2 == (_STACK *)0x0) {
LAB_0016b524:
          p_Var2 = (_STACK *)0x0;
          p_Var6 = p_Var2;
          goto LAB_0016b4c6;
        }
        pAVar3 = ASN1_item_new((ASN1_ITEM *)DIST_POINT_it);
        if (pAVar3 == (ASN1_VALUE *)0x0) {
LAB_0016b494:
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var2);
          p_Var2 = (_STACK *)0x0;
          p_Var6 = (_STACK *)0x0;
          goto LAB_0016b4c6;
        }
        for (iVar1 = 0; iVar4 = sk_num(p_Var2), iVar1 < iVar4; iVar1 = iVar1 + 1) {
          pvVar5 = sk_value(p_Var2,iVar1);
          iVar4 = set_dist_point_name(pAVar3,param_2,pvVar5);
          if (0 < iVar4) goto LAB_0016b410;
          if (iVar4 != 0) {
LAB_0016b48c:
            ASN1_item_free(pAVar3,(ASN1_ITEM *)DIST_POINT_it);
            goto LAB_0016b494;
          }
          pcVar9 = *(char **)((int)pvVar5 + 4);
          iVar4 = strcmp(pcVar9,"reasons");
          if (iVar4 == 0) {
            iVar4 = set_reasons(pAVar3 + 4,*(undefined4 *)((int)pvVar5 + 8));
            if (iVar4 == 0) goto LAB_0016b48c;
          }
          else {
            iVar4 = strcmp(pcVar9,"CRLissuer");
            if (iVar4 == 0) {
              pcVar9 = *(char **)((int)pvVar5 + 8);
              if (*pcVar9 == '@') {
                p_Var6 = &X509V3_get_section(param_2,pcVar9 + 1)->stack;
              }
              else {
                p_Var6 = &X509V3_parse_list(pcVar9)->stack;
              }
              if (p_Var6 == (_STACK *)0x0) {
                ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x66);
                *(undefined4 *)(pAVar3 + 8) = 0;
              }
              else {
                pGVar7 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,
                                           (stack_st_CONF_VALUE *)p_Var6);
                if (*pcVar9 == '@') {
                  X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var6);
                }
                else {
                  sk_pop_free(p_Var6,(func *)0x167909);
                }
                *(GENERAL_NAMES **)(pAVar3 + 8) = pGVar7;
                if (pGVar7 != (GENERAL_NAMES *)0x0) goto LAB_0016b410;
              }
              goto LAB_0016b48c;
            }
          }
LAB_0016b410:
        }
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var2);
        iVar1 = sk_push(st,pAVar3);
        if (iVar1 == 0) {
          ASN1_item_free(pAVar3,(ASN1_ITEM *)DIST_POINT_it);
          p_Var2 = (_STACK *)0x0;
          p_Var6 = (_STACK *)0x0;
          goto LAB_0016b4b4;
        }
      }
      else {
        p_Var6 = (_STACK *)v2i_GENERAL_NAME(param_1,param_2,cnf);
        if (p_Var6 == (_STACK *)0x0) goto LAB_0016b524;
        p_Var2 = &GENERAL_NAMES_new()->stack;
        if (((p_Var2 == (_STACK *)0x0) || (iVar1 = sk_push(p_Var2,p_Var6), iVar1 == 0)) ||
           (p_Var6 = (_STACK *)ASN1_item_new((ASN1_ITEM *)DIST_POINT_it), p_Var6 == (_STACK *)0x0))
        goto LAB_0016b4b4;
        iVar1 = sk_push(st,p_Var6);
        if (iVar1 == 0) {
          ASN1_item_free((ASN1_VALUE *)p_Var6,(ASN1_ITEM *)DIST_POINT_it);
          p_Var6 = (_STACK *)0x0;
          goto LAB_0016b4b4;
        }
        pAVar3 = ASN1_item_new((ASN1_ITEM *)DIST_POINT_NAME_it);
        p_Var6->num = (int)pAVar3;
        if (pAVar3 == (ASN1_VALUE *)0x0) {
          p_Var6 = (_STACK *)0x0;
          goto LAB_0016b4b4;
        }
        *(_STACK **)(pAVar3 + 4) = p_Var2;
        *(undefined4 *)pAVar3 = 0;
      }
    }
  }
  return local_38;
}

