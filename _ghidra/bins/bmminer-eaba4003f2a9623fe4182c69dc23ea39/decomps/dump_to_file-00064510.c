
int dump_to_file(char *buffer,size_t size,void *data)

{
  size_t sVar1;
  int iVar2;
  void *data_local;
  size_t size_local;
  char *buffer_local;
  FILE *dest;
  
  sVar1 = fwrite(buffer,size,1,(FILE *)data);
  if (sVar1 == 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

