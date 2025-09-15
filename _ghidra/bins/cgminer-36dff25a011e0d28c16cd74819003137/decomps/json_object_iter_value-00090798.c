
json_t * json_object_iter_value(void *iter)

{
  json_t *pjVar1;
  void *iter_local;
  
  if (iter == (void *)0x0) {
    pjVar1 = (json_t *)0x0;
  }
  else {
    pjVar1 = (json_t *)hashtable_iter_value(iter);
  }
  return pjVar1;
}

