
void PKCS12_SAFEBAG_get0_attr(int param_1,int param_2)

{
  PKCS12_get_attr_gen(*(stack_st_X509_ATTRIBUTE **)(param_1 + 8),param_2);
  return;
}

