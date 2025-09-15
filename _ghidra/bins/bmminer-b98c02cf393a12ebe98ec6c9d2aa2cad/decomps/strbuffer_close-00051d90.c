
void strbuffer_close(int *param_1)

{
  if (*param_1 != 0) {
    jsonp_free();
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

