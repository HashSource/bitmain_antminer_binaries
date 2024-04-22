
int EC_POINT_set_affine_coordinates_GFp(EC_GROUP *group,EC_POINT *p,BIGNUM *x,BIGNUM *y,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 0x44);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x7c,0x42,DAT_000a18cc,0x353);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)p) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0x7c,0x65,DAT_000a18cc,0x358);
    iVar1 = 0;
  }
  return iVar1;
}

