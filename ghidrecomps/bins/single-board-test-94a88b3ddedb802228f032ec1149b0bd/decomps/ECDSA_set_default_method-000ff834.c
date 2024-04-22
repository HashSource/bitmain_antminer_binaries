
void ECDSA_set_default_method(ECDSA_METHOD *meth)

{
  default_ECDSA_method = meth;
  return;
}

