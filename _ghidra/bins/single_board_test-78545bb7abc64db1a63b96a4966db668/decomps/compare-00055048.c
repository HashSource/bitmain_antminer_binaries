
_Bool compare(float a,float b)

{
  _Bool _Var1;
  float b_local;
  float a_local;
  
  if (1.1920929e-07 < ABS(a - b)) {
    if (a - b <= 1.1920929e-07) {
      _Var1 = false;
    }
    else {
      _Var1 = true;
    }
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}

