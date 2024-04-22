
stack_st_X509 * CMS_get0_signers(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  void *data;
  int iVar4;
  _STACK *p_Var5;
  _STACK *st;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    p_Var5 = *(_STACK **)(cms + 4);
    if (p_Var5 != (_STACK *)0x0) {
      p_Var5 = (_STACK *)p_Var5[1].num;
    }
  }
  else {
    ERR_put_error(0x2e,0x85,0x6c,DAT_00110424,0x48);
    p_Var5 = (_STACK *)0x0;
  }
  st = (_STACK *)0x0;
  iVar1 = 0;
  do {
    do {
      iVar2 = sk_num(p_Var5);
      iVar4 = iVar1 + 1;
      if (iVar2 <= iVar1) {
        return (stack_st_X509 *)st;
      }
      pvVar3 = sk_value(p_Var5,iVar1);
      data = *(void **)((int)pvVar3 + 0x1c);
      iVar1 = iVar4;
    } while (data == (void *)0x0);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      if (st == (_STACK *)0x0) {
        return (stack_st_X509 *)0x0;
      }
      data = *(void **)((int)pvVar3 + 0x1c);
    }
    iVar2 = sk_push(st,data);
  } while (iVar2 != 0);
  sk_free(st);
  return (stack_st_X509 *)0x0;
}

