
int PKCS7_stream(uchar ***boundary,PKCS7 *p7)

{
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  switch(iVar1) {
  case 0x15:
    pAVar2 = (p7->d).data;
    break;
  case 0x16:
    pAVar2 = (((p7->d).sign)->contents->d).data;
    break;
  case 0x17:
    pAVar2 = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (pAVar2 != (ASN1_OCTET_STRING *)0x0) goto LAB_001531c4;
    pAVar2 = ASN1_OCTET_STRING_new();
    ((p7->d).enveloped)->enc_data->enc_data = pAVar2;
    break;
  case 0x18:
    pAVar2 = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (pAVar2 != (ASN1_OCTET_STRING *)0x0) goto LAB_001531c4;
    pAVar2 = ASN1_OCTET_STRING_new();
    ((p7->d).signed_and_enveloped)->enc_data->enc_data = pAVar2;
    break;
  default:
    goto switchD_001531a6_default;
  }
  if (pAVar2 != (ASN1_OCTET_STRING *)0x0) {
LAB_001531c4:
    pAVar2->flags = pAVar2->flags | 0x10;
    *boundary = &pAVar2->data;
    return 1;
  }
switchD_001531a6_default:
  return 0;
}

