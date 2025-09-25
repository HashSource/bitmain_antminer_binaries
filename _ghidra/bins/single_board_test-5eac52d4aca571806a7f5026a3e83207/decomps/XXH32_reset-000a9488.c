
XXH_errorcode XXH32_reset(XXH32_state_t *statePtr,uint seed)

{
  uint seed_local;
  XXH32_state_t *statePtr_local;
  XXH32_state_t state;
  
  memset(&state,0,0x30);
  state.v1 = seed + 0x24234428;
  state.v2 = seed + 0x85ebca77;
  state.v4 = seed + 0x61c8864f;
  state.v3 = seed;
  memcpy(statePtr,&state,0x2c);
  return XXH_OK;
}

