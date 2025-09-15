
uchar * X509_alias_get0(X509 *x,int *len)

{
  int *piVar1;
  
  piVar1 = *(int **)(x->sha1_hash + 0xc);
  if ((piVar1 != (int *)0x0) && (piVar1 = (int *)piVar1[2], piVar1 != (int *)0x0)) {
    if (len != (int *)0x0) {
      *len = *piVar1;
    }
    piVar1 = (int *)piVar1[2];
  }
  return (uchar *)piVar1;
}

