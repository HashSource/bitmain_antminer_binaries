
bool is_partially_overlapping(int param_1,int param_2,uint param_3)

{
  return (param_3 != 0 && param_1 != param_2) &&
         (-param_3 < (uint)(param_1 - param_2) || (uint)(param_1 - param_2) < param_3);
}

