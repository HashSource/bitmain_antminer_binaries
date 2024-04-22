
void rev(int param_1,char param_2)

{
  undefined uVar1;
  byte local_a;
  byte local_9;
  
  local_a = param_2 - 1;
  for (local_9 = 0; local_9 < local_a; local_9 = local_9 + 1) {
    uVar1 = *(undefined *)((uint)local_9 + param_1);
    *(undefined *)((uint)local_9 + param_1) = *(undefined *)((uint)local_a + param_1);
    *(undefined *)((uint)local_a + param_1) = uVar1;
    local_a = local_a - 1;
  }
  return;
}

