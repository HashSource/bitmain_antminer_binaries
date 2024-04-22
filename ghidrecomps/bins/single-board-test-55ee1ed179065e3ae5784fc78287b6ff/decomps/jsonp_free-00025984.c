
void jsonp_free(int param_1)

{
  if (param_1 != 0) {
    (*do_free)(param_1);
  }
  return;
}

