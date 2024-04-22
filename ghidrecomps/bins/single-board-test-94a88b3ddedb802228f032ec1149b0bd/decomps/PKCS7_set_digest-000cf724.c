
int PKCS7_set_digest(PKCS7 *p7,EVP_MD *md)

{
  int iVar1;
  ASN1_TYPE *pAVar2;
  ASN1_OBJECT *pAVar3;
  X509_ALGOR *pXVar4;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x19) {
    pXVar4 = ((p7->d).digest)->md;
    pAVar2 = ASN1_TYPE_new();
    pXVar4->parameter = pAVar2;
    if (pAVar2 == (ASN1_TYPE *)0x0) {
      ERR_put_error(0x21,0x7e,0x41,DAT_000cf790,0x1b2);
      iVar1 = 0;
    }
    else {
      pXVar4 = ((p7->d).digest)->md;
      pXVar4->parameter->type = 5;
      iVar1 = EVP_MD_type(md);
      pAVar3 = OBJ_nid2obj(iVar1);
      iVar1 = 1;
      pXVar4->algorithm = pAVar3;
    }
  }
  else {
    ERR_put_error(0x21,0x7e,0x71,DAT_000cf790,0x1ba);
    iVar1 = 1;
  }
  return iVar1;
}

