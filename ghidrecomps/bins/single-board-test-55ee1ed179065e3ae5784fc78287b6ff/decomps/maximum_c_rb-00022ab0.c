
int maximum_c_rb(int param_1,int param_2)

{
  int local_10;
  
  for (local_10 = param_2; *(int *)(local_10 + 4) != param_1 + 4; local_10 = *(int *)(local_10 + 4))
  {
  }
  return local_10;
}

