
BIO * BIO_new_file(char *filename,char *mode)

{
  FILE *__stream;
  char *pcVar1;
  BIO_METHOD *type;
  BIO *b;
  uint *puVar2;
  int reason;
  long larg;
  int line;
  
  __stream = openssl_fopen(filename,mode);
  pcVar1 = strchr(mode,0x62);
  if (pcVar1 == (char *)0x0) {
    larg = 0x11;
  }
  else {
    larg = 1;
  }
  if (__stream == (FILE *)0x0) {
    puVar2 = (uint *)__errno_location();
    ERR_put_error(2,1,*puVar2,"crypto/bio/bss_file.c",0x45);
    ERR_add_error_data(5,"fopen(\'",filename,&DAT_002091c8,mode,&DAT_00202e30);
    if ((*puVar2 & 0xfffffffb) == 2) {
      line = 0x4c;
      reason = 0x80;
    }
    else {
      line = 0x4e;
      reason = 2;
    }
    ERR_put_error(0x20,0x6d,reason,"crypto/bio/bss_file.c",line);
    return (BIO *)0x0;
  }
  type = BIO_s_file();
  b = BIO_new(type);
  if (b == (BIO *)0x0) {
    fclose(__stream);
  }
  else {
    BIO_clear_flags(b,0);
    BIO_ctrl(b,0x6a,larg,__stream);
  }
  return b;
}

