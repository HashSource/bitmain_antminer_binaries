
/* WARNING: Unknown calling convention */

int32_t dhash_get_midstate_by_workid(uint32_t work_id,uint8_t *midstate,uint32_t len)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  uint8_t *puVar3;
  
  if (len != 0) {
    puVar1 = (uint8_t *)(work_id * 0x40 + 0x1f + (int)nonce2_jobid_address);
    puVar2 = midstate;
    do {
      puVar1 = puVar1 + 1;
      puVar3 = puVar2 + 1;
      *puVar2 = *puVar1;
      puVar2 = puVar3;
    } while (puVar3 != midstate + len);
  }
  return 0;
}

