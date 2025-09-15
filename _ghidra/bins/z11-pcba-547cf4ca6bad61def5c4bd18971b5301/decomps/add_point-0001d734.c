
void add_point(int *param_1,int param_2)

{
  *param_1 = *param_1 + 1;
  if (param_2 <= *param_1) {
    *param_1 = 0;
  }
  return;
}

