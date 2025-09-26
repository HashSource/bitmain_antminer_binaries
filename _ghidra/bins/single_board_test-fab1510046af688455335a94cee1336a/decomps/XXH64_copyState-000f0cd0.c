
void XXH64_copyState(XXH64_state_t *dstState,XXH64_state_t *srcState)

{
  XXH64_state_t *srcState_local;
  XXH64_state_t *dstState_local;
  
  memcpy(dstState,srcState,0x58);
  return;
}

