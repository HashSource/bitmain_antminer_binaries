
int ConvirtTotalRate(int param_1)

{
  int local_c;
  
  if (param_1 % 1000 < 500) {
    local_c = 0;
  }
  else {
    local_c = 500;
  }
  return local_c + (param_1 / 1000) * 1000;
}

