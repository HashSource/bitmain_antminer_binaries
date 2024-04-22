
io_data * _io_new(size_t initial,_Bool socket_buf)

{
  io_data *io_data_00;
  char *pcVar1;
  io_list *piVar2;
  _Bool socket_buf_local;
  size_t initial_local;
  io_list *io_list;
  io_data *io_data;
  
  io_data_00 = (io_data *)_cgmalloc(0x10,"api-btm.c","_io_new",0x2d3);
  pcVar1 = (char *)_cgmalloc(initial,"api-btm.c","_io_new",0x2d4);
  io_data_00->ptr = pcVar1;
  io_data_00->siz = initial;
  io_data_00->sock = socket_buf;
  io_reinit(io_data_00);
  piVar2 = (io_list *)_cgmalloc(0xc,"api-btm.c","_io_new",0x2d9);
  piVar2->io_data = io_data_00;
  if (io_head == (io_list *)0x0) {
    piVar2->prev = piVar2;
    piVar2->next = piVar2;
    io_head = piVar2;
  }
  else {
    piVar2->next = io_head;
    piVar2->prev = io_head->prev;
    piVar2->next->prev = piVar2;
    piVar2->prev->next = piVar2;
  }
  return io_data_00;
}

