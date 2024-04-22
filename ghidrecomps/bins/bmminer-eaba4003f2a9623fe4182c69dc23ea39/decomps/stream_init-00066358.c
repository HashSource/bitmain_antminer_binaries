
void stream_init(stream_t *stream,get_func get,void *data)

{
  void *data_local;
  get_func get_local;
  stream_t *stream_local;
  
  stream->get = get;
  stream->data = data;
  stream->buffer[0] = '\0';
  stream->buffer_pos = 0;
  stream->state = 0;
  stream->line = 1;
  stream->column = 0;
  stream->position = 0;
  return;
}

