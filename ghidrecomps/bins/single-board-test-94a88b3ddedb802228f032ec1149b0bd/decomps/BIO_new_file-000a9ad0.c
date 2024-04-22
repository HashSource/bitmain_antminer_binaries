
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
    ERR_put_error(2,1,*piVar1,DAT_000a9b60,0xa8);
    ERR_add_error_data(5,DAT_000a9b68,filename,DAT_000a9b6c,mode,DAT_000a9b64);
    if (*piVar1 == 2) {
      line = 0xab;
      reason = 0x80;
    }
    else {
      line = 0xad;
      reason = 2;
    }
    ERR_put_error(0x20,0x6d,reason,DAT_000a9b60,line);
    b = (BIO *)0x0;
  }
  else {
    b = BIO_new(DAT_000a9b5c);
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

