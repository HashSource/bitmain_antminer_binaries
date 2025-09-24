
/* WARNING: Unknown calling convention */

void remove_port_form_gpio_map(uint32_t port,clib_map *map)

{
  clib_bool cVar1;
  uint32_t local_c;
  
  if ((map != (clib_map *)0x0) && (local_c = port, cVar1 = exists_c_map(map,&local_c), cVar1 == 1))
  {
    remove_c_map(map,&local_c);
    return;
  }
  return;
}

