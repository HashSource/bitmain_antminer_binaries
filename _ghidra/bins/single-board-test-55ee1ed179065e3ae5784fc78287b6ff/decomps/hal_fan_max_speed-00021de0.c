
undefined4 hal_fan_max_speed(int param_1)

{
  int local_c;
  
  if (conf_loaded != 0) {
    for (local_c = 0; local_c < 6; local_c = local_c + 1) {
      if (*(int *)(fans + local_c * 0xc) == param_1) {
        return *(undefined4 *)(fans + local_c * 0xc + 8);
      }
    }
  }
  return 0xffffffff;
}

