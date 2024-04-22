
void BIO_set_callback_arg(BIO *b,char *arg)

{
  b->cb_arg = arg;
  return;
}

