
void X509_ALGOR_set_md(X509_ALGOR *alg,EVP_MD *md)

{
  int n;
  ASN1_OBJECT *aobj;
  int ptype;
  
  if ((md->flags & 8) == 0) {
    ptype = 5;
  }
  else {
    ptype = -1;
  }
  n = EVP_MD_type(md);
  aobj = OBJ_nid2obj(n);
  X509_ALGOR_set0(alg,aobj,ptype,(void *)0x0);
  return;
}

