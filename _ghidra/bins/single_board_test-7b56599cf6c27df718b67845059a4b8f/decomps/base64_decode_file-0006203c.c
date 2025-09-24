
int base64_decode_file(FILE *f_in,FILE *f_out)

{
  size_t sVar1;
  char *bufcoded;
  size_t sVar2;
  char *bufplain;
  FILE *f_out_local;
  FILE *f_in_local;
  int write_len;
  int decoded_len;
  char *decode;
  int decode_len;
  int read_len;
  char *data;
  int file_size;
  int res;
  
  res = 1;
  if ((f_in == (FILE *)0x0) || (f_out == (FILE *)0x0)) {
    res = 1;
  }
  else {
    fseek((FILE *)f_in,0,2);
    sVar1 = ftell((FILE *)f_in);
    fseek((FILE *)f_in,0,0);
    bufcoded = (char *)malloc(sVar1);
    if (bufcoded != (char *)0x0) {
      memset(bufcoded,0,sVar1);
      sVar2 = fread(bufcoded,1,sVar1,(FILE *)f_in);
      if (sVar2 == sVar1) {
        sVar2 = Base64decode_len(bufcoded);
        printf("decode_len:%d,src len:%d\n",sVar2,sVar1);
        if (sVar2 != 0) {
          bufplain = (char *)malloc(sVar2);
          if (bufplain != (char *)0x0) {
            sVar1 = Base64decode(bufplain,bufcoded);
            printf("decoded_len:%d,decode len:%d\n",sVar1,sVar2);
            if (sVar1 != 0) {
              puts("decode_success");
              sVar2 = fwrite(bufplain,1,sVar1,(FILE *)f_out);
              if (sVar2 == sVar1) {
                res = 0;
              }
            }
          }
          if (bufplain != (char *)0x0) {
            free(bufplain);
          }
        }
      }
      if (bufcoded != (char *)0x0) {
        free(bufcoded);
      }
    }
  }
  return res;
}

