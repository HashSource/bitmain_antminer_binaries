
void json_delete_string(json_string_t *string)

{
  json_string_t *string_local;
  
  jsonp_free(string->value);
  jsonp_free(string);
  return;
}

