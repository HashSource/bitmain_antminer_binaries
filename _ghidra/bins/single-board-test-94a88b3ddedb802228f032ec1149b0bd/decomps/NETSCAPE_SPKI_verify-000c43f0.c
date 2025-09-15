
int NETSCAPE_SPKI_verify(NETSCAPE_SPKI *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = ASN1_item_verify((ASN1_ITEM *)&NETSCAPE_SPKAC_it,a->sig_algor,a->signature,a->spkac,r);
  return iVar1;
}

