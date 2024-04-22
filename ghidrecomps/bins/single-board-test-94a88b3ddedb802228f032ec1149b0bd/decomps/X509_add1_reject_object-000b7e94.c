
int X509_add1_reject_object(X509 *x,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *data;
  _STACK *st;
  int iVar1;
  ASN1_VALUE *pAVar2;
  
  data = OBJ_dup(obj);
  if ((data != (ASN1_OBJECT *)0x0) && (x != (X509 *)0x0)) {
    pAVar2 = *(ASN1_VALUE **)(x->sha1_hash + 0xc);
    if (pAVar2 == (ASN1_VALUE *)0x0) {
      pAVar2 = ASN1_item_new(DAT_000b7ed4);
      *(ASN1_VALUE **)(x->sha1_hash + 0xc) = pAVar2;
      if (pAVar2 == (ASN1_VALUE *)0x0) {
        return 0;
      }
    }
    st = *(_STACK **)(pAVar2 + 4);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(pAVar2 + 4) = st;
      if (st == (_STACK *)0x0) {
        return 0;
      }
    }
    iVar1 = sk_push(st,data);
    return iVar1;
  }
  return 0;
}

