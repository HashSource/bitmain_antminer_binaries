
undefined4 ssl3_do_uncompress(int param_1,int param_2)

{
  int iVar1;
  uchar *out;
  
  out = *(uchar **)(param_2 + 0x1c);
  if (out == (uchar *)0x0) {
    out = (uchar *)CRYPTO_malloc(0x4540,"ssl/record/ssl3_record.c",799);
    *(uchar **)(param_2 + 0x1c) = out;
    if (out == (uchar *)0x0) {
      return 0;
    }
  }
  iVar1 = COMP_expand_block(*(COMP_CTX **)(param_1 + 1000),out,0x4000,*(uchar **)(param_2 + 0x14),
                            *(int *)(param_2 + 8));
  if (iVar1 < 0) {
    return 0;
  }
  *(int *)(param_2 + 8) = iVar1;
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x1c);
  return 1;
}

