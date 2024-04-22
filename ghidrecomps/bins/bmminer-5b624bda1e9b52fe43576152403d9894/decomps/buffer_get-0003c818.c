
/* WARNING: Unknown calling convention */
/* Local variable stream:buffer_data_t *[r0:4] conflicts with parameter, skipped. */

int buffer_get(void *data)

{
  int in_r1;
  char c;
  bool bVar1;
  
  _c = *(uint *)((int)data + 8);
  bVar1 = _c < *(uint *)((int)data + 4);
                    /* WARNING: Load size is inaccurate */
  if (bVar1) {
    in_r1 = _c + 1;
    _c = (uint)*(byte *)(*data + _c);
  }
  if (bVar1) {
    *(int *)((int)data + 8) = in_r1;
  }
  else {
    _c = 0xffffffff;
  }
  return _c;
}

