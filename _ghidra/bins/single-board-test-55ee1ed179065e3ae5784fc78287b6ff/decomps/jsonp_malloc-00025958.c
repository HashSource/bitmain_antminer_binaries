
undefined4 jsonp_malloc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*do_malloc)(param_1);
  }
  return uVar1;
}

