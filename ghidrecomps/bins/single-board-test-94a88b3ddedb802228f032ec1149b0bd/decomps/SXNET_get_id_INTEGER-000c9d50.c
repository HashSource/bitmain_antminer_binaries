
ASN1_OCTET_STRING * SXNET_get_id_INTEGER(SXNET *sx,ASN1_INTEGER *zone)

{
  ASN1_STRING **ppAVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = sk_num(&sx->ids->stack);
    if (iVar2 <= iVar3) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    ppAVar1 = (ASN1_STRING **)sk_value(&sx->ids->stack,iVar3);
    iVar2 = ASN1_STRING_cmp(*ppAVar1,zone);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  return ppAVar1[1];
}

