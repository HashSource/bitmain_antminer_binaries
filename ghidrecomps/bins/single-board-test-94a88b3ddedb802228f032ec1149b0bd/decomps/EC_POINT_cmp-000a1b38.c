
int EC_POINT_cmp(EC_GROUP *group,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x6c) == (code *)0x0) {
    ERR_put_error(0x10,0x71,0x42,DAT_000a1b88,0x3e6);
    iVar1 = -1;
  }
  else if ((iVar1 == *(int *)a) && (iVar1 == *(int *)b)) {
    iVar1 = (**(code **)(iVar1 + 0x6c))();
  }
  else {
    ERR_put_error(0x10,0x71,0x65,DAT_000a1b88,0x3ea);
    iVar1 = -1;
  }
  return iVar1;
}

