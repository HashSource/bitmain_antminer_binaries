
ASN1_VALUE ** asn1_get_field_ptr(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  return (ASN1_VALUE **)(*pval + tt->offset);
}

