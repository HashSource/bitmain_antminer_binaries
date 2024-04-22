
void doquit(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)(param_1 + 4);
  if (param_4 == 0) {
    *(undefined **)(param_1 + 8) = puVar1;
    *puVar1 = 0;
    *(undefined *)(param_1 + 0xd) = 0;
    io_add(param_1,&DAT_000579c8);
  }
  else {
    *(undefined **)(param_1 + 8) = puVar1;
    *puVar1 = 0;
    *(undefined *)(param_1 + 0xd) = 0;
    io_add(param_1,"{\"STATUS\":\"BYE\"");
  }
  bye = 1;
  do_a_quit = 1;
  return;
}

