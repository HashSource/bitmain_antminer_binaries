
void __delete_c_rb_node(int param_1,int param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    get_raw_clib_object(*(undefined4 *)(param_2 + 0x10),&local_c);
    (**(code **)(param_1 + 0x1c))(local_c);
  }
  delete_clib_object(*(undefined4 *)(param_2 + 0x10));
  if (*(int *)(param_2 + 0x14) != 0) {
    if (*(int *)(param_1 + 0x20) != 0) {
      get_raw_clib_object(*(undefined4 *)(param_2 + 0x14),&local_10);
      (**(code **)(param_1 + 0x20))(local_10);
    }
    delete_clib_object(*(undefined4 *)(param_2 + 0x14));
  }
  return;
}

