
int dump_to_strbuffer(char *buffer,size_t size,void *data)

{
  int iVar1;
  void *data_local;
  size_t size_local;
  char *buffer_local;
  
  iVar1 = strbuffer_append_bytes((strbuffer_t *)data,buffer,size);
  return iVar1;
}

