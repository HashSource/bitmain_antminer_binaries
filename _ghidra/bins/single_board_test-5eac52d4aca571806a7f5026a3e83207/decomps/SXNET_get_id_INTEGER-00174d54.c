
ASN1_OCTET_STRING * SXNET_get_id_INTEGER(SXNET *sx,ASN1_INTEGER *zone)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = OPENSSL_sk_num(sx->ids);
    if (iVar2 <= iVar3) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    puVar1 = (undefined4 *)OPENSSL_sk_value(sx->ids,iVar3);
    iVar2 = ASN1_INTEGER_cmp((ASN1_INTEGER *)*puVar1,zone);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  return (ASN1_OCTET_STRING *)puVar1[1];
}

