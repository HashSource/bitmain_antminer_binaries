
int buffer_get(void *data)

{
  byte bVar1;
  uint uVar2;
  void *data_local;
  char c;
  buffer_data_t *stream;
  
  if (*(uint *)((int)data + 8) < *(uint *)((int)data + 4)) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *(byte *)(*(int *)((int)data + 8) + *data);
    *(int *)((int)data + 8) = *(int *)((int)data + 8) + 1;
    uVar2 = (uint)bVar1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

