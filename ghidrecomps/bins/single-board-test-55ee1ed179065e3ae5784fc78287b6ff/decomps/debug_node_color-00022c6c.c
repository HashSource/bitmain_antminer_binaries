
undefined4 debug_node_color(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 + 4 == param_2) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0xc);
  }
  return uVar1;
}

