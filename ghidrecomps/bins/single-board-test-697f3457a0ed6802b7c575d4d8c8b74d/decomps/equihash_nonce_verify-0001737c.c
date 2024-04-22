
/* WARNING: Variable defined which should be unmapped: shift-local */

int equihash_nonce_verify(nonce_verify_info_t *verify_info,int *tm,uint32_t shift)

{
  int iVar1;
  uint32_t uVar2;
  undefined4 uStack_1a0;
  uint32_t shift_local;
  int *tm_local;
  nonce_verify_info_t *verify_info_local;
  validData valData;
  blake2b_state digest [1];
  int valid;
  
  memcpy((void *)((int)verify_info + (verify_info->work_len - shift) + -4),verify_info->nonce,
         verify_info->nonce_len);
  valData.n = 200;
  valData.k = 9;
  valData.digest = digest;
  digestInit(digest,200,9);
  blake2b_update(digest,verify_info->work,CONCAT44(shift,uStack_1a0));
  iVar1 = sortValidator(&valData,verify_info->sol);
  uVar2 = targetValidator(verify_info->work,verify_info->sol,verify_info->target);
  *tm = uVar2;
  return iVar1;
}

