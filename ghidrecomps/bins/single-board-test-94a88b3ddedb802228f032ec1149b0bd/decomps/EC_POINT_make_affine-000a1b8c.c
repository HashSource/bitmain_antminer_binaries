
int EC_POINT_make_affine(EC_GROUP *group,EC_POINT *point,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 0x70);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x78,0x42,DAT_000a1bd0,0x3f3);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)point) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0x78,0x65,DAT_000a1bd0,0x3f7);
    iVar1 = 0;
  }
  return iVar1;
}

