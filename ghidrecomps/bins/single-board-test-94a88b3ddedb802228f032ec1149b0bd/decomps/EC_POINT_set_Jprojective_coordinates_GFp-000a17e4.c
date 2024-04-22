
int EC_POINT_set_Jprojective_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,BIGNUM *y,BIGNUM *z,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 0x3c);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x7e,0x42,DAT_000a1830,0x32e);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)p) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0x7e,0x65,DAT_000a1830,0x333);
    iVar1 = 0;
  }
  return iVar1;
}

