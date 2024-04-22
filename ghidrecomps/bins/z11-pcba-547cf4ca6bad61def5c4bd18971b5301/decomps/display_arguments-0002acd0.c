
void display_arguments(void)

{
  size_t __n;
  undefined auStack_2b4 [16];
  char acStack_2a4 [16];
  char acStack_294 [16];
  char acStack_284 [16];
  undefined auStack_274 [4];
  char acStack_270 [400];
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  
  get_app_config(auStack_274);
  memset(auStack_2b4,0,0x40);
  lseek(cgpu._36_4_,0,0);
  memset(auStack_2b4,0x20,0x40);
  __n = strlen(acStack_270);
  memcpy(auStack_2b4,acStack_270,__n);
  sprintf(acStack_2a4,"IC:%2d",local_e0);
  sprintf(acStack_294,"FREQ: %d",local_d8);
  sprintf(acStack_284,"Voltage: %d",local_d4);
  write(cgpu._36_4_,auStack_2b4,0x40);
  return;
}

