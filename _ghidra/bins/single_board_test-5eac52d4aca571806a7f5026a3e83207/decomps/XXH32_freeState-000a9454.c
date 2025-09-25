
XXH_errorcode XXH32_freeState(XXH32_state_t *statePtr)

{
  XXH32_state_t *statePtr_local;
  
  XXH_free(statePtr);
  return XXH_OK;
}

