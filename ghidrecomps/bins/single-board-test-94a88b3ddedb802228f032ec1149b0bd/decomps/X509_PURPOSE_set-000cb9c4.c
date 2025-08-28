
int X509_PURPOSE_set(int *p,int purpose)

{
  int iVar1;
  int local_2c [8];
  
  if ((8 < purpose - 1U) &&
     (((local_2c[0] = purpose, xptable == (_STACK *)0x0 ||
       (iVar1 = sk_find(xptable,local_2c), iVar1 == -1)) || (iVar1 == -10)))) {
    ERR_put_error(0x22,0x8d,0x92,"v3_purp.c",0x94);
    return 0;
  }
  *p = purpose;
  return 1;
}

