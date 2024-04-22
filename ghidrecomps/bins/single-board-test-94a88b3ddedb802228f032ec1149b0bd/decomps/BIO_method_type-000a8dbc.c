
int BIO_method_type(BIO *b)

{
  return b->method->type;
}

