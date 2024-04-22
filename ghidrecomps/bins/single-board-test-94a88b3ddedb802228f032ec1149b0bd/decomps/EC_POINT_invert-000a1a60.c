
int EC_POINT_invert(EC_GROUP *group,EC_POINT *a,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 0x60);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0xd2,0x42,DAT_000a1aa4,0x3b5);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)a) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0xd2,0x65,DAT_000a1aa4,0x3b9);
    iVar1 = 0;
  }
  return iVar1;
}

