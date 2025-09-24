
int EC_METHOD_get_field_type(EC_METHOD *meth)

{
  return *(int *)(meth + 4);
}

