
/* WARNING: Unknown calling convention */

void set_nonce2_and_job_id_store_address(uint value)

{
  char cVar1;
  
  cVar1 = *DAT_0002d1b0;
  *(uint *)(*(int *)(DAT_0002d1ac + 0x8d4) + 0x110) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002d1b4 != '\0' || (*DAT_0002d1b8 != '\0')) || (6 < *DAT_0002d1bc)))) {
    set_nonce2_and_job_id_store_address(value);
    return;
  }
  return;
}

