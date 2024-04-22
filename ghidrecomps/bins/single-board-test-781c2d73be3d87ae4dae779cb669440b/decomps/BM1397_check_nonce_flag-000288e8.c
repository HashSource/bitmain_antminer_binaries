
/* WARNING: Unknown calling convention */

int BM1397_check_nonce_flag(uint data)

{
  if ((data & 0xe0) != 0x80) {
    printf("%s: data = 0x%08x\n",DAT_0002890c,data);
    return 0;
  }
  return 1;
}

