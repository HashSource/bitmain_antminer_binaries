
double round(double __x)

{
  int iVar1;
  double x_local;
  
  if (__x < 0.0) {
    iVar1 = (int)(longlong)(__x - 0.5);
  }
  else {
    iVar1 = (int)(longlong)(__x + 0.5);
  }
  return (double)(longlong)iVar1;
}

