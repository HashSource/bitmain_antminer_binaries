
void cms_DigestAlgorithm_set(X509_ALGOR *param_1,EVP_MD *param_2)

{
  int n;
  ASN1_OBJECT *aobj;
  int ptype;
  
  if ((param_2->flags & 8) == 0) {
    ptype = 5;
  }
  else {
    ptype = -1;
  }
  n = EVP_MD_type(param_2);
  aobj = OBJ_nid2obj(n);
  X509_ALGOR_set0(param_1,aobj,ptype,(void *)0x0);
  return;
}

