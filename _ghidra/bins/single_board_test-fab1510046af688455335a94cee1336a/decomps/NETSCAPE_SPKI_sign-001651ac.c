
int NETSCAPE_SPKI_sign(NETSCAPE_SPKI *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  
  iVar1 = ASN1_item_sign((ASN1_ITEM *)&NETSCAPE_SPKAC_it,x->sig_algor,(X509_ALGOR *)0x0,x->signature
                         ,x->spkac,pkey,md);
  return iVar1;
}

