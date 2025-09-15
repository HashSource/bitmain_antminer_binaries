
int callback_get(void *data)

{
  byte bVar1;
  undefined4 uVar2;
  void *data_local;
  char c;
  callback_data_t *stream;
  
  if (*(uint *)((int)data + 0x400) <= *(uint *)((int)data + 0x404)) {
    *(undefined4 *)((int)data + 0x404) = 0;
    uVar2 = (**(code **)((int)data + 0x408))(data,0x400,*(undefined4 *)((int)data + 0x40c));
    *(undefined4 *)((int)data + 0x400) = uVar2;
    if ((*(int *)((int)data + 0x400) == 0) || (*(int *)((int)data + 0x400) == -1)) {
      return -1;
    }
  }
  bVar1 = *(byte *)((int)data + *(int *)((int)data + 0x404));
  *(int *)((int)data + 0x404) = *(int *)((int)data + 0x404) + 1;
  return (uint)bVar1;
}

