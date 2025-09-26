
void * ASN1_TYPE_unpack_sequence(ASN1_ITEM *param_1,int *param_2)

{
  void *pvVar1;
  
  if (((param_2 != (int *)0x0) && (*param_2 == 0x10)) &&
     ((ASN1_STRING *)param_2[1] != (ASN1_STRING *)0x0)) {
    pvVar1 = ASN1_item_unpack((ASN1_STRING *)param_2[1],param_1);
    return pvVar1;
  }
  return (void *)0x0;
}

