
XXH_errorcode XXH64_freeState(XXH64_state_t *statePtr)

{
  XXH64_state_t *statePtr_local;
  
  XXH_free(statePtr);
  return XXH_OK;
}

