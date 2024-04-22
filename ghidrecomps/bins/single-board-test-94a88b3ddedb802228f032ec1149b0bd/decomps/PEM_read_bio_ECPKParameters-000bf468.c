
EC_GROUP * PEM_read_bio_ECPKParameters(BIO *bp,EC_GROUP **x,undefined1 *cb,void *u)

{
  EC_GROUP *pEVar1;
  
  pEVar1 = (EC_GROUP *)PEM_ASN1_read_bio(d2i_ECPKParameters + 1,"EC PARAMETERS",bp,x,cb,u);
  return pEVar1;
}

