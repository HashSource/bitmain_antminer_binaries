
/* WARNING: Unknown calling convention */

int BM1385_is_nonce_or_reg_value(uchar data)

{
  return (uint)(data >> 7);
}

