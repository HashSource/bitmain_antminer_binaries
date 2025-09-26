
X509 * d2i_X509_bio(BIO *bp,X509 **x509)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)ASN1_item_d2i_bio((ASN1_ITEM *)X509_it,bp,x509);
  return pXVar1;
}

