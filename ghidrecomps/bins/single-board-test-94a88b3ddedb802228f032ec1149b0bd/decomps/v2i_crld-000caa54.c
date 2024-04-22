
_STACK * v2i_crld(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  undefined4 *puVar1;
  int iVar2;
  CONF_VALUE *cnf;
  _STACK *p_Var3;
  ASN1_VALUE *val;
  int iVar4;
  void *pvVar5;
  _STACK *p_Var6;
  GENERAL_NAMES *pGVar7;
  int iVar8;
  char *pcVar9;
  _STACK *local_38;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    p_Var3 = (_STACK *)0x0;
    p_Var6 = (_STACK *)0x0;
LAB_000cabb4:
    ERR_put_error(0x22,0x86,0x41,DAT_000cac70,0x150);
LAB_000cabc6:
    GENERAL_NAME_free((GENERAL_NAME *)p_Var6);
    GENERAL_NAMES_free((GENERAL_NAMES *)p_Var3);
    local_38 = (_STACK *)0x0;
    sk_pop_free(st,DAT_000cac74);
  }
  else {
    for (iVar8 = 0; iVar2 = sk_num(param_3), local_38 = st, iVar8 < iVar2; iVar8 = iVar8 + 1) {
      cnf = (CONF_VALUE *)sk_value(param_3,iVar8);
      if (cnf->value == (char *)0x0) {
        p_Var3 = &X509V3_get_section(param_2,cnf->name)->stack;
        if (p_Var3 == (_STACK *)0x0) {
LAB_000cac24:
          p_Var3 = (_STACK *)0x0;
          p_Var6 = p_Var3;
          goto LAB_000cabc6;
        }
        val = ASN1_item_new(DAT_000cac5c);
        if (val == (ASN1_VALUE *)0x0) {
LAB_000cab94:
          X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var3);
          p_Var3 = (_STACK *)0x0;
          p_Var6 = (_STACK *)0x0;
          goto LAB_000cabc6;
        }
        for (iVar2 = 0; iVar4 = sk_num(p_Var3), iVar2 < iVar4; iVar2 = iVar2 + 1) {
          pvVar5 = sk_value(p_Var3,iVar2);
          iVar4 = set_dist_point_name(val,param_2,pvVar5);
          if (0 < iVar4) goto LAB_000cab10;
          if (iVar4 != 0) {
LAB_000cab8c:
            ASN1_item_free(val,DAT_000cac5c);
            goto LAB_000cab94;
          }
          pcVar9 = *(char **)((int)pvVar5 + 4);
          iVar4 = strcmp(pcVar9,DAT_000cac64);
          if (iVar4 == 0) {
            iVar4 = set_reasons(val + 4,*(undefined4 *)((int)pvVar5 + 8));
            if (iVar4 == 0) goto LAB_000cab8c;
          }
          else {
            iVar4 = strcmp(pcVar9,DAT_000cac68);
            if (iVar4 == 0) {
              pcVar9 = *(char **)((int)pvVar5 + 8);
              if (*pcVar9 == '@') {
                p_Var6 = &X509V3_get_section(param_2,pcVar9 + 1)->stack;
              }
              else {
                p_Var6 = &X509V3_parse_list(pcVar9)->stack;
              }
              if (p_Var6 == (_STACK *)0x0) {
                ERR_put_error(0x22,0x9c,0x96,DAT_000cac70,0x66);
                *(undefined4 *)(val + 8) = 0;
              }
              else {
                pGVar7 = v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,
                                           (stack_st_CONF_VALUE *)p_Var6);
                if (*pcVar9 == '@') {
                  X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var6);
                }
                else {
                  sk_pop_free(p_Var6,DAT_000cac6c);
                }
                *(GENERAL_NAMES **)(val + 8) = pGVar7;
                if (pGVar7 != (GENERAL_NAMES *)0x0) goto LAB_000cab10;
              }
              goto LAB_000cab8c;
            }
          }
LAB_000cab10:
        }
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var3);
        iVar2 = sk_push(st,val);
        if (iVar2 == 0) {
          ASN1_item_free(val,DAT_000cac5c);
          p_Var3 = (_STACK *)0x0;
          p_Var6 = (_STACK *)0x0;
          goto LAB_000cabb4;
        }
      }
      else {
        p_Var6 = (_STACK *)v2i_GENERAL_NAME(param_1,param_2,cnf);
        if (p_Var6 == (_STACK *)0x0) goto LAB_000cac24;
        p_Var3 = &GENERAL_NAMES_new()->stack;
        if (((p_Var3 == (_STACK *)0x0) || (iVar2 = sk_push(p_Var3,p_Var6), iVar2 == 0)) ||
           (p_Var6 = (_STACK *)ASN1_item_new(DAT_000cac5c), p_Var6 == (_STACK *)0x0))
        goto LAB_000cabb4;
        iVar2 = sk_push(st,p_Var6);
        if (iVar2 == 0) {
          ASN1_item_free((ASN1_VALUE *)p_Var6,DAT_000cac5c);
          p_Var6 = (_STACK *)0x0;
          goto LAB_000cabb4;
        }
        puVar1 = (undefined4 *)ASN1_item_new(DAT_000cac60);
        p_Var6->num = (int)puVar1;
        if (puVar1 == (undefined4 *)0x0) {
          p_Var6 = (_STACK *)0x0;
          goto LAB_000cabb4;
        }
        puVar1[1] = p_Var3;
        *puVar1 = 0;
      }
    }
  }
  return local_38;
}

