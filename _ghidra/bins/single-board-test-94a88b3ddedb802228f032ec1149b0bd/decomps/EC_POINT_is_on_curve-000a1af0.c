
int EC_POINT_is_on_curve(EC_GROUP *group,EC_POINT *point,BN_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)group + 0x68);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x77,0x42,"ec_lib.c",0x3d8);
    iVar1 = 0;
  }
  else if (*(int *)group == *(int *)point) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0x77,0x65,"ec_lib.c",0x3dc);
    iVar1 = 0;
  }
  return iVar1;
}

