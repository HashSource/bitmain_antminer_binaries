
void remove_port_form_gpio_map(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 local_c;
  
  if ((param_2 != 0) && (local_c = param_1, iVar1 = exists_c_map(param_2,&local_c), iVar1 == 1)) {
    printf("%s:%d","remove_port_form_gpio_map",0xa8);
    printf("remove %d from flicker list\n",local_c);
    remove_c_map(param_2,&local_c);
  }
  return;
}

