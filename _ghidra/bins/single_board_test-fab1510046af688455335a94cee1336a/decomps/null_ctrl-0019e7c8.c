
undefined4 null_ctrl(undefined4 param_1,uint param_2)

{
  if ((param_2 < 0xd) && ((1 << (param_2 & 0xff) & 0x1a16U) != 0)) {
    return 1;
  }
  return 0;
}

