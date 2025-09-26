
void md_callback_ctrl(BIO *param_1,int param_2,fp *param_3)

{
  BIO *b;
  
  b = BIO_next(param_1);
  if (b != (BIO *)0x0) {
    BIO_callback_ctrl(b,param_2,param_3);
    return;
  }
  return;
}

