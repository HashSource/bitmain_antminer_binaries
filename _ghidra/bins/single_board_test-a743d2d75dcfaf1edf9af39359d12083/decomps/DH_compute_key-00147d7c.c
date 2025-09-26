
int DH_compute_key(uchar *key,BIGNUM *pub_key,DH *dh)

{
  int iVar1;
  
  iVar1 = (*dh->meth->compute_key)(key,pub_key,dh);
  return iVar1;
}

