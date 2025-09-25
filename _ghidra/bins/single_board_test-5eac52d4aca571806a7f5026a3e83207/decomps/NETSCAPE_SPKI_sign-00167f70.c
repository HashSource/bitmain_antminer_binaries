
int NETSCAPE_SPKI_sign(NETSCAPE_SPKI *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  
  iVar1 = ASN1_item_sign((ASN1_ITEM *)NETSCAPE_SPKAC_it,(X509_ALGOR *)&x->sig_algor,
                         (X509_ALGOR *)0x0,(ASN1_BIT_STRING *)x[1].spkac,x->spkac,pkey,md);
  return iVar1;
}

