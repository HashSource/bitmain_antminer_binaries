
char * PKCS12_get_friendlyname(PKCS12_SAFEBAG *bag)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  _STACK *p_Var6;
  
  p_Var6 = &bag->attrib->stack;
  if (p_Var6 != (_STACK *)0x0) {
    iVar3 = 0;
    do {
      iVar2 = sk_num(p_Var6);
      if (iVar2 <= iVar3) {
        return (char *)0x0;
      }
      ppAVar1 = (ASN1_OBJECT **)sk_value(p_Var6,iVar3);
      iVar2 = OBJ_obj2nid(*ppAVar1);
      iVar3 = iVar3 + 1;
    } while (iVar2 != 0x9c);
    iVar3 = sk_num((_STACK *)ppAVar1[2]);
    if (((iVar3 != 0) && (piVar4 = (int *)sk_value((_STACK *)ppAVar1[2],0), piVar4 != (int *)0x0))
       && (*piVar4 == 0x1e)) {
      pcVar5 = OPENSSL_uni2asc((uchar *)((int *)piVar4[1])[2],*(int *)piVar4[1]);
      return pcVar5;
    }
  }
  return (char *)0x0;
}

