
stack_st_OPENSSL_STRING * X509_get1_ocsp(X509 *x)

{
  _STACK *a;
  int iVar1;
  undefined4 *puVar2;
  char *data;
  void *data_00;
  int iVar3;
  int *piVar4;
  _STACK *st;
  _STACK *p_Var5;
  
  a = (_STACK *)X509_get_ext_d2i(x,0xb1,(int *)0x0,(int *)0x0);
  if (a == (_STACK *)0x0) {
    p_Var5 = (_STACK *)0x0;
  }
  else {
    p_Var5 = (_STACK *)0x0;
    for (iVar3 = 0; iVar1 = sk_num(a), iVar3 < iVar1; iVar3 = iVar3 + 1) {
      puVar2 = (undefined4 *)sk_value(a,iVar3);
      iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*puVar2);
      st = p_Var5;
      if ((((iVar1 == 0xb2) && (*(int *)puVar2[1] == 6)) &&
          (piVar4 = (int *)((int *)puVar2[1])[1], piVar4[1] == 0x16)) &&
         ((data_00 = (void *)piVar4[2], data_00 != (void *)0x0 && (*piVar4 != 0)))) {
        if (p_Var5 == (_STACK *)0x0) {
          p_Var5 = sk_new((cmp *)0x167935);
          if (p_Var5 == (_STACK *)0x0) break;
          data_00 = (void *)piVar4[2];
          st = p_Var5;
        }
        iVar1 = sk_find(st,data_00);
        if ((iVar1 == -1) &&
           ((data = BUF_strdup((char *)piVar4[2]), data == (char *)0x0 ||
            (iVar1 = sk_push(st,data), iVar1 == 0)))) {
          p_Var5 = (_STACK *)0x0;
          sk_pop_free(st,(func *)0x167905);
          break;
        }
      }
      p_Var5 = st;
    }
    AUTHORITY_INFO_ACCESS_free((AUTHORITY_INFO_ACCESS *)a);
  }
  return (stack_st_OPENSSL_STRING *)p_Var5;
}

