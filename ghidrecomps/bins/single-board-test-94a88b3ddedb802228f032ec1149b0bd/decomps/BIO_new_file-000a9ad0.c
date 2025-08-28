
BIO * BIO_new_file(char *filename,char *mode)

{
  FILE *__stream;
  BIO *b;
  int *piVar1;
  int reason;
  int line;
  
  __stream = fopen64(filename,mode);
  if (__stream == (FILE *)0x0) {
    piVar1 = __errno_location();
    ERR_put_error(2,1,*piVar1,"bss_file.c",0xa8);
    ERR_add_error_data(5,"fopen(\'",filename,&DAT_0015d940,mode,&DAT_00141c8c);
    if (*piVar1 == 2) {
      line = 0xab;
      reason = 0x80;
    }
    else {
      line = 0xad;
      reason = 2;
    }
    ERR_put_error(0x20,0x6d,reason,"bss_file.c",line);
    b = (BIO *)0x0;
  }
  else {
    b = BIO_new((BIO_METHOD *)&methods_filep);
    if (b == (BIO *)0x0) {
      fclose(__stream);
    }
    else {
      BIO_clear_flags(b,0);
      BIO_ctrl(b,0x6a,1,__stream);
    }
  }
  return b;
}

