
size_t BIO_ctrl_pending(BIO *b)

{
  size_t sVar1;
  
  sVar1 = BIO_ctrl(b,10,0,(void *)0x0);
  return sVar1;
}

