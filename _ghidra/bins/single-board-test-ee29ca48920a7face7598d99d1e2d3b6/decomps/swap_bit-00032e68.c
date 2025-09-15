
byte swap_bit(byte param_1)

{
  undefined4 local_10;
  undefined1 local_9;
  
  local_9 = 0;
  for (local_10 = 0; (int)local_10 < 8; local_10 = local_10 + 1) {
    if (((int)(uint)param_1 >> (local_10 & 0xff) & 1U) != 0) {
      local_9 = local_9 | (byte)(1 << (7 - local_10 & 0xff));
    }
  }
  return local_9;
}

