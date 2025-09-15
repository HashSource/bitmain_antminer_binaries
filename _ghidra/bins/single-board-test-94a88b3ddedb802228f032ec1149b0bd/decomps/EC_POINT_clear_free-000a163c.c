
void EC_POINT_clear_free(EC_POINT *point)

{
  code *pcVar1;
  
  if (point == (EC_POINT *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*(int *)point + 0x30);
  if ((pcVar1 != (code *)0x0) || (pcVar1 = *(code **)(*(int *)point + 0x2c), pcVar1 != (code *)0x0))
  {
    (*pcVar1)();
  }
  OPENSSL_cleanse(point,0x44);
  CRYPTO_free(point);
  return;
}

