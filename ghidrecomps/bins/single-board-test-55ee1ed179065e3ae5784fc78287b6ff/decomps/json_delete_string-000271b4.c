
void json_delete_string(int param_1)

{
  jsonp_free(*(undefined4 *)(param_1 + 8));
  jsonp_free(param_1);
  return;
}

