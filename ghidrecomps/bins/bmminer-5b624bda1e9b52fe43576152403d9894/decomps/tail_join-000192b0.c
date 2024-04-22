
/* WARNING: Unknown calling convention */

void tail_join(io_data *io_data,_Bool isjson)

{
  if (io_data->close != false) {
    io_add(io_data,DAT_000192e0);
    io_data->close = false;
  }
  if (isjson) {
    io_add(io_data,DAT_000192e4);
    io_add(io_data,DAT_000192e0);
    return;
  }
  return;
}

