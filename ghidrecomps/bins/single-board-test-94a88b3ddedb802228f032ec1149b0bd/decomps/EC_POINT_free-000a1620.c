
void EC_POINT_free(EC_POINT *point)

{
  if (point != (EC_POINT *)0x0) {
    if (*(code **)(*(int *)point + 0x2c) != (code *)0x0) {
      (**(code **)(*(int *)point + 0x2c))();
    }
    CRYPTO_free(point);
    return;
  }
  return;
}

