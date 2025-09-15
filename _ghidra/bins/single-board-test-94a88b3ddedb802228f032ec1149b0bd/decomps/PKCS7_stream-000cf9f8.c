
int PKCS7_stream(uchar ***boundary,PKCS7 *p7)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  ASN1_STRING *pAVar3;
  
  iVar1 = OBJ_obj2nid(p7->type);
  switch(iVar1) {
  case 0x15:
    pAVar2 = (p7->d).data;
    break;
  case 0x16:
    pAVar2 = (((p7->d).sign)->contents->d).data;
    break;
  case 0x17:
    pAVar3 = (ASN1_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (pAVar3 == (ASN1_STRING *)0x0) {
      pAVar2 = ASN1_STRING_type_new(4);
      ((p7->d).enveloped)->enc_data->enc_data = pAVar2;
      break;
    }
    goto LAB_000cfa48;
  case 0x18:
    pAVar3 = (ASN1_STRING *)((p7->d).sign)->contents->state;
    if (pAVar3 != (ASN1_STRING *)0x0) goto LAB_000cfa48;
    pAVar2 = ASN1_STRING_type_new(4);
    ((p7->d).signed_and_enveloped)->enc_data->enc_data = pAVar2;
    break;
  default:
    return 0;
  }
  pAVar3 = pAVar2;
  if (pAVar2 != (ASN1_STRING *)0x0) {
LAB_000cfa48:
    pAVar2 = (ASN1_STRING *)0x1;
    pAVar3->flags = pAVar3->flags | 0x10;
    *boundary = &pAVar3->data;
  }
  return (int)pAVar2;
}

