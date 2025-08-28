
ASN1_OCTET_STRING * SXNET_get_id_asc(SXNET *sx,char *zone)

{
  ASN1_INTEGER *b;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  ASN1_OCTET_STRING *pAVar4;
  
  b = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,zone);
  iVar3 = 0;
  if (b == (ASN1_INTEGER *)0x0) {
    ERR_put_error(0x22,0x80,0x83,"v3_sxnet.c",0xed);
    pAVar4 = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    do {
      iVar2 = sk_num(&sx->ids->stack);
      if (iVar2 <= iVar3) {
        pAVar4 = (ASN1_OCTET_STRING *)0x0;
        goto LAB_000c9cb8;
      }
      puVar1 = (undefined4 *)sk_value(&sx->ids->stack,iVar3);
      iVar2 = ASN1_STRING_cmp((ASN1_STRING *)*puVar1,b);
      iVar3 = iVar3 + 1;
    } while (iVar2 != 0);
    pAVar4 = (ASN1_OCTET_STRING *)puVar1[1];
LAB_000c9cb8:
    ASN1_STRING_free(b);
  }
  return pAVar4;
}

