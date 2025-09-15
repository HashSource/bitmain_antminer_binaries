
void add_point(uint *param_1,uint param_2)

{
  *param_1 = *param_1 + 1;
  if (param_2 <= *param_1) {
    *param_1 = 0;
  }
  return;
}

