
int X509_STORE_set_depth(X509_STORE *store,int depth)

{
  X509_VERIFY_PARAM_set_depth(store->param,depth);
  return 1;
}

