
void names_lh_free_doall(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if ((free_type < 0) || (free_type == *param_1)) {
      OBJ_NAME_remove((char *)param_1[2],*param_1);
      return;
    }
  }
  return;
}

