
int __pthread_atfork(__prepare *__prepare,__parent *__parent,__child *__child)

{
  int iVar1;
  
  iVar1 = __register_atfork(__prepare,__parent,__child,__dso_handle);
  return iVar1;
}

