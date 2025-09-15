
char * BIO_method_name(BIO *b)

{
  return b->method->name;
}

