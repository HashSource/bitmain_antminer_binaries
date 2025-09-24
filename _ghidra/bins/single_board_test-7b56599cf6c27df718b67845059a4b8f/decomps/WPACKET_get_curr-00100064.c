
int WPACKET_get_curr(int *param_1)

{
  if (param_1[1] != 0) {
    return param_1[2] + param_1[1];
  }
  return param_1[2] + *(int *)(*param_1 + 4);
}

