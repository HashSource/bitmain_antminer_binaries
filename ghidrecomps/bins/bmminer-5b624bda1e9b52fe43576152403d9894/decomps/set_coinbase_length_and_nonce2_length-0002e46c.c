
/* WARNING: Unknown calling convention */

void set_coinbase_length_and_nonce2_length(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002e4c0;
  *(uint *)(*(int *)(DAT_0002e4bc + 0x8d4) + 0x104) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e4c4 != '\0' || (*DAT_0002e4c8 != '\0')) || (6 < *DAT_0002e4cc)))) {
    snprintf(tmp42,0x800,DAT_0002e4d0,DAT_0002e4d4,value);
    _applog(7,tmp42,false);
  }
  get_coinbase_length_and_nonce2_length();
  return;
}

