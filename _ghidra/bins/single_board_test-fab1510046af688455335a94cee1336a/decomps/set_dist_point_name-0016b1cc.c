
undefined4 set_dist_point_name(int *param_1,X509V3_CTX *param_2,int param_3)

{
  int iVar1;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  void *pvVar2;
  ASN1_VALUE *pAVar3;
  char *pcVar4;
  _STACK *st;
  _STACK *p_Var5;
  
  pcVar4 = *(char **)(param_3 + 4);
  iVar1 = strcmp(pcVar4,"fullname");
  if (iVar1 == 0) {
    pcVar4 = *(char **)(param_3 + 8);
    if (*pcVar4 == '@') {
      p_Var5 = &X509V3_get_section(param_2,pcVar4 + 1)->stack;
    }
    else {
      p_Var5 = &X509V3_parse_list(pcVar4)->stack;
    }
    if (p_Var5 == (_STACK *)0x0) {
      ERR_put_error(0x22,0x9c,0x96,"v3_crld.c",0x66);
      return 0xffffffff;
    }
    st = &v2i_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,param_2,(stack_st_CONF_VALUE *)p_Var5)->stack;
    if (*pcVar4 == '@') {
      X509V3_section_free(param_2,(stack_st_CONF_VALUE *)p_Var5);
    }
    else {
      sk_pop_free(p_Var5,(func *)0x167909);
    }
    if (st == (_STACK *)0x0) {
      return 0xffffffff;
    }
    p_Var5 = (_STACK *)0x0;
  }
  else {
    iVar1 = strcmp(pcVar4,"relativename");
    if (iVar1 != 0) {
      return 0;
    }
    nm = X509_NAME_new();
    if (nm == (X509_NAME *)0x0) {
      return 0xffffffff;
    }
    dn_sk = X509V3_get_section(param_2,*(char **)(param_3 + 8));
    if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
      ERR_put_error(0x22,0x9e,0x96,"v3_crld.c",0x84);
      return 0xffffffff;
    }
    iVar1 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
    X509V3_section_free(param_2,dn_sk);
    p_Var5 = &nm->entries->stack;
    nm->entries = (stack_st_X509_NAME_ENTRY *)0x0;
    X509_NAME_free(nm);
    if ((iVar1 == 0) || (iVar1 = sk_num(p_Var5), iVar1 < 1)) goto joined_r0x0016b2a4;
    iVar1 = sk_num(p_Var5);
    pvVar2 = sk_value(p_Var5,iVar1 + -1);
    st = *(_STACK **)((int)pvVar2 + 8);
    if (st != (_STACK *)0x0) {
      ERR_put_error(0x22,0x9e,0xa1,"v3_crld.c",0x94);
      goto joined_r0x0016b2a4;
    }
  }
  if (*param_1 == 0) {
    pAVar3 = ASN1_item_new((ASN1_ITEM *)DIST_POINT_NAME_it);
    *param_1 = (int)pAVar3;
    if (pAVar3 != (ASN1_VALUE *)0x0) {
      if (st == (_STACK *)0x0) {
        *(undefined4 *)pAVar3 = 1;
        *(_STACK **)(pAVar3 + 4) = p_Var5;
        return 1;
      }
      *(undefined4 *)pAVar3 = 0;
      *(_STACK **)(pAVar3 + 4) = st;
      return 1;
    }
  }
  else {
    ERR_put_error(0x22,0x9e,0xa0,"v3_crld.c",0x9c);
  }
  if (st != (_STACK *)0x0) {
    sk_pop_free(st,(func *)0x169121);
  }
joined_r0x0016b2a4:
  if (p_Var5 == (_STACK *)0x0) {
    return 0xffffffff;
  }
  sk_pop_free(p_Var5,(func *)0x159e31);
  return 0xffffffff;
}

