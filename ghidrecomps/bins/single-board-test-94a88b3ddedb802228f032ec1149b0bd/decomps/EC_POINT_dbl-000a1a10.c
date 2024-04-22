
int EC_POINT_dbl(EC_GROUP *group,EC_POINT *r,EC_POINT *a,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x5c) == (code *)0x0) {
    ERR_put_error(0x10,0x73,0x42,DAT_000a1a5c,0x3a8);
    iVar1 = 0;
  }
  else if ((iVar1 == *(int *)r) && (iVar1 == *(int *)a)) {
    iVar1 = (**(code **)(iVar1 + 0x5c))();
  }
  else {
    ERR_put_error(0x10,0x73,0x65,DAT_000a1a5c,0x3ac);
    iVar1 = 0;
  }
  return iVar1;
}

