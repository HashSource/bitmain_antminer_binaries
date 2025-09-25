
int base64_encode_file(FILE *f_in,FILE *f_out)

{
  size_t sVar1;
  size_t __size;
  char *string;
  char *encoded_00;
  size_t sVar2;
  FILE *f_out_local;
  FILE *f_in_local;
  int write_len;
  int encoded_res;
  int read_len;
  char *encoded;
  char *data;
  int encode_len;
  int file_size;
  int res;
  
  res = 1;
  if ((f_in == (FILE *)0x0) || (f_out == (FILE *)0x0)) {
    res = 1;
  }
  else {
    fseek((FILE *)f_in,0,2);
    sVar1 = ftell((FILE *)f_in);
    __size = Base64encode_len(sVar1);
    printf("file_size:%d,encodelen:%d\n",sVar1,__size);
    fseek((FILE *)f_in,0,0);
    string = (char *)malloc(sVar1);
    encoded_00 = (char *)malloc(__size);
    if ((string != (char *)0x0) && (encoded_00 != (char *)0x0)) {
      memset(string,0,sVar1);
      sVar2 = fread(string,1,sVar1,(FILE *)f_in);
      if (sVar2 == sVar1) {
        sVar1 = Base64encode(encoded_00,string,sVar1);
        if (sVar1 == __size) {
          sVar1 = fwrite(encoded_00,1,sVar1,(FILE *)f_out);
          printf("encode_success,writelen:%d\n",sVar1);
          if (sVar1 == __size) {
            res = 0;
          }
        }
        else {
          printf("encoded_res:%d,encodelen:%d\n",sVar1,__size);
        }
      }
    }
    if (string != (char *)0x0) {
      free(string);
    }
    if (encoded_00 != (char *)0x0) {
      free(encoded_00);
    }
  }
  return res;
}

