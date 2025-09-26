
uchar * EC_GROUP_get0_seed(EC_GROUP *x)

{
  return *(uchar **)(x + 0x3c);
}

