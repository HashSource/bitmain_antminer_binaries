
/* WARNING: Unknown calling convention */

int dump_to_buffer(char *buffer,size_t size,void *data)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = size + *(int *)((int)data + 4);
  if (uVar1 <= *data) {
    memcpy((void *)(*(int *)((int)data + 8) + *(int *)((int)data + 4)),buffer,size);
    uVar1 = size + *(int *)((int)data + 4);
  }
  *(uint *)((int)data + 4) = uVar1;
  return 0;
}

