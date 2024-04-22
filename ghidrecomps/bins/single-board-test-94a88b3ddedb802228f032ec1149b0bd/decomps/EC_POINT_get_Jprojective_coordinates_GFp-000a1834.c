
int EC_POINT_get_Jprojective_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,BIGNUM *y,BIGNUM *z,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 0x40);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x75,0x42,DAT_000a1880,0x341);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)p) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0x75,0x65,DAT_000a1880,0x346);
    iVar1 = 0;
  }
  return iVar1;
}

