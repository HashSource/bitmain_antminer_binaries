
void rw_register_loop(void)

{
  do {
    write_register(0x58,0);
    sleep(1);
    read_register(0,1,0,0x58);
    sleep(3);
    write_register(0x58,3);
    sleep(1);
    read_register(0,1,0,0x58);
    sleep(3);
  } while( true );
}

