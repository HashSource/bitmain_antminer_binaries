
EC_GROUP * PEM_read_ECPKParameters(FILE *fp,EC_GROUP **x,undefined1 *cb,void *u)

{
  EC_GROUP *pEVar1;
  
  pEVar1 = (EC_GROUP *)PEM_ASN1_read(d2i_ECPKParameters + 1,"EC PARAMETERS",fp,x,cb,u);
  return pEVar1;
}

