
int X509_CRL_get_ext_by_OBJ(X509_CRL *x,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_OBJ(x->crl->extensions,obj,lastpos);
  return iVar1;
}

