
int PKCS7_add_attrib_content_type(PKCS7_SIGNER_INFO *si,ASN1_OBJECT *coid)

{
  ASN1_TYPE *pAVar1;
  int iVar2;
  
  pAVar1 = PKCS7_get_signed_attribute(si,0x32);
  if (pAVar1 != (ASN1_TYPE *)0x0) {
    return 0;
  }
  if (coid == (ASN1_OBJECT *)0x0) {
    coid = OBJ_nid2obj(0x15);
  }
  iVar2 = PKCS7_add_signed_attribute(si,0x32,6,coid);
  return iVar2;
}

