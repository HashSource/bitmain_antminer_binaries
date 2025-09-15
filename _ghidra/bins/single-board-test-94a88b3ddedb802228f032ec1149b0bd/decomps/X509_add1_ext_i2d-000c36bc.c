
int X509_add1_ext_i2d(X509 *x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  
  iVar1 = X509V3_add1_i2d(&x->cert_info->extensions,nid,value,crit,flags);
  return iVar1;
}

