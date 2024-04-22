
/* WARNING: Unknown calling convention */

void io_free(void)

{
  io_list *piVar1;
  io_list *io_next;
  io_list *io_list;
  
  if (io_head != (io_list *)0x0) {
    io_list = io_head;
    do {
      piVar1 = io_list->next;
      free(io_list->io_data->ptr);
      free(io_list->io_data);
      free(io_list);
      io_list = piVar1;
    } while (piVar1 != io_head);
    io_head = (io_list *)0x0;
  }
  return;
}

