
void BIO_set_callback_arg(BIO *b,char *arg)

{
  b->init = (int)arg;
  return;
}

