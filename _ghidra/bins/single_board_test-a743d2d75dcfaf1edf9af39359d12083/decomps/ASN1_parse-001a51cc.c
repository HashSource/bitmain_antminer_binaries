
int ASN1_parse(BIO *bp,uchar *pp,long len,int indent)

{
  int iVar1;
  uchar *local_14 [2];
  
  local_14[0] = pp;
  iVar1 = asn1_parse2(bp,local_14,len,0,0,indent,0);
  return iVar1;
}

