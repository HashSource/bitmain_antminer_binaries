
int OCSP_SINGLERESP_get_ext_by_OBJ(OCSP_SINGLERESP *x,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_OBJ(x->singleExtensions,obj,lastpos);
  return iVar1;
}

