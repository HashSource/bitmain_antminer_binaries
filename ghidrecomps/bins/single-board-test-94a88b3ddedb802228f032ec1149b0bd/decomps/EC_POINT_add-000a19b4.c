
int EC_POINT_add(EC_GROUP *group,EC_POINT *r,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x58) == (code *)0x0) {
    ERR_put_error(0x10,0x70,0x42,DAT_000a1a0c,0x399);
    iVar1 = 0;
  }
  else if (((iVar1 == *(int *)r) && (iVar1 == *(int *)a)) && (iVar1 == *(int *)b)) {
    iVar1 = (**(code **)(iVar1 + 0x58))();
  }
  else {
    ERR_put_error(0x10,0x70,0x65,DAT_000a1a0c,0x39e);
    iVar1 = 0;
  }
  return iVar1;
}

