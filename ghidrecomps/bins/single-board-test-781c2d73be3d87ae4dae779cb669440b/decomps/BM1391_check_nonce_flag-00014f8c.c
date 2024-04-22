
/* WARNING: Unknown calling convention */

int BM1391_check_nonce_flag(uint data)

{
  if ((data & 0xe0) != 0x80) {
    printf("%s: data = 0x%08x\n",DAT_00014fb0,data);
    return 0;
  }
  return 1;
}

