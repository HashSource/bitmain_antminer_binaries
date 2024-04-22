
_STACK ** v2i_NAME_CONSTRAINTS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK **val;
  GENERAL_NAME **val_00;
  GENERAL_NAME *pGVar1;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  char *__s1;
  int iVar4;
  _STACK **pp_Var5;
  CONF_VALUE CStack_34;
  
  val = (_STACK **)ASN1_item_new(DAT_000ccc04);
  if (val == (_STACK **)0x0) {
    ERR_put_error(0x22,0x93,0x41,DAT_000ccc14,0x93);
  }
  else {
    for (iVar4 = 0; iVar2 = sk_num(param_3), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      pvVar3 = sk_value(param_3,iVar4);
      __s1 = *(char **)((int)pvVar3 + 4);
      iVar2 = strncmp(__s1,DAT_000ccc0c,9);
      if ((iVar2 == 0) && (__s1[9] != '\0')) {
        CStack_34.name = __s1 + 10;
        pp_Var5 = val;
      }
      else {
        iVar2 = strncmp(__s1,DAT_000ccc10,8);
        if ((iVar2 != 0) || (__s1[8] == '\0')) {
          val_00 = (GENERAL_NAME **)0x0;
          ERR_put_error(0x22,0x93,0x8f,DAT_000ccc14,0x82);
          goto LAB_000ccbcc;
        }
        CStack_34.name = __s1 + 9;
        pp_Var5 = val + 1;
      }
      CStack_34.value = *(char **)((int)pvVar3 + 8);
      val_00 = (GENERAL_NAME **)ASN1_item_new(DAT_000ccc08);
      pGVar1 = v2i_GENERAL_NAME_ex(*val_00,param_1,param_2,&CStack_34,1);
      if (pGVar1 == (GENERAL_NAME *)0x0) goto LAB_000ccbcc;
      st = *pp_Var5;
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        *pp_Var5 = st;
        if (st != (_STACK *)0x0) goto LAB_000ccb5a;
LAB_000ccbf2:
        ERR_put_error(0x22,0x93,0x41,DAT_000ccc14,0x93);
LAB_000ccbcc:
        ASN1_item_free((ASN1_VALUE *)val,DAT_000ccc04);
        if (val_00 == (GENERAL_NAME **)0x0) {
          return (_STACK **)0x0;
        }
        ASN1_item_free((ASN1_VALUE *)val_00,DAT_000ccc08);
        return (_STACK **)0x0;
      }
LAB_000ccb5a:
      iVar2 = sk_push(st,val_00);
      if (iVar2 == 0) goto LAB_000ccbf2;
    }
  }
  return val;
}

