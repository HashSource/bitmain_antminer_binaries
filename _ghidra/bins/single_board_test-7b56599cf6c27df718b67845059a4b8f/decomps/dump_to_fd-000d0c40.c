
/* WARNING: Unknown calling convention */

int dump_to_fd(char *buffer,size_t size,void *data)

{
  size_t sVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  sVar1 = write(*data,buffer,size);
  if (sVar1 == size) {
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

