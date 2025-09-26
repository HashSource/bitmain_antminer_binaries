
/* WARNING: Unknown calling convention */

uint64_t dhash_get_nonce2_by_workid(uint32_t work_id)

{
  return *(uint64_t *)(nonce2_jobid_address + work_id * 0x10 + 2);
}

