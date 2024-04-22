
void io_close(io_data *io_data)

{
  io_data *io_data_local;
  
  io_data->close = true;
  return;
}

