
char * json_object_iter_key(void *iter)

{
  char *pcVar1;
  void *iter_local;
  
  if (iter == (void *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)hashtable_iter_key(iter);
  }
  return pcVar1;
}

