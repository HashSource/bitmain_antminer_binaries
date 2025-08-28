
ASN1_TYPE * PKCS7_get_signed_attribute(PKCS7_SIGNER_INFO *si,int nid)

{
  ASN1_OBJECT *b;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  _STACK *p_Var5;
  
  p_Var5 = &si->auth_attr->stack;
  b = OBJ_nid2obj(nid);
  if (p_Var5 != (_STACK *)0x0 && b != (ASN1_OBJECT *)0x0) {
    iVar3 = 0;
    do {
      iVar2 = sk_num(p_Var5);
      if (iVar2 <= iVar3) {
        return (ASN1_TYPE *)0x0;
      }
      puVar1 = (undefined4 *)sk_value(p_Var5,iVar3);
      iVar2 = OBJ_cmp((ASN1_OBJECT *)*puVar1,b);
      iVar3 = iVar3 + 1;
    } while (iVar2 != 0);
    if ((puVar1[1] == 0) && (iVar3 = sk_num((_STACK *)puVar1[2]), iVar3 != 0)) {
      pAVar4 = (ASN1_TYPE *)sk_value((_STACK *)puVar1[2],0);
      return pAVar4;
    }
  }
  return (ASN1_TYPE *)0x0;
}

