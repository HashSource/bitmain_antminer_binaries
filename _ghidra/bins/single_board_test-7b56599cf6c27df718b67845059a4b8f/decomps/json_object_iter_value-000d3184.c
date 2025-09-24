
/* WARNING: Unknown calling convention */

json_t * json_object_iter_value(void *iter)

{
  json_t *pjVar1;
  
  if (iter != (void *)0x0) {
    pjVar1 = (json_t *)hashtable_iter_value(iter);
    return pjVar1;
  }
  return (json_t *)0x0;
}

