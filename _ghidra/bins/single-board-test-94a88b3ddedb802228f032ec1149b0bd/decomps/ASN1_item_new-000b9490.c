
ASN1_VALUE * ASN1_item_new(ASN1_ITEM *it)

{
  int iVar1;
  ASN1_VALUE *local_c;
  
  local_c = (ASN1_VALUE *)0x0;
  iVar1 = asn1_item_ex_combine_new(&local_c,it,0);
  if (iVar1 < 1) {
    local_c = (ASN1_VALUE *)0x0;
  }
  return local_c;
}

