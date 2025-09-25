
BIO * BIO_new_socket(int sock,int close_flag)

{
  BIO_METHOD *type;
  BIO *bp;
  
  type = BIO_s_socket();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_int_ctrl(bp,0x68,close_flag,sock);
  }
  return bp;
}

