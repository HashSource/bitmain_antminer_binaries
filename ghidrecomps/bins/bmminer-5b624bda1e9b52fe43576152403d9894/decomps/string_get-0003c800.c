
/* WARNING: Unknown calling convention */

int string_get(void *data)

{
  string_data_t *stream;
  
                    /* WARNING: Load size is inaccurate */
  stream = (string_data_t *)(uint)*(byte *)(*data + *(int *)((int)data + 4));
  if (stream != (string_data_t *)0x0) {
    *(int *)((int)data + 4) = *(int *)((int)data + 4) + 1;
    return (int)stream;
  }
  return -1;
}

