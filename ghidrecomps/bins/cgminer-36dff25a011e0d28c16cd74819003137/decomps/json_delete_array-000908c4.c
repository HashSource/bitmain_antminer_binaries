
void json_delete_array(json_array_t *array)

{
  json_array_t *array_local;
  size_t i;
  
  for (i = 0; i < array->entries; i = i + 1) {
    json_decref(array->table[i]);
  }
  jsonp_free(array->table);
  jsonp_free(array);
  return;
}

