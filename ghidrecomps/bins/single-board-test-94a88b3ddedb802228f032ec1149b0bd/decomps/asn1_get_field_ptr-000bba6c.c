
ASN1_VALUE ** asn1_get_field_ptr(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  if (-1 < (int)(tt->flags << 0x15)) {
    pval = (ASN1_VALUE **)(*pval + tt->offset);
  }
  return pval;
}

