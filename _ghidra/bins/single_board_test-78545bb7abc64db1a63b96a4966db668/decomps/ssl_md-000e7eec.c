
undefined4 ssl_md(byte param_1)

{
  if (param_1 < 0xc) {
    return *(undefined4 *)(ssl_digest_methods + (uint)param_1 * 4);
  }
  return 0;
}

