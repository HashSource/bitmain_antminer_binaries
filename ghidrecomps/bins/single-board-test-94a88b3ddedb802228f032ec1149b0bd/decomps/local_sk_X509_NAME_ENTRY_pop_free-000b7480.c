
void local_sk_X509_NAME_ENTRY_pop_free(_STACK *param_1)

{
  sk_pop_free(param_1,X509_NAME_ENTRY_free + 1);
  return;
}

