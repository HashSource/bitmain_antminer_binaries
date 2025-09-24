
uint * EC_KEY_can_sign(int param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0xc);
  if ((puVar1 != (uint *)0x0) && (puVar1 = (uint *)*puVar1, puVar1 != (uint *)0x0)) {
    if ((*puVar1 & 4) == 0) {
      puVar1 = (uint *)0x1;
    }
    else {
      puVar1 = (uint *)0x0;
    }
  }
  return puVar1;
}

