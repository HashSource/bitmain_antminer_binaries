
/* WARNING: Unknown calling convention */

int dump_to_strbuffer(char *buffer,size_t size,void *data)

{
  int iVar1;
  
  iVar1 = strbuffer_append_bytes((strbuffer_t *)data,buffer,size);
  return iVar1;
}

