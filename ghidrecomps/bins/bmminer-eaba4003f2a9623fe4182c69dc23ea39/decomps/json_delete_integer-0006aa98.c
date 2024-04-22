
void json_delete_integer(json_integer_t *integer)

{
  json_integer_t *integer_local;
  
  jsonp_free(integer);
  return;
}

