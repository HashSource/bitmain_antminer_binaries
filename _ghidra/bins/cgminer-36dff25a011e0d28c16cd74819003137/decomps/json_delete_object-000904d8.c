
void json_delete_object(json_object_t *object)

{
  json_object_t *object_local;
  
  hashtable_close(&object->hashtable);
  jsonp_free(object);
  return;
}

