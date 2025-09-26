
BIO * BIO_new_fp(FILE *stream,int close_flag)

{
  BIO *b;
  
  b = BIO_new((BIO_METHOD *)&methods_filep);
  if (b != (BIO *)0x0) {
    BIO_set_flags(b,0);
    BIO_ctrl(b,0x6a,close_flag,stream);
  }
  return b;
}

