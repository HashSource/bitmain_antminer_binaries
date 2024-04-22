
/* WARNING: Unknown calling convention */

int callback_get(void *data)

{
  byte bVar1;
  callback_data_t *stream;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((int)data + 0x404);
  if (*(uint *)((int)data + 0x400) <= uVar3) {
    *(undefined4 *)((int)data + 0x404) = 0;
    iVar2 = (**(code **)((int)data + 0x408))(data,0x400,*(undefined4 *)((int)data + 0x40c));
    *(int *)((int)data + 0x400) = iVar2;
    if (0xfffffffd < iVar2 - 1U) {
      return -1;
    }
    uVar3 = *(uint *)((int)data + 0x404);
  }
  bVar1 = *(byte *)((int)data + uVar3);
  *(uint *)((int)data + 0x404) = uVar3 + 1;
  return (uint)bVar1;
}

