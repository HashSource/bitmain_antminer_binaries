
/* WARNING: Unknown calling convention */

int object_key_compare_serials(void *key1,void *key2)

{
  size_t b;
  size_t a;
  
                    /* WARNING: Load size is inaccurate */
  a = *key1;
                    /* WARNING: Load size is inaccurate */
  if (a < *key2) {
    return -1;
  }
  return (uint)(a != *key2);
}

