
ASN1_TYPE * ASN1_TYPE_pack_sequence(ASN1_ITEM *param_1,void *param_2,int *param_3)

{
  ASN1_STRING *a;
  ASN1_TYPE *a_00;
  
  a = ASN1_item_pack(param_2,param_1,(ASN1_OCTET_STRING **)0x0);
  if (a != (ASN1_STRING *)0x0) {
    if (param_3 == (int *)0x0) {
      a_00 = ASN1_TYPE_new();
      if (a_00 != (ASN1_TYPE *)0x0) goto LAB_001056aa;
    }
    else {
      a_00 = (ASN1_TYPE *)*param_3;
      if (a_00 != (ASN1_TYPE *)0x0) {
LAB_001056aa:
        ASN1_TYPE_set(a_00,0x10,a);
        return a_00;
      }
      a_00 = ASN1_TYPE_new();
      if (a_00 != (ASN1_TYPE *)0x0) {
        *param_3 = (int)a_00;
        goto LAB_001056aa;
      }
    }
    ASN1_OCTET_STRING_free(a);
  }
  return (ASN1_TYPE *)0x0;
}

