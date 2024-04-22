
void x86_tty_init(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  x86_tty_open(param_1,0x4b00);
  if (param_2 != 0x4b00) {
    uVar1 = get_bt8d_from_baud(param_2);
    set_baud_chain(uVar1);
    usleep(200000);
    x86_tty_close();
    x86_tty_open(param_1,param_2);
  }
  return;
}

