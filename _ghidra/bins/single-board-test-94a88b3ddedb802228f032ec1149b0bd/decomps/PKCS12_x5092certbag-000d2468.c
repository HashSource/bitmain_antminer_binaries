
PKCS12_SAFEBAG * PKCS12_x5092certbag(X509 *x509)

{
  PKCS12_SAFEBAG *pPVar1;
  
  pPVar1 = PKCS12_item_pack_safebag(x509,(ASN1_ITEM *)X509_it,0x9e,0x98);
  return pPVar1;
}

