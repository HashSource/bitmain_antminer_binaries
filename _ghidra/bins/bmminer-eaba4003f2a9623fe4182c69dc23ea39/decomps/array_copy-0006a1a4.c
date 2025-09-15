
void array_copy(json_t **dest,size_t dpos,json_t **src,size_t spos,size_t count)

{
  size_t spos_local;
  json_t **src_local;
  size_t dpos_local;
  json_t **dest_local;
  
  memcpy(dest + dpos,src + spos,count << 2);
  return;
}

