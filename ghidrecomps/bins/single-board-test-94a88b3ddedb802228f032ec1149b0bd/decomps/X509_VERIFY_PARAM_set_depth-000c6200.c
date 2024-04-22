
void X509_VERIFY_PARAM_set_depth(X509_VERIFY_PARAM *param,int depth)

{
  param->depth = depth;
  return;
}

