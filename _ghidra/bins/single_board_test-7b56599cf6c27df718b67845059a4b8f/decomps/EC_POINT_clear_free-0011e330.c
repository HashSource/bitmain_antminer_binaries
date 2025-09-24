
void EC_POINT_clear_free(EC_POINT *point)

{
  code *pcVar1;
  
  if (point == (EC_POINT *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*(int *)point + 0x34);
  if ((pcVar1 != (code *)0x0) || (pcVar1 = *(code **)(*(int *)point + 0x30), pcVar1 != (code *)0x0))
  {
    (*pcVar1)();
  }
  CRYPTO_clear_free(point,0x18,"crypto/ec/ec_lib.c",699);
  return;
}

