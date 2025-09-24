
undefined4 null_ctrl(undefined4 param_1,undefined4 param_2)

{
  switch(param_2) {
  case 1:
  case 2:
  case 4:
  case 9:
  case 0xb:
  case 0xc:
    return 1;
  default:
    return 0;
  }
}

