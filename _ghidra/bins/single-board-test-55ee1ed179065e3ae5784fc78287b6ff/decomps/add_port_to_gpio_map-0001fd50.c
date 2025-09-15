
void add_port_to_gpio_map(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_1c [2];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_3 != 0) {
    local_1c[0] = param_1;
    iVar1 = exists_c_map(param_3,local_1c);
    if (iVar1 == 0) {
      printf("%s:%d","add_port_to_gpio_map",0xb4);
      printf("add %d to flicker map with interval %d\n",local_1c[0],param_2);
      local_10 = 0;
      local_c = 1;
      local_14 = param_2;
      insert_c_map(param_3,local_1c,4,&local_14,0xc);
    }
    else {
      printf("%s:%d","add_port_to_gpio_map",0xb8);
      printf("port %d already exist in map\n",local_1c[0]);
    }
  }
  return;
}

