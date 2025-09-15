
void array_move(json_array_t *array,size_t dest,size_t src,size_t count)

{
  size_t count_local;
  size_t src_local;
  size_t dest_local;
  json_array_t *array_local;
  
  memmove(array->table + dest,array->table + src,count << 2);
  return;
}

