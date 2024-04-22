
DSO_METHOD * DSO_set_method(DSO *dso,DSO_METHOD *meth)

{
  DSO_METHOD *pDVar1;
  
  pDVar1 = dso->meth;
  dso->meth = meth;
  return pDVar1;
}

