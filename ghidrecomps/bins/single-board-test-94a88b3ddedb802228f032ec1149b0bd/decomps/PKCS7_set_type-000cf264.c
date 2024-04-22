
int PKCS7_set_type(PKCS7 *p7,int type)

{
  ASN1_OBJECT *pAVar1;
  PKCS7_ENCRYPT *pPVar2;
  int iVar3;
  ASN1_STRING *pAVar4;
  PKCS7_SIGNED *pPVar5;
  PKCS7_ENVELOPE *pPVar6;
  PKCS7_SIGN_ENVELOPE *pPVar7;
  PKCS7_DIGEST *pPVar8;
  PKCS7_ENC_CONTENT *pPVar9;
  X509_ALGOR *pXVar10;
  
  pAVar1 = OBJ_nid2obj(type);
  switch(type) {
  case 0x15:
    p7->type = pAVar1;
    pAVar4 = ASN1_STRING_type_new(4);
    (p7->d).data = pAVar4;
    if (pAVar4 == (ASN1_STRING *)0x0) {
      return 0;
    }
    return 1;
  case 0x16:
    p7->type = pAVar1;
    pPVar5 = PKCS7_SIGNED_new();
    (p7->d).sign = pPVar5;
    if (pPVar5 != (PKCS7_SIGNED *)0x0) {
      iVar3 = ASN1_INTEGER_set(pPVar5->version,1);
      if (iVar3 != 0) {
        return 1;
      }
      PKCS7_SIGNED_free((p7->d).sign);
      (p7->d).ptr = (char *)0x0;
      return 0;
    }
    break;
  case 0x17:
    p7->type = pAVar1;
    pPVar6 = PKCS7_ENVELOPE_new();
    (p7->d).enveloped = pPVar6;
    if ((pPVar6 != (PKCS7_ENVELOPE *)0x0) &&
       (iVar3 = ASN1_INTEGER_set(pPVar6->version,0), iVar3 != 0)) {
      pPVar9 = ((p7->d).enveloped)->enc_data;
      pAVar1 = OBJ_nid2obj(0x15);
      pPVar9->content_type = pAVar1;
      return 1;
    }
    break;
  case 0x18:
    p7->type = pAVar1;
    pPVar7 = PKCS7_SIGN_ENVELOPE_new();
    (p7->d).signed_and_enveloped = pPVar7;
    if (pPVar7 != (PKCS7_SIGN_ENVELOPE *)0x0) {
      ASN1_INTEGER_set(pPVar7->version,1);
      iVar3 = ASN1_INTEGER_set(((p7->d).sign)->version,1);
      if (iVar3 != 0) {
        pPVar9 = ((p7->d).signed_and_enveloped)->enc_data;
        pAVar1 = OBJ_nid2obj(0x15);
        pPVar9->content_type = pAVar1;
        return 1;
      }
    }
    break;
  case 0x19:
    p7->type = pAVar1;
    pPVar8 = PKCS7_DIGEST_new();
    (p7->d).digest = pPVar8;
    if (pPVar8 != (PKCS7_DIGEST *)0x0) {
      iVar3 = ASN1_INTEGER_set(pPVar8->version,0);
      if (iVar3 == 0) {
        return 0;
      }
      return 1;
    }
    break;
  case 0x1a:
    p7->type = pAVar1;
    pPVar2 = PKCS7_ENCRYPT_new();
    (p7->d).encrypted = pPVar2;
    if ((pPVar2 != (PKCS7_ENCRYPT *)0x0) &&
       (iVar3 = ASN1_INTEGER_set(pPVar2->version,0), iVar3 != 0)) {
      pXVar10 = ((p7->d).digest)->md;
      pAVar1 = OBJ_nid2obj(0x15);
      pXVar10->algorithm = pAVar1;
      return 1;
    }
    break;
  default:
    ERR_put_error(0x21,0x6e,0x70,DAT_000cf374,0xde);
  }
  return 0;
}

