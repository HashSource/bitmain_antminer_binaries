
int read_data(FILE *file,uint32_t offset,uint32_t len,uint8_t *data)

{
  uint uVar1;
  size_t __n;
  uint8_t *data_local;
  uint32_t len_local;
  uint32_t offset_local;
  FILE *file_local;
  int size;
  int read_len;
  
  if (file != (FILE *)0x0) {
    fseek((FILE *)file,0,2);
    uVar1 = ftell((FILE *)file);
    __n = len;
    if (uVar1 < offset + len) {
      __n = uVar1 - offset;
    }
    fseek((FILE *)file,offset,0);
    fread(data,1,__n,(FILE *)file);
  }
  return len;
}

