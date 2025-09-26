
short BIO_ADDR_rawport(short *param_1)

{
  if ((*param_1 != 2) && (*param_1 != 10)) {
    return 0;
  }
  return param_1[1];
}

