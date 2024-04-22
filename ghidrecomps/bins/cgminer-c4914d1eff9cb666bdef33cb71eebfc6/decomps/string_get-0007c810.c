
int string_get(void *data)

{
  byte bVar1;
  uint uVar2;
  void *data_local;
  char c;
  string_data_t *stream;
  
                    /* WARNING: Load size is inaccurate */
  bVar1 = *(byte *)(*data + *(int *)((int)data + 4));
  if (bVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(int *)((int)data + 4) = *(int *)((int)data + 4) + 1;
    uVar2 = (uint)bVar1;
  }
  return uVar2;
}

