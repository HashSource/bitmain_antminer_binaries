
int ASN1_TYPE_set1(ASN1_TYPE *a,int type,void *value)

{
  ASN1_STRING *pAVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  ASN1_BOOLEAN AVar4;
  ASN1_TYPE *local_24;
  ASN1_TYPE *local_20;
  ASN1_TYPE *local_1c [2];
  
  if (value == (void *)0x0 || type == 1) {
    if ((a->value).ptr != (char *)0x0) {
      local_24 = a;
      ASN1_primitive_free((ASN1_VALUE **)&local_24,(ASN1_ITEM *)0x0);
      a = local_24;
    }
    a->type = type;
    if (type == 1) {
      if (value == (void *)0x0) {
        AVar4 = 0;
      }
      else {
        AVar4 = 0xff;
      }
      iVar3 = 1;
      (a->value).boolean = AVar4;
    }
    else {
      (a->value).ptr = (char *)value;
      iVar3 = 1;
    }
  }
  else {
    if (type == 6) {
      pAVar2 = OBJ_dup((ASN1_OBJECT *)value);
      if (pAVar2 != (ASN1_OBJECT *)0x0) {
        if ((a->value).ptr != (char *)0x0) {
          local_20 = a;
          ASN1_primitive_free((ASN1_VALUE **)&local_20,(ASN1_ITEM *)0x0);
          a = local_20;
        }
        a->type = 6;
        (a->value).object = pAVar2;
        return 1;
      }
    }
    else {
      pAVar1 = ASN1_STRING_dup((ASN1_STRING *)value);
      if (pAVar1 != (ASN1_STRING *)0x0) {
        if ((a->value).ptr != (char *)0x0) {
          local_1c[0] = a;
          ASN1_primitive_free((ASN1_VALUE **)local_1c,(ASN1_ITEM *)0x0);
          a = local_1c[0];
        }
        a->type = type;
        (a->value).asn1_string = pAVar1;
        return 1;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}

