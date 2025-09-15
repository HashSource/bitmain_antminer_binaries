
/* WARNING: Unknown calling convention */

void tail_join(io_data *io_data,_Bool isjson)

{
  if (io_data->close != false) {
    io_add(io_data,"]");
    io_data->close = false;
  }
  if (isjson) {
    io_add(io_data,",\"id\":1}");
    io_add(io_data,"]");
    return;
  }
  return;
}

