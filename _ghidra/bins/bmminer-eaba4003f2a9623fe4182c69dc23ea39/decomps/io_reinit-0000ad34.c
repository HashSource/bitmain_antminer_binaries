
void io_reinit(io_data *io_data)

{
  io_data *io_data_local;
  
  io_data->cur = io_data->ptr;
  *io_data->ptr = '\0';
  io_data->close = false;
  return;
}

