
void RSA_set_default_method(RSA_METHOD *meth)

{
  default_RSA_meth = meth;
  return;
}

