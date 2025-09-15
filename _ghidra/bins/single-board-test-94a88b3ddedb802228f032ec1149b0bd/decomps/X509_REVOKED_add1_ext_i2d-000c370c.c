
int X509_REVOKED_add1_ext_i2d(X509_REVOKED *x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  
  iVar1 = X509V3_add1_i2d(&x->extensions,nid,value,crit,flags);
  return iVar1;
}

