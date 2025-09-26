
BIO * BIO_new_socket(int sock,int close_flag)

{
  BIO *bp;
  
  bp = BIO_new((BIO_METHOD *)&methods_sockp);
  if (bp != (BIO *)0x0) {
    BIO_int_ctrl(bp,0x68,close_flag,sock);
  }
  return bp;
}

