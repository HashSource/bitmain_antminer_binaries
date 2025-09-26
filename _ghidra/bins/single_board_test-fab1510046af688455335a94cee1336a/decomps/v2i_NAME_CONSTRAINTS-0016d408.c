
ASN1_VALUE * v2i_NAME_CONSTRAINTS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  ASN1_VALUE *val;
  ASN1_VALUE *val_00;
  GENERAL_NAME *pGVar1;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  char *__s1;
  int iVar4;
  ASN1_VALUE *pAVar5;
  CONF_VALUE CStack_34;
  
  val = ASN1_item_new((ASN1_ITEM *)&NAME_CONSTRAINTS_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x22,0x93,0x41,"v3_ncons.c",0x93);
  }
  else {
    for (iVar4 = 0; iVar2 = sk_num(param_3), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      pvVar3 = sk_value(param_3,iVar4);
      __s1 = *(char **)((int)pvVar3 + 4);
      iVar2 = strncmp(__s1,"permitted",9);
      if ((iVar2 == 0) && (__s1[9] != '\0')) {
        CStack_34.name = __s1 + 10;
        pAVar5 = val;
      }
      else {
        iVar2 = strncmp(__s1,"excluded",8);
        if ((iVar2 != 0) || (__s1[8] == '\0')) {
          val_00 = (ASN1_VALUE *)0x0;
          ERR_put_error(0x22,0x93,0x8f,"v3_ncons.c",0x82);
          goto LAB_0016d4cc;
        }
        CStack_34.name = __s1 + 9;
        pAVar5 = val + 4;
      }
      CStack_34.value = *(char **)((int)pvVar3 + 8);
      val_00 = ASN1_item_new((ASN1_ITEM *)GENERAL_SUBTREE_it);
      pGVar1 = v2i_GENERAL_NAME_ex(*(GENERAL_NAME **)val_00,param_1,param_2,&CStack_34,1);
      if (pGVar1 == (GENERAL_NAME *)0x0) goto LAB_0016d4cc;
      st = *(_STACK **)pAVar5;
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        *(_STACK **)pAVar5 = st;
        if (st != (_STACK *)0x0) goto LAB_0016d45a;
LAB_0016d4f2:
        ERR_put_error(0x22,0x93,0x41,"v3_ncons.c",0x93);
LAB_0016d4cc:
        ASN1_item_free(val,(ASN1_ITEM *)&NAME_CONSTRAINTS_it);
        if (val_00 == (ASN1_VALUE *)0x0) {
          return (ASN1_VALUE *)0x0;
        }
        ASN1_item_free(val_00,(ASN1_ITEM *)GENERAL_SUBTREE_it);
        return (ASN1_VALUE *)0x0;
      }
LAB_0016d45a:
      iVar2 = sk_push(st,val_00);
      if (iVar2 == 0) goto LAB_0016d4f2;
    }
  }
  return val;
}

