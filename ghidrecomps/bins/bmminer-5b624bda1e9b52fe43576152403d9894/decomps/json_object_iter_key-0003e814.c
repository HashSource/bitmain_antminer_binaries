
/* WARNING: Unknown calling convention */

char * json_object_iter_key(void *iter)

{
  char *pcVar1;
  
  if (iter != (void *)0x0) {
    pcVar1 = (char *)hashtable_iter_key(iter);
    return pcVar1;
  }
  return (char *)0x0;
}

