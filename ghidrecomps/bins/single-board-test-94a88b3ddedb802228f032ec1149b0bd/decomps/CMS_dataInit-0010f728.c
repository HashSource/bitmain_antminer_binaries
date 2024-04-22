
BIO * CMS_dataInit(CMS_ContentInfo *cms,BIO *icont)

{
  int iVar1;
  ASN1_OCTET_STRING **ppAVar2;
  BIO *pBVar3;
  BIO *b;
  BIO_METHOD *pBVar4;
  ASN1_OCTET_STRING *pAVar5;
  
  pBVar3 = icont;
  if (icont == (BIO *)0x0) {
    ppAVar2 = CMS_get0_content(cms);
    if (ppAVar2 == (ASN1_OCTET_STRING **)0x0) {
LAB_0010f76a:
      ERR_put_error(0x2e,0x6f,0x7f,DAT_0010f7ec,0x72);
      return (BIO *)0x0;
    }
    pAVar5 = *ppAVar2;
    if (pAVar5 == (ASN1_OCTET_STRING *)0x0) {
      pBVar4 = BIO_s_null();
      pBVar3 = BIO_new(pBVar4);
    }
    else if (pAVar5->flags == 0x20) {
      pBVar4 = BIO_s_mem();
      pBVar3 = BIO_new(pBVar4);
    }
    else {
      pBVar3 = BIO_new_mem_buf(pAVar5->data,pAVar5->length);
    }
    if (pBVar3 == (BIO *)0x0) goto LAB_0010f76a;
  }
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  switch(iVar1) {
  case 0x15:
    goto switchD_0010f740_caseD_15;
  case 0x16:
    b = (BIO *)cms_SignedData_init_bio(cms);
    break;
  case 0x17:
    b = (BIO *)cms_EnvelopedData_init_bio(cms);
    break;
  default:
    ERR_put_error(0x2e,0x6f,0x9c,DAT_0010f7ec,0x90);
    return (BIO *)0x0;
  case 0x19:
    b = (BIO *)cms_DigestedData_init_bio(cms);
    break;
  case 0x1a:
    b = (BIO *)cms_EncryptedData_init_bio(cms);
  }
  if (b != (BIO *)0x0) {
    pBVar3 = BIO_push(b,pBVar3);
    return pBVar3;
  }
  if (icont == (BIO *)0x0) {
    BIO_free(pBVar3);
    pBVar3 = icont;
  }
  else {
    pBVar3 = (BIO *)0x0;
  }
switchD_0010f740_caseD_15:
  return pBVar3;
}

