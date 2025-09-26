
char * BIO_get_callback_arg(BIO *b)

{
  return (char *)b->init;
}

