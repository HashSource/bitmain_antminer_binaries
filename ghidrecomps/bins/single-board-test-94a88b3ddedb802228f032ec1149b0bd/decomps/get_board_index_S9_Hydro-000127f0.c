
int get_board_index_S9_Hydro(int param_1,int *param_2)

{
  int local_c;
  
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  local_c = param_1;
  switch(param_1) {
  case 6:
  case 7:
    local_c = 5;
    if (param_2 != (int *)0x0) {
      *param_2 = param_1 + -5;
    }
    break;
  case 8:
  case 9:
    local_c = 1;
    if (param_2 != (int *)0x0) {
      *param_2 = param_1 + -7;
    }
    break;
  case 10:
  case 0xb:
    local_c = 2;
    if (param_2 != (int *)0x0) {
      *param_2 = param_1 + -9;
    }
    break;
  case 0xc:
  case 0xd:
    local_c = 3;
    if (param_2 != (int *)0x0) {
      *param_2 = param_1 + -0xb;
    }
  }
  return local_c;
}

