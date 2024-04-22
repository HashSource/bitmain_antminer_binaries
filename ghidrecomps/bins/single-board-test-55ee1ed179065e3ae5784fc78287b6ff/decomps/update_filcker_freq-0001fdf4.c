
void update_filcker_freq(int param_1,undefined4 param_2,int param_3)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  code *local_14;
  code **local_10;
  int local_c;
  
  if (param_3 != 0) {
    local_10 = (code **)new_iterator_c_map(param_3);
    local_c = (**local_10)(local_10);
    while (local_c != 0) {
      local_14 = local_10[5];
      if (***(int ***)(local_14 + 0x10) == param_1) {
        local_18 = (undefined4 *)(*local_10[2])(local_c);
        local_20 = 0;
        local_1c = 1;
        local_24 = param_2;
        (*local_10[1])(local_10,&local_24,0xc);
        printf("%s:%d","update_filcker_freq",0xc9);
        printf("update the freq interval of port[%d] from %d to %d\n",param_1,*local_18,param_2);
        free(local_18);
        break;
      }
      local_c = (**local_10)(local_10);
    }
    delete_iterator_c_map(local_10);
  }
  return;
}

