
/* WARNING: Unknown calling convention */

void _jsonp_free(void **ptr)

{
  if (*ptr != (void *)0x0) {
    (**(code **)(DAT_0003dcdc + 4))();
    *ptr = (void *)0x0;
  }
  return;
}

