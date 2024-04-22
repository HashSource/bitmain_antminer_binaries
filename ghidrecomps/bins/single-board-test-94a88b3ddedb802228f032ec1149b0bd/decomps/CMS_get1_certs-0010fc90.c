
stack_st_X509 * CMS_get1_certs(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  _STACK **pp_Var5;
  _STACK *st;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    pp_Var5 = (_STACK **)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,DAT_0010fd30,0x1a4);
      return (stack_st_X509 *)0x0;
    }
    pp_Var5 = *(_STACK ***)(*(int *)(cms + 4) + 4);
  }
  if (pp_Var5 == (_STACK **)0x0) {
LAB_0010fd1a:
    st = (_STACK *)0x0;
  }
  else {
    st = (_STACK *)0x0;
    iVar1 = 0;
    while( true ) {
      iVar2 = sk_num(*pp_Var5);
      iVar4 = iVar1 + 1;
      if (iVar2 <= iVar1) break;
      piVar3 = (int *)sk_value(*pp_Var5,iVar1);
      iVar1 = iVar4;
      if (*piVar3 == 0) {
        if ((st == (_STACK *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) goto LAB_0010fd1a;
        iVar2 = sk_push(st,(void *)piVar3[1]);
        if (iVar2 == 0) {
          sk_pop_free(st,DAT_0010fd34);
          return (stack_st_X509 *)0x0;
        }
        CRYPTO_add_lock((int *)(piVar3[1] + 0x10),1,3,DAT_0010fd30,0x233);
      }
    }
  }
  return (stack_st_X509 *)st;
}

