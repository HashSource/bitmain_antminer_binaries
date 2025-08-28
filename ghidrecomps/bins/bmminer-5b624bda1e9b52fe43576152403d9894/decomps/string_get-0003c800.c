
/* WARNING: Unknown calling convention */

int string_get(void *data)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = (uint)*(byte *)(*data + *(int *)((int)data + 4));
  if (uVar1 != 0) {
    *(int *)((int)data + 4) = *(int *)((int)data + 4) + 1;
    return uVar1;
  }
  return -1;
}

