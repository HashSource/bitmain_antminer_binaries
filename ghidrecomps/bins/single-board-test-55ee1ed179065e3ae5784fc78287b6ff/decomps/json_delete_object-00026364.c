
void json_delete_object(int param_1)

{
  hashtable_close(param_1 + 8);
  jsonp_free(param_1);
  return;
}

