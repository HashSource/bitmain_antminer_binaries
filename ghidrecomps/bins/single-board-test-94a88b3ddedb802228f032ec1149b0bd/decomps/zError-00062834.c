
undefined4 zError(int param_1)

{
  return *(undefined4 *)(&z_errmsg + (2 - param_1) * 4);
}

