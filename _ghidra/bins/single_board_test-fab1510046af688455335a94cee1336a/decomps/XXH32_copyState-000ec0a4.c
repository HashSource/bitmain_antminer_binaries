
void XXH32_copyState(XXH32_state_t *dstState,XXH32_state_t *srcState)

{
  XXH32_state_t *srcState_local;
  XXH32_state_t *dstState_local;
  
  memcpy(dstState,srcState,0x30);
  return;
}

