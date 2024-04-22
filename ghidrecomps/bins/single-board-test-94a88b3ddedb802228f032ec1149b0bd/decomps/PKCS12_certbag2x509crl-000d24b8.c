
X509_CRL * PKCS12_certbag2x509crl(PKCS12_SAFEBAG *bag)

{
  int iVar1;
  X509_CRL *pXVar2;
  
  iVar1 = OBJ_obj2nid(bag->type);
  if ((iVar1 == 0x99) && (iVar1 = OBJ_obj2nid(((bag->value).bag)->type), iVar1 == 0xa0)) {
    pXVar2 = (X509_CRL *)ASN1_item_unpack(((bag->value).keybag)->version,DAT_000d24e4);
    return pXVar2;
  }
  return (X509_CRL *)0x0;
}

