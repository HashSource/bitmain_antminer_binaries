
int DH_generate_key(DH *dh)

{
  int iVar1;
  
  iVar1 = (*dh->meth->generate_key)(dh);
  return iVar1;
}

